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
    constant->value = value;
    this->constants[constant->name] = constant;
    return new Value{.constant = constant};
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

  Value* Module::declareFunction(const std::string& name,
                                 Type* result_type,
                                 std::vector<Type*> parameters) {
    auto function = new Function();
    function->name = "@\"" + name + "\"";
    function->result_type = result_type;
    function->parameters = parameters;
    this->functions[name] = function;
    return new Value{.function = function};
  }

  Value* Module::defineFunction(const std::string& name,
                                Type* result_type,
                                std::vector<Type*> parameters) {
    auto function = new Function();
    function->name = "@" + name;
    function->result_type = result_type;
    function->parameters = parameters;
    this->defineFunctionBlock(function, "entry");
    this->functions[name] = function;
    return new Value{.function = function};
  }

  FunctionBlock* Module::defineFunctionBlock(Function* function,
                                             const std::string& name) {
    auto block = new FunctionBlock();
    block->name = name;
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
    return new Value{.instruction = instruction};
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
    return new Value{.instruction = instruction};
  }

  FunctionInstruction* Module::pushFunctionBlockStoreInstruction(
      FunctionBlock* block,
      Value* value,
      Value* pointer) {
    const auto instruction = new FunctionInstruction();
    const auto store = new FunctionInstructionStore();
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
    return new Value{.instruction = instruction};
  }

  FunctionInstruction* Module::pushFunctionBlockRetInstruction(
      FunctionBlock* block,
      Value* value) {
    const auto instruction = new FunctionInstruction();
    const auto ret = new FunctionInstructionRet();
    ret->value = value;
    instruction->ret = ret;
    block->instructions.push_back(instruction);
    return instruction;
  }

  Value* Module::pushFunctionBlockCallInstruction(
      FunctionBlock* block,
      Value* value,
      std::vector<Value*> arguments) {
    const auto instruction = new FunctionInstruction();
    const auto call = new FunctionInstructionCall();
    call->value = value;
    call->arguments = arguments;
    instruction->name = "%call." + std::to_string(this->variable_counter++);
    instruction->call = call;
    block->instructions.push_back(instruction);
    return new Value{.instruction = instruction};
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

  std::string Constant::dumpLL(Module* module) {
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

  std::string Value::dumpLL(Module* module) {
    if (this->constant) {
      return "ptr " + this->constant->name;
    }
    if (this->instruction) {
      if (this->instruction->alloca) {
        return "ptr " + this->instruction->name;
      }
      if (this->instruction->getelementptr) {
        return "ptr " + this->instruction->name;
      }
      if (this->instruction->store) {
        return "void";
      }
      if (this->instruction->load) {
        return this->instruction->load->type->name + " " +
               this->instruction->name;
      }
    }
    if (this->function) {
      return "ptr " + this->function->name;
    }
    if (this->number) {
      return this->number->type->name + " " + this->number->value;
    }
    return "void";
  }

  std::string Value::dumpRightLL(Module* module) {
    if (this->constant) {
      return this->constant->name;
    }
    if (this->instruction) {
      if (this->instruction->alloca) {
        return this->instruction->name;
      }
      if (this->instruction->getelementptr) {
        return this->instruction->name;
      }
      if (this->instruction->store) {
        return "void";
      }
      if (this->instruction->load) {
        return this->instruction->name;
      }
    }
    if (this->function) {
      return this->function->name;
    }
    if (this->number) {
      return this->number->value;
    }
    return "void";
  }

  std::string Function::dumpLL(Module* module) {
    std::vector<std::string> parameters;
    for (const auto& parameter : this->parameters) {
      parameters.push_back(parameter->name);
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
      return "store " + this->store->value->dumpLL(module) + ", " +
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
      std::string result = this->name + " = call ";
      result += this->call->value->dumpLL(module);
      result += "(";
      implode(arguments, ", ", result);
      result += ")";
      return result;
    }
    if (this->br) {
      return "br label %" + this->br->target->name;
    }
    if (this->brif) {
      return "br i1 " + this->brif->condition->dumpRightLL(module) +
             ", label %" + this->brif->target_true->name + ", label %" +
             this->brif->target_false->name;
    }
    return "";
  }
} // namespace tsil::x