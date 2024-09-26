#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"

#include <iostream>

struct XLMStruct {
  llvm::LLVMContext* llvmContext;
  llvm::Module* llvmModule;
  llvm::IRBuilder<>* llvmBuilder;
};
#define XLM_TYPE XLMStruct
#define XL_FUNCTION_TYPE llvm::Function
#define XL_FUNCTION_TYPE_TYPE llvm::FunctionType
#define XL_TYPE_TYPE llvm::Type
#define XL_VALUE_TYPE llvm::Value
#define XL_BASIC_BLOCK_TYPE llvm::BasicBlock
#include "xl.h"

extern "C" {
XLM* xlm_create(char* name) {
  const auto xlModule = new XLM();
  xlModule->llvmContext = new llvm::LLVMContext();
  xlModule->llvmModule = new llvm::Module(name, *xlModule->llvmContext);
  xlModule->llvmBuilder = new llvm::IRBuilder<>(*xlModule->llvmContext);
  return xlModule;
}

XLType* xl_create_struct(XLM* m, char* name) {
  return llvm::StructType::create(*m->llvmContext, name);
}

XLType* xl_set_struct_fields(XLM* m,
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

XLFunction* xl_declare_function(XLM* m,
                                char* name,
                                XLType* ret_type,
                                unsigned long params_size,
                                XLType** params,
                                unsigned long isVarArg) {
  std::vector<llvm::Type*> llvmParams(params_size);
  for (int i = 0; i < params_size; i++) {
    llvmParams[i] = params[i];
  }
  return llvm::Function::Create(
      llvm::FunctionType::get(ret_type, llvmParams, isVarArg),
      llvm::Function::ExternalLinkage, name, m->llvmModule);
}

XLBasicBlock* xl_create_function_block(XLM* m, XLFunction* f, char* name) {
  return llvm::BasicBlock::Create(*m->llvmContext, name,
                                  static_cast<llvm::Function*>(f));
}

XLValue* xl_inst_alloca(XLM* m, XLBasicBlock* block, char* name, XLType* type) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAlloca(type, nullptr, name);
}

XLValue* xl_inst_getelementptr(XLM* m,
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

void xl_inst_store(XLM* m,
                   XLBasicBlock* block,
                   XLValue* value,
                   XLValue* pointer) {
  llvm::IRBuilder<> builder(block);
  builder.CreateStore(value, pointer);
}

size_t loadIndex = 0;

XLValue* xl_inst_load(XLM* m,
                      XLBasicBlock* block,
                      XLType* type,
                      XLValue* pointer) {
  llvm::IRBuilder<> builder(block);
  loadIndex++;
  auto name = "load" + std::to_string(loadIndex);
  return builder.CreateLoad(type, pointer, name);
}

XLValue* xl_inst_ret(XLM* m, XLBasicBlock* block, XLValue* value) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateRet(value);
}

XLValue* xl_inst_call_value(XLM* m,
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

XLValue* xl_inst_call_func(XLM* m,
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

void xl_inst_br(XLM* m, XLBasicBlock* block, XLBasicBlock* target) {
  llvm::IRBuilder<> builder(block);
  builder.CreateBr(target);
}

void xl_inst_br_if(XLM* m,
                   XLBasicBlock* block,
                   XLValue* condition,
                   XLBasicBlock* target_true,
                   XLBasicBlock* target_false) {
  llvm::IRBuilder<> builder(block);
  builder.CreateCondBr(condition, target_true, target_false);
}

XLValue* xl_inst_icmp(XLM* m,
                      XLBasicBlock* block,
                      char* op,
                      XLValue* left,
                      XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateICmp(llvm::CmpInst::Predicate::ICMP_EQ, left, right);
}

XLValue* xl_inst_fcmp(XLM* m,
                      XLBasicBlock* block,
                      char* op,
                      XLValue* left,
                      XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_OEQ, left, right);
}

XLValue* xl_inst_add(XLM* m,
                     XLBasicBlock* block,
                     XLValue* left,
                     XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAdd(left, right);
}

XLValue* xl_inst_fadd(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFAdd(left, right);
}

XLValue* xl_inst_sub(XLM* m,
                     XLBasicBlock* block,
                     XLValue* left,
                     XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSub(left, right);
}

XLValue* xl_inst_fsub(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFSub(left, right);
}

XLValue* xl_inst_mul(XLM* m,
                     XLBasicBlock* block,
                     XLValue* left,
                     XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateMul(left, right);
}

XLValue* xl_inst_fmul(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFMul(left, right);
}

XLValue* xl_inst_udiv(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateUDiv(left, right);
}

XLValue* xl_inst_sdiv(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSDiv(left, right);
}

XLValue* xl_inst_fdiv(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFDiv(left, right);
}

XLValue* xl_inst_mod(XLM* m,
                     XLBasicBlock* block,
                     XLValue* left,
                     XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateURem(left, right);
}

XLValue* xl_inst_fmod(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFRem(left, right);
}

XLValue* xl_inst_and(XLM* m,
                     XLBasicBlock* block,
                     XLValue* left,
                     XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAnd(left, right);
}

XLValue* xl_inst_or(XLM* m,
                    XLBasicBlock* block,
                    XLValue* left,
                    XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateOr(left, right);
}

XLValue* xl_inst_xor(XLM* m,
                     XLBasicBlock* block,
                     XLValue* left,
                     XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateXor(left, right);
}

XLValue* xl_inst_shl(XLM* m,
                     XLBasicBlock* block,
                     XLValue* left,
                     XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateShl(left, right);
}

XLValue* xl_inst_lshr(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateLShr(left, right);
}

XLValue* xl_inst_ashr(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAShr(left, right);
}

XLValue* xl_inst_trunc(XLM* m,
                       XLBasicBlock* block,
                       XLValue* value,
                       XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateTrunc(value, toType);
}

XLValue* xl_inst_zext(XLM* m,
                      XLBasicBlock* block,
                      XLValue* value,
                      XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateZExt(value, toType);
}

XLValue* xl_inst_sext(XLM* m,
                      XLBasicBlock* block,
                      XLValue* value,
                      XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSExt(value, toType);
}

XLValue* xl_inst_fptrunc(XLM* m,
                         XLBasicBlock* block,
                         XLValue* value,
                         XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPTrunc(value, toType);
}

XLValue* xl_inst_fpext(XLM* m,
                       XLBasicBlock* block,
                       XLValue* value,
                       XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPExt(value, toType);
}

XLValue* xl_inst_fptoui(XLM* m,
                        XLBasicBlock* block,
                        XLValue* value,
                        XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPToUI(value, toType);
}

XLValue* xl_inst_fptosi(XLM* m,
                        XLBasicBlock* block,
                        XLValue* value,
                        XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPToSI(value, toType);
}

XLValue* xl_inst_uitofp(XLM* m,
                        XLBasicBlock* block,
                        XLValue* value,
                        XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateUIToFP(value, toType);
}

XLValue* xl_inst_sitofp(XLM* m,
                        XLBasicBlock* block,
                        XLValue* value,
                        XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSIToFP(value, toType);
}

XLValue* xl_inst_ptrtoint(XLM* m,
                          XLBasicBlock* block,
                          XLValue* value,
                          XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreatePtrToInt(value, toType);
}

XLValue* xl_inst_inttoptr(XLM* m,
                          XLBasicBlock* block,
                          XLValue* value,
                          XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateIntToPtr(value, toType);
}

XLValue* xl_inst_bitcast(XLM* m,
                         XLBasicBlock* block,
                         XLValue* value,
                         XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateBitCast(value, toType);
}

XLType* xl_type_get_pointer_to(XLM* m, XLType* type) {
  return llvm::PointerType::get(type, 0);
}

XLType* xl_type_get_array_of(XLM* m, XLType* type, unsigned long size) {
  return llvm::ArrayType::get(type, size);
}

XLType* xl_get_void_type(XLM* m) {
  return llvm::Type::getVoidTy(*m->llvmContext);
}

XLType* xl_get_pointer_type(XLM* m) {
  return xl_type_get_pointer_to(m, xl_get_void_type(m));
}

XLType* xl_get_int1_type(XLM* m) {
  return llvm::Type::getInt1Ty(*m->llvmContext);
}

XLType* xl_get_int8_type(XLM* m) {
  return llvm::Type::getInt8Ty(*m->llvmContext);
}

XLType* xl_get_int16_type(XLM* m) {
  return llvm::Type::getInt16Ty(*m->llvmContext);
}

XLType* xl_get_int32_type(XLM* m) {
  return llvm::Type::getInt32Ty(*m->llvmContext);
}

XLType* xl_get_int64_type(XLM* m) {
  return llvm::Type::getInt64Ty(*m->llvmContext);
}

XLType* xl_get_float32_type(XLM* m) {
  return llvm::Type::getFloatTy(*m->llvmContext);
}

XLType* xl_get_float64_type(XLM* m) {
  return llvm::Type::getDoubleTy(*m->llvmContext);
}

XLValue* xl_create_int32(XLM* m, long value) {
  return llvm::ConstantInt::get(*m->llvmContext, llvm::APInt(32, value));
}

XLValue* xl_create_int64(XLM* m, long value) {
  return llvm::ConstantInt::get(*m->llvmContext, llvm::APInt(64, value));
}

XLValue* xl_create_double(XLM* m, double value) {
  return llvm::ConstantFP::get(*m->llvmContext, llvm::APFloat(value));
}

XLValue* xl_create_string(XLM* m, char* value) {
  return new llvm::GlobalVariable(
      *m->llvmModule,
      llvm::ArrayType::get(llvm::Type::getInt8Ty(*m->llvmContext),
                           strlen(value) + 1),
      true, llvm::GlobalValue::LinkageTypes::PrivateLinkage,
      llvm::ConstantDataArray::getString(*m->llvmContext, value));
}

XLType* xl_get_type(XLM* m, XLValue* value) {
  return value->getType();
}

XLFunctionType* xl_get_as_function_type(XLM* m, XLValue* value) {
  return static_cast<llvm::Function*>(value)->getFunctionType();
}

XLValue* xl_get_function_arg_value(XLM* m, XLFunction* f, unsigned long index) {
  return static_cast<llvm::Function*>(f)->getArg(index);
}

XLType* xl_create_function_type(XLM* m,
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

XLValue* xl_get_null(XLM* m) {
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