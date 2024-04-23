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

  void processASTBody(std::vector<ast::ASTValue*>& body) {
    for (const auto& item : body) {
      if (item == nullptr) {
        std::erase(body, item);
      }
      if (item->kind == ast::KindIdentifierNode) {
        if (item->data.IdentifierNode->name == "перервати") {
          item->kind = ast::KindBreakNode;
          item->data.BreakNode = new ast::BreakNode();
          continue;
        }
        if (item->data.IdentifierNode->name == "продовжити") {
          item->kind = ast::KindContinueNode;
          item->data.ContinueNode = new ast::ContinueNode();
          continue;
        }
      }
    }
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
    if (const auto program_element_context =
            dynamic_cast<TsilParser::Program_elementContext*>(context)) {
      return visitProgram_element(program_element_context);
    }
    if (const auto structure_context =
            dynamic_cast<TsilParser::StructureContext*>(context)) {
      return visitStructure(structure_context);
    }
    if (const auto structure_params_context =
            dynamic_cast<TsilParser::Structure_paramsContext*>(context)) {
      return visitStructure_params(structure_params_context);
    }
    if (const auto structure_element_context =
            dynamic_cast<TsilParser::Structure_paramContext*>(context)) {
      return visitStructure_param(structure_element_context);
    }
    if (const auto diia_context =
            dynamic_cast<TsilParser::DiiaContext*>(context)) {
      return visitDiia(diia_context);
    }
    if (const auto diia_declaration_context =
            dynamic_cast<TsilParser::Diia_declarationContext*>(context)) {
      return visitDiia_declaration(diia_declaration_context);
    }
    if (const auto if_context = dynamic_cast<TsilParser::IfContext*>(context)) {
      return visitIf(if_context);
    }
    if (const auto while_context =
            dynamic_cast<TsilParser::WhileContext*>(context)) {
      return visitWhile(while_context);
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
    if (const auto number_context =
            dynamic_cast<TsilParser::NumberContext*>(context)) {
      return visitNumber(number_context);
    }
    if (const auto atom_number_context =
            dynamic_cast<TsilParser::Atom_numberContext*>(context)) {
      return visitAtom_number(atom_number_context);
    }
    if (const auto string_context =
            dynamic_cast<TsilParser::StringContext*>(context)) {
      return visitString(string_context);
    }
    if (const auto atom_string_context =
            dynamic_cast<TsilParser::Atom_stringContext*>(context)) {
      return visitAtom_string(atom_string_context);
    }
    if (const auto identifier_context =
            dynamic_cast<TsilParser::IdentifierContext*>(context)) {
      return visitIdentifier(identifier_context);
    }
    if (const auto atom_identifier_context =
            dynamic_cast<TsilParser::Atom_identifierContext*>(context)) {
      return visitAtom_identifier(atom_identifier_context);
    }
    if (const auto get_context =
            dynamic_cast<TsilParser::GetContext*>(context)) {
      return visitGet(get_context);
    }
    if (const auto call_context =
            dynamic_cast<TsilParser::CallContext*>(context)) {
      return visitCall(call_context);
    }
    if (const auto positive_context =
            dynamic_cast<TsilParser::PositiveContext*>(context)) {
      return visitPositive(positive_context);
    }
    if (const auto negative_context =
            dynamic_cast<TsilParser::NegativeContext*>(context)) {
      return visitNegative(negative_context);
    }
    if (const auto not_context =
            dynamic_cast<TsilParser::NotContext*>(context)) {
      return visitNot(not_context);
    }
    if (const auto bitwise_not_context =
            dynamic_cast<TsilParser::Bitwise_notContext*>(context)) {
      return visitBitwise_not(bitwise_not_context);
    }
    if (const auto nested_context =
            dynamic_cast<TsilParser::NestedContext*>(context)) {
      return visitNested(nested_context);
    }
    if (const auto value_atom_context =
            dynamic_cast<TsilParser::Value_atomContext*>(context)) {
      return visitValue_atom(value_atom_context);
    }
    if (const auto arithmetic_mul_context =
            dynamic_cast<TsilParser::Arithmetic_mulContext*>(context)) {
      return visitArithmetic_mul(arithmetic_mul_context);
    }
    if (const auto arithmetic_add_context =
            dynamic_cast<TsilParser::Arithmetic_addContext*>(context)) {
      return visitArithmetic_add(arithmetic_add_context);
    }
    if (const auto bitwise_context =
            dynamic_cast<TsilParser::BitwiseContext*>(context)) {
      return visitBitwise(bitwise_context);
    }
    if (const auto bitwise_op_context =
            dynamic_cast<TsilParser::Bitwise_opContext*>(context)) {
      return visitBitwise_op(bitwise_op_context);
    }
    if (const auto comparison_context =
            dynamic_cast<TsilParser::ComparisonContext*>(context)) {
      return visitComparison(comparison_context);
    }
    if (const auto comparison_op_context =
            dynamic_cast<TsilParser::Comparison_opContext*>(context)) {
      return visitComparison_op(comparison_op_context);
    }
    if (const auto logical_context =
            dynamic_cast<TsilParser::LogicalContext*>(context)) {
      return visitLogical(logical_context);
    }
    if (const auto logical_op_context =
            dynamic_cast<TsilParser::Logical_opContext*>(context)) {
      return visitLogical_op(logical_op_context);
    }
    if (const auto identifiers_chain_context =
            dynamic_cast<TsilParser::Identifiers_chainContext*>(context)) {
      return visitIdentifiers_chain(identifiers_chain_context);
    }
    if (const auto type_context =
            dynamic_cast<TsilParser::TypeContext*>(context)) {
      return visitType(type_context);
    }
    if (const auto full_type_context =
            dynamic_cast<TsilParser::Full_typeContext*>(context)) {
      return visitFullType(full_type_context);
    }
    if (const auto args_context =
            dynamic_cast<TsilParser::ArgsContext*>(context)) {
      return visitArgs(args_context);
    }
    if (const auto params_context =
            dynamic_cast<TsilParser::ParamsContext*>(context)) {
      return visitParams(params_context);
    }
    if (const auto param_context =
            dynamic_cast<TsilParser::ParamContext*>(context)) {
      return visitParam(param_context);
    }
    if (const auto body_context =
            dynamic_cast<TsilParser::BodyContext*>(context)) {
      return visitBody(body_context);
    }
    if (const auto body_element_or_return_context =
            dynamic_cast<TsilParser::Body_element_or_returnContext*>(context)) {
      return visitBody_element_or_return(body_element_or_return_context);
    }
    if (const auto body_element_context =
            dynamic_cast<TsilParser::Body_elementContext*>(context)) {
      return visitBody_element(body_element_context);
    }
    if (const auto return_body_element_context =
            dynamic_cast<TsilParser::Return_body_elementContext*>(context)) {
      return visitReturn_body_element(return_body_element_context);
    }
    if (const auto constructor_context =
            dynamic_cast<TsilParser::ConstructorContext*>(context)) {
      return visitConstructor(constructor_context);
    }
    if (const auto constructor_args_context =
            dynamic_cast<TsilParser::Constructor_argsContext*>(context)) {
      return visitConstructor_args(constructor_args_context);
    }
    if (const auto constructor_arg_context =
            dynamic_cast<TsilParser::Constructor_argContext*>(context)) {
      return visitConstructor_arg(constructor_arg_context);
    }
    if (const auto atom_constructor_context =
            dynamic_cast<TsilParser::Atom_constructorContext*>(context)) {
      return visitAtom_constructor(atom_constructor_context);
    }
    if (const auto sizeof_context =
            dynamic_cast<TsilParser::SizeofContext*>(context)) {
      return visitSizeof(sizeof_context);
    }
    if (const auto atom_sizeof_context =
            dynamic_cast<TsilParser::Atom_sizeofContext*>(context)) {
      return visitAtom_sizeof(atom_sizeof_context);
    }
    if (const auto as_context = dynamic_cast<TsilParser::AsContext*>(context)) {
      return visitAs(as_context);
    }
    if (const auto expr_molecule_context =
            dynamic_cast<TsilParser::Expr_moleculeContext*>(context)) {
      return visitExpr_molecule(expr_molecule_context);
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
