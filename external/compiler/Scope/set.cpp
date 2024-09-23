#include "../tk.h"

namespace tsil::tk {
  CompilerResult Scope::compileSet(XLFunction* xFunction,
                                   XLBasicBlock* xBlock,
                                   ast::ASTValue* astValue) {
    const auto setNode = astValue->data.SetNode;
    Type* leftType = nullptr;
    XLValue* leftXValue = nullptr;
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
        const auto gepXValue = tsil_xl_inst_getelementptr(
            this->compiler->xModule, xBlock, leftType->xType, leftXValue, 2,
            std::vector({tsil_xl_create_int32(this->compiler->xModule, 0),
                         indexResult.xValue})
                .data());
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
        const auto loadPtrXValue = tsil_xl_inst_load(
            this->compiler->xModule, xBlock, leftType->xType, leftXValue);
        const auto gepXValue = tsil_xl_inst_getelementptr(
            this->compiler->xModule, xBlock, leftType->pointerTo->xType,
            loadPtrXValue, 1, std::vector({indexResult.xValue}).data());
        tsil_xl_inst_store(this->compiler->xModule, xBlock, valueResult.xValue,
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
        const auto loadPtrXValue = tsil_xl_inst_load(
            this->compiler->xModule, xBlock, leftType->xType, leftXValue);
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
        const auto gepXValue = tsil_xl_inst_getelementptr(
            this->compiler->xModule, xBlock, leftType->xType, leftXValue, 2,
            std::vector(
                {tsil_xl_create_int32(this->compiler->xModule, 0),
                 tsil_xl_create_int32(this->compiler->xModule, field.index)})
                .data());
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
        tsil_xl_inst_store(this->compiler->xModule, xBlock, valueResult.xValue,
                           gepXValue);
        return {nullptr};
      }
    }
    return {CompilerError::typeHasNoProperty(astValue, leftType, setNode->id)};
  }
} // namespace tsil::tk