#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitSet(TsilParser::SetContext* context) {
    const auto set_node = new ast::SetNode();
    set_node->left = AAV(visitContext(context->s_left));
    set_node->value = AAV(visitContext(context->s_value));
    return AV(context, ast::KindSetNode, set_node);
  }
} // namespace tsil::parser