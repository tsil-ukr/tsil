#include "llvm/ADT/APFloat.h"
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
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/TargetParser/Host.h"

#include <iostream>

struct XLMStruct {
  llvm::LLVMContext* llvmContext;
  llvm::Module* llvmModule;
  llvm::IRBuilder<>* llvmBuilder;
};
#define TL_TYPE XLMStruct
#define TSIL_LLVM_FUNCTION_TYPE llvm::Function
#define TSIL_LLVM_FUNCTION_TYPE_TYPE llvm::FunctionType
#define TSIL_LLVM_TYPE_TYPE llvm::Type
#define TSIL_LLVM_VALUE_TYPE llvm::Value
#define TSIL_LLVM_BASIC_BLOCK_TYPE llvm::BasicBlock
#include "tsil_llvm.h"

extern "C" {
TL* tsil_llvm_create_tl(char* name) {
  const auto xlModule = new TL();
  xlModule->llvmContext = new llvm::LLVMContext();
  xlModule->llvmModule = new llvm::Module(name, *xlModule->llvmContext);
  xlModule->llvmBuilder = new llvm::IRBuilder<>(*xlModule->llvmContext);
  return xlModule;
}

LLVMType* tsil_llvm_create_struct(TL* m, char* name) {
  return llvm::StructType::create(*m->llvmContext, name);
}

LLVMType* tsil_llvm_set_struct_fields(TL* m,
                                      LLVMType* st,
                                      unsigned long fields_size,
                                      LLVMType** fields) {
  std::vector<llvm::Type*> llvmFields(fields_size);
  for (int i = 0; i < fields_size; i++) {
    llvmFields[i] = fields[i];
  }
  static_cast<llvm::StructType*>(st)->setBody(llvmFields);
  return st;
}

LLVMFunction* tsil_llvm_declare_function(TL* m,
                                         size_t linkage,
                                         char* name,
                                         LLVMType* ret_type,
                                         unsigned long params_size,
                                         LLVMType** params,
                                         unsigned long isVarArg) {
  std::vector<llvm::Type*> llvmParams(params_size);
  for (int i = 0; i < params_size; i++) {
    llvmParams[i] = params[i];
  }
  llvm::Function::LinkageTypes linkageType;
  if (linkage == tsil_llvm_LINKAGE_EXTERNAL) {
    linkageType = llvm::Function::ExternalLinkage;
  } else if (linkage == tsil_llvm_LINKAGE_DSO_LOCAL) {
    linkageType = llvm::Function::ExternalLinkage;
  } else {
    linkageType = llvm::Function::InternalLinkage;
  }
  auto function = llvm::Function::Create(
      llvm::FunctionType::get(ret_type, llvmParams, isVarArg), linkageType,
      name, m->llvmModule);
  if (linkage == tsil_llvm_LINKAGE_DSO_LOCAL) {
    function->setDSOLocal(true);
  }
  return function;
}

LLVMBasicBlock* tsil_llvm_create_function_block(TL* m,
                                                LLVMFunction* f,
                                                char* name) {
  return llvm::BasicBlock::Create(*m->llvmContext, name,
                                  static_cast<llvm::Function*>(f));
}

LLVMValue* tsil_llvm_inst_alloca(TL* m,
                                 LLVMBasicBlock* block,
                                 char* name,
                                 LLVMType* type) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAlloca(type, nullptr, name);
}

LLVMValue* tsil_llvm_inst_getelementptr(TL* m,
                                        LLVMBasicBlock* block,
                                        LLVMType* type,
                                        LLVMValue* pointer,
                                        unsigned long indices_size,
                                        LLVMValue** indices) {
  llvm::IRBuilder<> builder(block);
  std::vector<llvm::Value*> llvmIndices(indices_size);
  for (int i = 0; i < indices_size; i++) {
    llvmIndices[i] = indices[i];
  }
  return builder.CreateGEP(type, pointer, llvmIndices);
}

void tsil_llvm_inst_store(TL* m,
                          LLVMBasicBlock* block,
                          LLVMValue* value,
                          LLVMValue* pointer) {
  llvm::IRBuilder<> builder(block);
  builder.CreateStore(value, pointer);
}

