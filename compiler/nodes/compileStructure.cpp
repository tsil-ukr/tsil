#include "../compiler.h"

namespace tsil::compiler {
  CompilerStructureResult CompilationScope::compileStructure(
      tsil::ast::ASTValue* astValue) {
    const auto structureNode = astValue->data.StructureNode;
    if (this->state->predefined_types.contains(structureNode->name)) {
      return {nullptr, CompilerError::fromASTValue(
                           astValue, "Субʼєкт \"" + structureNode->name +
                                         "\" вже визначено")};
    }
    if (this->state->structures.contains(structureNode->name)) {
      return {nullptr, CompilerError::fromASTValue(
                           astValue, "Субʼєкт \"" + structureNode->name +
                                         "\" вже визначено")};
    }
    int paramIndex = 0;
    const auto structure = this->createStructure(
        structureNode->name, structureNode->generic_definitions, {});
    this->state->structures.insert_or_assign(structure->name, structure);
    for (const auto& paramAstValue : structureNode->params) {
      const auto paramNode = paramAstValue->data.ParamNode;
      const auto paramTypeNode = paramNode->type->data.TypeNode;
      const auto paramTypeName = paramTypeNode->id;
      bool processedGenericType = false;
      int genericTypeIndex = 0;
      for (const auto& genericDefinitionName :
           structureNode->generic_definitions) {
        if (genericDefinitionName == paramTypeName) {
          if (!paramTypeNode->generics.empty()) {
            return {nullptr, CompilerError::fromASTValue(
                                 paramNode->type,
                                 "Не можна використовувати назву "
                                 "параметра шаблону як тип з шаблонами")};
          }
          structure->fields.insert_or_assign(
              paramNode->id,
              StructureField{.index = paramIndex,
                             .type = nullptr,
                             .generic_type_index = genericTypeIndex});
          processedGenericType = true;
          break;
        }
        genericTypeIndex++;
      }
      if (!processedGenericType) {
        std::vector<Type*> genericValues;
        for (const auto& genericAstValue : paramTypeNode->generics) {
          const auto genericTypeNode = genericAstValue->data.TypeNode;
          const auto genericTypeResult = this->makeType(
              genericTypeNode->id, {}); // todo: handle inner generics
          if (!genericTypeResult.type) {
            return {nullptr, CompilerError::fromASTValue(
                                 genericAstValue, genericTypeResult.error)};
          }
          genericValues.push_back(genericTypeResult.type);
        }
        const auto typeResult =
            this->makeType(paramTypeNode->id, genericValues);
        if (!typeResult.type) {
          return {nullptr, CompilerError::fromASTValue(paramNode->type,
                                                       typeResult.error)};
        }
        structure->fields.insert_or_assign(
            paramNode->id, StructureField{.index = paramIndex,
                                          .type = typeResult.type,
                                          .generic_type_index = 0});
      }
      paramIndex++;
    }
    return {structure, nullptr};
  }
} // namespace tsil::compiler