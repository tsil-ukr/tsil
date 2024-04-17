#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_as_node(
      x::Function* function,
      tsil::ast::ASTValue* ast_value) {
    const auto as_node = ast_value->data.AsNode;
    const auto left_result = this->compile_ast_value(function, as_node->value);
    if (left_result.error) {
      return left_result;
    }
    const auto type_result = this->makeTypeFromTypeNodeASTValue(as_node->type);
    if (!type_result.type) {
      return {nullptr, nullptr, new CompilerError(type_result.error)};
    }
    const auto castedLV =
        left_result.type->castToLV(this, type_result.type, left_result.LV);
    if (!castedLV) {
      return {nullptr, nullptr, new CompilerError("Неможливо привести тип")};
    }
    return {type_result.type, castedLV, nullptr};
  }
} // namespace tsil::compiler