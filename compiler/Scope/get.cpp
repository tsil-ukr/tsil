#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileGet(tsil::x::Function* xFunction,
                                        tsil::x::FunctionBlock* xBlock,
                                        ast::ASTValue* astValue,
                                        bool load) {
    const auto getNode = astValue->data.GetNode;
    Type* leftType = nullptr;
    x::Value* leftXValue = nullptr;
    if (getNode->left->kind == ast::KindIdentifierNode) {
      const auto identifierResult =
          this->compileIdentifier(xFunction, xBlock, getNode->left, {}, false);
      if (identifierResult.error) {
        return identifierResult;
      }
      leftType = identifierResult.type;
      leftXValue = identifierResult.xValue;
      goto proceed;
    }
    if (getNode->left->kind == ast::KindGetNode) {
      const auto getLeftResult =
          this->compileGet(xFunction, xBlock, getNode->left, false);
      if (getLeftResult.error) {
        return getLeftResult;
      }
      leftType = getLeftResult.type;
      leftXValue = getLeftResult.xValue;
      goto proceed;
    }
    if (getNode->left->kind == ast::KindAccessNode) {
      const auto accessLeftResult =
          this->compileAccess(xFunction, xBlock, getNode->left, false);
      if (accessLeftResult.error) {
        return accessLeftResult;
      }
      leftType = accessLeftResult.type;
      leftXValue = accessLeftResult.xValue;
      goto proceed;
    }
    return {
        nullptr, nullptr,
        CompilerError::fromASTValue(
            astValue, "NOT IMPLEMENTED GET: " +
                          ast::ast_value_kind_to_string(getNode->left->kind))};
  proceed:
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