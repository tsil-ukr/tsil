#include "x2.h"

namespace tsil::x2 {
  std::pair<FunctionX2*, ValueX2*> ModuleX2::declareFunction(
      const std::string& attributes,
      const std::string& name,
      TypeX2* result_type,
      std::vector<TypeX2*> parameters) {
    const auto func_type =
        llvm::FunctionType::get(result_type, parameters, false);
    const auto func = llvm::Function::Create(
        func_type, llvm::Function::ExternalLinkage, name, LLVMModule);
    return {
        new FunctionX2(func, result_type, nullptr, nullptr, nullptr, nullptr),
        func};
  }

  TypeX2* ModuleX2::defineStructType(const std::string& name,
                                     std::vector<TypeX2*> fields) {
    const auto struct_type =
        llvm::StructType::create(*LLVMContext, fields, name);
    return struct_type;
  }

  void ModuleX2::setStructTypeFields(tsil::x2::TypeX2* type,
                                     std::vector<TypeX2*> fields) {
    auto struct_type = llvm::cast<llvm::StructType>(type);
    struct_type->setBody(fields);
  }

  FunctionX2Block* ModuleX2::createFunctionBlock(tsil::x2::FunctionX2* function,
                                                 const std::string& name) {
    return llvm::BasicBlock::Create(*LLVMContext, name);
  }

  FunctionX2Block* ModuleX2::defineFunctionBlock(tsil::x2::FunctionX2* function,
                                                 const std::string& name) {
    auto block = createFunctionBlock(function, name);
    function->LLVMFunction->insert(function->LLVMFunction->end(), block);
    return block;
  }

