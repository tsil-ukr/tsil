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
        if (this->hasLocalSubject(defineNode->id)) {
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
        if (this->hasSubject(structureNode->name)) {
          return {
              tsil::tk::CompilerError::subjectAlreadyDefined(childAstValue)};
        }
        this->rawTypes.insert_or_assign(structureNode->name, childAstValue);
      } else if (childAstValue->kind == tsil::ast::KindDiiaDeclarationNode) {
        const auto diiaDeclarationNode =
            childAstValue->data.DiiaDeclarationNode;
        if (!diiaDeclarationNode->head->generic_definitions.empty()) {
          return {tsil::tk::CompilerError::fromASTValue(
              childAstValue, "Шаблон-дія повинна мати тіло")};
        }
        if (this->hasSubject(diiaDeclarationNode->head->id)) {
          return {
              tsil::tk::CompilerError::subjectAlreadyDefined(childAstValue)};
        }
        if (diiaDeclarationNode->head->generic_definitions.empty()) {
          const auto bakedDiiaResult =
              this->bakeDiia(childAstValue, childAstValue, {});
          if (bakedDiiaResult.error) {
            return {bakedDiiaResult.error};
          }
          if (diiaDeclarationNode->as.empty()) {
            this->bakedDiias[{diiaDeclarationNode->head->id, {}}] = {
                bakedDiiaResult.type, bakedDiiaResult.xValue};
          } else {
            this->bakedDiias[{diiaDeclarationNode->as, {}}] = {
                bakedDiiaResult.type, bakedDiiaResult.xValue};
          }
        } else {
          if (diiaDeclarationNode->as.empty()) {
            this->rawDiias.insert_or_assign(diiaDeclarationNode->head->id,
                                            childAstValue);
          } else {
            this->rawDiias.insert_or_assign(diiaDeclarationNode->as,
                                            childAstValue);
          }
        }
      } else if (childAstValue->kind == tsil::ast::KindDiiaNode) {
        const auto diiaNode = childAstValue->data.DiiaNode;
        if (this->hasSubject(diiaNode->head->id)) {
          return {
              tsil::tk::CompilerError::subjectAlreadyDefined(childAstValue)};
        }
        if (diiaNode->head->generic_definitions.empty()) {
          const auto bakedDiiaResult =
              this->bakeDiia(childAstValue, childAstValue, {});
          if (bakedDiiaResult.error) {
            return {bakedDiiaResult.error};
          }
          this->bakedDiias[{diiaNode->head->id, {}}] = {bakedDiiaResult.type,
                                                        bakedDiiaResult.xValue};
        } else {
          this->rawDiias.insert_or_assign(diiaNode->head->id, childAstValue);
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
    const auto bodyResult = this->compileBody(sectionNode->body);
    if (bodyResult.error) {
      return {bodyResult.error};
    }
    return {nullptr};
  }
} // namespace tsil::tk