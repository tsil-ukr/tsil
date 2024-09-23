#include "../tk.h"

namespace tsil::tk {
  CompilerResult Scope::compileSet(x2::FunctionX2* xFunction,
                                   x2::FunctionX2Block* xBlock,
                                   ast::ASTValue* astValue) {
    const auto setNode = astValue->data.SetNode;
    Type* leftType = nullptr;
    x2::ValueX2* leftXValue = nullptr;
    const auto leftResult = this->compileLeft(xFunction, xBlock, setNode->left);
    if (leftResult.error) {
      return {leftResult.error};
    }
    leftType = leftResult.type;
    leftXValue = leftResult.xValue;
    if (setNode->access) {
      if (leftType->type == TypeTypeArray) {
        auto indexResult =
            this->compileValueNoVariation(xFunction, xBlock, setNode->access);
        if (indexResult.error) {
          return {indexResult.error};
        }
        const auto castedIndexXValue = this->compileSoftCast(
            xFunction, xBlock, indexResult.type, indexResult.xValue,
            this->compiler->uint64Type);
        if (castedIndexXValue) {
          indexResult.type = this->compiler->uint64Type;
          indexResult.xValue = castedIndexXValue;
        } else {
          return {CompilerError::invalidArgumentType(
              setNode->value, "значення", indexResult.type,
              this->compiler->uint64Type)};
        }
        auto valueResult =
            this->compileValueNoVariation(xFunction, xBlock, setNode->value);
        if (valueResult.error) {
          return {valueResult.error};
        }
        const auto castedXValue =
            this->compileSoftCast(xFunction, xBlock, valueResult.type,
                                  valueResult.xValue, leftType->arrayOf);
        if (castedXValue) {
          valueResult.type = leftType->arrayOf;
          valueResult.xValue = castedXValue;
        } else {
          return {CompilerError::invalidArgumentType(
              setNode->value, "значення", leftType->arrayOf, valueResult.type)};
        }
        const auto gepXValue =
            this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
                xBlock, leftType->xType, leftXValue,
                {x2::CreateInt32(this->compiler->xModule, 0),
                 indexResult.xValue});
        // todo: uncomment
        //        this->compiler->xModule->pushFunctionBlockStoreInstruction(
        //            xBlock, leftType->xType->arrayOf, valueResult.xValue, gepXValue);
        return {nullptr};
      } else if (leftType->type == TypeTypePointer) {
        auto indexResult =
            this->compileValueNoVariation(xFunction, xBlock, setNode->access);
        if (indexResult.error) {
          return {indexResult.error};
        }
        const auto castedIndexXValue = this->compileSoftCast(
            xFunction, xBlock, indexResult.type, indexResult.xValue,
            this->compiler->uint64Type);
        if (castedIndexXValue) {
          indexResult.type = this->compiler->uint64Type;
          indexResult.xValue = castedIndexXValue;
        } else {
          return {CompilerError::invalidArgumentType(
              setNode->value, "значення", indexResult.type,
              this->compiler->uint64Type)};
        }
        auto valueResult =
            this->compileValueNoVariation(xFunction, xBlock, setNode->value);
        if (valueResult.error) {
          return {valueResult.error};
        }
        const auto castedXValue =
            this->compileSoftCast(xFunction, xBlock, valueResult.type,
                                  valueResult.xValue, leftType->pointerTo);
        if (castedXValue) {
          valueResult.type = leftType->pointerTo;
          valueResult.xValue = castedXValue;
        } else {
          return {CompilerError::invalidArgumentType(setNode->value, "значення",
                                                     leftType->pointerTo,
                                                     valueResult.type)};
        }
        const auto loadPtrXValue =
            this->compiler->xModule->pushFunctionBlockLoadInstruction(
                xBlock, leftType->xType, leftXValue);
        const auto gepXValue =
            this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
                xBlock, leftType->pointerTo->xType, loadPtrXValue,
                {indexResult.xValue});
        this->compiler->xModule->pushFunctionBlockStoreInstruction(
            xBlock, leftType->xType->getPointerTo(), valueResult.xValue,
            gepXValue);
        return {nullptr};
      }
    } else {
      if (leftType->type == TypeTypePointer) {
        if (!leftType->pointerTo->structureInstanceFields.contains(
                setNode->id)) {
          return {CompilerError::typeHasNoProperty(
              astValue, leftType->pointerTo, setNode->id)};
        }
        const auto loadPtrXValue =
            this->compiler->xModule->pushFunctionBlockLoadInstruction(
                xBlock, leftType->xType, leftXValue);
        leftType = leftType->pointerTo;
        leftXValue = loadPtrXValue;
      }
      if (leftType->type == TypeTypeStructureInstance) {
        if (!leftType->structureInstanceFields.contains(setNode->id)) {
          return {CompilerError::typeHasNoProperty(astValue, leftType,
                                                   setNode->id)};
        }
        const auto field = leftType->structureInstanceFields[setNode->id];
        auto fieldType = field.type;
        const auto gepXValue =
            this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
                xBlock, leftType->xType, leftXValue,
                {x2::CreateInt32(this->compiler->xModule, 0),
                 x2::CreateInt32(this->compiler->xModule, field.index)});
        auto valueResult =
            this->compileValueNoVariation(xFunction, xBlock, setNode->value);
        if (valueResult.error) {
          return {valueResult.error};
        }
        if (fieldType->type == TypeTypeVariationInstance) {
          for (const auto& variationType : fieldType->variationTypes) {
            if (variationType == valueResult.type) {
              fieldType = variationType;
              break;
            }
          }
        }
        const auto castedXValue = this->compileSoftCast(
            xFunction, xBlock, valueResult.type, valueResult.xValue, fieldType);
        if (castedXValue) {
          valueResult.type = fieldType;
          valueResult.xValue = castedXValue;
        } else {
          return {CompilerError::invalidArgumentType(
              setNode->value, field.name, fieldType, valueResult.type)};
        }
        this->compiler->xModule->pushFunctionBlockStoreInstruction(
            xBlock, fieldType->xType, valueResult.xValue, gepXValue);
        return {nullptr};
      }
    }
    return {CompilerError::typeHasNoProperty(astValue, leftType, setNode->id)};
  }
} // namespace tsil::tk