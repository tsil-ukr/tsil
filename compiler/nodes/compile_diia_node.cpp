#include "../compiler.h"

namespace tsil::compiler {
  CompilerDiiaResult CompilationScope::compile_diia_head_node(
      tsil::ast::ASTValue* ast_value,
      tsil::ast::DiiaHeadNode* diia_head_node) {
    if (this->has_variable(diia_head_node->id)) {
      return {nullptr, nullptr, nullptr,
              CompilerError::fromASTValue(
                  ast_value,
                  "Субʼєкт \"" + diia_head_node->id + "\" вже визначено")};
    }
    const auto diia_type = new Type();
    diia_type->type = TypeTypeDiia;
    diia_type->name = diia_head_node->id;
    diia_type->diia_is_extern = diia_head_node->is_extern;
    diia_type->diia_is_variadic = diia_head_node->is_variadic;
    diia_type->diia_result_type = this->state->voidType;
    for (const auto& param_ast_value : diia_head_node->params) {
      const auto param_node = param_ast_value->data.ParamNode;
      const auto type_result =
          this->makeTypeFromTypeNodeASTValue(param_node->type);
      if (!type_result.type) {
        return {
            nullptr, nullptr, nullptr,
            CompilerError::fromASTValue(param_ast_value, type_result.error)};
      }
      diia_type->diia_parameters.push_back(
          TypeDiiaParameter{.name = param_node->id, .type = type_result.type});
    }
    if (diia_head_node->type) {
      const auto type_result =
          this->makeTypeFromTypeNodeASTValue(diia_head_node->type);
      if (!type_result.type) {
        return {nullptr, nullptr, nullptr,
                CompilerError::fromASTValue(diia_head_node->type,
                                            type_result.error)};
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
    const auto declared_diia = this->state->Module->declareFunction(
        diia_type->name, LDResultType, LDParams);
    this->set_variable(diia_type->name, {diia_type, declared_diia.second});
    return {diia_type, declared_diia.first, declared_diia.second, nullptr};
  }

  CompilerResult CompilationScope::compile_diia_block(
      Type* diia_type,
      tsil::x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::x::FunctionBlock* exit_block,
      const std::vector<ast::ASTValue*>& body) {
    bool returned = false;
    int i = 0;
    for (const auto& body_ast_value : body) {
      if (body_ast_value == nullptr) {
        continue;
      }
      if (body_ast_value->kind == tsil::ast::KindNone) {
        continue;
      }
      if (body_ast_value->kind == ast::KindDefineNode) {
        const auto define_result =
            this->compile_define_node(function, block, body_ast_value);
        if (define_result.error) {
          return {define_result.error};
        }
      } else if (body_ast_value->kind == ast::KindAssignNode) {
        const auto assign_result =
            this->compile_assign_node(function, block, body_ast_value);
        if (assign_result.error) {
          return {assign_result.error};
        }
      } else if (body_ast_value->kind == ast::KindSetNode) {
        const auto set_result =
            this->compile_set_node(function, block, body_ast_value);
        if (set_result.error) {
          return {set_result.error};
        }
      } else if (body_ast_value->kind == ast::KindWhileNode) {
        const auto while_block =
            this->state->Module->defineFunctionBlock(function, "while");
        const auto while_body_block =
            this->state->Module->defineFunctionBlock(function, "while_body");
        const auto while_exit_block =
            i == body.size() - 1 ? exit_block
                                 : this->state->Module->defineFunctionBlock(
                                       function, "while_exit");

        const auto result = this->compile_ast_value(
            function, while_block, body_ast_value->data.WhileNode->condition);
        if (result.error) {
          return {result.error};
        }
        this->state->Module->pushFunctionBlockBrIfInstruction(
            while_block, result.LV, while_body_block, while_exit_block);

        const auto while_body_result = this->compile_diia_block(
            diia_type, function, while_body_block, while_exit_block,
            body_ast_value->data.WhileNode->body);
        if (while_body_result.error) {
          return {while_body_result.error};
        }
        this->state->Module->pushFunctionBlockBrInstruction(while_body_block,
                                                            while_block);

        this->state->Module->pushFunctionBlockBrInstruction(block, while_block);

        block = while_exit_block;
      } else if (body_ast_value->kind == tsil::ast::KindReturnNode) {
        const auto return_result = this->compile_ast_value(
            function, block, body_ast_value->data.ReturnNode->value);
        if (return_result.error) {
          return {return_result.error};
        }
        if (return_result.type != diia_type->diia_result_type) {
          return {CompilerError::fromASTValue(
              body_ast_value->data.ReturnNode->value,
              "Невірний тип результату дії \"" + diia_type->getFullName() +
                  "\"")};
        }
        this->state->Module->pushFunctionBlockStoreInstruction(
            block, return_result.type->LT, return_result.LV,
            function->return_alloca);
        this->state->Module->pushFunctionBlockBrInstruction(
            block, function->exit_block);
        break;
      } else {
        auto result = this->compile_ast_value(function, block, body_ast_value);
        if (result.error) {
          return {result.error};
        }
      }
      i++;
    }
    return {nullptr};
  }

  CompilerDiiaResult CompilationScope::compile_diia_node(
      tsil::ast::ASTValue* ast_value) {
    const auto diia_node = ast_value->data.DiiaNode;
    auto diia_head_result =
        this->compile_diia_head_node(ast_value, diia_node->head);
    if (diia_head_result.error) {
      return diia_head_result;
    }
    const auto diia_type = diia_head_result.type;
    const auto function = diia_head_result.LF;
    const auto diia_scope = new CompilationScope(this, this->state);

    function->entry_block =
        diia_scope->state->Module->defineFunctionBlock(function, "entry");
    if (function->result_type) {
      if (function->result_type != diia_scope->state->Module->voidType) {
        function->return_alloca =
            diia_scope->state->Module->pushFunctionBlockAllocaInstruction(
                function->entry_block, function->result_type);
      }
    }
    function->exit_block =
        diia_scope->state->Module->defineFunctionBlock(function, "exit");
    if (function->return_alloca) {
      const auto loadedReturnValue =
          diia_scope->state->Module->pushFunctionBlockLoadInstruction(
              function->exit_block, function->result_type,
              function->return_alloca);
      diia_scope->state->Module->pushFunctionBlockRetInstruction(
          function->exit_block, function->result_type, loadedReturnValue);
    } else {
      diia_scope->state->Module->pushFunctionBlockRetInstruction(
          function->exit_block, diia_scope->state->Module->voidType, nullptr);
    }

    //    for (const auto& parameter : diia_type->diia_parameters) {
    //      const auto LAI =
    //      this->state->Module->pushFunctionBlockAllocaInstruction(
    //          function->blocks["entry"], parameter.type->LT);
    //      this->state->Module->pushFunctionBlockStoreInstruction(
    //          function->blocks["entry"], LAI);
    //      //      this->state->Builder->CreateStore(arg, LAI);
    //      diia_scope->set_variable(parameter.name, {parameter.type, LAI});
    //    }

    const auto body_compile_result = diia_scope->compile_diia_block(
        diia_type, function, function->entry_block, function->exit_block,
        diia_node->body);
    if (body_compile_result.error) {
      return {nullptr, nullptr, nullptr, body_compile_result.error};
    }

    return diia_head_result;
  }

  CompilerDiiaResult CompilationScope::compile_diia_declaration_node(
      tsil::ast::ASTValue* ast_value) {
    const auto diia_declaration_node = ast_value->data.DiiaDeclarationNode;
    auto diia_head_result =
        this->compile_diia_head_node(ast_value, diia_declaration_node->head);
    if (!diia_declaration_node->as.empty()) {
      this->set_variable(diia_declaration_node->as,
                         {diia_head_result.type, diia_head_result.LV});
    }
    return diia_head_result;
  }
} // namespace tsil::compiler