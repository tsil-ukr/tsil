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
        const auto sectionAccessNode = typeNode->id->data.SectionAccessNode;
        const auto lastPart = sectionAccessNode->parts.back();
        std::vector<std::string> partsWithoutLast;
        for (size_t i = 0; i < sectionAccessNode->parts.size() - 1; i++) {
          partsWithoutLast.push_back(sectionAccessNode->parts[i]);
        }
        for (const auto& part : partsWithoutLast) {
          if (scope->hasSubject(part)) {
            const auto subject = scope->getSubject(part);
            if (subject.kind == SubjectKindSection) {
              scope = subject.data.section;
            } else {
              return {nullptr, "Секція \"" + part + "\" не знайдена"};
            }
          } else {
            return {nullptr, "Секція \"" + part + "\" не знайдена"};
          }
        }
        typeId = lastPart;
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
      if (typeId == "комірка") {
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
          if (genericValues.size()) {
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