#include "../compiler.h"

namespace tsil::compiler {
  std::string getTsilAstBinaryOpSymbol(tsil::ast::BinaryOp op) {
    switch (op) {
      case tsil::ast::ARITHMETIC_ADD:
        return "+";
      case tsil::ast::ARITHMETIC_SUB:
        return "-";
      case tsil::ast::ARITHMETIC_MUL:
        return "*";
      case tsil::ast::ARITHMETIC_DIV:
        return "/";
      case tsil::ast::ARITHMETIC_MOD:
        return "%";
      case tsil::ast::BITWISE_AND:
        return "&";
      case tsil::ast::BITWISE_OR:
        return "|";
      case tsil::ast::BITWISE_XOR:
        return "^";
      case tsil::ast::BITWISE_SHIFT_LEFT:
        return "<<";
      case tsil::ast::BITWISE_SHIFT_RIGHT:
        return ">>";
      case tsil::ast::COMPARISON_EQ:
        return "==";
      case tsil::ast::COMPARISON_NE:
        return "!=";
      case tsil::ast::COMPARISON_LT:
        return "<";
      case tsil::ast::COMPARISON_GT:
        return ">";
      case tsil::ast::COMPARISON_LE:
        return "<=";
      case tsil::ast::COMPARISON_GE:
        return ">=";
    }
    return "";
  }

  CompilerValueResult CompilationScope::compileBinary(
      x::Function* function,
      tsil::x::FunctionBlock* block,
      tsil::ast::ASTValue* astValue) {
    const auto binaryNode = astValue->data.BinaryNode;
    CompilerValueResult leftResult =
        this->compileValue(function, block, binaryNode->left);
    if (leftResult.error) {
      return leftResult;
    }
    CompilerValueResult rightResult =
        this->compileValue(function, block, binaryNode->right);
    if (rightResult.error) {
      return rightResult;
    }
    if (leftResult.type != rightResult.type) {
      return {
          nullptr, nullptr,
          CompilerError::fromASTValue(
              astValue,
              "Типи вказівки \"" + getTsilAstBinaryOpSymbol(binaryNode->op) +
                  "\" не співпадають: \"" + leftResult.type->getFullName() +
                  "\" та \"" + rightResult.type->getFullName() + "\"")};
    }
    x::Value* xValue = nullptr;
    switch (binaryNode->op) {
      case tsil::ast::ARITHMETIC_ADD: {
        xValue = this->state->Module->pushFunctionBlockAddInstruction(
            block, leftResult.type->LT, leftResult.LV, rightResult.LV);
        break;
      }
      case tsil::ast::ARITHMETIC_SUB: {
        xValue = this->state->Module->pushFunctionBlockSubInstruction(
            block, leftResult.type->LT, leftResult.LV, rightResult.LV);
        break;
      }
      case tsil::ast::ARITHMETIC_MUL: {
        xValue = this->state->Module->pushFunctionBlockMulInstruction(
            block, leftResult.type->LT, leftResult.LV, rightResult.LV);
        break;
      }
      case tsil::ast::ARITHMETIC_DIV: {
        xValue = this->state->Module->pushFunctionBlockDivInstruction(
            block, leftResult.type->LT, leftResult.LV, rightResult.LV);
        break;
      }
      case tsil::ast::ARITHMETIC_MOD: {
        xValue = this->state->Module->pushFunctionBlockModInstruction(
            block, leftResult.type->LT, leftResult.LV, rightResult.LV);
        break;
      }
      case tsil::ast::COMPARISON_EQ: {
        xValue = this->state->Module->pushFunctionBlockICmpInstruction(
            block, "eq", leftResult.type->LT, leftResult.LV, rightResult.LV);
        break;
      }
      case tsil::ast::COMPARISON_NE: {
        xValue = this->state->Module->pushFunctionBlockICmpInstruction(
            block, "ne", leftResult.type->LT, leftResult.LV, rightResult.LV);
        break;
      }
      case tsil::ast::COMPARISON_LT: {
        xValue = this->state->Module->pushFunctionBlockICmpInstruction(
            block, "lt", leftResult.type->LT, leftResult.LV, rightResult.LV);
        break;
      }
      case tsil::ast::COMPARISON_GT: {
        xValue = this->state->Module->pushFunctionBlockICmpInstruction(
            block, "gt", leftResult.type->LT, leftResult.LV, rightResult.LV);
        break;
      }
      case tsil::ast::COMPARISON_LE: {
        xValue = this->state->Module->pushFunctionBlockICmpInstruction(
            block, "le", leftResult.type->LT, leftResult.LV, rightResult.LV);
        break;
      }
      case tsil::ast::COMPARISON_GE: {
        xValue = this->state->Module->pushFunctionBlockICmpInstruction(
            block, "ge", leftResult.type->LT, leftResult.LV, rightResult.LV);
        break;
      }
    }
    return {leftResult.type, xValue, nullptr};
  }
} // namespace tsil::compiler