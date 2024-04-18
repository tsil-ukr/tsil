#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitIf(TsilParser::IfContext* context) {
    const auto if_node = new ast::IfNode();
    if_node->condition = AAV(visitContext(context->i_value));
    if (context->i_body) {
      if_node->body = AAVec(visitBody(context->i_body));
    }
    if (context->i_else_body) {
      if_node->else_body = AAVec(visitBody(context->i_else_body));
    }
    return AV(context, ast::KindIfNode, if_node);
  }
} // namespace tsil::parser