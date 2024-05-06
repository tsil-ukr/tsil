#include "tk.h"

namespace tsil::tk {
  CompilerError* CompilerError::fromParserError(
      tsil::parser::TsilParserError* error) {
    return new CompilerError(error->line, error->column, error->message);
  }

  CompilerError* CompilerError::fromASTValue(tsil::ast::ASTValue* ast_value,
                                             const std::string& message) {
    return new CompilerError(ast_value->start_line, ast_value->start_column,
                             message);
  }

  CompilerError* CompilerError::fromLocation(const Location& location,
                                             const std::string& message) {
    return new CompilerError(location.start_line, location.start_column,
                             message);
  }

  CompilerError* CompilerError::subjectAlreadyDefined(
      tsil::ast::ASTValue* ast_value) {
    std::string name;
    if (ast_value->kind == tsil::ast::KindStructureNode) {
      name = ast_value->data.StructureNode->name;
    } else if (ast_value->kind == tsil::ast::KindDiiaNode) {
      name = ast_value->data.DiiaNode->head->id;
    } else if (ast_value->kind == tsil::ast::KindDiiaDeclarationNode) {
      name = ast_value->data.DiiaDeclarationNode->head->id;
    } else if (ast_value->kind == tsil::ast::KindDefineNode) {
      name = ast_value->data.DefineNode->id;
    } else if (ast_value->kind == tsil::ast::KindIdentifierNode) {
      name = ast_value->data.IdentifierNode->name;
    } else {
      name = "BUG";
    }
    return new CompilerError(ast_value->start_line, ast_value->start_column,
                             "Субʼєкт \"" + name + "\" вже визначено");
  }

  CompilerError* CompilerError::subjectNotDefined(
      tsil::ast::ASTValue* ast_value) {
    std::string name;
    if (ast_value->kind == tsil::ast::KindStructureNode) {
      name = ast_value->data.StructureNode->name;
    } else if (ast_value->kind == tsil::ast::KindDiiaNode) {
      name = ast_value->data.DiiaNode->head->id;
    } else if (ast_value->kind == tsil::ast::KindDiiaDeclarationNode) {
      name = ast_value->data.DiiaDeclarationNode->head->id;
    } else if (ast_value->kind == tsil::ast::KindDefineNode) {
      name = ast_value->data.DefineNode->id;
    } else if (ast_value->kind == tsil::ast::KindIdentifierNode) {
      name = ast_value->data.IdentifierNode->name;
    } else {
      name = "BUG";
    }
    return new CompilerError(ast_value->start_line, ast_value->start_column,
                             "Субʼєкт \"" + name + "\" не визначено");
  }

  CompilerError* CompilerError::subjectIsNotCallable(
      tsil::ast::ASTValue* ast_value) {
    return new CompilerError(
        ast_value->start_line, ast_value->start_column,
        "Неможливо виконати цей субʼєкт, так як його тип не є дією");
  }

  CompilerError* CompilerError::typesAreNotCompatible(
      tsil::ast::ASTValue* ast_value,
      Type* left,
      Type* right) {
    return new CompilerError(ast_value->start_line, ast_value->start_column,
                             "Типи \"" + left->getFullName() + "\" та \"" +
                                 right->getFullName() + "\" не сумісні");
  }

  CompilerError* CompilerError::cannotRedefineSubject(
      tsil::ast::ASTValue* ast_value,
      const std::string& name) {
    return new CompilerError(
        ast_value->start_line, ast_value->start_column,
        "Неможливо перевизначити субʼєкт \"" + name + "\"");
  }

  CompilerError* CompilerError::typeIsNotConstructable(
      tsil::ast::ASTValue* ast_value,
      Type* type) {
    return new CompilerError(
        ast_value->start_line, ast_value->start_column,
        "Тип \"" + type->getFullName() + "\" не є структурою");
  }

  CompilerError* CompilerError::typeHasNoProperty(
      tsil::ast::ASTValue* ast_value,
      Type* type,
      const std::string& name) {
    return new CompilerError(ast_value->start_line, ast_value->start_column,
                             "Тип \"" + type->getFullName() +
                                 "\" не має властивості \"" + name + "\"");
  }

