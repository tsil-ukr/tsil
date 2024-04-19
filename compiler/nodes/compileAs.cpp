#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compileAs(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* astValue) {
    const auto asNode = astValue->data.AsNode;
    const auto leftResult =
        this->compileValue(function, block, asNode->value);
    if (leftResult.error) {
      return leftResult;
    }
    const auto typeResult = this->makeTypeFromTypeNodeASTValue(asNode->type);
    if (!typeResult.type) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(asNode->type, typeResult.error)};
    }
    const auto castedXValue =
        leftResult.type->castToLV(this, typeResult.type, leftResult.LV);
    if (!castedXValue) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue,
                  "Неможливо привести тип \"" + leftResult.type->getFullName() +
                      "\" до типу \"" + typeResult.type->getFullName() + "\"")};
    }
    return {typeResult.type, castedXValue, nullptr};
  }
} // namespace tsil::compiler