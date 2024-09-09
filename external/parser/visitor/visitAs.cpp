#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitAs(TsilParser::AsContext* ctx) {
    const auto as_node = new ast::AsNode();
    as_node->value = AAV(visitContext(ctx->a_left));
    as_node->type = AAV(visitContext(ctx->a_type));
    return AV(ctx, ast::KindAsNode, as_node);
  }
} // namespace tsil::parser