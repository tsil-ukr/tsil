#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitTake(TsilParser::TakeContext* context) {
    const auto take_node = new ast::TakeNode();
    take_node->repo = context->t_type->getText();
    if (context->t_string) {
      take_node->path = context->t_string->getText().substr(
          1, context->t_string->getText().size() - 2);
    }
    if (context->t_id) {
      take_node->id = context->t_id->getText();
    }
    return AV(context, ast::KindTakeNode, take_node);
  }
} // namespace tsil::parser