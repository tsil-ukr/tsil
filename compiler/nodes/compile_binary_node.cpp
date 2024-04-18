#include "../compiler.h"

std::string getBinaryOpSymbol(tsil::ast::BinaryOp op) {
  if (op == tsil::ast::ARITHMETIC_ADD) {
    return "+";
  }
  if (op == tsil::ast::ARITHMETIC_SUB) {
    return "-";
  }
  if (op == tsil::ast::ARITHMETIC_MUL) {
    return "*";
  }
  if (op == tsil::ast::ARITHMETIC_DIV) {
    return "/";
  }
  if (op == tsil::ast::ARITHMETIC_MOD) {
    return "%";
  }
  if (op == tsil::ast::COMPARISON_EQ) {
    return "==";
  }
  if (op == tsil::ast::COMPARISON_NE) {
    return "!=";
  }
  if (op == tsil::ast::COMPARISON_LT) {
    return "<";
  }
  if (op == tsil::ast::COMPARISON_GT) {
    return ">";
  }
  if (op == tsil::ast::COMPARISON_LE) {
    return "<=";
  }
  if (op == tsil::ast::COMPARISON_GE) {
    return ">=";
  }
  return "";
}

namespace tsil::compiler {
  CompilerValueResult CompilationScope::compile_binary_node(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* ast_value) {
    const auto binary_node = ast_value->data.BinaryNode;
    CompilerValueResult left =
        this->compile_ast_value(function, block, binary_node->left);
    if (left.error) {
      return left;
    }
    CompilerValueResult right =
        this->compile_ast_value(function, block, binary_node->right);
    if (right.error) {
      return right;
    }
    if (left.type != right.type) {
      return {nullptr, nullptr,
              CompilerError::fromASTValue(
                  ast_value,
                  "Типи операції \"" + getBinaryOpSymbol(binary_node->op) +
                      "\" не співпадають: \"" + left.type->getFullName() +
                      "\" та \"" + right.type->getFullName() + "\"")};
    }
    x::Value* result = nullptr;
    switch (binary_node->op) {
      case tsil::ast::ARITHMETIC_ADD: {
        result = this->state->Module->pushFunctionBlockAddInstruction(
            block, left.type->LT, left.LV, right.LV);
        break;
      }
      case tsil::ast::ARITHMETIC_SUB: {
        result = this->state->Module->pushFunctionBlockSubInstruction(
            block, left.type->LT, left.LV, right.LV);
        break;
      }
      case tsil::ast::ARITHMETIC_MUL: {
        result = this->state->Module->pushFunctionBlockMulInstruction(
            block, left.type->LT, left.LV, right.LV);
        break;
      }
      case tsil::ast::ARITHMETIC_DIV: {
        result = this->state->Module->pushFunctionBlockDivInstruction(
            block, left.type->LT, left.LV, right.LV);
        break;
      }
      case tsil::ast::ARITHMETIC_MOD: {
        result = this->state->Module->pushFunctionBlockModInstruction(
            block, left.type->LT, left.LV, right.LV);
        break;
      }
      case tsil::ast::COMPARISON_EQ: {
        result = this->state->Module->pushFunctionBlockICmpInstruction(
            block, "eq", left.type->LT, left.LV, right.LV);
        break;
      }
      case tsil::ast::COMPARISON_NE: {
        result = this->state->Module->pushFunctionBlockICmpInstruction(
            block, "ne", left.type->LT, left.LV, right.LV);
        break;
      }
      case tsil::ast::COMPARISON_LT: {
        result = this->state->Module->pushFunctionBlockICmpInstruction(
            block, "lt", left.type->LT, left.LV, right.LV);
        break;
      }
      case tsil::ast::COMPARISON_GT: {
        result = this->state->Module->pushFunctionBlockICmpInstruction(
            block, "gt", left.type->LT, left.LV, right.LV);
        break;
      }
      case tsil::ast::COMPARISON_LE: {
        result = this->state->Module->pushFunctionBlockICmpInstruction(
            block, "le", left.type->LT, left.LV, right.LV);
        break;
      }
      case tsil::ast::COMPARISON_GE: {
        result = this->state->Module->pushFunctionBlockICmpInstruction(
            block, "ge", left.type->LT, left.LV, right.LV);
        break;
      }
    }
    return {left.type, result, nullptr};
  }
} // namespace tsil::compiler