  CompilerError* CompilerError::subjectIsNotRuntimeValue(
      tsil::ast::ASTValue* ast_value) {
    return new CompilerError(ast_value->start_line, ast_value->start_column,
                             "Цей субʼєкт доступний лише під час компіляції");
  }

  CompilerError* CompilerError::typesOfInstructionDifferent(
      tsil::ast::ASTValue* astValue,
      Type* leftType,
      Type* rightType) {
    return new CompilerError(
        astValue->start_line, astValue->start_column,
        "Типи вказівки \"" +
            getTsilAstBinaryOpSymbol(astValue->data.BinaryNode->op) +
            "\" не співпадають: \"" + leftType->getFullName() + "\" та \"" +
            rightType->getFullName() + "\"");
  }

  CompilerError* CompilerError::typeIsNotComparable(
      tsil::ast::ASTValue* astValue,
      Type* type) {
    return new CompilerError(
        astValue->start_line, astValue->start_column,
        "Тип \"" + type->getFullName() + "\" недоступний для порівняння");
  }

  CompilerError* CompilerError::typeIsNotArithmetical(
      tsil::ast::ASTValue* astValue,
      Type* type) {
    return new CompilerError(
        astValue->start_line, astValue->start_column,
        "Тип \"" + type->getFullName() + "\" недоступний для арифметики");
  }

  CompilerError* CompilerError::typeIsNotBitwisible(
      tsil::ast::ASTValue* astValue,
      Type* type) {
    return new CompilerError(astValue->start_line, astValue->start_column,
                             "Тип \"" + type->getFullName() +
                                 "\" недоступний для побітових операцій");
  }

  CompilerError* CompilerError::notEnoughCallArguments(
      tsil::ast::ASTValue* astValue) {
    return new CompilerError(astValue->start_line, astValue->start_column,
                             "Недостатньо аргументів для виконання дії");
  }

  CompilerError* CompilerError::tooManyCallArguments(
      tsil::ast::ASTValue* astValue) {
    return new CompilerError(astValue->start_line, astValue->start_column,
                             "Забагато аргументів для виконання дії");
  }

  CompilerError* CompilerError::notEnoughCallTemplateArguments(
      tsil::ast::ASTValue* astValue) {
    return new CompilerError(
        astValue->start_line, astValue->start_column,
        "Недостатньо аргументів шаблону для виконання дії");
  }

  CompilerError* CompilerError::tooManyCallTemplateArguments(
      tsil::ast::ASTValue* astValue) {
    return new CompilerError(astValue->start_line, astValue->start_column,
                             "Забагато аргументів шаблону для виконання дії");
  }

  CompilerError* CompilerError::invalidArgumentType(
      tsil::ast::ASTValue* astValue,
      const std::string& name,
      Type* expected,
      Type* got) {
    return new CompilerError(astValue->start_line, astValue->start_column,
                             "Недопустимий тип аргументу \"" + name +
                                 "\": очікується \"" + expected->getFullName() +
                                 "\", отримано \"" + got->getFullName() + "\"");
  }

  CompilerError* CompilerError::invalidPropertyType(
      tsil::ast::ASTValue* astValue,
      const std::string& name,
      Type* expected,
      Type* got) {
    return new CompilerError(astValue->start_line, astValue->start_column,
                             "Недопустимий тип властивості \"" + name +
                                 "\": очікується \"" + expected->getFullName() +
                                 "\", отримано \"" + got->getFullName() + "\"");
  }

  CompilerError* CompilerError::cannotAccessNonPointer(
      tsil::ast::ASTValue* astValue,
      Type* type) {
    return new CompilerError(astValue->start_line, astValue->start_column,
                             "Позиційний доступ недоступний для типу \"" +
                                 type->getFullName() + "\"");
  }

  CompilerError* CompilerError::tooManyConstructorArguments(
      tsil::ast::ASTValue* astValue) {
    return new CompilerError(astValue->start_line, astValue->start_column,
                             "Забагато аргументів для конструктора");
  }
} // namespace tsil::tk