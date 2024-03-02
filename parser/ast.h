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
  struct SetNode;
  struct ComparisonNode;
  struct ContinueNode;
  struct DiiaNode;
  struct IdentifierNode;
  struct IfNode;
  struct NumberNode;
  struct ParamNode;
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
    KindArgNode,
    KindAssignNode,
    KindBinaryNode,
    KindBreakNode,
    KindCallNode,
    KindDefineNode,
    KindGetNode,
    KindSetNode,
    KindComparisonNode,
    KindContinueNode,
    KindDiiaNode,
    KindIdentifierNode,
    KindIfNode,
    KindNumberNode,
    KindParamNode,
    KindReturnNode,
    KindStringNode,
    KindStructureNode,
    KindLogicalNode,
    KindTypeNode,
    KindUnaryNode,
    KindWhileNode,
    KindBlockNode,
  };

  union ASTValueData {
    void* ref;
    tsil::ast::ArgNode* ArgNode;
    tsil::ast::AssignNode* AssignNode;
    tsil::ast::BinaryNode* BinaryNode;
    tsil::ast::BreakNode* BreakNode;
    tsil::ast::CallNode* CallNode;
    tsil::ast::DefineNode* DefineNode;
    tsil::ast::GetNode* GetNode;
    tsil::ast::SetNode* SetNode;
    tsil::ast::ComparisonNode* ComparisonNode;
    tsil::ast::ContinueNode* ContinueNode;
    tsil::ast::DiiaNode* DiiaNode;
    tsil::ast::IdentifierNode* IdentifierNode;
    tsil::ast::IfNode* IfNode;
    tsil::ast::NumberNode* NumberNode;
    tsil::ast::ParamNode* ParamNode;
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

    static ASTValue* ast_value(AssignNode* node) {
      const auto value = new ASTValue(KindAssignNode);
      value->data.AssignNode = node;
      return value;
    }
  };

  struct BinaryNode {
    BinaryOp op;
    ASTValue* left;
    ASTValue* right;

    static ASTValue* ast_value(BinaryNode* node) {
      const auto value = new ASTValue(KindBinaryNode);
      value->data.BinaryNode = node;
      return value;
    }
  };

  struct BreakNode {
    static ASTValue* ast_value(BreakNode* node) {
      const auto value = new ASTValue(KindBreakNode);
      value->data.BreakNode = node;
      return value;
    }
  };

  struct CallNode {
    ASTValue* value;
    std::vector<ASTValue*> args;

    static ASTValue* ast_value(CallNode* node) {
      const auto value = new ASTValue(KindCallNode);
      value->data.CallNode = node;
      return value;
    }
  };

  struct DefineNode {
    ASTValue* type;
    std::string id;
    ASTValue* value;

    static ASTValue* ast_value(DefineNode* node) {
      const auto value = new ASTValue(KindDefineNode);
      value->data.DefineNode = node;
      return value;
    }
  };

  struct GetNode {
    ASTValue* left;
    std::string id;

    static ASTValue* ast_value(GetNode* node) {
      const auto value = new ASTValue(KindGetNode);
      value->data.GetNode = node;
      return value;
    }
  };

  struct SetNode {
    ASTValue* left;
    std::string id;
    ASTValue* value;

    static ASTValue* ast_value(SetNode* node) {
      const auto value = new ASTValue(KindSetNode);
      value->data.SetNode = node;
      return value;
    }
  };

  struct ComparisonNode {
    BinaryOp op;
    ASTValue* left;
    ASTValue* right;

    static ASTValue* ast_value(ComparisonNode* node) {
      const auto value = new ASTValue(KindComparisonNode);
      value->data.ComparisonNode = node;
      return value;
    }
  };

  struct ContinueNode {
    static ASTValue* ast_value(ContinueNode* node) {
      const auto value = new ASTValue(KindContinueNode);
      value->data.ContinueNode = node;
      return value;
    }
  };

  struct DiiaNode {
    ASTValue* type;
    std::string id;
    std::vector<ASTValue*> params;
    std::vector<ASTValue*> body;

    static ASTValue* ast_value(DiiaNode* node) {
      const auto value = new ASTValue(KindDiiaNode);
      value->data.DiiaNode = node;
      return value;
    }
  };

  struct IdentifierNode {
    std::string name;

    static ASTValue* ast_value(IdentifierNode* node) {
      const auto value = new ASTValue(KindIdentifierNode);
      value->data.IdentifierNode = node;
      return value;
    }
  };

  struct IfNode {
    ASTValue* condition;
    std::vector<ASTValue*> body;
    std::vector<ASTValue*> else_body;

    static ASTValue* ast_value(IfNode* node) {
      const auto value = new ASTValue(KindIfNode);
      value->data.IfNode = node;
      return value;
    }
  };

  struct NumberNode {
    std::string value;

    static ASTValue* ast_value(NumberNode* node) {
      const auto value = new ASTValue(KindNumberNode);
      value->data.NumberNode = node;
      return value;
    }
  };

  struct ParamNode {
    ASTValue* type;
    std::string id;

    static ASTValue* ast_value(ParamNode* node) {
      const auto value = new ASTValue(KindParamNode);
      value->data.ParamNode = node;
      return value;
    }
  };

  struct ReturnNode {
    ASTValue* value;

    static ASTValue* ast_value(ReturnNode* node) {
      const auto value = new ASTValue(KindReturnNode);
      value->data.ReturnNode = node;
      return value;
    }
  };

  struct StringNode {
    std::string value;

    static ASTValue* ast_value(StringNode* node) {
      const auto value = new ASTValue(KindStringNode);
      value->data.StringNode = node;
      return value;
    }
  };

  struct StructureNode {
    std::string name;
    std::vector<ASTValue*> params;

    static ASTValue* ast_value(StructureNode* node) {
      const auto value = new ASTValue(KindStructureNode);
      value->data.StructureNode = node;
      return value;
    }
  };

  struct LogicalNode {
    LogicalOp op;
    ASTValue* left;
    ASTValue* right;

    static ASTValue* ast_value(LogicalNode* node) {
      const auto value = new ASTValue(KindLogicalNode);
      value->data.LogicalNode = node;
      return value;
    }
  };

  struct TypeNode {
    std::string id;

    static ASTValue* ast_value(TypeNode* node) {
      const auto value = new ASTValue(KindTypeNode);
      value->data.TypeNode = node;
      return value;
    }
  };

  struct UnaryNode {
    UnaryOp op;
    ASTValue* value;

    static ASTValue* ast_value(UnaryNode* node) {
      const auto value = new ASTValue(KindUnaryNode);
      value->data.UnaryNode = node;
      return value;
    }
  };

  struct WhileNode {
    ASTValue* condition;
    std::vector<ASTValue*> body;

    static ASTValue* ast_value(WhileNode* node) {
      const auto value = new ASTValue(KindWhileNode);
      value->data.WhileNode = node;
      return value;
    }
  };

  struct BlockNode {
    std::vector<ASTValue*> body;

    static ASTValue* ast_value(BlockNode* node) {
      const auto value = new ASTValue(KindBlockNode);
      value->data.BlockNode = node;
      return value;
    }
  };
} // namespace tsil::ast
#endif // TSIL_AST_H
