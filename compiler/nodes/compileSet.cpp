#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compileSet(x::Function* xFunction,
                                              tsil::x::FunctionBlock* xBlock,
                                              tsil::ast::ASTValue* astValue) {
    const auto setNode = astValue->data.SetNode;
    CompilerValueResult leftResult =
        this->compileValue(xFunction, xBlock, setNode->left);
    if (leftResult.error) {
      return {leftResult.error};
    }
    if (leftResult.type->type != TypeTypeStructureInstance) {
      return {
          CompilerError::fromASTValue(setNode->left, "Тип не є структурою")};
    }
    if (!leftResult.type->structure_instance_fields.contains(setNode->id)) {
      return {CompilerError::fromASTValue(
          astValue, "Властивість \"" + setNode->id + "\" не знайдено")};
    }
    const auto field = leftResult.type->structure_instance_fields[setNode->id];
    const auto valueResult =
        this->compileValue(xFunction, xBlock, setNode->value);
    if (valueResult.error) {
      return {valueResult.error};
    }
    if (valueResult.type != field.type) {
      return {CompilerError::fromASTValue(
          setNode->value, "Невірний тип властивості \"" + setNode->id +
                              "\": очікується \"" + field.type->getFullName() +
                              "\", отримано \"" +
                              valueResult.type->getFullName() + "\"")};
    }
    const auto gepXValue =
        this->state->Module->pushFunctionBlockGetElementPtrInstruction(
            xBlock, leftResult.type->LT, leftResult.LV,
            {0, static_cast<unsigned long>(field.index)});
    this->state->Module->pushFunctionBlockStoreInstruction(
        xBlock, valueResult.type->LT, valueResult.LV, gepXValue);
    return {nullptr};
  }
} // namespace tsil::compiler