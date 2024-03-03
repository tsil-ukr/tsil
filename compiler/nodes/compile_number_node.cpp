#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compile_number_node(
      tsil::ast::ASTValue* ast_value) {
    const auto number_node = ast_value->data.NumberNode;
    const auto value = std::stol(number_node->value);
    const auto llval =
        llvm::ConstantInt::get(*state->Context, llvm::APInt(64, value));
    return ok(llval, nullptr);
  }
} // namespace tsil::compiler