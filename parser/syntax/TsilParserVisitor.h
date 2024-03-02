
// Generated from TsilParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "TsilParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by TsilParser.
 */
class  TsilParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by TsilParser.
   */
    virtual std::any visitFile(TsilParser::FileContext *context) = 0;

    virtual std::any visitProgram(TsilParser::ProgramContext *context) = 0;

    virtual std::any visitProgram_element(TsilParser::Program_elementContext *context) = 0;

    virtual std::any visitStructure(TsilParser::StructureContext *context) = 0;

    virtual std::any visitStructure_params(TsilParser::Structure_paramsContext *context) = 0;

    virtual std::any visitStructure_param(TsilParser::Structure_paramContext *context) = 0;

    virtual std::any visitDiia(TsilParser::DiiaContext *context) = 0;

    virtual std::any visitIf(TsilParser::IfContext *context) = 0;

    virtual std::any visitWhile(TsilParser::WhileContext *context) = 0;

    virtual std::any visitDefine(TsilParser::DefineContext *context) = 0;

    virtual std::any visitAssign(TsilParser::AssignContext *context) = 0;

    virtual std::any visitSet(TsilParser::SetContext *context) = 0;

    virtual std::any visitCall(TsilParser::CallContext *context) = 0;

    virtual std::any visitNegative(TsilParser::NegativeContext *context) = 0;

    virtual std::any visitNot(TsilParser::NotContext *context) = 0;

    virtual std::any visitAtom_number(TsilParser::Atom_numberContext *context) = 0;

    virtual std::any visitBitwise_not(TsilParser::Bitwise_notContext *context) = 0;

    virtual std::any visitGet(TsilParser::GetContext *context) = 0;

    virtual std::any visitAtom_identifier(TsilParser::Atom_identifierContext *context) = 0;

    virtual std::any visitPositive(TsilParser::PositiveContext *context) = 0;

    virtual std::any visitNested(TsilParser::NestedContext *context) = 0;

    virtual std::any visitAtom_string(TsilParser::Atom_stringContext *context) = 0;

    virtual std::any visitArithmetic_mul(TsilParser::Arithmetic_mulContext *context) = 0;

    virtual std::any visitArithmetic_add(TsilParser::Arithmetic_addContext *context) = 0;

    virtual std::any visitComparison(TsilParser::ComparisonContext *context) = 0;

    virtual std::any visitBitwise(TsilParser::BitwiseContext *context) = 0;

    virtual std::any visitValue_atom(TsilParser::Value_atomContext *context) = 0;

    virtual std::any visitLogical(TsilParser::LogicalContext *context) = 0;

    virtual std::any visitIdentifiers_chain(TsilParser::Identifiers_chainContext *context) = 0;

    virtual std::any visitType(TsilParser::TypeContext *context) = 0;

    virtual std::any visitArgs(TsilParser::ArgsContext *context) = 0;

    virtual std::any visitParams(TsilParser::ParamsContext *context) = 0;

    virtual std::any visitParam(TsilParser::ParamContext *context) = 0;

    virtual std::any visitBody(TsilParser::BodyContext *context) = 0;

    virtual std::any visitBody_element_or_return(TsilParser::Body_element_or_returnContext *context) = 0;

    virtual std::any visitBody_element(TsilParser::Body_elementContext *context) = 0;

    virtual std::any visitReturn_body_element(TsilParser::Return_body_elementContext *context) = 0;

    virtual std::any visitBitwise_op(TsilParser::Bitwise_opContext *context) = 0;

    virtual std::any visitComparison_op(TsilParser::Comparison_opContext *context) = 0;

    virtual std::any visitLogical_op(TsilParser::Logical_opContext *context) = 0;

    virtual std::any visitNumber(TsilParser::NumberContext *context) = 0;

    virtual std::any visitString(TsilParser::StringContext *context) = 0;

    virtual std::any visitIdentifier(TsilParser::IdentifierContext *context) = 0;


};

