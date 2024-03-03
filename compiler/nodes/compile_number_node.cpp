#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compile_number_node(
      tsil::ast::ASTValue* ast_value) {
    const auto number_node = ast_value->data.NumberNode;
    const double value = std::stod(number_node->value);
    const auto llval =
        llvm::ConstantFP::get(*state->Context, llvm::APFloat(value));
    return ok(llval, nullptr);
  }
} // namespace tsil::compiler