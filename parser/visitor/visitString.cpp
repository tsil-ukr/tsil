#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitString(TsilParser::StringContext* context) {
    const auto text = context->STRING()->getText();
    const auto string_node = new ast::StringNode();
    if (context->s_prefix) {
      string_node->prefix = context->s_prefix->getText();
    }
    string_node->value = text.substr(1, text.length() - 2);
    return AV(context, ast::KindStringNode, string_node);
  }

  std::any TsilASTVisitor::visitAtom_string(
      TsilParser::Atom_stringContext* ctx) {
    return visitString(ctx->string());
  }
} // namespace tsil::parser