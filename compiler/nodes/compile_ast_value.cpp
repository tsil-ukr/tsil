#include "../compiler.h"

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_ast_value(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* ast_value) {
    if (ast_value->kind == tsil::ast::KindCallNode) {
      return this->compile_call_node(function, block, ast_value);
    }
    if (ast_value->kind == tsil::ast::KindIdentifierNode) {
      return this->compile_identifier_node(function, block, ast_value);
    }
    if (ast_value->kind == tsil::ast::KindNumberNode) {
      return this->compile_number_node(ast_value);
    }
    if (ast_value->kind == tsil::ast::KindStringNode) {
      return this->compile_string_node(function, block, ast_value);
    }
    if (ast_value->kind == tsil::ast::KindGetNode) {
      return this->compile_get_node(function, block, ast_value);
    }
    if (ast_value->kind == tsil::ast::KindGetPointerNode) {
      return this->compile_get_pointer_node(function, block, ast_value);
    }
    if (ast_value->kind == tsil::ast::KindConstructorNode) {
      return this->compile_constructor_node(function, block, ast_value);
    }
    if (ast_value->kind == tsil::ast::KindSizeofNode) {
      return this->compile_sizeof_node(ast_value);
    }
    if (ast_value->kind == tsil::ast::KindAsNode) {
      return this->compile_as_node(function, block, ast_value);
    }
    return {nullptr, nullptr,
            new CompilerError(
                "Unknown ASTValue kind: " +
                tsil::ast::ast_value_kind_to_string(ast_value->kind))};
  }
} // namespace tsil::compiler