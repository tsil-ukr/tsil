#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_identifier_node(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* ast_value) {
    const auto identifier_node = ast_value->data.IdentifierNode;
    if (this->has_variable(identifier_node->name)) {
      const auto variable = this->get_variable(identifier_node->name);
      const auto LV = this->state->Module->pushFunctionBlockLoadInstruction(
          block, variable.first->LT, variable.second);
      return {variable.first, LV, nullptr};
    }
    if (this->state->structures.contains(identifier_node->name)) {
      return {nullptr, nullptr,
              new CompilerError("Субʼєкт \"" + identifier_node->name +
                                "\" не можна використовувати як значення")};
    }
    return {nullptr, nullptr,
            new CompilerError("Субʼєкт \"" + identifier_node->name +
                              "\" не визначено")};
  }
} // namespace tsil::compiler