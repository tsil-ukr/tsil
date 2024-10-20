#include "tsil_cli.h"
#include "tsil_llvm/tsil_llvm.h"
#include "tsil_parser/parser.h"

struct ПомилкаКомпіляціїЦілі {
  Місцезнаходження* місцезнаходження;
  char* повідомлення;
  size_t довжина_шляху;
  Місцезнаходження** шлях;
};

extern "C" ПомилкаКомпіляціїЦілі* скомпілювати_ціль_в_ll(XTL* m,
                                                         ТекстКоду* текст_коду);

extern "C" int tsil_cli_parse(TsilCliConfig config,
                              size_t argsSize,
                              char** args,
                              TsilCliParsedCommand* parsedCommandPtr) {
  if (argsSize == 0) {
    config.println("Не вказано команду");
    return 1;
  }
  if (std::string(args[0]) == "допомога") {
    parsedCommandPtr->type = TsilCliParsedCommandTypeHelp;
    parsedCommandPtr->c = TsilCliFuseHelp{};
    return 0;
  }
  if (argsSize >= 2 && std::string(args[1]) == "скомпілювати") {
    if (argsSize < 3) {
      config.println("Не вказано вхідні файли");
      return 1;
    }
    TsilCliCompileCommand compileCommand;
    compileCommand.outputPath = args[0];
    compileCommand.options.outFormat = TsilCliCompileCommandOutputFormatLLVM;
    compileCommand.options.libraryPath = "";
    if (std::string(compileCommand.outputPath) == "-ll" ||
        std::string(compileCommand.outputPath).ends_with(".ll")) {
      compileCommand.options.outFormat = TsilCliCompileCommandOutputFormatLLVM;
    } else {
      config.println("Невідомий формат вихідного файлу");
      return 1;
    }
    size_t i = 2;
    while (i < argsSize) {
      std::string arg = args[i];
      if (arg.starts_with("--")) {
        // handle args
      } else {
        break;
      }
      i = i + 1;
    }
    if (i >= argsSize) {
      config.println("Не вказано вхідні файли");
      return 1;
    }
    if (i + 1 < argsSize) {
      config.println("Можна вказати лише один вхідний файл");
      return 1;
    }
    compileCommand.inputPath = args[i];
    parsedCommandPtr->type = TsilCliParsedCommandTypeCompile;
    parsedCommandPtr->c = compileCommand;
    return 0;
  }
  return 0;
}

extern "C" int tsil_cli_compile(TsilCliConfig config,
                                TsilCliWriter outputWriter,
                                TsilCliCompileCommandOptions options,
                                char* inputPath,
                                char* inputSource) {
  if (options.outFormat == TsilCliCompileCommandOutputFormatLLVM) {
    auto текстКоду = new ТекстКоду{.шлях = inputPath, .значення = inputSource};
    const auto L = xlm_create(inputPath);
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
             std::to_string(
                 помилка_компіляції_цілі->місцезнаходження->стовпець) +
             ":" + помилка_компіляції_цілі->повідомлення)
                .c_str()));

        for (auto місцезнаходження : шлях) {
          config.println(
              strdup((std::string(місцезнаходження->текст_коду->шлях) + ":" +
                      std::to_string(місцезнаходження->рядок) + ":" +
                      std::to_string(місцезнаходження->стовпець))
                         .c_str()));
        }
        return 1;
      } else {
        config.println(помилка_компіляції_цілі->повідомлення);
        return 1;
      }
    }
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