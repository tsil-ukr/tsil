#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compile_define_node(
      tsil::ast::ASTValue* ast_value) {
    const auto define_node = ast_value->data.DefineNode;
    if (this->has_variable(define_node->id)) {
      return {new CompilerError("Субʼєкт \"" + define_node->id +
                                "\" вже визначено")};
    }
    if (this->state->structures.contains(define_node->id)) {
      return {new CompilerError("Субʼєкт \"" + define_node->id +
                                "\" вже визначено")};
    }
    Type* type = nullptr;
    if (define_node->type) {
      const auto type_result =
          this->makeTypeFromTypeNodeASTValue(define_node->type);
      if (!type_result.type) {
        return {new CompilerError(type_result.error)};
      }
      type = type_result.type;
    }
    if (define_node->value) {
      auto value_result = this->compile_ast_value(define_node->value);
      if (value_result.error) {
        return {value_result.error};
      }
      if (type) {
        if (value_result.type != type) {
          return {new CompilerError(
              "Тип \"" + value_result.type->getFullName() +
              "\" не сумісний з типом \"" + type->getFullName() + "\"")};
        }
      } else {
        type = value_result.type;
      }
      llvm::Function* LF = this->state->Builder->GetInsertBlock()->getParent();
      llvm::AllocaInst* LAI = this->createEntryBlockAlloca(type->LT, LF);
      this->state->Builder->CreateStore(value_result.LV, LAI);
      this->set_variable(define_node->id, {type, LAI});
    } else {
      llvm::Function* LF = this->state->Builder->GetInsertBlock()->getParent();
      llvm::AllocaInst* LAI = this->createEntryBlockAlloca(type->LT, LF);
      this->set_variable(define_node->id, {type, LAI});
    }
    return {nullptr};
  }
} // namespace tsil::compiler