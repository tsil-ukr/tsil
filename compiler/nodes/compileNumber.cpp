#include "../compiler.h"

namespace tsil::compiler {
  void strreplace(std::string& str,
                  const std::string& from,
                  const std::string& to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
      str.replace(start_pos, from.length(), to);
      start_pos += to.length();
    }
  }

  bool strcontains(const std::string& str, const std::string& substr) {
    return str.find(substr) != std::string::npos;
  }

  CompilerValueResult CompilationScope::compileNumber(
      x::Function* xFunction,
      tsil::x::FunctionBlock* xBlock,
      tsil::ast::ASTValue* astValue) {
    const auto numberNode = astValue->data.NumberNode;
    if (numberNode->value.starts_with("0д")) {
      const auto binString = numberNode->value.substr(std::string("0д").size());
      const auto xValue =
          new x::Value(this->state->int64Type->LT,
                       std::to_string(std::stoll(binString, nullptr, 2)));
      return {this->state->int64Type, xValue, nullptr};
    }
    if (numberNode->value.starts_with("0ш")) {
      auto hexString = numberNode->value.substr(std::string("0ш").size());
      strreplace(hexString, "А", "A");
      strreplace(hexString, "а", "a");
      strreplace(hexString, "Б", "B");
      strreplace(hexString, "б", "b");
      strreplace(hexString, "В", "C");
      strreplace(hexString, "в", "c");
      strreplace(hexString, "Г", "D");
      strreplace(hexString, "г", "d");
      strreplace(hexString, "Ґ", "E");
      strreplace(hexString, "ґ", "e");
      strreplace(hexString, "Д", "F");
      strreplace(hexString, "д", "f");
      const auto xValue =
          new x::Value(this->state->int64Type->LT,
                       std::to_string(std::stoll(hexString, nullptr, 16)));
      return {this->state->int64Type, xValue, nullptr};
    }
    if (strcontains(numberNode->value, ".")) {
      const auto xValue =
          new x::Value(this->state->doubleType->LT, numberNode->value);
      return {this->state->doubleType, xValue, nullptr};
    }
    const auto xValue =
        new x::Value(this->state->int64Type->LT, numberNode->value);
    return {this->state->int64Type, xValue, nullptr};
  }
} // namespace tsil::compiler