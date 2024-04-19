#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitProgram(TsilParser::ProgramContext* context) {
    std::vector<ast::ASTValue*> body;
    for (const auto program_element : context->program_element()) {
      body.push_back(AAV(visitProgram_element(program_element)));
    }
    processASTBody(body);
    const auto program_node = new ast::ProgramNode();
    program_node->body = body;
    return AV(ast::KindProgramNode, program_node);
  }

  std::any TsilASTVisitor::visitProgram_element(
      TsilParser::Program_elementContext* context) {
    if (context->structure()) {
      return visitStructure(context->structure());
    }
    if (context->diia_declaration()) {
      return visitDiia_declaration(context->diia_declaration());
    }
    if (context->diia()) {
      return visitDiia(context->diia());
    }
    return new ast::ASTValue();
  }
} // namespace tsil::parser