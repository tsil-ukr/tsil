#include "../tk.h"

namespace tsil::tk {
  BakedTypeResult Scope::bakeType(ast::ASTValue* astValue) {
    if (astValue->kind == ast::KindTypeNode) {
      const auto typeNode = astValue->data.TypeNode;
      const auto scope = this;
      std::string typeId;
      if (typeNode->id->kind == ast::KindIdentifierNode) {
        typeId = typeNode->id->data.IdentifierNode->name;
      } else {
        return {nullptr, "NOT IMPLEMENTED BAKED SECTION TYPE"};
      }
      std::vector<Type*> genericValues;
      for (const auto& genericAstValue : typeNode->generics) {
        const auto genericTypeResult = scope->bakeType(genericAstValue);
        if (!genericTypeResult.type) {
          return {nullptr, genericTypeResult.error};
        }
        genericValues.push_back(genericTypeResult.type);
      }
      if (scope->hasBakedType(typeId, genericValues)) {
        const auto type = scope->getBakedType(typeId, genericValues);
        return {type, ""};
      }
      if (typeId == "комірка") {
        if (genericValues.empty()) {
          return {scope->compiler->pointerType};
        }
        const auto type = genericValues[0]->getPointerType(scope);
        return {type, ""};
      }
      if (scope->hasRawType(typeId)) {
        const auto rawType = scope->getRawType(typeId);
        if (rawType->kind == ast::KindStructureNode) {
          const auto structureNode = rawType->data.StructureNode;
          if (structureNode->generic_definitions.size() !=
              genericValues.size()) {
            return {nullptr,
                    "Кількість параметрів шаблону структури не "
                    "співпадає з кількістю переданих параметрів"};
          }
          const auto scopeWithGenerics = new Scope(scope->compiler, scope);
          int genericIndex = 0;
          for (const auto& genericDefinition :
               structureNode->generic_definitions) {
            const auto genericType = genericValues[genericIndex];
            scopeWithGenerics->bakedTypes[{genericDefinition, {}}] =
                genericType;
            genericIndex++;
          }
          const auto type = new Type();
          type->type = TypeTypeStructureInstance;
          type->name = structureNode->name;
          type->genericValues = genericValues;
          scopeWithGenerics->compiler->globalScope->bakedTypes.insert_or_assign(
              {structureNode->name, genericValues}, type);
          std::vector<x::Type*> xFields(structureNode->params.size());
          int paramIndex = 0;
          for (const auto& paramAstValue : structureNode->params) {
            const auto paramNode = paramAstValue->data.ParamNode;
            const auto paramTypeResult =
                scopeWithGenerics->bakeType(paramNode->type);
            if (!paramTypeResult.type) {
              return {nullptr, paramTypeResult.error};
            }
            const auto field = TypeStructureField{
                .index = paramIndex,
                .type = paramTypeResult.type,
                .name = paramNode->id,
            };
            type->structureInstanceFields[paramNode->id] = field;
            xFields[paramIndex] = field.type->xType;
            paramIndex++;
          }
          type->xType = scopeWithGenerics->compiler->xModule->defineStructType(
              structureNode->name, xFields);
          return {type, ""};
        }
      }
    }
    if (astValue->kind == ast::KindFunctionTypeNode) {
      const auto functionTypeNode = astValue->data.FunctionTypeNode;
      const auto type = new Type();
      type->type = TypeTypeDiia;
      type->name = "";
      type->xType = this->compiler->xModule->pointerType;
      int argIndex = 0;
      for (const auto& paramAstValue : functionTypeNode->args) {
        const auto typeResult = this->bakeType(paramAstValue);
        if (!typeResult.type) {
          return {nullptr, typeResult.error};
        }
        const auto paramXValue =
            new x::Value(typeResult.type->xType,
                         this->compiler->xModule->computeNextVarName("arg"));
        type->diiaParameters.push_back(
            TypeDiiaParameter{.name = std::to_string(argIndex),
                              .type = typeResult.type,
                              .xValue = paramXValue});
        argIndex++;
      }
      if (functionTypeNode->return_type) {
        const auto returnTypeResult =
            this->bakeType(functionTypeNode->return_type);
        if (!returnTypeResult.type) {
          return {nullptr, returnTypeResult.error};
        }
        type->diiaReturnType = returnTypeResult.type;
      } else {
        type->diiaReturnType = this->compiler->voidType;
      }
      return {type, ""};
    }
    if (astValue->kind == ast::KindArrayTypeNode) {
      const auto arrayTypeNode = astValue->data.ArrayTypeNode;
      const auto arraySizeNumberNode = arrayTypeNode->size->data.NumberNode;
      if (str_contains(arraySizeNumberNode->value, ".")) {
        return {nullptr, "Розмір масиву повинен бути цілим числом"};
      }
      const auto arraySizeString =
          tsilNumberToLLVMNumber(arraySizeNumberNode->value);
      const auto arraySize = std::stoi(arraySizeString);
      if (arraySize < 0) {
        return {nullptr, "Розмір масиву повинен бути додатнім числом"};
      }
      const auto elementTypeResult = this->bakeType(arrayTypeNode->type);
      if (!elementTypeResult.type) {
        return {nullptr, elementTypeResult.error};
      }
      return {elementTypeResult.type->getArrayType(this, arraySize), ""};
    }
    return {nullptr, "NOT IMPLEMENTED BAKED TYPE"};
  }
} // namespace tsil::tk