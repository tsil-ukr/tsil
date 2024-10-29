#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitSynonym(TsilParser::SynonymContext* context) {
    const auto synonym_node = new ast::SynonymNode();
    synonym_node->id = context->ID()->getText();
    if (context->s_value->full_type()) {
      synonym_node->value = AAV(visitContext(context->s_value->full_type()));
    }
    if (context->s_value->number()) {
      synonym_node->value = AAV(visitContext(context->s_value->number()));
    }
    if (context->s_value->string()) {
      synonym_node->value = AAV(visitContext(context->s_value->string()));
    }
    return AV(context, ast::KindSynonymNode, synonym_node);
  }
} // namespace tsil::parser