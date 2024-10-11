#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileAs(tsil::x::Function* xFunction,
                                       tsil::x::FunctionBlock* xBlock,
                                       ast::ASTValue* astValue,
                                       bool load) {
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
    if (valueResult.type->type == TypeTypeVariationInstance) {
      if (valueResult.type->shortTermVariationIndex == -1) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(astValue, "Щось пішло не так")};
      }
      if (valueResult.type->shortTermVariationLeftType == nullptr) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(astValue, "Щось пішло не так")};
      }
      size_t index = 0;
      for (const auto variationType : valueResult.type->variationTypes) {
        if (variationType == typeResult.type) {
          const auto gepXValue =
              this->compiler->xModule
                  ->pushFunctionBlockGetElementPtrInstruction(
                      xBlock,
                      valueResult.type->shortTermVariationLeftType->xType,
                      valueResult.xValue,
                      {new x::Value(this->compiler->int32Type->xType, "0"),
                       new x::Value(
                           this->compiler->int32Type->xType,
                           std::to_string(
                               valueResult.type->shortTermVariationIndex))});
          valueResult.type->shortTermVariationIndex = -1;
          valueResult.type->shortTermVariationLeftType = nullptr;
          if (load) {
            const auto loadXValue =
                this->compiler->xModule->pushFunctionBlockLoadInstruction(
                    xBlock, variationType->xType, gepXValue);
            return {variationType, loadXValue, nullptr};
          }
          return {variationType, gepXValue, nullptr};
        }
        index++;
      }
      return {nullptr, nullptr,
              CompilerError::fromASTValue(astValue, "Щось пішло не так")};
    }
    auto newXValue = this->compileSoftCast(xFunction, xBlock, valueResult.type,
                                           valueResult.xValue, typeResult.type);
    if (newXValue == nullptr) {
      newXValue = this->compileHardCast(xFunction, xBlock, valueResult.type,
                                        valueResult.xValue, typeResult.type);
      if (newXValue == nullptr) {
        return {nullptr, nullptr,
                CompilerError::cannotCast(asNode->value, valueResult.type,
                                          typeResult.type)};
      }
    }
    return {typeResult.type, newXValue, nullptr};
  }
} // namespace tsil::tk