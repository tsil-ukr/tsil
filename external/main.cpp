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

int main(int argc, char** argv) {
  TsilCliConfig tsilCliConfig{.println = println};
  TsilCliParsedCommand parsedCommand;
  int result =
      tsil_cli_parse(tsilCliConfig, argc - 1, argv + 1, &parsedCommand);
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
    char* inputPath = command.inputPath;
    std::ifstream inputIfs(inputPath);
    char* inputSource =
        strdup(std::string((std::istreambuf_iterator<char>(inputIfs)),
                           std::istreambuf_iterator<char>())
                   .c_str());
    if (std::string(command.outputPath) == "-ll") {
      return tsil_cli_compile(tsilCliConfig,
                              {
                                  write_to_stdout,
                                  nullptr,
                              },
                              command.options, inputPath, inputSource);
    } else {
      return tsil_cli_compile(tsilCliConfig,
                              {
                                  write_to_file_by_path,
                                  command.outputPath,
                              },
                              command.options, inputPath, inputSource);
    }
  }
  tsilCliConfig.println("Здається ви виявили помилку...");
  return 1;
}

extern "C" char* позитивне_в_ю8(unsigned long value) {
  return (char*)strdup(std::to_string(value).c_str());
}