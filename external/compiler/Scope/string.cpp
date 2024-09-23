#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileString(XLFunction* xFunction,
                                           XLBasicBlock* xBlock,
                                           ast::ASTValue* astValue) {
    const auto stringNode = astValue->data.StringNode;
    const auto stringValue = tsilStringToCString(stringNode->value);
    const auto xStringConstant = tsil_xl_create_string(
        this->compiler->xModule, strdup(stringValue.c_str()));
    std::cout << "String: " << stringValue << std::endl;
    if (stringNode->prefix == "ю8") {
      return {this->compiler->uint8Type->getPointerType(this), xStringConstant,
              nullptr};
    }
    return {nullptr, nullptr,
            CompilerError::fromASTValue(astValue,
                                        "Текст тимчасово не підтримується.")};
  }
} // namespace tsil::tk