#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compileCall(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* astValue) {
    const auto callNode = astValue->data.CallNode;
    CompilerValueResult valueResult{};
    if (callNode->value->kind == ast::KindIdentifierNode) {
      const auto name = callNode->value->data.IdentifierNode->name;
      if (name == "комірка") {
        if (callNode->args.size() != 1) {
          return {
              nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue, "Неправильна кількість аргументів для комірки")};
        }
        const auto firstArg = callNode->args[0];
        if (firstArg->kind == ast::KindIdentifierNode) {
          if (this->hasVariable(firstArg->data.IdentifierNode->name)) {
            const auto variable =
                this->getVariable(firstArg->data.IdentifierNode->name);
            return {variable.first->getPointerType(this), variable.second,
                    nullptr};
          }
          return {
              nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue, "Субʼєкт \"" + firstArg->data.IdentifierNode->name +
                                "\" не визначено")};
        }
        return {nullptr, nullptr,
                CompilerError::fromASTValue(astValue,
                                            "Неможливо отримати комірку.")};
      }
      if (name == "вміст") {
        if (callNode->args.size() != 1) {
          return {nullptr, nullptr,
                  CompilerError::fromASTValue(
                      astValue,
                      "Неправильна кількість аргументів для дії \"вміст\"")};
        }
        const auto firstArg = callNode->args[0];
        if (firstArg->kind == ast::KindIdentifierNode) {
          if (this->hasVariable(firstArg->data.IdentifierNode->name)) {
            const auto variable =
                this->getVariable(firstArg->data.IdentifierNode->name);
            if (variable.first->type != TypeTypePointer) {
              return {
                  nullptr, nullptr,
                  CompilerError::fromASTValue(astValue, "Тип не є коміркою")};
            }
            const auto loadXValue =
                this->state->Module->pushFunctionBlockLoadInstruction(
                    block, variable.first->LT, variable.second);
            const auto loadXValue2 =
                this->state->Module->pushFunctionBlockLoadInstruction(
                    block, variable.first->pointer_to->LT, loadXValue);
            return {variable.first->pointer_to, loadXValue2, nullptr};
          }
          return {
              nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue, "Субʼєкт \"" + firstArg->data.IdentifierNode->name +
                                "\" не визначено")};
        }
        return {nullptr, nullptr,
                CompilerError::fromASTValue(astValue,
                                            "Неможливо отримати комірку.")};
      }
      if (this->hasNonVariableSubject(name)) {
        return {nullptr, nullptr,
                CompilerError::subjectIsNotCallable(astValue)};
      }
      if (this->state->diias.contains(name)) {
        std::vector<Type*> genericValues;
        for (const auto& genericASTValue : callNode->generic_values) {
          const auto genericResult =
              this->makeTypeFromTypeNodeASTValue(genericASTValue);
          if (!genericResult.type) {
            return {nullptr, nullptr,
                    CompilerError::fromASTValue(genericASTValue,
                                                genericResult.error)};
          }
          genericValues.push_back(genericResult.type);
        }
        const auto diia = this->state->diias[name];
        valueResult = this->compileDiiaWithGenerics(diia, genericValues);
      }
      if (!this->hasVariable(name)) {
        return {nullptr, nullptr, CompilerError::subjectNotDefined(astValue)};
      }
      const auto variable =
          this->getVariable(callNode->value->data.IdentifierNode->name);
      valueResult = {variable.first, variable.second, nullptr};
    } else {
      valueResult.error = CompilerError::subjectIsNotCallable(astValue);
    }
    if (valueResult.error) {
      return {nullptr, nullptr, valueResult.error};
    }
    if (valueResult.type->type != TypeTypeDiia) {
      return {nullptr, nullptr, CompilerError::subjectIsNotCallable(astValue)};
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