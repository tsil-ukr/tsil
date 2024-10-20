#include "tsil_cli.h"
#include <optional>
#include "tsil_llvm/tsil_llvm.h"
#include "tsil_parser/parser.h"

struct ПомилкаКомпіляціїЦілі {
  Місцезнаходження* місцезнаходження;
  char* повідомлення;
  size_t довжина_шляху;
  Місцезнаходження** шлях;
};

extern "C" ПомилкаКомпіляціїЦілі* скомпілювати_ціль_в_ll(TL* m,
                                                         ТекстКоду* текст_коду);

void write_to_stdout(TsilCliConfig config, unsigned char* data, void* options) {
  config.println(reinterpret_cast<char*>(data));
}

void write_to_file_by_path(TsilCliConfig config,
                           unsigned char* data,
                           void* options) {
  auto path = reinterpret_cast<char*>(options);
  std::ofstream ofs(path);
  ofs << reinterpret_cast<char*>(data);
}

// програма [--опції-програми]... [(вихід) [--опції-виходу]...]... (команда) [--опції-команди]... [(вхід) [--опції-входу]...]...
extern "C" int tsil_cli_parse(TsilCliConfig config,
                              size_t argsSize,
                              char** args,
                              TsilCliParsedCommand* parsedCommandPtr) {
  if (argsSize == 0) {
    config.println("Не вказано команду");
    return 1;
  }

  std::set<std::string> availableCommands = {
      "допомога",
      "скомпілювати",
  };

  std::map<std::string, std::optional<std::string>> programOptions;
  struct Output {
    std::string path;
    std::map<std::string, std::optional<std::string>> options;
  };
  std::vector<Output> outputs;
  std::optional<std::string> command = std::nullopt;
  std::map<std::string, std::optional<std::string>> commandOptions;
  struct Input {
    std::string path;
    std::map<std::string, std::optional<std::string>> options;
  };
  std::vector<Input> inputs;

  size_t i = 0;

  // programOptions
  while (i < argsSize) {
    std::string arg = args[i];
    if (arg.starts_with("--")) {
      std::string key;
      std::optional<std::string> value = std::nullopt;
      if (arg.find('=') == std::string::npos) {
        key = arg.substr(2);
      } else {
        key = arg.substr(2, arg.find('=') - 2);
        value = arg.substr(arg.find('=') + 1);
      }
      programOptions.insert_or_assign(key, value);
    } else {
      break;
    }
    i = i + 1;
  }

  // outputs and command
  while (i < argsSize) {
    std::string arg = args[i];
    if (arg.starts_with("--")) {
      std::string key;
      std::optional<std::string> value = std::nullopt;
      if (arg.find('=') == std::string::npos) {
        key = arg.substr(2);
      } else {
        key = arg.substr(2, arg.find('=') - 2);
        value = arg.substr(arg.find('=') + 1);
      }
      outputs.back().options.insert_or_assign(key, value);
    } else {
      if (availableCommands.contains(arg)) {
        command = arg;
        i = i + 1;
        break;
      } else {
        outputs.push_back({.path = arg, .options = {}});
      }
    }
    i = i + 1;
  }
  if (!command.has_value()) {
    config.println("Не вказано команду");
    return 1;
  }

  // command options
  while (i < argsSize) {
    std::string arg = args[i];
    if (arg.starts_with("--")) {
      std::string key;
      std::optional<std::string> value = std::nullopt;
      if (arg.find('=') == std::string::npos) {
        key = arg.substr(2);
      } else {
        key = arg.substr(2, arg.find('=') - 2);
        value = arg.substr(arg.find('=') + 1);
      }
      commandOptions.insert_or_assign(key, value);
    } else {
      break;
    }
    i = i + 1;
  }

  // inputs
  while (i < argsSize) {
    std::string arg = args[i];
    if (arg.starts_with("--")) {
      std::string key;
      std::optional<std::string> value = std::nullopt;
      if (arg.find('=') == std::string::npos) {
        key = arg.substr(2);
      } else {
        key = arg.substr(2, arg.find('=') - 2);
        value = arg.substr(arg.find('=') + 1);
      }
      inputs.back().options.insert_or_assign(key, value);
    } else {
      inputs.push_back({.path = arg, .options = {}});
    }
    i = i + 1;
  }

  if (command == "допомога") {
    parsedCommandPtr->type = TsilCliParsedCommandTypeHelp;
    parsedCommandPtr->c = TsilCliFuseHelp{};
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
    if (std::string(output.path) == "-") {
      return tsil_cli_do_compile(config,
                                 {
                                     write_to_stdout,
                                     nullptr,
                                 },
                                 output.format, command.options, inputPath,
                                 inputSource);
    } else {
      return tsil_cli_do_compile(config,
                                 {
                                     write_to_file_by_path,
                                     output.path,
                                 },
                                 output.format, command.options, inputPath,
                                 inputSource);
    }
  }
  return 0;
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
      std::vector<Місцезнаходження*> шлях;
      for (size_t i = 0; i < помилка_компіляції_цілі->довжина_шляху; ++i) {
        шлях.push_back(помилка_компіляції_цілі->шлях[i]);
      }
      std::reverse(шлях.begin(), шлях.end());

      config.println(strdup(
          (std::string(
               помилка_компіляції_цілі->місцезнаходження->текст_коду->шлях) +
           ":" +
           std::to_string(помилка_компіляції_цілі->місцезнаходження->рядок) +
           ":" +
           std::to_string(помилка_компіляції_цілі->місцезнаходження->стовпець) +
           ":" + помилка_компіляції_цілі->повідомлення)
              .c_str()));

      for (auto місцезнаходження : шлях) {
        config.println(strdup((std::string(місцезнаходження->текст_коду->шлях) +
                               ":" + std::to_string(місцезнаходження->рядок) +
                               ":" + std::to_string(місцезнаходження->стовпець))
                                  .c_str()));
      }
      return 1;
    } else {
      config.println(помилка_компіляції_цілі->повідомлення);
      return 1;
    }
  }
  if (outputFormat == TsilCliCompileCommandOutputFormatLLVM) {
    auto llvm_out = dumpLL(L);
    outputWriter.write(config, reinterpret_cast<unsigned char*>(llvm_out),
                       outputWriter.options);
    return 0;
  } else {
    config.println("Unsupported output format");
    return 1;
  }
  return 0;
}