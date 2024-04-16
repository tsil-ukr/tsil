#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_get_node(
      tsil::ast::ASTValue* ast_value) {
    const auto get_node = ast_value->data.GetNode;
    CompilerValueResult left;
    if (get_node->left->kind == tsil::ast::KindIdentifierNode) {
      if (!this->has_variable(get_node->left->data.IdentifierNode->name)) {
        return {nullptr, nullptr,
                new CompilerError("Ціль \"" +
                                  get_node->left->data.IdentifierNode->name +
                                  "\" не визначено")};
      }
      const auto variable =
          this->get_variable(get_node->left->data.IdentifierNode->name);
      left = {variable.first, variable.second, nullptr};
    } else {
      left = this->compile_ast_value(get_node->left);
      if (left.error) {
        return left;
      }
    }
    if (!left.type->structure) {
      return {nullptr, nullptr, new CompilerError("Тип не є структурою")};
    }
    const auto LV = this->state->Builder->CreateGEP(
        left.type->LT, left.LV,
        {llvm::ConstantInt::get(*this->state->Context, llvm::APInt(32, 0)),
         llvm::ConstantInt::get(*this->state->Context, llvm::APInt(32, 0))},
        "g");
    llvm::Value* loaded_member =
        this->state->Builder->CreateLoad(left.type->LT, LV);
    return {left.type, loaded_member, nullptr};
  }
} // namespace tsil::compiler