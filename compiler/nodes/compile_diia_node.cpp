#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compile_diia_head_node(
      tsil::ast::DiiaHeadNode* diia_head_node) {
    std::vector<llvm::Type*> Params;
    for (const auto& param : diia_head_node->params) {
      const auto param_node = param->data.ParamNode;
      const auto type = this->get_type(param_node->type->data.TypeNode);
      if (!type) {
        return error("Тип не знайдено");
      }
      Params.push_back(type->lltype);
    }

    llvm::Type* Result = llvm::Type::getVoidTy(*this->state->Context);
    if (diia_head_node->type) {
      const auto result_type =
          this->get_type(diia_head_node->type->data.TypeNode);
      if (!result_type) {
        return error("Тип не знайдено");
      }
      Result = result_type->lltype;
    }

    llvm::FunctionType* FT =
        llvm::FunctionType::get(Result, Params, diia_head_node->is_variadic);
    llvm::Function* F = llvm::Function::Create(
        FT,
        diia_head_node->is_extern ? llvm::Function::ExternalLinkage
                                  : llvm::Function::PrivateLinkage,
        diia_head_node->id, this->state->Module);
    this->set_variable(diia_head_node->id, new Value(F));
    return ok(F, nullptr);
  }

  CompilerResult CompilationScope::compile_diia_node(
      tsil::ast::ASTValue* ast_value) {
    const auto diia_node = ast_value->data.DiiaNode;
    auto diia_head_result = this->compile_diia_head_node(diia_node->head);
    if (diia_head_result.error) {
      return diia_head_result;
    }
    const auto F = diia_head_result.result->as_function();
    const auto diia_scope = new CompilationScope(this, this->state);
    for (const auto& param : diia_node->head->params) {
      const auto param_node = param->data.ParamNode;
      const auto type = diia_scope->get_type(param_node->type->data.TypeNode);
      const auto arg = F->arg_begin();
      arg->setName(param_node->id);
      diia_scope->set_variable(param_node->id, new Value(arg));
    }
    llvm::BasicBlock* BB =
        llvm::BasicBlock::Create(*diia_scope->state->Context, "entry", F);
    diia_scope->state->Builder->SetInsertPoint(BB);

    for (const auto& body_ast_value : diia_node->body) {
      if (body_ast_value == nullptr) {
        continue;
      }
      if (body_ast_value->kind == tsil::ast::KindNone) {
        continue;
      }
      if (body_ast_value->kind == tsil::ast::KindReturnNode) {
        auto result = diia_scope->compile_ast_value(
            body_ast_value->data.ReturnNode->value);
        if (result.error) {
          return result;
        }
        verifyFunction(*F);
        diia_scope->state->Builder->CreateRet(result.result->llval);
      } else {
        auto result = diia_scope->compile_ast_value(body_ast_value);
        if (result.error) {
          return result;
        }
      }
    }
    verifyFunction(*F);
    diia_scope->state->Builder->CreateRet(nullptr);
    return diia_head_result;
  }

  CompilerResult CompilationScope::compile_diia_declaration_node(
      tsil::ast::ASTValue* ast_value) {
    const auto diia_declaration_node = ast_value->data.DiiaDeclarationNode;
    auto diia_head_result =
        this->compile_diia_head_node(diia_declaration_node->head);
    if (!diia_declaration_node->as.empty()) {
      this->set_variable(diia_declaration_node->as, diia_head_result.result);
    }
    return diia_head_result;
  }
} // namespace tsil::compiler