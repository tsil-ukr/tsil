#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compileAssign(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* astValue) {
    const auto assignNode = astValue->data.AssignNode;
    if (this->hasNonVariableSubject(assignNode->id)) {
      return {CompilerError::fromASTValue(
          astValue,
          "Неможливо перевизначити субʼєкт \"" + assignNode->id + "\"")};
    }
    if (!this->hasVariable(assignNode->id)) {
      return {CompilerError::fromASTValue(
          astValue, "Субʼєкт \"" + assignNode->id + "\" не визначено")};
    }
    const auto& [variableType, variableXValue] =
        this->getVariable(assignNode->id);
    if (variableType->type == TypeTypeDiia) {
      return {CompilerError::fromASTValue(
          astValue,
          "Неможливо перевизначити субʼєкт \"" + assignNode->id + "\"")};
    }
    const auto valueResult =
        this->compileValue(function, block, assignNode->value);
    if (valueResult.error) {
      return {valueResult.error};
    }
    this->state->Module->pushFunctionBlockStoreInstruction(
        block, valueResult.type->LT, valueResult.LV, variableXValue);
    return {nullptr};
  }
} // namespace tsil::compiler