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
      const auto gepXValue =
          this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
              xBlock, leftType->xType, leftXValue,
              {new x::Value(this->compiler->int32Type->xType, "0"),
               new x::Value(this->compiler->int32Type->xType,
                            std::to_string(field.index))});
      return {field.type, gepXValue, nullptr};
    }
    return {nullptr, nullptr,
            CompilerError::typeHasNoProperty(astValue, leftType, getNode->id)};
  }
} // namespace tsil::tk