#include "tk.h"

namespace tsil::tk {
  bool Type::equals(Type* other) {
    if (this == other) {
      return true;
    }
    if (this->type != other->type) {
      return false;
    }
    if (this->type == TypeTypeDiia) {
      if (this->diiaParameters.size() != other->diiaParameters.size()) {
        return false;
      }
      for (size_t i = 0; i < this->diiaParameters.size(); i++) {
        if (!this->diiaParameters[i].type->equals(
                other->diiaParameters[i].type)) {
          return false;
        }
      }
      return this->diiaReturnType->equals(other->diiaReturnType);
    }
    return false;
  }

  std::string Type::getFullName() {
    if (this->type == TypeTypeDiia) {
      std::string result = "";
      if (!this->diiaParameters.empty()) {
        if (this->diiaParameters.size() == 1) {
          result += this->diiaParameters[0].type->getFullName();
        } else {
          result += "(";
          bool first = true;
          for (const auto& diia_parameter : this->diiaParameters) {
            if (!first) {
              result += ", ";
            }
            first = false;
            result += diia_parameter.type->getFullName();
          }
          result += ")";
        }
      }
      const auto resultFullName = this->diiaReturnType->getFullName();
      result += " -> " + (this->diiaReturnType->type == TypeTypeDiia
                              ? "(" + resultFullName + ")"
                              : resultFullName);
      return result;
    }
    std::string result = this->name;
    if (!this->genericValues.empty()) {
      result += "<";
      bool first = true;
      for (const auto& generic_value_type : this->genericValues) {
        if (!first) {
          result += ", ";
        }
        first = false;
        result += generic_value_type->getFullName();
      }
      result += ">";
    }
    return result;
  }

  Type* Type::getPointerType(Scope* scope) {
    if (this->cachedPointerType) {
      return this->cachedPointerType;
    }
    const auto type = new Type();
    type->type = TypeTypePointer;
    type->name = "комірка";
    type->pointerTo = this;
    type->genericValues.push_back(this);
    type->xType = scope->compiler->xModule->pointerType;
    this->cachedPointerType = type;
    return type;
  }

  bool Type::isComparable(Scope* scope) {
    return this == scope->compiler->int1Type ||
           this == scope->compiler->int8Type ||
           this == scope->compiler->int32Type ||
           this == scope->compiler->int64Type ||
           this == scope->compiler->uint8Type ||
           this == scope->compiler->uint32Type ||
           this == scope->compiler->uint64Type ||
           this == scope->compiler->floatType ||
           this == scope->compiler->doubleType || this->type == TypeTypePointer;
  }

  bool Type::isUnsigned(tsil::tk::Scope* scope) {
    return this == scope->compiler->uint8Type ||
           this == scope->compiler->uint32Type ||
           this == scope->compiler->uint64Type || this->type == TypeTypePointer;
  }

  bool Type::isFloating(tsil::tk::Scope* scope) {
    return this == scope->compiler->floatType ||
           this == scope->compiler->doubleType;
  }

  bool Type::isArithmetical(tsil::tk::Scope* scope) {
    return this->isComparable(scope);
  }

  bool Type::isBitwisible(tsil::tk::Scope* scope) {
    return this == scope->compiler->int8Type ||
           this == scope->compiler->int32Type ||
           this == scope->compiler->int64Type ||
           this == scope->compiler->uint8Type ||
           this == scope->compiler->uint32Type ||
           this == scope->compiler->uint64Type || this->type == TypeTypePointer;
  }
} // namespace tsil::tk