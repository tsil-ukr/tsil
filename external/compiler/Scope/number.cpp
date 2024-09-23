#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileNumber(XLFunction* xFunction,
                                           XLBasicBlock* xBlock,
                                           ast::ASTValue* astValue) {
    const auto numberNode = astValue->data.NumberNode;
    const auto type = str_contains(numberNode->value, ".")
                          ? this->compiler->f64Type
                          : this->compiler->int64Type;
    if (type == this->compiler->f64Type) {
      const auto xValue =
          tsil_xl_create_double(this->compiler->xModule, 0); // todo: ...
      return {type, xValue, nullptr};
    }
    if (type == this->compiler->int64Type) {
      const auto xValue =
          tsil_xl_create_int64(this->compiler->xModule, 0); // todo: ...
      return {type, xValue, nullptr};
    }
  }
} // namespace tsil::tk