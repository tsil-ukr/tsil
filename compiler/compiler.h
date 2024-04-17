#include "../parser/parser.h"
#include "x.h"

namespace tsil::compiler {
  struct Type;
  struct Structure;
  struct CompilationState;
  struct CompilationScope;

  enum TypeType {
    TypeTypeNative,
    TypeTypePointer,
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
    Type* cached_pointer_type = nullptr;
    std::vector<Type*> generic_values;
    // pointer
    Type* pointer_to = nullptr;
    // structure
    std::unordered_map<std::string, TypeStructureField>
        structure_instance_fields;
    // diia
    bool diia_is_extern;
    std::vector<TypeDiiaParameter> diia_parameters;
    bool diia_is_variadic;
    Type* diia_result_type = nullptr;
    // llvm
    x::Type* LT = nullptr;

    std::string getFullName();
    Type* getPointerType(CompilationScope* scope);
    x::Value* castToLV(CompilationScope* scope,
                       Type* target_type,
                       x::Value* LV);
    size_t getSizeOf(CompilationScope* scope);
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
    x::Value* LV;
    CompilerError* error;
  };

  struct CompilerDiiaResult {
    Type* type;
    x::Value* LF;
    CompilerError* error;
  };

  struct CompilerStructureResult {
    Structure* structure;
    CompilerError* error;
  };

  struct CompilationState {
    x::Module* Module;
    CompilationScope* globalScope;
    std::map<std::string, Type*> types;
    std::map<std::string, Structure*> structures;
    std::map<std::pair<Structure*, std::vector<Type*>>, Type*> types_cache;

    Type* voidPointerType = nullptr;
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
    std::map<std::string, std::pair<Type*, x::Value*>> variables;

    bool has_variable(const std::string& name) const;
    std::pair<Type*, x::Value*> get_variable(const std::string& name);
    void set_variable(const std::string& name,
                      std::pair<Type*, x::Value*> value);

    MakeTypeResult makeType(const std::string& name,
                            std::vector<Type*> generic_values);
    MakeTypeResult makeTypeFromTypeNodeASTValue(tsil::ast::ASTValue* ast_value);

    Structure* createStructure(
        const std::string& name,
        const std::vector<std::string>& generic_definitions,
        const std::map<std::string, StructureField>& fields);

    CompilerValueResult compile_number_node(tsil::ast::ASTValue* ast_value);
    CompilerValueResult compile_string_node(x::Function* function,
                                            tsil::ast::ASTValue* ast_value);

    CompilerValueResult compile_ast_value(x::Function* function,
                                          tsil::ast::ASTValue* ast_value);
    CompilerValueResult compile_call_node(x::Function* function,
                                          tsil::ast::ASTValue* ast_value);
    CompilerValueResult compile_identifier_node(x::Function* function,
                                                tsil::ast::ASTValue* ast_value);

    CompilerResult compile_define_node(x::Function* function,
                                       tsil::ast::ASTValue* ast_value);
    CompilerResult compile_assign_node(x::Function* function,
                                       tsil::ast::ASTValue* ast_value);
    CompilerResult compile_set_node(x::Function* function,
                                    tsil::ast::ASTValue* ast_value);
    CompilerValueResult compile_get_node(x::Function* function,
                                         tsil::ast::ASTValue* ast_value);
    CompilerValueResult compile_get_pointer_node(
        x::Function* function,
        tsil::ast::ASTValue* ast_value);

    CompilerValueResult compile_constructor_node(
        x::Function* function,
        tsil::ast::ASTValue* ast_value);

    CompilerValueResult compile_as_node(x::Function* function,
                                        tsil::ast::ASTValue* ast_value);

    CompilerDiiaResult compile_diia_head_node(
        tsil::ast::DiiaHeadNode* diia_head_node);
    CompilerDiiaResult compile_diia_node(tsil::ast::ASTValue* ast_value);
    CompilerDiiaResult compile_diia_declaration_node(
        tsil::ast::ASTValue* ast_value);

    CompilerStructureResult compile_structure_node(
        tsil::ast::ASTValue* ast_value);

    CompilerValueResult compile_sizeof_node(tsil::ast::ASTValue* ast_value);
  };
} // namespace tsil::compiler