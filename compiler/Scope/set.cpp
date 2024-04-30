#include "../tk.h"

namespace tsil::tk {
  CompilerResult Scope::compileSet(tsil::x::Function* xFunction,
                                   tsil::x::FunctionBlock* xBlock,
                                   ast::ASTValue* astValue) {
    const auto setNode = astValue->data.SetNode;
    Type* leftType = nullptr;
    x::Value* leftXValue = nullptr;
    const auto leftResult = this->compileLeft(xFunction, xBlock, setNode->left);
    if (leftResult.error) {
      return {leftResult.error};
    }
    leftType = leftResult.type;
    leftXValue = leftResult.xValue;
    if (leftType->isPointer()) {
      leftType = leftType->pointerTo;
    }
    if (leftType->type == TypeTypeStructureInstance) {
      if (!leftType->structureInstanceFields.contains(setNode->id)) {
        return {
            CompilerError::typeHasNoProperty(astValue, leftType, setNode->id)};
      }
      const auto field = leftType->structureInstanceFields[setNode->id];
      const auto gepXValue =
          this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
              xBlock, leftType->xType, leftXValue,
              {new x::Value(this->compiler->int32Type->xType, "0"),
               new x::Value(this->compiler->int32Type->xType,
                            std::to_string(field.index))});
      const auto valueResult =
          this->compileValue(xFunction, xBlock, setNode->value);
      const auto storeXValue =
          this->compiler->xModule->pushFunctionBlockStoreInstruction(
              xBlock, field.type->xType, valueResult.xValue, gepXValue);
      return {nullptr};
    } else {
      if (setNode->access) {
        if (leftType->type == TypeTypeArray) {
          const auto indexResult =
              this->compileValue(xFunction, xBlock, setNode->access);
          if (indexResult.error) {
            return {indexResult.error};
          }
          auto valueResult =
              this->compileValue(xFunction, xBlock, setNode->value);
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
                setNode->value, "значення", leftType->arrayOf,
                valueResult.type)};
          }
          const auto gepXValue =
              this->compiler->xModule
                  ->pushFunctionBlockGetElementPtrInstruction(
                      xBlock, leftType->xType, leftXValue,
                      {new x::Value(this->compiler->int32Type->xType, "0"),
                       indexResult.xValue});
          const auto storeXValue =
              this->compiler->xModule->pushFunctionBlockStoreInstruction(
                  xBlock, leftType->xType->arrayOf, valueResult.xValue,
                  gepXValue);
          return {nullptr};
        }
      }
    }
    return {CompilerError::typeHasNoProperty(astValue, leftType, setNode->id)};
  }
} // namespace tsil::tk