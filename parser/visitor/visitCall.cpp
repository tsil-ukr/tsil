#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitCall(TsilParser::CallContext* context) {
    const auto call_node = new ast::CallNode();
    call_node->value = AAV(visitContext(context->c_value));
    if (context->c_args) {
      call_node->args = AAVec(visitArgs(context->c_args));
    }
    return AV(context, ast::KindCallNode, call_node);
  }
} // namespace tsil::parser