size_t loadIndex = 0;

LLVMValue* tsil_llvm_inst_load(TL* m,
                               LLVMBasicBlock* block,
                               LLVMType* type,
                               LLVMValue* pointer) {
  llvm::IRBuilder<> builder(block);
  loadIndex++;
  auto name = "load" + std::to_string(loadIndex);
  return builder.CreateLoad(type, pointer, name);
}

LLVMValue* tsil_llvm_inst_ret(TL* m, LLVMBasicBlock* block, LLVMValue* value) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateRet(value);
}

LLVMValue* tsil_llvm_inst_call_value(TL* m,
                                     LLVMBasicBlock* block,
                                     LLVMFunctionType* ft,
                                     LLVMValue* value,
                                     unsigned long arguments_size,
                                     LLVMValue** arguments) {
  llvm::IRBuilder<> builder(block);
  std::vector<llvm::Value*> llvmArguments(arguments_size);
  for (int i = 0; i < arguments_size; i++) {
    llvmArguments[i] = arguments[i];
  }
  return builder.CreateCall(ft, value, llvmArguments);
}

LLVMValue* tsil_llvm_inst_call_func(TL* m,
                                    LLVMBasicBlock* block,
                                    LLVMFunction* func,
                                    unsigned long arguments_size,
                                    LLVMValue** arguments) {
  llvm::IRBuilder<> builder(block);
  std::vector<llvm::Value*> llvmArguments(arguments_size);
  for (int i = 0; i < arguments_size; i++) {
    llvmArguments[i] = arguments[i];
  }
  return builder.CreateCall(static_cast<llvm::Function*>(func), llvmArguments);
}

void tsil_llvm_inst_br(TL* m, LLVMBasicBlock* block, LLVMBasicBlock* target) {
  llvm::IRBuilder<> builder(block);
  builder.CreateBr(target);
}

void tsil_llvm_inst_brif(TL* m,
                         LLVMBasicBlock* block,
                         LLVMValue* condition,
                         LLVMBasicBlock* target_true,
                         LLVMBasicBlock* target_false) {
  llvm::IRBuilder<> builder(block);
  builder.CreateCondBr(condition, target_true, target_false);
}

LLVMValue* tsil_llvm_inst_icmp(TL* m,
                               LLVMBasicBlock* block,
                               char* op,
                               LLVMValue* left,
                               LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateICmp(llvm::CmpInst::Predicate::ICMP_EQ, left, right);
}

LLVMValue* tsil_llvm_inst_fcmp(TL* m,
                               LLVMBasicBlock* block,
                               char* op,
                               LLVMValue* left,
                               LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_OEQ, left, right);
}

LLVMValue* tsil_llvm_inst_add(TL* m,
                              LLVMBasicBlock* block,
                              LLVMValue* left,
                              LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAdd(left, right);
}

LLVMValue* tsil_llvm_inst_fadd(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFAdd(left, right);
}

LLVMValue* tsil_llvm_inst_sub(TL* m,
                              LLVMBasicBlock* block,
                              LLVMValue* left,
                              LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSub(left, right);
}

LLVMValue* tsil_llvm_inst_fsub(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFSub(left, right);
}

LLVMValue* tsil_llvm_inst_mul(TL* m,
                              LLVMBasicBlock* block,
                              LLVMValue* left,
                              LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateMul(left, right);
}

LLVMValue* tsil_llvm_inst_fmul(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFMul(left, right);
}

LLVMValue* tsil_llvm_inst_udiv(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateUDiv(left, right);
}

LLVMValue* tsil_llvm_inst_sdiv(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSDiv(left, right);
}

LLVMValue* tsil_llvm_inst_fdiv(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFDiv(left, right);
}

LLVMValue* tsil_llvm_inst_urem(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateURem(left, right);
}

LLVMValue* tsil_llvm_inst_srem(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSRem(left, right);
}

LLVMValue* tsil_llvm_inst_frem(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFRem(left, right);
}

LLVMValue* tsil_llvm_inst_icmp_sgt(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateICmp(llvm::CmpInst::Predicate::ICMP_SGT, left, right);
}

