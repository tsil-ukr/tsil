#include "../compiler.h"

namespace tsil::compiler {
  void strreplaceall(std::string& str,
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

  CompilerValueResult CompilationScope::compileString(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* astValue) {
    const auto string_node = astValue->data.StringNode;
    auto string_value = string_node->value;
    strreplaceall(string_value, "\\n", "\n");
    strreplaceall(string_value, "\\н", "\n");
    strreplaceall(string_value, "\\t", "\t");
    strreplaceall(string_value, "\\т", "\t");
    strreplaceall(string_value, "\\r", "\r");
    strreplaceall(string_value, "\\р", "\r");
    strreplaceall(string_value, "\\\"", "\"");
    strreplaceall(string_value, "\\\\", "\\");
    strreplaceall(string_value, "\\0", "\0");
    strreplaceall(string_value, "\\a", "\a");
    strreplaceall(string_value, "\\b", "\b");
    strreplaceall(string_value, "\\f", "\f");
    strreplaceall(string_value, "\\v", "\v");
    //    strreplaceall(string_value, "\\e", "\e");
    strreplaceall(string_value, "\\?", "\?");
    strreplaceall(string_value, "\\'", "\'");
    strreplaceall(string_value, "\\\"", "\"");
    const auto xStringConstant =
        this->state->Module->putStringConstant(string_value);
    if (string_node->prefix == "сі") {
      return {this->state->uint8Type->getPointerType(this), xStringConstant,
              nullptr};
    }
    const auto textAllocaXValue =
        this->state->Module->pushFunctionBlockAllocaInstruction(
            block, this->state->textType->LT);
    const auto lengthGepXValue =
        this->state->Module->pushFunctionBlockGetElementPtrInstruction(
            block, this->state->textType->LT, textAllocaXValue, {0, 0});
    const auto sizeXValue = new x::Value(this->state->Module->int64Type,
                                         std::to_string(string_value.size()));
    this->state->Module->pushFunctionBlockStoreInstruction(
        block, sizeXValue->type, sizeXValue, lengthGepXValue);
    const auto dataGepXValue =
        this->state->Module->pushFunctionBlockGetElementPtrInstruction(
            block, this->state->textType->LT, textAllocaXValue, {0, 1});
    this->state->Module->pushFunctionBlockStoreInstruction(
        block, xStringConstant->type, xStringConstant, dataGepXValue);
    const auto textLoadXValue =
        this->state->Module->pushFunctionBlockLoadInstruction(
            block, this->state->textType->LT, textAllocaXValue);
    return {this->state->textType, textLoadXValue, nullptr};
  }
} // namespace tsil::compiler