#include "tk.h"

namespace tsil::tk {
  bool Scope::hasSubject(const std::string& name) const {
    if (this->variables.contains(name)) {
      return true;
    }
    if (this->rawTypes.contains(name)) {
      return true;
    }
    if (this->bakedTypes.contains({name, {}})) {
      return true;
    }
    if (this->rawDiias.contains(name)) {
      return true;
    }
    if (this->bakedDiias.contains({name, {}})) {
      return true;
    }
    if (this->parent) {
      return this->parent->hasSubject(name);
    }
    return false;
  }

  bool Scope::hasNonVariableAndNonDiiaSubject(const std::string& name) const {
    if (this->rawTypes.contains(name)) {
      return true;
    }
    if (this->bakedTypes.contains({name, {}})) {
      return true;
    }
    if (this->parent) {
      return this->parent->hasNonVariableAndNonDiiaSubject(name);
    }
    return false;
  }

  bool Scope::hasRawDiia(const std::string& name) const {
    if (this->rawDiias.contains(name)) {
      return true;
    }
    if (this->parent) {
      return this->parent->hasRawDiia(name);
    }
    return false;
  }

  ast::ASTValue* Scope::getRawDiia(const std::string& name) {
    if (this->rawDiias.contains(name)) {
      return this->rawDiias[name];
    }
    if (this->parent) {
      return this->parent->getRawDiia(name);
    }
    return nullptr;
  }

  bool Scope::hasBakedDiia(const std::string& name,
                           const std::vector<Type*>& genericValues) const {
    if (this->bakedDiias.contains({name, genericValues})) {
      return true;
    }
    if (this->parent) {
      return this->parent->hasBakedDiia(name, genericValues);
    }
    return false;
  }

  std::pair<Type*, x::Value*> Scope::getBakedDiia(
      const std::string& name,
      const std::vector<Type*>& genericValues) {
    if (this->bakedDiias.contains({name, genericValues})) {
      return this->bakedDiias[{name, genericValues}];
    }
    if (this->parent) {
      return this->parent->getBakedDiia(name, genericValues);
    }
    return {nullptr, nullptr};
  }

  bool Scope::hasRawType(const std::string& name) const {
    if (this->rawTypes.contains(name)) {
      return true;
    }
    if (this->parent) {
      return this->parent->hasRawType(name);
    }
    return false;
  }

  ast::ASTValue* Scope::getRawType(const std::string& name) {
    if (this->rawTypes.contains(name)) {
      return this->rawTypes[name];
    }
    if (this->parent) {
      return this->parent->getRawType(name);
    }
    return nullptr;
  }

  bool Scope::hasBakedType(const std::string& name,
                           const std::vector<Type*>& genericValues) const {
    if (this->bakedTypes.contains({name, genericValues})) {
      return true;
    }
    if (this->parent) {
      return this->parent->hasBakedType(name, genericValues);
    }
    return false;
  }

  Type* Scope::getBakedType(const std::string& name,
                            const std::vector<Type*>& genericValues) {
    if (this->bakedTypes.contains({name, genericValues})) {
      return this->bakedTypes[{name, genericValues}];
    }
    if (this->parent) {
      return this->parent->getBakedType(name, genericValues);
    }
    return nullptr;
  }

  bool Scope::hasVariable(const std::string& name) const {
    if (this->variables.contains(name)) {
      return true;
    }
    if (this->parent) {
      return this->parent->hasVariable(name);
    }
    return false;
  }

  std::pair<Type*, x::Value*> Scope::getVariable(const std::string& name) {
    if (this->variables.contains(name)) {
      return this->variables[name];
    }
    if (this->parent) {
      return this->parent->getVariable(name);
    }
    return {nullptr, nullptr};
  }

