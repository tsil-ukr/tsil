#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitValue_atom(TsilParser::Value_atomContext* ctx) {
    return visitContext(ctx->atom());
  }

  std::any TsilASTVisitor::visitExpr_molecule(
      TsilParser::Expr_moleculeContext* ctx) {
    return visitContext(ctx->molecule());
  }
} // namespace tsil::parser