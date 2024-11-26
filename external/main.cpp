#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>

#include "tsil_cli.h"

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
  std::cout << "  ціль [--опції-цілі]... [(вихід) [--опції-виходу]...]... "
               "(команда) [--опції-команди]... [(вхід) [--опції-входу]...]..."
            << std::endl;
  std::cout << std::endl;
  std::cout << "Команди:" << std::endl;
  std::cout << "  допомога" << std::endl;
  std::cout << "    Опис: надрукувати допомогу" << std::endl;
  std::cout << "    Опції: немає" << std::endl;
  std::cout << "    Вихід: немає" << std::endl;
  std::cout << "    Вхід: немає" << std::endl;
  std::cout << "  версія" << std::endl;
  std::cout << "    Опис: надрукувати версію Цілі" << std::endl;
  std::cout << "    Опції: немає" << std::endl;
  std::cout << "    Вихід: немає" << std::endl;
  std::cout << "    Вхід: немає" << std::endl;
  std::cout << "  скомпілювати" << std::endl;
  std::cout << "    Опис: скомпілювати вхідний файл" << std::endl;
  std::cout << "    Опції: немає" << std::endl;
  std::cout << "    Вихід:" << std::endl;
  std::cout << "      Опції: " << std::endl;
  std::cout << "        --формат=<o|ll>" << std::endl;
  std::cout << "    Вхід:" << std::endl;
  std::cout << "      Формат: .ц" << std::endl;
  std::cout << "  сплавити" << std::endl;
  std::cout << "    Опис: сплавити вхідні файли" << std::endl;
  std::cout << "    Опції:" << std::endl;
  std::cout << "      --clang-options=\"додаткові опції до clang\""
            << std::endl;
  std::cout << "    Вихід:" << std::endl;
  std::cout << "      Опції: " << std::endl;
  std::cout << "        --формат=<elf>" << std::endl;
  std::cout << "    Вхід:" << std::endl;
  std::cout << "      Формат: .ц .c .o .a .ll" << std::endl;
}

int main(int argc, char** argv) {
  TsilCliConfig tsilCliConfig{.path = argv[0], .println = println};
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
  if (parsedCommand.type == TsilCliParsedCommandTypeVersion) {
    tsilCliConfig.println(TSIL_VERSION);
    return 0;
  }
  if (parsedCommand.type == TsilCliParsedCommandTypeCompile) {
    TsilCliCompileCommand command =
        std::get<TsilCliCompileCommand>(parsedCommand.c);
    return tsil_cli_run_compile_command(tsilCliConfig, command);
  }
  if (parsedCommand.type == TsilCliParsedCommandTypeFuse) {
    TsilCliFuseCommand command = std::get<TsilCliFuseCommand>(parsedCommand.c);
    return tsil_cli_run_fuse_command(tsilCliConfig, command);
  }
  tsilCliConfig.println("Здається ви виявили помилку...");
  return 1;
}

extern "C" char* позитивне_в_ю8(unsigned long value) {
  return (char*)strdup(std::to_string(value).c_str());
}

extern "C" char* отримати_копію_cwd() {
  char* cwd = strdup(std::filesystem::current_path().c_str());
  return cwd;
}

extern "C" size_t перевірити_чи_файл_існує(char* path) {
  return std::filesystem::exists(path);
}

extern "C" size_t перевірити_чи_файл_доступний(char* path) {
  return std::filesystem::exists(path) &&
         std::filesystem::is_regular_file(path);
}

extern "C" char* прочитати_файл(char* path) {
  std::ifstream file(path);
  if (!file.is_open()) {
    return nullptr;
  }
  std::string content((std::istreambuf_iterator<char>(file)),
                      std::istreambuf_iterator<char>());
  return strdup(content.c_str());
}

void str_replace_all(std::string& str,
                     const std::string& from,
                     const std::string& to) {
  if (from.empty()) {
    return;
  }
  size_t start_pos = 0;
  while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length();
  }
}

extern "C" char* tsil_hex_to_dec(char* value) {
  std::string strvalue = value;
  str_replace_all(strvalue, "А", "A");
  str_replace_all(strvalue, "а", "a");
  str_replace_all(strvalue, "Б", "B");
  str_replace_all(strvalue, "б", "b");
  str_replace_all(strvalue, "В", "C");
  str_replace_all(strvalue, "в", "c");
  str_replace_all(strvalue, "Г", "D");
  str_replace_all(strvalue, "г", "d");
  str_replace_all(strvalue, "Д", "E");
  str_replace_all(strvalue, "д", "e");
  str_replace_all(strvalue, "Е", "F");
  str_replace_all(strvalue, "е", "f");
  return strdup(std::to_string(std::stoll(strvalue, nullptr, 16)).c_str());
}

extern "C" char* tsil_replace_backslashes(char* value) {
  std::string str = value;
  str_replace_all(str, "\\n", "\n");
  str_replace_all(str, "\\r", "\r");
  str_replace_all(str, "\\t", "\t");
  str_replace_all(str, "\\v", "\v");
  str_replace_all(str, "\\0", "\0");
  str_replace_all(str, "\\a", "\a");
  str_replace_all(str, "\\b", "\b");
  str_replace_all(str, "\\f", "\f");
  str_replace_all(str, "\\e", "\e");
  str_replace_all(str, "\\\\", "\\");
  str_replace_all(str, "\\\"", "\"");
  return strdup(str.c_str());
}

extern "C" char* отримати_шлях_до_папки_файлу(char* path) {
  return strdup(std::filesystem::path(path).parent_path().c_str());
}

extern "C" char* вирівняти_шлях(char* path) {
  return strdup(std::filesystem::path(path).lexically_normal().c_str());
}