#include <llvm/IR/Value.h>
#include "../parser/parser.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/TargetParser/Host.h"

namespace tsil::compiler {
  struct CompilationScope;

  struct Type {
    llvm::Type* lltype;
  };

  struct Value {
    llvm::Value* llval;
    Type* type;

    inline llvm::Function* as_function() {
      return llvm::cast<llvm::Function>(this->llval);
    }
  };

  struct CompilerError {
    std::string message;
  };

  struct CompilerResult {
    Value* result;
    CompilerError* error;
  };

  CompilerResult ok(llvm::Value* llval, Type* type);
  CompilerResult error(const std::string& message);

  struct CompilationState {
    llvm::LLVMContext* Context;
    llvm::Module* Module;
    llvm::IRBuilder<>* Builder;
    CompilationScope* globalScope;
  };

  struct CompilationScope {
    CompilationScope* parent;
    CompilationState* state;
    std::map<std::string, Value*> variables;
    std::map<std::string, Type*> types;

    inline bool has_variable(const std::string& name) const {
      if (this->variables.contains(name)) {
        return true;
      }
      if (this->parent) {
        return this->parent->has_variable(name);
      }
      return false;
    }

    inline Value* get_variable(const std::string& name) {
      if (this->variables.contains(name)) {
        return this->variables[name];
      }
      if (this->parent) {
        return this->parent->get_variable(name);
      }
      return nullptr;
    }

    inline void set_variable(const std::string& name, Value* value) {
      this->variables.insert_or_assign(name, value);
    }

    inline Type* get_type(tsil::ast::TypeNode* type_node) {
      const auto name = type_node->id;
      if (this->types.contains(name)) {
        return this->types[name];
      }
      return nullptr;
    }

    CompilerResult compile_ast_value(tsil::ast::ASTValue* ast_value);
    CompilerResult compile_call_node(tsil::ast::ASTValue* ast_value);
    CompilerResult compile_number_node(tsil::ast::ASTValue* ast_value);
    CompilerResult compile_define_node(tsil::ast::ASTValue* ast_value);
    CompilerResult compile_string_node(tsil::ast::ASTValue* ast_value);
    CompilerResult compile_identifier_node(tsil::ast::ASTValue* ast_value);
    CompilerResult compile_diia_head_node(
        tsil::ast::DiiaHeadNode* diia_head_node);
    CompilerResult compile_diia_node(tsil::ast::ASTValue* ast_value);
    CompilerResult compile_diia_declaration_node(
        tsil::ast::ASTValue* ast_value);
  };
} // namespace tsil::compiler