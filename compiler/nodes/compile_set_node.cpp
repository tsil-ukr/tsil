#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compile_set_node(
      tsil::ast::ASTValue* ast_value) {
    const auto set_node = ast_value->data.SetNode;
    CompilerValueResult left_result = this->compile_ast_value(set_node->left);
    if (left_result.error) {
      return {left_result.error};
    }
    if (left_result.type->type != TypeTypeStructureInstance) {
      return {new CompilerError("Тип не є структурою")};
    }
    if (!left_result.type->structure_instance_fields.contains(set_node->id)) {
      return {new CompilerError("Властивість \"" + set_node->id +
                                "\" не знайдено")};
    }
    const auto field =
        left_result.type->structure_instance_fields[set_node->id];
    const auto value_result = this->compile_ast_value(set_node->value);
    if (value_result.error) {
      return {value_result.error};
    }
    const auto castedLV =
        value_result.type->castToLV(this, field.type, value_result.LV);
    if (!castedLV) {
      return {new CompilerError("Невірний тип властивості \"" + set_node->id +
                                "\": очікується \"" + field.type->name +
                                "\", отримано \"" + value_result.type->name +
                                "\"")};
    }
    const auto LV = this->state->Builder->CreateGEP(
        left_result.type->LT, left_result.LV,
        {llvm::ConstantInt::get(*this->state->Context, llvm::APInt(32, 0)),
         llvm::ConstantInt::get(*this->state->Context,
                                llvm::APInt(32, field.index))},
        "set");
    this->state->Builder->CreateStore(castedLV, LV);
    return {nullptr};
  }
} // namespace tsil::compiler