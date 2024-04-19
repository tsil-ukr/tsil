#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compileGet(
      x::Function* xFunction,
      tsil::x::FunctionBlock* xBlock,
      tsil::ast::ASTValue* astValue) {
    const auto getNode = astValue->data.GetNode;
    CompilerValueResult leftResult =
        this->compileValue(xFunction, xBlock, getNode->left);
    if (leftResult.error) {
      return leftResult;
    }
    if (leftResult.type->type != TypeTypeStructureInstance) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(astValue, "Тип не є структурою")};
    }
    if (!leftResult.type->structure_instance_fields.contains(getNode->id)) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue, "Властивість \"" + getNode->id + "\" не знайдено")};
    }
    const auto field = leftResult.type->structure_instance_fields[getNode->id];
    const auto gepXValue =
        this->state->Module->pushFunctionBlockGetElementPtrInstruction(
            xBlock, leftResult.type->LT, leftResult.LV,
            {0, static_cast<unsigned long>(field.index)});
    const auto loadXValue =
        this->state->Module->pushFunctionBlockLoadInstruction(
            xBlock, gepXValue->type, gepXValue);
    return {field.type, loadXValue, nullptr};
  }
} // namespace tsil::compiler