#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compile_identifier_node(
      tsil::ast::ASTValue* ast_value) {
    const auto identifier_node = ast_value->data.IdentifierNode;
    if (!this->has_variable(identifier_node->name)) {
      return error("Ціль \"" + identifier_node->name + "\" не визначена");
    }
    const auto value = this->get_variable(identifier_node->name);
    return {value, nullptr};
  }
} // namespace tsil::compiler