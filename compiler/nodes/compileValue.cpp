#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compileValue(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* astValue) {
    if (astValue->kind == tsil::ast::KindCallNode) {
      return this->compileCall(function, block, astValue);
    }
    if (astValue->kind == tsil::ast::KindIdentifierNode) {
      return this->compileLoad(function, block, astValue);
    }
    if (astValue->kind == tsil::ast::KindNumberNode) {
      return this->compileNumber(function, block, astValue);
    }
    if (astValue->kind == tsil::ast::KindStringNode) {
      return this->compileString(function, block, astValue);
    }
    if (astValue->kind == tsil::ast::KindGetNode) {
      return this->compileGet(function, block, astValue);
    }
    if (astValue->kind == tsil::ast::KindGetPointerNode) {
      return this->compileGep(function, block, astValue);
    }
    if (astValue->kind == tsil::ast::KindConstructorNode) {
      return this->compileConstruct(function, block, astValue);
    }
    if (astValue->kind == tsil::ast::KindSizeofNode) {
      return this->compileSizeof(astValue);
    }
    if (astValue->kind == tsil::ast::KindAsNode) {
      return this->compileAs(function, block, astValue);
    }
    if (astValue->kind == tsil::ast::KindBinaryNode) {
      return this->compileBinary(function, block, astValue);
    }
    return {
        nullptr, nullptr,
        CompilerError::fromASTValue(
            astValue, "Unknown ASTValue kind: " +
                          tsil::ast::ast_value_kind_to_string(astValue->kind))};
  }
} // namespace tsil::compiler