#include "../compiler.h"

namespace tsil::compiler {
  CompilerResult CompilationScope::compile_call_node(
      tsil::ast::ASTValue* ast_value) {
    const auto call_node = ast_value->data.CallNode;
    const auto name = call_node->value->data.IdentifierNode->name;
    llvm::Function* F = this->get_variable(name)->as_function();
    if (!F) {
      return error("Unknown function referenced: " + name);
    }
    if (!F->isVarArg()) {
      if (F->arg_size() != call_node->args.size()) {
        return error("Incorrect # arguments passed");
      }
    }
    std::vector<llvm::Value*> ArgsV;
    for (const auto& arg : call_node->args) {
      auto arg_result = this->compile_ast_value(arg);
      if (arg_result.error) {
        return arg_result;
      }
      ArgsV.push_back(arg_result.result->llval);
    }
    if (F->getReturnType() == llvm::Type::getVoidTy(*this->state->Context)) {
      const auto llval = this->state->Builder->CreateCall(F, ArgsV);
      return ok(llval, nullptr);
    }
    const auto llval = this->state->Builder->CreateCall(F, ArgsV, "calltmp");
    return ok(llval, nullptr);
  }
} // namespace tsil::compiler