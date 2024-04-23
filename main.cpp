#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "compiler/tk/tk.h"

std::pair<size_t, std::string> strtrim(const std::string& str) {
  size_t start = 0;
  size_t end = str.size();
  for (size_t i = 0; i < str.size(); i++) {
    if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r') {
      start = i;
      break;
    }
  }
  for (size_t i = str.size(); i > 0; i--) {
    if (str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\n' &&
        str[i - 1] != '\r') {
      end = i;
      break;
    }
  }
  const auto res = str.substr(start, end - start);
  return {start, res};
}

std::string strgetline(const std::string& code, size_t line) {
  size_t current_line = 1;
  size_t start = 0;
  size_t end = 0;
  for (size_t i = 0; i < code.size(); i++) {
    if (code[i] == '\n') {
      if (current_line == line) {
        end = i;
        break;
      }
      start = i + 1;
      current_line++;
    }
  }
  return code.substr(start, end - start);
}

void printCompilerError(const std::string& path,
                        const std::string& code,
                        const tsil::tk::CompilerError* error) {
  const auto line = std::to_string(error->line);
  const auto column = std::to_string(error->column);
  const auto message = error->message;
  std::cerr << path << ":" << line + ":" + column + ": " << message
            << std::endl;
  const auto [new_start, code_line] = strtrim(strgetline(code, error->line));
  std::string prefix = line + "| ";
  std::cerr << prefix << code_line << std::endl;
  for (size_t i = 0; i < (error->column - new_start) + prefix.size(); i++) {
    std::cerr << " ";
  }
  std::cerr << "^" << std::endl;
  if (error->secondError) {
    const auto secondLine = std::to_string(error->secondError->line);
    const auto secondColumn = std::to_string(error->secondError->column);
    std::cerr << path << ":" << secondLine + ":" + secondColumn + ": "
              << std::endl;
    const auto [new_start, code_line] =
        strtrim(strgetline(code, error->secondError->line));
    std::string prefix = secondLine + "| ";
    std::cerr << prefix << code_line << std::endl;
    for (size_t i = 0;
         i < (error->secondError->column - new_start) + prefix.size(); i++) {
      std::cerr << " ";
    }
    std::cerr << "^" << std::endl;
  }
}

void printParserError(const std::string& path,
                      const std::string& code,
                      const tsil::parser::TsilParserError* error) {
  const auto line = std::to_string(error->line);
  const auto column = std::to_string(error->column);
  const auto message = error->message;
  std::cerr << path << ":" << line + ":" + column + ": " << message
            << std::endl;
  const auto [new_start, code_line] = strtrim(strgetline(code, error->line));
  std::string prefix = line + "| ";
  std::cerr << prefix << code_line << std::endl;
  for (size_t i = 0; i < (error->column - new_start) + prefix.size(); i++) {
    std::cerr << " ";
  }
  std::cerr << "^" << std::endl;
}

