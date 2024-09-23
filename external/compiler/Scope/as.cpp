#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileAs(XLFunction* xFunction,
                                       XLBasicBlock* xBlock,
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
          const auto gepXValue = tsil_xl_inst_getelementptr(
              this->compiler->xModule, xBlock,
              valueResult.type->shortTermVariationLeftType->xType,
              valueResult.xValue, 2,
              std::vector({tsil_xl_create_int32(this->compiler->xModule, 0),
                           tsil_xl_create_int32(
                               this->compiler->xModule,
                               valueResult.type->shortTermVariationIndex)})
                  .data());
          valueResult.type->shortTermVariationIndex = -1;
          valueResult.type->shortTermVariationLeftType = nullptr;
          if (load) {
            const auto loadXValue =
                tsil_xl_inst_load(this->compiler->xModule, xBlock,
                                  variationType->xType, gepXValue);
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