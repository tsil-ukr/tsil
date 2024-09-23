#include "../tk.h"

namespace tsil::tk {
  CompilerValueResult Scope::compileBinary(XLFunction* xFunction,
                                           XLBasicBlock* xBlock,
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
    if (leftResult.type->isPointer()) {
      if (binaryNode->op == ast::ARITHMETIC_ADD) {
        const auto castedRightXValue = this->compileSoftCast(
            xFunction, xBlock, rightResult.type, rightResult.xValue,
            this->compiler->int64Type);
        if (castedRightXValue) {
          rightResult.type = this->compiler->int64Type;
          rightResult.xValue = castedRightXValue;
          const auto gepXValue = tsil_xl_inst_getelementptr(
              this->compiler->xModule, xBlock,
              leftResult.type->pointerTo ? leftResult.type->pointerTo->xType
                                         : this->compiler->voidType->xType,
              leftResult.xValue, 1, std::vector({rightResult.xValue}).data());
          return {leftResult.type, gepXValue, nullptr};
        } else {
          return {nullptr, nullptr,
                  CompilerError::typesOfInstructionDifferent(
                      astValue, leftResult.type, rightResult.type)};
        }
      }
    }
    const auto castedXValue =
        this->compileSoftCast(xFunction, xBlock, rightResult.type,
                              rightResult.xValue, leftResult.type);
    if (castedXValue) {
      rightResult.type = leftResult.type;
      rightResult.xValue = castedXValue;
    } else {
      return {nullptr, nullptr,
              CompilerError::typesOfInstructionDifferent(
                  astValue, rightResult.type, leftResult.type)};
    }
    XLValue* xValue = nullptr;
    switch (binaryNode->op) {
      case tsil::ast::ARITHMETIC_ADD: {
        if (!leftResult.type->isArithmetical(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotArithmetical(astValue, leftResult.type)};
        }
        if (leftResult.type->isFloating(this)) {
          xValue = tsil_xl_inst_fadd(this->compiler->xModule, xBlock,
                                     leftResult.xValue, rightResult.xValue);
        } else {
          xValue = tsil_xl_inst_add(this->compiler->xModule, xBlock,
                                    leftResult.xValue, rightResult.xValue);
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
          xValue = tsil_xl_inst_fsub(this->compiler->xModule, xBlock,
                                     leftResult.xValue, rightResult.xValue);
        } else {
          xValue = tsil_xl_inst_sub(this->compiler->xModule, xBlock,
                                    leftResult.xValue, rightResult.xValue);
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
          xValue = tsil_xl_inst_fmul(this->compiler->xModule, xBlock,
                                     leftResult.xValue, rightResult.xValue);
        } else {
          xValue = tsil_xl_inst_mul(this->compiler->xModule, xBlock,
                                    leftResult.xValue, rightResult.xValue);
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
          xValue = tsil_xl_inst_fdiv(this->compiler->xModule, xBlock,
                                     leftResult.xValue, rightResult.xValue);
        } else if (leftResult.type->isUnsigned(this)) {
          xValue = tsil_xl_inst_udiv(this->compiler->xModule, xBlock,
                                     leftResult.xValue, rightResult.xValue);
        } else {
          xValue = tsil_xl_inst_sdiv(this->compiler->xModule, xBlock,
                                     leftResult.xValue, rightResult.xValue);
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
          xValue = tsil_xl_inst_fmod(this->compiler->xModule, xBlock,
                                     leftResult.xValue, rightResult.xValue);
        } else {
          xValue = tsil_xl_inst_mod(this->compiler->xModule, xBlock,
                                    leftResult.xValue, rightResult.xValue);
        }
        return {leftResult.type, xValue, nullptr};
      }
      case tsil::ast::BITWISE_AND: {
        if (!leftResult.type->isBitwisible(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotBitwisible(astValue, leftResult.type)};
        }
        xValue = tsil_xl_inst_and(this->compiler->xModule, xBlock,
                                  leftResult.xValue, rightResult.xValue);
        return {leftResult.type, xValue, nullptr};
      }
      case tsil::ast::BITWISE_OR: {
        if (!leftResult.type->isBitwisible(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotBitwisible(astValue, leftResult.type)};
        }
        xValue = tsil_xl_inst_or(this->compiler->xModule, xBlock,
                                 leftResult.xValue, rightResult.xValue);
        return {leftResult.type, xValue, nullptr};
      }
      case tsil::ast::BITWISE_XOR: {
        if (!leftResult.type->isBitwisible(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotBitwisible(astValue, leftResult.type)};
        }
        xValue = tsil_xl_inst_xor(this->compiler->xModule, xBlock,
                                  leftResult.xValue, rightResult.xValue);
        return {leftResult.type, xValue, nullptr};
      }
      case tsil::ast::BITWISE_SHIFT_LEFT: {
        if (!leftResult.type->isBitwisible(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotBitwisible(astValue, leftResult.type)};
        }
        xValue = tsil_xl_inst_shl(this->compiler->xModule, xBlock,
                                  leftResult.xValue, rightResult.xValue);
        return {leftResult.type, xValue, nullptr};
      }
      case tsil::ast::BITWISE_SHIFT_RIGHT: {
        if (!leftResult.type->isBitwisible(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotBitwisible(astValue, leftResult.type)};
        }
        xValue = tsil_xl_inst_lshr(this->compiler->xModule, xBlock,
                                   leftResult.xValue, rightResult.xValue);
        return {leftResult.type, xValue, nullptr};
      }
      case tsil::ast::COMPARISON_EQ: {
        if (!leftResult.type->isComparable(this)) {
          return {
              nullptr, nullptr,
              CompilerError::typeIsNotComparable(astValue, leftResult.type)};
        }
        if (leftResult.type->isFloating(this)) {
          xValue = tsil_xl_inst_fcmp(this->compiler->xModule, xBlock, "ueq",
                                     leftResult.xValue, rightResult.xValue);
        } else {
          xValue = tsil_xl_inst_icmp(this->compiler->xModule, xBlock, "eq",
                                     leftResult.xValue, rightResult.xValue);
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
          xValue = tsil_xl_inst_fcmp(this->compiler->xModule, xBlock, "une",
                                     leftResult.xValue, rightResult.xValue);
        } else {
          xValue = tsil_xl_inst_icmp(this->compiler->xModule, xBlock, "ne",
                                     leftResult.xValue, rightResult.xValue);
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
          xValue = tsil_xl_inst_icmp(this->compiler->xModule, xBlock, "ult",
                                     leftResult.xValue, rightResult.xValue);
        } else if (leftResult.type->isFloating(this)) {
          xValue = tsil_xl_inst_fcmp(this->compiler->xModule, xBlock, "ult",
                                     leftResult.xValue, rightResult.xValue);
        } else {
          xValue = tsil_xl_inst_icmp(this->compiler->xModule, xBlock, "slt",
                                     leftResult.xValue, rightResult.xValue);
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
          xValue = tsil_xl_inst_icmp(this->compiler->xModule, xBlock, "ugt",
                                     leftResult.xValue, rightResult.xValue);
        } else if (leftResult.type->isFloating(this)) {
          xValue = tsil_xl_inst_fcmp(this->compiler->xModule, xBlock, "ugt",
                                     leftResult.xValue, rightResult.xValue);
        } else {
          xValue = tsil_xl_inst_icmp(this->compiler->xModule, xBlock, "sgt",
                                     leftResult.xValue, rightResult.xValue);
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
          xValue = tsil_xl_inst_icmp(this->compiler->xModule, xBlock, "ule",
                                     leftResult.xValue, rightResult.xValue);
        } else if (leftResult.type->isFloating(this)) {
          xValue = tsil_xl_inst_fcmp(this->compiler->xModule, xBlock, "ule",
                                     leftResult.xValue, rightResult.xValue);
        } else {
          xValue = tsil_xl_inst_icmp(this->compiler->xModule, xBlock, "sle",
                                     leftResult.xValue, rightResult.xValue);
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
          xValue = tsil_xl_inst_icmp(this->compiler->xModule, xBlock, "uge",
                                     leftResult.xValue, rightResult.xValue);
        } else if (leftResult.type->isFloating(this)) {
          xValue = tsil_xl_inst_fcmp(this->compiler->xModule, xBlock, "uge",
                                     leftResult.xValue, rightResult.xValue);
        } else {
          xValue = tsil_xl_inst_icmp(this->compiler->xModule, xBlock, "sge",
                                     leftResult.xValue, rightResult.xValue);
        }
        return {this->compiler->uint1Type, xValue, nullptr};
      }
    }
    return {leftResult.type, xValue, nullptr};
  }
} // namespace tsil::tk