LLVMValue* tsil_llvm_inst_icmp_ugt(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateICmp(llvm::CmpInst::Predicate::ICMP_UGT, left, right);
}

LLVMValue* tsil_llvm_inst_fcmp_ogt(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_OGT, left, right);
}

LLVMValue* tsil_llvm_inst_fcmp_ugt(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_UGT, left, right);
}

LLVMValue* tsil_llvm_inst_icmp_sge(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateICmp(llvm::CmpInst::Predicate::ICMP_SGE, left, right);
}

LLVMValue* tsil_llvm_inst_icmp_uge(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateICmp(llvm::CmpInst::Predicate::ICMP_UGE, left, right);
}

LLVMValue* tsil_llvm_inst_fcmp_oge(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_OGE, left, right);
}

LLVMValue* tsil_llvm_inst_fcmp_uge(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_UGE, left, right);
}

LLVMValue* tsil_llvm_inst_icmp_slt(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateICmp(llvm::CmpInst::Predicate::ICMP_SLT, left, right);
}

LLVMValue* tsil_llvm_inst_icmp_ult(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateICmp(llvm::CmpInst::Predicate::ICMP_ULT, left, right);
}

LLVMValue* tsil_llvm_inst_fcmp_olt(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_OLT, left, right);
}

LLVMValue* tsil_llvm_inst_fcmp_ult(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_ULT, left, right);
}

LLVMValue* tsil_llvm_inst_icmp_sle(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateICmp(llvm::CmpInst::Predicate::ICMP_SLE, left, right);
}

LLVMValue* tsil_llvm_inst_icmp_ule(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateICmp(llvm::CmpInst::Predicate::ICMP_ULE, left, right);
}

LLVMValue* tsil_llvm_inst_fcmp_ole(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_OLE, left, right);
}

LLVMValue* tsil_llvm_inst_fcmp_ule(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* left,
                                   LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_ULE, left, right);
}

LLVMValue* tsil_llvm_inst_and(TL* m,
                              LLVMBasicBlock* block,
                              LLVMValue* left,
                              LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAnd(left, right);
}

LLVMValue* tsil_llvm_inst_or(TL* m,
                             LLVMBasicBlock* block,
                             LLVMValue* left,
                             LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateOr(left, right);
}

LLVMValue* tsil_llvm_inst_xor(TL* m,
                              LLVMBasicBlock* block,
                              LLVMValue* left,
                              LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateXor(left, right);
}

LLVMValue* tsil_llvm_inst_shl(TL* m,
                              LLVMBasicBlock* block,
                              LLVMValue* left,
                              LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateShl(left, right);
}

LLVMValue* tsil_llvm_inst_lshr(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateLShr(left, right);
}

LLVMValue* tsil_llvm_inst_ashr(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* left,
                               LLVMValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAShr(left, right);
}

LLVMValue* tsil_llvm_inst_trunc(TL* m,
                                LLVMBasicBlock* block,
                                LLVMValue* value,
                                LLVMType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateTrunc(value, toType);
}

LLVMValue* tsil_llvm_inst_zext(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* value,
                               LLVMType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateZExt(value, toType);
}

LLVMValue* tsil_llvm_inst_sext(TL* m,
                               LLVMBasicBlock* block,
                               LLVMValue* value,
                               LLVMType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSExt(value, toType);
}

LLVMValue* tsil_llvm_inst_fptrunc(TL* m,
                                  LLVMBasicBlock* block,
                                  LLVMValue* value,
                                  LLVMType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPTrunc(value, toType);
}

LLVMValue* tsil_llvm_inst_fpext(TL* m,
                                LLVMBasicBlock* block,
                                LLVMValue* value,
                                LLVMType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPExt(value, toType);
}

LLVMValue* tsil_llvm_inst_fptoui(TL* m,
                                 LLVMBasicBlock* block,
                                 LLVMValue* value,
                                 LLVMType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPToUI(value, toType);
}

