#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitTake(TsilParser::TakeContext* context) {
    const auto take_node = new ast::TakeNode();
    take_node->repo = context->t_type->getText();
    if (context->t_string) {
      take_node->path = context->t_string->getText().substr(
          1, context->t_string->getText().size() - 2);
    }
    if (context->t_parts) {
      if (context->t_parts->tp_relative) {
        take_node->parts_relative = true;
      }
      for (const auto id : context->t_parts->ID()) {
        take_node->parts.push_back(id->getText());
      }
    }
    return AV(context, ast::KindTakeNode, take_node);
  }
} // namespace tsil::parser