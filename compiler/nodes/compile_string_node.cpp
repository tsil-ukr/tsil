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

  CompilerValueResult CompilationScope::compile_string_node(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* ast_value) {
    const auto string_node = ast_value->data.StringNode;
    auto string_value = string_node->value;
    replace_all(string_value, "\\n", "\n");
    replace_all(string_value, "\\н", "\n");
    replace_all(string_value, "\\t", "\t");
    replace_all(string_value, "\\т", "\t");
    replace_all(string_value, "\\r", "\r");
    replace_all(string_value, "\\р", "\r");
    replace_all(string_value, "\\\"", "\"");
    replace_all(string_value, "\\\\", "\\");
    replace_all(string_value, "\\0", "\0");
    replace_all(string_value, "\\a", "\a");
    replace_all(string_value, "\\b", "\b");
    replace_all(string_value, "\\f", "\f");
    replace_all(string_value, "\\v", "\v");
    //    replace_all(string_value, "\\e", "\e");
    replace_all(string_value, "\\?", "\?");
    replace_all(string_value, "\\'", "\'");
    replace_all(string_value, "\\\"", "\"");
    const auto LV = this->state->Module->putStringConstant(string_value);
    if (string_node->prefix == "сі") {
      return {this->state->uint8Type->getPointerType(this), LV, nullptr};
    }
    const auto LAI = this->state->Module->pushFunctionBlockAllocaInstruction(
        block, this->state->textType->LT);
    const auto lengthLGEP =
        this->state->Module->pushFunctionBlockGetElementPtrInstruction(
            block, this->state->textType->LT, LAI, {0, 0});
    this->state->Module->pushFunctionBlockStoreInstruction(
        block,
        new x::Value{.number =
                         new x::Number(this->state->Module->int64Type,
                                       std::to_string(string_value.size()))},
        lengthLGEP);
    const auto dataLGEP =
        this->state->Module->pushFunctionBlockGetElementPtrInstruction(
            block, this->state->textType->LT, LAI, {0, 1});
    this->state->Module->pushFunctionBlockStoreInstruction(
        block, LV, dataLGEP);
    const auto LLOAD = this->state->Module->pushFunctionBlockLoadInstruction(
        block, LAI->instruction->alloca->type, LAI);
    return {this->state->textType, LLOAD, nullptr};
  }
} // namespace tsil::compiler