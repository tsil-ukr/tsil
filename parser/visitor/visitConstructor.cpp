#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitConstruct(
      TsilParser::ConstructContext* context) {
    const auto construct_node = new ast::ConstructorNode();
    construct_node->type = AAV(visitContext(context->c_type));
    if (context->c_args) {
      for (const auto constructor_arg : context->c_args->construct_arg()) {
        const auto constructor_arg_node = new ast::ConstructorArgNode();
        if (constructor_arg->ca_name) {
          constructor_arg_node->id = constructor_arg->ca_name->getText();
        }
        constructor_arg_node->value =
            AAV(visitContext(constructor_arg->ca_value));
        construct_node->args.push_back(AV(constructor_arg,
                                          ast::KindConstructorArgNode,
                                          constructor_arg_node));
      }
    }
    return AV(context, ast::KindConstructorNode, construct_node);
  }
} // namespace tsil::parser