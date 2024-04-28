#include "../tk.h"

namespace tsil::tk {
  CompilerResult Scope::compileBody(const std::vector<ast::ASTValue*>& body) {
    for (const auto& astValue : body) {
      if (astValue == nullptr) {
        continue;
      }
      if (astValue->kind == tsil::ast::KindNone) {
        continue;
      }
      if (astValue->kind == tsil::ast::KindTakeNode) {
        const auto takeNode = astValue->data.TakeNode;
        std::string parts = tsil::parser::tools::implode(takeNode->parts, "/");
        std::string path = parts + ".в";
        std::string folderPath = parts + "/" + path;
        if (this->compiler->fileExist(path)) {
          //
        } else if (this->compiler->fileExist(folderPath)) {
          path = folderPath;
        } else {
          return {tsil::tk::CompilerError::fromASTValue(
              astValue, "Файл \"" + path + "\" не знайдено")};
        }
        const auto takeResult = this->compiler->takeDefinitions(path);
        if (takeResult.compilerError) {
          return {takeResult.compilerError};
        }
        if (!takeResult.error.empty()) {
          return {tsil::tk::CompilerError::fromASTValue(astValue,
                                                        takeResult.error)};
        }
      } else if (astValue->kind == tsil::ast::KindSectionNode) {
        const auto sectionResult = this->compileSection(astValue);
        if (sectionResult.error) {
          return {sectionResult.error};
        }
      } else if (astValue->kind == tsil::ast::KindStructureNode) {
        const auto structureNode = astValue->data.StructureNode;
        if (this->hasSubject(structureNode->name)) {
          return {tsil::tk::CompilerError::subjectAlreadyDefined(astValue)};
        }
        this->rawTypes.insert_or_assign(structureNode->name, astValue);
      } else if (astValue->kind == tsil::ast::KindDiiaDeclarationNode) {
        const auto diiaDeclarationNode = astValue->data.DiiaDeclarationNode;
        if (!diiaDeclarationNode->head->generic_definitions.empty()) {
          return {tsil::tk::CompilerError::fromASTValue(
              astValue, "Шаблон-дія повинна мати тіло")};
        }
        if (this->hasSubject(diiaDeclarationNode->head->id)) {
          return {tsil::tk::CompilerError::subjectAlreadyDefined(astValue)};
        }
        if (diiaDeclarationNode->head->generic_definitions.empty()) {
          const auto bakedDiiaResult = this->bakeDiia(astValue, astValue, {});
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
                                            astValue);
          } else {
            this->rawDiias.insert_or_assign(diiaDeclarationNode->as, astValue);
          }
        }
      } else if (astValue->kind == tsil::ast::KindDiiaNode) {
        const auto diiaNode = astValue->data.DiiaNode;
        if (this->hasSubject(diiaNode->head->id)) {
          return {tsil::tk::CompilerError::subjectAlreadyDefined(astValue)};
        }
        if (diiaNode->head->generic_definitions.empty()) {
          const auto bakedDiiaResult = this->bakeDiia(astValue, astValue, {});
          if (bakedDiiaResult.error) {
            return {bakedDiiaResult.error};
          }
          this->bakedDiias[{diiaNode->head->id, {}}] = {bakedDiiaResult.type,
                                                        bakedDiiaResult.xValue};
        } else {
          this->rawDiias.insert_or_assign(diiaNode->head->id, astValue);
        }
      } else {
        return {tsil::tk::CompilerError::fromASTValue(
            astValue, "Неможливо скомпілювати це речення")};
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