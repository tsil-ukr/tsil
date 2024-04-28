#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileAccess(tsil::x::Function* xFunction,
                                           tsil::x::FunctionBlock* xBlock,
                                           ast::ASTValue* astValue,
                                           bool load) {
    const auto accessNode = astValue->data.AccessNode;
    Type* leftType = nullptr;
    x::Value* leftXValue = nullptr;
    if (accessNode->value->kind == ast::KindIdentifierNode) {
      const auto subjectResult =
          this->getRuntimeSubjectByIdentifierNodeAstValue(accessNode->value);
      if (subjectResult.error) {
        return {nullptr, nullptr, subjectResult.error};
      }
      leftType = subjectResult.type;
      leftXValue = subjectResult.xValue;
    } else if (accessNode->value->kind == ast::KindGetNode) {
      const auto getResult =
          this->compileGet(xFunction, xBlock, accessNode->value, false);
      if (getResult.error) {
        return getResult;
      }
      leftType = getResult.type;
      leftXValue = getResult.xValue;
    } else if (accessNode->value->kind == ast::KindAccessNode) {
      const auto accessResult =
          this->compileAccess(xFunction, xBlock, accessNode->value, false);
      if (accessResult.error) {
        return accessResult;
      }
      leftType = accessResult.type;
      leftXValue = accessResult.xValue;
    } else {
      const auto valueResult =
          this->compileValue(xFunction, xBlock, accessNode->value);
      if (valueResult.error) {
        return valueResult;
      }
      leftType = valueResult.type;
      leftXValue = valueResult.xValue;
    }
    if (leftType->type == TypeTypePointer) {
      auto indexResult =
          this->compileValue(xFunction, xBlock, accessNode->index);
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
      const auto xGepValue =
          this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
              xBlock, leftType->xType, leftXValue, {indexResult.xValue});
      if (load) {
        const auto xLoadValue =
            this->compiler->xModule->pushFunctionBlockLoadInstruction(
                xBlock, leftType->pointerTo->xType, xGepValue);
        return {leftType->pointerTo, xLoadValue, nullptr};
      } else {
        return {leftType->pointerTo, xGepValue, nullptr};
      }
    }
    if (leftType->type == TypeTypeArray) {
      auto indexResult =
          this->compileValue(xFunction, xBlock, accessNode->index);
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
      const auto xGepValue =
          this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
              xBlock, leftType->xType, leftXValue, {indexResult.xValue});
      if (load) {
        const auto xLoadValue =
            this->compiler->xModule->pushFunctionBlockLoadInstruction(
                xBlock, leftType->arrayOf->xType, xGepValue);
        return {leftType->arrayOf, xLoadValue, nullptr};
      } else {
        return {leftType->arrayOf, xGepValue, nullptr};
      }
    }
    return {nullptr, nullptr,
            CompilerError::cannotAccessNonPointer(accessNode->value, leftType)};
  }
} // namespace tsil::tk