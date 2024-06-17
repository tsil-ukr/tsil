#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileAs(tsil::x::Function* xFunction,
                                       tsil::x::FunctionBlock* xBlock,
                                       ast::ASTValue* astValue) {
    const auto asNode = astValue->data.AsNode;
    const auto valueResult =
        this->compileValue(xFunction, xBlock, asNode->value);
    if (valueResult.error) {
      return valueResult;
    }
    const auto typeResult = this->bakeType(asNode->type);
    if (!typeResult.type) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(asNode->type, typeResult.error)};
    }
    auto newXValue = this->compileSoftCast(xFunction, xBlock, valueResult.type,
                                           valueResult.xValue, typeResult.type);
    if (newXValue == nullptr) {
      newXValue = this->compileHardCast(xFunction, xBlock, valueResult.type,
                                        valueResult.xValue, typeResult.type);
      if (newXValue == nullptr) {
        return {
            nullptr, nullptr,
            CompilerError::cannotCast(
                asNode->value, valueResult.type, typeResult.type)};
      }
    }
    return {typeResult.type, newXValue, nullptr};
  }
} // namespace tsil::tk