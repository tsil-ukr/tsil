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

int main() {
  std::string filename = "тест.ц";
  std::ifstream file(filename);
  std::string code((std::istreambuf_iterator<char>(file)),
                   std::istreambuf_iterator<char>());
  return tsil_cli_compile_single(
      TsilCliConfig{.println = println},
      {
          [](unsigned char* data, void* options) { println((char*)data); },
          nullptr,
      },
      TsilCliCompileOptions{.outFormat = TsilCliCompileOutFormatLLVM,
                            .libraryPath = ""},
      strdup(filename.c_str()), strdup(code.c_str()));
  return 0;
}

extern "C" char* позитивне_в_ю8(unsigned long value) {
  return (char*)strdup(std::to_string(value).c_str());
}