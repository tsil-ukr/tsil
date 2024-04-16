#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_set_node(
      tsil::ast::ASTValue* ast_value) {
    const auto set_node = ast_value->data.SetNode;
    CompilerValueResult left = this->compile_ast_value(set_node->left);
    if (left.error) {
      return left;
    }
    if (left.type->type != TypeTypeStructureInstance) {
      return {nullptr, nullptr, new CompilerError("Тип не є структурою")};
    }
    if (!left.type->structure_instance_fields.contains(set_node->id)) {
      return {nullptr, nullptr,
              new CompilerError("Властивість \"" + set_node->id +
                                "\" не знайдено")};
    }
    const auto field = left.type->structure_instance_fields[set_node->id];
    const auto value = this->compile_ast_value(set_node->value);
    if (value.error) {
      return value;
    }
    const auto LV = this->state->Builder->CreateGEP(
        left.type->LT, left.LV,
        {llvm::ConstantInt::get(*this->state->Context, llvm::APInt(32, 0)),
         llvm::ConstantInt::get(*this->state->Context,
                                llvm::APInt(32, field.index))},
        "set");
    this->state->Builder->CreateStore(value.LV, LV);
    return {this->makeType("ц64", {}).type, value.LV, nullptr};
  }
} // namespace tsil::compiler