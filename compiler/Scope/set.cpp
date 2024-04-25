#include "../tk.h"

namespace tsil::tk {
  CompilerResult Scope::compileSet(tsil::x::Function* xFunction,
                                   tsil::x::FunctionBlock* xBlock,
                                   ast::ASTValue* astValue) {
    const auto setNode = astValue->data.SetNode;
    Type* leftType = nullptr;
    x::Value* leftXValue = nullptr;
    if (setNode->left->kind == ast::KindIdentifierNode) {
      const auto identifierNode = setNode->left->data.IdentifierNode;
      const auto subjectResult =
          this->getSubjectByName(setNode->left, identifierNode->name, {});
      if (subjectResult.error) {
        return {subjectResult.error};
      }
      if (subjectResult.what != CompilerSubjectResultWhatVariable &&
          subjectResult.what != CompilerSubjectResultWhatDiia) {
        return {CompilerError::subjectIsNotRuntimeValue(setNode->left)};
      }
      leftType = subjectResult.type;
      leftXValue = subjectResult.xValue;
    } else if (setNode->left->kind == ast::KindGetNode) {
      const auto getLeftResult =
          this->compileGet(xFunction, xBlock, setNode->left, false);
      if (getLeftResult.error) {
        return {getLeftResult.error};
      }
      leftType = getLeftResult.type;
      leftXValue = getLeftResult.xValue;
    } else if (setNode->left->kind == ast::KindAccessNode) {
      const auto accessLeftResult =
          this->compileAccess(xFunction, xBlock, setNode->left, false);
      if (accessLeftResult.error) {
        return {accessLeftResult.error};
      }
      leftType = accessLeftResult.type;
      leftXValue = accessLeftResult.xValue;
    } else {
      const auto valueResult =
          this->compileValue(xFunction, xBlock, setNode->left, {});
      if (valueResult.error) {
        return {valueResult.error};
      }
      leftType = valueResult.type;
      leftXValue = valueResult.xValue;
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
          this->compileValue(xFunction, xBlock, setNode->value, {});
      const auto storeXValue =
          this->compiler->xModule->pushFunctionBlockStoreInstruction(
              xBlock, field.type->xType, valueResult.xValue, gepXValue);
      return {nullptr};
    } else {
      if (setNode->access) {
        if (leftType->type == TypeTypeArray) {
          const auto indexResult =
              this->compileValue(xFunction, xBlock, setNode->access, {});
          if (indexResult.error) {
            return {indexResult.error};
          }
          auto valueResult =
              this->compileValue(xFunction, xBlock, setNode->value, {});
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
                      {indexResult.xValue});
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