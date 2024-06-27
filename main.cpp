#include <dirent.h>
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
  return {start + 1, res};
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
    std::cerr << "помилка: Не вдалося відкрити файл \"" +
                     compileCommand.inputPath + "\""
              << std::endl;
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
    compiler->xModule->int16Type = compiler->xModule->defineNativeType("i16");
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
    compiler->globalScope->setSubject(
        "ніщо", tsil::tk::Subject{tsil::tk::SubjectKindType, voidType});
    compiler->voidType = voidType;

    const auto pointerType = new tsil::tk::Type();
    pointerType->type = tsil::tk::TypeTypePointer;
    pointerType->name = "невідома_комірка";
    pointerType->xType = compiler->xModule->pointerType;
    compiler->globalScope->setSubject(
        "невідома_комірка",
        tsil::tk::Subject{tsil::tk::SubjectKindType, pointerType});
    compiler->pointerType = pointerType;

    const auto uint1Type = new tsil::tk::Type();
    uint1Type->type = tsil::tk::TypeTypeNative;
    uint1Type->name = "ц1";
    uint1Type->xType = compiler->xModule->int1Type;
    compiler->globalScope->setSubject(
        "ц1", tsil::tk::Subject{tsil::tk::SubjectKindType, uint1Type});
    compiler->uint1Type = uint1Type;

    const auto int8Type = new tsil::tk::Type();
    int8Type->type = tsil::tk::TypeTypeNative;
    int8Type->name = "ц8";
    int8Type->xType = compiler->xModule->int8Type;
    compiler->globalScope->setSubject(
        "ц8", tsil::tk::Subject{tsil::tk::SubjectKindType, int8Type});
    compiler->int8Type = int8Type;

    const auto int16Type = new tsil::tk::Type();
    int16Type->type = tsil::tk::TypeTypeNative;
    int16Type->name = "ц16";
    int16Type->xType = compiler->xModule->int16Type;
    compiler->globalScope->setSubject(
        "ц16", tsil::tk::Subject{tsil::tk::SubjectKindType, int16Type});
    compiler->int16Type = int16Type;

    const auto int32Type = new tsil::tk::Type();
    int32Type->type = tsil::tk::TypeTypeNative;
    int32Type->name = "ц32";
    int32Type->xType = compiler->xModule->int32Type;
    compiler->globalScope->setSubject(
        "ц32", tsil::tk::Subject{tsil::tk::SubjectKindType, int32Type});
    compiler->int32Type = int32Type;

    const auto int64Type = new tsil::tk::Type();
    int64Type->type = tsil::tk::TypeTypeNative;
    int64Type->name = "ц64";
    int64Type->xType = compiler->xModule->int64Type;
    compiler->globalScope->setSubject(
        "ц64", tsil::tk::Subject{tsil::tk::SubjectKindType, int64Type});
    compiler->int64Type = int64Type;

    compiler->globalScope->setSubject(
        "ціле", tsil::tk::Subject{tsil::tk::SubjectKindType, int64Type});

    const auto floatType = new tsil::tk::Type();
    floatType->type = tsil::tk::TypeTypeNative;
    floatType->name = "д32";
    floatType->xType = compiler->xModule->floatType;
    compiler->globalScope->setSubject(
        "д32", tsil::tk::Subject{tsil::tk::SubjectKindType, floatType});
    compiler->f32Type = floatType;

    const auto d64Type = new tsil::tk::Type();
    d64Type->type = tsil::tk::TypeTypeNative;
    d64Type->name = "д64";
    d64Type->xType = compiler->xModule->doubleType;
    compiler->globalScope->setSubject(
        "д64", tsil::tk::Subject{tsil::tk::SubjectKindType, d64Type});
    compiler->f64Type = d64Type;

    compiler->globalScope->setSubject(
        "дійсне", tsil::tk::Subject{tsil::tk::SubjectKindType, d64Type});

    const auto uint8Type = new tsil::tk::Type();
    uint8Type->type = tsil::tk::TypeTypeNative;
    uint8Type->name = "п8";
    uint8Type->xType = compiler->xModule->int8Type;
    compiler->globalScope->setSubject(
        "п8", tsil::tk::Subject{tsil::tk::SubjectKindType, uint8Type});
    compiler->uint8Type = uint8Type;

    compiler->globalScope->setSubject(
        "логічне", tsil::tk::Subject{tsil::tk::SubjectKindType, uint8Type});

    const auto uint16Type = new tsil::tk::Type();
    uint16Type->type = tsil::tk::TypeTypeNative;
    uint16Type->name = "п16";
    uint16Type->xType = compiler->xModule->int16Type;
    compiler->globalScope->setSubject(
        "п16", tsil::tk::Subject{tsil::tk::SubjectKindType, uint16Type});
    compiler->uint16Type = uint16Type;

    const auto uint32Type = new tsil::tk::Type();
    uint32Type->type = tsil::tk::TypeTypeNative;
    uint32Type->name = "п32";
    uint32Type->xType = compiler->xModule->int32Type;
    compiler->globalScope->setSubject(
        "п32", tsil::tk::Subject{tsil::tk::SubjectKindType, uint32Type});
    compiler->uint32Type = uint32Type;

    const auto uint64Type = new tsil::tk::Type();
    uint64Type->type = tsil::tk::TypeTypeNative;
    uint64Type->name = "п64";
    uint64Type->xType = compiler->xModule->int64Type;
    compiler->globalScope->setSubject(
        "п64", tsil::tk::Subject{tsil::tk::SubjectKindType, uint64Type});
    compiler->uint64Type = uint64Type;

    compiler->globalScope->setSubject(
        "позитивне", tsil::tk::Subject{tsil::tk::SubjectKindType, uint64Type});

    compiler->nullConstant = new tsil::tk::Constant(
        pointerType,
        new tsil::x::Value(compiler->xModule->pointerType, "null"));
    compiler->globalScope->setSubject(
        "пусто", {.kind = tsil::tk::SubjectKindConstant,
                  .data = {.constant = compiler->nullConstant}});

    compiler->yesConstant = new tsil::tk::Constant(
        uint8Type, new tsil::x::Value(compiler->xModule->int8Type, "1"));
    compiler->globalScope->setSubject(
        "так", {.kind = tsil::tk::SubjectKindConstant,
                .data = {.constant = compiler->yesConstant}});
    compiler->noConstant = new tsil::tk::Constant(
        uint8Type, new tsil::x::Value(compiler->xModule->int8Type, "0"));
    compiler->globalScope->setSubject(
        "ні", {.kind = tsil::tk::SubjectKindConstant,
               .data = {.constant = compiler->noConstant}});

    const auto compilerError =
        compiler->compileProgramNode(parserResult.program_node);
    if (compilerError != nullptr) {
      printCompilerError(compileCommand.inputPath, code, compilerError);
      return 1;
    }

    std::ofstream outFile(compileCommand.outputPath);
    if (!outFile.is_open()) {
      std::cerr << "помилка: Не вдалося відкрити файл \"" +
                       compileCommand.outputPath + "\""
                << std::endl;
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
  std::cout << "Ціль " << TSIL_VERSION << std::endl;
  std::cout << std::endl;
  std::cout << "Використання:" << std::endl;
  std::cout << "  ціль <ціль> <команда> [аргументи...]" << std::endl;
  std::cout << std::endl;
  std::cout << "  ціль версія" << std::endl;
  std::cout << "  ціль допомога" << std::endl;
  std::cout << "  ціль перебудувати-бібліотеку" << std::endl;
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
  std::cout << "    Опис: сплавити через CLang" << std::endl;
  std::cout << "    Вихід: без розширення або .o .so .wasm" << std::endl;
  std::cout << "    Вхід: .ц .c .cpp .ll .bc" << std::endl;
  std::cout << "    Опції:" << std::endl;
  std::cout << "      --режим=<розробка|випуск>" << std::endl;
  std::cout << "      --кеш=<ні|ccache>" << std::endl;
  std::cout << "      --clang=\"path to clang\"" << std::endl;
  std::cout << "      --clang-override=\"custom clang options\"" << std::endl;
  std::cout << "      --clang-append=\"additional clang options\"" << std::endl;
}

