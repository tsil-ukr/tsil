#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileString(x2::FunctionX2* xFunction,
                                           x2::FunctionX2Block* xBlock,
                                           ast::ASTValue* astValue) {
    const auto stringNode = astValue->data.StringNode;
    const auto stringValue = tsilStringToCString(stringNode->value);
    const auto xStringConstant =
        x2::CreateGlobalStringPtr(this->compiler->xModule, stringValue);
    if (stringNode->prefix == "ю8") {
      return {this->compiler->uint8Type->getPointerType(this), xStringConstant,
              nullptr};
    }
    return {nullptr, nullptr,
            CompilerError::fromASTValue(astValue,
                                        "Текст тимчасово не підтримується.")};
  }
} // namespace tsil::tk