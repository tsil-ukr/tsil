#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitString(TsilParser::StringContext* context) {
    const auto text = context->getText();
    const auto string_node =
        new ast::StringNode(text.substr(1, text.length() - 2));
    return AV(context, ast::KindStringNode, string_node);
  }

  std::any TsilASTVisitor::visitAtom_string(
      TsilParser::Atom_stringContext* ctx) {
    return visitString(ctx->string());
  }
} // namespace tsil::parser