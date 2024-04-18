#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_constructor_node(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* ast_value) {
    const auto constructor_node = ast_value->data.ConstructorNode;
    const auto type_result =
        this->makeTypeFromTypeNodeASTValue(constructor_node->type);
    if (!type_result.type) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(constructor_node->type,
                                          type_result.error)};
    }
    if (type_result.type->type != TypeTypeStructureInstance) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(constructor_node->type,
                                          "Тип не є структурою")};
    }
    const auto LAI = this->state->Module->pushFunctionBlockAllocaInstruction(
        block, type_result.type->LT);
    for (const auto arg : constructor_node->args) {
      const auto constructor_arg_node = arg->data.ConstructorArgNode;
      if (!type_result.type->structure_instance_fields.contains(
              constructor_arg_node->id)) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(arg, "Властивість \"" +
                                                     constructor_arg_node->id +
                                                     "\" не знайдено")};
      }
      const auto field =
          type_result.type->structure_instance_fields[constructor_arg_node->id];
      const auto value_result =
          this->compile_ast_value(function, block, constructor_arg_node->value);
      if (value_result.error) {
        return {nullptr, nullptr, value_result.error};
      }
      if (value_result.type != field.type) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(
                    constructor_arg_node->value,
                    "Невірний тип властивості \"" + constructor_arg_node->id +
                        "\": очікується \"" + field.type->getFullName() +
                        "\", отримано \"" + value_result.type->getFullName() +
                        "\"")};
      }
      const auto LV =
          this->state->Module->pushFunctionBlockGetElementPtrInstruction(
              block, type_result.type->LT, LAI,
              {0, static_cast<unsigned long>(field.index)});
      this->state->Module->pushFunctionBlockStoreInstruction(
          block, value_result.type->LT, value_result.LV, LV);
    }
    x::Value* loaded_member =
        this->state->Module->pushFunctionBlockLoadInstruction(
            block, type_result.type->LT, LAI);
    return {type_result.type, loaded_member, nullptr};
  }
} // namespace tsil::compiler