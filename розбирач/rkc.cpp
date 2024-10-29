#include <cstring>
#include <fstream>
#include <iostream>

extern "C" char *прочитати_файл(char *path) {
  std::ifstream file(path);
  if (file.fail()) {
    return nullptr;
  }
  std::string code((std::istreambuf_iterator<char>(file)),
                   std::istreambuf_iterator<char>());
  return strdup(code.c_str());
}