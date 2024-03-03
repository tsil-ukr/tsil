#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compile_diia_head_node(
      tsil::ast::DiiaHeadNode* diia_head_node) {
    std::vector<llvm::Type*> Params;
    for (const auto& param : diia_head_node->params) {
      const auto param_node = param->data.ParamNode;
      Params.push_back(this->get_type(param_node->type->data.TypeNode)->lltype);
    }

    llvm::Type* Result =
        diia_head_node->type
            ? this->get_type(diia_head_node->type->data.TypeNode)->lltype
            : llvm::Type::getVoidTy(*this->state->Context);

    llvm::FunctionType* FT = llvm::FunctionType::get(Result, Params, false);
    llvm::Function* F = llvm::Function::Create(
        FT,
        diia_head_node->splav ? llvm::Function::ExternalLinkage
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
    llvm::BasicBlock* BB = llvm::BasicBlock::Create(
        *this->state->Context, "entry", diia_head_result.result->as_function());
    this->state->Builder->SetInsertPoint(BB);

    for (const auto& body_ast_value : diia_node->body) {
      if (body_ast_value == nullptr) {
        continue;
      }
      if (body_ast_value->kind == tsil::ast::KindNone) {
        continue;
      }
      if (body_ast_value->kind == tsil::ast::KindReturnNode) {
        auto result =
            this->compile_ast_value(body_ast_value->data.ReturnNode->value);
        if (result.error) {
          return result;
        }
        this->state->Builder->CreateRet(result.result->llval);
      } else {
        auto result = this->compile_ast_value(body_ast_value);
        if (result.error) {
          return result;
        }
      }
    }
    this->state->Builder->CreateRet(nullptr);
    return diia_head_result;
  }

  CompilerResult CompilationScope::compile_diia_declaration_node(
      tsil::ast::ASTValue* ast_value) {
    const auto diia_declaration_node = ast_value->data.DiiaDeclarationNode;
    auto diia_head_result =
        this->compile_diia_head_node(diia_declaration_node->head);
    return diia_head_result;
  }
} // namespace tsil::compiler