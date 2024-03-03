#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compile_ast_value(
      tsil::ast::ASTValue* ast_value) {
    if (ast_value->kind == tsil::ast::KindCallNode) {
      return this->compile_call_node(ast_value);
    }
    if (ast_value->kind == tsil::ast::KindDefineNode) {
      return this->compile_define_node(ast_value);
    }
    if (ast_value->kind == tsil::ast::KindDiiaNode) {
      return this->compile_diia_node(ast_value);
    }
    if (ast_value->kind == tsil::ast::KindDiiaDeclarationNode) {
      return this->compile_diia_declaration_node(ast_value);
    }
    if (ast_value->kind == tsil::ast::KindIdentifierNode) {
      return this->compile_identifier_node(ast_value);
    }
    if (ast_value->kind == tsil::ast::KindNumberNode) {
      return this->compile_number_node(ast_value);
    }
    if (ast_value->kind == tsil::ast::KindStringNode) {
      return this->compile_string_node(ast_value);
    }
    return error("Unknown ASTValue kind: " +
                 tsil::ast::ast_value_kind_to_string(ast_value->kind));
  }
} // namespace tsil::compiler