#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_call_node(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* ast_value) {
    const auto call_node = ast_value->data.CallNode;
    const auto name = call_node->value->data.IdentifierNode->name;
    if (!this->has_variable(name)) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(
                  ast_value, "Субʼєкт \"" + name + "\" не визначено")};
    }
    const auto variable = this->get_variable(name);
    const auto diia_parameters = variable.first->diia_parameters;
    const auto diia_result_type = variable.first->diia_result_type;
    if (call_node->args.size() < diia_parameters.size()) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(ast_value,
                                          "Недостатньо аргументів для дії")};
    }
    if (call_node->args.size() > diia_parameters.size()) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(ast_value,
                                          "Забагато аргументів для дії")};
    }
    std::vector<x::Value*> LArgs;
    int arg_index = 0;
    for (const auto& arg_ast_value : call_node->args) {
      auto arg_result = this->compile_ast_value(function, block, arg_ast_value);
      if (arg_result.error) {
        return arg_result;
      }
      const auto parameter = variable.first->diia_parameters[arg_index];
      if (arg_result.type != parameter.type) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(
                    arg_ast_value,
                    "Невірний тип параметра \"" + parameter.name + "\" дії \"" +
                        variable.first->getFullName() + "\": очікується \"" +
                        parameter.type->getFullName() + "\", отримано \"" +
                        arg_result.type->getFullName() + "\"")};
      }
      LArgs.push_back(arg_result.LV);
      arg_index++;
    }
    const auto LV = this->state->Module->pushFunctionBlockCallInstruction(
        block, variable.first->diia_result_type->LT, variable.second, LArgs);
    return {variable.first->diia_result_type, LV, nullptr};
  }
} // namespace tsil::compiler