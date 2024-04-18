#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compile_set_node(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* ast_value) {
    const auto set_node = ast_value->data.SetNode;
    CompilerValueResult left_result =
        this->compile_ast_value(function, block, set_node->left);
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
    const auto value_result =
        this->compile_ast_value(function, block, set_node->value);
    if (value_result.error) {
      return {value_result.error};
    }
    if (value_result.type != field.type) {
      return {new CompilerError("Невірний тип властивості \"" + set_node->id +
                                "\": очікується \"" +
                                field.type->getFullName() + "\", отримано \"" +
                                value_result.type->getFullName() + "\"")};
    }
    const auto LV =
        this->state->Module->pushFunctionBlockGetElementPtrInstruction(
            block, left_result.type->LT, left_result.LV,
            {0, static_cast<unsigned long>(field.index)});
    this->state->Module->pushFunctionBlockStoreInstruction(
        block, value_result.LV, LV);
    return {nullptr};
  }
} // namespace tsil::compiler