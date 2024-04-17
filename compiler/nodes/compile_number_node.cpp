#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_number_node(
      tsil::ast::ASTValue* ast_value) {
    const auto number_node = ast_value->data.NumberNode;
    const auto LV = new x::Value{
        .number = new x::Number{.type = this->state->Module->int64Type,
                                .value = number_node->value}};
    return {this->state->int64Type, LV, nullptr};
  }
} // namespace tsil::compiler