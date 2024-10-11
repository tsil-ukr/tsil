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
    const auto bodyResult = this->globalScope->compileBody(programNode->body);
    if (bodyResult.error) {
      return bodyResult.error;
    }
    return nullptr;
  }
} // namespace tsil::tk