#include "tsil_cli.h"
#include <filesystem>
#include <optional>
#include "tsil_llvm/tsil_llvm.h"
#include "tsil_parser/parser.h"
#include "tsil_toc/tsil_toc.h"

struct ПомилкаКомпіляціїЦілі {
  Місцезнаходження* місцезнаходження;
  char* повідомлення;
  size_t розмір_повідомлення;
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
  auto pos = std::string(path).find_last_of('/');
  if (pos != std::string::npos) {
    auto folder = std::string(path).substr(0, pos);
    if (!std::filesystem::exists(folder)) {
      std::filesystem::create_directories(folder);
    }
  }
  std::ofstream ofs(path);
  if (!ofs) {
    config.println("Помилка запису у файл");
    return;
  }
  ofs.write(reinterpret_cast<char*>(data), size);
}

extern "C" int tsil_cli_parse(TsilCliConfig config,
                              size_t argsSize,
                              char** args,
                              TsilCliParsedCommand* parsedCommandPtr) {
  if (argsSize == 0) {
    parsedCommandPtr->type = TsilCliParsedCommandTypeHelp;
    parsedCommandPtr->c = TsilCliHelpCommand{};
    return 0;
  }

  auto toc = parseTOC(std::vector<std::string>(args, args + argsSize),
                      {
                          "допомога",
                          "версія",
                          "скомпілювати",
                          "сплавити",
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

  if (command == "версія") {
    parsedCommandPtr->type = TsilCliParsedCommandTypeVersion;
    parsedCommandPtr->c = TsilCliVersionCommand{};
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
        compileCommand.outputs[i].format = TsilCliCompileCommandOutputFormatOBJ;
        if (std::string(outputs[i].path).ends_with(".ll")) {
          compileCommand.outputs[i].format =
              TsilCliCompileCommandOutputFormatLLVM;
        } else if (std::string(outputs[i].path).ends_with(".bc")) {
          compileCommand.outputs[i].format =
              TsilCliCompileCommandOutputFormatBITCODE;
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
            } else if (value == "bc") {
              compileCommand.outputs[i].format =
                  TsilCliCompileCommandOutputFormatBITCODE;
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
          } else if (key == "triple") {
            if (value != std::nullopt) {
              compileCommand.outputs[i].targetTriple = value.value();
            } else {
              config.println("Не вказано значення для опції --triple");
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
    for (auto [key, value] : commandOptions) {
      config.println(strdup(("Невідома опція команди: --" + key).c_str()));
      return 1;
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

  if (command == "сплавити") {
    TsilCliFuseCommand fuseCommand;
    fuseCommand.outputsSize = outputs.size();
    if (fuseCommand.outputsSize > 0) {
      fuseCommand.outputs =
          new TsilCliFuseCommandOutput[fuseCommand.outputsSize];
      for (size_t i = 0; i < outputs.size(); i++) {
        fuseCommand.outputs[i].path = strdup(outputs[i].path.c_str());
        fuseCommand.outputs[i].format = TsilCliFuseCommandOutputFormatELF;
        for (auto [key, value] : outputs[i].options) {
          if (key == "формат") {
            if (value == "elf") {
              fuseCommand.outputs[i].format = TsilCliFuseCommandOutputFormatELF;
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
      fuseCommand.outputs = nullptr;
    }
    for (auto [key, value] : commandOptions) {
      if (key == "triple") {
        if (value != std::nullopt) {
          fuseCommand.options.targetTriple = value.value();
        } else {
          config.println("Не вказано значення для опції --triple");
          return 1;
        }
      } else if (key == "clang-options") {
        if (value != std::nullopt) {
          fuseCommand.options.clangOptions = value.value();
        } else {
          config.println("Не вказано значення для опції --clang-options");
          return 1;
        }
      } else {
        config.println(strdup(("Невідома опція команди: --" + key).c_str()));
        return 1;
      }
    }
    if (inputs.empty()) {
      config.println("Не вказано вхідні файли");
      return 1;
    }
    fuseCommand.inputsSize = inputs.size();
    if (fuseCommand.inputsSize > 0) {
      fuseCommand.inputs = new TsilCliFuseCommandInput[fuseCommand.inputsSize];
      for (size_t i = 0; i < inputs.size(); i++) {
        fuseCommand.inputs[i].path = strdup(inputs[i].path.c_str());
      }
    } else {
      fuseCommand.inputs = nullptr;
    }
    parsedCommandPtr->type = TsilCliParsedCommandTypeFuse;
    parsedCommandPtr->c = fuseCommand;
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
                                      output.format, output.targetTriple,
                                      command.options, inputPath, inputSource);
    if (result != 0) {
      return result;
    }
  }
  return 0;
}

extern "C" int tsil_cli_run_fuse_command(TsilCliConfig config,
                                         TsilCliFuseCommand command) {
  for (size_t i = 0; i < command.outputsSize; i++) {
    auto output = command.outputs[i];
    auto result =
        tsil_cli_do_fuse(config, output.path, output.format, command.options,
                         command.inputsSize, command.inputs);
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
  std::cerr << std::string(місцезнаходження->текст_коду->шлях,
                           місцезнаходження->текст_коду->розмір_шляху)
            << ":" << line + ":" + column + ": " << message << std::endl;
  const auto [new_start, code_line] = strtrim(
      strgetline(std::string(місцезнаходження->текст_коду->значення,
                             місцезнаходження->текст_коду->розмір_значення),
                 місцезнаходження->рядок));
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
    std::string outputTriple,
    TsilCliCompileCommandOptions options,
    char* inputPath,
    char* inputSource) {
  auto fixedFullPathToFile =
      strdup(std::filesystem::absolute(inputPath).c_str());
  const auto L = tsil_llvm_create_tl(
      fixedFullPathToFile,
      outputTriple.empty() ? nullptr : outputTriple.c_str());
  auto текстКоду = new ТекстКоду{.шлях = fixedFullPathToFile,
                                 .розмір_шляху = strlen(fixedFullPathToFile),
                                 .значення = inputSource,
                                 .розмір_значення = strlen(inputSource)};
  const auto помилка_компіляції_цілі = скомпілювати_ціль_в_ll(L, текстКоду);
  if (помилка_компіляції_цілі != nullptr) {
    if (помилка_компіляції_цілі->місцезнаходження != nullptr) {
      printCompilerError(
          помилка_компіляції_цілі->місцезнаходження,
          strdup(std::string(помилка_компіляції_цілі->повідомлення,
                             помилка_компіляції_цілі->розмір_повідомлення)
                     .c_str()));
      return 1;
    } else {
      config.println(
          strdup(std::string(помилка_компіляції_цілі->повідомлення,
                             помилка_компіляції_цілі->розмір_повідомлення)
                     .c_str()));
      return 1;
    }
  }
  if (outputFormat == TsilCliCompileCommandOutputFormatLLVM) {
    char* llvm_out = nullptr;
    size_t size = tsil_llvm_dump_ll(L, &llvm_out);
    outputWriter.write(config, size, reinterpret_cast<unsigned char*>(llvm_out),
                       outputWriter.options);
    return 0;
  } else if (outputFormat == TsilCliCompileCommandOutputFormatBITCODE) {
    char* llvm_out = nullptr;
    size_t size = tsil_llvm_dump_bc(L, &llvm_out);
    outputWriter.write(config, size, reinterpret_cast<unsigned char*>(llvm_out),
                       outputWriter.options);
    return 0;
  } else if (outputFormat == TsilCliCompileCommandOutputFormatOBJ) {
    config.println("Такий формат виходу наразі не підтримується");
    return 1;
  } else {
    config.println("Такий формат виходу наразі не підтримується");
    return 1;
  }
}

extern "C" int tsil_cli_do_fuse(TsilCliConfig config,
                                char* outputPath,
                                TsilCliFuseCommandOutputFormat outputFormat,
                                TsilCliFuseCommandOptions options,
                                unsigned long inputsSize,
                                TsilCliFuseCommandInput* inputs) {
  std::vector<std::string> clangInputPaths;
  for (int i = 0; i < inputsSize; ++i) {
    std::string inputPath = inputs[i].path;
    if (inputPath.ends_with(".ю8.ц")) {
      auto filename = std::filesystem::path(inputPath).filename().string();
      auto filenameWithoutExtension =
          filename.substr(0, filename.find_last_of("."));
      auto pathHash = std::to_string(std::hash<std::string>{}(inputPath));
      auto outputPath = std::filesystem::temp_directory_path().string() + "/" +
                        filenameWithoutExtension + "-" + pathHash + ".ll";
      auto compileCommand = std::string(config.path) + " " + outputPath +
                            " скомпілювати " + inputPath;
      config.println(strdup(compileCommand.c_str()));
      auto compileResult = system(compileCommand.c_str());
      if (compileResult != 0) {
        return compileResult;
      }
      inputs[i].path = strdup(outputPath.c_str());
      clangInputPaths.push_back(inputs[i].path);
    } else if (inputPath.ends_with(".c")) {
      clangInputPaths.push_back(inputs[i].path);
    } else if (inputPath.ends_with(".o")) {
      clangInputPaths.push_back(inputs[i].path);
    } else if (inputPath.ends_with(".a")) {
      clangInputPaths.push_back(inputs[i].path);
    } else if (inputPath.ends_with(".ll")) {
      clangInputPaths.push_back(inputs[i].path);
    } else {
      config.println("Невідомий формат вхідного файлу");
      return 1;
    }
  }
  std::string clangCommand = "clang";
  if (options.clangOptions.empty()) {
    clangCommand.append(" ");
  } else {
    if (!options.clangOptions.starts_with(" ")) {
      clangCommand.append(" ");
    }
    if (!options.targetTriple.empty()) {
      clangCommand.append("-target");
      clangCommand.append(options.targetTriple);
      if (!options.clangOptions.ends_with(" ")) {
        clangCommand.append(" ");
      }
    }
    clangCommand.append(options.clangOptions);
    if (!options.clangOptions.ends_with(" ")) {
      clangCommand.append(" ");
    }
  }
  clangCommand.append("-o ");
  clangCommand.append(outputPath);
  for (auto inputPath : clangInputPaths) {
    clangCommand.append(" ");
    clangCommand.append(inputPath);
  }
  config.println(strdup(clangCommand.c_str()));
  auto result = system(clangCommand.c_str());
  if (result != 0) {
    return result;
  }
  return 0;
}