#include "tk.h"

namespace tsil::tk {
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

  bool str_contains(const std::string& str, const std::string& substr) {
    return str.find(substr) != std::string::npos;
  }

  std::string getTsilAstBinaryOpSymbol(tsil::ast::BinaryOp op) {
    switch (op) {
      case tsil::ast::ARITHMETIC_ADD:
        return "+";
      case tsil::ast::ARITHMETIC_SUB:
        return "-";
      case tsil::ast::ARITHMETIC_MUL:
        return "*";
      case tsil::ast::ARITHMETIC_DIV:
        return "/";
      case tsil::ast::ARITHMETIC_MOD:
        return "%";
      case tsil::ast::BITWISE_AND:
        return "&";
      case tsil::ast::BITWISE_OR:
        return "|";
      case tsil::ast::BITWISE_XOR:
        return "^";
      case tsil::ast::BITWISE_SHIFT_LEFT:
        return "<<";
      case tsil::ast::BITWISE_SHIFT_RIGHT:
        return ">>";
      case tsil::ast::COMPARISON_EQ:
        return "==";
      case tsil::ast::COMPARISON_NE:
        return "!=";
      case tsil::ast::COMPARISON_LT:
        return "<";
      case tsil::ast::COMPARISON_GT:
        return ">";
      case tsil::ast::COMPARISON_LE:
        return "<=";
      case tsil::ast::COMPARISON_GE:
        return ">=";
    }
    return "";
  }

  std::string tsilNumberToLLVMNumber(const std::string& value) {
    if (value.starts_with("0д")) {
      const auto binString = value.substr(std::string("0д").size());
      return std::to_string(std::stoll(binString, nullptr, 2));
    }
    if (value.starts_with("0ш")) {
      auto hexString = value.substr(std::string("0ш").size());
      str_replace_all(hexString, "А", "A");
      str_replace_all(hexString, "а", "a");
      str_replace_all(hexString, "Б", "B");
      str_replace_all(hexString, "б", "b");
      str_replace_all(hexString, "В", "C");
      str_replace_all(hexString, "в", "c");
      str_replace_all(hexString, "Г", "D");
      str_replace_all(hexString, "г", "d");
      str_replace_all(hexString, "Ґ", "E");
      str_replace_all(hexString, "ґ", "e");
      str_replace_all(hexString, "Д", "F");
      str_replace_all(hexString, "д", "f");
      return std::to_string(std::stoll(hexString, nullptr, 16));
    }
    return value;
  }

  std::string tsilStringToCString(const std::string& value) {
    auto stringValue = value;
    str_replace_all(stringValue, "\\н", "\n");
    str_replace_all(stringValue, "\\т", "\t");
    str_replace_all(stringValue, "\\р", "\r");
    str_replace_all(stringValue, "\\n", "\n");
    str_replace_all(stringValue, "\\t", "\t");
    str_replace_all(stringValue, "\\r", "\r");
    str_replace_all(stringValue, "\\\\", "\\");
    str_replace_all(stringValue, "\\a", "\a");
    str_replace_all(stringValue, "\\b", "\b");
    str_replace_all(stringValue, "\\f", "\f");
    str_replace_all(stringValue, "\\v", "\v");
    str_replace_all(stringValue, "\\?", "\?");
    str_replace_all(stringValue, "\\'", "\'");
    str_replace_all(stringValue, "\\\"", "\"");
    str_replace_all(stringValue, "\\0", "\0");
    return stringValue;
  }
} // namespace tsil::tk