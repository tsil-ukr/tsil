#include <fstream>
#include <iostream>

#include "parser/parser.h"

extern "C" char* скомпілювати_ціль_в_ll(ТекстКоду* текст_коду);

int main() {
  std::string filename = "тест.ц";
  std::ifstream file(filename);
  std::string code((std::istreambuf_iterator<char>(file)),
                   std::istreambuf_iterator<char>());
  auto текстКоду = new ТекстКоду((char*)filename.c_str(), (char*)code.c_str());
  const auto result = скомпілювати_ціль_в_ll(текстКоду);
  std::cout << result << std::endl;
  //  auto parseResult = розібрати_ціль(текстКоду);
  //  if (parseResult.успіх) {
  //    const auto compiler = new Compiler();
  //    const auto globalScope = createScope(nullptr);
  //    compiler->globalScope = globalScope;
  //    compiler->m = xlm_create(strdup(filename.c_str()));
  //
  //    const auto scope = createScope(globalScope);
  //
  //    const auto nativeInt32 = new Native();
  //    nativeInt32->name = "ц32";
  //    nativeInt32->xlType = xl_get_int32_type(compiler->m);
  //    setSubject(scope, "ц32",
  //               Subject{SubjectKindNative, {.native = nativeInt32}});
  //
  //    for (int i = 0; i < parseResult.тіло->довжина; ++i) {
  //      const auto& astValue = parseResult.тіло->елементи[i];
  //      const auto result = compile(compiler, scope, astValue);
  //      if (result.error) {
  //        std::cout << "Failed" << std::endl;
  //        std::cout << result.error->message << std::endl;
  //        return 1;
  //      }
  //    }
  //    std::cout << dumpLL(compiler->m) << std::endl;
  //  } else {
  //    std::cout << "Failed" << std::endl;
  //    std::cout << parseResult.помилка->повідомлення << std::endl;
  //  }
  return 0;
}