int main(int argc, char** argv) {
  auto args = std::vector<std::string>(argv, argv + argc);
  const auto& command = args[1];

  if (command == "сплавити") {
    if (args.size() < 3) {
      std::cerr << "помилка: Не вказано вхідний файл" << std::endl;
      return 1;
    }
    if (args.size() < 4) {
      std::cerr << "помилка: Не вказано вихідний файл" << std::endl;
      return 1;
    }

    const auto& inputPath = args[2];
    const auto& outputPath = args[3];

    if (!outputPath.ends_with(".ll") && !outputPath.ends_with(".bc")) {
      std::cerr << "помилка: Вихідний файл повинен мати розширення .ll або .bc"
                << std::endl;
      return 1;
    }
    if (outputPath.ends_with(".bc")) {
      std::cerr << "помилка: Вихідний файл з розширенням .bc тимчасово не "
                   "підтримується"
                << std::endl;
      return 1;
    }

    std::ifstream inputFile(inputPath);
    if (!inputFile.is_open()) {
      std::cerr << "помилка: Не вдалося відкрити вхідний файл" << std::endl;
      return 1;
    }
    std::string code;
    std::string line;
    while (std::getline(inputFile, line)) {
      code += line + "\n";
    }
    inputFile.close();

    const auto parserResult = tsil::parser::parse(code);
    if (parserResult.program_node) {
      const auto compiler = new tsil::tk::Compiler();

      compiler->xModule = new tsil::x::Module();

      compiler->xModule->int1Type = compiler->xModule->defineNativeType("i1");
      compiler->xModule->int8Type = compiler->xModule->defineNativeType("i8");
      compiler->xModule->int32Type = compiler->xModule->defineNativeType("i32");
      compiler->xModule->int64Type = compiler->xModule->defineNativeType("i64");
      compiler->xModule->floatType =
          compiler->xModule->defineNativeType("float");
      compiler->xModule->doubleType =
          compiler->xModule->defineNativeType("double");
      compiler->xModule->pointerType =
          compiler->xModule->defineNativeType("ptr");
      compiler->xModule->voidType = compiler->xModule->defineNativeType("void");

      compiler->globalScope = new tsil::tk::Scope();
      compiler->globalScope->compiler = compiler;

      const auto voidType = new tsil::tk::Type();
      voidType->type = tsil::tk::TypeTypeNative;
      voidType->name = "ніщо";
      voidType->xType = compiler->xModule->voidType;
      compiler->globalScope->bakedTypes.insert_or_assign({"ніщо", {}},
                                                         voidType);
      compiler->voidType = voidType;

      const auto pointerType = new tsil::tk::Type();
      pointerType->type = tsil::tk::TypeTypeNative;
      pointerType->name = "невідома_комірка";
      pointerType->xType = compiler->xModule->pointerType;
      compiler->globalScope->bakedTypes.insert_or_assign(
          {"невідома_комірка", {}}, pointerType);
      compiler->pointerType = pointerType;

      const auto int1Type = new tsil::tk::Type();
      int1Type->type = tsil::tk::TypeTypeNative;
      int1Type->name = "логічне";
      int1Type->xType = compiler->xModule->int1Type;
      compiler->globalScope->bakedTypes.insert_or_assign({"логічне", {}},
                                                         int1Type);
      compiler->int1Type = int1Type;

      const auto int8Type = new tsil::tk::Type();
      int8Type->type = tsil::tk::TypeTypeNative;
      int8Type->name = "ц8";
      int8Type->xType = compiler->xModule->int8Type;
      compiler->globalScope->bakedTypes.insert_or_assign({"ц8", {}}, int8Type);
      compiler->int8Type = int8Type;

      const auto int32Type = new tsil::tk::Type();
      int32Type->type = tsil::tk::TypeTypeNative;
      int32Type->name = "ц32";
      int32Type->xType = compiler->xModule->int32Type;
      compiler->globalScope->bakedTypes.insert_or_assign({"ц32", {}},
                                                         int32Type);
      compiler->int32Type = int32Type;

      const auto int64Type = new tsil::tk::Type();
      int64Type->type = tsil::tk::TypeTypeNative;
      int64Type->name = "ціле";
      int64Type->xType = compiler->xModule->int64Type;
      compiler->globalScope->bakedTypes.insert_or_assign({"ціле", {}},
                                                         int64Type);
      compiler->int64Type = int64Type;

      const auto floatType = new tsil::tk::Type();
      floatType->type = tsil::tk::TypeTypeNative;
      floatType->name = "д32";
      floatType->xType = compiler->xModule->floatType;
      compiler->globalScope->bakedTypes.insert_or_assign({"д32", {}},
                                                         floatType);
      compiler->floatType = floatType;

      const auto doubleType = new tsil::tk::Type();
      doubleType->type = tsil::tk::TypeTypeNative;
      doubleType->name = "дійсне";
      doubleType->xType = compiler->xModule->doubleType;
      compiler->globalScope->bakedTypes.insert_or_assign({"дійсне", {}},
                                                         doubleType);
      compiler->doubleType = doubleType;

      const auto uint8Type = new tsil::tk::Type();
      uint8Type->type = tsil::tk::TypeTypeNative;
      uint8Type->name = "п8";
      uint8Type->xType = compiler->xModule->int8Type;
      compiler->globalScope->bakedTypes.insert_or_assign({"п8", {}}, uint8Type);
      compiler->uint8Type = uint8Type;

      const auto uint32Type = new tsil::tk::Type();
      uint32Type->type = tsil::tk::TypeTypeNative;
      uint32Type->name = "п32";
      uint32Type->xType = compiler->xModule->int32Type;
      compiler->globalScope->bakedTypes.insert_or_assign({"п32", {}},
                                                         uint32Type);
      compiler->uint32Type = uint32Type;

      const auto uint64Type = new tsil::tk::Type();
      uint64Type->type = tsil::tk::TypeTypeNative;
      uint64Type->name = "позитивне";
      uint64Type->xType = compiler->xModule->int64Type;
      compiler->globalScope->bakedTypes.insert_or_assign({"позитивне", {}},
                                                         uint64Type);
      compiler->uint64Type = uint64Type;

      compiler->globalScope->variables["так"] = {
          compiler->int8Type, compiler->xModule->putI8Constant(1)};
      compiler->globalScope->variables["ні"] = {
          compiler->int8Type, compiler->xModule->putI8Constant(0)};

      for (const auto& astValue : parserResult.program_node->body) {
        if (astValue == nullptr) {
          continue;
        }
        if (astValue->kind == tsil::ast::KindNone) {
          continue;
        }
        if (astValue->kind == tsil::ast::KindStructureNode) {
          const auto structureNode = astValue->data.StructureNode;
          if (compiler->globalScope->hasSubject(structureNode->name)) {
            printCompilerError(
                inputPath, code,
                tsil::tk::CompilerError::subjectAlreadyDefined(astValue));
            return 1;
          }
          compiler->globalScope->rawTypes.insert_or_assign(structureNode->name,
                                                           astValue);
        } else if (astValue->kind == tsil::ast::KindDiiaDeclarationNode) {
          const auto diiaDeclarationNode = astValue->data.DiiaDeclarationNode;
          if (compiler->globalScope->hasSubject(
                  diiaDeclarationNode->head->id)) {
            printCompilerError(
                inputPath, code,
                tsil::tk::CompilerError::subjectAlreadyDefined(astValue));
            return 1;
          }
          if (diiaDeclarationNode->head->generic_definitions.empty()) {
            const auto bakedDiiaResult =
                compiler->globalScope->bakeDiia(astValue, astValue, {});
            if (bakedDiiaResult.error) {
              printCompilerError(inputPath, code, bakedDiiaResult.error);
              return 1;
            }
            if (diiaDeclarationNode->as.empty()) {
              compiler->globalScope
                  ->bakedDiias[{diiaDeclarationNode->head->id, {}}] = {
                  bakedDiiaResult.type, bakedDiiaResult.xValue};
            } else {
              compiler->globalScope->bakedDiias[{diiaDeclarationNode->as, {}}] =
                  {bakedDiiaResult.type, bakedDiiaResult.xValue};
            }
          } else {
            if (diiaDeclarationNode->as.empty()) {
              compiler->globalScope->rawDiias.insert_or_assign(
                  diiaDeclarationNode->head->id, astValue);
            } else {
              compiler->globalScope->rawDiias.insert_or_assign(
                  diiaDeclarationNode->as, astValue);
            }
          }
        } else if (astValue->kind == tsil::ast::KindDiiaNode) {
          const auto diiaNode = astValue->data.DiiaNode;
          if (compiler->globalScope->hasSubject(diiaNode->head->id)) {
            printCompilerError(
                inputPath, code,
                tsil::tk::CompilerError::subjectAlreadyDefined(astValue));
            return 1;
          }
          if (diiaNode->head->generic_definitions.empty()) {
            const auto bakedDiiaResult =
                compiler->globalScope->bakeDiia(astValue, astValue, {});
            if (bakedDiiaResult.error) {
              printCompilerError(inputPath, code, bakedDiiaResult.error);
              return 1;
            }
            compiler->globalScope->bakedDiias[{diiaNode->head->id, {}}] = {
                bakedDiiaResult.type, bakedDiiaResult.xValue};
          } else {
            compiler->globalScope->rawDiias.insert_or_assign(diiaNode->head->id,
                                                             astValue);
          }
        } else {
          printCompilerError(
              inputPath, code,
              tsil::tk::CompilerError::fromASTValue(
                  astValue, "Неможливо скомпілювати це речення"));
          return 1;
        }
      }

      std::ofstream outFile(outputPath);
      if (!outFile.is_open()) {
        std::cerr << "помилка: Не вдалося відкрити вихідний файл" << std::endl;
        return 1;
      }
      outFile << compiler->xModule->dumpLL();
      outFile.close();
    } else {
      printParserError(inputPath, code, &parserResult.errors[0]);
      return 1;
    }
  } else if (command == "допомога") {
    std::cout << "Використання:" << std::endl;
    std::cout << "  ціль <команда> [<аргументи>]" << std::endl;
    std::cout << "Команди:" << std::endl;
    std::cout << "  сплавити <вхідний файл> <вихідний файл>" << std::endl;
    std::cout << "  допомога" << std::endl;
  } else {
    std::cerr << "помилка: Невідома команда" << std::endl;
    return 1;
  }

  return 0;
}