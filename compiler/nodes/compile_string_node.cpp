#include "../compiler.h"

namespace tsil::compiler {
  void replace_all(std::string& str,
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

  CompilerResult CompilationScope::compile_string_node(
      tsil::ast::ASTValue* ast_value) {
    const auto string_node = ast_value->data.StringNode;
    auto string_value = string_node->value;
    replace_all(string_value, "\\n", "\n");
    replace_all(string_value, "\\t", "\t");
    replace_all(string_value, "\\r", "\r");
    replace_all(string_value, "\\\"", "\"");
    replace_all(string_value, "\\\\", "\\");
    replace_all(string_value, "\\0", "\0");
    replace_all(string_value, "\\a", "\a");
    replace_all(string_value, "\\b", "\b");
    replace_all(string_value, "\\f", "\f");
    replace_all(string_value, "\\v", "\v");
    replace_all(string_value, "\\e", "\e");
    replace_all(string_value, "\\?", "\?");
    replace_all(string_value, "\\'", "\'");
    replace_all(string_value, "\\\"", "\"");
    const auto llval =
        this->state->Builder->CreateGlobalStringPtr(string_value);
    return ok(llval, nullptr);
  }
} // namespace tsil::compiler