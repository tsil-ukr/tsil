#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileAccess(tsil::x::Function* xFunction,
                                           tsil::x::FunctionBlock* xBlock,
                                           ast::ASTValue* astValue,
                                           bool load) {
    const auto accessNode = astValue->data.AccessNode;
    CompilerValueResult leftResult;
    if (accessNode->value->kind == ast::KindIdentifierNode) {
      const auto identifierResult = this->compileIdentifier(
          xFunction, xBlock, accessNode->value, {}, false);
      if (identifierResult.error) {
        return identifierResult;
      }
      leftResult.type = identifierResult.type;
      leftResult.xValue = identifierResult.xValue;
    } else if (accessNode->value->kind == ast::KindGetNode) {
      const auto getResult =
          this->compileGet(xFunction, xBlock, accessNode->value, false);
      if (getResult.error) {
        return getResult;
      }
      leftResult.type = getResult.type;
      leftResult.xValue = getResult.xValue;
    } else if (accessNode->value->kind == ast::KindAccessNode) {
      const auto accessResult =
          this->compileAccess(xFunction, xBlock, accessNode->value, false);
      if (accessResult.error) {
        return accessResult;
      }
      leftResult.type = accessResult.type;
      leftResult.xValue = accessResult.xValue;
    } else {
      const auto valueResult =
          this->compileValue(xFunction, xBlock, accessNode->value, {});
      if (valueResult.error) {
        return leftResult;
      }
      leftResult.type = valueResult.type;
      leftResult.xValue = valueResult.xValue;
    }
    if (leftResult.type->type == TypeTypePointer) {
      const auto indexResult =
          this->compileValue(xFunction, xBlock, accessNode->index, {});
      if (indexResult.error) {
        return indexResult;
      }
      if (!indexResult.type->equals(this->compiler->uint64Type)) {
        return {nullptr, nullptr,
                CompilerError::invalidArgumentType(accessNode->index, "позиція",
                                                   this->compiler->uint64Type,
                                                   indexResult.type)};
      }
      const auto xGepValue =
          this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
              xBlock, leftResult.type->xType, leftResult.xValue,
              {indexResult.xValue});
      if (load) {
        const auto xLoadValue =
            this->compiler->xModule->pushFunctionBlockLoadInstruction(
                xBlock, leftResult.type->pointerTo->xType, xGepValue);
        return {leftResult.type->pointerTo, xLoadValue, nullptr};
      } else {
        return {leftResult.type->pointerTo, xGepValue, nullptr};
      }
    }
    if (leftResult.type->type == TypeTypeArray) {
      const auto indexResult =
          this->compileValue(xFunction, xBlock, accessNode->index, {});
      if (indexResult.error) {
        return indexResult;
      }
      if (!indexResult.type->equals(this->compiler->uint64Type)) {
        return {nullptr, nullptr,
                CompilerError::invalidArgumentType(accessNode->index, "позиція",
                                                   this->compiler->uint64Type,
                                                   indexResult.type)};
      }
      const auto xGepValue =
          this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
              xBlock, leftResult.type->xType, leftResult.xValue,
              {indexResult.xValue});
      if (load) {
        const auto xLoadValue =
            this->compiler->xModule->pushFunctionBlockLoadInstruction(
                xBlock, leftResult.type->arrayOf->xType, xGepValue);
        return {leftResult.type->arrayOf, xLoadValue, nullptr};
      } else {
        return {leftResult.type->arrayOf, xGepValue, nullptr};
      }
    }
    return {nullptr, nullptr,
            CompilerError::cannotAccessNonPointer(accessNode->value,
                                                  leftResult.type)};
  }
} // namespace tsil::tk