#include "tk.h"

namespace tsil::tk {
  x::Value* Compiler::ensureCallocConnected() {
    if (this->callocXValue == nullptr) {
      const auto numberofblocksXValue = new x::Value(
          this->uint64Type->xType, this->xModule->computeNextVarName("arg"));
      const auto sizeOfBlockXValue = new x::Value(
          this->uint64Type->xType, this->xModule->computeNextVarName("arg"));
      const auto& [xFunction, xValue] = this->xModule->declareFunction(
          "", "calloc", this->pointerType->xType,
          {numberofblocksXValue, sizeOfBlockXValue});
      this->callocXValue = xValue;
    }
    return this->callocXValue;
  }

  x::Value* Compiler::ensureMallocConnected() {
    if (this->mallocXValue == nullptr) {
      const auto sizeXValue = new x::Value(
          this->uint64Type->xType, this->xModule->computeNextVarName("arg"));
      const auto& [xFunction, xValue] = this->xModule->declareFunction(
          "", "malloc", this->pointerType->xType, {sizeXValue});
      this->mallocXValue = xValue;
    }
    return this->mallocXValue;
  }

  x::Value* Compiler::ensureReallocConnected() {
    if (this->reallocXValue == nullptr) {
      const auto pointerXValue = new x::Value(
          this->pointerType->xType, this->xModule->computeNextVarName("arg"));
      const auto sizeXValue = new x::Value(
          this->uint64Type->xType, this->xModule->computeNextVarName("arg"));
      const auto& [xFunction, xValue] = this->xModule->declareFunction(
          "", "realloc", this->pointerType->xType, {pointerXValue, sizeXValue});
      this->reallocXValue = xValue;
    }
    return this->reallocXValue;
  }

  x::Value* Compiler::ensureFreeConnected() {
    if (this->freeXValue == nullptr) {
      const auto pointerXValue = new x::Value(
          this->pointerType->xType, this->xModule->computeNextVarName("arg"));
      const auto& [xFunction, xValue] = this->xModule->declareFunction(
          "", "free", this->voidType->xType, {pointerXValue});
      this->freeXValue = xValue;
    }
    return this->freeXValue;
  }
} // namespace tsil::tk