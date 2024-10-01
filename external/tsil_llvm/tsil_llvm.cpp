#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"

#include <iostream>

struct XLMStruct {
  llvm::LLVMContext* llvmContext;
  llvm::Module* llvmModule;
  llvm::IRBuilder<>* llvmBuilder;
};
#define XLM_TYPE XLMStruct
#define tsil_llvm_FUNCTION_TYPE llvm::Function
#define tsil_llvm_FUNCTION_TYPE_TYPE llvm::FunctionType
#define tsil_llvm_TYPE_TYPE llvm::Type
#define tsil_llvm_VALUE_TYPE llvm::Value
#define tsil_llvm_BASIC_BLOCK_TYPE llvm::BasicBlock
#include "tsil_llvm.h"

extern "C" {
XLM* xlm_create(char* name) {
  const auto xlModule = new XLM();
  xlModule->llvmContext = new llvm::LLVMContext();
  xlModule->llvmModule = new llvm::Module(name, *xlModule->llvmContext);
  xlModule->llvmBuilder = new llvm::IRBuilder<>(*xlModule->llvmContext);
  return xlModule;
}

XLType* tsil_llvm_create_struct(XLM* m, char* name) {
  return llvm::StructType::create(*m->llvmContext, name);
}

XLType* tsil_llvm_set_struct_fields(XLM* m,
                                    XLType* st,
                                    unsigned long fields_size,
                                    XLType** fields) {
  std::vector<llvm::Type*> llvmFields(fields_size);
  for (int i = 0; i < fields_size; i++) {
    llvmFields[i] = fields[i];
  }
  static_cast<llvm::StructType*>(st)->setBody(llvmFields);
  return st;
}

XLFunction* tsil_llvm_declare_function(XLM* m,
                                       size_t linkage,
                                       char* name,
                                       XLType* ret_type,
                                       unsigned long params_size,
                                       XLType** params,
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

XLBasicBlock* tsil_llvm_create_function_block(XLM* m,
                                              XLFunction* f,
                                              char* name) {
  return llvm::BasicBlock::Create(*m->llvmContext, name,
                                  static_cast<llvm::Function*>(f));
}

XLValue* tsil_llvm_inst_alloca(XLM* m,
                               XLBasicBlock* block,
                               char* name,
                               XLType* type) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAlloca(type, nullptr, name);
}

XLValue* tsil_llvm_inst_getelementptr(XLM* m,
                                      XLBasicBlock* block,
                                      XLType* type,
                                      XLValue* pointer,
                                      unsigned long indices_size,
                                      XLValue** indices) {
  llvm::IRBuilder<> builder(block);
  std::vector<llvm::Value*> llvmIndices(indices_size);
  for (int i = 0; i < indices_size; i++) {
    llvmIndices[i] = indices[i];
  }
  return builder.CreateGEP(type, pointer, llvmIndices);
}

void tsil_llvm_inst_store(XLM* m,
                          XLBasicBlock* block,
                          XLValue* value,
                          XLValue* pointer) {
  llvm::IRBuilder<> builder(block);
  builder.CreateStore(value, pointer);
}

size_t loadIndex = 0;

XLValue* tsil_llvm_inst_load(XLM* m,
                             XLBasicBlock* block,
                             XLType* type,
                             XLValue* pointer) {
  llvm::IRBuilder<> builder(block);
  loadIndex++;
  auto name = "load" + std::to_string(loadIndex);
  return builder.CreateLoad(type, pointer, name);
}

XLValue* tsil_llvm_inst_ret(XLM* m, XLBasicBlock* block, XLValue* value) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateRet(value);
}

XLValue* tsil_llvm_inst_call_value(XLM* m,
                                   XLBasicBlock* block,
                                   XLFunctionType* ft,
                                   XLValue* value,
                                   unsigned long arguments_size,
                                   XLValue** arguments) {
  llvm::IRBuilder<> builder(block);
  std::vector<llvm::Value*> llvmArguments(arguments_size);
  for (int i = 0; i < arguments_size; i++) {
    llvmArguments[i] = arguments[i];
  }
  return builder.CreateCall(ft, value, llvmArguments);
}

