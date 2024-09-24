extern "C" {
#ifndef XLM_TYPE
#define XLM_TYPE void
#endif
#ifndef XL_TYPE_TYPE
#define XL_TYPE_TYPE void
#endif
#ifndef XL_FUNCTION_TYPE
#define XL_FUNCTION_TYPE void
#endif
#ifndef XL_FUNCTION_TYPE_TYPE
#define XL_FUNCTION_TYPE_TYPE void
#endif
#ifndef XL_VALUE_TYPE
#define XL_VALUE_TYPE void
#endif
#ifndef XL_BASIC_BLOCK_TYPE
#define XL_BASIC_BLOCK_TYPE void
#endif

typedef XLM_TYPE XLM;
typedef XL_TYPE_TYPE XLType;
typedef XL_FUNCTION_TYPE XLFunction;
typedef XL_FUNCTION_TYPE_TYPE XLFunctionType;
typedef XL_VALUE_TYPE XLValue;
typedef XL_BASIC_BLOCK_TYPE XLBasicBlock;

XLM* xlm_create(char* name);

XLType* xl_create_struct(XLM* m, char* name);
XLType* xl_set_struct_fields(XLM* m,
                             XLType* st,
                             int fields_size,
                             XLType** fields);

XLFunction* xl_declare_function(XLM* m,
                                char* name,
                                XLType* ret_type,
                                int params_size,
                                XLType** params,
                                bool isVarArg);
XLBasicBlock* xl_create_function_block(XLM* m, XLFunction* f, char* name);

XLValue* xl_inst_alloca(XLM* m, XLBasicBlock* block, char* name, XLType* type);
XLValue* xl_inst_getelementptr(XLM* m,
                               XLBasicBlock* block,
                               XLType* type,
                               XLValue* pointer,
                               int indices_size,
                               XLValue** indices);
void xl_inst_store(XLM* m,
                   XLBasicBlock* block,
                   XLValue* value,
                   XLValue* pointer);
XLValue* xl_inst_load(XLM* m,
                      XLBasicBlock* block,
                      XLType* type,
                      XLValue* pointer);
XLValue* xl_inst_ret(XLM* m, XLBasicBlock* block, XLValue* value);
XLValue* xl_inst_call_value(XLM* m,
                            XLBasicBlock* block,
                            XLFunctionType* ft,
                            XLValue* value,
                            int arguments_size,
                            XLValue** arguments);
XLValue* xl_inst_call_func(XLM* m,
                           XLBasicBlock* block,
                           XLFunction* func,
                           int arguments_size,
                           XLValue** arguments);
void xl_inst_br(XLM* m, XLBasicBlock* block, XLBasicBlock* target);
void xl_inst_br_if(XLM* m,
                   XLBasicBlock* block,
                   XLValue* condition,
                   XLBasicBlock* target_true,
                   XLBasicBlock* target_false);
XLValue* xl_inst_icmp(XLM* m,
                      XLBasicBlock* block,
                      char* op,
                      XLValue* left,
                      XLValue* right);
XLValue* xl_inst_fcmp(XLM* m,
                      XLBasicBlock* block,
                      char* op,
                      XLValue* left,
                      XLValue* right);
XLValue* xl_inst_add(XLM* m,
                     XLBasicBlock* block,
                     XLValue* left,
                     XLValue* right);
XLValue* xl_inst_fadd(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right);
XLValue* xl_inst_sub(XLM* m,
                     XLBasicBlock* block,
                     XLValue* left,
                     XLValue* right);
XLValue* xl_inst_fsub(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right);
XLValue* xl_inst_mul(XLM* m,
                     XLBasicBlock* block,
                     XLValue* left,
                     XLValue* right);
XLValue* xl_inst_fmul(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right);
XLValue* xl_inst_udiv(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right);
XLValue* xl_inst_sdiv(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right);
XLValue* xl_inst_fdiv(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right);
XLValue* xl_inst_mod(XLM* m,
                     XLBasicBlock* block,
                     XLValue* left,
                     XLValue* right);
XLValue* xl_inst_fmod(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right);
XLValue* xl_inst_and(XLM* m,
                     XLBasicBlock* block,
                     XLValue* left,
                     XLValue* right);
XLValue* xl_inst_or(XLM* m, XLBasicBlock* block, XLValue* left, XLValue* right);
XLValue* xl_inst_xor(XLM* m,
                     XLBasicBlock* block,
                     XLValue* left,
                     XLValue* right);
XLValue* xl_inst_shl(XLM* m,
                     XLBasicBlock* block,
                     XLValue* left,
                     XLValue* right);
XLValue* xl_inst_lshr(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right);
XLValue* xl_inst_ashr(XLM* m,
                      XLBasicBlock* block,
                      XLValue* left,
                      XLValue* right);
XLValue* xl_inst_trunc(XLM* m,
                       XLBasicBlock* block,
                       XLValue* value,
                       XLType* toType);
XLValue* xl_inst_zext(XLM* m,
                      XLBasicBlock* block,
                      XLValue* value,
                      XLType* toType);
XLValue* xl_inst_sext(XLM* m,
                      XLBasicBlock* block,
                      XLValue* value,
                      XLType* toType);
XLValue* xl_inst_fptrunc(XLM* m,
                         XLBasicBlock* block,
                         XLValue* value,
                         XLType* toType);
XLValue* xl_inst_fpext(XLM* m,
                       XLBasicBlock* block,
                       XLValue* value,
                       XLType* toType);
XLValue* xl_inst_fptoui(XLM* m,
                        XLBasicBlock* block,
                        XLValue* value,
                        XLType* toType);
XLValue* xl_inst_fptosi(XLM* m,
                        XLBasicBlock* block,
                        XLValue* value,
                        XLType* toType);
XLValue* xl_inst_uitofp(XLM* m,
                        XLBasicBlock* block,
                        XLValue* value,
                        XLType* toType);
XLValue* xl_inst_sitofp(XLM* m,
                        XLBasicBlock* block,
                        XLValue* value,
                        XLType* toType);
XLValue* xl_inst_ptrtoint(XLM* m,
                          XLBasicBlock* block,
                          XLValue* value,
                          XLType* toType);
XLValue* xl_inst_inttoptr(XLM* m,
                          XLBasicBlock* block,
                          XLValue* value,
                          XLType* toType);
XLValue* xl_inst_bitcast(XLM* m,
                         XLBasicBlock* block,
                         XLValue* value,
                         XLType* toType);

XLType* xl_type_get_pointer_to(XLM* m, XLType* type);
XLType* xl_type_get_array_of(XLM* m, XLType* type, int size);

XLType* xl_get_void_type(XLM* m);
XLType* xl_get_pointer_type(XLM* m);
XLType* xl_get_int1_type(XLM* m);
XLType* xl_get_int8_type(XLM* m);
XLType* xl_get_int16_type(XLM* m);
XLType* xl_get_int32_type(XLM* m);
XLType* xl_get_int64_type(XLM* m);
XLType* xl_get_float32_type(XLM* m);
XLType* xl_get_float64_type(XLM* m);

XLValue* xl_create_int32(XLM* m, int value);
XLValue* xl_create_int64(XLM* m, long value);
XLValue* xl_create_double(XLM* m, double value);
XLValue* xl_create_string(XLM* m, char* value);

XLType* xl_get_type(XLM* m, XLValue* value);
XLFunctionType* xl_get_as_function_type(XLM* m, XLValue* value);

XLValue* xl_get_function_arg_value(XLM* m, XLFunction* f, int index);

XLType* xl_create_function_type(XLM* m,
                                XLType* ret_type,
                                int params_size,
                                XLType** params,
                                bool isVarArg);

XLValue* xl_get_null(XLM* m);

char* dumpLL(XLM* m);
}