#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileBinary(tsil::x::Function* xFunction,
                                           tsil::x::FunctionBlock* xBlock,
                                           ast::ASTValue* astValue) {
    const auto binaryNode = astValue->data.BinaryNode;
    CompilerValueResult leftResult =
        this->compileValueNoVariation(xFunction, xBlock, binaryNode->left);
    if (leftResult.error) {
      return leftResult;
    }
    CompilerValueResult rightResult =
        this->compileValueNoVariation(xFunction, xBlock, binaryNode->right);
    if (rightResult.error) {
      return rightResult;
    }
    const auto castedXValue =
        this->compileSoftCast(xFunction, xBlock, leftResult.type,
                              leftResult.xValue, rightResult.type);
    if (castedXValue) {
      leftResult.type = rightResult.type;
      leftResult.xValue = castedXValue;
    } else {
      return {nullptr, nullptr,
              CompilerError::typesOfInstructionDifferent(
                  astValue, leftResult.type, rightResult.type)};
    }
    x::Value* xValue = nullptr;
    switch (binaryNode->op) {
      case tsil::ast::ARITHMETIC_ADD: {
        if (!leftResult.type->isArithmetical(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotArithmetical(astValue, leftResult.type)};
        }
        if (leftResult.type->isFloating(this)) {
          xValue = this->compiler->xModule->pushFunctionBlockFAddInstruction(
              xBlock, leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        } else {
          xValue = this->compiler->xModule->pushFunctionBlockAddInstruction(
              xBlock, leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        }
        return {leftResult.type, xValue, nullptr};
      }
      case tsil::ast::ARITHMETIC_SUB: {
        if (!leftResult.type->isArithmetical(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotArithmetical(astValue, leftResult.type)};
        }
        if (leftResult.type->isFloating(this)) {
          xValue = this->compiler->xModule->pushFunctionBlockFSubInstruction(
              xBlock, leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        } else {
          xValue = this->compiler->xModule->pushFunctionBlockSubInstruction(
              xBlock, leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        }
        return {leftResult.type, xValue, nullptr};
      }
      case tsil::ast::ARITHMETIC_MUL: {
        if (!leftResult.type->isArithmetical(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotArithmetical(astValue, leftResult.type)};
        }
        if (leftResult.type->isFloating(this)) {
          xValue = this->compiler->xModule->pushFunctionBlockFMulInstruction(
              xBlock, leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        } else {
          xValue = this->compiler->xModule->pushFunctionBlockMulInstruction(
              xBlock, leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        }
        return {leftResult.type, xValue, nullptr};
      }
      case tsil::ast::ARITHMETIC_DIV: {
        if (!leftResult.type->isArithmetical(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotArithmetical(astValue, leftResult.type)};
        }
        if (leftResult.type->isFloating(this)) {
          xValue = this->compiler->xModule->pushFunctionBlockFDivInstruction(
              xBlock, leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        } else {
          xValue = this->compiler->xModule->pushFunctionBlockDivInstruction(
              xBlock, leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        }
        return {leftResult.type, xValue, nullptr};
      }
      case tsil::ast::ARITHMETIC_MOD: {
        if (!leftResult.type->isArithmetical(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotArithmetical(astValue, leftResult.type)};
        }
        if (leftResult.type->isFloating(this)) {
          xValue = this->compiler->xModule->pushFunctionBlockFModInstruction(
              xBlock, leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        } else {
          xValue = this->compiler->xModule->pushFunctionBlockModInstruction(
              xBlock, leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        }
        return {leftResult.type, xValue, nullptr};
      }
      case tsil::ast::BITWISE_AND: {
        if (!leftResult.type->isBitwisible(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotBitwisible(astValue, leftResult.type)};
        }
        xValue = this->compiler->xModule->pushFunctionBlockAndInstruction(
            xBlock, leftResult.type->xType, leftResult.xValue,
            rightResult.xValue);
        return {leftResult.type, xValue, nullptr};
      }
      case tsil::ast::BITWISE_OR: {
        if (!leftResult.type->isBitwisible(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotBitwisible(astValue, leftResult.type)};
        }
        xValue = this->compiler->xModule->pushFunctionBlockOrInstruction(
            xBlock, leftResult.type->xType, leftResult.xValue,
            rightResult.xValue);
        return {leftResult.type, xValue, nullptr};
      }
      case tsil::ast::BITWISE_XOR: {
        if (!leftResult.type->isBitwisible(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotBitwisible(astValue, leftResult.type)};
        }
        xValue = this->compiler->xModule->pushFunctionBlockXorInstruction(
            xBlock, leftResult.type->xType, leftResult.xValue,
            rightResult.xValue);
        return {leftResult.type, xValue, nullptr};
      }
      case tsil::ast::BITWISE_SHIFT_LEFT: {
        if (!leftResult.type->isBitwisible(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotBitwisible(astValue, leftResult.type)};
        }
        xValue = this->compiler->xModule->pushFunctionBlockShlInstruction(
            xBlock, leftResult.type->xType, leftResult.xValue,
            rightResult.xValue);
        return {leftResult.type, xValue, nullptr};
      }
      case tsil::ast::BITWISE_SHIFT_RIGHT: {
        if (!leftResult.type->isBitwisible(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotBitwisible(astValue, leftResult.type)};
        }
        xValue = this->compiler->xModule->pushFunctionBlockLShrInstruction(
            xBlock, leftResult.type->xType, leftResult.xValue,
            rightResult.xValue);
        return {leftResult.type, xValue, nullptr};
      }
      case tsil::ast::COMPARISON_EQ: {
        if (!leftResult.type->isComparable(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotComparable(astValue, leftResult.type)};
        }
        if (leftResult.type->isFloating(this)) {
          xValue = this->compiler->xModule->pushFunctionBlockFCmpInstruction(
              xBlock, "ueq", leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        } else {
          xValue = this->compiler->xModule->pushFunctionBlockICmpInstruction(
              xBlock, "eq", leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        }
        return {this->compiler->uint1Type, xValue, nullptr};
      }
      case tsil::ast::COMPARISON_NE: {
        if (!leftResult.type->isComparable(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotComparable(astValue, leftResult.type)};
        }
        if (leftResult.type->isFloating(this)) {
          xValue = this->compiler->xModule->pushFunctionBlockFCmpInstruction(
              xBlock, "une", leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        } else {
          xValue = this->compiler->xModule->pushFunctionBlockICmpInstruction(
              xBlock, "ne", leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        }
        return {this->compiler->uint1Type, xValue, nullptr};
      }
      case tsil::ast::COMPARISON_LT: {
        if (!leftResult.type->isComparable(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotComparable(astValue, leftResult.type)};
        }
        if (leftResult.type->isUnsigned(this)) {
          xValue = this->compiler->xModule->pushFunctionBlockICmpInstruction(
              xBlock, "ult", leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        } else if (leftResult.type->isFloating(this)) {
          xValue = this->compiler->xModule->pushFunctionBlockFCmpInstruction(
              xBlock, "ult", leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        } else {
          xValue = this->compiler->xModule->pushFunctionBlockICmpInstruction(
              xBlock, "slt", leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        }
        return {this->compiler->uint1Type, xValue, nullptr};
      }
      case tsil::ast::COMPARISON_GT: {
        if (!leftResult.type->isComparable(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotComparable(astValue, leftResult.type)};
        }
        if (leftResult.type->isUnsigned(this)) {
          xValue = this->compiler->xModule->pushFunctionBlockICmpInstruction(
              xBlock, "ugt", leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        } else if (leftResult.type->isFloating(this)) {
          xValue = this->compiler->xModule->pushFunctionBlockFCmpInstruction(
              xBlock, "ugt", leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        } else {
          xValue = this->compiler->xModule->pushFunctionBlockICmpInstruction(
              xBlock, "sgt", leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        }
        return {this->compiler->uint1Type, xValue, nullptr};
      }
      case tsil::ast::COMPARISON_LE: {
        if (!leftResult.type->isComparable(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotComparable(astValue, leftResult.type)};
        }
        if (leftResult.type->isUnsigned(this)) {
          xValue = this->compiler->xModule->pushFunctionBlockICmpInstruction(
              xBlock, "ule", leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        } else if (leftResult.type->isFloating(this)) {
          xValue = this->compiler->xModule->pushFunctionBlockFCmpInstruction(
              xBlock, "ule", leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        } else {
          xValue = this->compiler->xModule->pushFunctionBlockICmpInstruction(
              xBlock, "sle", leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        }
        return {this->compiler->uint1Type, xValue, nullptr};
      }
      case tsil::ast::COMPARISON_GE: {
        if (!leftResult.type->isComparable(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotComparable(astValue, leftResult.type)};
        }
        if (leftResult.type->isUnsigned(this)) {
          xValue = this->compiler->xModule->pushFunctionBlockICmpInstruction(
              xBlock, "uge", leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        } else if (leftResult.type->isFloating(this)) {
          xValue = this->compiler->xModule->pushFunctionBlockFCmpInstruction(
              xBlock, "uge", leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        } else {
          xValue = this->compiler->xModule->pushFunctionBlockICmpInstruction(
              xBlock, "sge", leftResult.type->xType, leftResult.xValue,
              rightResult.xValue);
        }
        return {this->compiler->uint1Type, xValue, nullptr};
      }
    }
    return {leftResult.type, xValue, nullptr};
  }
} // namespace tsil::tk