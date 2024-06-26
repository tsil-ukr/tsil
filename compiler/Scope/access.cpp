#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileAccessGep(tsil::x::Function* xFunction,
                                              tsil::x::FunctionBlock* xBlock,
                                              ast::ASTValue* astValue) {
    const auto accessNode = astValue->data.AccessNode;
    Type* leftType = nullptr;
    x::Value* leftXValue = nullptr;
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
      const auto loadPtrXValue =
          this->compiler->xModule->pushFunctionBlockLoadInstruction(
              xBlock, leftType->xType, leftXValue);
      const auto xGepValue =
          this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
              xBlock, leftType->pointerTo->xType, loadPtrXValue,
              {indexResult.xValue});
      return {leftType->pointerTo, xGepValue, nullptr};
    }
    if (leftType->type == TypeTypeArray) {
      const auto xGepValue =
          this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
              xBlock, leftType->xType, leftXValue,
              {new x::Value(this->compiler->int32Type->xType, "0"),
               indexResult.xValue});
      return {leftType->arrayOf, xGepValue, nullptr};
    }
    return {nullptr, nullptr,
            CompilerError::cannotAccessNonPointer(accessNode->value, leftType)};
  }
} // namespace tsil::tk