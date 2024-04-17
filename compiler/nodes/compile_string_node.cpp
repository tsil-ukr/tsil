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
    const auto LV = this->state->Builder->CreateGlobalStringPtr(string_value);
    if (string_node->prefix == "сі") {
      return {this->state->uint8Type->getPointerType(), LV, nullptr};
    }
    const auto LF = this->state->Builder->GetInsertBlock()->getParent();
    const auto LAI =
        this->createEntryBlockAlloca(this->state->textType->LT, LF);
    const auto lengthLGEP = this->state->Builder->CreateGEP(
        this->state->textType->LT, LAI,
        {this->state->Builder->getInt32(0), this->state->Builder->getInt32(0)});
    this->state->Builder->CreateStore(
        llvm::ConstantInt::get(*state->Context,
                               llvm::APInt(64, string_value.size())),
        lengthLGEP);
    const auto dataLGEP = this->state->Builder->CreateGEP(
        this->state->textType->LT, LAI,
        {this->state->Builder->getInt32(0), this->state->Builder->getInt32(1)});
    this->state->Builder->CreateStore(LV, dataLGEP);
    const auto LLOAD =
        this->state->Builder->CreateLoad(LAI->getAllocatedType(), LAI);
    return {this->state->textType, LLOAD, nullptr};
  }
} // namespace tsil::compiler