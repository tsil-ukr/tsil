#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_get_pointer_node(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* ast_value) {
    const auto get_pointer_node = ast_value->data.GetPointerNode;
    if (get_pointer_node->value->kind == ast::KindIdentifierNode) {
      const auto identifier_node = get_pointer_node->value->data.IdentifierNode;
      if (this->has_variable(identifier_node->name)) {
        const auto variable = this->get_variable(identifier_node->name);
        return {variable.first, variable.second, nullptr};
      }
      if (this->state->structures.contains(identifier_node->name)) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(
                    get_pointer_node->value,
                    "Субʼєкт \"" + identifier_node->name +
                        "\" не можна використовувати як значення")};
      }
      return {nullptr, nullptr,
              CompilerError::fromASTValue(
                  get_pointer_node->value,
                  "Субʼєкт \"" + identifier_node->name + "\" не визначено")};
    } else if (get_pointer_node->value->kind == ast::KindGetNode) {
      const auto get_node = get_pointer_node->value->data.GetNode;
      CompilerValueResult left =
          this->compile_ast_value(function, block, get_node->left);
      if (left.error) {
        return left;
      }
      if (left.type->type != TypeTypeStructureInstance) {
        return {
            nullptr, nullptr,
            CompilerError::fromASTValue(get_node->left, "Тип не є структурою")};
      }
      if (!left.type->structure_instance_fields.contains(get_node->id)) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(
                    get_pointer_node->value,
                    "Властивість \"" + get_node->id + "\" не знайдено")};
      }
      const auto field = left.type->structure_instance_fields[get_node->id];
      const auto LV =
          this->state->Module->pushFunctionBlockGetElementPtrInstruction(
              block, left.type->LT, left.LV,
              {0, static_cast<unsigned long>(field.index)});
      return {field.type, LV, nullptr};

    } else {
      return this->compile_ast_value(function, block, get_pointer_node->value);
    }
  }
} // namespace tsil::compiler