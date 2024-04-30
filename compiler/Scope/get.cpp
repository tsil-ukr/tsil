#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileGet(tsil::x::Function* xFunction,
                                        tsil::x::FunctionBlock* xBlock,
                                        ast::ASTValue* astValue,
                                        bool load) {
    const auto getNode = astValue->data.GetNode;
    Type* leftType = nullptr;
    x::Value* leftXValue = nullptr;
    const auto leftResult = this->compileLeft(xFunction, xBlock, getNode->left);
    if (leftResult.error) {
      return leftResult;
    }
    leftType = leftResult.type;
    leftXValue = leftResult.xValue;
    bool isPointer = leftType->isPointer();
    if (leftType->isPointer()) {
      leftType = leftType->pointerTo;
    }
    if (leftType->type == TypeTypeStructureInstance) {
      if (!leftType->structureInstanceFields.contains(getNode->id)) {
        return {
            nullptr, nullptr,
            CompilerError::typeHasNoProperty(astValue, leftType, getNode->id)};
      }
      const auto field = leftType->structureInstanceFields[getNode->id];
      x::Value* gepXValue = nullptr;
      gepXValue =
          this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
              xBlock, leftType->xType, leftXValue,
              {new x::Value(this->compiler->int32Type->xType, "0"),
               new x::Value(this->compiler->int32Type->xType,
                            std::to_string(field.index))});
      if (load) {
        const auto loadXValue =
            this->compiler->xModule->pushFunctionBlockLoadInstruction(
                xBlock, field.type->xType, gepXValue);
        return {field.type, loadXValue, nullptr};
      } else {
        return {field.type, gepXValue, nullptr};
      }
    }
    return {nullptr, nullptr,
            CompilerError::typeHasNoProperty(astValue, leftType, getNode->id)};
  }
} // namespace tsil::tk