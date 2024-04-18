#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compile_define_node(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* ast_value) {
    const auto define_node = ast_value->data.DefineNode;
    if (this->has_variable(define_node->id)) {
      return {CompilerError::fromASTValue(
          ast_value, "Субʼєкт \"" + define_node->id + "\" вже визначено")};
    }
    if (this->state->structures.contains(define_node->id)) {
      return {CompilerError::fromASTValue(
          ast_value, "Субʼєкт \"" + define_node->id + "\" вже визначено")};
    }
    Type* type = nullptr;
    if (define_node->type) {
      const auto type_result =
          this->makeTypeFromTypeNodeASTValue(define_node->type);
      if (!type_result.type) {
        return {
            CompilerError::fromASTValue(define_node->type, type_result.error)};
      }
      type = type_result.type;
    }
    if (define_node->value) {
      auto value_result =
          this->compile_ast_value(function, block, define_node->value);
      if (value_result.error) {
        return {value_result.error};
      }
      if (type) {
        if (value_result.type != type) {
          return {CompilerError::fromASTValue(
              define_node->value, "Тип \"" + value_result.type->getFullName() +
                                      "\" не сумісний з типом \"" +
                                      type->getFullName() + "\"")};
        }
      } else {
        type = value_result.type;
      }
      const auto LAI = this->state->Module->pushFunctionBlockAllocaInstruction(
          block, type->LT);
      this->state->Module->pushFunctionBlockStoreInstruction(
          block, value_result.type->LT, value_result.LV, LAI);
      this->set_variable(define_node->id, {type, LAI});
    } else {
      const auto LAI = this->state->Module->pushFunctionBlockAllocaInstruction(
          block, type->LT);
      this->set_variable(define_node->id, {type, LAI});
    }
    return {nullptr};
  }
} // namespace tsil::compiler