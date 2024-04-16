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
  struct Type;
  struct Structure;
  struct CompilationState;
  struct CompilationScope;

  enum TypeType {
    TypeTypeNative,
    TypeTypeStructureInstance,
    TypeTypeDiia,
  };

  struct TypeStructureField {
    int index;
    Type* type;
  };

  struct TypeDiiaParameter {
    std::string name;
    Type* type;
  };

  struct Type {
    TypeType type;
    std::string name;
    // structure
    std::unordered_map<std::string, TypeStructureField>
        structure_instance_fields;
    // diia
    bool diia_is_extern;
    std::vector<TypeDiiaParameter> diia_parameters;
    bool diia_is_variadic;
    Type* diia_result_type;
    // llvm
    llvm::Type* LT;

    llvm::Value* castToLV(CompilationScope* scope,
                          Type* target_type,
                          llvm::Value* LV);
  };

  struct StructureField {
    int index;
    Type* type;
    int generic_type_index;
  };

  struct Structure {
    std::string name;
    std::vector<std::string> generic_definitions;
    std::map<std::string, StructureField> fields;
  };

  struct CompilerError {
    std::string message;
  };

  struct CompilerResult {
    CompilerError* error;
  };

  struct CompilerValueResult {
    Type* type;
    llvm::Value* LV;
    CompilerError* error;
  };

  struct CompilerDiiaResult {
    Type* type;
    llvm::Function* LF;
    CompilerError* error;
  };

  struct CompilerStructureResult {
    Structure* structure;
    CompilerError* error;
  };

  struct CompilationState {
    llvm::LLVMContext* Context;
    llvm::Module* Module;
    llvm::IRBuilder<>* Builder;
    CompilationScope* globalScope;
    std::map<std::string, Type*> types;
    std::map<std::string, Structure*> structures;
    std::map<std::pair<Structure*, std::vector<Type*>>, Type*> types_cache;

    Type* voidType = nullptr;
    Type* int8Type = nullptr;
    Type* int16Type = nullptr;
    Type* int32Type = nullptr;
    Type* int64Type = nullptr;
    Type* floatType = nullptr;
    Type* doubleType = nullptr;
    Type* uint8Type = nullptr;
    Type* uint16Type = nullptr;
    Type* uint32Type = nullptr;
    Type* uint64Type = nullptr;
    Type* textType = nullptr;
  };

  struct MakeTypeResult {
    Type* type;
    std::string error;
  };

  struct CompilationScope {
    CompilationScope* parent;
    CompilationState* state;
    std::map<std::string, std::pair<Type*, llvm::Value*>> variables;

    bool has_variable(const std::string& name) const;
    std::pair<Type*, llvm::Value*> get_variable(const std::string& name);
    void set_variable(const std::string& name,
                      std::pair<Type*, llvm::Value*> value);

    llvm::AllocaInst* createEntryBlockAlloca(llvm::Type* T, llvm::Function* F);

    MakeTypeResult makeType(const std::string& name,
                            std::vector<Type*> generic_values);
    MakeTypeResult makeTypeFromTypeNodeASTValue(tsil::ast::ASTValue* ast_value);

    Structure* createStructure(
        const std::string& name,
        const std::vector<std::string>& generic_definitions,
        const std::map<std::string, StructureField>& fields);

    CompilerValueResult compile_ast_value(tsil::ast::ASTValue* ast_value);
    CompilerValueResult compile_call_node(tsil::ast::ASTValue* ast_value);
    CompilerValueResult compile_identifier_node(tsil::ast::ASTValue* ast_value);
    CompilerValueResult compile_number_node(tsil::ast::ASTValue* ast_value);
    CompilerValueResult compile_string_node(tsil::ast::ASTValue* ast_value);

    CompilerResult compile_define_node(tsil::ast::ASTValue* ast_value);
    CompilerResult compile_assign_node(tsil::ast::ASTValue* ast_value);
    CompilerDiiaResult compile_diia_head_node(
        tsil::ast::DiiaHeadNode* diia_head_node);
    CompilerDiiaResult compile_diia_node(tsil::ast::ASTValue* ast_value);
    CompilerDiiaResult compile_diia_declaration_node(
        tsil::ast::ASTValue* ast_value);
    CompilerStructureResult compile_structure_node(
        tsil::ast::ASTValue* ast_value);
    CompilerResult compile_set_node(tsil::ast::ASTValue* ast_value);
    CompilerValueResult compile_get_node(tsil::ast::ASTValue* ast_value);
    CompilerValueResult compile_get_pointer_node(
        tsil::ast::ASTValue* ast_value);
  };
} // namespace tsil::compiler