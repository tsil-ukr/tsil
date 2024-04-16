#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_get_node(
      tsil::ast::ASTValue* ast_value) {
    const auto get_node = ast_value->data.GetNode;
    const auto left = this->compile_ast_value(get_node->left);
    if (left.error) {
      return left;
    }
    if (!left.type->structure) {
      return {nullptr, nullptr, new CompilerError("Тип не є структурою")};
    }
    const auto LV = this->state->Builder->CreateExtractValue(left.LV, {0});
    return {this->get_type("ц32"), LV, nullptr};
  }
} // namespace tsil::compiler