std::pair<FuseCommand, std::string> parseFuseCommand(
    const std::string& outputPath,
    const std::vector<std::string>& arguments) {
  FuseCommand fuseCommand;
  for (const auto& argument : arguments) {
    if (argument.starts_with("--")) {
      if (argument == "--режим=випуск") {
        fuseCommand.releaseMode = true;
      } else if (argument == "--кеш=ccache") {
        fuseCommand.useCCache = true;
      } else if (argument.starts_with("--clang=")) {
        fuseCommand.clang = argument.substr(std::string("--clang=").size());
      } else if (argument.starts_with("--clang-override=")) {
        fuseCommand.clangOverride =
            argument.substr(std::string("--clang-override=").size());
      } else if (argument.starts_with("--clang-append=")) {
        fuseCommand.clangAppend =
            argument.substr(std::string("--clang-append=").size());
      } else {
        //        return {{}, "помилка: Невідома опція \"" + argument + "\""};
      }
    } else {
      fuseCommand.inputPaths.push_back(argument);
    }
  }
  fuseCommand.outputPath = outputPath;
  std::string targetFileName =
      std::filesystem::path(fuseCommand.outputPath).filename();
  if (targetFileName.ends_with(".обʼєкт") || targetFileName.ends_with(".o")) {
    fuseCommand.outputType = FuseCommandOutputTypeObject;
  } else if (targetFileName.ends_with(".динаміт") ||
             targetFileName.ends_with(".so")) {
    fuseCommand.outputType = FuseCommandOutputTypeSharedLibrary;
  } else if (targetFileName.ends_with(".васм") ||
             targetFileName.ends_with(".wasm")) {
    fuseCommand.outputType = FuseCommandOutputTypeWasm;
  } else if (targetFileName.ends_with(".сплав") ||
             std::count(targetFileName.begin(), targetFileName.end(), '.') ==
                 0) {
    fuseCommand.outputType = FuseCommandOutputTypeExecutable;
  } else {
    return {{},
            "помилка: Вихідний файл повинен мати розширення .o, .so або .wasm"};
  }
  return {fuseCommand, ""};
}

