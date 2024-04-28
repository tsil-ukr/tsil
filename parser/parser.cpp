#include "parser.h"

namespace tsil::ast {
  std::string ast_value_kind_to_string(ast::ASTValueKind kind) {
    {
      switch (kind) {
        case ast::KindNone:
          return "None";
        case ast::KindAssignNode:
          return "AssignNode";
        case ast::KindBinaryNode:
          return "BinaryNode";
        case ast::KindBreakNode:
          return "BreakNode";
        case ast::KindCallNode:
          return "CallNode";
        case ast::KindDefineNode:
          return "DefineNode";
        case ast::KindGetNode:
          return "GetNode";
        case ast::KindSetNode:
          return "SetNode";
        case ast::KindComparisonNode:
          return "ComparisonNode";
        case ast::KindContinueNode:
          return "ContinueNode";
        case ast::KindDiiaHeadNode:
          return "DiiaHeadNode";
        case ast::KindDiiaNode:
          return "DiiaNode";
        case ast::KindDiiaDeclarationNode:
          return "DiiaDeclarationNode";
        case ast::KindIdentifierNode:
          return "IdentifierNode";
        case ast::KindIfNode:
          return "IfNode";
        case ast::KindNumberNode:
          return "NumberNode";
        case ast::KindParamNode:
          return "ParamNode";
        case ast::KindProgramNode:
          return "ProgramNode";
        case ast::KindReturnNode:
          return "ReturnNode";
        case ast::KindStringNode:
          return "StringNode";
        case ast::KindStructureNode:
          return "StructureNode";
        case ast::KindLogicalNode:
          return "LogicalNode";
        case ast::KindTypeNode:
          return "TypeNode";
        case ast::KindUnaryNode:
          return "UnaryNode";
        case ast::KindWhileNode:
          return "WhileNode";
        case ast::KindBlockNode:
          return "BlockNode";
        case ast::KindGetPointerNode:
          return "GetPointerNode";
        case ast::KindConstructorNode:
          return "ConstructorNode";
        case ast::KindConstructorArgNode:
          return "ConstructorArgNode";
        case ast::KindSizeofNode:
          return "SizeofNode";
        case ast::KindAsNode:
          return "AsNode";
        case ast::KindFunctionTypeNode:
          return "FunctionTypeNode";
        case ast::KindIncludeNode:
          return "IncludeNode";
        case ast::KindAccessNode:
          return "AccessNode";
        case ast::KindArrayTypeNode:
          return "ArrayTypeNode";
        case ast::KindTakeNode:
          return "TakeNode";
        case ast::KindSectionAccessNode:
          return "SectionAccessNode";
        case ast::KindSectionNode:
          return "SectionNode";
        case ast::KindGenericNode:
          return "GenericNode";
      }
      return "Unknown";
    }
  }
} // namespace tsil::ast

namespace tsil::parser {
  void FILL(ast::ASTValue* ast_value, antlr4::ParserRuleContext* context) {
    ast_value->start_line = context->getStart()->getLine();
    ast_value->start_column = context->getStart()->getCharPositionInLine();
    ast_value->end_line = context->getStop()->getLine();
    ast_value->end_column = context->getStop()->getCharPositionInLine();
  }

  void FILL(ast::ASTValue* ast_value, antlr4::Token* token) {
    ast_value->start_line = token->getLine();
    ast_value->start_column = token->getCharPositionInLine();
    ast_value->end_line = token->getLine();
    ast_value->end_column = token->getCharPositionInLine();
  }

  ast::ASTValue* AV(ast::ASTValueKind kind, void* data) {
    const auto ast_value = new ast::ASTValue();
    ast_value->kind = kind;
    ast_value->data.ref = data;
    return ast_value;
  }

  ast::ASTValue* AV(antlr4::ParserRuleContext* context,
                    ast::ASTValueKind kind,
                    void* data) {
    const auto ast_value = new ast::ASTValue();
    FILL(ast_value, context);
    ast_value->kind = kind;
    ast_value->data.ref = data;
    return ast_value;
  }

  ast::ASTValue* AV(antlr4::Token* token, ast::ASTValueKind kind, void* data) {
    const auto ast_value = new ast::ASTValue();
    FILL(ast_value, token);
    ast_value->kind = kind;
    ast_value->data.ref = data;
    return ast_value;
  }

