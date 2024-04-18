#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compile_assign_node(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* ast_value) {
    const auto assign_node = ast_value->data.AssignNode;
    if (this->state->structures.contains(assign_node->id)) {
      return {CompilerError::fromASTValue(
          ast_value,
          "Неможливо перевизначити субʼєкт \"" + assign_node->id + "\"")};
    }
    if (!this->has_variable(assign_node->id)) {
      return {CompilerError::fromASTValue(
          ast_value, "Субʼєкт \"" + assign_node->id + "\" не визначено")};
    }
    const auto variable = this->get_variable(assign_node->id);
    if (variable.first->type == TypeTypeDiia) {
      return {CompilerError::fromASTValue(
          ast_value,
          "Неможливо перевизначити субʼєкт \"" + assign_node->id + "\"")};
    }
    const auto value_result =
        this->compile_ast_value(function, block, assign_node->value);
    if (value_result.error) {
      return {value_result.error};
    }
    this->state->Module->pushFunctionBlockStoreInstruction(
        block, value_result.type->LT, value_result.LV, variable.second);
    return {nullptr};
  }
} // namespace tsil::compiler