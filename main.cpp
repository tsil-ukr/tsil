#include <filesystem>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "compiler/tk.h"

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

struct CompileCommand {
  std::string inputPath;
  std::string outputPath;
};

enum FuseCommandOutputType {
  FuseCommandOutputTypeObject,
  FuseCommandOutputTypeStaticLibrary,
  FuseCommandOutputTypeSharedLibrary,
  FuseCommandOutputTypeStaticExecutable,
  FuseCommandOutputTypeExecutable,
  FuseCommandOutputTypeWasm,
};

struct FuseCommand {
  std::vector<std::string> inputPaths;
  std::string outputPath;
  FuseCommandOutputType outputType;
  bool releaseMode = false;
  bool useCCache = false;
  std::string clang = "clang++";
  std::string clangOverride = "";
  std::string clangAppend = "";
};

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

int compile(const CompileCommand& compileCommand) {
  if (!compileCommand.outputPath.ends_with(".ll") &&
      !compileCommand.outputPath.ends_with(".bc")) {
    std::cerr << "помилка: Вихідний файл повинен мати розширення .ll або .bc"
              << std::endl;
    return 1;
  }
  if (compileCommand.outputPath.ends_with(".bc")) {
    std::cerr << "помилка: Вихідний файл з розширенням .bc тимчасово не "
                 "підтримується"
              << std::endl;
    return 1;
  }

  std::ifstream inputFile(compileCommand.inputPath);
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
    compiler->xModule->floatType = compiler->xModule->defineNativeType("float");
    compiler->xModule->doubleType =
        compiler->xModule->defineNativeType("double");
    compiler->xModule->pointerType = compiler->xModule->defineNativeType("ptr");
    compiler->xModule->voidType = compiler->xModule->defineNativeType("void");

    compiler->globalScope = new tsil::tk::Scope();
    compiler->globalScope->compiler = compiler;

    const auto voidType = new tsil::tk::Type();
    voidType->type = tsil::tk::TypeTypeNative;
    voidType->name = "ніщо";
    voidType->xType = compiler->xModule->voidType;
    compiler->globalScope->bakedTypes.insert_or_assign({"ніщо", {}}, voidType);
    compiler->voidType = voidType;

    const auto pointerType = new tsil::tk::Type();
    pointerType->type = tsil::tk::TypeTypePointer;
    pointerType->name = "невідома_комірка";
    pointerType->xType = compiler->xModule->pointerType;
    compiler->globalScope->bakedTypes.insert_or_assign({"невідома_комірка", {}},
                                                       pointerType);
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
    compiler->globalScope->bakedTypes.insert_or_assign({"ц32", {}}, int32Type);
    compiler->int32Type = int32Type;

    const auto int64Type = new tsil::tk::Type();
    int64Type->type = tsil::tk::TypeTypeNative;
    int64Type->name = "ціле";
    int64Type->xType = compiler->xModule->int64Type;
    compiler->globalScope->bakedTypes.insert_or_assign({"ціле", {}}, int64Type);
    compiler->int64Type = int64Type;

    const auto floatType = new tsil::tk::Type();
    floatType->type = tsil::tk::TypeTypeNative;
    floatType->name = "д32";
    floatType->xType = compiler->xModule->floatType;
    compiler->globalScope->bakedTypes.insert_or_assign({"д32", {}}, floatType);
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
    compiler->globalScope->bakedTypes.insert_or_assign({"п32", {}}, uint32Type);
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
              compileCommand.inputPath, code,
              tsil::tk::CompilerError::subjectAlreadyDefined(astValue));
          return 1;
        }
        compiler->globalScope->rawTypes.insert_or_assign(structureNode->name,
                                                         astValue);
      } else if (astValue->kind == tsil::ast::KindDiiaDeclarationNode) {
        const auto diiaDeclarationNode = astValue->data.DiiaDeclarationNode;
        if (compiler->globalScope->hasSubject(diiaDeclarationNode->head->id)) {
          printCompilerError(
              compileCommand.inputPath, code,
              tsil::tk::CompilerError::subjectAlreadyDefined(astValue));
          return 1;
        }
        if (diiaDeclarationNode->head->generic_definitions.empty()) {
          const auto bakedDiiaResult =
              compiler->globalScope->bakeDiia(astValue, astValue, {});
          if (bakedDiiaResult.error) {
            printCompilerError(compileCommand.inputPath, code,
                               bakedDiiaResult.error);
            return 1;
          }
          if (diiaDeclarationNode->as.empty()) {
            compiler->globalScope
                ->bakedDiias[{diiaDeclarationNode->head->id, {}}] = {
                bakedDiiaResult.type, bakedDiiaResult.xValue};
          } else {
            compiler->globalScope->bakedDiias[{diiaDeclarationNode->as, {}}] = {
                bakedDiiaResult.type, bakedDiiaResult.xValue};
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
              compileCommand.inputPath, code,
              tsil::tk::CompilerError::subjectAlreadyDefined(astValue));
          return 1;
        }
        if (diiaNode->head->generic_definitions.empty()) {
          const auto bakedDiiaResult =
              compiler->globalScope->bakeDiia(astValue, astValue, {});
          if (bakedDiiaResult.error) {
            printCompilerError(compileCommand.inputPath, code,
                               bakedDiiaResult.error);
            return 1;
          }
          compiler->globalScope->bakedDiias[{diiaNode->head->id, {}}] = {
              bakedDiiaResult.type, bakedDiiaResult.xValue};
        } else {
          compiler->globalScope->rawDiias.insert_or_assign(diiaNode->head->id,
                                                           astValue);
        }
      } else {
        printCompilerError(compileCommand.inputPath, code,
                           tsil::tk::CompilerError::fromASTValue(
                               astValue, "Неможливо скомпілювати це речення"));
        return 1;
      }
    }

    std::ofstream outFile(compileCommand.outputPath);
    if (!outFile.is_open()) {
      std::cerr << "помилка: Не вдалося відкрити вихідний файл" << std::endl;
      return 1;
    }
    outFile << compiler->xModule->dumpLL();
    outFile.close();
    return 0;
  } else {
    printParserError(compileCommand.inputPath, code, &parserResult.errors[0]);
    return 1;
  }
}

