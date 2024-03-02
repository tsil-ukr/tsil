#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitBody(TsilParser::BodyContext* context) {
    std::vector<ast::ASTValue*> body;
    for (const auto body_element : context->body_element_or_return()) {
      const auto ast_value = AAV(visitBody_element_or_return(body_element));
      if (ast_value->kind == ast::KindIdentifierNode) {
        if (ast_value->data.IdentifierNode->name == "перервати") {
          const auto break_ast_value =
              ast::BreakNode::ast_value(new ast::BreakNode());
          break_ast_value->start_line = ast_value->start_line;
          break_ast_value->start_column = ast_value->start_column;
          break_ast_value->end_line = ast_value->end_line;
          break_ast_value->end_column = ast_value->end_column;
          body.push_back(break_ast_value);
        } else if (ast_value->data.IdentifierNode->name == "продовжити") {
          const auto continue_ast_value =
              ast::ContinueNode::ast_value(new ast::ContinueNode());
          continue_ast_value->start_line = ast_value->start_line;
          continue_ast_value->start_column = ast_value->start_column;
          continue_ast_value->end_line = ast_value->end_line;
          continue_ast_value->end_column = ast_value->end_column;
          body.push_back(continue_ast_value);
        } else {
          body.push_back(ast_value);
        }
      } else {
        body.push_back(ast_value);
      }
    }
    return body;
  }

  std::any TsilASTVisitor::visitBody_element(
      TsilParser::Body_elementContext* context) {
    if (context->if_()) {
      return visitIf(context->if_());
    }
    if (context->while_()) {
      return visitWhile(context->while_());
    }
    if (context->expr()) {
      return visitContext(context->expr());
    }
    if (context->define()) {
      return visitDefine(context->define());
    }
    if (context->assign()) {
      return visitAssign(context->assign());
    }
    if (context->set()) {
      return visitSet(context->set());
    }
    return new ast::ASTValue();
  }

  std::any TsilASTVisitor::visitBody_element_or_return(
      TsilParser::Body_element_or_returnContext* context) {
    if (context->body_element()) {
      return visitBody_element(context->body_element());
    }
    if (context->return_body_element()) {
      return visitReturn_body_element(context->return_body_element());
    }
    return new ast::ASTValue();
  }

  std::any TsilASTVisitor::visitReturn_body_element(
      TsilParser::Return_body_elementContext* context) {
    const auto return_node = new ast::ReturnNode();
    return_node->value = AAV(visitContext(context->rbl_value));
    return AV(context, ast::KindReturnNode, return_node);
  }
} // namespace tsil::parser