#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitConstructor(
      TsilParser::ConstructorContext* context) {
    const auto constructor_node = new ast::ConstructorNode();
    constructor_node->type = AAV(visitContext(context->c_type));
    if (context->c_args) {
      constructor_node->args = AAVec(visitConstructor_args(context->c_args));
    }
    return AV(context, ast::KindConstructorNode, constructor_node);
  }

  std::any TsilASTVisitor::visitConstructor_args(
      TsilParser::Constructor_argsContext* context) {
    std::vector<ast::ASTValue*> args;
    for (const auto arg : context->constructor_arg()) {
      args.push_back(AAV(visitConstructor_arg(arg)));
    }
    return args;
  }

  std::any TsilASTVisitor::visitConstructor_arg(
      TsilParser::Constructor_argContext* context) {
    const auto constructor_arg_node = new ast::ConstructorArgNode();
    constructor_arg_node->id = context->ca_name->getText();
    constructor_arg_node->value = AAV(visitContext(context->ca_value));
    return AV(context, ast::KindConstructorArgNode, constructor_arg_node);
  }

  std::any TsilASTVisitor::visitAtom_constructor(
      TsilParser::Atom_constructorContext* ctx) {
    return visitContext(ctx->constructor());
  }
} // namespace tsil::parser