std::vector<std::string> buildFuseCmd(const FuseCommand& fuseCommand) {
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
      }
    } else if (fuseCommand.outputType == FuseCommandOutputTypeSharedLibrary) {
      cmd.emplace_back("-shared");
      if (fuseCommand.releaseMode) {
        cmd.emplace_back("-O3");
      }
    } else if (fuseCommand.outputType == FuseCommandOutputTypeExecutable) {
      if (fuseCommand.releaseMode) {
        cmd.emplace_back("-O3");
      }
    } else if (fuseCommand.outputType == FuseCommandOutputTypeWasm) {
      cmd.emplace_back("--target=wasm32");
      if (fuseCommand.releaseMode) {
        cmd.emplace_back("-O3");
      }
      cmd.emplace_back("-nostdlib");
      cmd.emplace_back("-Wl,--no-entry");
      cmd.emplace_back("-Wl,--export-all");
      if (fuseCommand.releaseMode) {
        cmd.emplace_back("-Wl,--lto-O3");
      }
    }
  } else {
    cmd.push_back(fuseCommand.clangOverride);
  }
  if (!fuseCommand.clangAppend.empty()) {
    cmd.push_back(fuseCommand.clangAppend);
  }
  cmd.emplace_back("-o");
  cmd.push_back(fuseCommand.outputPath);
  return cmd;
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
  if (args[1] == "перебудувати-бібліотеку") {
    const auto build_path =
        std::filesystem::path(std::filesystem::temp_directory_path().string())
            .append("будова_бібліотеки_цілі");
    const auto build_lib_path =
        std::filesystem::path(build_path.string()).append("біб.a");
    const auto build_fuse_path =
        std::filesystem::path(build_path.string()).append(".плавлення");
    std::vector<std::string> objectFiles;
    for (const auto& p : std::filesystem::recursive_directory_iterator(
             "/usr/local/lib/ціль/бібліотека/біб")) {
      if (!std::filesystem::is_directory(p)) {
        const auto ps = p.path().string();
        const auto rps =
            std::filesystem::path(ps)
                .lexically_relative("/usr/local/lib/ціль/бібліотека/біб")
                .string();
        //        std::cout << ps << " " << rps << std::endl;
        if (ps.ends_with(".ц")) {
          const auto outputLLPath =
              std::filesystem::path(build_fuse_path.string())
                  .append(rps + ".ll");
          const auto inputPathOutputDirname =
              std::filesystem::path(outputLLPath).parent_path();
          if (!std::filesystem::is_directory(inputPathOutputDirname) ||
              !std::filesystem::exists(inputPathOutputDirname)) {
            if (!std::filesystem::create_directories(inputPathOutputDirname)) {
              std::cerr << "помилка: Не вдалося створити директорію \"" +
                               std::string(inputPathOutputDirname.c_str()) +
                               "\""
                        << std::endl;
              return 1;
            }
          }
          std::cout << "> ціль " << outputLLPath.string() << " скомпілювати "
                    << ps << std::endl;
          auto compilationResult = compile({ps, outputLLPath.string()});
          if (compilationResult != 0) {
            return compilationResult;
          }
          const auto outputOPath =
              std::filesystem::path(build_fuse_path.string())
                  .append(rps + ".o");
          const auto fuseCommandResult = parseFuseCommand(
              outputOPath.string(),
              std::vector<std::string>(args.begin() + 2, args.end()));
          if (!fuseCommandResult.second.empty()) {
            std::cerr << fuseCommandResult.second << std::endl;
            return 1;
          }
          auto fuseCommand = fuseCommandResult.first;
          auto cmd = buildFuseCmd(fuseCommand);
          cmd.push_back(outputLLPath.string());
          std::string cmdStr;
          tsil::x::implode(cmd, " ", cmdStr);
          std::cout << "> " << cmdStr << std::endl;
          if (system(cmdStr.c_str()) != 0) {
            return 1;
          }
          objectFiles.push_back(outputOPath.string());
        } else if (ps.ends_with(".c")) {
          //
        } else if (ps.ends_with(".cpp")) {
          const auto outputOPath =
              std::filesystem::path(build_fuse_path.string())
                  .append(rps + ".o");
          const auto fuseCommandResult = parseFuseCommand(
              outputOPath.string(),
              std::vector<std::string>(args.begin() + 2, args.end()));
          if (!fuseCommandResult.second.empty()) {
            std::cerr << fuseCommandResult.second << std::endl;
            return 1;
          }
          auto fuseCommand = fuseCommandResult.first;
          auto cmd = buildFuseCmd(fuseCommand);
          cmd.push_back(ps);
          std::string cmdStr;
          tsil::x::implode(cmd, " ", cmdStr);
          std::cout << "> " << cmdStr << std::endl;
          if (system(cmdStr.c_str()) != 0) {
            return 1;
          }
          objectFiles.push_back(outputOPath.string());
        }
      }
    }
    std::string ar = "llvm-ar";
    for (const auto& argument : args) {
      if (argument.starts_with("--ar=")) {
        ar = argument.substr(std::string("--ar=").size());
      }
    }
    std::string arCmd = ar + " rcs " + build_lib_path.string();
    for (const auto& objectFile : objectFiles) {
      arCmd += " " + objectFile;
    }
    std::cout << "> " << arCmd << std::endl;
    return system(arCmd.c_str());
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
    const auto fuseCommandResult = parseFuseCommand(
        target, std::vector<std::string>(args.begin() + 3, args.end()));
    if (!fuseCommandResult.second.empty()) {
      std::cerr << fuseCommandResult.second << std::endl;
      return 1;
    }
    auto fuseCommand = fuseCommandResult.first;
    auto cmd = buildFuseCmd(fuseCommand);
    for (const auto& inputPath : fuseCommand.inputPaths) {
      if (inputPath.ends_with(".ц")) {
        std::string fsSeparator;
        fsSeparator.push_back(std::filesystem::path::preferred_separator);
        const auto compiledDirPath =
            ".плавлення" + fsSeparator + "скомпільоване";
        const auto inputPathOutput =
            compiledDirPath + fsSeparator +
            inputPath.substr(0, inputPath.size() - std::string(".ц").size()) +
            ".ll";
        const auto inputPathOutputDirname =
            std::filesystem::path(inputPathOutput).parent_path();
        if (!std::filesystem::is_directory(inputPathOutputDirname) ||
            !std::filesystem::exists(inputPathOutputDirname)) {
          if (!std::filesystem::create_directories(inputPathOutputDirname)) {
            std::cerr << "помилка: Не вдалося створити директорію \"" +
                             std::string(inputPathOutputDirname.c_str()) + "\""
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
    cmd.push_back("/usr/local/lib/ціль/бібліотека/біб.a");
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