#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_get_node(
      x::Function* function,
      tsil::ast::ASTValue* ast_value) {
    const auto get_node = ast_value->data.GetNode;
    CompilerValueResult left =
        this->compile_ast_value(function, get_node->left);
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
    const auto LV =
        this->state->Module->pushFunctionBlockGetElementPtrInstruction(
            function->blocks["entry"], left.type->LT, left.LV,
            {0, static_cast<unsigned long>(field.index)});
    x::Value* loaded_member =
        this->state->Module->pushFunctionBlockLoadInstruction(
            function->blocks["entry"], field.type->LT, LV);
    return {field.type, loaded_member, nullptr};
  }
} // namespace tsil::compiler