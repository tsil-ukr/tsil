#include <cstring>
#include <fstream>
#include <iostream>
#include <map>

#include "tsil_cli.h"

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

extern "C" unsigned char* зʼєднати_ю8(unsigned char* value,
                                      unsigned char* value2) {
  std::string str = (char*)value;
  std::string str2 = (char*)value2;
  return (unsigned char*)strdup((str + str2).c_str());
}

void println(char* message) {
  std::cout << message << std::endl;
}

void printHelp() {
  std::cout << "Ціль " << TSIL_VERSION << std::endl;
  std::cout << std::endl;
  std::cout << "Використання:" << std::endl;
  std::cout << "  ціль <ціль> <команда> [аргументи...]" << std::endl;
  std::cout << std::endl;
  std::cout << "  ціль версія" << std::endl;
  std::cout << "  ціль допомога" << std::endl;
  std::cout << "  ціль <команда> допомога" << std::endl;
  std::cout << std::endl;
  std::cout << "Команди:" << std::endl;
  std::cout << "  <вихід> скомпілювати [опції...] <вхід>" << std::endl;
  std::cout
      << "    Опис: скомпілювати вхідний файл в зрозумілий для LLVM формат"
      << std::endl;
  std::cout << "    Вихід: .ll .bc" << std::endl;
  std::cout << "    Вхід: .ц" << std::endl;
  std::cout << "    Опції:" << std::endl;
  std::cout << "      --режим=<розробка|випуск>" << std::endl;
  std::cout << "      --бібліотека=\"власний шлях до бібліотеки\"" << std::endl;
  std::cout << std::endl;
  std::cout << "  <вихід> сплавити [опції...]  <вхід...>" << std::endl;
  std::cout << "    Опис: сплавити через CLang" << std::endl;
  std::cout << "    Вихід: без розширення або .o .so .wasm" << std::endl;
  std::cout << "    Вхід: .ц .c .cpp .ll .bc" << std::endl;
  std::cout << "    Опції:" << std::endl;
  std::cout << "      --режим=<розробка|випуск>" << std::endl;
  std::cout << "      --бібліотека=\"власний шлях до бібліотеки\"" << std::endl;
  std::cout << "      --кеш=<ні|ccache>" << std::endl;
  std::cout << "      --clang=\"path to clang\"" << std::endl;
  std::cout << "      --clang-override=\"custom clang options\"" << std::endl;
  std::cout << "      --clang-append=\"additional clang options\"" << std::endl;
}

int main(int argc, char** argv) {
  TsilCliConfig tsilCliConfig{.println = println};
  TsilCliParsedCommand parsedCommand;
  int result = tsil_cli_parse(tsilCliConfig, argv[0], argc - 1, argv + 1,
                              &parsedCommand);
  if (result != 0) {
    return result;
  }
  if (parsedCommand.type == TsilCliParsedCommandTypeHelp) {
    printHelp();
    return 0;
  }
  if (parsedCommand.type == TsilCliParsedCommandTypeCompile) {
    TsilCliCompileCommand command =
        std::get<TsilCliCompileCommand>(parsedCommand.c);
    return tsil_cli_run_compile_command(tsilCliConfig, command);
  }
  if (parsedCommand.type == TsilCliParsedCommandTypeLLD) {
    TsilCliLLDCommand command = std::get<TsilCliLLDCommand>(parsedCommand.c);
    return tsil_cli_do_lld(tsilCliConfig, command);
  }
  if (parsedCommand.type == TsilCliParsedCommandTypeClang) {
    TsilCliClangCommand command =
        std::get<TsilCliClangCommand>(parsedCommand.c);
    return tsil_cli_do_clang(tsilCliConfig, command);
  }
  tsilCliConfig.println("Здається ви виявили помилку...");
  return 1;
}

extern "C" char* позитивне_в_ю8(unsigned long value) {
  return (char*)strdup(std::to_string(value).c_str());
}