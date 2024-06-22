#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitSimple_type(
      TsilParser::Simple_typeContext* context) {
    const auto type_node = new ast::TypeNode();
    type_node->id = AAV(visitContext(context->section_access()));
    if (context->t_first_generic_type) {
      for (const auto generic : context->full_type()) {
        type_node->generics.push_back(AAV(visitContext(generic)));
      }
    }
    return AV(context, ast::KindTypeNode, type_node);
  }

  std::any TsilASTVisitor::visitArray_type(
      TsilParser::Array_typeContext* context) {
    const auto array_type_node = new ast::ArrayTypeNode();
    array_type_node->type = AAV(visitContext(context->at_type));
    const auto size_number_node = new ast::NumberNode();
    size_number_node->value = context->at_size->getText();
    array_type_node->size =
        AV(context->at_size, ast::KindNumberNode, size_number_node);
    return AV(context, ast::KindArrayTypeNode, array_type_node);
  }

  std::any TsilASTVisitor::visitComplex_function_type(
      TsilParser::Complex_function_typeContext* context) {
    const auto function_type_node = new ast::FunctionTypeNode();
    if (context->cft_args) {
      for (const auto arg : context->cft_args->full_type()) {
        function_type_node->args.push_back(AAV(visitContext(arg)));
      }
    }
    function_type_node->return_type = AAV(visitContext(context->cft_ret));
    return AV(context, ast::KindFunctionTypeNode, function_type_node);
  }

  std::any TsilASTVisitor::visitSimple_function_type(
      TsilParser::Simple_function_typeContext* context) {
    const auto function_type_node = new ast::FunctionTypeNode();
    function_type_node->args.push_back(AAV(visitContext(context->sft_arg)));
    function_type_node->return_type = AAV(visitContext(context->sft_ret));
    return AV(context, ast::KindFunctionTypeNode, function_type_node);
  }

  std::any TsilASTVisitor::visitVariation_type(
      TsilParser::Variation_typeContext* context) {
    const auto variation_type_node = new ast::VariationTypeNode();
    for (const auto type : context->basic_type()) {
      variation_type_node->types.push_back(AAV(visitContext(type)));
    }
    return AV(context, ast::KindVariationTypeNode, variation_type_node);
  }

  std::any TsilASTVisitor::visitFull_type_nested(
      TsilParser::Full_type_nestedContext* context) {
    return visitContext(context->full_type());
  }

  std::any TsilASTVisitor::visitBasic_type_real_basic(
      TsilParser::Basic_type_real_basicContext* context) {
    return visitContext(context->basic_type());
  }
} // namespace tsil::parser