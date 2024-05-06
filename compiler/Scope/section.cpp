#include "../tk.h"

namespace tsil::tk {
  CompilerResult Scope::compileBody(const std::vector<ast::ASTValue*>& body) {
    for (const auto& childAstValue : body) {
      if (childAstValue == nullptr) {
        continue;
      }
      if (childAstValue->kind == tsil::ast::KindNone) {
        continue;
      }
      if (childAstValue->kind == tsil::ast::KindTakeNode) {
        const auto takeNode = childAstValue->data.TakeNode;
        std::string parts = tsil::parser::tools::implode(takeNode->parts, "/");
        std::string path = parts + ".в";
        std::string folderPath = parts + "/" + path;
        if (this->compiler->fileExist(path)) {
          //
        } else if (this->compiler->fileExist(folderPath)) {
          path = folderPath;
        } else {
          return {tsil::tk::CompilerError::fromASTValue(
              childAstValue, "Файл \"" + path + "\" не знайдено")};
        }
        const auto takeResult = this->compiler->takeDefinitions(path);
        if (takeResult.compilerError) {
          return {takeResult.compilerError};
        }
        if (!takeResult.error.empty()) {
          return {tsil::tk::CompilerError::fromASTValue(childAstValue,
                                                        takeResult.error)};
        }
      } else if (childAstValue->kind == tsil::ast::KindDefineNode) {
        const auto defineNode = childAstValue->data.DefineNode;
        if (this->hasVariable(defineNode->id) ||
            this->hasPredefinedType(defineNode->id) ||
            this->hasDiia(defineNode->id) ||
            this->hasStructure(defineNode->id) ||
            this->hasSection(defineNode->id)) {
          return {CompilerError::subjectAlreadyDefined(childAstValue)};
        }
        //        Type* type = nullptr;
        //        if (defineNode->type) {
        //          const auto typeResult = this->bakeType(defineNode->type);
        //          if (!typeResult.type) {
        //            return {CompilerError::fromASTValue(defineNode->type,
        //                                                typeResult.error)};
        //          }
        //          type = typeResult.type;
        //        }
        if (defineNode->value) {
          if (defineNode->value->kind == ast::KindNumberNode) {
            const auto numberNode = defineNode->value->data.NumberNode;
            const auto type = str_contains(numberNode->value, ".")
                                  ? this->compiler->doubleType
                                  : this->compiler->integerType;
            const auto xValue = new x::Value(
                type->xType, tsilNumberToLLVMNumber(numberNode->value));
            const auto globalXValue =
                this->compiler->xModule->putGlobal(type->xType, xValue);
            this->variables[defineNode->id] = {type, globalXValue};
          } else {
            return {CompilerError::fromASTValue(
                defineNode->value,
                "Глобальні цілі та змінні можуть мати лише числові значення.")};
          }
        } else {
          return {CompilerError::fromASTValue(defineNode->value,
                                              "NOT IMPLEMENTED")};
        }
      } else if (childAstValue->kind == tsil::ast::KindSectionNode) {
        const auto sectionResult = this->compileSection(childAstValue);
        if (sectionResult.error) {
          return {sectionResult.error};
        }
      } else if (childAstValue->kind == tsil::ast::KindStructureNode) {
        const auto structureNode = childAstValue->data.StructureNode;
        if (this->hasStructure(structureNode->name)) {
          const auto structure = this->getStructure(structureNode->name);
          if (structure->fields.empty()) {
            if (structure->genericDefinitions.size() !=
                structureNode->generic_definitions.size()) {
              return {tsil::tk::CompilerError::fromASTValue(
                  childAstValue,
                  "Кількість параметрів шаблон-структур не співпадає")};
            }
            for (size_t i = 0; i < structure->genericDefinitions.size(); i++) {
              const auto genericDefinition = structure->genericDefinitions[i];
              const auto genericNode = structureNode->generic_definitions[i];
              if (genericDefinition != genericNode) {
                return {tsil::tk::CompilerError::fromASTValue(
                    childAstValue, "Параметри шаблон-структур не співпадають")};
              }
            }
            if (structureNode->params.empty()) {
              continue;
            }
            for (const auto& paramAstValue : structureNode->params) {
              const auto paramNode = paramAstValue->data.ParamNode;
              StructureField field{};
              field.name = paramNode->id;
              field.type = paramNode->type;
              structure->fields.push_back(field);
            }
            const auto fillErrorText = structure->fillBakedTypesWithFields();
            if (!fillErrorText.empty()) {
              return {tsil::tk::CompilerError::fromASTValue(childAstValue,
                                                            fillErrorText)};
            }
          } else {
            return {
                tsil::tk::CompilerError::subjectAlreadyDefined(childAstValue)};
          }
        } else {
          if (this->hasVariable(structureNode->name) ||
              this->hasPredefinedType(structureNode->name) ||
              this->hasDiia(structureNode->name) ||
              this->hasSection(structureNode->name)) {
            return {
                tsil::tk::CompilerError::subjectAlreadyDefined(childAstValue)};
          }
          const auto structure = new Structure();
          structure->name =
              this->getSectionPrefixForName() + structureNode->name;
          for (const auto& genericDefinition :
               structureNode->generic_definitions) {
            structure->genericDefinitions.push_back(genericDefinition);
          }
          for (const auto& paramAstValue : structureNode->params) {
            const auto paramNode = paramAstValue->data.ParamNode;
            StructureField field{};
            field.name = paramNode->id;
            field.type = paramNode->type;
            structure->fields.push_back(field);
          }
          this->structures.insert_or_assign(structureNode->name, structure);
        }

      } else if (childAstValue->kind == tsil::ast::KindDiiaDeclarationNode) {
        const auto diiaDeclarationNode =
            childAstValue->data.DiiaDeclarationNode;
        const auto name = diiaDeclarationNode->as.empty()
                              ? diiaDeclarationNode->head->id
                              : diiaDeclarationNode->as;
        if (this->hasVariable(name) || this->hasPredefinedType(name) ||
            this->hasStructure(name) || this->hasPredefinedType(name) ||
            this->hasSection(name)) {
          return {
              tsil::tk::CompilerError::subjectAlreadyDefined(childAstValue)};
        }
        if (this->hasDiia(name)) {
          const auto diia = this->getDiia(name);
          // todo: validate head signature
        } else {
          const auto diia = new Diia();
          diia->isDeclaration = true;
          diia->linkage = diiaDeclarationNode->head->linkage;
          diia->name =
              this->getSectionPrefixForName() + diiaDeclarationNode->head->id;
          diia->genericDefinitions =
              diiaDeclarationNode->head->generic_definitions;
          for (const auto& param : diiaDeclarationNode->head->params) {
            diia->parameters.push_back(
                {param->data.ParamNode->id, param->data.ParamNode->type});
          }
          diia->isVariadic = diiaDeclarationNode->head->is_variadic;
          diia->returnType = diiaDeclarationNode->head->type;
          this->diias.insert_or_assign(name, diia);
        }
      } else if (childAstValue->kind == tsil::ast::KindDiiaNode) {
        const auto diiaNode = childAstValue->data.DiiaNode;
        if (this->hasVariable(diiaNode->head->id) ||
            this->hasPredefinedType(diiaNode->head->id) ||
            this->hasStructure(diiaNode->head->id)) {
          return {
              tsil::tk::CompilerError::subjectAlreadyDefined(childAstValue)};
        }
        if (this->hasDiia(diiaNode->head->id)) {
          const auto diia = this->getDiia(diiaNode->head->id);
          // todo: validate head signature
          if (diia->isDeclaration) {
            diia->body = diiaNode->body;
            diia->isDeclaration = false;
            diia->fillBakedDiiasWithBodies();
          } else {
            return {
                tsil::tk::CompilerError::subjectAlreadyDefined(childAstValue)};
          }
        } else {
          const auto diia = new Diia();
          diia->isDeclaration = false;
          diia->linkage = diiaNode->head->linkage;
          diia->name = this->getSectionPrefixForName() + diiaNode->head->id;
          diia->genericDefinitions = diiaNode->head->generic_definitions;
          for (const auto& param : diiaNode->head->params) {
            diia->parameters.push_back(
                {param->data.ParamNode->id, param->data.ParamNode->type});
          }
          diia->isVariadic = diiaNode->head->is_variadic;
          diia->returnType = diiaNode->head->type;
          diia->body = diiaNode->body;
          this->diias.insert_or_assign(diiaNode->head->id, diia);
          if (diia->genericDefinitions.empty()) {
            const auto bakedDiiaResult = diia->bakeDiia(this, {});
            if (bakedDiiaResult.error) {
              return {bakedDiiaResult.error};
            }
          }
        }
      } else {
        return {tsil::tk::CompilerError::fromASTValue(
            childAstValue, "Неможливо скомпілювати це речення")};
      }
    }
    return {nullptr};
  }

  CompilerResult Scope::compileSection(ast::ASTValue* astValue) {
    const auto sectionNode = astValue->data.SectionNode;
    const auto sectionId = sectionNode->id;
    Scope* sectionScope;
    if (this->hasPredefinedType(sectionId) ||
        this->hasStructure(sectionId) || this->hasDiia(sectionId) ||
        this->hasVariable(sectionId)) {
      return {CompilerError::subjectAlreadyDefined(astValue)};
    }
    if (this->hasSection(sectionId)) {
      sectionScope = this->getSection(sectionId);
    } else {
      sectionScope = new Scope(this->compiler, this);
      sectionScope->sectionName = sectionId;
      this->sections.insert_or_assign(sectionId, sectionScope);
    }
    const auto bodyResult = sectionScope->compileBody(sectionNode->body);
    if (bodyResult.error) {
      return {bodyResult.error};
    }
    return {nullptr};
  }
} // namespace tsil::tk