  std::any TsilASTVisitor::visitContext(antlr4::ParserRuleContext* context) {
    if (const auto file_context =
            dynamic_cast<TsilParser::FileContext*>(context)) {
      return visitFile(file_context);
    }
    if (const auto program_context =
            dynamic_cast<TsilParser::ProgramContext*>(context)) {
      return visitProgram(program_context);
    }
    if (const auto section_context =
            dynamic_cast<TsilParser::SectionContext*>(context)) {
      return visitSection(section_context);
    }
    if (const auto structure_context =
            dynamic_cast<TsilParser::StructureContext*>(context)) {
      return visitStructure(structure_context);
    }
    if (const auto diia_context =
            dynamic_cast<TsilParser::DiiaContext*>(context)) {
      return visitDiia(diia_context);
    }
    if (const auto diia_declaration_context =
            dynamic_cast<TsilParser::Diia_declarationContext*>(context)) {
      return visitDiia_declaration(diia_declaration_context);
    }
    if (const auto body_context =
            dynamic_cast<TsilParser::BodyContext*>(context)) {
      return visitBody(body_context);
    }
    if (const auto if_context = dynamic_cast<TsilParser::IfContext*>(context)) {
      return visitIf(if_context);
    }
    if (const auto while_context =
            dynamic_cast<TsilParser::WhileContext*>(context)) {
      return visitWhile(while_context);
    }
    if (const auto declare_context =
            dynamic_cast<TsilParser::DeclareContext*>(context)) {
      return visitDeclare(declare_context);
    }
    if (const auto define_context =
            dynamic_cast<TsilParser::DefineContext*>(context)) {
      return visitDefine(define_context);
    }
    if (const auto assign_context =
            dynamic_cast<TsilParser::AssignContext*>(context)) {
      return visitAssign(assign_context);
    }
    if (const auto set_context =
            dynamic_cast<TsilParser::SetContext*>(context)) {
      return visitSet(set_context);
    }
    if (const auto identifier_context =
            dynamic_cast<TsilParser::IdentifierContext*>(context)) {
      return visitIdentifier(identifier_context);
    }
    if (const auto get_context =
            dynamic_cast<TsilParser::GetContext*>(context)) {
      return visitGet(get_context);
    }
    if (const auto access_context =
            dynamic_cast<TsilParser::AccessContext*>(context)) {
      return visitAccess(access_context);
    }
    if (const auto call_context =
            dynamic_cast<TsilParser::CallContext*>(context)) {
      return visitCall(call_context);
    }
    if (const auto nested_context =
            dynamic_cast<TsilParser::NestedContext*>(context)) {
      return visitNested(nested_context);
    }
    if (const auto atom_particle_context =
            dynamic_cast<TsilParser::Atom_particleContext*>(context)) {
      return visitContext(atom_particle_context->particle());
    }
    if (const auto number_context =
            dynamic_cast<TsilParser::NumberContext*>(context)) {
      return visitNumber(number_context);
    }
    if (const auto string_context =
            dynamic_cast<TsilParser::StringContext*>(context)) {
      return visitString(string_context);
    }
    if (const auto molecule_atom_context =
            dynamic_cast<TsilParser::Molecule_atomContext*>(context)) {
      return visitContext(molecule_atom_context->atom());
    }
    if (const auto not_context =
            dynamic_cast<TsilParser::NotContext*>(context)) {
      return visitNot(not_context);
    }
    if (const auto positive_context =
            dynamic_cast<TsilParser::PositiveContext*>(context)) {
      return visitPositive(positive_context);
    }
    if (const auto negative_context =
            dynamic_cast<TsilParser::NegativeContext*>(context)) {
      return visitNegative(negative_context);
    }
    if (const auto bitwise_not_context =
            dynamic_cast<TsilParser::Bitwise_notContext*>(context)) {
      return visitBitwise_not(bitwise_not_context);
    }
    if (const auto operation_molecule_context =
            dynamic_cast<TsilParser::Operation_moleculeContext*>(context)) {
      return visitContext(operation_molecule_context->molecule());
    }
    if (const auto as_context = dynamic_cast<TsilParser::AsContext*>(context)) {
      return visitAs(as_context);
    }
    if (const auto mul_context =
            dynamic_cast<TsilParser::MulContext*>(context)) {
      return visitMul(mul_context);
    }
    if (const auto add_context =
            dynamic_cast<TsilParser::AddContext*>(context)) {
      return visitAdd(add_context);
    }
    if (const auto bitwise_context =
            dynamic_cast<TsilParser::BitwiseContext*>(context)) {
      return visitBitwise(bitwise_context);
    }
    if (const auto comparison_context =
            dynamic_cast<TsilParser::ComparisonContext*>(context)) {
      return visitComparison(comparison_context);
    }
    if (const auto logical_context =
            dynamic_cast<TsilParser::LogicalContext*>(context)) {
      return visitLogical(logical_context);
    }
    if (const auto expr_operation_context =
            dynamic_cast<TsilParser::Expr_operationContext*>(context)) {
      return visitContext(expr_operation_context->operation());
    }
    if (const auto construct_context =
            dynamic_cast<TsilParser::ConstructContext*>(context)) {
      return visitConstruct(construct_context);
    }
    if (const auto simple_type_context =
            dynamic_cast<TsilParser::Simple_typeContext*>(context)) {
      return visitSimple_type(simple_type_context);
    }
    if (const auto array_type_context =
            dynamic_cast<TsilParser::Array_typeContext*>(context)) {
      return visitArray_type(array_type_context);
    }
    if (const auto full_type_basic_type_context =
            dynamic_cast<TsilParser::Full_type_basic_typeContext*>(context)) {
      return visitContext(full_type_basic_type_context->basic_type());
    }
    if (const auto complex_function_type_context =
            dynamic_cast<TsilParser::Complex_function_typeContext*>(context)) {
      return visitComplex_function_type(complex_function_type_context);
    }
    if (const auto simple_function_type_context =
            dynamic_cast<TsilParser::Simple_function_typeContext*>(context)) {
      return visitSimple_function_type(simple_function_type_context);
    }
    if (const auto take_context =
            dynamic_cast<TsilParser::TakeContext*>(context)) {
      return visitTake(take_context);
    }
    if (const auto real_section_access_context =
            dynamic_cast<TsilParser::Real_section_accessContext*>(context)) {
      return visitReal_section_access(real_section_access_context);
    }
    if (const auto particle_section_access_context =
            dynamic_cast<TsilParser::Particle_section_accessContext*>(
                context)) {
      return visitContext(particle_section_access_context->section_access());
    }
    if (const auto generic_context =
            dynamic_cast<TsilParser::GenericContext*>(context)) {
      return visitGeneric(generic_context);
    }
    return nullptr;
  }

