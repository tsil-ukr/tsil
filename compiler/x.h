#include "iostream"
#include "unordered_map"
#include "vector"

namespace tsil::x {
  struct Module;
  struct Value;
  struct Constant;
  struct Type;
  struct Function;
  struct FunctionBlock;
  struct FunctionInstruction;
  struct FunctionInstructionAlloca;
  struct FunctionInstructionGetElementPtr;
  struct FunctionInstructionStore;
  struct FunctionInstructionLoad;
  struct FunctionInstructionRet;
  struct FunctionInstructionCall;
  struct FunctionInstructionBr;
  struct FunctionInstructionBrIf;

  struct Module {
    std::string name;

    size_t variable_counter = 0;

    std::unordered_map<std::string, Constant*> constants;
    std::unordered_map<std::string, Type*> types;
    std::unordered_map<std::string, Function*> functions;

    Type* int8Type;
    Type* int32Type;
    Type* int64Type;
    Type* floatType;
    Type* doubleType;
    Type* pointerType;
    Type* voidType;

    Value* putStringConstant(const std::string& value);

    Type* defineNativeType(const std::string& name);
    Type* defineStructType(const std::string& name, std::vector<Type*> fields);

    Value* declareFunction(const std::string& name,
                           Type* result_type,
                           std::vector<Type*> parameters);

    Value* defineFunction(const std::string& name,
                          Type* result_type,
                          std::vector<Type*> parameters);
    FunctionBlock* defineFunctionBlock(Function* function,
                                       const std::string& name);
    FunctionBlock* getFunctionBlock(Function* function,
                                    const std::string& name);
    Value* pushFunctionBlockAllocaInstruction(FunctionBlock* block, Type* type);
    Value* pushFunctionBlockGetElementPtrInstruction(
        FunctionBlock* block,
        Type* type,
        Value* pointer,
        std::vector<size_t> indexes);
    FunctionInstruction* pushFunctionBlockStoreInstruction(FunctionBlock* block,
                                                           Value* value,
                                                           Value* pointer);
    Value* pushFunctionBlockLoadInstruction(FunctionBlock* block,
                                            Type* type,
                                            Value* pointer);
    FunctionInstruction* pushFunctionBlockRetInstruction(FunctionBlock* block,
                                                         Value* value);
    Value* pushFunctionBlockCallInstruction(FunctionBlock* block,
                                            Value* value,
                                            std::vector<Value*> arguments);
    FunctionInstruction* pushFunctionBlockBrInstruction(FunctionBlock* block,
                                                        FunctionBlock* target);
    FunctionInstruction* pushFunctionBlockBrIfInstruction(
        FunctionBlock* block,
        Value* condition,
        FunctionBlock* target_true,
        FunctionBlock* target_false);

    std::string dumpLL();
  };

  struct Number {
    Type* type;
    std::string value;
  };

  struct Value {
    Constant* constant = nullptr;
    FunctionInstruction* instruction = nullptr;
    Function* function = nullptr;
    Number* number;

    std::string dumpLL(Module* module);
    std::string dumpRightLL(Module* module);
  };

  struct Constant {
    size_t variable_index;
    std::string name;
    std::string value;

    std::string dumpLL(Module* module);
  };

  enum TypeType {
    TypeTypeNative,
    TypeTypeType,
  };

  struct Type {
    size_t variable_index;
    TypeType type;
    std::string name;
    std::vector<Type*> fields;

    std::string dumpLL(Module* module);
  };

  struct Function {
    std::string name;
    Type* result_type;
    std::vector<Type*> parameters;
    std::vector<FunctionBlock*> blocks;

    std::string dumpLL(Module* module);
  };

  struct FunctionBlock {
    std::string name;
    std::vector<FunctionInstruction*> instructions;

    std::string dumpLL(Module* module);
  };

  struct FunctionInstruction {
    std::string name;
    FunctionInstructionAlloca* alloca;
    FunctionInstructionGetElementPtr* getelementptr;
    FunctionInstructionStore* store;
    FunctionInstructionLoad* load;
    FunctionInstructionRet* ret;
    FunctionInstructionCall* call;
    FunctionInstructionBr* br;
    FunctionInstructionBrIf* brif;

    std::string dumpLL(Module* module);
  };

  struct FunctionInstructionAlloca {
    Type* type;
  };

  struct FunctionInstructionGetElementPtr {
    Type* type;
    Value* pointer;
    std::vector<size_t> indexes;
  };

  struct FunctionInstructionStore {
    Value* value;
    Value* pointer;
  };

  struct FunctionInstructionLoad {
    Type* type;
    Value* pointer;
  };

  struct FunctionInstructionRet {
    Value* value;
  };

  struct FunctionInstructionCall {
    Value* value;
    std::vector<Value*> arguments;
  };

  struct FunctionInstructionBr {
    FunctionBlock* target;
  };

  struct FunctionInstructionBrIf {
    Value* condition;
    FunctionBlock* target_true;
    FunctionBlock* target_false;
  };
} // namespace tsil::x