XLValue* tsil_llvm_inst_call_func(XLM* m,
                                  XLBasicBlock* block,
                                  XLFunction* func,
                                  unsigned long arguments_size,
                                  XLValue** arguments) {
  llvm::IRBuilder<> builder(block);
  std::vector<llvm::Value*> llvmArguments(arguments_size);
  for (int i = 0; i < arguments_size; i++) {
    llvmArguments[i] = arguments[i];
  }
  return builder.CreateCall(static_cast<llvm::Function*>(func), llvmArguments);
}

void tsil_llvm_inst_br(XLM* m, XLBasicBlock* block, XLBasicBlock* target) {
  llvm::IRBuilder<> builder(block);
  builder.CreateBr(target);
}

void tsil_llvm_inst_br_if(XLM* m,
                          XLBasicBlock* block,
                          XLValue* condition,
                          XLBasicBlock* target_true,
                          XLBasicBlock* target_false) {
  llvm::IRBuilder<> builder(block);
  builder.CreateCondBr(condition, target_true, target_false);
}

XLValue* tsil_llvm_inst_icmp(XLM* m,
                             XLBasicBlock* block,
                             char* op,
                             XLValue* left,
                             XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateICmp(llvm::CmpInst::Predicate::ICMP_EQ, left, right);
}

XLValue* tsil_llvm_inst_fcmp(XLM* m,
                             XLBasicBlock* block,
                             char* op,
                             XLValue* left,
                             XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_OEQ, left, right);
}

XLValue* tsil_llvm_inst_add(XLM* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAdd(left, right);
}

XLValue* tsil_llvm_inst_fadd(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFAdd(left, right);
}

XLValue* tsil_llvm_inst_sub(XLM* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSub(left, right);
}

XLValue* tsil_llvm_inst_fsub(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFSub(left, right);
}

XLValue* tsil_llvm_inst_mul(XLM* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateMul(left, right);
}

XLValue* tsil_llvm_inst_fmul(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFMul(left, right);
}

XLValue* tsil_llvm_inst_udiv(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateUDiv(left, right);
}

XLValue* tsil_llvm_inst_sdiv(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSDiv(left, right);
}

XLValue* tsil_llvm_inst_fdiv(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFDiv(left, right);
}

XLValue* tsil_llvm_inst_urem(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateURem(left, right);
}

XLValue* tsil_llvm_inst_srem(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSRem(left, right);
}

XLValue* tsil_llvm_inst_frem(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFRem(left, right);
}

XLValue* tsil_llvm_inst_and(XLM* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAnd(left, right);
}

XLValue* tsil_llvm_inst_or(XLM* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateOr(left, right);
}

XLValue* tsil_llvm_inst_xor(XLM* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateXor(left, right);
}

XLValue* tsil_llvm_inst_shl(XLM* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateShl(left, right);
}

XLValue* tsil_llvm_inst_lshr(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateLShr(left, right);
}

XLValue* tsil_llvm_inst_ashr(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAShr(left, right);
}

XLValue* tsil_llvm_inst_trunc(XLM* m,
                              XLBasicBlock* block,
                              XLValue* value,
                              XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateTrunc(value, toType);
}

XLValue* tsil_llvm_inst_zext(XLM* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateZExt(value, toType);
}

XLValue* tsil_llvm_inst_sext(XLM* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSExt(value, toType);
}

XLValue* tsil_llvm_inst_fptrunc(XLM* m,
                                XLBasicBlock* block,
                                XLValue* value,
                                XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPTrunc(value, toType);
}

XLValue* tsil_llvm_inst_fpext(XLM* m,
                              XLBasicBlock* block,
                              XLValue* value,
                              XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPExt(value, toType);
}

XLValue* tsil_llvm_inst_fptoui(XLM* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPToUI(value, toType);
}

XLValue* tsil_llvm_inst_fptosi(XLM* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPToSI(value, toType);
}

XLValue* tsil_llvm_inst_uitofp(XLM* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateUIToFP(value, toType);
}

XLValue* tsil_llvm_inst_sitofp(XLM* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSIToFP(value, toType);
}

XLValue* tsil_llvm_inst_ptrtoint(XLM* m,
                                 XLBasicBlock* block,
                                 XLValue* value,
                                 XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreatePtrToInt(value, toType);
}

XLValue* tsil_llvm_inst_inttoptr(XLM* m,
                                 XLBasicBlock* block,
                                 XLValue* value,
                                 XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateIntToPtr(value, toType);
}

