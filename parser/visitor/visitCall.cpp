#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitCall(TsilParser::CallContext* context) {
    const auto call_node = new ast::CallNode();
    call_node->value = AAV(visitContext(context->c_value));
    if (context->c_first_generic_type) {
      for (const auto& generic_type : context->full_type()) {
        call_node->generic_values.push_back(AAV(visitContext(generic_type)));
      }
    }
    if (context->c_args) {
      for (const auto& arg : context->c_args->expr()) {
        call_node->args.push_back(AAV(visitContext(arg)));
      }
    }
    return AV(context, ast::KindCallNode, call_node);
  }
} // namespace tsil::parser