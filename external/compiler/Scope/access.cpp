#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileAccessGep(XLFunction* xFunction,
                                              XLBasicBlock* xBlock,
                                              ast::ASTValue* astValue) {
    const auto accessNode = astValue->data.AccessNode;
    Type* leftType = nullptr;
    XLValue* leftXValue = nullptr;
    const auto leftResult =
        this->compileLeft(xFunction, xBlock, accessNode->value);
    if (leftResult.error) {
      return leftResult;
    }
    leftType = leftResult.type;
    leftXValue = leftResult.xValue;
    auto indexResult =
        this->compileValueNoVariation(xFunction, xBlock, accessNode->index);
    if (indexResult.error) {
      return indexResult;
    }
    const auto castedXValue =
        this->compileSoftCast(xFunction, xBlock, indexResult.type,
                              indexResult.xValue, this->compiler->uint64Type);
    if (castedXValue) {
      indexResult.type = this->compiler->uint64Type;
      indexResult.xValue = castedXValue;
    } else {
      return {nullptr, nullptr,
              CompilerError::invalidArgumentType(accessNode->index, "позиція",
                                                 this->compiler->uint64Type,
                                                 indexResult.type)};
    }
    if (leftType->type == TypeTypePointer) {
      const auto loadPtrXValue = tsil_xl_inst_load(
          this->compiler->xModule, xBlock, leftType->getAllocaXLType(this), leftXValue);
      const auto xGepValue = tsil_xl_inst_getelementptr(
          this->compiler->xModule, xBlock, leftType->pointerTo->xType,
          loadPtrXValue, 1, std::vector({indexResult.xValue}).data());
      return {leftType->pointerTo, xGepValue, nullptr};
    }
    if (leftType->type == TypeTypeArray) {
      const auto xGepValue = tsil_xl_inst_getelementptr(
          this->compiler->xModule, xBlock, leftType->xType, leftXValue, 2,
          std::vector({tsil_xl_create_int32(this->compiler->xModule, 0),
                       indexResult.xValue})
              .data());
      return {leftType->arrayOf, xGepValue, nullptr};
    }
    return {nullptr, nullptr,
            CompilerError::cannotAccessNonPointer(accessNode->value, leftType)};
  }
} // namespace tsil::tk