XLValue* tsil_llvm_inst_bitcast(XLM* m,
                                XLBasicBlock* block,
                                XLValue* value,
                                XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateBitCast(value, toType);
}

XLType* tsil_llvm_type_get_pointer_to(XLM* m, XLType* type) {
  return llvm::PointerType::get(type, 0);
}

XLType* tsil_llvm_type_get_array_of(XLM* m, XLType* type, unsigned long size) {
  return llvm::ArrayType::get(type, size);
}

XLType* tsil_llvm_get_void_type(XLM* m) {
  return llvm::Type::getVoidTy(*m->llvmContext);
}

XLType* tsil_llvm_get_pointer_type(XLM* m) {
  return tsil_llvm_type_get_pointer_to(m, tsil_llvm_get_void_type(m));
}

XLType* tsil_llvm_get_int1_type(XLM* m) {
  return llvm::Type::getInt1Ty(*m->llvmContext);
}

XLType* tsil_llvm_get_int8_type(XLM* m) {
  return llvm::Type::getInt8Ty(*m->llvmContext);
}

XLType* tsil_llvm_get_int16_type(XLM* m) {
  return llvm::Type::getInt16Ty(*m->llvmContext);
}

XLType* tsil_llvm_get_int32_type(XLM* m) {
  return llvm::Type::getInt32Ty(*m->llvmContext);
}

XLType* tsil_llvm_get_int64_type(XLM* m) {
  return llvm::Type::getInt64Ty(*m->llvmContext);
}

XLType* tsil_llvm_get_float32_type(XLM* m) {
  return llvm::Type::getFloatTy(*m->llvmContext);
}

XLType* tsil_llvm_get_float64_type(XLM* m) {
  return llvm::Type::getDoubleTy(*m->llvmContext);
}

XLValue* tsil_llvm_create_int32(XLM* m, long value) {
  return llvm::ConstantInt::get(*m->llvmContext, llvm::APInt(32, value));
}

XLValue* tsil_llvm_create_int64(XLM* m, long value) {
  return llvm::ConstantInt::get(*m->llvmContext, llvm::APInt(64, value));
}

XLValue* tsil_llvm_create_double(XLM* m, double value) {
  return llvm::ConstantFP::get(*m->llvmContext, llvm::APFloat(value));
}

XLValue* tsil_llvm_create_string(XLM* m, char* value) {
  return new llvm::GlobalVariable(
      *m->llvmModule,
      llvm::ArrayType::get(llvm::Type::getInt8Ty(*m->llvmContext),
                           strlen(value) + 1),
      true, llvm::GlobalValue::LinkageTypes::PrivateLinkage,
      llvm::ConstantDataArray::getString(*m->llvmContext, value));
}

XLType* tsil_llvm_get_type(XLM* m, XLValue* value) {
  return value->getType();
}

XLFunctionType* tsil_llvm_get_as_function_type(XLM* m, XLValue* value) {
  return static_cast<llvm::Function*>(value)->getFunctionType();
}

XLFunctionType* tsil_llvm_get_function_type(XLM* m, XLFunction* f) {
  return static_cast<llvm::Function*>(f)->getFunctionType();
}

XLValue* tsil_llvm_get_function_arg_value(XLM* m,
                                          XLFunction* f,
                                          unsigned long index) {
  return static_cast<llvm::Function*>(f)->getArg(index);
}

XLType* tsil_llvm_create_function_type(XLM* m,
                                       XLType* ret_type,
                                       unsigned long params_size,
                                       XLType** params,
                                       unsigned long isVarArg) {
  std::vector<llvm::Type*> llvmParams(params_size);
  for (int i = 0; i < params_size; i++) {
    llvmParams[i] = params[i];
  }
  return llvm::FunctionType::get(ret_type, llvmParams, isVarArg);
}

XLValue* tsil_llvm_get_null(XLM* m) {
  return llvm::ConstantPointerNull::get(
      llvm::PointerType::get(llvm::Type::getInt8Ty(*m->llvmContext), 0));
}

char* dumpLL(XLM* m) {
  std::string str;
  llvm::raw_string_ostream os(str);
  m->llvmModule->print(os, nullptr);
  return strdup(os.str().c_str());
}
}