#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitFile(TsilParser::FileContext* ctx) {
    return visitProgram(ctx->f_program);
  }
} // namespace tsil::parser