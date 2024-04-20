#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitFullType(
      TsilParser::Full_typeContext* context) {
    if (const auto type = dynamic_cast<TsilParser::TypeContext*>(context)) {
      return visitType(type);
    }
    if (const auto type =
            dynamic_cast<TsilParser::Complex_function_typeContext*>(context)) {
      return visitComplex_function_type(type);
    }
    if (const auto type =
            dynamic_cast<TsilParser::Simple_function_typeContext*>(context)) {
      return visitSimple_function_type(type);
    }
    return nullptr;
  }

  std::any TsilASTVisitor::visitType(TsilParser::TypeContext* context) {
    const auto type_node = new ast::TypeNode();
    type_node->id = context->identifier()->getText();
    if (context->t_first_generic_type) {
      for (const auto generic : context->full_type()) {
        type_node->generics.push_back(AAV(visitFullType(generic)));
      }
    }
    return AV(context, ast::KindTypeNode, type_node);
  }

  std::any TsilASTVisitor::visitSimple_function_type(
      TsilParser::Simple_function_typeContext* context) {
    const auto function_type_node = new ast::FunctionTypeNode();
    function_type_node->args.push_back(AAV(visitFullType(context->sft_arg)));
    function_type_node->return_type = AAV(visitFullType(context->sft_ret));
    return AV(context, ast::KindFunctionTypeNode, function_type_node);
  }

  std::any TsilASTVisitor::visitComplex_function_type(
      TsilParser::Complex_function_typeContext* context) {
    const auto function_type_node = new ast::FunctionTypeNode();
    if (context->cft_args) {
      for (const auto arg : context->cft_args->full_type()) {
        function_type_node->args.push_back(AAV(visitFullType(arg)));
      }
    }
    function_type_node->return_type = AAV(visitFullType(context->cft_ret));
    return AV(context, ast::KindFunctionTypeNode, function_type_node);
  }
} // namespace tsil::parser