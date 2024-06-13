#include "../tk.h"

namespace tsil::tk {
  CompilerResult Scope::compileSynonym(ast::ASTValue* astValue) {
    const auto synonymNode = astValue->data.SynonymNode;
    if (this->hasLocalSubject(synonymNode->id)) {
      return {CompilerError::subjectAlreadyDefined(astValue)};
    }
    if (synonymNode->value->kind == ast::KindNumberNode) {
      const auto numberNode = synonymNode->value->data.NumberNode;
      const auto type = str_contains(numberNode->value, ".")
                            ? this->compiler->doubleType
                            : this->compiler->integerType;
      const auto xValue =
          new x::Value(type->xType, tsilNumberToLLVMNumber(numberNode->value));
      const auto constant = new Constant();
      constant->type = type;
      constant->xValue = xValue;
      this->setSubject(synonymNode->id,
                       Subject{SubjectKindConstant, {.constant = constant}});
    } else if (synonymNode->value->kind == ast::KindStringNode) {
      const auto stringNode = synonymNode->value->data.StringNode;
      const auto stringValue = tsilStringToCString(stringNode->value);
      const auto xStringConstant =
          this->compiler->xModule->putStringConstant("private", stringValue);
      Type* type = nullptr;
      if (stringNode->prefix == "сі") {
        type = this->compiler->int8Type->getPointerType(this);
      } else {
        return {CompilerError::fromASTValue(
            synonymNode->value, "Текст тимчасово не підтримується.")};
      }
      const auto constant = new Constant();
      constant->type = type;
      constant->xValue = xStringConstant;
      this->setSubject(synonymNode->id,
                       Subject{SubjectKindConstant, {.constant = constant}});
    } else if (synonymNode->value->kind == ast::KindTypeNode) {
      const auto typeNode = synonymNode->value->data.TypeNode;
      auto scope = this;
      std::string typeId;
      if (typeNode->id->kind == ast::KindIdentifierNode) {
        typeId = typeNode->id->data.IdentifierNode->name;
      } else if (typeNode->id->kind == ast::KindSectionAccessNode) {
        const auto sectionAccessResult =
            this->resolveSectionAccess(typeNode->id);
        if (sectionAccessResult.error) {
          return {sectionAccessResult.error};
        }
        scope = sectionAccessResult.scope;
        typeId = sectionAccessResult.lastPart->data.IdentifierNode->name;
      } else {
        return {CompilerError::fromASTValue(
            typeNode->id, "NOT IMPLEMENTED BAKED SECTION TYPE")};
      }
      std::vector<Type*> genericValues;
      for (const auto& genericAstValue : typeNode->generics) {
        const auto genericTypeResult = scope->bakeType(genericAstValue);
        if (!genericTypeResult.type) {
          return {CompilerError::fromASTValue(genericAstValue,
                                              genericTypeResult.error)};
        }
        genericValues.push_back(genericTypeResult.type);
      }
      if (scope->hasSubject(typeId)) {
        const auto subject = scope->getSubject(typeId);
        if (subject.kind == SubjectKindType) {
          const auto type = subject.data.type;
          if (!genericValues.empty()) {
            return {CompilerError::fromASTValue(
                synonymNode->value,
                "Неможливо застосувати шаблон до типу \"" + type->name + "\"")};
          }
          // ...
          this->setSubject(synonymNode->id,
                           Subject{SubjectKindType, {.type = type}});
        } else if (subject.kind == SubjectKindStructure) {
          const auto structure = subject.data.structure;
          if (genericValues.empty()) {
            this->setSubject(
                synonymNode->id,
                Subject{SubjectKindStructure, {.structure = structure}});
          } else {
            const auto bakedTypeResult =
                structure->bakeType(scope, genericValues);
            if (!bakedTypeResult.type) {
              return {CompilerError::fromASTValue(synonymNode->value,
                                                  bakedTypeResult.error)};
            }
            this->setSubject(
                synonymNode->id,
                Subject{SubjectKindType, {.type = bakedTypeResult.type}});
          }
        } else if (subject.kind == SubjectKindDiia) {
          const auto diia = subject.data.diia;
          const auto bakedDiiaResult = diia->bakeDiia(scope, genericValues);
          if (bakedDiiaResult.error) {
            return {bakedDiiaResult.error};
          }
          const auto constant = new Constant();
          constant->type = bakedDiiaResult.type;
          constant->xValue = bakedDiiaResult.xValue;
          this->setSubject(synonymNode->id, Subject{SubjectKindConstant,
                                                    {.constant = constant}});
        } else if (subject.kind == SubjectKindVariable) {
          const auto variable = subject.data.variable;
          if (!genericValues.empty()) {
            return {CompilerError::fromASTValue(
                synonymNode->value,
                "Неможливо застосувати шаблон до субʼєкта \"" + typeId + "\"")};
          }
          this->setSubject(synonymNode->id, Subject{SubjectKindVariable,
                                                    {.variable = variable}});
        } else if (subject.kind == SubjectKindConstant) {
          const auto constant = subject.data.constant;
          if (!genericValues.empty()) {
            return {CompilerError::fromASTValue(
                synonymNode->value,
                "Неможливо застосувати шаблон до субʼєкта \"" + typeId + "\"")};
          }
          this->setSubject(synonymNode->id, Subject{SubjectKindConstant,
                                                    {.constant = constant}});
        } else if (subject.kind == SubjectKindSection) {
          const auto section = subject.data.section;
          this->setSubject(synonymNode->id,
                           Subject{SubjectKindSection, {.section = section}});
        } else {
          return {CompilerError::fromASTValue(
              synonymNode->value,
              "Неможливо створити синонім до цього субʼєкта")};
        }
      } else {
        return {CompilerError::subjectNotDefined(synonymNode->value)};
      }
    } else if (synonymNode->value->kind == ast::KindArrayTypeNode ||
               synonymNode->value->kind == ast::KindFunctionTypeNode) {
      const auto bakedTypeResult = this->bakeType(synonymNode->value);
      if (!bakedTypeResult.type) {
        return {CompilerError::fromASTValue(synonymNode->value,
                                            bakedTypeResult.error)};
      }
      this->setSubject(
          synonymNode->id,
          Subject{SubjectKindType, {.type = bakedTypeResult.type}});
    } else {
      return {CompilerError::fromASTValue(
          synonymNode->value, "Неможливо створити синонім до цього субʼєкта")};
    }
    return {nullptr};
  }
} // namespace tsil::tk