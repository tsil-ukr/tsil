#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileGetGep(x2::FunctionX2* xFunction,
                                           x2::FunctionX2Block* xBlock,
                                           ast::ASTValue* astValue) {
    const auto getNode = astValue->data.GetNode;
    Type* leftType = nullptr;
    x2::ValueX2* leftXValue = nullptr;
    const auto leftResult = this->compileLeft(xFunction, xBlock, getNode->left);
    if (leftResult.error) {
      return leftResult;
    }
    leftType = leftResult.type;
    leftXValue = leftResult.xValue;
    if (leftType->type == TypeTypePointer) {
      if (!leftType->pointerTo->structureInstanceFields.contains(getNode->id)) {
        return {nullptr, nullptr,
                CompilerError::typeHasNoProperty(astValue, leftType->pointerTo,
                                                 getNode->id)};
      }
      const auto loadPtrXValue =
          this->compiler->xModule->pushFunctionBlockLoadInstruction(
              xBlock, leftType->xType, leftXValue);
      leftType = leftType->pointerTo;
      leftXValue = loadPtrXValue;
    }
    if (leftType->type == TypeTypeStructureInstance) {
      if (!leftType->structureInstanceFields.contains(getNode->id)) {
        return {
            nullptr, nullptr,
            CompilerError::typeHasNoProperty(astValue, leftType, getNode->id)};
      }
      const auto field = leftType->structureInstanceFields[getNode->id];
      auto fieldType = field.type;
      if (fieldType->type == TypeTypeVariationInstance) {
        fieldType->shortTermVariationIndex = field.index;
        fieldType->shortTermVariationLeftType = leftType;
        return {fieldType, leftXValue, nullptr};
      }
      const auto gepXValue =
          this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
              xBlock, leftType->xType, leftXValue,
              {x2::CreateInt32(this->compiler->xModule, 0),
               x2::CreateInt32(this->compiler->xModule, field.index)});
      return {fieldType, gepXValue, nullptr};
    }
    if (leftType->type == TypeTypeVariationInstance) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue, "Неможливо використовувати варіацію як значення")};
    }
    return {nullptr, nullptr,
            CompilerError::typeHasNoProperty(astValue, leftType, getNode->id)};
  }
} // namespace tsil::tk