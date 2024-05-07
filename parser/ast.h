#pragma once

#ifndef TSIL_AST_H
#define TSIL_AST_H

#include <map>
#include <string>
#include <vector>

namespace tsil::ast {
  struct ASTValue;
  struct ArgNode;
  struct AssignNode;
  struct BinaryNode;
  struct BreakNode;
  struct CallNode;
  struct DefineNode;
  struct GetNode;
  struct GetPointerNode;
  struct SetNode;
  struct ComparisonNode;
  struct ContinueNode;
  struct DiiaHeadNode;
  struct DiiaNode;
  struct DiiaDeclarationNode;
  struct IdentifierNode;
  struct IfNode;
  struct NumberNode;
  struct ParamNode;
  struct ProgramNode;
  struct ReturnNode;
  struct StringNode;
  struct StructureNode;
  struct LogicalNode;
  struct TypeNode;
  struct FunctionTypeNode;
  struct ArrayTypeNode;
  struct UnaryNode;
  struct WhileNode;
  struct BlockNode;
  struct ConstructorNode;
  struct ConstructorArgNode;
  struct SizeofNode;
  struct AsNode;
  struct IncludeNode;
  struct AccessNode;
  struct TakeNode;
  struct SectionAccessNode;
  struct SectionNode;
  struct GenericNode;
  struct SynonymNode;

  enum BinaryOp : u_int32_t {
    ARITHMETIC_ADD,
    ARITHMETIC_SUB,
    ARITHMETIC_MUL,
    ARITHMETIC_DIV,
    ARITHMETIC_MOD,
    BITWISE_AND,
    BITWISE_OR,
    BITWISE_XOR,
    BITWISE_SHIFT_LEFT,
    BITWISE_SHIFT_RIGHT,
    COMPARISON_EQ,
    COMPARISON_NE,
    COMPARISON_LT,
    COMPARISON_GT,
    COMPARISON_LE,
    COMPARISON_GE,
  };

  enum LogicalOp : u_int32_t {
    TEST_OR,
    TEST_AND,
  };

  enum UnaryOp : u_int32_t {
    UNARY_POSITIVE,
    UNARY_NEGATIVE,
    UNARY_NOT,
    UNARY_BITWISE_NOT,
  };

  enum ASTValueKind : u_int32_t {
    KindNone = 0,
    KindAssignNode = 1,
    KindBinaryNode = 2,
    KindBreakNode = 3,
    KindCallNode = 4,
    KindDefineNode = 5,
    KindGetNode = 6,
    KindGetPointerNode = 7,
    KindSetNode = 8,
    KindComparisonNode = 9,
    KindContinueNode = 10,
    KindDiiaHeadNode = 11,
    KindDiiaNode = 12,
    KindDiiaDeclarationNode = 13,
    KindIdentifierNode = 14,
    KindIfNode = 15,
    KindNumberNode = 16,
    KindParamNode = 17,
    KindProgramNode = 18,
    KindReturnNode = 19,
    KindStringNode = 20,
    KindStructureNode = 21,
    KindLogicalNode = 22,
    KindTypeNode = 23,
    KindFunctionTypeNode = 24,
    KindArrayTypeNode = 25,
    KindUnaryNode = 26,
    KindWhileNode = 27,
    KindBlockNode = 28,
    KindConstructorNode = 29,
    KindConstructorArgNode = 30,
    KindSizeofNode = 31,
    KindAsNode = 32,
    KindIncludeNode = 33,
    KindAccessNode = 34,
    KindTakeNode = 35,
    KindSectionAccessNode = 36,
    KindSectionNode = 37,
    KindGenericNode = 38,
    KindSynonymNode = 39,
  };

  std::string ast_value_kind_to_string(ASTValueKind kind);

  union ASTValueData {
    void* ref;
    tsil::ast::ArgNode* ArgNode;
    tsil::ast::AssignNode* AssignNode;
    tsil::ast::BinaryNode* BinaryNode;
    tsil::ast::BreakNode* BreakNode;
    tsil::ast::CallNode* CallNode;
    tsil::ast::DefineNode* DefineNode;
    tsil::ast::GetNode* GetNode;
    tsil::ast::GetPointerNode* GetPointerNode;
    tsil::ast::SetNode* SetNode;
    tsil::ast::ComparisonNode* ComparisonNode;
    tsil::ast::ContinueNode* ContinueNode;
    tsil::ast::DiiaHeadNode* DiiaHeadNode;
    tsil::ast::DiiaNode* DiiaNode;
    tsil::ast::DiiaDeclarationNode* DiiaDeclarationNode;
    tsil::ast::IdentifierNode* IdentifierNode;
    tsil::ast::IfNode* IfNode;
    tsil::ast::NumberNode* NumberNode;
    tsil::ast::ParamNode* ParamNode;
    tsil::ast::ProgramNode* ProgramNode;
    tsil::ast::ReturnNode* ReturnNode;
    tsil::ast::StringNode* StringNode;
    tsil::ast::StructureNode* StructureNode;
    tsil::ast::LogicalNode* LogicalNode;
    tsil::ast::TypeNode* TypeNode;
    tsil::ast::FunctionTypeNode* FunctionTypeNode;
    tsil::ast::ArrayTypeNode* ArrayTypeNode;
    tsil::ast::UnaryNode* UnaryNode;
    tsil::ast::WhileNode* WhileNode;
    tsil::ast::BlockNode* BlockNode;
    tsil::ast::ConstructorNode* ConstructorNode;
    tsil::ast::ConstructorArgNode* ConstructorArgNode;
    tsil::ast::SizeofNode* SizeofNode;
    tsil::ast::AsNode* AsNode;
    tsil::ast::IncludeNode* IncludeNode;
    tsil::ast::AccessNode* AccessNode;
    tsil::ast::TakeNode* TakeNode;
    tsil::ast::SectionAccessNode* SectionAccessNode;
    tsil::ast::SectionNode* SectionNode;
    tsil::ast::ASTValue* ASTValue;
    tsil::ast::GenericNode* GenericNode;
    tsil::ast::SynonymNode* SynonymNode;
  };

