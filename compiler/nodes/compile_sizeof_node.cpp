#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_sizeof_node(
      tsil::ast::ASTValue* ast_value) {
    const auto sizeof_node = ast_value->data.SizeofNode;
    const auto type_result =
        this->makeTypeFromTypeNodeASTValue(sizeof_node->value);
    if (!type_result.type) {
      return {
          nullptr, nullptr,
          CompilerError::fromASTValue(sizeof_node->value, type_result.error)};
    }
    const auto size = type_result.type->getSizeOf(this);
    const auto xValue = this->state->Module->putI64Constant(size);
    return {this->state->int64Type, xValue, nullptr};
  }
} // namespace tsil::compiler