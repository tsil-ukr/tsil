#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_sizeof_node(
      tsil::ast::ASTValue* ast_value) {
    const auto sizeof_node = ast_value->data.SizeofNode;
    const auto type_result =
        this->makeTypeFromTypeNodeASTValue(sizeof_node->value);
    if (!type_result.type) {
      return {nullptr, nullptr, new CompilerError(type_result.error)};
    }
    const auto size = type_result.type->getSizeOf(this);
    return {this->state->int64Type,
            new x::Value{
                .number = new x::Number{.type = this->state->Module->int64Type,
                                        .value = std::to_string(size)}},
            nullptr};
  }
} // namespace tsil::compiler