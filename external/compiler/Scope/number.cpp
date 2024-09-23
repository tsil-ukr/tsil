#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileNumber(x2::FunctionX2* xFunction,
                                           x2::FunctionX2Block* xBlock,
                                           ast::ASTValue* astValue) {
    const auto numberNode = astValue->data.NumberNode;
    const auto type = str_contains(numberNode->value, ".")
                          ? this->compiler->f64Type
                          : this->compiler->int64Type;
    if (type == this->compiler->f64Type) {
      const auto xValue =
          x2::CreateDouble(this->compiler->xModule, 0); // todo: ...
      return {type, xValue, nullptr};
    }
    if (type == this->compiler->int64Type) {
      const auto xValue =
          x2::CreateInt64(this->compiler->xModule, 0); // todo: ...
      return {type, xValue, nullptr};
    }
  }
} // namespace tsil::tk