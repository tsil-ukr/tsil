#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compileLoad(
      x::Function* xFunction,
      tsil::x::FunctionBlock* xBlock,
      tsil::ast::ASTValue* astValue) {
    const auto identifierNode = astValue->data.IdentifierNode;
    if (this->state->types.contains(identifierNode->name)) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue, "Субʼєкт \"" + identifierNode->name +
                                "\" не можна використовувати як значення")};
    }
    if (this->state->structures.contains(identifierNode->name)) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue, "Субʼєкт \"" + identifierNode->name +
                                "\" не можна використовувати як значення")};
    }
    if (this->has_variable(identifierNode->name)) {
      const auto variable = this->get_variable(identifierNode->name);
      const auto loadXValue =
          this->state->Module->pushFunctionBlockLoadInstruction(
              xBlock, variable.first->LT, variable.second);
      return {variable.first, loadXValue, nullptr};
    }
    return {
        nullptr, nullptr,
        CompilerError::fromASTValue(
            astValue, "Субʼєкт \"" + identifierNode->name + "\" не визначено")};
  }
} // namespace tsil::compiler