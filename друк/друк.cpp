#include <codecvt>
#include <iostream>
#include <locale>

extern "C" void друк_ю8(unsigned char* value) {
  std::cout << value << std::endl;
}

extern "C" void друк_ю16(unsigned short int* value) {
  std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> conversion;
  std::string mbs = conversion.to_bytes((char16_t*)value);
  std::cout << mbs << std::endl;
}

extern "C" void друк_ю32(unsigned int* value) {
  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert;
  std::string mbs = convert.to_bytes((char32_t*)value);
  std::cout << mbs << std::endl;
}

extern "C" void друк_п8(unsigned char value) {
  std::cout << (unsigned int)value << std::endl;
}

extern "C" void друк_п16(unsigned short int value) {
  std::cout << (unsigned int)value << std::endl;
}

extern "C" void друк_п32(unsigned int value) {
  std::cout << value << std::endl;
}

extern "C" void друк_п64(unsigned long value) {
  std::cout << value << std::endl;
}

extern "C" void друк_ц8(char value) {
  std::cout << (int)value << std::endl;
}

extern "C" void друк_ц32(int value) {
  std::cout << value << std::endl;
}

extern "C" void друк_ц64(long value) {
  std::cout << value << std::endl;
}

extern "C" void друк_д32(float value) {
  std::cout << value << std::endl;
}

extern "C" void друк_д64(float value) {
  std::cout << value << std::endl;
}

extern "C" void вивести_ю8(char* value) {
  std::cout << value;
}

extern "C" void вивести_п8(unsigned char value) {
  std::cout << (unsigned int)value;
}

extern "C" void вивести_п32(unsigned int value) {
  std::cout << value;
}

extern "C" void вивести_п64(unsigned long value) {
  std::cout << value;
}

extern "C" void вивести_ц8(char value) {
  std::cout << (int)value;
}

extern "C" void вивести_ц32(int value) {
  std::cout << value;
}

extern "C" void вивести_ц64(long value) {
  std::cout << value;
}

extern "C" void вивести_д32(float value) {
  std::cout << value;
}

extern "C" void вивести_д64(float value) {
  std::cout << value;
}