void printHelp() {
  std::cout << "Використання:" << std::endl;
  std::cout << "  ціль <ціль> <команда> [аргументи...]" << std::endl;
  std::cout << std::endl;
  std::cout << "  ціль версія" << std::endl;
  std::cout << "  ціль допомога" << std::endl;
  std::cout << "  ціль <команда> допомога" << std::endl;
  std::cout << std::endl;
  std::cout << "Команди:" << std::endl;
  std::cout << "  <вихід> скомпілювати <вхід>" << std::endl;
  std::cout
      << "    Опис: скомпілювати вхідний файл в зрозумілий для LLVM формат"
      << std::endl;
  std::cout << "    Вихід: .ll .bc" << std::endl;
  std::cout << "    Вхід: .ц" << std::endl;
  std::cout << std::endl;
  std::cout << "  <вихід> сплавити [опції...]  <вхід...>" << std::endl;
  std::cout << "    Опис: сплавити обʼєкт або програму через CLang"
            << std::endl;
  std::cout << "    Вихід: .сплав .виріб .обц .бобц .сбобц .васм" << std::endl;
  std::cout << "    Вхід: .ц .c .cpp .ll .bc" << std::endl;
  std::cout << "    Опції:" << std::endl;
  std::cout << "      --режим=<розробка|випуск>" << std::endl;
  std::cout << "      --кеш=<ні|ccache>" << std::endl;
  std::cout << "      --clang=\"path to clang\"" << std::endl;
  std::cout << "      --clang-override=\"custom clang options\"" << std::endl;
  std::cout << "      --clang-append=\"additional clang options\"" << std::endl;
}

