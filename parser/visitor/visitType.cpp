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
    if (const auto type =
            dynamic_cast<TsilParser::Array_typeContext*>(context)) {
      return visitArray_type(type);
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

  std::any TsilASTVisitor::visitArray_type(TsilParser::Array_typeContext* ctx) {
    const auto array_type_node = new ast::ArrayTypeNode();
    array_type_node->type = AAV(visitFullType(ctx->at_type));
    array_type_node->size = AAV(visitContext(ctx->at_size));
    return AV(ctx, ast::KindArrayTypeNode, array_type_node);
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