#include "../tk.h"

namespace tsil::tk {
  BodyCompilerResult Scope::compileDiiaBody(
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
    std::vector<std::pair<x::FunctionBlock*, x::FunctionBlock*>> exits;
    for (const auto& childAstValue : body) {
      if (childAstValue == nullptr) {
        continue;
      }
      if (childAstValue->kind == tsil::ast::KindNone) {
        continue;
      }
      if (childAstValue->kind == tsil::ast::KindBlockNode) {
        const auto blockScope = new Scope(this->compiler, this);
        const auto blockResult =
            blockScope->compileDiiaBody(diiaType, xFunction, xBlock, xExitBlock,
                                        childAstValue->data.BlockNode->body);
        if (blockResult.error) {
          return {nullptr, nullptr, blockResult.error};
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
          auto valueResult =
              this->compileValue(xFunction, xBlock, defineNode->value);
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
                  xBlock, defineNode->id, type->xType);
          this->compiler->xModule->pushFunctionBlockStoreInstruction(
              xBlock, valueResult.type->xType, valueResult.xValue,
              allocaXValue);
          this->variables[defineNode->id] = {type, allocaXValue};
        } else {
          const auto allocaXValue =
              this->compiler->xModule->pushFunctionBlockAllocaInstruction(
                  xBlock, defineNode->id, type->xType);
          this->variables[defineNode->id] = {type, allocaXValue};
        }
      } else if (childAstValue->kind == ast::KindAssignNode) {
        const auto assignNode = childAstValue->data.AssignNode;
        if (!this->hasVariable(assignNode->id)) {
          return {nullptr, nullptr,
                  CompilerError::cannotRedefineSubject(childAstValue,
                                                       assignNode->id)};
        }
        const auto& [variableType, variableXValue] =
            this->getVariable(assignNode->id);
        const auto valueResult =
            this->compileValue(xFunction, xBlock, assignNode->value);
        if (valueResult.error) {
          return {nullptr, nullptr, valueResult.error};
        }
        if (variableType->type == TypeTypeDiia) {
          return {nullptr, nullptr,
                  CompilerError::typesAreNotCompatible(
                      childAstValue, variableType, valueResult.type)};
        }
        this->compiler->xModule->pushFunctionBlockStoreInstruction(
            xBlock, valueResult.type->xType, valueResult.xValue,
            variableXValue);
      } else if (childAstValue->kind == ast::KindSetNode) {
        const auto setResult =
            this->compileSet(xFunction, xBlock, childAstValue);
        if (setResult.error) {
          return {nullptr, nullptr, setResult.error};
        }
      } else if (childAstValue->kind == ast::KindCallNode) {
        const auto valueResult =
            this->compileValue(xFunction, xBlock, childAstValue);
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
        auto valueResult = this->compileValue(
            xFunction, xWhileBlock, childAstValue->data.WhileNode->condition);
        if (valueResult.error) {
          return {nullptr, nullptr, valueResult.error};
        }
        const auto castedXValue =
            this->compileSoftCast(xFunction, xWhileBlock, valueResult.type,
                                  valueResult.xValue, this->compiler->int1Type);
        if (castedXValue) {
          valueResult.type = this->compiler->int1Type;
          valueResult.xValue = castedXValue;
        } else {
          return {nullptr, nullptr,
                  CompilerError::typesAreNotCompatible(
                      childAstValue->data.WhileNode->condition,
                      valueResult.type, this->compiler->int1Type)};
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
        auto valueResult = this->compileValue(
            xFunction, xIfBlock, childAstValue->data.IfNode->condition);
        if (valueResult.error) {
          return {nullptr, nullptr, valueResult.error};
        }
        const auto castedXValue =
            this->compileSoftCast(xFunction, xIfBlock, valueResult.type,
                                  valueResult.xValue, this->compiler->int1Type);
        if (castedXValue) {
          valueResult.type = this->compiler->int1Type;
          valueResult.xValue = castedXValue;
        } else {
          return {nullptr, nullptr,
                  CompilerError::typesAreNotCompatible(
                      childAstValue->data.WhileNode->condition,
                      valueResult.type, this->compiler->int1Type)};
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
          const auto valueResult = this->compileValue(
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
      } else {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(childAstValue,
                                            "NOT IMPLEMENTED OTHER")};
      }
      childIndex++;
    }
    this->compiler->xModule->pushFunctionBlockBrInstruction(xBlock, xExitBlock);
    return {xBlock, nullptr};
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
      diiaType->xType = diiaScope->compiler->xModule->pointerType;
      diiaType->linkage = diiaHeadNode->linkage;
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
            diiaScope->compiler->xModule->computeNextVarName("arg"));
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
      if (diiaHeadNode->id == "main") {
        return {
            nullptr, nullptr,
            CompilerError::fromASTValue(
                diiaAstValue, "Неможливо визначити субʼєкт з назвою \"main\"")};
      }
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
      if (diiaHeadNode->id == "main") {
        return {
            nullptr, nullptr,
            CompilerError::fromASTValue(
                diiaAstValue, "Неможливо визначити субʼєкт з назвою \"main\"")};
      }
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
    struct CoercedParam {
      std::string name;
      Type* type;
      std::vector<x::Value*> params;
    };
    std::vector<CoercedParam> coercedParams;
    for (const auto& diiaParameter : diiaType->diiaParameters) {
      if (diiaParameter.type->type == TypeTypeStructureInstance && false) {
        CoercedParam coercedParam;
        coercedParam.name = diiaParameter.name;
        coercedParam.type = diiaParameter.type;
        for (const auto& [fieldName, field] :
             diiaParameter.type->structureInstanceFields) {
          const auto xValue =
              new x::Value(field.type->xType,
                           this->compiler->xModule->computeNextVarName(
                               "arg.coerce" + std::to_string(field.index)));
          xParamTypes.push_back(xValue);
          coercedParam.params.push_back(xValue);
        }
        coercedParams.push_back(coercedParam);
      } else {
        xParamTypes.push_back(diiaParameter.xValue);
      }
    }
    x::Type* xReturnType = diiaScope->compiler->xModule->voidType;
    if (diiaType->diiaReturnType) {
      xReturnType = diiaType->diiaReturnType->xType;
    }
    auto xFunctionName = diiaType->name == "старт" ? "main" : diiaType->name;
    auto xFunctionAttributes = "";
    if (diiaType->linkage == ast::DiiaLinkageExtern ||
        xFunctionName == "main") {
      xFunctionAttributes = "";
    } else if (diiaType->linkage == ast::DiiaLinkageStatic) {
      xFunctionName =
          diiaScope->compiler->xModule->computeNextName(diiaType->name);
      if (diiaAstValue->kind == ast::KindDiiaDeclarationNode) {
        return {nullptr, nullptr,
                CompilerError::fromASTValue(
                    diiaAstValue, "Внутрішня дія повинна мати тіло.")};
      }
      xFunctionAttributes = "internal";
    } else {
      xFunctionAttributes = "dso_local";
    }
    const auto& [xFunction, functionXValue] =
        diiaScope->compiler->xModule->declareFunction(
            xFunctionAttributes, xFunctionName, xReturnType, xParamTypes);
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
                  xFunction->entry_block, "return", xFunction->result_type);
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
        if (diiaParameter.type->type != TypeTypeStructureInstance || true) {
          const auto allocXValue =
              diiaScope->compiler->xModule->pushFunctionBlockAllocaInstruction(
                  xFunction->entry_block, diiaParameter.name,
                  diiaParameter.type->xType);
          diiaScope->compiler->xModule->pushFunctionBlockStoreInstruction(
              xFunction->entry_block, diiaParameter.type->xType,
              diiaParameter.xValue, allocXValue);
          diiaScope->variables[diiaParameter.name] = {diiaParameter.type,
                                                      allocXValue};
        }
      }
      for (const auto& coercedParam : coercedParams) {
        const auto allocXValue =
            diiaScope->compiler->xModule->pushFunctionBlockAllocaInstruction(
                xFunction->entry_block, coercedParam.name,
                coercedParam.type->xType);
        int index = 0;
        for (const auto& paramXValue : coercedParam.params) {
          const auto gepXValue =
              diiaScope->compiler->xModule
                  ->pushFunctionBlockGetElementPtrInstruction(
                      xFunction->entry_block, coercedParam.type->xType,
                      allocXValue,
                      {new x::Value(diiaScope->compiler->int32Type->xType, "0"),
                       new x::Value(diiaScope->compiler->int32Type->xType,
                                    std::to_string(index))});
          diiaScope->compiler->xModule->pushFunctionBlockStoreInstruction(
              xFunction->entry_block, paramXValue->type, paramXValue,
              gepXValue);
          index++;
        }
        diiaScope->variables[coercedParam.name] = {coercedParam.type,
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
    }
    return {diiaType, functionXValue, nullptr};
  }
} // namespace tsil::tk