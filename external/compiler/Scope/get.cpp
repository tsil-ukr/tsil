#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileGetGep(XLFunction* xFunction,
                                           XLBasicBlock* xBlock,
                                           ast::ASTValue* astValue) {
    const auto getNode = astValue->data.GetNode;
    Type* leftType = nullptr;
    XLValue* leftXValue = nullptr;
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
      const auto loadPtrXValue = tsil_xl_inst_load(
          this->compiler->xModule, xBlock, leftType->xType, leftXValue);
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
      const auto gepXValue = tsil_xl_inst_getelementptr(
          this->compiler->xModule, xBlock, leftType->xType, leftXValue, 2,
          std::vector(
              {tsil_xl_create_int32(this->compiler->xModule, 0),
               tsil_xl_create_int32(this->compiler->xModule, field.index)})
              .data());
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