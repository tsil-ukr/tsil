#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitNested(TsilParser::NestedContext* context) {
    return visitContext(context->n_value);
  }
} // namespace tsil::parser