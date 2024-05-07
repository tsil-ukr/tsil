
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

    virtual std::any visitIdentifier(TsilParser::IdentifierContext *context) = 0;

    virtual std::any visitReal_section_access(TsilParser::Real_section_accessContext *context) = 0;

    virtual std::any visitNumber(TsilParser::NumberContext *context) = 0;

    virtual std::any visitString(TsilParser::StringContext *context) = 0;

    virtual std::any visitTake(TsilParser::TakeContext *context) = 0;

    virtual std::any visitTake_parts(TsilParser::Take_partsContext *context) = 0;

    virtual std::any visitSynonym(TsilParser::SynonymContext *context) = 0;

    virtual std::any visitSynonym_value(TsilParser::Synonym_valueContext *context) = 0;

    virtual std::any visitSection(TsilParser::SectionContext *context) = 0;

    virtual std::any visitSection_element(TsilParser::Section_elementContext *context) = 0;

    virtual std::any visitStructure(TsilParser::StructureContext *context) = 0;

    virtual std::any visitStructure_generics(TsilParser::Structure_genericsContext *context) = 0;

    virtual std::any visitStructure_generic(TsilParser::Structure_genericContext *context) = 0;

    virtual std::any visitStructure_params(TsilParser::Structure_paramsContext *context) = 0;

    virtual std::any visitStructure_param(TsilParser::Structure_paramContext *context) = 0;

    virtual std::any visitDiia_head(TsilParser::Diia_headContext *context) = 0;

    virtual std::any visitDiia(TsilParser::DiiaContext *context) = 0;

    virtual std::any visitDiia_generics(TsilParser::Diia_genericsContext *context) = 0;

    virtual std::any visitDiia_generic(TsilParser::Diia_genericContext *context) = 0;

    virtual std::any visitDiia_declaration(TsilParser::Diia_declarationContext *context) = 0;

    virtual std::any visitParams(TsilParser::ParamsContext *context) = 0;

    virtual std::any visitParam(TsilParser::ParamContext *context) = 0;

    virtual std::any visitBody(TsilParser::BodyContext *context) = 0;

    virtual std::any visitBody_element(TsilParser::Body_elementContext *context) = 0;

    virtual std::any visitReturn_body_element(TsilParser::Return_body_elementContext *context) = 0;

    virtual std::any visitBlock(TsilParser::BlockContext *context) = 0;

    virtual std::any visitIf(TsilParser::IfContext *context) = 0;

    virtual std::any visitWhile(TsilParser::WhileContext *context) = 0;

    virtual std::any visitDeclare(TsilParser::DeclareContext *context) = 0;

    virtual std::any visitDefine(TsilParser::DefineContext *context) = 0;

    virtual std::any visitAssign(TsilParser::AssignContext *context) = 0;

    virtual std::any visitSet(TsilParser::SetContext *context) = 0;

    virtual std::any visitCall(TsilParser::CallContext *context) = 0;

    virtual std::any visitAccess(TsilParser::AccessContext *context) = 0;

    virtual std::any visitGet(TsilParser::GetContext *context) = 0;

    virtual std::any visitParticle_section_access(TsilParser::Particle_section_accessContext *context) = 0;

    virtual std::any visitNested(TsilParser::NestedContext *context) = 0;

    virtual std::any visitGeneric(TsilParser::GenericContext *context) = 0;

    virtual std::any visitArgs(TsilParser::ArgsContext *context) = 0;

    virtual std::any visitAtom_particle(TsilParser::Atom_particleContext *context) = 0;

    virtual std::any visitAtom_number(TsilParser::Atom_numberContext *context) = 0;

    virtual std::any visitAtom_string(TsilParser::Atom_stringContext *context) = 0;

    virtual std::any visitMolecule_atom(TsilParser::Molecule_atomContext *context) = 0;

    virtual std::any visitNot(TsilParser::NotContext *context) = 0;

    virtual std::any visitPositive(TsilParser::PositiveContext *context) = 0;

    virtual std::any visitNegative(TsilParser::NegativeContext *context) = 0;

    virtual std::any visitBitwise_not(TsilParser::Bitwise_notContext *context) = 0;

    virtual std::any visitAdd(TsilParser::AddContext *context) = 0;

    virtual std::any visitAs(TsilParser::AsContext *context) = 0;

    virtual std::any visitComparison(TsilParser::ComparisonContext *context) = 0;

    virtual std::any visitMul(TsilParser::MulContext *context) = 0;

    virtual std::any visitBitwise(TsilParser::BitwiseContext *context) = 0;

    virtual std::any visitOperation_molecule(TsilParser::Operation_moleculeContext *context) = 0;

    virtual std::any visitLogical(TsilParser::LogicalContext *context) = 0;

    virtual std::any visitConstruct(TsilParser::ConstructContext *context) = 0;

    virtual std::any visitExpr_operation(TsilParser::Expr_operationContext *context) = 0;

    virtual std::any visitConstruct_args(TsilParser::Construct_argsContext *context) = 0;

    virtual std::any visitConstruct_arg(TsilParser::Construct_argContext *context) = 0;

    virtual std::any visitSimple_type(TsilParser::Simple_typeContext *context) = 0;

    virtual std::any visitArray_type(TsilParser::Array_typeContext *context) = 0;

    virtual std::any visitSimple_function_type(TsilParser::Simple_function_typeContext *context) = 0;

    virtual std::any visitComplex_function_type(TsilParser::Complex_function_typeContext *context) = 0;

    virtual std::any visitFull_type_basic_type(TsilParser::Full_type_basic_typeContext *context) = 0;

    virtual std::any visitComplex_function_type_args(TsilParser::Complex_function_type_argsContext *context) = 0;

    virtual std::any visitBitwise_op(TsilParser::Bitwise_opContext *context) = 0;

    virtual std::any visitComparison_op(TsilParser::Comparison_opContext *context) = 0;

    virtual std::any visitLogical_op(TsilParser::Logical_opContext *context) = 0;


};

