#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitType(TsilParser::TypeContext* context) {
    const auto type_node = new ast::TypeNode();
    type_node->id = context->ID()->getText();
    return AV(context, ast::KindTypeNode, type_node);
  }
} // namespace tsil::parser