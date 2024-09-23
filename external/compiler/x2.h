#include "iostream"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/Unicode.h"
#include "unordered_map"
#include "vector"

namespace tsil::x2 {
  struct ModuleX2;
  typedef llvm::Type TypeX2;
  typedef llvm::Value ValueX2;
  typedef llvm::BasicBlock FunctionX2Block;
  struct FunctionX2 {
    llvm::Function* LLVMFunction;
    TypeX2* result_type = nullptr;
    ValueX2* return_alloca = nullptr;
    FunctionX2Block* alloca_block = nullptr;
    FunctionX2Block* entry_block = nullptr;
    FunctionX2Block* exit_block = nullptr;
  };

  struct ModuleX2 {
    llvm::LLVMContext* LLVMContext;
    llvm::Module* LLVMModule;
    llvm::IRBuilder<>* LLVMBuilder;

    TypeX2* int1Type;
    TypeX2* int8Type;
    TypeX2* int16Type;
    TypeX2* int32Type;
    TypeX2* int64Type;
    TypeX2* floatType;
    TypeX2* doubleType;
    TypeX2* pointerType;
    TypeX2* voidType;

    //    ValueX2* putGlobal(const std::string& attributes, TypeX2* type, ValueX2* value);
    //    ValueX2* putStringConstant(const std::string& attributes,
    //                             const std::string& value);
    //
    TypeX2* defineStructType(const std::string& name,
                             std::vector<TypeX2*> fields);
    void setStructTypeFields(TypeX2* type, std::vector<TypeX2*> fields);

    std::pair<FunctionX2*, ValueX2*> declareFunction(
        const std::string& attributes,
        const std::string& name,
        TypeX2* result_type,
        std::vector<TypeX2*> parameters);
    FunctionX2Block* createFunctionBlock(FunctionX2* function,
                                         const std::string& name);
    FunctionX2Block* defineFunctionBlock(FunctionX2* function,
                                         const std::string& name);