int main(int argc, char** argv) {
  auto args = std::vector<std::string>(argv, argv + argc);
  if (args.size() < 2) {
    printHelp();
    return 0;
  }
  if (args[1] == "допомога") {
    printHelp();
    return 0;
  }
  if (args[1] == "версія") {
    std::cout << TSIL_VERSION << std::endl;
    return 0;
  }
  const auto& target = args[1];
  const auto& command = args[2];

  if (command == "скомпілювати") {
    if (args.size() < 4) {
      std::cerr << "помилка: Не вказано вхід" << std::endl;
      return 1;
    }
    return compile({args[3], target});
  } else if (command == "сплавити") {
    if (args.size() < 4) {
      std::cerr << "помилка: Не вказано вхід" << std::endl;
      return 1;
    }

    FuseCommand fuseCommand;
    for (const auto& inputPath :
         std::vector<std::string>(args.begin() + 3, args.end())) {
      if (inputPath.starts_with("--")) {
        if (inputPath == "--режим=випуск") {
          fuseCommand.releaseMode = true;
        } else if (inputPath == "--кеш=ccache") {
          fuseCommand.useCCache = true;
        } else if (inputPath.starts_with("--clang=")) {
          fuseCommand.clang = inputPath.substr(std::string("--clang=").size());
        } else if (inputPath.starts_with("--clang-override=")) {
          fuseCommand.clangOverride =
              inputPath.substr(std::string("--clang-override=").size());
        } else if (inputPath.starts_with("--clang-append=")) {
          fuseCommand.clangAppend =
              inputPath.substr(std::string("--clang-append=").size());
        } else {
          std::cerr << "помилка: Невідома опція " << inputPath << std::endl;
          return 1;
        }
      } else {
        fuseCommand.inputPaths.push_back(inputPath);
      }
    }
    fuseCommand.outputPath = target;
    if (target.ends_with(".обц") || target.ends_with(".o")) {
      fuseCommand.outputType = FuseCommandOutputTypeObject;
    } else if (target.ends_with(".бобц") || target.ends_with(".a")) {
      fuseCommand.outputType = FuseCommandOutputTypeStaticLibrary;
    } else if (target.ends_with(".сбобц") || target.ends_with(".so")) {
      fuseCommand.outputType = FuseCommandOutputTypeSharedLibrary;
    } else if (target.ends_with(".виріб") || target.ends_with(".out")) {
      fuseCommand.outputType = FuseCommandOutputTypeStaticExecutable;
    } else if (target.ends_with(".васм") || target.ends_with(".wasm")) {
      fuseCommand.outputType = FuseCommandOutputTypeWasm;
    } else if (target.ends_with(".сплав") ||
               std::count(target.begin(), target.end(), '.') == 0) {
      fuseCommand.outputType = FuseCommandOutputTypeExecutable;
    } else {
      std::cerr
          << "помилка: Вихідний файл повинен мати розширення .обц, .бобц, "
             ".сбобц, .виріб, .васм або .сплав"
          << std::endl;
      return 1;
    }

    std::vector<std::string> cmd;
    if (fuseCommand.useCCache) {
      cmd.emplace_back("ccache");
    }
    cmd.emplace_back(fuseCommand.clang);
    if (fuseCommand.clangOverride.empty()) {
      if (fuseCommand.outputType == FuseCommandOutputTypeObject) {
        cmd.emplace_back("-c");
        if (fuseCommand.releaseMode) {
          cmd.emplace_back("-O3");
          cmd.emplace_back("-flto");
        }
      } else if (fuseCommand.outputType == FuseCommandOutputTypeStaticLibrary) {
        cmd.emplace_back("-c");
        cmd.emplace_back("-static");
        if (fuseCommand.releaseMode) {
          cmd.emplace_back("-O3");
          cmd.emplace_back("-flto");
        }
      } else if (fuseCommand.outputType == FuseCommandOutputTypeSharedLibrary) {
        cmd.emplace_back("-shared");
        if (fuseCommand.releaseMode) {
          cmd.emplace_back("-O3");
          cmd.emplace_back("-flto");
        }
      } else if (fuseCommand.outputType ==
                 FuseCommandOutputTypeStaticExecutable) {
        cmd.emplace_back("-static");
        if (fuseCommand.releaseMode) {
          cmd.emplace_back("-O3");
          cmd.emplace_back("-flto");
        }
      } else if (fuseCommand.outputType == FuseCommandOutputTypeExecutable) {
        if (fuseCommand.releaseMode) {
          cmd.emplace_back("-O3");
          cmd.emplace_back("-flto");
        }
      } else if (fuseCommand.outputType == FuseCommandOutputTypeWasm) {
        cmd.emplace_back("--target=wasm32");
        if (fuseCommand.releaseMode) {
          cmd.emplace_back("-O3");
          cmd.emplace_back("-flto");
        }
        cmd.emplace_back("-nostdlib");
        cmd.emplace_back("-Wl,--no-entry");
        cmd.emplace_back("-Wl,--export-all");
        if (fuseCommand.releaseMode) {
          cmd.emplace_back("-Wl,--lto-O3");
        }
        cmd.emplace_back("-Wl,-z,stack-size=8388608"); // 8MB
      }
    } else {
      cmd.push_back(fuseCommand.clangOverride);
    }
    if (!fuseCommand.clangAppend.empty()) {
      cmd.push_back(fuseCommand.clangAppend);
    }
    cmd.emplace_back("-o");
    cmd.push_back(fuseCommand.outputPath);
    for (const auto& inputPath : fuseCommand.inputPaths) {
      if (inputPath.ends_with(".ц")) {
        std::string fsSeparator;
        fsSeparator.push_back(std::filesystem::path::preferred_separator);
        const auto cacheDirPath = "плавлення" + fsSeparator + "скомпільоване";
        const auto inputPathOutput =
            cacheDirPath + fsSeparator +
            inputPath.substr(0, inputPath.size() - std::string(".ц").size()) +
            ".ll";
        if (!std::filesystem::is_directory(cacheDirPath) ||
            !std::filesystem::exists(cacheDirPath)) {
          if (!std::filesystem::create_directories(cacheDirPath)) {
            std::cerr << "помилка: Не вдалося створити директорію \"сплави\""
                      << std::endl;
            return 1;
          }
        }
        std::cout << "> ціль " << inputPathOutput << " скомпілювати "
                  << inputPath << std::endl;
        int compilationStatus = compile({inputPath, inputPathOutput});
        if (compilationStatus != 0) {
          return compilationStatus;
        }
        cmd.push_back(inputPathOutput);
      } else {
        cmd.push_back(inputPath);
      }
    }
    std::string cmdStr;
    tsil::x::implode(cmd, " ", cmdStr);
    std::cout << "> " << cmdStr << std::endl;
    return system(cmdStr.c_str());
  } else if (command == "допомога") {
    std::cout << "в розробці" << std::endl;
  } else {
    std::cerr << "помилка: Невідома команда" << std::endl;
    return 1;
  }

  return 0;
}