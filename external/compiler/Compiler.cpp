#include "tk.h"

namespace tsil::tk {
  XLValue* Compiler::ensureCallocConnected() {
    if (this->callocXValue == nullptr) {
      const auto& xFunction = tsil_xl_declare_function(
          this->xModule, "calloc", this->pointerType->xType, 2,
          std::vector({this->uint64Type->xType, this->uint64Type->xType})
              .data());
      this->callocXValue = xFunction->llvm_function;
    }
    return this->callocXValue;
  }

  XLValue* Compiler::ensureMallocConnected() {
    if (this->mallocXValue == nullptr) {
      const auto& xFunction = tsil_xl_declare_function(
          this->xModule, "malloc", this->pointerType->xType, 1,
          std::vector({this->uint64Type->xType}).data());
      this->mallocXValue = xFunction->llvm_function;
    }
    return this->mallocXValue;
  }

  XLValue* Compiler::ensureReallocConnected() {
    if (this->reallocXValue == nullptr) {
      const auto& xFunction = tsil_xl_declare_function(
          this->xModule, "realloc", this->pointerType->xType, 2,
          std::vector({this->pointerType->xType, this->uint64Type->xType})
              .data());
      this->reallocXValue = xFunction->llvm_function;
    }
    return this->reallocXValue;
  }

  XLValue* Compiler::ensureFreeConnected() {
    if (this->freeXValue == nullptr) {
      const auto& xFunction = tsil_xl_declare_function(
          this->xModule, "free", this->voidType->xType, 1,
          std::vector({this->pointerType->xType}).data());
      this->freeXValue = xFunction->llvm_function;
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