LLVMValue* tsil_llvm_inst_fptosi(TL* m,
                                 LLVMBasicBlock* block,
                                 LLVMValue* value,
                                 LLVMType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPToSI(value, toType);
}

LLVMValue* tsil_llvm_inst_uitofp(TL* m,
                                 LLVMBasicBlock* block,
                                 LLVMValue* value,
                                 LLVMType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateUIToFP(value, toType);
}

LLVMValue* tsil_llvm_inst_sitofp(TL* m,
                                 LLVMBasicBlock* block,
                                 LLVMValue* value,
                                 LLVMType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSIToFP(value, toType);
}

LLVMValue* tsil_llvm_inst_ptrtoint(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* value,
                                   LLVMType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreatePtrToInt(value, toType);
}

LLVMValue* tsil_llvm_inst_inttoptr(TL* m,
                                   LLVMBasicBlock* block,
                                   LLVMValue* value,
                                   LLVMType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateIntToPtr(value, toType);
}

LLVMValue* tsil_llvm_inst_bitcast(TL* m,
                                  LLVMBasicBlock* block,
                                  LLVMValue* value,
                                  LLVMType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateBitCast(value, toType);
}

LLVMType* tsil_llvm_type_get_pointer_to(TL* m, LLVMType* type) {
  return llvm::PointerType::get(type, 0);
}

LLVMType* tsil_llvm_type_get_array_of(TL* m,
                                      LLVMType* type,
                                      unsigned long size) {
  return llvm::ArrayType::get(type, size);
}

LLVMType* tsil_llvm_get_void_type(TL* m) {
  return llvm::Type::getVoidTy(*m->llvmContext);
}

LLVMType* tsil_llvm_get_pointer_type(TL* m) {
  return tsil_llvm_type_get_pointer_to(m, tsil_llvm_get_void_type(m));
}

LLVMType* tsil_llvm_get_int1_type(TL* m) {
  return llvm::Type::getInt1Ty(*m->llvmContext);
}

LLVMType* tsil_llvm_get_int8_type(TL* m) {
  return llvm::Type::getInt8Ty(*m->llvmContext);
}

LLVMType* tsil_llvm_get_int16_type(TL* m) {
  return llvm::Type::getInt16Ty(*m->llvmContext);
}

LLVMType* tsil_llvm_get_int32_type(TL* m) {
  return llvm::Type::getInt32Ty(*m->llvmContext);
}

LLVMType* tsil_llvm_get_int64_type(TL* m) {
  return llvm::Type::getInt64Ty(*m->llvmContext);
}

LLVMType* tsil_llvm_get_float32_type(TL* m) {
  return llvm::Type::getFloatTy(*m->llvmContext);
}

LLVMType* tsil_llvm_get_float64_type(TL* m) {
  return llvm::Type::getDoubleTy(*m->llvmContext);
}

LLVMValue* tsil_llvm_create_int8(TL* m, char value) {
  return llvm::ConstantInt::get(*m->llvmContext, llvm::APInt(8, value));
}

LLVMValue* tsil_llvm_create_int16(TL* m, short value) {
  return llvm::ConstantInt::get(*m->llvmContext, llvm::APInt(16, value));
}

LLVMValue* tsil_llvm_create_int32(TL* m, int value) {
  return llvm::ConstantInt::get(*m->llvmContext, llvm::APInt(32, value));
}

LLVMValue* tsil_llvm_create_int64(TL* m, long value) {
  return llvm::ConstantInt::get(*m->llvmContext, llvm::APInt(64, value));
}

LLVMValue* tsil_llvm_create_uint1(TL* m, unsigned char value) {
  return llvm::ConstantInt::get(*m->llvmContext, llvm::APInt(1, value));
}

LLVMValue* tsil_llvm_create_uint8(TL* m, unsigned char value) {
  return llvm::ConstantInt::get(*m->llvmContext, llvm::APInt(8, value));
}

LLVMValue* tsil_llvm_create_uint16(TL* m, unsigned short value) {
  return llvm::ConstantInt::get(*m->llvmContext, llvm::APInt(16, value));
}

LLVMValue* tsil_llvm_create_uint32(TL* m, unsigned int value) {
  return llvm::ConstantInt::get(*m->llvmContext, llvm::APInt(32, value));
}

