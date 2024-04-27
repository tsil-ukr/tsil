#include "tk.h"

namespace tsil::tk {
  x::Value* Compiler::ensureCallocConnected() {
    if (this->callocXValue == nullptr) {
      const auto numberofblocksXValue = new x::Value(
          this->uint64Type->xType, this->xModule->computeNextVarName("arg"));
      const auto sizeOfBlockXValue = new x::Value(
          this->uint64Type->xType, this->xModule->computeNextVarName("arg"));
      const auto& [xFunction, xValue] = this->xModule->declareFunction(
          "", "calloc", this->pointerType->xType,
          {numberofblocksXValue, sizeOfBlockXValue});
      this->callocXValue = xValue;
    }
    return this->callocXValue;
  }

  x::Value* Compiler::ensureMallocConnected() {
    if (this->mallocXValue == nullptr) {
      const auto sizeXValue = new x::Value(
          this->uint64Type->xType, this->xModule->computeNextVarName("arg"));
      const auto& [xFunction, xValue] = this->xModule->declareFunction(
          "", "malloc", this->pointerType->xType, {sizeXValue});
      this->mallocXValue = xValue;
    }
    return this->mallocXValue;
  }

  x::Value* Compiler::ensureReallocConnected() {
    if (this->reallocXValue == nullptr) {
      const auto pointerXValue = new x::Value(
          this->pointerType->xType, this->xModule->computeNextVarName("arg"));
      const auto sizeXValue = new x::Value(
          this->uint64Type->xType, this->xModule->computeNextVarName("arg"));
      const auto& [xFunction, xValue] = this->xModule->declareFunction(
          "", "realloc", this->pointerType->xType, {pointerXValue, sizeXValue});
      this->reallocXValue = xValue;
    }
    return this->reallocXValue;
  }

  x::Value* Compiler::ensureFreeConnected() {
    if (this->freeXValue == nullptr) {
      const auto pointerXValue = new x::Value(
          this->pointerType->xType, this->xModule->computeNextVarName("arg"));
      const auto& [xFunction, xValue] = this->xModule->declareFunction(
          "", "free", this->voidType->xType, {pointerXValue});
      this->freeXValue = xValue;
    }
    return this->freeXValue;
  }

  std::pair<std::string, bool> Compiler::readFile(const std::string& path) {
    std::ifstream fileStream = std::ifstream(path);
    if (!fileStream.is_open()) {
      return {"", false};
    }
    std::string fileContent;
    std::string line;
    while (std::getline(fileStream, line)) {
      fileContent += line + "\n";
    }
    return {fileContent, true};
  }

  bool Compiler::fileExist(const std::string& path) {
    std::ifstream fileStream = std::ifstream(path);
    return fileStream.is_open();
  }

  TakeResult Compiler::takeDefinitions(const std::string& path) {
    if (this->tookDefinitions.contains(path)) {
      return {"", nullptr};
    }
    this->tookDefinitions.insert(path);
    const auto [fileContent, success] = this->readFile(path);
    if (!success) {
      return {"Не вдалось прочитати файл \"" + path + "\"", nullptr};
    }
    const auto parserResult = tsil::parser::parse(fileContent);
    if (!parserResult.errors.empty()) {
      auto parserError = parserResult.errors.front();
      return {"", CompilerError::fromParserError(&parserError)};
    }
    const auto compilerError =
        this->compileProgramNode(parserResult.program_node);
    if (compilerError != nullptr) {
      return {"", compilerError};
    }
    return {"", nullptr};
  }

  CompilerError* Compiler::compileProgramNode(
      tsil::ast::ProgramNode* programNode) {
    for (const auto& astValue : programNode->body) {
      if (astValue == nullptr) {
        continue;
      }
      if (astValue->kind == tsil::ast::KindNone) {
        continue;
      }
      if (astValue->kind == tsil::ast::KindTakeNode) {
        const auto takeNode = astValue->data.TakeNode;
        std::string path = takeNode->id + ".в";
        std::string folderPath = takeNode->id + "/" + path;
        if (this->fileExist(path)) {
          //
        } else if (this->fileExist(folderPath)) {
          path = folderPath;
        } else {
          return tsil::tk::CompilerError::fromASTValue(
              astValue, "Файл \"" + takeNode->id + "\" не знайдено");
        }
        const auto takeResult = this->takeDefinitions(path);
        if (takeResult.compilerError) {
          return takeResult.compilerError;
        }
        if (!takeResult.error.empty()) {
          return tsil::tk::CompilerError::fromASTValue(astValue,
                                                       takeResult.error);
        }
      } else if (astValue->kind == tsil::ast::KindStructureNode) {
        const auto structureNode = astValue->data.StructureNode;
        if (this->globalScope->hasSubject(structureNode->name)) {
          return tsil::tk::CompilerError::subjectAlreadyDefined(astValue);
        }
        this->globalScope->rawTypes.insert_or_assign(structureNode->name,
                                                     astValue);
      } else if (astValue->kind == tsil::ast::KindDiiaDeclarationNode) {
        const auto diiaDeclarationNode = astValue->data.DiiaDeclarationNode;
        if (!diiaDeclarationNode->head->generic_definitions.empty()) {
          return tsil::tk::CompilerError::fromASTValue(
              astValue, "Шаблон-дія повинна мати тіло");
        }
        if (this->globalScope->hasSubject(diiaDeclarationNode->head->id)) {
          return tsil::tk::CompilerError::subjectAlreadyDefined(astValue);
        }
        if (diiaDeclarationNode->head->generic_definitions.empty()) {
          const auto bakedDiiaResult =
              this->globalScope->bakeDiia(astValue, astValue, {});
          if (bakedDiiaResult.error) {
            return bakedDiiaResult.error;
          }
          if (diiaDeclarationNode->as.empty()) {
            this->globalScope->bakedDiias[{diiaDeclarationNode->head->id, {}}] =
                {bakedDiiaResult.type, bakedDiiaResult.xValue};
          } else {
            this->globalScope->bakedDiias[{diiaDeclarationNode->as, {}}] = {
                bakedDiiaResult.type, bakedDiiaResult.xValue};
          }
        } else {
          if (diiaDeclarationNode->as.empty()) {
            this->globalScope->rawDiias.insert_or_assign(
                diiaDeclarationNode->head->id, astValue);
          } else {
            this->globalScope->rawDiias.insert_or_assign(
                diiaDeclarationNode->as, astValue);
          }
        }
      } else if (astValue->kind == tsil::ast::KindDiiaNode) {
        const auto diiaNode = astValue->data.DiiaNode;
        if (this->globalScope->hasSubject(diiaNode->head->id)) {
          return tsil::tk::CompilerError::subjectAlreadyDefined(astValue);
        }
        if (diiaNode->head->generic_definitions.empty()) {
          const auto bakedDiiaResult =
              this->globalScope->bakeDiia(astValue, astValue, {});
          if (bakedDiiaResult.error) {
            return bakedDiiaResult.error;
          }
          this->globalScope->bakedDiias[{diiaNode->head->id, {}}] = {
              bakedDiiaResult.type, bakedDiiaResult.xValue};
        } else {
          this->globalScope->rawDiias.insert_or_assign(diiaNode->head->id,
                                                       astValue);
        }
      } else {
        return tsil::tk::CompilerError::fromASTValue(
            astValue, "Неможливо скомпілювати це речення");
      }
    }
    return nullptr;
  }
} // namespace tsil::tk