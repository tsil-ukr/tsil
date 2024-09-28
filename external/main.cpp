#include <fstream>
#include <iostream>

#include "tsil_llvm/tsil_llvm.h"
#include "tsil_parser/parser.h"

extern "C" size_t отримати_з_карти_субʼєктів(void* map,
                                             char* name,
                                             unsigned long* outType,
                                             void** outData) {
  auto m =
      static_cast<std::map<std::string, std::pair<unsigned long, void*>>*>(map);
  auto result = m->find(std::string(name));
  if (result != m->end()) {
    *outType = result->second.first;
    *outData = result->second.second;
    return true;
  }
  return false;
}

extern "C" void змінити_в_карті_субʼєктів(void* map,
                                          char* name,
                                          unsigned long type,
                                          void* data) {
  auto m =
      static_cast<std::map<std::string, std::pair<unsigned long, void*>>*>(map);
  m->insert_or_assign(std::string(name),
                      std::pair<unsigned long, void*>({type, data}));
}

extern "C" void* створити_карту_субʼєктів() {
  return new std::map<std::string, std::pair<unsigned long, void*>>();
}

extern "C" size_t отримати_з_карти_комірок(void* map,
                                           char* name,
                                           void** dataPtr) {
  auto m = static_cast<std::map<std::string, void*>*>(map);
  auto result = m->find(std::string(name));
  if (result != m->end()) {
    *dataPtr = result->second;
    return true;
  }
  return false;
}

extern "C" void змінити_в_карті_комірок(void* map, char* name, void* data) {
  auto m = static_cast<std::map<std::string, void*>*>(map);
  m->insert_or_assign(std::string(name), data);
}

extern "C" void* створити_карту_комірок() {
  return new std::map<std::string, void*>();
}

struct ПомилкаКомпіляціїЦілі {
  Місцезнаходження* місцезнаходження;
  char* повідомлення;
};

extern "C" ПомилкаКомпіляціїЦілі* скомпілювати_ціль_в_ll(XLM* m,
                                                         ТекстКоду* текст_коду);

int main() {
  std::string filename = "тест.ц";
  std::ifstream file(filename);
  std::string code((std::istreambuf_iterator<char>(file)),
                   std::istreambuf_iterator<char>());
  auto текстКоду = new ТекстКоду{.шлях = (char*)filename.c_str(),
                                 .значення = (char*)code.c_str()};
  const auto L = xlm_create(strdup(filename.c_str()));
  const auto помилка_компіляції_цілі = скомпілювати_ціль_в_ll(L, текстКоду);
  if (помилка_компіляції_цілі != nullptr) {
    std::cout << помилка_компіляції_цілі->місцезнаходження->текст_коду->шлях
              << ":" << помилка_компіляції_цілі->місцезнаходження->рядок << ":"
              << помилка_компіляції_цілі->місцезнаходження->стовпець << ": "
              << помилка_компіляції_цілі->повідомлення << std::endl;
    return 1;
  }
  std::cout << dumpLL(L) << std::endl;
  //  auto parseResult = розібрати_ціль(текстКоду);
  //  if (parseResult.успіх) {
  //    const auto compiler = new Compiler();
  //    const auto globalScope = createScope(nullptr);
  //    compiler->globalScope = globalScope;
  //    compiler->L = xlm_create(strdup(filename.c_str()));
  //
  //    const auto scope = createScope(globalScope);
  //
  //    const auto nativeInt32 = new Native();
  //    nativeInt32->name = "ц32";
  //    nativeInt32->xlType = xl_get_int32_type(compiler->L);
  //    setSubject(scope, "ц32",
  //               Subject{SubjectKindNative, {.native = nativeInt32}});
  //
  //    for (int i = 0; i < parseResult.тіло->довжина; ++i) {
  //      const auto& astValue = parseResult.тіло->елементи[i];
  //      const auto помилка_компіляції_цілі = compile(compiler, scope, astValue);
  //      if (помилка_компіляції_цілі.error) {
  //        std::cout << "Failed" << std::endl;
  //        std::cout << помилка_компіляції_цілі.error->message << std::endl;
  //        return 1;
  //      }
  //    }
  //    std::cout << dumpLL(compiler->L) << std::endl;
  //  } else {
  //    std::cout << "Failed" << std::endl;
  //    std::cout << parseResult.помилка->повідомлення << std::endl;
  //  }
  return 0;
}
