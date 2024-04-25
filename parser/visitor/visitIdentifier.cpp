#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitIdentifier(
      TsilParser::IdentifierContext* context) {
    const auto identifier_node = new ast::IdentifierNode();
    identifier_node->name = context->getText();
    return AV(context, ast::KindIdentifierNode, identifier_node);
  }
} // namespace tsil::parser