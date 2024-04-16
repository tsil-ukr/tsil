#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_get_node(
      tsil::ast::ASTValue* ast_value) {
    const auto get_node = ast_value->data.GetNode;
    CompilerValueResult left = this->compile_ast_value(get_node->left);
    if (left.error) {
      return left;
    }
    if (left.type->type != TypeTypeStructureInstance) {
      return {nullptr, nullptr, new CompilerError("Тип не є структурою")};
    }
    if (!left.type->structure_instance_fields.contains(get_node->id)) {
      return {nullptr, nullptr,
              new CompilerError("Властивість \"" + get_node->id +
                                "\" не знайдено")};
    }
    const auto field = left.type->structure_instance_fields[get_node->id];
    const auto LV = this->state->Builder->CreateGEP(
        left.type->LT, left.LV,
        {llvm::ConstantInt::get(*this->state->Context, llvm::APInt(32, 0)),
         llvm::ConstantInt::get(*this->state->Context,
                                llvm::APInt(32, field.index))},
        "gep");
    llvm::Value* loaded_member =
        this->state->Builder->CreateLoad(field.type->LT, LV);
    return {field.type, loaded_member, nullptr};
  }
} // namespace tsil::compiler