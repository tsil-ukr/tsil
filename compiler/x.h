#include "iostream"
#include "unordered_map"
#include "vector"

namespace tsil::x {
  struct Module;
  struct Value;
  struct Constant;
  struct Global;
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
  struct FunctionInstructionFCmp;
  struct FunctionInstructionAdd;
  struct FunctionInstructionFAdd;
  struct FunctionInstructionSub;
  struct FunctionInstructionFSub;
  struct FunctionInstructionMul;
  struct FunctionInstructionFMul;
  struct FunctionInstructionDiv;
  struct FunctionInstructionFDiv;
  struct FunctionInstructionMod;
  struct FunctionInstructionFMod;
  struct FunctionInstructionAnd;
  struct FunctionInstructionOr;
  struct FunctionInstructionXor;
  struct FunctionInstructionShl;
  struct FunctionInstructionLShr;
  struct FunctionInstructionAShr;
  struct FunctionInstructionTrunc;
  struct FunctionInstructionZext;
  struct FunctionInstructionSext;
  struct FunctionInstructionFptrunc;
  struct FunctionInstructionFpext;
  struct FunctionInstructionFptoui;
  struct FunctionInstructionFptosi;
  struct FunctionInstructionUitofp;
  struct FunctionInstructionSitofp;
  struct FunctionInstructionPtrtoint;
  struct FunctionInstructionInttoptr;

  void implode(std::vector<std::string>& v,
               const std::string& sep,
               std::string& result);

  struct Module {
    std::string name;

    size_t variable_counter = 0;

    std::unordered_map<std::string, Constant*> constants;
    std::unordered_map<std::string, Global*> globals;
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

    std::string targetTriple = "x86_64-pc-linux-gnu";

    std::string computeNextName(const std::string& prefix);
    std::string computeNextVarName(const std::string& prefix);
    std::string computeNextGlobalName(const std::string& prefix);

    Value* putGlobal(const std::string& attributes, Type* type, Value* value);
    Value* putStringConstant(const std::string& attributes,
                             const std::string& value);

    Type* defineNativeType(const std::string& name);
    Type* defineStructType(const std::string& name, std::vector<Type*> fields);

    std::pair<Function*, Value*> declareFunction(
        const std::string& attributes,
        const std::string& name,
        Type* result_type,
        std::vector<Value*> parameters);
    Value* defineFunction(const std::string& attributes,
                          const std::string& name,
                          Type* result_type,
                          std::vector<Value*> parameters);
    FunctionBlock* defineFunctionBlock(Function* function,
                                       const std::string& name);
    FunctionBlock* getFunctionBlock(Function* function,
                                    const std::string& name);

    Value* pushFunctionBlockAllocaInstruction(FunctionBlock* block,
                                              const std::string& name,
                                              Type* type);
    Value* pushFunctionBlockGetElementPtrInstruction(
        FunctionBlock* block,
        Type* type,
        Value* pointer,
        const std::vector<Value*>& indexes);
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
    Value* pushFunctionBlockFCmpInstruction(FunctionBlock* block,
                                            const std::string& op,
                                            Type* type,
                                            Value* left,
                                            Value* right);
    Value* pushFunctionBlockAddInstruction(FunctionBlock* block,
                                           Type* type,
                                           Value* left,
                                           Value* right);
    Value* pushFunctionBlockFAddInstruction(FunctionBlock* block,
                                            Type* type,
                                            Value* left,
                                            Value* right);
    Value* pushFunctionBlockSubInstruction(FunctionBlock* block,
                                           Type* type,
                                           Value* left,
                                           Value* right);
    Value* pushFunctionBlockFSubInstruction(FunctionBlock* block,
                                            Type* type,
                                            Value* left,
                                            Value* right);
    Value* pushFunctionBlockMulInstruction(FunctionBlock* block,
                                           Type* type,
                                           Value* left,
                                           Value* right);
    Value* pushFunctionBlockFMulInstruction(FunctionBlock* block,
                                            Type* type,
                                            Value* left,
                                            Value* right);
    Value* pushFunctionBlockDivInstruction(FunctionBlock* block,
                                           Type* type,
                                           Value* left,
                                           Value* right);
    Value* pushFunctionBlockFDivInstruction(FunctionBlock* block,
                                            Type* type,
                                            Value* left,
                                            Value* right);
    Value* pushFunctionBlockModInstruction(FunctionBlock* block,
                                           Type* type,
                                           Value* left,
                                           Value* right);
    Value* pushFunctionBlockFModInstruction(FunctionBlock* block,
                                            Type* type,
                                            Value* left,
                                            Value* right);
    Value* pushFunctionBlockAndInstruction(FunctionBlock* block,
                                           Type* type,
                                           Value* left,
                                           Value* right);
    Value* pushFunctionBlockOrInstruction(FunctionBlock* block,
                                          Type* type,
                                          Value* left,
                                          Value* right);
    Value* pushFunctionBlockXorInstruction(FunctionBlock* block,
                                           Type* type,
                                           Value* left,
                                           Value* right);
    Value* pushFunctionBlockShlInstruction(FunctionBlock* block,
                                           Type* type,
                                           Value* left,
                                           Value* right);
    Value* pushFunctionBlockLShrInstruction(FunctionBlock* block,
                                            Type* type,
                                            Value* left,
                                            Value* right);
    Value* pushFunctionBlockAShrInstruction(FunctionBlock* block,
                                            Type* type,
                                            Value* left,
                                            Value* right);
    Value* pushFunctionBlockTruncInstruction(FunctionBlock* block,
                                             Type* type,
                                             Value* value,
                                             Type* toType);
    Value* pushFunctionBlockZextInstruction(FunctionBlock* block,
                                            Type* type,
                                            Value* value,
                                            Type* toType);
    Value* pushFunctionBlockSextInstruction(FunctionBlock* block,
                                            Type* type,
                                            Value* value,
                                            Type* toType);
    Value* pushFunctionBlockFptruncInstruction(FunctionBlock* block,
                                               Type* type,
                                               Value* value,
                                               Type* toType);
    Value* pushFunctionBlockFpextInstruction(FunctionBlock* block,
                                             Type* type,
                                             Value* value,
                                             Type* toType);
    Value* pushFunctionBlockFptouiInstruction(FunctionBlock* block,
                                              Type* type,
                                              Value* value,
                                              Type* toType);
    Value* pushFunctionBlockFptosiInstruction(FunctionBlock* block,
                                              Type* type,
                                              Value* value,
                                              Type* toType);
    Value* pushFunctionBlockUitofpInstruction(FunctionBlock* block,
                                              Type* type,
                                              Value* value,
                                              Type* toType);
    Value* pushFunctionBlockSitofpInstruction(FunctionBlock* block,
                                              Type* type,
                                              Value* value,
                                              Type* toType);
    Value* pushFunctionBlockPtrtointInstruction(FunctionBlock* block,
                                                Type* type,
                                                Value* value,
                                                Type* toType);
    Value* pushFunctionBlockInttoptrInstruction(FunctionBlock* block,
                                                Type* type,
                                                Value* value,
                                                Type* toType);

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
    std::string attributes;
    std::string name;
    Type* type;
    std::string value;

