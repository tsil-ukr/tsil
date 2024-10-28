#include "tsil_cli.h"
#include <optional>
#include "tsil_llvm/tsil_llvm.h"
#include "tsil_parser/parser.h"
#include "tsil_toc/tsil_toc.h"

struct ПомилкаКомпіляціїЦілі {
  Місцезнаходження* місцезнаходження;
  char* повідомлення;
  size_t довжина_шляху;
  Місцезнаходження** шлях;
};

extern "C" ПомилкаКомпіляціїЦілі* скомпілювати_ціль_в_ll(TL* m,
                                                         ТекстКоду* текст_коду);

void write_to_stdout(TsilCliConfig config,
                     size_t size,
                     unsigned char* data,
                     void* options) {
  config.println(reinterpret_cast<char*>(data));
}

void write_to_file_by_path(TsilCliConfig config,
                           size_t size,
                           unsigned char* data,
                           void* options) {
  auto path = reinterpret_cast<char*>(options);
  std::ofstream ofs(path);
  ofs.write(reinterpret_cast<char*>(data), size);
}

extern "C" int tsil_cli_parse(TsilCliConfig config,
                              char* firstArg,
                              size_t argsSize,
                              char** args,
                              TsilCliParsedCommand* parsedCommandPtr) {
  if (argsSize == 0) {
    config.println("Не вказано команду");
    return 1;
  }

  if (argsSize >= 1) {
    if (std::string(args[0]) == "lld") {
      TsilCliLLDCommand lldCommand{};
      lldCommand.argc = argsSize - 1;
      lldCommand.argv = args + 1;
      parsedCommandPtr->type = TsilCliParsedCommandTypeLLD;
      parsedCommandPtr->c = lldCommand;
      return 0;
    } else if ((std::string(args[0]) == "clang") ||
               (std::string(args[0]) == "clang++")) {
      TsilCliClangCommand clangCommand{};
      clangCommand.path = firstArg;
      clangCommand.prependArg = args[0];
      clangCommand.argsSize = argsSize - 1;
      clangCommand.args = args + 1;
      parsedCommandPtr->type = TsilCliParsedCommandTypeClang;
      parsedCommandPtr->c = clangCommand;
      return 0;
    }
  }

  auto toc = parseTOC(std::vector<std::string>(args, args + argsSize),
                      {
                          "допомога",
                          "скомпілювати",
                          "lld",
                      });
  if (std::holds_alternative<std::string>(toc)) {
    config.println(strdup(std::get<std::string>(toc).c_str()));
    return 1;
  }
  auto programOptions = std::get<TargetOrientedCommand>(toc).programOptions;
  auto outputs = std::get<TargetOrientedCommand>(toc).outputs;
  auto command = std::get<TargetOrientedCommand>(toc).command;
  auto commandOptions = std::get<TargetOrientedCommand>(toc).commandOptions;
  auto inputs = std::get<TargetOrientedCommand>(toc).inputs;

  if (command == "допомога") {
    parsedCommandPtr->type = TsilCliParsedCommandTypeHelp;
    parsedCommandPtr->c = TsilCliHelpCommand{};
    return 0;
  }

  if (command == "скомпілювати") {
    TsilCliCompileCommand compileCommand;
    compileCommand.outputsSize = outputs.size();
    if (compileCommand.outputsSize > 0) {
      compileCommand.outputs =
          new TsilCliCompileCommandOutput[compileCommand.outputsSize];
      for (size_t i = 0; i < outputs.size(); i++) {
        compileCommand.outputs[i].path = strdup(outputs[i].path.c_str());
        compileCommand.outputs[i].format =
            TsilCliCompileCommandOutputFormatLLVM;
        if (std::string(outputs[i].path).ends_with(".ll")) {
          compileCommand.outputs[i].format =
              TsilCliCompileCommandOutputFormatLLVM;
        } else if (std::string(outputs[i].path).ends_with(".S")) {
          compileCommand.outputs[i].format =
              TsilCliCompileCommandOutputFormatASM;
        } else if (std::string(outputs[i].path).ends_with(".o")) {
          compileCommand.outputs[i].format =
              TsilCliCompileCommandOutputFormatOBJ;
        } else if (std::string(outputs[i].path).ends_with(".a")) {
          compileCommand.outputs[i].format =
              TsilCliCompileCommandOutputFormatARCHIVE;
        }
        for (auto [key, value] : outputs[i].options) {
          if (key == "формат") {
            if (value == "ll") {
              compileCommand.outputs[i].format =
                  TsilCliCompileCommandOutputFormatLLVM;
            } else if (value == "S") {
              compileCommand.outputs[i].format =
                  TsilCliCompileCommandOutputFormatASM;
            } else if (value == "o") {
              compileCommand.outputs[i].format =
                  TsilCliCompileCommandOutputFormatOBJ;
            } else if (value == "a") {
              compileCommand.outputs[i].format =
                  TsilCliCompileCommandOutputFormatARCHIVE;
            } else {
              config.println("Невідомий формат виходу");
              return 1;
            }
          } else {
            config.println(strdup(("Невідома опція виходу: --" + key).c_str()));
            return 1;
          }
        }
      }
    } else {
      compileCommand.outputs = nullptr;
    }
    compileCommand.options.libraryPath = "";
    for (auto [key, value] : commandOptions) {
      if (key == "бібліотека") {
        if (value != std::nullopt) {
          compileCommand.options.libraryPath = value.value();
        } else {
          config.println("Не вказано значення для опції --бібліотека");
          return 1;
        }
      } else {
        config.println(strdup(("Невідома опція команди: --" + key).c_str()));
        return 1;
      }
    }
    if (inputs.empty()) {
      config.println("Не вказано вхідний файл");
      return 1;
    }
    if (inputs.size() > 1) {
      config.println("Більше одного вхідного файлу не підтримується");
      return 1;
    }
    compileCommand.input = {.path = strdup(inputs.front().path.c_str())};
    parsedCommandPtr->type = TsilCliParsedCommandTypeCompile;
    parsedCommandPtr->c = compileCommand;
    return 0;
  }

  config.println("Невідома команда");
  return 1;
}