LLVMValue* tsil_llvm_create_uint64(TL* m, unsigned long value) {
  return llvm::ConstantInt::get(*m->llvmContext, llvm::APInt(64, value));
}

LLVMValue* tsil_llvm_create_float(TL* m, float value) {
  return llvm::ConstantFP::get(*m->llvmContext, llvm::APFloat(value));
}

LLVMValue* tsil_llvm_create_double(TL* m, double value) {
  return llvm::ConstantFP::get(*m->llvmContext, llvm::APFloat(value));
}

LLVMValue* tsil_llvm_create_string(TL* m, char* value) {
  return new llvm::GlobalVariable(
      *m->llvmModule,
      llvm::ArrayType::get(llvm::Type::getInt8Ty(*m->llvmContext),
                           strlen(value) + 1),
      true, llvm::GlobalValue::LinkageTypes::PrivateLinkage,
      llvm::ConstantDataArray::getString(*m->llvmContext, value));
}

LLVMType* tsil_llvm_get_type(TL* m, LLVMValue* value) {
  return value->getType();
}

LLVMFunctionType* tsil_llvm_get_as_function_type(TL* m, LLVMValue* value) {
  return static_cast<llvm::Function*>(value)->getFunctionType();
}

LLVMFunctionType* tsil_llvm_get_function_type(TL* m, LLVMFunction* f) {
  return static_cast<llvm::Function*>(f)->getFunctionType();
}

LLVMValue* tsil_llvm_get_function_arg_value(TL* m,
                                            LLVMFunction* f,
                                            unsigned long index) {
  return static_cast<llvm::Function*>(f)->getArg(index);
}

LLVMType* tsil_llvm_create_function_type(TL* m,
                                         LLVMType* ret_type,
                                         unsigned long params_size,
                                         LLVMType** params,
                                         unsigned long isVarArg) {
  std::vector<llvm::Type*> llvmParams(params_size);
  for (int i = 0; i < params_size; i++) {
    llvmParams[i] = params[i];
  }
  return llvm::FunctionType::get(ret_type, llvmParams, isVarArg);
}

LLVMValue* tsil_llvm_get_null(TL* m) {
  return llvm::ConstantPointerNull::get(
      llvm::PointerType::get(llvm::Type::getInt8Ty(*m->llvmContext), 0));
}

char* dumpLL(TL* m) {
  std::string str;
  llvm::raw_string_ostream os(str);
  m->llvmModule->print(os, nullptr);
  return strdup(os.str().c_str());
}

void dumpOBJ(TL* m, std::vector<unsigned char>& out) {
  llvm::InitializeAllTargetInfos();
  llvm::InitializeAllTargets();
  llvm::InitializeAllTargetMCs();
  llvm::InitializeAllAsmParsers();
  llvm::InitializeAllAsmPrinters();

  auto TargetTriple = llvm::sys::getDefaultTargetTriple();
  m->llvmModule->setTargetTriple(TargetTriple);

  std::string Error;
  auto Target = llvm::TargetRegistry::lookupTarget(TargetTriple, Error);

  // Print an error and exit if we couldn't find the requested target.
  // This generally occurs if we've forgotten to initialise the
  // TargetRegistry or we have a bogus target triple.
  if (!Target) {
    llvm::errs() << Error;
    return;
  }

  auto CPU = "generic";
  auto Features = "";

  llvm::TargetOptions opt;
  auto TheTargetMachine = Target->createTargetMachine(
      TargetTriple, CPU, Features, opt, llvm::Reloc::PIC_);

  m->llvmModule->setDataLayout(TheTargetMachine->createDataLayout());

  llvm::SmallVector<char> data;
  llvm::raw_svector_ostream dest(data);

  llvm::legacy::PassManager pass;
  auto FileType = llvm::CodeGenFileType::ObjectFile;

  if (TheTargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType)) {
    llvm::errs() << "TheTargetMachine can't emit a file of this type";
    return;
  }

  pass.run(*m->llvmModule);

  out = std::vector<unsigned char>(data.begin(), data.end());
}
}