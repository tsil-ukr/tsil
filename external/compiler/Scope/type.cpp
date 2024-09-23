#include "../tk.h"

namespace tsil::tk {
  BakedTypeResult Scope::bakeType(ast::ASTValue* astValue) {
    if (astValue->kind == ast::KindTypeNode) {
      const auto typeNode = astValue->data.TypeNode;
      auto scope = this;
      std::string typeId;
      if (typeNode->id->kind == ast::KindIdentifierNode) {
        typeId = typeNode->id->data.IdentifierNode->name;
      } else if (typeNode->id->kind == ast::KindSectionAccessNode) {
        const auto sectionAccessResult =
            this->resolveSectionAccess(typeNode->id);
        if (sectionAccessResult.error) {
          return {nullptr, sectionAccessResult.error->message};
        }
        scope = sectionAccessResult.scope;
        typeId = sectionAccessResult.lastPart->data.IdentifierNode->name;
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
      if (typeId == "комірка" || typeId == "памʼять") {
        if (genericValues.empty()) {
          return {scope->compiler->pointerType};
        }
        const auto type = genericValues[0]->getPointerType(scope);
        return {type, ""};
      }
      if (scope->hasSubject(typeId)) {
        const auto subject = scope->getSubject(typeId);
        if (subject.kind == SubjectKindType) {
          const auto type = subject.data.type;
          if (!genericValues.empty()) {
            return {nullptr, "Неможливо застосувати шаблон до типу \"" +
                                 type->name + "\""};
          }
          return {type, ""};
        }
        if (subject.kind == SubjectKindStructure) {
          const auto structure = subject.data.structure;
          return structure->bakeType(scope, genericValues);
        }
      }
      return {nullptr, "Субʼєкт \"" + typeId + "\" не знайдено"};
    }
    if (astValue->kind == ast::KindFunctionTypeNode) {
      const auto functionTypeNode = astValue->data.FunctionTypeNode;
      const auto type = new Type();
      type->type = TypeTypeDiia;
      type->name = "";
      type->xType = tsil_xl_get_pointer_type(this->compiler->xModule);
      int argIndex = 0;
      for (const auto& paramAstValue : functionTypeNode->args) {
        const auto typeResult = this->bakeType(paramAstValue);
        if (!typeResult.type) {
          return {nullptr, typeResult.error};
        }
        type->diiaParameters.push_back(TypeDiiaParameter{
            .name = std::to_string(argIndex), .type = typeResult.type});
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
    if (astValue->kind == ast::KindVariationTypeNode) {
      const auto variationNode = astValue->data.VariationTypeNode;
      const auto type = new Type();
      type->type = TypeTypeVariationInstance;
      type->name = "";
      int paramIndex = 0;
      for (const auto& variationTypeTypeAstValue : variationNode->types) {
        const auto variationTypeTypeResult =
            this->bakeType(variationTypeTypeAstValue);
        if (!variationTypeTypeResult.type) {
          return {nullptr, variationTypeTypeResult.error};
        }
        if (variationTypeTypeResult.type->type == TypeTypeStructureInstance &&
            variationTypeTypeResult.type->structureInstanceFields.empty()) {
          return {nullptr, "Виявлено неповний тип"};
        }
        if (variationTypeTypeResult.type->type == TypeTypeVariationInstance) {
          return {nullptr, "Виявлено вкладену варіацію"};
        }
        type->variationTypes.push_back(variationTypeTypeResult.type);
        paramIndex++;
      }
      Type* largestVariationType = type->variationTypes[0];
      for (const auto& variationType : type->variationTypes) {
        if (variationType->getBytesSize(this) >
            largestVariationType->getBytesSize(this)) {
          largestVariationType = variationType;
        }
      }
      type->largestVariationType = largestVariationType;
      type->xType = largestVariationType->xType;
      return {type, ""};
    }
    return {nullptr, "NOT IMPLEMENTED BAKED TYPE"};
  }
} // namespace tsil::tk