  void TsilParserErrorListener::syntaxError(antlr4::Recognizer* recognizer,
                                            antlr4::Token* offendingSymbol,
                                            size_t line,
                                            size_t charPositionInLine,
                                            const std::string& msg,
                                            std::exception_ptr e) {
    TsilParserError error{};
    error.line = line;
    error.column = charPositionInLine;
    error.message = msg;
    this->errors.push_back(error);
  }

  void TsilParserErrorListener::reportAmbiguity(
      antlr4::Parser* recognizer,
      const antlr4::dfa::DFA& dfa,
      size_t startIndex,
      size_t stopIndex,
      bool exact,
      const antlrcpp::BitSet& ambigAlts,
      antlr4::atn::ATNConfigSet* configs) {}

  void TsilParserErrorListener::reportAttemptingFullContext(
      antlr4::Parser* recognizer,
      const antlr4::dfa::DFA& dfa,
      size_t startIndex,
      size_t stopIndex,
      const antlrcpp::BitSet& conflictingAlts,
      antlr4::atn::ATNConfigSet* configs) {}

  void TsilParserErrorListener::reportContextSensitivity(
      antlr4::Parser* recognizer,
      const antlr4::dfa::DFA& dfa,
      size_t startIndex,
      size_t stopIndex,
      size_t prediction,
      antlr4::atn::ATNConfigSet* configs) {}

  TsilParserResult parse(const std::string& code) {
    antlr4::ANTLRInputStream input(code);

    const auto lexer_error_listener = new TsilParserErrorListener();
    TsilLexer lexer(&input);
    lexer.removeErrorListeners();
    lexer.addErrorListener(lexer_error_listener);

    antlr4::CommonTokenStream tokens(&lexer);

    if (!lexer_error_listener->errors.empty()) {
      return TsilParserResult{
          .errors = lexer_error_listener->errors,
      };
    }

    const auto parser_error_listener = new TsilParserErrorListener();
    TsilParser parser(&tokens);
    parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(
        antlr4::atn::PredictionMode::SLL);
    parser.removeParseListeners();
    parser.removeErrorListeners();
    parser.addErrorListener(parser_error_listener);

    TsilParser::FileContext* tree = parser.file();

    if (!parser_error_listener->errors.empty()) {
      return TsilParserResult{
          .errors = parser_error_listener->errors,
      };
    }

    const auto visitor = new TsilASTVisitor();
    visitor->tokens = &tokens;

    const auto ast_value = AAV(visitor->visitFile(tree));

    auto parser_result = TsilParserResult();
    parser_result.program_node = ast_value->data.ProgramNode;

    return parser_result;
  }
} // namespace tsil::parser
