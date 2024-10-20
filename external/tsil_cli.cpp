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

extern "C" int tsil_cli_compile_single(TsilCliConfig config,
                                       TsilCliWriter outputWriter,
                                       TsilCliCompileOptions options,
                                       char* inputPath,
                                       char* inputSource) {
  if (options.outFormat == TsilCliCompileOutFormatLLVM) {
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
    outputWriter.write((unsigned char*)llvm_out, outputWriter.options);
    return 0;
  } else {
    config.println("Unsupported output format");
    return 1;
  }
  return 0;
}