#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitIdentifier(
      TsilParser::IdentifierContext* context) {
    const auto identifier_node = new ast::IdentifierNode();
    identifier_node->name = context->getText();
    return AV(context, ast::KindIdentifierNode, identifier_node);
  }

  std::any TsilASTVisitor::visitReal_section_access(
      TsilParser::Real_section_accessContext* context) {
    if (context->identifier().size() == 1) {
      return AAV(visitIdentifier(context->identifier().front()));
    }
    const auto section_access_node = new ast::SectionAccessNode();
    for (const auto& id : context->identifier()) {
      section_access_node->parts.push_back(AAV(visitIdentifier(id)));
    }
    return AV(context, ast::KindSectionAccessNode, section_access_node);
  }
} // namespace tsil::parser