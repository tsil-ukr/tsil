#include "../parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitProgram(TsilParser::ProgramContext* context) {
    const auto program_node = new ast::ProgramNode();
    for (const auto program_element : context->program_element()) {
      if (program_element->take()) {
        program_node->body.push_back(AAV(visitTake(program_element->take())));
      }
      if (program_element->synonym()) {
        program_node->body.push_back(
            AAV(visitSynonym(program_element->synonym())));
      }
      if (program_element->declare()) {
        program_node->body.push_back(
            AAV(visitDeclare(program_element->declare())));
      }
      if (program_element->define()) {
        program_node->body.push_back(
            AAV(visitDefine(program_element->define())));
      }
      if (program_element->section()) {
        program_node->body.push_back(
            AAV(visitSection(program_element->section())));
      }
      if (program_element->structure()) {
        program_node->body.push_back(
            AAV(visitStructure(program_element->structure())));
      }
      if (program_element->diia_declaration()) {
        program_node->body.push_back(
            AAV(visitDiia_declaration(program_element->diia_declaration())));
      }
      if (program_element->diia()) {
        program_node->body.push_back(AAV(visitDiia(program_element->diia())));
      }
    }
    return AV(ast::KindProgramNode, program_node);
  }
} // namespace tsil::parser