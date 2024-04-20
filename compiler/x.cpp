#include "x.h"

namespace tsil::x {
  void implode(std::vector<std::string>& v,
               const std::string& sep,
               std::string& result) {
    for (size_t i = 0; i < v.size(); i++) {
      result += v[i];
      if (i < v.size() - 1) {
        result += sep;
      }
    }
  }

  Value* Module::putStringConstant(const std::string& value) {
    auto constant = new Constant();
    constant->variable_index = this->variable_counter++;
    constant->name = "@const." + std::to_string(constant->variable_index);
    constant->type = this->pointerType;
    constant->value = value;
    this->constants[constant->name] = constant;
    return new Value(this->pointerType, constant->name);
  }

  Value* Module::putI64Constant(long value) {
    auto constant = new Constant();
    constant->variable_index = this->variable_counter++;
    constant->name = "@const." + std::to_string(constant->variable_index);
    constant->type = this->int64Type;
    constant->value = std::to_string(value);
    this->constants[constant->name] = constant;
    return new Value(this->pointerType, constant->name);
  }

  Value* Module::putI8Constant(char value) {
    auto constant = new Constant();
    constant->variable_index = this->variable_counter++;
    constant->name = "@const." + std::to_string(constant->variable_index);
    constant->type = this->int8Type;
    constant->value = std::to_string(value);
    this->constants[constant->name] = constant;
    return new Value(this->pointerType, constant->name);
  }

  Type* Module::defineNativeType(const std::string& name) {
    auto type = new Type();
    type->variable_index = this->variable_counter++;
    type->type = TypeTypeNative;
    type->name = name;
    this->types[name] = type;
    return type;
  }

  Type* Module::defineStructType(const std::string& name,
                                 std::vector<Type*> fields) {
    auto type = new Type();
    type->variable_index = this->variable_counter++;
    type->type = TypeTypeType;
    type->name = "%struct." + std::to_string(type->variable_index);
    type->fields = fields;
    this->types[name] = type;
    return type;
  }

  std::pair<Function*, Value*> Module::declareFunction(
      const std::string& name,
      Type* result_type,
      std::vector<Value*> parameters) {
    auto function = new Function();
    function->name = "@\"" + name + "\"";
    function->result_type = result_type;
    function->parameters = parameters;
    this->functions[name] = function;
    return {function, new Value(this->pointerType, function->name)};
  }

  Value* Module::defineFunction(const std::string& name,
                                Type* result_type,
                                std::vector<Value*> parameters) {
    auto function = new Function();
    function->name = "@" + name;
    function->result_type = result_type;
    function->parameters = parameters;
    const auto entryBlock = this->defineFunctionBlock(function, "entry");
    if (result_type) {
      if (result_type != this->voidType) {
        function->return_alloca =
            this->pushFunctionBlockAllocaInstruction(entryBlock, result_type);
        const auto exitBlock = this->defineFunctionBlock(function, "exit");
        const auto loadedReturnValue = this->pushFunctionBlockLoadInstruction(
            exitBlock, result_type, function->return_alloca);
        this->pushFunctionBlockRetInstruction(exitBlock, result_type,
                                              loadedReturnValue);
      }
    }
    this->functions[name] = function;
    return new Value(this->pointerType, function->name);
  }

  FunctionBlock* Module::defineFunctionBlock(Function* function,
                                             const std::string& name) {
    auto block = new FunctionBlock();
    block->name = name + "." + std::to_string(function->blocks.size());
    function->blocks.push_back(block);
    return block;
  }

  FunctionBlock* Module::getFunctionBlock(Function* function,
                                          const std::string& name) {
    for (const auto& b : function->blocks) {
      if (b->name == name) {
        return b;
        break;
      }
    }
    return nullptr;
  }

  Value* Module::pushFunctionBlockAllocaInstruction(FunctionBlock* block,
                                                    tsil::x::Type* type) {
    const auto instruction = new FunctionInstruction();
    const auto alloca = new FunctionInstructionAlloca();
    alloca->type = type;
    instruction->name = "%alloca." + std::to_string(this->variable_counter++);
    instruction->alloca = alloca;
    block->instructions.push_back(instruction);
    return new Value(this->pointerType, instruction->name);
  }

  Value* Module::pushFunctionBlockGetElementPtrInstruction(
      FunctionBlock* block,
      Type* type,
      Value* pointer,
      std::vector<size_t> indexes) {
    const auto instruction = new FunctionInstruction();
    const auto getelementptr = new FunctionInstructionGetElementPtr();
    getelementptr->type = type;
    getelementptr->pointer = pointer;
    getelementptr->indexes = indexes;
    instruction->name =
        "%getelementptr." + std::to_string(this->variable_counter++);
    instruction->getelementptr = getelementptr;
    block->instructions.push_back(instruction);
    return new Value(this->pointerType, instruction->name);
  }

