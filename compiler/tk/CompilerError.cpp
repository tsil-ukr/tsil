#include "tk.h"

namespace tsil::tk {
  CompilerError* CompilerError::fromASTValue(tsil::ast::ASTValue* ast_value,
                                             const std::string& message) {
    return new CompilerError(ast_value->start_line, ast_value->start_column,
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
} // namespace tsil::tk