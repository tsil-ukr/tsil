#include "../compiler.h"

namespace tsil::compiler {
  llvm::AllocaInst* CompilationScope::createEntryBlockAlloca(
      llvm::Type* T,
      llvm::Function* F,
      const std::string& varName) {
    llvm::IRBuilder<> TmpB(&F->getEntryBlock(), F->getEntryBlock().begin());
    return TmpB.CreateAlloca(T, nullptr, varName);
  }

  CompilerValueResult CompilationScope::compile_define_node(
      tsil::ast::ASTValue* ast_value) {
    const auto define_node = ast_value->data.DefineNode;
    if (this->has_variable(define_node->id) ||
        this->has_diia(define_node->id) || this->has_type(define_node->id) ||
        this->has_structure(define_node->id)) {
      return {
          nullptr, nullptr,
          new CompilerError("Ціль \"" + define_node->id + "\" вже визначена")};
    }
    const auto value_result = this->compile_ast_value(define_node->value);
    if (value_result.error) {
      return value_result;
    }
    llvm::Function* F = this->state->Builder->GetInsertBlock()->getParent();
    llvm::AllocaInst* LAI =
        this->createEntryBlockAlloca(value_result.type->LT, F, define_node->id);
    this->state->Builder->CreateStore(value_result.LV, LAI);
    this->set_variable(define_node->id, {value_result.type, LAI});
    return value_result;
  }
} // namespace tsil::compiler