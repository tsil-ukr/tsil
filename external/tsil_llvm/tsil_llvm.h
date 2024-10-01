extern "C" {
#ifndef XLM_TYPE
#define XLM_TYPE void
#endif
#ifndef tsil_llvm_TYPE_TYPE
#define tsil_llvm_TYPE_TYPE void
#endif
#ifndef tsil_llvm_FUNCTION_TYPE
#define tsil_llvm_FUNCTION_TYPE void
#endif
#ifndef tsil_llvm_FUNCTION_TYPE_TYPE
#define tsil_llvm_FUNCTION_TYPE_TYPE void
#endif
#ifndef tsil_llvm_VALUE_TYPE
#define tsil_llvm_VALUE_TYPE void
#endif
#ifndef tsil_llvm_BASIC_BLOCK_TYPE
#define tsil_llvm_BASIC_BLOCK_TYPE void
#endif

typedef XLM_TYPE XLM;
typedef tsil_llvm_TYPE_TYPE XLType;
typedef tsil_llvm_FUNCTION_TYPE XLFunction;
typedef tsil_llvm_FUNCTION_TYPE_TYPE XLFunctionType;
typedef tsil_llvm_VALUE_TYPE XLValue;
typedef tsil_llvm_BASIC_BLOCK_TYPE XLBasicBlock;

#define tsil_llvm_LINKAGE_EXTERNAL 0
#define tsil_llvm_LINKAGE_DSO_LOCAL 1
#define tsil_llvm_LINKAGE_INTERNAL 2

XLM* xlm_create(char* name);

XLType* tsil_llvm_create_struct(XLM* m, char* name);
XLType* tsil_llvm_set_struct_fields(XLM* m,
                                    XLType* st,
                                    unsigned long fields_size,
                                    XLType** fields);

XLFunction* tsil_llvm_declare_function(XLM* m,
                                       size_t linkage,
                                       char* name,
                                       XLType* ret_type,
                                       unsigned long params_size,
                                       XLType** params,
                                       unsigned long isVarArg);
XLBasicBlock* tsil_llvm_create_function_block(XLM* m,
                                              XLFunction* f,
                                              char* name);

XLValue* tsil_llvm_inst_alloca(XLM* m,
                               XLBasicBlock* block,
                               char* name,
                               XLType* type);
XLValue* tsil_llvm_inst_getelementptr(XLM* m,
                                      XLBasicBlock* block,
                                      XLType* type,
                                      XLValue* pointer,
                                      unsigned long indices_size,
                                      XLValue** indices);
void tsil_llvm_inst_store(XLM* m,
                          XLBasicBlock* block,
                          XLValue* value,
                          XLValue* pointer);
XLValue* tsil_llvm_inst_load(XLM* m,
                             XLBasicBlock* block,
                             XLType* type,
                             XLValue* pointer);
XLValue* tsil_llvm_inst_ret(XLM* m, XLBasicBlock* block, XLValue* value);
XLValue* tsil_llvm_inst_call_value(XLM* m,
                                   XLBasicBlock* block,
                                   XLFunctionType* ft,
                                   XLValue* value,
                                   unsigned long arguments_size,
                                   XLValue** arguments);
XLValue* tsil_llvm_inst_call_func(XLM* m,
                                  XLBasicBlock* block,
                                  XLFunction* func,
                                  unsigned long arguments_size,
                                  XLValue** arguments);
void tsil_llvm_inst_br(XLM* m, XLBasicBlock* block, XLBasicBlock* target);
void tsil_llvm_inst_br_if(XLM* m,
                          XLBasicBlock* block,
                          XLValue* condition,
                          XLBasicBlock* target_true,
                          XLBasicBlock* target_false);
XLValue* tsil_llvm_inst_icmp(XLM* m,
                             XLBasicBlock* block,
                             char* op,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_fcmp(XLM* m,
                             XLBasicBlock* block,
                             char* op,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_add(XLM* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right);
XLValue* tsil_llvm_inst_fadd(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_sub(XLM* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right);
XLValue* tsil_llvm_inst_fsub(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_mul(XLM* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right);
XLValue* tsil_llvm_inst_fmul(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_udiv(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_sdiv(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_fdiv(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_urem(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_srem(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_frem(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_and(XLM* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right);
XLValue* tsil_llvm_inst_or(XLM* m,
                           XLBasicBlock* block,
                           XLValue* left,
                           XLValue* right);
XLValue* tsil_llvm_inst_xor(XLM* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right);
XLValue* tsil_llvm_inst_shl(XLM* m,
                            XLBasicBlock* block,
                            XLValue* left,
                            XLValue* right);
XLValue* tsil_llvm_inst_lshr(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_ashr(XLM* m,
                             XLBasicBlock* block,
                             XLValue* left,
                             XLValue* right);
XLValue* tsil_llvm_inst_trunc(XLM* m,
                              XLBasicBlock* block,
                              XLValue* value,
                              XLType* toType);
XLValue* tsil_llvm_inst_zext(XLM* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType);
XLValue* tsil_llvm_inst_sext(XLM* m,
                             XLBasicBlock* block,
                             XLValue* value,
                             XLType* toType);
XLValue* tsil_llvm_inst_fptrunc(XLM* m,
                                XLBasicBlock* block,
                                XLValue* value,
                                XLType* toType);
XLValue* tsil_llvm_inst_fpext(XLM* m,
                              XLBasicBlock* block,
                              XLValue* value,
                              XLType* toType);
XLValue* tsil_llvm_inst_fptoui(XLM* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType);
XLValue* tsil_llvm_inst_fptosi(XLM* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType);
XLValue* tsil_llvm_inst_uitofp(XLM* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType);
XLValue* tsil_llvm_inst_sitofp(XLM* m,
                               XLBasicBlock* block,
                               XLValue* value,
                               XLType* toType);
XLValue* tsil_llvm_inst_ptrtoint(XLM* m,
                                 XLBasicBlock* block,
                                 XLValue* value,
                                 XLType* toType);
XLValue* tsil_llvm_inst_inttoptr(XLM* m,
                                 XLBasicBlock* block,
                                 XLValue* value,
                                 XLType* toType);
XLValue* tsil_llvm_inst_bitcast(XLM* m,
                                XLBasicBlock* block,
                                XLValue* value,
                                XLType* toType);

XLType* tsil_llvm_type_get_pointer_to(XLM* m, XLType* type);
XLType* tsil_llvm_type_get_array_of(XLM* m, XLType* type, unsigned long size);

XLType* tsil_llvm_get_void_type(XLM* m);
XLType* tsil_llvm_get_pointer_type(XLM* m);
XLType* tsil_llvm_get_int1_type(XLM* m);
XLType* tsil_llvm_get_int8_type(XLM* m);
XLType* tsil_llvm_get_int16_type(XLM* m);
XLType* tsil_llvm_get_int32_type(XLM* m);
XLType* tsil_llvm_get_int64_type(XLM* m);
XLType* tsil_llvm_get_float32_type(XLM* m);
XLType* tsil_llvm_get_float64_type(XLM* m);

XLValue* tsil_llvm_create_int8(XLM* m, char value);
XLValue* tsil_llvm_create_int16(XLM* m, short value);
XLValue* tsil_llvm_create_int32(XLM* m, int value);
XLValue* tsil_llvm_create_int64(XLM* m, long value);
XLValue* tsil_llvm_create_uint8(XLM* m, unsigned char value);
XLValue* tsil_llvm_create_uint16(XLM* m, unsigned short value);
XLValue* tsil_llvm_create_uint32(XLM* m, unsigned int value);
XLValue* tsil_llvm_create_uint64(XLM* m, unsigned long value);
XLValue* tsil_llvm_create_float(XLM* m, float value);
XLValue* tsil_llvm_create_double(XLM* m, double value);
XLValue* tsil_llvm_create_string(XLM* m, char* value);

XLType* tsil_llvm_get_type(XLM* m, XLValue* value);
XLFunctionType* tsil_llvm_get_as_function_type(XLM* m, XLValue* value);
XLFunctionType* tsil_llvm_get_function_type(XLM* m, XLFunction* f);

XLValue* tsil_llvm_get_function_arg_value(XLM* m,
                                          XLFunction* f,
                                          unsigned long index);

XLType* tsil_llvm_create_function_type(XLM* m,
                                       XLType* ret_type,
                                       unsigned long params_size,
                                       XLType** params,
                                       unsigned long isVarArg);

XLValue* tsil_llvm_get_null(XLM* m);

char* dumpLL(XLM* m);
}