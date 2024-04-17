#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_number_node(
      tsil::ast::ASTValue* ast_value) {
    const auto number_node = ast_value->data.NumberNode;
    const auto value = std::stol(number_node->value);
    const auto LV =
        llvm::ConstantInt::get(*state->Context, llvm::APInt(64, value));
    return {this->state->int64Type, LV, nullptr};
  }
} // namespace tsil::compiler