  struct ASTValue {
    ASTValueKind kind = KindNone;
    ASTValueData data = {.ref = nullptr};
    size_t start_line = 0;
    size_t start_column = 0;
    size_t end_line = 0;
    size_t end_column = 0;
  };

  struct AssignNode {
    std::string id;
    ASTValue* value;
  };

  struct BinaryNode {
    BinaryOp op;
    ASTValue* left;
    ASTValue* right;
  };

  struct BreakNode {};

  struct CallNode {
    ASTValue* value;
    std::vector<ASTValue*> args;
  };

  struct DefineNode {
    ASTValue* type;
    std::string id;
    ASTValue* value;
  };

  struct GetNode {
    ASTValue* left;
    std::string id;
  };

  struct GetPointerNode {
    ASTValue* value;
  };

  struct SetNode {
    ASTValue* left;
    std::string id;
    ASTValue* access;
    ASTValue* value;
  };

  struct ComparisonNode {
    BinaryOp op;
    ASTValue* left;
    ASTValue* right;
  };

  struct ContinueNode {};

  enum DiiaLinkage : u_int32_t {
    DiiaLinkageExtern,
    DiiaLinkageLocal,
    DiiaLinkageStatic,
  };

  struct DiiaHeadNode {
    ast::DiiaLinkage linkage;
    std::string id;
    std::vector<std::string> generic_definitions;
    std::vector<ASTValue*> params;
    ASTValue* type;
    bool is_variadic;
  };

  struct DiiaNode {
    DiiaHeadNode* head;
    std::vector<ASTValue*> body;
  };

  struct DiiaDeclarationNode {
    DiiaHeadNode* head;
    std::string as;
  };

  struct IdentifierNode {
    std::string name;
  };

  struct IfNode {
    ASTValue* condition;
    std::vector<ASTValue*> body;
    std::vector<ASTValue*> else_body;
  };

  struct NumberNode {
    std::string value;
  };

  struct ParamNode {
    ASTValue* type;
    std::string id;
  };

  struct ProgramNode {
    std::vector<ASTValue*> body;
  };

  struct ReturnNode {
    ASTValue* value;
  };

  struct StringNode {
    std::string prefix;
    std::string value;
  };

  struct StructureNode {
    std::string name;
    std::vector<std::string> generic_definitions;
    std::vector<ASTValue*> params;
  };

  struct LogicalNode {
    LogicalOp op;
    ASTValue* left;
    ASTValue* right;
  };

  struct TypeNode {
    ASTValue* id;
    std::vector<ASTValue*> generics;
  };

  struct FunctionTypeNode {
    std::vector<ASTValue*> args;
    ASTValue* return_type;
  };

  struct ArrayTypeNode {
    ASTValue* type;
    ASTValue* size;
  };

  struct UnaryNode {
    UnaryOp op;
    ASTValue* value;
  };

  struct WhileNode {
    ASTValue* condition;
    std::vector<ASTValue*> body;
  };

  struct BlockNode {
    std::vector<ASTValue*> body;
  };

  struct ConstructorNode {
    ASTValue* type;
    std::vector<ASTValue*> args;
  };

  struct ConstructorArgNode {
    std::string id;
    ASTValue* value;
  };

  struct SizeofNode {
    ASTValue* value;
  };

  struct AsNode {
    ASTValue* value;
    ASTValue* type;
  };

  struct IncludeNode {
    std::string path;
  };

  struct AccessNode {
    ASTValue* value;
    ASTValue* index;
  };

  struct TakeNode {
    std::string repo;
    std::string path;
    bool parts_relative;
    std::vector<std::string> parts;
  };

  struct SectionAccessNode {
    std::vector<ast::ASTValue*> parts;
  };

  struct SectionNode {
    std::string id;
    std::vector<ASTValue*> body;
  };

  struct GenericNode {
    ASTValue* left;
    std::vector<ASTValue*> values;
  };

  struct SynonymNode {
    std::string id;
    ASTValue* value;
  };
} // namespace tsil::ast
#endif // TSIL_AST_H
