#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitIdentifier(
      TsilParser::IdentifierContext* context) {
    const auto identifier_node = new ast::IdentifierNode();
    identifier_node->name = context->getText();
    return AV(context, ast::KindIdentifierNode, identifier_node);
  }

  std::any TsilASTVisitor::visitIdentifiers_chain(
      TsilParser::Identifiers_chainContext* context) {
    if (context->ic_id) {
      const auto identifier_node = new ast::IdentifierNode();
      identifier_node->name = context->ic_id->getText();
      return AV(context, ast::KindIdentifierNode, identifier_node);
    }
    const auto get_node = new ast::GetNode();
    get_node->left = AAV(visitIdentifiers_chain(context->ic_left));
    get_node->id = context->ic_right->getText();
    return AV(context, ast::KindGetNode, get_node);
  }

  std::any TsilASTVisitor::visitAtom_identifier(
      TsilParser::Atom_identifierContext* ctx) {
    return visitIdentifier(ctx->identifier());
  }
} // namespace tsil::parser