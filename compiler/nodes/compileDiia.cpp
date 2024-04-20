#include "../compiler.h"

namespace tsil::compiler {
  CompilerDiiaResult CompilationScope::compileDiiaHead(
      tsil::ast::ASTValue* astValue,
      tsil::ast::DiiaHeadNode* diiaHeadNode) {
    const auto diiaType = new Type();
    diiaType->type = TypeTypeDiia;
    diiaType->name = diiaHeadNode->id;
    diiaType->diia_is_extern = diiaHeadNode->is_extern;
    diiaType->diia_is_variadic = diiaHeadNode->is_variadic;
    diiaType->diia_result_type = this->state->voidType;
    for (const auto& paramAstValue : diiaHeadNode->params) {
      const auto paramNode = paramAstValue->data.ParamNode;
      const auto paramTypeResult =
          this->makeTypeFromTypeNodeASTValue(paramNode->type);
      if (!paramTypeResult.type) {
        return {
            nullptr, nullptr, nullptr,
            CompilerError::fromASTValue(paramAstValue, paramTypeResult.error)};
      }
      const auto paramXValue = new x::Value(
          paramTypeResult.type->LT,
          "%arg." + std::to_string(this->state->Module->variable_counter++));
      diiaType->diia_parameters.push_back(
          TypeDiiaParameter{.name = paramNode->id,
                            .type = paramTypeResult.type,
                            .xValue = paramXValue});
    }
    if (diiaHeadNode->type) {
      const auto diiaResultTypeResult =
          this->makeTypeFromTypeNodeASTValue(diiaHeadNode->type);
      if (!diiaResultTypeResult.type) {
        return {nullptr, nullptr, nullptr,
                CompilerError::fromASTValue(diiaHeadNode->type,
                                            diiaResultTypeResult.error)};
      }
      diiaType->diia_result_type = diiaResultTypeResult.type;
    }
    std::vector<x::Value*> xParamTypes;
    for (const auto& param : diiaType->diia_parameters) {
      xParamTypes.push_back(param.xValue);
    }
    x::Type* xResultType = this->state->Module->voidType;
    if (diiaType->diia_result_type) {
      xResultType = diiaType->diia_result_type->LT;
    }
    const auto& [xFunction, functionXValue] =
        this->state->Module->declareFunction(diiaType->name, xResultType,
                                             xParamTypes);
    this->setVariable(diiaType->name, {diiaType, functionXValue});
    return {diiaType, xFunction, functionXValue, nullptr};
  }

  CompilerResult CompilationScope::compileDiiaBody(
      Type* diiaType,
      tsil::x::Function* xFunction,
      tsil::x::FunctionBlock* xBlock,
      tsil::x::FunctionBlock* xExitBlock,
      const std::vector<ast::ASTValue*>& body) {
    int childIndex = 0;
    for (const auto& childAstValue : body) {
      if (childAstValue == nullptr) {
        continue;
      }
      if (childAstValue->kind == tsil::ast::KindNone) {
        continue;
      }
      if (childAstValue->kind == ast::KindDefineNode) {
        const auto defineResult =
            this->compileDefine(xFunction, xBlock, childAstValue);
        if (defineResult.error) {
          return {defineResult.error};
        }
      } else if (childAstValue->kind == ast::KindAssignNode) {
        const auto assignResult =
            this->compileAssign(xFunction, xBlock, childAstValue);
        if (assignResult.error) {
          return {assignResult.error};
        }
      } else if (childAstValue->kind == ast::KindSetNode) {
        const auto setResult =
            this->compileSet(xFunction, xBlock, childAstValue);
        if (setResult.error) {
          return {setResult.error};
        }
      } else if (childAstValue->kind == ast::KindWhileNode) {
        const auto xWhileBlock =
            this->state->Module->defineFunctionBlock(xFunction, "while");
        const auto xWhileBodyBlock =
            this->state->Module->defineFunctionBlock(xFunction, "while_body");
        const auto xWhileExitBlock =
            childIndex == body.size() - 1
                ? xExitBlock
                : this->state->Module->defineFunctionBlock(xFunction,
                                                           "while_exit");

        const auto valueResult = this->compileValue(
            xFunction, xWhileBlock, childAstValue->data.WhileNode->condition);
        if (valueResult.error) {
          return {valueResult.error};
        }
        this->state->Module->pushFunctionBlockBrIfInstruction(
            xWhileBlock, valueResult.LV, xWhileBodyBlock, xWhileExitBlock);

        const auto whileBodyResult = this->compileDiiaBody(
            diiaType, xFunction, xWhileBodyBlock, xWhileExitBlock,
            childAstValue->data.WhileNode->body);
        if (whileBodyResult.error) {
          return {whileBodyResult.error};
        }
        this->state->Module->pushFunctionBlockBrInstruction(xWhileBodyBlock,
                                                            xWhileBlock);

        this->state->Module->pushFunctionBlockBrInstruction(xBlock,
                                                            xWhileBlock);

        xBlock = xWhileExitBlock;
      } else if (childAstValue->kind == tsil::ast::KindReturnNode) {
        const auto valueResult = this->compileValue(
            xFunction, xBlock, childAstValue->data.ReturnNode->value);
        if (valueResult.error) {
          return {valueResult.error};
        }
        if (valueResult.type != diiaType->diia_result_type) {
          return {
              CompilerError::fromASTValue(childAstValue->data.ReturnNode->value,
                                          "Невірний тип результату дії \"" +
                                              diiaType->getFullName() + "\"")};
        }
        this->state->Module->pushFunctionBlockStoreInstruction(
            xBlock, valueResult.type->LT, valueResult.LV,
            xFunction->return_alloca);
        this->state->Module->pushFunctionBlockBrInstruction(
            xBlock, xFunction->exit_block);
        break;
      } else {
        const auto result =
            this->compileValue(xFunction, xBlock, childAstValue);
        if (result.error) {
          return {result.error};
        }
      }
      childIndex++;
    }
    return {nullptr};
  }