  ValueX2* ModuleX2::pushFunctionBlockAllocaInstruction(
      tsil::x2::FunctionX2Block* block,
      const std::string& name,
      tsil::x2::TypeX2* type) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateAlloca(type, nullptr, name);
  }

  ValueX2* ModuleX2::pushFunctionBlockGetElementPtrInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* pointer,
      const std::vector<ValueX2*>& indexes) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateGEP(type, pointer, indexes);
  }

  void ModuleX2::pushFunctionBlockStoreInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* value,
      tsil::x2::ValueX2* pointer) {
    llvm::IRBuilder<> TmpB(block);
    TmpB.CreateStore(value, pointer);
  }

  ValueX2* ModuleX2::pushFunctionBlockLoadInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* pointer) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateLoad(type, pointer, "load");
  }

  void ModuleX2::pushFunctionBlockRetInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* value) {
    llvm::IRBuilder<> TmpB(block);
    TmpB.CreateRet(value);
  }

  ValueX2* ModuleX2::pushFunctionBlockCallInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* value,
      std::vector<ValueX2*> arguments) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateCall(llvm::cast<llvm::Function>(value), arguments);
  }

  void ModuleX2::pushFunctionBlockBrInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::FunctionX2Block* target) {
    llvm::IRBuilder<> TmpB(block);
    TmpB.CreateBr(target);
  }

  void ModuleX2::pushFunctionBlockBrIfInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::ValueX2* condition,
      tsil::x2::FunctionX2Block* target_true,
      tsil::x2::FunctionX2Block* target_false) {
    llvm::IRBuilder<> TmpB(block);
    TmpB.CreateCondBr(condition, target_true, target_false);
  }

  ValueX2* ModuleX2::pushFunctionBlockICmpInstruction(
      tsil::x2::FunctionX2Block* block,
      const std::string& op,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::ICmpInst::Predicate predicate;
    if (op == "eq") {
      predicate = llvm::ICmpInst::ICMP_EQ;
    } else if (op == "ne") {
      predicate = llvm::ICmpInst::ICMP_NE;
    } else if (op == "ugt") {
      predicate = llvm::ICmpInst::ICMP_UGT;
    } else if (op == "uge") {
      predicate = llvm::ICmpInst::ICMP_UGE;
    } else if (op == "ult") {
      predicate = llvm::ICmpInst::ICMP_ULT;
    } else if (op == "ule") {
      predicate = llvm::ICmpInst::ICMP_ULE;
    } else if (op == "sgt") {
      predicate = llvm::ICmpInst::ICMP_SGT;
    } else if (op == "sge") {
      predicate = llvm::ICmpInst::ICMP_SGE;
    } else if (op == "slt") {
      predicate = llvm::ICmpInst::ICMP_SLT;
    } else if (op == "sle") {
      predicate = llvm::ICmpInst::ICMP_SLE;
    } else {
      return nullptr;
    }
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateICmp(predicate, left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockFCmpInstruction(
      tsil::x2::FunctionX2Block* block,
      const std::string& op,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::FCmpInst::Predicate predicate;
    if (op == "false") {
      predicate = llvm::FCmpInst::FCMP_FALSE;
    } else if (op == "oeq") {
      predicate = llvm::FCmpInst::FCMP_OEQ;
    } else if (op == "ogt") {
      predicate = llvm::FCmpInst::FCMP_OGT;
    } else if (op == "oge") {
      predicate = llvm::FCmpInst::FCMP_OGE;
    } else if (op == "olt") {
      predicate = llvm::FCmpInst::FCMP_OLT;
    } else if (op == "ole") {
      predicate = llvm::FCmpInst::FCMP_OLE;
    } else if (op == "one") {
      predicate = llvm::FCmpInst::FCMP_ONE;
    } else if (op == "ord") {
      predicate = llvm::FCmpInst::FCMP_ORD;
    } else if (op == "ueq") {
      predicate = llvm::FCmpInst::FCMP_UEQ;
    } else if (op == "ugt") {
      predicate = llvm::FCmpInst::FCMP_UGT;
    } else if (op == "uge") {
      predicate = llvm::FCmpInst::FCMP_UGE;
    } else if (op == "ult") {
      predicate = llvm::FCmpInst::FCMP_ULT;
    } else if (op == "ule") {
      predicate = llvm::FCmpInst::FCMP_ULE;
    } else if (op == "une") {
      predicate = llvm::FCmpInst::FCMP_UNE;
    } else if (op == "uno") {
      predicate = llvm::FCmpInst::FCMP_UNO;
    } else if (op == "true") {
      predicate = llvm::FCmpInst::FCMP_TRUE;
    } else {
      return nullptr;
    }
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateFCmp(predicate, left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockAddInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateAdd(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockFAddInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateFAdd(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockSubInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateSub(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockFSubInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateFSub(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockMulInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateMul(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockFMulInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateFMul(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockUDivInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateUDiv(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockSDivInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateSDiv(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockFDivInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateFDiv(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockModInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateURem(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockFModInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateFRem(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockAndInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateAnd(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockOrInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateOr(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockXorInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateXor(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockShlInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateShl(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockLShrInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateLShr(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockAShrInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* left,
      tsil::x2::ValueX2* right) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateAShr(left, right);
  }

  ValueX2* ModuleX2::pushFunctionBlockTruncInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* value,
      tsil::x2::TypeX2* toType) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateTrunc(value, toType);
  }

  ValueX2* ModuleX2::pushFunctionBlockZextInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* value,
      tsil::x2::TypeX2* toType) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateZExt(value, toType);
  }

  ValueX2* ModuleX2::pushFunctionBlockSextInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* value,
      tsil::x2::TypeX2* toType) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateSExt(value, toType);
  }

  ValueX2* ModuleX2::pushFunctionBlockFptruncInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* value,
      tsil::x2::TypeX2* toType) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateFPTrunc(value, toType);
  }

  ValueX2* ModuleX2::pushFunctionBlockFpextInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* value,
      tsil::x2::TypeX2* toType) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateFPExt(value, toType);
  }

  ValueX2* ModuleX2::pushFunctionBlockFptouiInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* value,
      tsil::x2::TypeX2* toType) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateFPToUI(value, toType);
  }

  ValueX2* ModuleX2::pushFunctionBlockFptosiInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* value,
      tsil::x2::TypeX2* toType) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateFPToSI(value, toType);
  }

  ValueX2* ModuleX2::pushFunctionBlockUitofpInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* value,
      tsil::x2::TypeX2* toType) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateUIToFP(value, toType);
  }

  ValueX2* ModuleX2::pushFunctionBlockSitofpInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* value,
      tsil::x2::TypeX2* toType) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateSIToFP(value, toType);
  }

  ValueX2* ModuleX2::pushFunctionBlockPtrtointInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* value,
      tsil::x2::TypeX2* toType) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreatePtrToInt(value, toType);
  }

  ValueX2* ModuleX2::pushFunctionBlockInttoptrInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* value,
      tsil::x2::TypeX2* toType) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateIntToPtr(value, toType);
  }

  ValueX2* ModuleX2::pushFunctionBlockBitcastInstruction(
      tsil::x2::FunctionX2Block* block,
      tsil::x2::TypeX2* type,
      tsil::x2::ValueX2* value,
      tsil::x2::TypeX2* toType) {
    llvm::IRBuilder<> TmpB(block);
    return TmpB.CreateBitCast(value, toType);
  }
} // namespace tsil::x2