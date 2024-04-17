#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitSizeof(TsilParser::SizeofContext* context) {
    const auto sizeof_node = new ast::SizeofNode();
    sizeof_node->value = AAV(visitContext(context->s_type));
    return AV(context, ast::KindSizeofNode, sizeof_node);
  }

  std::any TsilASTVisitor::visitAtom_sizeof(
      TsilParser::Atom_sizeofContext* ctx) {
    return visitSizeof(ctx->sizeof_());
  }
} // namespace tsil::parser