    ValueX2* pushFunctionBlockAllocaInstruction(FunctionX2Block* block,
                                                const std::string& name,
                                                TypeX2* type);
    ValueX2* pushFunctionBlockGetElementPtrInstruction(
        FunctionX2Block* block,
        TypeX2* type,
        ValueX2* pointer,
        const std::vector<ValueX2*>& indexes);
    void pushFunctionBlockStoreInstruction(FunctionX2Block* block,
                                           TypeX2* type,
                                           ValueX2* value,
                                           ValueX2* pointer);
    ValueX2* pushFunctionBlockLoadInstruction(FunctionX2Block* block,
                                              TypeX2* type,
                                              ValueX2* pointer);
    void pushFunctionBlockRetInstruction(FunctionX2Block* block,
                                         TypeX2* type,
                                         ValueX2* value);
    ValueX2* pushFunctionBlockCallInstruction(FunctionX2Block* block,
                                              TypeX2* type,
                                              ValueX2* value,
                                              std::vector<ValueX2*> arguments);
    void pushFunctionBlockBrInstruction(FunctionX2Block* block,
                                        FunctionX2Block* target);
    void pushFunctionBlockBrIfInstruction(FunctionX2Block* block,
                                          ValueX2* condition,
                                          FunctionX2Block* target_true,
                                          FunctionX2Block* target_false);
    ValueX2* pushFunctionBlockICmpInstruction(FunctionX2Block* block,
                                              const std::string& op,
                                              TypeX2* type,
                                              ValueX2* left,
                                              ValueX2* right);
    ValueX2* pushFunctionBlockFCmpInstruction(FunctionX2Block* block,
                                              const std::string& op,
                                              TypeX2* type,
                                              ValueX2* left,
                                              ValueX2* right);
    ValueX2* pushFunctionBlockAddInstruction(FunctionX2Block* block,
                                             TypeX2* type,
                                             ValueX2* left,
                                             ValueX2* right);
    ValueX2* pushFunctionBlockFAddInstruction(FunctionX2Block* block,
                                              TypeX2* type,
                                              ValueX2* left,
                                              ValueX2* right);
    ValueX2* pushFunctionBlockSubInstruction(FunctionX2Block* block,
                                             TypeX2* type,
                                             ValueX2* left,
                                             ValueX2* right);
    ValueX2* pushFunctionBlockFSubInstruction(FunctionX2Block* block,
                                              TypeX2* type,
                                              ValueX2* left,
                                              ValueX2* right);
    ValueX2* pushFunctionBlockMulInstruction(FunctionX2Block* block,
                                             TypeX2* type,
                                             ValueX2* left,
                                             ValueX2* right);
    ValueX2* pushFunctionBlockFMulInstruction(FunctionX2Block* block,
                                              TypeX2* type,
                                              ValueX2* left,
                                              ValueX2* right);
    ValueX2* pushFunctionBlockUDivInstruction(FunctionX2Block* block,
                                              TypeX2* type,
                                              ValueX2* left,
                                              ValueX2* right);
    ValueX2* pushFunctionBlockSDivInstruction(FunctionX2Block* block,
                                              TypeX2* type,
                                              ValueX2* left,
                                              ValueX2* right);
    ValueX2* pushFunctionBlockFDivInstruction(FunctionX2Block* block,
                                              TypeX2* type,
                                              ValueX2* left,
                                              ValueX2* right);
    ValueX2* pushFunctionBlockModInstruction(FunctionX2Block* block,
                                             TypeX2* type,
                                             ValueX2* left,
                                             ValueX2* right);
    ValueX2* pushFunctionBlockFModInstruction(FunctionX2Block* block,
                                              TypeX2* type,
                                              ValueX2* left,
                                              ValueX2* right);
    ValueX2* pushFunctionBlockAndInstruction(FunctionX2Block* block,
                                             TypeX2* type,
                                             ValueX2* left,
                                             ValueX2* right);
    ValueX2* pushFunctionBlockOrInstruction(FunctionX2Block* block,
                                            TypeX2* type,
                                            ValueX2* left,
                                            ValueX2* right);
    ValueX2* pushFunctionBlockXorInstruction(FunctionX2Block* block,
                                             TypeX2* type,
                                             ValueX2* left,
                                             ValueX2* right);
    ValueX2* pushFunctionBlockShlInstruction(FunctionX2Block* block,
                                             TypeX2* type,
                                             ValueX2* left,
                                             ValueX2* right);
    ValueX2* pushFunctionBlockLShrInstruction(FunctionX2Block* block,
                                              TypeX2* type,
                                              ValueX2* left,
                                              ValueX2* right);
    ValueX2* pushFunctionBlockAShrInstruction(FunctionX2Block* block,
                                              TypeX2* type,
                                              ValueX2* left,
                                              ValueX2* right);
    ValueX2* pushFunctionBlockTruncInstruction(FunctionX2Block* block,
                                               TypeX2* type,
                                               ValueX2* value,
                                               TypeX2* toType);
    ValueX2* pushFunctionBlockZextInstruction(FunctionX2Block* block,
                                              TypeX2* type,
                                              ValueX2* value,
                                              TypeX2* toType);
    ValueX2* pushFunctionBlockSextInstruction(FunctionX2Block* block,
                                              TypeX2* type,
                                              ValueX2* value,
                                              TypeX2* toType);
    ValueX2* pushFunctionBlockFptruncInstruction(FunctionX2Block* block,
                                                 TypeX2* type,
                                                 ValueX2* value,
                                                 TypeX2* toType);
    ValueX2* pushFunctionBlockFpextInstruction(FunctionX2Block* block,
                                               TypeX2* type,
                                               ValueX2* value,
                                               TypeX2* toType);
    ValueX2* pushFunctionBlockFptouiInstruction(FunctionX2Block* block,
                                                TypeX2* type,
                                                ValueX2* value,
                                                TypeX2* toType);
    ValueX2* pushFunctionBlockFptosiInstruction(FunctionX2Block* block,
                                                TypeX2* type,
                                                ValueX2* value,
                                                TypeX2* toType);
    ValueX2* pushFunctionBlockUitofpInstruction(FunctionX2Block* block,
                                                TypeX2* type,
                                                ValueX2* value,
                                                TypeX2* toType);
    ValueX2* pushFunctionBlockSitofpInstruction(FunctionX2Block* block,
                                                TypeX2* type,
                                                ValueX2* value,
                                                TypeX2* toType);
    ValueX2* pushFunctionBlockPtrtointInstruction(FunctionX2Block* block,
                                                  TypeX2* type,
                                                  ValueX2* value,
                                                  TypeX2* toType);
    ValueX2* pushFunctionBlockInttoptrInstruction(FunctionX2Block* block,
                                                  TypeX2* type,
                                                  ValueX2* value,
                                                  TypeX2* toType);
    ValueX2* pushFunctionBlockBitcastInstruction(FunctionX2Block* block,
                                                 TypeX2* type,
                                                 ValueX2* value,
                                                 TypeX2* toType);
  };

