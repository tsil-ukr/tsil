#include "compiler.h"

namespace tsil::compiler {
  CompilerResult ok(llvm::Value* llval, Type* type) {
    const auto value = new Value{llval, type};
    return {value, nullptr};
  }

  CompilerResult error(const std::string& message) {
    return {nullptr, new CompilerError{message}};
  }
} // namespace tsil::compiler