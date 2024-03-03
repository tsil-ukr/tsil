#include <iostream>

extern "C" void друк(char* str) {
  std::cout << str << std::endl;
}