  CompilerDiiaResult CompilationScope::compileDiia(
      tsil::ast::ASTValue* astValue) {
    const auto diiaNode = astValue->data.DiiaNode;
    if (this->state->predefined_types.contains(diiaNode->head->id)) {
      return {nullptr, nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue,
                  "Субʼєкт \"" + diiaNode->head->id + "\" вже визначено")};
    }
    if (this->state->structures.contains(diiaNode->head->id)) {
      return {nullptr, nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue,
                  "Субʼєкт \"" + diiaNode->head->id + "\" вже визначено")};
    }
    if (this->hasVariable(diiaNode->head->id)) {
      return {nullptr, nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue,
                  "Субʼєкт \"" + diiaNode->head->id + "\" вже визначено")};
    }
    const auto diiaHeadResult = this->compileDiiaHead(astValue, diiaNode->head);
    if (diiaHeadResult.error) {
      return diiaHeadResult;
    }
    const auto diiaType = diiaHeadResult.type;
    const auto xFunction = diiaHeadResult.LF;
    const auto diiaScope = new CompilationScope(this, this->state);

    xFunction->entry_block =
        diiaScope->state->Module->defineFunctionBlock(xFunction, "entry");
    if (xFunction->result_type) {
      if (xFunction->result_type != diiaScope->state->Module->voidType) {
        xFunction->return_alloca =
            diiaScope->state->Module->pushFunctionBlockAllocaInstruction(
                xFunction->entry_block, xFunction->result_type);
      }
    }
    xFunction->exit_block =
        diiaScope->state->Module->defineFunctionBlock(xFunction, "exit");
    if (xFunction->return_alloca) {
      const auto returnLoadXValue =
          diiaScope->state->Module->pushFunctionBlockLoadInstruction(
              xFunction->exit_block, xFunction->result_type,
              xFunction->return_alloca);
      diiaScope->state->Module->pushFunctionBlockRetInstruction(
          xFunction->exit_block, xFunction->result_type, returnLoadXValue);
    } else {
      diiaScope->state->Module->pushFunctionBlockRetInstruction(
          xFunction->exit_block, diiaScope->state->Module->voidType, nullptr);
    }

    for (const auto& diiaParameter : diiaType->diia_parameters) {
      const auto allocXValue =
          diiaScope->state->Module->pushFunctionBlockAllocaInstruction(
              xFunction->entry_block, diiaParameter.type->LT);
      diiaScope->state->Module->pushFunctionBlockStoreInstruction(
          xFunction->entry_block, diiaParameter.type->LT, diiaParameter.xValue,
          allocXValue);
      diiaScope->setVariable(diiaParameter.name,
                             {diiaParameter.type, allocXValue});
    }

    const auto bodyResult =
        diiaScope->compileDiiaBody(diiaType, xFunction, xFunction->entry_block,
                                   xFunction->exit_block, diiaNode->body);
    if (bodyResult.error) {
      return {nullptr, nullptr, nullptr, bodyResult.error};
    }

    return diiaHeadResult;
  }

  CompilerDiiaResult CompilationScope::compileDiiaDeclaration(
      tsil::ast::ASTValue* astValue) {
    const auto diiaDeclarationNode = astValue->data.DiiaDeclarationNode;
    if (this->state->predefined_types.contains(diiaDeclarationNode->head->id)) {
      return {nullptr, nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue, "Субʼєкт \"" + diiaDeclarationNode->head->id +
                                "\" вже визначено")};
    }
    if (this->state->structures.contains(diiaDeclarationNode->head->id)) {
      return {nullptr, nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue, "Субʼєкт \"" + diiaDeclarationNode->head->id +
                                "\" вже визначено")};
    }
    if (this->hasVariable(diiaDeclarationNode->head->id)) {
      return {nullptr, nullptr, nullptr,
              CompilerError::fromASTValue(
                  astValue, "Субʼєкт \"" + diiaDeclarationNode->head->id +
                                "\" вже визначено")};
    }
    const auto diiaHeadResult =
        this->compileDiiaHead(astValue, diiaDeclarationNode->head);
    if (!diiaDeclarationNode->as.empty()) {
      this->setVariable(diiaDeclarationNode->as,
                        {diiaHeadResult.type, diiaHeadResult.LV});
    }
    return diiaHeadResult;
  }
} // namespace tsil::compiler