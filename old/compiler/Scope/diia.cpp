#include "../tk.h"

namespace tsil::tk {
  BodyCompilerResult Scope::compileDiiaBody(
      Type* diiaType,
      tsil::x::Function* xFunction,
      tsil::x::FunctionBlock* xBlock,
      tsil::x::FunctionBlock* xExitBlock,
      const std::vector<ast::ASTValue*>& body) {
    if (body.empty()) {
      this->compiler->xModule->pushFunctionBlockBrInstruction(xBlock,
                                                              xExitBlock);
      return {nullptr};
    }
    const auto deferXBlock = this->compiler->xModule->createFunctionBlock(
        xFunction, "exitWithDefer");
    int childIndex = 0;
    for (const auto& childAstValue : body) {
      if (childAstValue == nullptr) {
        continue;
      }
      if (childAstValue->kind == tsil::ast::KindNone) {
        continue;
      }
      if (childAstValue->kind == tsil::ast::KindBlockNode) {
        const auto xBlockBodyBlock =
            this->compiler->xModule->defineFunctionBlock(xFunction,
                                                         "block_body");
        const auto xBlockExitBlock =
            this->compiler->xModule->defineFunctionBlock(xFunction,
                                                         "block_exit");
        const auto blockScope = new Scope(this->compiler, this);
        const auto blockResult = blockScope->compileDiiaBody(
            diiaType, xFunction, xBlockBodyBlock, xBlockExitBlock,
            childAstValue->data.BlockNode->body);
        if (blockResult.error) {
          return {nullptr, nullptr, blockResult.error};
        }
        this->compiler->xModule->pushFunctionBlockBrInstruction(
            xBlockBodyBlock, xBlockExitBlock);
        this->compiler->xModule->pushFunctionBlockBrInstruction(
            xBlock, xBlockBodyBlock);
        xBlock = xBlockExitBlock;
      } else if (childAstValue->kind == tsil::ast::KindSynonymNode) {
        const auto result = this->compileSynonym(childAstValue);
        if (result.error) {
          return {nullptr, nullptr, result.error};
        }
      } else if (childAstValue->kind == ast::KindDefineNode) {
        const auto defineNode = childAstValue->data.DefineNode;
        if (this->hasLocalSubject(defineNode->id)) {
          return {nullptr, nullptr,
                  CompilerError::subjectAlreadyDefined(childAstValue)};
        }
        Type* type = nullptr;
        if (defineNode->type) {
          const auto typeResult = this->bakeType(defineNode->type);
          if (!typeResult.type) {
            return {nullptr, nullptr,
                    CompilerError::fromASTValue(defineNode->type,
                                                typeResult.error)};
          }
          type = typeResult.type;
        }
        if (defineNode->value) {
          auto valueResult = this->compileValueNoVariation(xFunction, xBlock,
                                                           defineNode->value);
          if (valueResult.error) {
            return {nullptr, nullptr, valueResult.error};
          }
          if (type) {
            const auto castedXValue = this->compileSoftCast(
                xFunction, xBlock, valueResult.type, valueResult.xValue, type);
            if (castedXValue) {
              valueResult.type = type;
              valueResult.xValue = castedXValue;
            } else {
              return {nullptr, nullptr,
                      CompilerError::typesAreNotCompatible(
                          defineNode->value, valueResult.type, type)};
            }
          } else {
            type = valueResult.type;
          }
          const auto allocaXValue =
              this->compiler->xModule->pushFunctionBlockAllocaInstruction(
                  xFunction->alloca_block, defineNode->id, type->xType);
          this->compiler->xModule->pushFunctionBlockStoreInstruction(
              xBlock, valueResult.type->xType, valueResult.xValue,
              allocaXValue);
          const auto variable = new Variable();
          variable->type = type;
          variable->xValue = allocaXValue;
          this->setSubject(defineNode->id, Subject{SubjectKindVariable,
                                                   {.variable = variable}});
        } else {
          const auto allocaXValue =
              this->compiler->xModule->pushFunctionBlockAllocaInstruction(
                  xFunction->alloca_block, defineNode->id, type->xType);
          const auto variable = new Variable();
          variable->type = type;
          variable->xValue = allocaXValue;
          this->setSubject(defineNode->id, Subject{SubjectKindVariable,
                                                   {.variable = variable}});
        }
      } else if (childAstValue->kind == ast::KindAssignNode) {
        const auto assignNode = childAstValue->data.AssignNode;
        if (this->hasSubject(assignNode->id)) {
          const auto subject = this->getSubject(assignNode->id);
          if (subject.kind == SubjectKindVariable) {
            const auto variable = subject.data.variable;
            const auto variableType = variable->type;
            const auto variableXValue = variable->xValue;
            auto valueResult = this->compileValueNoVariation(xFunction, xBlock,
                                                             assignNode->value);
            if (valueResult.error) {
              return {nullptr, nullptr, valueResult.error};
            }
            if (variableType->type == TypeTypeDiia) {
              return {nullptr, nullptr,
                      CompilerError::typesAreNotCompatible(
                          childAstValue, variableType, valueResult.type)};
            }
            const auto castedXValue =
                this->compileSoftCast(xFunction, xBlock, valueResult.type,
                                      valueResult.xValue, variableType);
            if (castedXValue) {
              valueResult.type = variableType;
              valueResult.xValue = castedXValue;
            } else {
              return {nullptr, nullptr,
                      CompilerError::typesAreNotCompatible(
                          childAstValue, valueResult.type, variableType)};
            }
            this->compiler->xModule->pushFunctionBlockStoreInstruction(
                xBlock, valueResult.type->xType, valueResult.xValue,
                variableXValue);
          } else {
            return {nullptr, nullptr,
                    CompilerError::cannotRedefineSubject(childAstValue,
                                                         assignNode->id)};
          }
        } else {
          return {nullptr, nullptr,
                  CompilerError::subjectNotDefined(childAstValue)};
        }
      } else if (childAstValue->kind == ast::KindSetNode) {
        const auto setResult =
            this->compileSet(xFunction, xBlock, childAstValue);
        if (setResult.error) {
          return {nullptr, nullptr, setResult.error};
        }
      } else if (childAstValue->kind == ast::KindCallNode) {
        const auto valueResult =
            this->compileValueNoVariation(xFunction, xBlock, childAstValue);
        if (valueResult.error) {
          return {nullptr, nullptr, valueResult.error};
        }
      } else if (childAstValue->kind == ast::KindWhileNode) {
        const auto xWhileBlock =
            this->compiler->xModule->defineFunctionBlock(xFunction, "while");
        const auto xWhileBodyBlock =
            this->compiler->xModule->defineFunctionBlock(xFunction,
                                                         "while_body");
        const auto xWhileExitBlock =
            this->compiler->xModule->defineFunctionBlock(xFunction,
                                                         "while_exit");
        auto valueResult = this->compileValueNoVariation(
            xFunction, xWhileBlock, childAstValue->data.WhileNode->condition);
        if (valueResult.error) {
          return {nullptr, nullptr, valueResult.error};
        }
        const auto castedXValue = this->compileSoftCast(
            xFunction, xWhileBlock, valueResult.type, valueResult.xValue,
            this->compiler->uint1Type);
        if (castedXValue) {
          valueResult.type = this->compiler->uint1Type;
          valueResult.xValue = castedXValue;
        } else {
          return {nullptr, nullptr,
                  CompilerError::typesAreNotCompatible(
                      childAstValue->data.WhileNode->condition,
                      valueResult.type, this->compiler->uint1Type)};
        }
        this->compiler->xModule->pushFunctionBlockBrIfInstruction(
            xWhileBlock, valueResult.xValue, xWhileBodyBlock, xWhileExitBlock);
        const auto whileScope = new Scope(this->compiler, this);
        const auto whileBodyResult = whileScope->compileDiiaBody(
            diiaType, xFunction, xWhileBodyBlock, xWhileBlock,
            childAstValue->data.WhileNode->body);
        if (whileBodyResult.error) {
          return {nullptr, nullptr, whileBodyResult.error};
        }
        this->compiler->xModule->pushFunctionBlockBrInstruction(xBlock,
                                                                xWhileBlock);
        xBlock = xWhileExitBlock;
      } else if (childAstValue->kind == ast::KindIfNode) {
        const auto xIfBlock =
            this->compiler->xModule->defineFunctionBlock(xFunction, "if");
        const auto xIfThenBlock =
            this->compiler->xModule->defineFunctionBlock(xFunction, "if_then");
        const auto xIfElseBlock =
            this->compiler->xModule->defineFunctionBlock(xFunction, "if_else");
        const auto xIfExitBlock =
            this->compiler->xModule->defineFunctionBlock(xFunction, "if_exit");
        auto valueResult = this->compileValueNoVariation(
            xFunction, xIfBlock, childAstValue->data.IfNode->condition);
        if (valueResult.error) {
          return {nullptr, nullptr, valueResult.error};
        }
        const auto castedXValue = this->compileSoftCast(
            xFunction, xIfBlock, valueResult.type, valueResult.xValue,
            this->compiler->uint1Type);
        if (castedXValue) {
          valueResult.type = this->compiler->uint1Type;
          valueResult.xValue = castedXValue;
        } else {
          return {nullptr, nullptr,
                  CompilerError::typesAreNotCompatible(
                      childAstValue->data.WhileNode->condition,
                      valueResult.type, this->compiler->uint1Type)};
        }
        this->compiler->xModule->pushFunctionBlockBrIfInstruction(
            xIfBlock, valueResult.xValue, xIfThenBlock, xIfElseBlock);
        const auto thenScope = new Scope(this->compiler, this);
        const auto thenBodyResult = thenScope->compileDiiaBody(
            diiaType, xFunction, xIfThenBlock, xIfExitBlock,
            childAstValue->data.IfNode->body);
        if (thenBodyResult.error) {
          return {nullptr, nullptr, thenBodyResult.error};
        }
        const auto elseScope = new Scope(this->compiler, this);
        const auto elseBodyResult = elseScope->compileDiiaBody(
            diiaType, xFunction, xIfElseBlock, xIfExitBlock,
            childAstValue->data.IfNode->else_body);
        if (elseBodyResult.error) {
          return {nullptr, nullptr, elseBodyResult.error};
        }
        this->compiler->xModule->pushFunctionBlockBrInstruction(xBlock,
                                                                xIfBlock);
        xBlock = xIfExitBlock;
      } else if (childAstValue->kind == tsil::ast::KindReturnNode) {
        Type* type = nullptr;
        x::Value* xValue = nullptr;
        if (childAstValue->data.ReturnNode->value) {
          const auto valueResult = this->compileValueNoVariation(
              xFunction, xBlock, childAstValue->data.ReturnNode->value);
          if (valueResult.error) {
            return {nullptr, nullptr, valueResult.error};
          }
          type = valueResult.type;
          xValue = valueResult.xValue;
        } else {
          type = this->compiler->voidType;
        }
        const auto castedXValue = this->compileSoftCast(
            xFunction, xBlock, type, xValue, diiaType->diiaReturnType);
        if (castedXValue) {
          type = diiaType->diiaReturnType;
          xValue = castedXValue;
        } else {
          return {nullptr, nullptr,
                  CompilerError::typesAreNotCompatible(
                      childAstValue->data.ReturnNode->value, type,
                      diiaType->diiaReturnType)};
        }
        if (!type->equals(this->compiler->voidType) && xValue) {
          this->compiler->xModule->pushFunctionBlockStoreInstruction(
              xBlock, type->xType, xValue, xFunction->return_alloca);
        }
        this->compiler->xModule->pushFunctionBlockBrInstruction(
            xBlock, xFunction->exit_block);
      } else if (childAstValue->kind == tsil::ast::KindDeferNode) {
        const auto deferNode = childAstValue->data.DeferNode;
        const auto valueResult = this->compileValueNoVariation(
            xFunction, deferXBlock, deferNode->value);
        if (valueResult.error) {
          return {nullptr, nullptr, valueResult.error};
        }
      } else {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(childAstValue,
                                            "NOT IMPLEMENTED OTHER")};
      }
      childIndex++;
    }
    std::vector<x::FunctionInstruction*> newExitBlockInstructions;
    for (const auto deferInstruction : deferXBlock->instructions) {
      newExitBlockInstructions.push_back(deferInstruction);
    }
    for (const auto exitBlockInstruction : xExitBlock->instructions) {
      newExitBlockInstructions.push_back(exitBlockInstruction);
    }
    xExitBlock->instructions = newExitBlockInstructions;
    this->compiler->xModule->pushFunctionBlockBrInstruction(xBlock, xExitBlock);
    return {xBlock, nullptr};
  }
} // namespace tsil::tk