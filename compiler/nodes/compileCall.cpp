#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compileCall(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* astValue) {
    const auto callNode = astValue->data.CallNode;
    CompilerValueResult valueResult{};
    if (callNode->value->kind == ast::KindIdentifierNode) {
      if (this->state->types.contains(
              callNode->value->data.IdentifierNode->name)) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(
                    astValue, "Неможливо викликати субʼєкт тип.")};
      }
      if (this->state->structures.contains(
              callNode->value->data.IdentifierNode->name)) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(
                    astValue, "Неможливо викликати субʼєкт структуру.")};
      }
      if (!this->has_variable(callNode->value->data.IdentifierNode->name)) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(
                    astValue, "Субʼєкт \"" +
                                  callNode->value->data.IdentifierNode->name +
                                  "\" не визначено")};
      }
      const auto variable =
          this->get_variable(callNode->value->data.IdentifierNode->name);
      valueResult = {variable.first, variable.second, nullptr};
    } else {
      // todo: need to check more cases
      valueResult = this->compileValue(function, block, callNode->value);
    }
    if (valueResult.error) {
      return {nullptr, nullptr, valueResult.error};
    }
    if (valueResult.type->type != TypeTypeDiia) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue, "Неможливо викликати \"" +
                                valueResult.type->getFullName() + "\"")};
    }
    const auto diiaParameters = valueResult.type->diia_parameters;
    const auto diiaResultType = valueResult.type->diia_result_type;
    if (callNode->args.size() < diiaParameters.size()) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue, "Недостатньо аргументів для виконання дії")};
    }
    if (callNode->args.size() > diiaParameters.size()) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue, "Забагато аргументів для виконання дії")};
    }
    std::vector<x::Value*> xArgs;
    int argIndex = 0;
    for (const auto& argAstValue : callNode->args) {
      const auto argResult = this->compileValue(function, block, argAstValue);
      if (argResult.error) {
        return argResult;
      }
      const auto& diiaParameter = diiaParameters[argIndex];
      if (argResult.type != diiaParameter.type) {
        return {
            nullptr, nullptr,
            CompilerError::fromASTValue(
                argAstValue,
                "Невірний тип параметра \"" + diiaParameter.name +
                    "\": очікується \"" + diiaParameter.type->getFullName() +
                    "\", отримано \"" + argResult.type->getFullName() + "\"")};
      }
      xArgs.push_back(argResult.LV);
      argIndex++;
    }
    const auto xValue = this->state->Module->pushFunctionBlockCallInstruction(
        block, diiaResultType->LT, valueResult.LV, xArgs);
    return {diiaResultType, xValue, nullptr};
  }
} // namespace tsil::compiler