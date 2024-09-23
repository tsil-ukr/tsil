#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"

struct XLModuleStruct {
  llvm::LLVMContext* llvmContext;
  llvm::Module* llvmModule;
};
#define XL_MODULE_TYPE XLModuleStruct
#define XL_FUNCTION_TYPE_TYPE llvm::FunctionType
#define XL_TYPE_TYPE llvm::Type
#define XL_VALUE_TYPE llvm::Value
#define XL_FUNCTION_TYPE llvm::Function
#define XL_BASIC_BLOCK_TYPE llvm::BasicBlock
#include "xl.h"

extern "C" {
XLModule* tsil_xl_create_module(char* name) {
  const auto llvmContext = new llvm::LLVMContext();
  const auto llvmModule = new llvm::Module(name, *llvmContext);
  const auto xlModule = new XLModule();
  xlModule->llvmContext = llvmContext;
  xlModule->llvmModule = llvmModule;
  return xlModule;
}

XLType* tsil_xl_create_struct(XLModule* m, char* name) {
  return llvm::StructType::create(*m->llvmContext, name);
}

XLType* tsil_xl_set_struct_fields(XLModule* m,
                                  XLType* st,
                                  int fields_size,
                                  XLType** fields) {
  std::vector<llvm::Type*> llvmFields(fields_size);
  for (int i = 0; i < fields_size; i++) {
    llvmFields[i] = fields[i];
  }
  llvm::cast<llvm::StructType>(st)->setBody(llvmFields);
  return st;
}

XLFunction* tsil_xl_declare_function(XLModule* m,
                                     char* name,
                                     XLType* ret_type,
                                     int params_size,
                                     XLType** params) {
  std::vector<llvm::Type*> llvmParams(params_size);
  for (int i = 0; i < params_size; i++) {
    llvmParams[i] = params[i];
  }
  return llvm::Function::Create(
      llvm::FunctionType::get(ret_type, llvmParams, false),
      llvm::Function::ExternalLinkage, name, m->llvmModule);
}

XLBasicBlock* tsil_xl_create_function_block(XLModule* m,
                                            XLFunction* f,
                                            char* name) {
  return llvm::BasicBlock::Create(*m->llvmContext, name, f);
}

XLValue* tsil_xl_inst_alloca(XLModule* m,
                             XLBasicBlock* block,
                             char* name,
                             XLType* type) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAlloca(type, nullptr, name);
}

XLValue* tsil_xl_inst_getelementptr(XLModule* m,
                                    XLBasicBlock* block,
                                    XLType* type,
                                    XLValue* pointer,
                                    int indices_size,
                                    XLValue** indices) {
  llvm::IRBuilder<> builder(block);
  std::vector<llvm::Value*> llvmIndices(indices_size);
  for (int i = 0; i < indices_size; i++) {
    llvmIndices[i] = indices[i];
  }
  return builder.CreateGEP(type, pointer, llvmIndices);
}

void tsil_xl_inst_store(XLModule* m,
                        XLBasicBlock* block,
                        XLValue* value,
                        XLValue* pointer) {
  llvm::IRBuilder<> builder(block);
  builder.CreateStore(value, pointer);
}

XLValue* tsil_xl_inst_load(XLModule* m,
                           XLBasicBlock* block,
                           XLType* type,
                           XLValue* pointer) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateLoad(type, pointer);
}

XLValue* tsil_xl_inst_ret(XLModule* m, XLBasicBlock* block, XLValue* value) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateRet(value);
}

XLValue* tsil_xl_inst_call_value(XLModule* m,
                                 XLBasicBlock* block,
                                 XLFunctionType* ft,
                                 XLValue* value,
                                 int arguments_size,
                                 XLValue** arguments) {
  llvm::IRBuilder<> builder(block);
  std::vector<llvm::Value*> llvmArguments(arguments_size);
  for (int i = 0; i < arguments_size; i++) {
    llvmArguments[i] = arguments[i];
  }
  return builder.CreateCall(ft, value, llvmArguments);
}

XLValue* tsil_xl_inst_call_func(XLModule* m,
                                XLBasicBlock* block,
                                XLFunction* func,
                                int arguments_size,
                                XLValue** arguments) {
  llvm::IRBuilder<> builder(block);
  std::vector<llvm::Value*> llvmArguments(arguments_size);
  for (int i = 0; i < arguments_size; i++) {
    llvmArguments[i] = arguments[i];
  }
  return builder.CreateCall(func, llvmArguments);
}

