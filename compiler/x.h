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
  struct FunctionInstructionICmp;
  struct FunctionInstructionAdd;
  struct FunctionInstructionSub;
  struct FunctionInstructionMul;
  struct FunctionInstructionDiv;
  struct FunctionInstructionMod;

  struct Module {
    std::string name;

    size_t variable_counter = 0;

    std::unordered_map<std::string, Constant*> constants;
    std::unordered_map<std::string, Type*> types;
    std::unordered_map<std::string, Function*> functions;

    Type* int1Type;
    Type* int8Type;
    Type* int32Type;
    Type* int64Type;
    Type* floatType;
    Type* doubleType;
    Type* pointerType;
    Type* voidType;

    Value* putStringConstant(const std::string& value);
    Value* putI64Constant(long value);
    Value* putI8Constant(char value);

    Type* defineNativeType(const std::string& name);
    Type* defineStructType(const std::string& name, std::vector<Type*> fields);

    std::pair<Function*, Value*> declareFunction(
        const std::string& name,
        Type* result_type,
        std::vector<Value*> parameters);

    Value* defineFunction(const std::string& name,
                          Type* result_type,
                          std::vector<Value*> parameters);
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
                                                           Type* type,
                                                           Value* value,
                                                           Value* pointer);
    Value* pushFunctionBlockLoadInstruction(FunctionBlock* block,
                                            Type* type,
                                            Value* pointer);
    FunctionInstruction* pushFunctionBlockRetInstruction(FunctionBlock* block,
                                                         Type* type,
                                                         Value* value);
    Value* pushFunctionBlockCallInstruction(FunctionBlock* block,
                                            Type* type,
                                            Value* value,
                                            std::vector<Value*> arguments);
    FunctionInstruction* pushFunctionBlockBrInstruction(FunctionBlock* block,
                                                        FunctionBlock* target);
    FunctionInstruction* pushFunctionBlockBrIfInstruction(
        FunctionBlock* block,
        Value* condition,
        FunctionBlock* target_true,
        FunctionBlock* target_false);
    Value* pushFunctionBlockICmpInstruction(FunctionBlock* block,
                                            const std::string& op,
                                            Type* type,
                                            Value* left,
                                            Value* right);
    Value* pushFunctionBlockAddInstruction(FunctionBlock* block,
                                           Type* type,
                                           Value* left,
                                           Value* right);
    Value* pushFunctionBlockSubInstruction(FunctionBlock* block,
                                           Type* type,
                                           Value* left,
                                           Value* right);
    Value* pushFunctionBlockMulInstruction(FunctionBlock* block,
                                           Type* type,
                                           Value* left,
                                           Value* right);
    Value* pushFunctionBlockDivInstruction(FunctionBlock* block,
                                           Type* type,
                                           Value* left,
                                           Value* right);
    Value* pushFunctionBlockModInstruction(FunctionBlock* block,
                                           Type* type,
                                           Value* left,
                                           Value* right);

    std::string dumpLL();
  };

  struct Number {
    Type* type;
    std::string value;
  };

  struct Value {
    Type* type;
    std::string name;

    std::string dumpLL(Module* module);
  };

  struct Constant {
    size_t variable_index;
    std::string name;
    Type* type;
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
    Type* result_type = nullptr;
    std::vector<Value*> parameters;
    std::vector<FunctionBlock*> blocks;
    Value* return_alloca = nullptr;
    FunctionBlock* entry_block = nullptr;
    FunctionBlock* exit_block = nullptr;

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
    FunctionInstructionICmp* icmp;
    FunctionInstructionAdd* add;
    FunctionInstructionSub* sub;
    FunctionInstructionMul* mul;
    FunctionInstructionDiv* div;
    FunctionInstructionMod* mod;

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
    Type* type;
    Value* value;
    Value* pointer;
  };

  struct FunctionInstructionLoad {
    Type* type;
    Value* pointer;
  };

  struct FunctionInstructionRet {
    Type* type;
    Value* value;
  };

  struct FunctionInstructionCall {
    Type* type;
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

  struct FunctionInstructionICmp {
    std::string op;
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionAdd {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionSub {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionMul {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionDiv {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionMod {
    Type* type;
    Value* left;
    Value* right;
  };
} // namespace tsil::x