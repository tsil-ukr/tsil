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
    x::Value* xValue;
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
    size_t line;
    size_t column;
    std::string message;

    static CompilerError* fromASTValue(tsil::ast::ASTValue* ast_value,
                                       const std::string& message);
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
    x::Function* LF;
    x::Value* LV;
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

    Type* voidType = nullptr;
    Type* pointerType = nullptr;
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

    CompilerValueResult compileAs(x::Function* function,
                                  tsil::x::FunctionBlock* block,
                                  tsil::ast::ASTValue* astValue);
    CompilerResult compileAssign(x::Function* function,
                                 tsil::x::FunctionBlock* block,
                                 tsil::ast::ASTValue* astValue);
    CompilerValueResult compileValue(x::Function* function,
                                     tsil::x::FunctionBlock* block,
                                     tsil::ast::ASTValue* astValue);
    CompilerValueResult compileBinary(x::Function* function,
                                      tsil::x::FunctionBlock* block,
                                      tsil::ast::ASTValue* astValue);
    CompilerValueResult compileCall(x::Function* function,
                                    tsil::x::FunctionBlock* block,
                                    tsil::ast::ASTValue* astValue);
    CompilerValueResult compileConstruct(x::Function* function,
                                         tsil::x::FunctionBlock* block,
                                         tsil::ast::ASTValue* astValue);
    CompilerValueResult compileString(x::Function* function,
                                      tsil::x::FunctionBlock* block,
                                      tsil::ast::ASTValue* astValue);
    CompilerResult compileDefine(x::Function* function,
                                 tsil::x::FunctionBlock* block,
                                 tsil::ast::ASTValue* astValue);
    CompilerDiiaResult compileDiiaHead(tsil::ast::ASTValue* astValue,
                                       tsil::ast::DiiaHeadNode* diiaHeadNode);
    CompilerResult compileDiiaBody(Type* diiaType,
                                   tsil::x::Function* xFunction,
                                   tsil::x::FunctionBlock* xBlock,
                                   tsil::x::FunctionBlock* xExitBlock,
                                   const std::vector<ast::ASTValue*>& body);
    CompilerDiiaResult compileDiia(tsil::ast::ASTValue* astValue);
    CompilerDiiaResult compileDiiaDeclaration(tsil::ast::ASTValue* astValue);
    CompilerValueResult compileGet(x::Function* xFunction,
                                   tsil::x::FunctionBlock* xBlock,
                                   tsil::ast::ASTValue* astValue);
    CompilerValueResult compileGep(x::Function* xFunction,
                                   tsil::x::FunctionBlock* xBlock,
                                   tsil::ast::ASTValue* astValue);
    CompilerValueResult compileLoad(x::Function* xFunction,
                                    tsil::x::FunctionBlock* xBlock,
                                    tsil::ast::ASTValue* astValue);
    CompilerValueResult compileNumber(x::Function* xFunction,
                                      tsil::x::FunctionBlock* xBlock,
                                      tsil::ast::ASTValue* astValue);
    CompilerResult compileSet(x::Function* xFunction,
                              tsil::x::FunctionBlock* xBlock,
                              tsil::ast::ASTValue* astValue);
    CompilerStructureResult compileStructure(tsil::ast::ASTValue* astValue);
    CompilerValueResult compileSizeof(tsil::ast::ASTValue* astValue);
  };
} // namespace tsil::compiler