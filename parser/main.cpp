#include <iostream>
#include "parser.h"

int main() {
  std::string code = R"(
дія а() {
  вернути 1;
}
)";
  const auto parser_result = tsil::parser::parse(code);
  if (parser_result.ast_value) {
    std::cout << "Parsed successfully" << std::endl;
  } else {
    std::cout << "Failed to parse" << std::endl;
  }
  return 0;
}
