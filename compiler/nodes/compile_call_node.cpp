#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_call_node(
      tsil::ast::ASTValue* ast_value) {
    const auto call_node = ast_value->data.CallNode;
    const auto name = call_node->value->data.IdentifierNode->name;
    if (!this->has_variable(name)) {
      return {nullptr, nullptr,
              new CompilerError("Субʼєкт \"" + name + "\" не визначено")};
    }
    const auto variable = this->get_variable(name);
    const auto diia_parameters = variable.first->diia_parameters;
    const auto diia_result_type = variable.first->diia_result_type;
    if (call_node->args.size() < diia_parameters.size()) {
      return {nullptr, nullptr,
              new CompilerError("Недостатньо аргументів для дії")};
    }
    if (call_node->args.size() > diia_parameters.size()) {
      return {nullptr, nullptr,
              new CompilerError("Забагато аргументів для дії")};
    }
    const auto F = llvm::cast<llvm::Function>(variable.second);
    std::vector<llvm::Value*> LArgs;
    int arg_index = 0;
    for (const auto& arg_ast_value : call_node->args) {
      auto arg_result = this->compile_ast_value(arg_ast_value);
      if (arg_result.error) {
        return arg_result;
      }
      const auto parameter = variable.first->diia_parameters[arg_index];
      const auto casted_LV =
          parameter.type->castToLV(this, arg_result.type, arg_result.LV);
      if (!casted_LV) {
        return {nullptr, nullptr,
                new CompilerError("Невірний тип параметра \"" + parameter.name +
                                  "\" дії \"" + variable.first->name +
                                  "\": очікується \"" + parameter.type->name +
                                  "\", отримано \"" + arg_result.type->name +
                                  "\"")};
      }
      LArgs.push_back(casted_LV);
      arg_index++;
    }
    const auto LV = this->state->Builder->CreateCall(F, LArgs);
    return {variable.first->diia_result_type, LV, nullptr};
  }
} // namespace tsil::compiler