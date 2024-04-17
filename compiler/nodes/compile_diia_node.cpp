#include "../compiler.h"

namespace tsil::compiler {
  CompilerDiiaResult CompilationScope::compile_diia_head_node(
      tsil::ast::DiiaHeadNode* diia_head_node) {
    if (this->has_variable(diia_head_node->id)) {
      return {nullptr, nullptr,
              new CompilerError("Субʼєкт \"" + diia_head_node->id +
                                "\" вже визначено")};
    }
    const auto diia_type = new Type();
    diia_type->type = TypeTypeDiia;
    diia_type->name = diia_head_node->id;
    diia_type->diia_is_extern = diia_head_node->is_extern;
    diia_type->diia_is_variadic = diia_head_node->is_variadic;
    diia_type->diia_result_type = nullptr;
    for (const auto& param_ast_value : diia_head_node->params) {
      const auto param_node = param_ast_value->data.ParamNode;
      const auto type_result =
          this->makeTypeFromTypeNodeASTValue(param_node->type);
      if (!type_result.type) {
        return {nullptr, nullptr, new CompilerError(type_result.error)};
      }
      diia_type->diia_parameters.push_back(
          TypeDiiaParameter{.name = param_node->id, .type = type_result.type});
    }
    if (diia_head_node->type) {
      const auto type_result =
          this->makeTypeFromTypeNodeASTValue(diia_head_node->type);
      if (!type_result.type) {
        return {nullptr, nullptr, new CompilerError(type_result.error)};
      }
      diia_type->diia_result_type = type_result.type;
    }
    std::vector<x::Type*> LDParams;
    for (const auto& param : diia_type->diia_parameters) {
      LDParams.push_back(param.type->LT);
    }
    x::Type* LDResultType = this->state->Module->voidType;
    if (diia_type->diia_result_type) {
      LDResultType = diia_type->diia_result_type->LT;
    }
    const auto LF = this->state->Module->declareFunction(
        diia_type->name, LDResultType, LDParams);
    this->set_variable(diia_type->name, {diia_type, LF});
    return {diia_type, LF, nullptr};
  }

  CompilerDiiaResult CompilationScope::compile_diia_node(
      tsil::ast::ASTValue* ast_value) {
    const auto diia_node = ast_value->data.DiiaNode;
    auto diia_head_result = this->compile_diia_head_node(diia_node->head);
    if (diia_head_result.error) {
      return diia_head_result;
    }
    const auto diia_type = diia_head_result.type;
    const auto LF = diia_head_result.LF->function;
    const auto diia_scope = new CompilationScope(this, this->state);

    const auto BB = this->state->Module->defineFunctionBlock(LF, "entry");

    //    for (const auto& parameter : diia_type->diia_parameters) {
    //      const auto LAI =
    //      this->state->Module->pushFunctionBlockAllocaInstruction(
    //          LF->blocks["entry"], parameter.type->LT);
    //      this->state->Module->pushFunctionBlockStoreInstruction(
    //          LF->blocks["entry"], LAI);
    //      //      this->state->Builder->CreateStore(arg, LAI);
    //      diia_scope->set_variable(parameter.name, {parameter.type, LAI});
    //    }

    bool returned = false;
    for (const auto& body_ast_value : diia_node->body) {
      if (body_ast_value == nullptr) {
        continue;
      }
      if (body_ast_value->kind == tsil::ast::KindNone) {
        continue;
      }
      if (body_ast_value->kind == ast::KindDefineNode) {
        const auto result = this->compile_define_node(LF, body_ast_value);
        if (result.error) {
          return {nullptr, nullptr, result.error};
        }
      } else if (body_ast_value->kind == ast::KindAssignNode) {
        const auto result = this->compile_assign_node(LF, body_ast_value);
        if (result.error) {
          return {nullptr, nullptr, result.error};
        }
      } else if (body_ast_value->kind == ast::KindSetNode) {
        const auto result = this->compile_set_node(LF, body_ast_value);
        if (result.error) {
          return {nullptr, nullptr, result.error};
        }
      } else if (body_ast_value->kind == tsil::ast::KindReturnNode) {
        const auto return_result = diia_scope->compile_ast_value(
            LF, body_ast_value->data.ReturnNode->value);
        if (return_result.error) {
          return {nullptr, nullptr, return_result.error};
        }
        if (return_result.type != diia_type->diia_result_type) {
          return {nullptr, nullptr,
                  new CompilerError("Невірний тип результату дії \"" +
                                    diia_type->getFullName() + "\"")};
        }
        diia_scope->state->Module->pushFunctionBlockRetInstruction(
            LF->blocks["entry"], return_result.LV);
        returned = true;
        break;
      } else {
        auto result = diia_scope->compile_ast_value(LF, body_ast_value);
        if (result.error) {
          return {nullptr, nullptr, result.error};
        }
      }
    }
    if (!returned) {
      diia_scope->state->Module->pushFunctionBlockRetInstruction(
          LF->blocks["entry"], nullptr);
    }
    return diia_head_result;
  }

  CompilerDiiaResult CompilationScope::compile_diia_declaration_node(
      tsil::ast::ASTValue* ast_value) {
    const auto diia_declaration_node = ast_value->data.DiiaDeclarationNode;
    auto diia_head_result =
        this->compile_diia_head_node(diia_declaration_node->head);
    if (!diia_declaration_node->as.empty()) {
      this->set_variable(diia_declaration_node->as,
                         {diia_head_result.type, diia_head_result.LF});
    }
    return diia_head_result;
  }
} // namespace tsil::compiler