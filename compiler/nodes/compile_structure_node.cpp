#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_assign_node(
      tsil::ast::ASTValue* ast_value) {
    const auto assign_node = ast_value->data.AssignNode;
    if (!this->has_variable(assign_node->id)) {
      return {
          nullptr, nullptr,
          new CompilerError("Ціль \"" + assign_node->id + "\" не визначено")};
    }
    const auto value_result = this->compile_ast_value(assign_node->value);
    if (value_result.error) {
      return value_result;
    }
    const auto variable = this->get_variable(assign_node->id);
    this->state->Builder->CreateStore(value_result.LV, variable.second);
    return value_result;
  }
} // namespace tsil::compiler