void tsil_xl_inst_br(XLModule* m, XLBasicBlock* block, XLBasicBlock* target) {
  llvm::IRBuilder<> builder(block);
  builder.CreateBr(target);
}

void tsil_xl_inst_br_if(XLModule* m,
                        XLBasicBlock* block,
                        XLValue* condition,
                        XLBasicBlock* target_true,
                        XLBasicBlock* target_false) {
  llvm::IRBuilder<> builder(block);
  builder.CreateCondBr(condition, target_true, target_false);
}

XLValue* tsil_xl_inst_icmp(XLModule* m,
                           XLBasicBlock* block,
                           char* op,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateICmp(llvm::CmpInst::Predicate::ICMP_EQ, left, right);
}

XLValue* tsil_xl_inst_fcmp(XLModule* m,
                           XLBasicBlock* block,
                           char* op,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFCmp(llvm::CmpInst::Predicate::FCMP_OEQ, left, right);
}

XLValue* tsil_xl_inst_add(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAdd(left, right);
}

XLValue* tsil_xl_inst_fadd(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFAdd(left, right);
}

XLValue* tsil_xl_inst_sub(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSub(left, right);
}

XLValue* tsil_xl_inst_fsub(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFSub(left, right);
}

XLValue* tsil_xl_inst_mul(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateMul(left, right);
}

XLValue* tsil_xl_inst_fmul(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFMul(left, right);
}

XLValue* tsil_xl_inst_udiv(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateUDiv(left, right);
}

XLValue* tsil_xl_inst_sdiv(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSDiv(left, right);
}

XLValue* tsil_xl_inst_fdiv(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFDiv(left, right);
}

XLValue* tsil_xl_inst_mod(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateURem(left, right);
}

XLValue* tsil_xl_inst_fmod(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFRem(left, right);
}

XLValue* tsil_xl_inst_and(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAnd(left, right);
}

XLValue* tsil_xl_inst_or(XLModule* m,
                         XLBasicBlock* block,
                         XLValue* left,
                         XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateOr(left, right);
}

XLValue* tsil_xl_inst_xor(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateXor(left, right);
}

XLValue* tsil_xl_inst_shl(XLModule* m,
                          XLBasicBlock* block,
                          XLValue* left,
                          XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateShl(left, right);
}

XLValue* tsil_xl_inst_lshr(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateLShr(left, right);
}

XLValue* tsil_xl_inst_ashr(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateAShr(left, right);
}

XLValue* tsil_xl_inst_trunc(XLModule* m,
                            XLBasicBlock* block,
                            XLValue* value,
                            XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateTrunc(value, toType);
}

XLValue* tsil_xl_inst_zext(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* value,
                           XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateZExt(value, toType);
}

XLValue* tsil_xl_inst_sext(XLModule* m,
                           XLBasicBlock* block,
                           XLValue* value,
                           XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSExt(value, toType);
}

XLValue* tsil_xl_inst_fptrunc(XLModule* m,
                              XLBasicBlock* block,
                              XLValue* value,
                              XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPTrunc(value, toType);
}

XLValue* tsil_xl_inst_fpext(XLModule* m,
                            XLBasicBlock* block,
                            XLValue* value,
                            XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPExt(value, toType);
}

XLValue* tsil_xl_inst_fptoui(XLModule* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPToUI(value, toType);
}

XLValue* tsil_xl_inst_fptosi(XLModule* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateFPToSI(value, toType);
}

XLValue* tsil_xl_inst_uitofp(XLModule* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateUIToFP(value, toType);
}

XLValue* tsil_xl_inst_sitofp(XLModule* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateSIToFP(value, toType);
}

XLValue* tsil_xl_inst_ptrtoint(XLModule* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreatePtrToInt(value, toType);
}

XLValue* tsil_xl_inst_inttoptr(XLModule* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateIntToPtr(value, toType);
}

XLValue* tsil_xl_inst_bitcast(XLModule* m,
                              XLBasicBlock* block,
                              XLValue* value,
                              XLType* toType) {
  llvm::IRBuilder<> builder(block);
  return builder.CreateBitCast(value, toType);
}
}