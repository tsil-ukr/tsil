#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compile_define_node(
      tsil::ast::ASTValue* ast_value) {
    const auto define_node = ast_value->data.DefineNode;
    if (this->has_variable(define_node->id)) {
      return error("Variable already defined");
    }
    auto value_result = this->compile_ast_value(define_node->value);
    if (value_result.error) {
      return value_result;
    }
    this->set_variable(define_node->id, value_result.result);
    return value_result;
  }
} // namespace tsil::compiler