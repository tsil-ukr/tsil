#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compileSizeof(
      tsil::ast::ASTValue* astValue) {
    const auto sizeofNode = astValue->data.SizeofNode;
    const auto typeResult =
        this->makeTypeFromTypeNodeASTValue(sizeofNode->value);
    if (!typeResult.type) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(sizeofNode->value, typeResult.error)};
    }
    const auto size = typeResult.type->getSizeOf(this);
    const auto xValue = this->state->Module->putI64Constant(size);
    return {this->state->int64Type, xValue, nullptr};
  }
} // namespace tsil::compiler