extern "C" int tsil_cli_run_compile_command(TsilCliConfig config,
                                            TsilCliCompileCommand command) {
  char* inputPath = command.input.path;
  std::ifstream inputIfs(inputPath);
  char* inputSource =
      strdup(std::string((std::istreambuf_iterator<char>(inputIfs)),
                         std::istreambuf_iterator<char>())
                 .c_str());
  for (size_t i = 0; i < command.outputsSize; i++) {
    auto output = command.outputs[i];
    auto result = tsil_cli_do_compile(config,
                                      {
                                          write_to_file_by_path,
                                          output.path,
                                      },
                                      output.format, command.options, inputPath,
                                      inputSource);
    if (result != 0) {
      return result;
    }
  }
  return 0;
}

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

void printCompilerError(Місцезнаходження* місцезнаходження,
                        const char* повідомлення) {
  const auto line = std::to_string(місцезнаходження->рядок);
  const auto column = std::to_string(місцезнаходження->стовпець);
  const auto message = повідомлення;
  std::cerr << місцезнаходження->текст_коду->шлях << ":"
            << line + ":" + column + ": " << message << std::endl;
  const auto [new_start, code_line] = strtrim(strgetline(
      місцезнаходження->текст_коду->значення, місцезнаходження->рядок));
  std::string prefix = line + "| ";
  std::cerr << prefix << code_line << std::endl;
  for (size_t i = 0;
       i < (місцезнаходження->стовпець - new_start) + prefix.size(); i++) {
    std::cerr << " ";
  }
  std::cerr << "^" << std::endl;
}

extern "C" int tsil_cli_do_compile(
    TsilCliConfig config,
    TsilCliWriter outputWriter,
    TsilCliCompileCommandOutputFormat outputFormat,
    TsilCliCompileCommandOptions options,
    char* inputPath,
    char* inputSource) {
  const auto L = tsil_llvm_create_tl(inputPath);
  auto текстКоду = new ТекстКоду{.шлях = inputPath, .значення = inputSource};
  const auto помилка_компіляції_цілі = скомпілювати_ціль_в_ll(L, текстКоду);
  if (помилка_компіляції_цілі != nullptr) {
    if (помилка_компіляції_цілі->місцезнаходження != nullptr) {
      printCompilerError(помилка_компіляції_цілі->місцезнаходження,
                         помилка_компіляції_цілі->повідомлення);
      return 1;
    } else {
      config.println(помилка_компіляції_цілі->повідомлення);
      return 1;
    }
  }
  if (outputFormat == TsilCliCompileCommandOutputFormatLLVM) {
    auto llvm_out = dumpLL(L);
    outputWriter.write(config, strlen(llvm_out),
                       reinterpret_cast<unsigned char*>(llvm_out),
                       outputWriter.options);
    return 0;
  } else if (outputFormat == TsilCliCompileCommandOutputFormatOBJ) {
    std::vector<unsigned char> llvm_out;
    dumpOBJ(L, llvm_out);
    outputWriter.write(config, llvm_out.size(), llvm_out.data(),
                       outputWriter.options);
    return 0;
  } else {
    config.println("Unsupported output format");
    return 1;
  }
}

extern "C" int tsil_cli_do_lld(TsilCliConfig config,
                               TsilCliLLDCommand command) {
  return tsil_llvm_run_lld(command.argc, command.argv);
}

extern "C" int tsil_cli_do_clang(TsilCliConfig config,
                                 TsilCliClangCommand command) {
  return tsil_clang_main(command.path, command.prependArg, command.argsSize,
                         command.args);
}