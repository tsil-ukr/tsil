#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitWhile(TsilParser::WhileContext* context) {
    const auto while_node = new ast::WhileNode();
    while_node->condition = AAV(visitContext(context->w_value));
    if (context->w_body) {
      while_node->body = AAVec(visitBody(context->w_body));
    }
    return AV(context, ast::KindWhileNode, while_node);
  }
} // namespace tsil::parser