  inline static ModuleX2* create_module_x2() {
    const auto context = new llvm::LLVMContext();
    const auto builder = new llvm::IRBuilder(*context);
    const auto module = new llvm::Module("test", *context);
    const auto x2Module = new ModuleX2();
    x2Module->LLVMContext = context;
    x2Module->LLVMModule = module;
    x2Module->LLVMBuilder = builder;
    x2Module->int1Type = builder->getInt1Ty();
    x2Module->int8Type = builder->getInt8Ty();
    x2Module->int16Type = builder->getInt16Ty();
    x2Module->int32Type = builder->getInt32Ty();
    x2Module->int64Type = builder->getInt64Ty();
    x2Module->floatType = builder->getFloatTy();
    x2Module->doubleType = builder->getDoubleTy();
    x2Module->pointerType = builder->getVoidTy()->getPointerTo();
    x2Module->voidType = builder->getVoidTy();
    return x2Module;
  }

  inline static ValueX2* CreateGlobalStringPtr(ModuleX2* module,
                                               const std::string& value) {
    return static_cast<llvm::IRBuilder<>*>(module->LLVMBuilder)
        ->CreateGlobalStringPtr(value);
  }

  inline static ValueX2* CreateInt8(ModuleX2* module, int8_t value) {
    return static_cast<llvm::IRBuilder<>*>(module->LLVMBuilder)->getInt8(value);
  }

  inline static ValueX2* CreateInt32(ModuleX2* module, int32_t value) {
    return static_cast<llvm::IRBuilder<>*>(module->LLVMBuilder)
        ->getInt32(value);
  }

  inline static ValueX2* CreateInt64(ModuleX2* module, int32_t value) {
    return static_cast<llvm::IRBuilder<>*>(module->LLVMBuilder)
        ->getInt64(value);
  }

  inline static ValueX2* CreateFloat(ModuleX2* module, float value) {
    return static_cast<llvm::IRBuilder<>*>(module->LLVMBuilder)
        ->getInt32(value);
  }

  inline static ValueX2* CreateDouble(ModuleX2* module, double value) {
    return static_cast<llvm::IRBuilder<>*>(module->LLVMBuilder)
        ->getInt64(value);
  }

  inline static ValueX2* GetConstantPointerNull(ModuleX2* module) {
    return llvm::ConstantPointerNull::get(
        static_cast<llvm::PointerType*>(module->pointerType));
  }

  inline static std::string dumpLL(ModuleX2* module) {
    std::string str;
    llvm::raw_string_ostream os(str);
    module->LLVMModule->print(os, nullptr);
    return os.str();
  }
} // namespace tsil::x2