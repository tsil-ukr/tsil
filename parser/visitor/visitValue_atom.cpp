#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitValue_atom(TsilParser::Value_atomContext* ctx) {
    return visitContext(ctx->atom());
  }
} // namespace tsil::parser