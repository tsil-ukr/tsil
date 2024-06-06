#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileString(tsil::x::Function* xFunction,
                                           tsil::x::FunctionBlock* xBlock,
                                           ast::ASTValue* astValue) {
    const auto stringNode = astValue->data.StringNode;
    const auto stringValue = tsilStringToLLVMString(stringNode->value);
    const auto xStringConstant =
        this->compiler->xModule->putStringConstant("private", stringValue);
    if (stringNode->prefix == "сі") {
      return {this->compiler->int8Type->getPointerType(this), xStringConstant,
              nullptr};
    }
    return {nullptr, nullptr,
            CompilerError::fromASTValue(astValue,
                                        "Текст тимчасово не підтримується.")};
  }
} // namespace tsil::tk