    std::string dumpLL(Module* module);
  };

  struct Global {
    std::string attributes;
    std::string name;
    Type* type;
    Value* value;

    std::string dumpLL(Module* module);
  };

  enum TypeType {
    TypeTypeNative,
    TypeTypePointer,
    TypeTypeType,
    TypeTypeArray,
  };

  struct Type {
    TypeType type;
    std::string name;
    std::vector<Type*> fields;
    Type* pointerTo;
    size_t arraySize;
    Type* arrayOf;
    Type* cachedPointerType;

    Type* getPointerType(Module* module);
    Type* getArrayType(Module* module, size_t size);
    size_t getAlign();
    std::string dumpLL(Module* module);
  };

  struct Function {
    std::string attributes;
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
    // todo: use unions maybe to keep memory usage lower
    FunctionInstructionAlloca* alloca;
    FunctionInstructionGetElementPtr* getelementptr;
    FunctionInstructionStore* store;
    FunctionInstructionLoad* load;
    FunctionInstructionRet* ret;
    FunctionInstructionCall* call;
    FunctionInstructionBr* br;
    FunctionInstructionBrIf* brif;
    FunctionInstructionICmp* icmp;
    FunctionInstructionFCmp* fcmp;
    FunctionInstructionAdd* add;
    FunctionInstructionFAdd* fadd;
    FunctionInstructionSub* sub;
    FunctionInstructionFSub* fsub;
    FunctionInstructionMul* mul;
    FunctionInstructionFMul* fmul;
    FunctionInstructionDiv* div;
    FunctionInstructionFDiv* fdiv;
    FunctionInstructionMod* mod;
    FunctionInstructionFMod* fmod;
    FunctionInstructionAnd* and_;
    FunctionInstructionOr* or_;
    FunctionInstructionXor* xor_;
    FunctionInstructionShl* shl;
    FunctionInstructionLShr* lshr;
    FunctionInstructionAShr* ashr;
    FunctionInstructionTrunc* trunc;
    FunctionInstructionZext* zext;
    FunctionInstructionSext* sext;
    FunctionInstructionFptrunc* fptrunc;
    FunctionInstructionFpext* fpext;
    FunctionInstructionFptoui* fptoui;
    FunctionInstructionFptosi* fptosi;
    FunctionInstructionUitofp* uitofp;
    FunctionInstructionSitofp* sitofp;
    FunctionInstructionPtrtoint* ptrtoint;
    FunctionInstructionInttoptr* inttoptr;

    std::string dumpLL(Module* module);
  };

  struct FunctionInstructionAlloca {
    Type* type;
  };

  struct FunctionInstructionGetElementPtr {
    Type* type;
    Value* pointer;
    std::vector<Value*> indexes;
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

  struct FunctionInstructionFCmp {
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

  struct FunctionInstructionFAdd {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionSub {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionFSub {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionMul {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionFMul {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionDiv {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionFDiv {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionMod {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionFMod {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionAnd {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionOr {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionXor {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionShl {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionLShr {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionAShr {
    Type* type;
    Value* left;
    Value* right;
  };

  struct FunctionInstructionTrunc {
    Type* type;
    Value* value;
    Type* toType;
  };

  struct FunctionInstructionZext {
    Type* type;
    Value* value;
    Type* toType;
  };

  struct FunctionInstructionSext {
    Type* type;
    Value* value;
    Type* toType;
  };

  struct FunctionInstructionFptrunc {
    Type* type;
    Value* value;
    Type* toType;
  };

  struct FunctionInstructionFpext {
    Type* type;
    Value* value;
    Type* toType;
  };

  struct FunctionInstructionFptoui {
    Type* type;
    Value* value;
    Type* toType;
  };

  struct FunctionInstructionFptosi {
    Type* type;
    Value* value;
    Type* toType;
  };

  struct FunctionInstructionUitofp {
    Type* type;
    Value* value;
    Type* toType;
  };

  struct FunctionInstructionSitofp {
    Type* type;
    Value* value;
    Type* toType;
  };

  struct FunctionInstructionPtrtoint {
    Type* type;
    Value* value;
    Type* toType;
  };

  struct FunctionInstructionInttoptr {
    Type* type;
    Value* value;
    Type* toType;
  };
} // namespace tsil::x