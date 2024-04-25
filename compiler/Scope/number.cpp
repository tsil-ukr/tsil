#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileNumber(tsil::x::Function* xFunction,
                                           tsil::x::FunctionBlock* xBlock,
                                           ast::ASTValue* astValue) {
    const auto numberNode = astValue->data.NumberNode;
    const auto type = str_contains(numberNode->value, ".")
                          ? this->compiler->doubleType
                          : this->compiler->int64Type;
    const auto xValue =
        new x::Value(type->xType, tsilNumberToLLVMNumber(numberNode->value));
    return {type, xValue, nullptr};
  }
} // namespace tsil::tk