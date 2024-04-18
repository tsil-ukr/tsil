#include "../compiler.h"

namespace tsil::compiler {
  CompilerStructureResult CompilationScope::compile_structure_node(
      tsil::ast::ASTValue* ast_value) {
    const auto structure_node = ast_value->data.StructureNode;
    if (this->state->structures.contains(structure_node->name)) {
      return {nullptr, CompilerError::fromASTValue(
                           ast_value, "Субʼєкт \"" + structure_node->name +
                                          "\" вже визначено")};
    }
    int param_index = 0;
    const auto structure = this->createStructure(
        structure_node->name, structure_node->generic_definitions, {});
    this->state->structures.insert_or_assign(structure->name, structure);
    for (const auto& param_ast_value : structure_node->params) {
      const auto param_node = param_ast_value->data.ParamNode;
      const auto param_type_node = param_node->type->data.TypeNode;
      const auto param_type_name = param_type_node->id;
      bool processed_generic_type = false;
      int generic_type_index = 0;
      for (const auto& generic_definition_name :
           structure_node->generic_definitions) {
        if (generic_definition_name == param_type_name) {
          if (!param_type_node->generics.empty()) {
            return {nullptr, CompilerError::fromASTValue(
                                 param_node->type,
                                 "Не можна використовувати назву "
                                 "параметра шаблону як тип з шаблонами")};
          }
          structure->fields.insert_or_assign(
              param_node->id,
              StructureField{.index = param_index,
                             .type = nullptr,
                             .generic_type_index = generic_type_index});
          processed_generic_type = true;
          break;
        }
        generic_type_index++;
      }
      if (!processed_generic_type) {
        std::vector<Type*> generic_values;
        for (const auto& generic_ast_value : param_type_node->generics) {
          const auto generic_type_node = generic_ast_value->data.TypeNode;
          const auto generic_type_result = this->makeType(
              generic_type_node->id, {}); // todo: handle inner generics
          if (!generic_type_result.type) {
            return {nullptr, CompilerError::fromASTValue(
                                 generic_ast_value, generic_type_result.error)};
          }
          generic_values.push_back(generic_type_result.type);
        }
        const auto type_result =
            this->makeType(param_type_node->id, generic_values);
        if (!type_result.type) {
          return {nullptr, CompilerError::fromASTValue(param_node->type,
                                                       type_result.error)};
        }
        structure->fields.insert_or_assign(
            param_node->id, StructureField{.index = param_index,
                                           .type = type_result.type,
                                           .generic_type_index = 0});
      }
      param_index++;
    }
    return {structure, nullptr};
  }
} // namespace tsil::compiler