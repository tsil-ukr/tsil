#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compile_string_node(
      tsil::ast::ASTValue* ast_value) {
    const auto string_node = ast_value->data.StringNode;
    const auto llval =
        this->state->Builder->CreateGlobalStringPtr(string_node->value);
    return ok(llval, nullptr);
  }
} // namespace tsil::compiler