  FunctionInstruction* Module::pushFunctionBlockStoreInstruction(
      FunctionBlock* block,
      Type* type,
      Value* value,
      Value* pointer) {
    const auto instruction = new FunctionInstruction();
    const auto store = new FunctionInstructionStore();
    store->type = type;
    store->value = value;
    store->pointer = pointer;
    instruction->store = store;
    block->instructions.push_back(instruction);
    return instruction;
  }

  Value* Module::pushFunctionBlockLoadInstruction(FunctionBlock* block,
                                                  Type* type,
                                                  Value* pointer) {
    const auto instruction = new FunctionInstruction();
    const auto load = new FunctionInstructionLoad();
    load->type = type;
    load->pointer = pointer;
    instruction->name = "%load." + std::to_string(this->variable_counter++);
    instruction->load = load;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  FunctionInstruction* Module::pushFunctionBlockRetInstruction(
      FunctionBlock* block,
      Type* type,
      Value* value) {
    const auto instruction = new FunctionInstruction();
    const auto ret = new FunctionInstructionRet();
    ret->type = type;
    ret->value = value;
    instruction->ret = ret;
    block->instructions.push_back(instruction);
    return instruction;
  }

  Value* Module::pushFunctionBlockCallInstruction(
      FunctionBlock* block,
      Type* type,
      Value* value,
      std::vector<Value*> arguments) {
    const auto instruction = new FunctionInstruction();
    const auto call = new FunctionInstructionCall();
    call->type = type;
    call->value = value;
    call->arguments = arguments;
    instruction->name = "%call." + std::to_string(this->variable_counter++);
    instruction->call = call;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  FunctionInstruction* Module::pushFunctionBlockBrInstruction(
      FunctionBlock* block,
      FunctionBlock* target) {
    const auto instruction = new FunctionInstruction();
    const auto br = new FunctionInstructionBr();
    br->target = target;
    instruction->br = br;
    block->instructions.push_back(instruction);
    return instruction;
  }

  FunctionInstruction* Module::pushFunctionBlockBrIfInstruction(
      FunctionBlock* block,
      Value* condition,
      FunctionBlock* target_true,
      FunctionBlock* target_false) {
    const auto instruction = new FunctionInstruction();
    const auto brif = new FunctionInstructionBrIf();
    brif->condition = condition;
    brif->target_true = target_true;
    brif->target_false = target_false;
    instruction->brif = brif;
    block->instructions.push_back(instruction);
    return instruction;
  }

  Value* Module::pushFunctionBlockICmpInstruction(FunctionBlock* block,
                                                  const std::string& op,
                                                  Type* type,
                                                  Value* left,
                                                  Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto icmp = new FunctionInstructionICmp();
    icmp->op = op;
    icmp->type = type;
    icmp->left = left;
    icmp->right = right;
    instruction->name = "%icmp." + std::to_string(this->variable_counter++);
    instruction->icmp = icmp;
    block->instructions.push_back(instruction);
    return new Value(this->int1Type, instruction->name);
  }

  Value* Module::pushFunctionBlockAddInstruction(FunctionBlock* block,
                                                 Type* type,
                                                 Value* left,
                                                 Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto add = new FunctionInstructionAdd();
    add->type = type;
    add->left = left;
    add->right = right;
    instruction->name = "%add." + std::to_string(this->variable_counter++);
    instruction->add = add;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockSubInstruction(FunctionBlock* block,
                                                 Type* type,
                                                 Value* left,
                                                 Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto sub = new FunctionInstructionSub();
    sub->type = type;
    sub->left = left;
    sub->right = right;
    instruction->name = "%sub." + std::to_string(this->variable_counter++);
    instruction->sub = sub;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockMulInstruction(FunctionBlock* block,
                                                 Type* type,
                                                 Value* left,
                                                 Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto mul = new FunctionInstructionMul();
    mul->type = type;
    mul->left = left;
    mul->right = right;
    instruction->name = "%mul." + std::to_string(this->variable_counter++);
    instruction->mul = mul;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockDivInstruction(FunctionBlock* block,
                                                 Type* type,
                                                 Value* left,
                                                 Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto div = new FunctionInstructionDiv();
    div->type = type;
    div->left = left;
    div->right = right;
    instruction->name = "%div." + std::to_string(this->variable_counter++);
    instruction->div = div;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  Value* Module::pushFunctionBlockModInstruction(FunctionBlock* block,
                                                 Type* type,
                                                 Value* left,
                                                 Value* right) {
    const auto instruction = new FunctionInstruction();
    const auto mod = new FunctionInstructionMod();
    mod->type = type;
    mod->left = left;
    mod->right = right;
    instruction->name = "%mod." + std::to_string(this->variable_counter++);
    instruction->mod = mod;
    block->instructions.push_back(instruction);
    return new Value(type, instruction->name);
  }

  std::string Module::dumpLL() {
    std::vector<std::string> lines;

    for (const auto& [name, constant] : this->constants) {
      lines.push_back(constant->dumpLL(this));
    }

    for (const auto& [name, type] : this->types) {
      if (type->type == TypeTypeType) {
        lines.push_back(type->dumpLL(this));
      }
    }

    for (const auto& [name, function] : this->functions) {
      lines.push_back(function->dumpLL(this));
    }

    std::string result;
    implode(lines, "\n", result);
    return result;
  }

  std::string Value::dumpLL(tsil::x::Module* module) {
    return this->type->name + " " + this->name;
  }

  std::string Constant::dumpLL(Module* module) {
    if (this->type == module->int8Type) {
      return this->name + " = constant " + this->type->name + " " + this->value;
    }
    if (this->type == module->int64Type) {
      return this->name + " = constant " + this->type->name + " " + this->value;
    }
    return this->name + " = constant [" +
           std::to_string(this->value.size() + 1) + " x i8] c\"" + this->value +
           "\\00\"";
  }

  std::string Type::dumpLL(Module* module) {
    if (this->type == TypeTypeNative) {
      return this->name;
    } else {
      std::vector<std::string> fields;
      for (const auto& field : this->fields) {
        fields.push_back(field->name);
      }
      std::string result = this->name + " = type { ";
      implode(fields, ", ", result);
      result += " }";
      return result;
    }
  }

  std::string Function::dumpLL(Module* module) {
    std::vector<std::string> parameters;
    for (const auto& parameter : this->parameters) {
      parameters.push_back(parameter->dumpLL(module));
    }
    if (this->blocks.empty()) {
      std::string result = "declare ";
      result += this->result_type->name;
      result += " ";
      result += this->name;
      result += "(";
      implode(parameters, ", ", result);
      result += ")";
      return result;
    } else {
      std::string result = "define ";
      result += this->result_type->name;
      result += " ";
      result += this->name;
      result += "(";
      implode(parameters, ", ", result);
      result += ") {\n";
      std::vector<std::string> blocks;
      for (const auto& block : this->blocks) {
        blocks.push_back(block->dumpLL(module));
      }
      implode(blocks, "\n", result);
      result += "\n}";
      return result;
    }
  }

  std::string FunctionBlock::dumpLL(Module* module) {
    std::string result = this->name + ":\n";
    std::vector<std::string> instructions;
    for (const auto& instruction : this->instructions) {
      instructions.push_back("  " + instruction->dumpLL(module));
    }
    implode(instructions, "\n", result);
    return result;
  }

  std::string FunctionInstruction::dumpLL(Module* module) {
    if (this->alloca) {
      return this->name + " = alloca " + this->alloca->type->name;
    }
    if (this->getelementptr) {
      std::vector<std::string> indexes;
      for (const auto& index : this->getelementptr->indexes) {
        indexes.push_back(module->int32Type->name + " " +
                          std::to_string(index));
      }
      std::string result = this->name + " = getelementptr ";
      result += this->getelementptr->type->name;
      result += ", ";
      result += this->getelementptr->pointer->dumpLL(module);
      result += ", ";
      implode(indexes, ", ", result);
      return result;
    }
    if (this->store) {
      return "store " + this->store->type->name + " " +
             this->store->value->name + ", " +
             this->store->pointer->dumpLL(module);
    }
    if (this->load) {
      return this->name + " = load " + this->load->type->name + ", " +
             this->load->pointer->dumpLL(module);
    }
    if (this->ret) {
      if (this->ret->value == nullptr) {
        return "ret void";
      }
      return "ret " + this->ret->value->dumpLL(module);
    }
    if (this->call) {
      std::vector<std::string> arguments;
      for (const auto& argument : this->call->arguments) {
        arguments.push_back(argument->dumpLL(module));
      }
      std::string result;
      if (this->call->type == module->voidType) {
        result = "call ";
      } else {
        result = this->name + " = call ";
      }
      result += this->call->type->name;
      result += " ";
      result += this->call->value->name;
      result += "(";
      implode(arguments, ", ", result);
      result += ")";
      return result;
    }
    if (this->br) {
      return "br label %" + this->br->target->name;
    }
    if (this->brif) {
      return "br i1 " + this->brif->condition->name + ", label %" +
             this->brif->target_true->name + ", label %" +
             this->brif->target_false->name;
    }
    if (this->icmp) {
      return this->name + " = icmp " + this->icmp->op + " " +
             this->icmp->type->name + " " + this->icmp->left->name + ", " +
             this->icmp->right->name;
    }
    if (this->add) {
      return this->name + " = add " + this->add->type->name + " " +
             this->add->left->name + ", " + this->add->right->name;
    }
    return "";
  }
} // namespace tsil::x