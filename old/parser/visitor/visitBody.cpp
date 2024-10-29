#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitBody(TsilParser::BodyContext* context) {
    std::vector<ast::ASTValue*> body;
    for (const auto body_element : context->body_element()) {
      if (body_element->if_()) {
        body.push_back(AAV(visitIf(body_element->if_())));
      }
      if (body_element->while_()) {
        body.push_back(AAV(visitWhile(body_element->while_())));
      }
      if (body_element->synonym()) {
        body.push_back(AAV(visitSynonym(body_element->synonym())));
      }
      if (body_element->declare()) {
        body.push_back(AAV(visitDeclare(body_element->declare())));
      }
      if (body_element->define()) {
        body.push_back(AAV(visitDefine(body_element->define())));
      }
      if (body_element->assign()) {
        body.push_back(AAV(visitAssign(body_element->assign())));
      }
      if (body_element->set()) {
        body.push_back(AAV(visitSet(body_element->set())));
      }
      if (body_element->expr()) {
        body.push_back(AAV(visitContext(body_element->expr())));
      }
      if (body_element->return_body_element()) {
        const auto return_node = new ast::ReturnNode();
        if (body_element->return_body_element()->rbl_value) {
          return_node->value =
              AAV(visitContext(body_element->return_body_element()->rbl_value));
        }
        body.push_back(AV(context, ast::KindReturnNode, return_node));
      }
      if (body_element->block()) {
        body.push_back(AAV(visitBlock(body_element->block())));
      }
      if (body_element->defer()) {
        body.push_back(AAV(visitDefer(body_element->defer())));
      }
    }
    return body;
  }

  std::any TsilASTVisitor::visitBlock(TsilParser::BlockContext* ctx) {
    const auto block_node = new ast::BlockNode();
    block_node->body = AAVec(visitBody(ctx->body()));
    return AV(ctx, ast::KindBlockNode, block_node);
  }

  std::any TsilASTVisitor::visitDefer(TsilParser::DeferContext* ctx) {
    const auto defer_node = new ast::DeferNode();
    if (ctx->assign()) {
      defer_node->value = AAV(visitContext(ctx->assign()));
    }
    if (ctx->set()) {
      defer_node->value = AAV(visitContext(ctx->set()));
    }
    if (ctx->expr()) {
      defer_node->value = AAV(visitContext(ctx->expr()));
    }
    return AV(ctx, ast::KindDeferNode, defer_node);
  }
} // namespace tsil::parser