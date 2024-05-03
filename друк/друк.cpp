#include <iostream>

extern "C" void друк_сі(char* value) {
  std::cout << value << std::endl;
}

extern "C" void друк_п8(unsigned char value) {
  std::cout << value << std::endl;
}

extern "C" void друк_п32(unsigned int value) {
  std::cout << value << std::endl;
}

extern "C" void друк_п64(unsigned long value) {
  std::cout << value << std::endl;
}

extern "C" void друк_позитивне(unsigned long value) {
  std::cout << value << std::endl;
}

extern "C" void друк_ц8(char value) {
  std::cout << value << std::endl;
}

extern "C" void друк_ц32(int value) {
  std::cout << value << std::endl;
}

extern "C" void друк_ц64(long value) {
  std::cout << value << std::endl;
}

extern "C" void друк_ціле(long value) {
  std::cout << value << std::endl;
}

extern "C" void друк_д32(float value) {
  std::cout << value << std::endl;
}

extern "C" void друк_д64(float value) {
  std::cout << value << std::endl;
}

extern "C" void друк_дійсне(double value) {
  std::cout << value << std::endl;
}

extern "C" void вивести_сі(char* value) {
  std::cout << value;
}

extern "C" void вивести_п8(unsigned char value) {
  std::cout << value;
}

extern "C" void вивести_п32(unsigned int value) {
  std::cout << value;
}

extern "C" void вивести_п64(unsigned long value) {
  std::cout << value;
}

extern "C" void вивести_позитивне(unsigned long value) {
  std::cout << value;
}

extern "C" void вивести_ц8(char value) {
  std::cout << value;
}

extern "C" void вивести_ц32(int value) {
  std::cout << value;
}

extern "C" void вивести_ц64(long value) {
  std::cout << value;
}

extern "C" void вивести_ціле(long value) {
  std::cout << value;
}

extern "C" void вивести_д32(float value) {
  std::cout << value;
}

extern "C" void вивести_д64(float value) {
  std::cout << value;
}

extern "C" void вивести_дійсне(double value) {
  std::cout << value;
}