  CompilerValueResult Scope::compileValueGet(tsil::x::Function* xFunction,
                                             tsil::x::FunctionBlock* xBlock,
                                             ast::ASTValue* astValue,
                                             bool load) {
    const auto getNode = astValue->data.GetNode;
    Type* leftType = nullptr;
    x::Value* leftXValue = nullptr;
    if (getNode->left->kind == ast::KindIdentifierNode) {
      const auto identifierNode = getNode->left->data.IdentifierNode;
      if (this->hasVariable(identifierNode->name)) {
        const auto& [variableType, variableXValue] =
            this->getVariable(identifierNode->name);
        leftType = variableType;
        leftXValue = variableXValue;
        goto proceed;
      }
      return {nullptr, nullptr,
              CompilerError::fromASTValue(astValue, "Субʼєкт не визначено")};
    }
    if (getNode->left->kind == ast::KindGetNode) {
      const auto getLeftResult =
          this->compileValueGet(xFunction, xBlock, getNode->left, false);
      if (getLeftResult.error) {
        return getLeftResult;
      }
      leftType = getLeftResult.type;
      leftXValue = getLeftResult.xValue;
      goto proceed;
    }
    if (getNode->left->kind == ast::KindCallNode) {
    }
    return {nullptr, nullptr,
            CompilerError::fromASTValue(astValue, "NOT IMPLEMENTED GET")};
  proceed:
    if (leftType->type == TypeTypeStructureInstance) {
      if (!leftType->structureInstanceFields.contains(getNode->id)) {
        return {
            nullptr, nullptr,
            CompilerError::typeHasNoProperty(astValue, leftType, getNode->id)};
      }
      const auto field = leftType->structureInstanceFields[getNode->id];
      const auto gepXValue =
          this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
              xBlock, leftType->xType, leftXValue,
              {0, static_cast<unsigned long>(field.index)});
      if (load) {
        const auto loadXValue =
            this->compiler->xModule->pushFunctionBlockLoadInstruction(
                xBlock, field.type->xType, gepXValue);
        return {field.type, loadXValue, nullptr};
      } else {
        return {field.type, gepXValue, nullptr};
      }
    }
    return {nullptr, nullptr,
            CompilerError::typeHasNoProperty(astValue, leftType, getNode->id)};
  }

  CompilerValueResult Scope::compileValue(tsil::x::Function* xFunction,
                                          tsil::x::FunctionBlock* xBlock,
                                          ast::ASTValue* astValue) {
    if (astValue->kind == ast::KindNumberNode) {
      const auto numberNode = astValue->data.NumberNode;
      const auto type = str_contains(numberNode->value, ".")
                            ? this->compiler->doubleType
                            : this->compiler->int64Type;
      const auto xValue =
          new x::Value(type->xType, tsilNumberToLLVMNumber(numberNode->value));
      return {type, xValue, nullptr};
    }
    if (astValue->kind == ast::KindStringNode) {
      const auto stringNode = astValue->data.StringNode;
      const auto stringValue = tsilStringToLLVMString(stringNode->value);
      const auto xStringConstant =
          this->compiler->xModule->putStringConstant(stringValue);
      if (stringNode->prefix == "сі") {
        return {this->compiler->int8Type->getPointerType(this), xStringConstant,
                nullptr};
      }
    }
    if (astValue->kind == ast::KindIdentifierNode) {
      const auto identifierNode = astValue->data.IdentifierNode;
      if (this->hasVariable(identifierNode->name)) {
        const auto& [variableType, variableXValue] =
            this->getVariable(identifierNode->name);
        const auto loadXValue =
            this->compiler->xModule->pushFunctionBlockLoadInstruction(
                xBlock, variableType->xType, variableXValue);
        return {variableType, loadXValue, nullptr};
      }
      if (this->hasBakedDiia(identifierNode->name, {})) {
        const auto bakedDiia = this->getBakedDiia(identifierNode->name, {});
        return {bakedDiia.first, bakedDiia.second, nullptr};
      }
      if (this->hasNonVariableAndNonDiiaSubject(identifierNode->name)) {
        return {nullptr, nullptr,
                CompilerError::subjectIsNotRuntimeValue(astValue)};
      }
      return {nullptr, nullptr,
              CompilerError::fromASTValue(astValue, "Субʼєкт не визначено")};
    }
    if (astValue->kind == ast::KindGetNode) {
      return this->compileValueGet(xFunction, xBlock, astValue, true);
    }
    if (astValue->kind == ast::KindAsNode) {
      const auto asNode = astValue->data.AsNode;
      const auto valueResult =
          this->compileValue(xFunction, xBlock, asNode->value);
      if (valueResult.error) {
        return valueResult;
      }
      const auto typeResult = this->bakeType(asNode->type);
      if (!typeResult.type) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(asNode->type, typeResult.error)};
      }
      // todo: cast
      return {typeResult.type, valueResult.xValue, nullptr};
    }
    if (astValue->kind == ast::KindBinaryNode) {
      const auto binaryNode = astValue->data.BinaryNode;
      CompilerValueResult leftResult =
          this->compileValue(xFunction, xBlock, binaryNode->left);
      if (leftResult.error) {
        return leftResult;
      }
      CompilerValueResult rightResult =
          this->compileValue(xFunction, xBlock, binaryNode->right);
      if (rightResult.error) {
        return rightResult;
      }
      if (leftResult.type != rightResult.type) {
        return {nullptr, nullptr,
                CompilerError::typesOfInstructionDifferent(
                    astValue, leftResult.type, rightResult.type)};
      }
      x::Value* xValue = nullptr;
      switch (binaryNode->op) {
        case tsil::ast::ARITHMETIC_ADD: {
          if (!leftResult.type->isArithmetical(this)) {
            return {nullptr, nullptr,
                    CompilerError::typeIsNotArithmetical(astValue,
                                                         leftResult.type)};
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
            return {nullptr, nullptr,
                    CompilerError::typeIsNotArithmetical(astValue,
                                                         leftResult.type)};
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
            return {nullptr, nullptr,
                    CompilerError::typeIsNotArithmetical(astValue,
                                                         leftResult.type)};
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
            return {nullptr, nullptr,
                    CompilerError::typeIsNotArithmetical(astValue,
                                                         leftResult.type)};
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
            return {nullptr, nullptr,
                    CompilerError::typeIsNotArithmetical(astValue,
                                                         leftResult.type)};
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
          return {this->compiler->int1Type, xValue, nullptr};
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
          return {this->compiler->int1Type, xValue, nullptr};
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
          return {this->compiler->int1Type, xValue, nullptr};
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
          return {this->compiler->int1Type, xValue, nullptr};
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
          return {this->compiler->int1Type, xValue, nullptr};
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
          return {this->compiler->int1Type, xValue, nullptr};
        }
      }
      return {leftResult.type, xValue, nullptr};
    }
    if (astValue->kind == ast::KindCallNode) {
      const auto callNode = astValue->data.CallNode;
      if (callNode->value->kind == ast::KindIdentifierNode) {
        const auto identifierNode = callNode->value->data.IdentifierNode;

        std::vector<Type*> genericValues;
        for (const auto& genericValue : callNode->generic_values) {
          const auto genericTypeResult = this->bakeType(genericValue);
          if (!genericTypeResult.type) {
            return {nullptr, nullptr,
                    CompilerError::fromASTValue(genericValue,
                                                genericTypeResult.error)};
          }
          genericValues.push_back(genericTypeResult.type);
        }
        Type* diiaType;
        x::Value* diiaXValue;
        if (this->hasBakedDiia(identifierNode->name, genericValues)) {
          const auto bakedDiia =
              this->getBakedDiia(identifierNode->name, genericValues);
          diiaType = bakedDiia.first;
          diiaXValue = bakedDiia.second;
        } else {
          if (this->hasRawDiia(identifierNode->name)) {
            const auto rawDiia = this->getRawDiia(identifierNode->name);
            const auto bakeDiiaResult =
                this->bakeDiia(astValue, rawDiia, genericValues);
            if (bakeDiiaResult.error) {
              return {nullptr, nullptr, bakeDiiaResult.error};
            }
            diiaType = bakeDiiaResult.type;
            diiaXValue = bakeDiiaResult.xValue;
          } else {
            return {
                nullptr, nullptr,
                CompilerError::fromASTValue(astValue, "Неможливо викликати")};
          }
        }
        if (callNode->args.size() < diiaType->diiaParameters.size()) {
          return {nullptr, nullptr,
                  CompilerError::fromASTValue(
                      astValue, "Недостатньо аргументів для виконання дії")};
        }
        if (callNode->args.size() > diiaType->diiaParameters.size()) {
          return {nullptr, nullptr,
                  CompilerError::fromASTValue(
                      astValue, "Забагато аргументів для виконання дії")};
        }
        std::vector<x::Value*> xArgs;
        int argIndex = 0;
        for (const auto& argAstValue : callNode->args) {
          const auto argResult =
              this->compileValue(xFunction, xBlock, argAstValue);
          if (argResult.error) {
            return argResult;
          }
          const auto& diiaParameter = diiaType->diiaParameters[argIndex];
          if (argResult.type != diiaParameter.type) {
            return {
                nullptr, nullptr,
                CompilerError::fromASTValue(
                    argAstValue, "Невірний тип параметра \"" +
                                     diiaParameter.name + "\": очікується \"" +
                                     diiaParameter.type->getFullName() +
                                     "\", отримано \"" +
                                     argResult.type->getFullName() + "\"")};
          }
          xArgs.push_back(argResult.xValue);
          argIndex++;
        }
        const auto xValue =
            this->compiler->xModule->pushFunctionBlockCallInstruction(
                xBlock, diiaType->diiaReturnType->xType, diiaXValue, xArgs);
        return {diiaType->diiaReturnType, xValue, nullptr};
      }
      return {nullptr, nullptr,
              CompilerError::fromASTValue(astValue, "Неможливо викликати")};
    }
    if (astValue->kind == ast::KindConstructorNode) {
      const auto constructorNode = astValue->data.ConstructorNode;
      const auto typeResult = this->bakeType(constructorNode->type);
      if (!typeResult.type) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(constructorNode->type,
                                            typeResult.error)};
      }
      if (typeResult.type->type != TypeTypeStructureInstance) {
        return {nullptr, nullptr,
                CompilerError::typeIsNotConstructable(constructorNode->type,
                                                      typeResult.type)};
      }
      const auto xAllocValue =
          this->compiler->xModule->pushFunctionBlockAllocaInstruction(
              xBlock, typeResult.type->xType);
      for (const auto argAstValue : constructorNode->args) {
        const auto constructorArgNode = argAstValue->data.ConstructorArgNode;
        if (!typeResult.type->structureInstanceFields.contains(
                constructorArgNode->id)) {
          return {nullptr, nullptr,
                  CompilerError::fromASTValue(
                      argAstValue, "Властивість \"" + constructorArgNode->id +
                                       "\" не знайдено в типі \"" +
                                       typeResult.type->getFullName() + "\"")};
        }
        const auto field =
            typeResult.type->structureInstanceFields[constructorArgNode->id];
        const auto argValueResult =
            this->compileValue(xFunction, xBlock, constructorArgNode->value);
        if (argValueResult.error) {
          return {nullptr, nullptr, argValueResult.error};
        }
        if (argValueResult.type != field.type) {
          return {nullptr, nullptr,
                  CompilerError::fromASTValue(
                      constructorArgNode->value,
                      "Невірний тип властивості \"" + constructorArgNode->id +
                          "\": очікується \"" + field.type->getFullName() +
                          "\", отримано \"" +
                          argValueResult.type->getFullName() + "\"")};
        }
        const auto xGepValue =
            this->compiler->xModule->pushFunctionBlockGetElementPtrInstruction(
                xBlock, typeResult.type->xType, xAllocValue,
                {0, static_cast<unsigned long>(field.index)});
        this->compiler->xModule->pushFunctionBlockStoreInstruction(
            xBlock, argValueResult.type->xType, argValueResult.xValue,
            xGepValue);
      }
      x::Value* xLoadValue =
          this->compiler->xModule->pushFunctionBlockLoadInstruction(
              xBlock, typeResult.type->xType, xAllocValue);
      return {typeResult.type, xLoadValue, nullptr};
    }
    return {nullptr, nullptr,
            CompilerError::fromASTValue(astValue, "NOT IMPLEMENTED VALUE")};
  }

  CompilerResult Scope::compileDiiaBody(
      Type* diiaType,
      tsil::x::Function* xFunction,
      tsil::x::FunctionBlock* xBlock,
      tsil::x::FunctionBlock* xExitBlock,
      const std::vector<ast::ASTValue*>& body) {
    const auto originalXBlock = xBlock;
    if (body.empty()) {
      this->compiler->xModule->pushFunctionBlockBrInstruction(xBlock,
                                                              xExitBlock);
      return {nullptr};
    }
    int childIndex = 0;
    for (const auto& childAstValue : body) {
      if (childAstValue == nullptr) {
        continue;
      }
      if (childAstValue->kind == tsil::ast::KindNone) {
        continue;
      }
      if (childAstValue->kind == ast::KindDefineNode) {
        const auto defineNode = childAstValue->data.DefineNode;
        if (this->hasSubject(defineNode->id)) {
          return {CompilerError::subjectAlreadyDefined(childAstValue)};
        }
        Type* type = nullptr;
        if (defineNode->type) {
          const auto typeResult = this->bakeType(defineNode->type);
          if (!typeResult.type) {
            return {CompilerError::fromASTValue(defineNode->type,
                                                typeResult.error)};
          }
          type = typeResult.type;
        }
        if (defineNode->value) {
          const auto valueResult =
              this->compileValue(xFunction, xBlock, defineNode->value);
          if (valueResult.error) {
            return {valueResult.error};
          }
          if (type) {
            if (valueResult.type != type) {
              return {CompilerError::typesAreNotCompatible(
                  defineNode->value, valueResult.type, type)};
            }
          } else {
            type = valueResult.type;
          }
          const auto allocaXValue =
              this->compiler->xModule->pushFunctionBlockAllocaInstruction(
                  xBlock, type->xType);
          this->compiler->xModule->pushFunctionBlockStoreInstruction(
              xBlock, valueResult.type->xType, valueResult.xValue,
              allocaXValue);
          this->variables[defineNode->id] = {type, allocaXValue};
        } else {
          const auto allocaXValue =
              this->compiler->xModule->pushFunctionBlockAllocaInstruction(
                  xBlock, type->xType);
          this->variables[defineNode->id] = {type, allocaXValue};
        }
      } else if (childAstValue->kind == ast::KindAssignNode) {
        const auto assignNode = childAstValue->data.AssignNode;
        if (!this->hasVariable(assignNode->id)) {
          return {CompilerError::cannotRedefineSubject(childAstValue,
                                                       assignNode->id)};
        }
        const auto& [variableType, variableXValue] =
            this->getVariable(assignNode->id);
        const auto valueResult =
            this->compileValue(xFunction, xBlock, assignNode->value);
        if (valueResult.error) {
          return {valueResult.error};
        }
        if (variableType->type == TypeTypeDiia) {
          return {CompilerError::typesAreNotCompatible(
              childAstValue, variableType, valueResult.type)};
        }
        this->compiler->xModule->pushFunctionBlockStoreInstruction(
            xBlock, valueResult.type->xType, valueResult.xValue,
            variableXValue);
      } else if (childAstValue->kind == ast::KindSetNode) {
        return {
            CompilerError::fromASTValue(childAstValue, "NOT IMPLEMENTED SET")};
      } else if (childAstValue->kind == ast::KindCallNode) {
        const auto valueResult =
            this->compileValue(xFunction, xBlock, childAstValue);
        if (valueResult.error) {
          return {valueResult.error};
        }
      } else if (childAstValue->kind == ast::KindWhileNode) {
        const auto xWhileBlock =
            this->compiler->xModule->defineFunctionBlock(xFunction, "while");
        const auto xWhileBodyBlock =
            this->compiler->xModule->defineFunctionBlock(xFunction,
                                                         "while_body");
        const auto xWhileExitBlock =
            childIndex == body.size() - 1
                ? xExitBlock
                : this->compiler->xModule->defineFunctionBlock(xFunction,
                                                               "while_exit");
        const auto valueResult = this->compileValue(
            xFunction, xWhileBlock, childAstValue->data.WhileNode->condition);
        if (valueResult.error) {
          return {valueResult.error};
        }
        this->compiler->xModule->pushFunctionBlockBrIfInstruction(
            xWhileBlock, valueResult.xValue, xWhileBodyBlock, xWhileExitBlock);
        const auto whileBodyResult = this->compileDiiaBody(
            diiaType, xFunction, xWhileBodyBlock, xWhileExitBlock,
            childAstValue->data.WhileNode->body);
        if (whileBodyResult.error) {
          return {whileBodyResult.error};
        }
        this->compiler->xModule->pushFunctionBlockBrInstruction(xWhileBodyBlock,
                                                                xWhileBlock);
        this->compiler->xModule->pushFunctionBlockBrInstruction(xBlock,
                                                                xWhileBlock);
        xBlock = xWhileExitBlock;
      } else if (childAstValue->kind == ast::KindIfNode) {
        return {
            CompilerError::fromASTValue(childAstValue, "NOT IMPLEMENTED IF")};
      } else if (childAstValue->kind == tsil::ast::KindReturnNode) {
        Type* type = nullptr;
        x::Value* xValue = nullptr;
        if (childAstValue->data.ReturnNode->value) {
          const auto valueResult = this->compileValue(
              xFunction, xBlock, childAstValue->data.ReturnNode->value);
          if (valueResult.error) {
            return {valueResult.error};
          }
          type = valueResult.type;
          xValue = valueResult.xValue;
        } else {
          type = this->compiler->voidType;
        }
        if (type != diiaType->diiaReturnType) {
          return {CompilerError::typesAreNotCompatible(
              childAstValue->data.ReturnNode->value, type,
              diiaType->diiaReturnType)};
        }
        if (type != this->compiler->voidType && xValue) {
          this->compiler->xModule->pushFunctionBlockStoreInstruction(
              xBlock, type->xType, xValue, xFunction->return_alloca);
        }
        this->compiler->xModule->pushFunctionBlockBrInstruction(
            xBlock, xFunction->exit_block);
      } else {
        return {CompilerError::fromASTValue(childAstValue,
                                            "NOT IMPLEMENTED OTHER")};
      }
      childIndex++;
    }
    if (xBlock != originalXBlock) {
      this->compiler->xModule->pushFunctionBlockBrInstruction(xBlock,
                                                              xExitBlock);
    }
    return {nullptr};
  }

  BakedDiiaResult Scope::bakeDiia(ast::ASTValue* fromAstValue,
                                  ast::ASTValue* diiaAstValue,
                                  const std::vector<Type*>& genericValues) {
    const auto diiaScope = new Scope(this->compiler, this);
    const auto compileDiiaHeadNode =
        [&fromAstValue, &diiaAstValue, &genericValues,
         &diiaScope](ast::DiiaHeadNode* diiaHeadNode)
        -> std::pair<Type*, CompilerError*> {
      if (genericValues.size() != diiaHeadNode->generic_definitions.size()) {
        const auto compilerError = CompilerError::fromASTValue(
            fromAstValue, "Кількість параметрів шаблону дії не співпадає");
        if (fromAstValue != diiaAstValue) {
          compilerError->secondError = new SecondCompilerError(
              diiaAstValue->start_line, diiaAstValue->start_column);
        }
        return {nullptr, compilerError};
      }
      int genericIndex = 0;
      for (const auto& genericDefinition : diiaHeadNode->generic_definitions) {
        const auto genericType = genericValues[genericIndex];
        diiaScope->bakedTypes[{genericDefinition, {}}] = genericType;
        genericIndex++;
      }
      const auto diiaType = new Type();
      diiaType->type = TypeTypeDiia;
      diiaType->name = diiaHeadNode->id;
      diiaType->diiaIsExtern = diiaHeadNode->is_extern;
      diiaType->diiaIsVariadic = diiaHeadNode->is_variadic;
      diiaType->diiaReturnType = diiaScope->compiler->voidType;
      for (const auto& paramAstValue : diiaHeadNode->params) {
        const auto paramNode = paramAstValue->data.ParamNode;
        const auto paramTypeResult = diiaScope->bakeType(paramNode->type);
        if (!paramTypeResult.type) {
          const auto compilerError = CompilerError::fromASTValue(
              paramNode->type, paramTypeResult.error);
          if (fromAstValue != diiaAstValue) {
            compilerError->secondError = new SecondCompilerError(
                fromAstValue->start_line, fromAstValue->start_column);
          }
          return {nullptr, compilerError};
        }
        const auto paramXValue = new x::Value(
            paramTypeResult.type->xType,
            "%arg." + std::to_string(
                          diiaScope->compiler->xModule->variable_counter++));
        diiaType->diiaParameters.push_back(
            TypeDiiaParameter{.name = paramNode->id,
                              .type = paramTypeResult.type,
                              .xValue = paramXValue});
        diiaScope->variables[paramNode->id] = {paramTypeResult.type,
                                               paramXValue};
      }
      if (diiaHeadNode->type) {
        const auto diiaResultTypeResult =
            diiaScope->bakeType(diiaHeadNode->type);
        if (!diiaResultTypeResult.type) {
          const auto compilerError = CompilerError::fromASTValue(
              diiaHeadNode->type, diiaResultTypeResult.error);
          if (fromAstValue != diiaAstValue) {
            compilerError->secondError = new SecondCompilerError(
                fromAstValue->start_line, fromAstValue->start_column);
          }
          return {nullptr, compilerError};
        }
        diiaType->diiaReturnType = diiaResultTypeResult.type;
      }
      return {diiaType, nullptr};
    };
    Type* diiaType;
    if (diiaAstValue->kind == ast::KindDiiaDeclarationNode) {
      const auto diiaHeadNode = diiaAstValue->data.DiiaDeclarationNode->head;
      const auto diiaHeadResult = compileDiiaHeadNode(diiaHeadNode);
      if (diiaHeadResult.second) {
        if (fromAstValue != diiaAstValue) {
          diiaHeadResult.second->secondError = new SecondCompilerError(
              fromAstValue->start_line, fromAstValue->start_column);
        }
        return {nullptr, nullptr, diiaHeadResult.second};
      }
      diiaType = diiaHeadResult.first;
    }
    if (diiaAstValue->kind == ast::KindDiiaNode) {
      const auto diiaHeadNode = diiaAstValue->data.DiiaDeclarationNode->head;
      const auto diiaHeadResult = compileDiiaHeadNode(diiaHeadNode);
      if (diiaHeadResult.second) {
        if (fromAstValue != diiaAstValue) {
          diiaHeadResult.second->secondError = new SecondCompilerError(
              fromAstValue->start_line, fromAstValue->start_column);
        }
        return {nullptr, nullptr, diiaHeadResult.second};
      }
      diiaType = diiaHeadResult.first;
    }
    std::vector<x::Value*> xParamTypes;
    for (const auto& param : diiaType->diiaParameters) {
      xParamTypes.push_back(param.xValue);
    }
    x::Type* xReturnType = diiaScope->compiler->xModule->voidType;
    if (diiaType->diiaReturnType) {
      xReturnType = diiaType->diiaReturnType->xType;
    }
    const auto& [xFunction, functionXValue] =
        diiaScope->compiler->xModule->declareFunction(diiaType->name,
                                                      xReturnType, xParamTypes);
    if (diiaAstValue->kind == ast::KindDiiaDeclarationNode) {
      if (diiaAstValue->data.DiiaDeclarationNode->as.empty()) {
        diiaScope->compiler->globalScope
            ->bakedDiias[{diiaType->name, genericValues}] = {diiaType,
                                                             functionXValue};
      } else {
        diiaScope->compiler->globalScope->bakedDiias[{
            diiaAstValue->data.DiiaDeclarationNode->as, genericValues}] = {
            diiaType, functionXValue};
      }
    }
    if (diiaAstValue->kind == ast::KindDiiaNode) {
      diiaScope->compiler->globalScope
          ->bakedDiias[{diiaType->name, genericValues}] = {diiaType,
                                                           functionXValue};
      xFunction->entry_block =
          diiaScope->compiler->xModule->defineFunctionBlock(xFunction, "entry");
      if (xFunction->result_type) {
        if (xFunction->result_type != diiaScope->compiler->xModule->voidType) {
          xFunction->return_alloca =
              diiaScope->compiler->xModule->pushFunctionBlockAllocaInstruction(
                  xFunction->entry_block, xFunction->result_type);
        }
      }
      xFunction->exit_block =
          diiaScope->compiler->xModule->defineFunctionBlock(xFunction, "exit");
      if (xFunction->return_alloca) {
        const auto returnLoadXValue =
            diiaScope->compiler->xModule->pushFunctionBlockLoadInstruction(
                xFunction->exit_block, xFunction->result_type,
                xFunction->return_alloca);
        diiaScope->compiler->xModule->pushFunctionBlockRetInstruction(
            xFunction->exit_block, xFunction->result_type, returnLoadXValue);
      } else {
        diiaScope->compiler->xModule->pushFunctionBlockRetInstruction(
            xFunction->exit_block, diiaScope->compiler->xModule->voidType,
            nullptr);
      }
      for (const auto& diiaParameter : diiaType->diiaParameters) {
        const auto allocXValue =
            diiaScope->compiler->xModule->pushFunctionBlockAllocaInstruction(
                xFunction->entry_block, diiaParameter.type->xType);
        diiaScope->compiler->xModule->pushFunctionBlockStoreInstruction(
            xFunction->entry_block, diiaParameter.type->xType,
            diiaParameter.xValue, allocXValue);
        diiaScope->variables[diiaParameter.name] = {diiaParameter.type,
                                                    allocXValue};
      }
      const auto bodyResult = diiaScope->compileDiiaBody(
          diiaType, xFunction, xFunction->entry_block, xFunction->exit_block,
          diiaAstValue->data.DiiaNode->body);
      if (bodyResult.error) {
        if (fromAstValue != diiaAstValue) {
          bodyResult.error->secondError = new SecondCompilerError(
              fromAstValue->start_line, fromAstValue->start_column);
        }
        return {nullptr, nullptr, bodyResult.error};
      }
      this->compiler->xModule->pushFunctionBlockBrInstruction(
          xFunction->entry_block, xFunction->exit_block);
    }
    return {diiaType, functionXValue, nullptr};
  }

  BakedTypeResult Scope::bakeType(ast::ASTValue* astValue) {
    if (astValue->kind == ast::KindTypeNode) {
      const auto typeNode = astValue->data.TypeNode;
      std::vector<Type*> genericValues;
      for (const auto& genericAstValue : typeNode->generics) {
        const auto genericTypeResult = this->bakeType(genericAstValue);
        if (!genericTypeResult.type) {
          return {nullptr, genericTypeResult.error};
        }
        genericValues.push_back(genericTypeResult.type);
      }
      if (this->hasBakedType(typeNode->id, genericValues)) {
        const auto type = this->getBakedType(typeNode->id, genericValues);
        return {type, ""};
      }
      if (typeNode->id == "комірка") {
        if (genericValues.empty()) {
          return {this->compiler->pointerType};
        }
        const auto type = genericValues[0]->getPointerType(this);
        return {type, ""};
      }
      if (this->hasRawType(typeNode->id)) {
        const auto rawType = this->getRawType(typeNode->id);
        if (rawType->kind == ast::KindStructureNode) {
          const auto structureNode = rawType->data.StructureNode;
          if (structureNode->generic_definitions.size() !=
              genericValues.size()) {
            return {nullptr,
                    "Кількість параметрів шаблону структури не "
                    "співпадає з кількістю переданих параметрів"};
          }
          const auto scopeWithGenerics = new Scope(this->compiler, this);
          int genericIndex = 0;
          for (const auto& genericDefinition :
               structureNode->generic_definitions) {
            const auto genericType = genericValues[genericIndex];
            scopeWithGenerics->bakedTypes[{genericDefinition, {}}] =
                genericType;
            genericIndex++;
          }
          const auto type = new Type();
          type->type = TypeTypeStructureInstance;
          type->name = structureNode->name;
          type->genericValues = genericValues;
          scopeWithGenerics->compiler->globalScope->bakedTypes.insert_or_assign(
              {structureNode->name, genericValues}, type);
          std::vector<x::Type*> xFields(structureNode->params.size());
          int paramIndex = 0;
          for (const auto& paramAstValue : structureNode->params) {
            const auto paramNode = paramAstValue->data.ParamNode;
            const auto paramTypeResult =
                scopeWithGenerics->bakeType(paramNode->type);
            if (!paramTypeResult.type) {
              return {nullptr, paramTypeResult.error};
            }
            const auto field = TypeStructureField{
                .index = paramIndex,
                .type = paramTypeResult.type,
            };
            type->structureInstanceFields[paramNode->id] = field;
            xFields[paramIndex] = field.type->xType;
            paramIndex++;
          }
          type->xType = scopeWithGenerics->compiler->xModule->defineStructType(
              structureNode->name, xFields);
          return {type, ""};
        }
      }
    }
    return {nullptr, "NOT IMPLEMENTED BAKED TYPE"};
  }
} // namespace tsil::tk