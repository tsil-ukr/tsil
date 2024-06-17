#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileGetGep(tsil::x::Function* xFunction,
                                           tsil::x::FunctionBlock* xBlock,
                                           ast::ASTValue* astValue) {
    const auto getNode = astValue->data.GetNode;
    Type* leftType = nullptr;
    x::Value* leftXValue = nullptr;
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
              {new x::Value(this->compiler->int32Type->xType, "0"),
               new x::Value(this->compiler->int32Type->xType,
                            std::to_string(field.index))});
      return {fieldType, gepXValue, nullptr};
    }
    if (leftType->type == TypeTypeVariationInstance) {
      if (!leftType->variationInstanceFields.contains(getNode->id)) {
        return {
            nullptr, nullptr,
            CompilerError::typeHasNoProperty(astValue, leftType, getNode->id)};
      }
      const auto field = leftType->variationInstanceFields[getNode->id];
      auto fieldType = field.type;
      if (leftType->shortTermVariationIndex == -1) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(astValue, "Щось пішло не так")};
      }
      if (leftType->shortTermVariationLeftType == nullptr) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(astValue, "Щось пішло не так")};
      }
      const auto gepXValue =
          this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
              xBlock, leftType->shortTermVariationLeftType->xType, leftXValue,
              {new x::Value(this->compiler->int32Type->xType, "0"),
               new x::Value(
                   this->compiler->int32Type->xType,
                   std::to_string(leftType->shortTermVariationIndex))});
      leftType->shortTermVariationIndex = -1;
      leftType->shortTermVariationLeftType = nullptr;
      return {fieldType, gepXValue, nullptr};
    }
    return {nullptr, nullptr,
            CompilerError::typeHasNoProperty(astValue, leftType, getNode->id)};
  }
} // namespace tsil::tk