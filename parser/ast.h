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
  struct UnaryNode;
  struct WhileNode;
  struct BlockNode;

  enum BinaryOp {
    ARITHMETIC_ADD,
    ARITHMETIC_SUB,
    ARITHMETIC_MUL,
    ARITHMETIC_DIV,
    ARITHMETIC_MOD,
    ARITHMETIC_DIVDIV,
    ARITHMETIC_POW,
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
    COMPARISON_CONTAINS,
    COMPARISON_NOT_CONTAINS,
    COMPARISON_IS,
    COMPARISON_NOT_IS,
    UTIL_AS,
  };

  enum LogicalOp {
    TEST_OR,
    TEST_AND,
  };

  enum UnaryOp {
    UNARY_POSITIVE,
    UNARY_NEGATIVE,
    UNARY_NOT,
    UNARY_BITWISE_NOT,
  };

  enum ASTValueKind {
    KindNone,
    KindAssignNode,
    KindBinaryNode,
    KindBreakNode,
    KindCallNode,
    KindDefineNode,
    KindGetNode,
    KindGetPointerNode,
    KindSetNode,
    KindComparisonNode,
    KindContinueNode,
    KindDiiaHeadNode,
    KindDiiaNode,
    KindDiiaDeclarationNode,
    KindIdentifierNode,
    KindIfNode,
    KindNumberNode,
    KindParamNode,
    KindProgramNode,
    KindReturnNode,
    KindStringNode,
    KindStructureNode,
    KindLogicalNode,
    KindTypeNode,
    KindUnaryNode,
    KindWhileNode,
    KindBlockNode,
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
    tsil::ast::UnaryNode* UnaryNode;
    tsil::ast::WhileNode* WhileNode;
    tsil::ast::BlockNode* BlockNode;
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
    ASTValue* value;
  };

  struct ComparisonNode {
    BinaryOp op;
    ASTValue* left;
    ASTValue* right;
  };

  struct ContinueNode {};

  struct DiiaHeadNode {
    bool is_extern;
    ASTValue* type;
    std::string id;
    std::vector<ASTValue*> params;
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
    std::string id;
    std::vector<ASTValue*> generics;
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
} // namespace tsil::ast
#endif // TSIL_AST_H
