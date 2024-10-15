#include "parser.h"

namespace tsil::parser {
  Місцезнаходження* LOC(TsilASTVisitor* visitor,
                        antlr4::ParserRuleContext* context) {
    const auto місцезнаходження = new Місцезнаходження();
    місцезнаходження->текст_коду = visitor->текст_коду;
    місцезнаходження->рядок = context->getStart()->getLine();
    місцезнаходження->стовпець =
        context->getStart()->getCharPositionInLine() + 1;
    return місцезнаходження;
  }

  Місцезнаходження* LOC(TsilASTVisitor* visitor, antlr4::Token* token) {
    const auto місцезнаходження = new Місцезнаходження();
    місцезнаходження->текст_коду = visitor->текст_коду;
    місцезнаходження->рядок = token->getLine();
    місцезнаходження->стовпець = token->getCharPositionInLine() + 1;
    return місцезнаходження;
  }

  void FILL(TsilASTVisitor* visitor,
            АСДЗначення* асд_значення,
            antlr4::ParserRuleContext* context) {
    асд_значення->місцезнаходження = LOC(visitor, context);
  }

  void FILL(TsilASTVisitor* visitor,
            АСДЗначення* асд_значення,
            antlr4::Token* token) {
    асд_значення->місцезнаходження = LOC(visitor, token);
  }

  АСДЗначення* AV(TsilASTVisitor* visitor, size_t kind, void* data) {
    const auto асд_значення = new АСДЗначення();
    асд_значення->вид = kind;
    асд_значення->дані = data;
    return асд_значення;
  }

  АСДЗначення* AV(TsilASTVisitor* visitor,
                  antlr4::ParserRuleContext* context,
                  size_t kind,
                  void* data) {
    const auto асд_значення = new АСДЗначення();
    FILL(visitor, асд_значення, context);
    асд_значення->вид = kind;
    асд_значення->дані = data;
    return асд_значення;
  }

  АСДЗначення* AV(TsilASTVisitor* visitor,
                  antlr4::Token* token,
                  size_t kind,
                  void* data) {
    const auto асд_значення = new АСДЗначення();
    FILL(visitor, асд_значення, token);
    асд_значення->вид = kind;
    асд_значення->дані = data;
    return асд_значення;
  }

  СписокАСДЗначень* AAVecToList(std::vector<АСДЗначення*> vec) {
    const auto elements = new АСДЗначення*[vec.size()];
    for (size_t i = 0; i < vec.size(); i++) {
      elements[i] = vec[i];
    }
    return new СписокАСДЗначень{.довжина = vec.size(), .елементи = elements};
  }

  Ідентифікатор* ІД(TsilASTVisitor* visitor,
                    antlr4::ParserRuleContext* context,
                    const std::string& значення) {
    const auto ідентифікатор = new Ідентифікатор();
    ідентифікатор->значення = strdup(значення.c_str());
    ідентифікатор->місцезнаходження = LOC(visitor, context);
    return ідентифікатор;
  }

  Ідентифікатор* ІД(TsilASTVisitor* visitor,
                    antlr4::Token* token,
                    const std::string& значення) {
    const auto ідентифікатор = new Ідентифікатор();
    ідентифікатор->значення = strdup(значення.c_str());
    ідентифікатор->місцезнаходження = LOC(visitor, token);
    return ідентифікатор;
  }

  std::string повторити_пробіл(size_t кількість) {
    std::string r;
    for (size_t i = 0; i < кількість; ++i) {
      r += " ";
    }
    return r;
  }

  std::string АСДЗначенняВString(АСДЗначення* асд_значення, size_t глибина) {
    if (асд_значення == nullptr) {
      return "nullptr";
    }
    if (асд_значення->вид == АСДВидНіщо) {
      return "Ніщо";
    }
    if (асд_значення->вид == АСДВидЗвернутись) {
      const auto data = static_cast<АСДДаніЗвернутись*>(асд_значення->дані);
      std::string r = "Звернутись(";
      r += data->ідентифікатор->значення;
      r += ")";
      return r;
    }
    if (асд_значення->вид == АСДВидОтримати) {
      const auto data = static_cast<АСДДаніОтримати*>(асд_значення->дані);
      std::string r = "Отримати(";
      r += АСДЗначенняВString(data->обʼєкт);
      r += ", ";
      r += data->ідентифікатор->значення;
      r += ")";
      return r;
    }
    if (асд_значення->вид == АСДВидОтриматиЗіСекції) {
      const auto data =
          static_cast<АСДДаніОтриматиЗіСекції*>(асд_значення->дані);
      std::string r = "ОтриматиЗіСекції(";
      r += АСДЗначенняВString(data->обʼєкт);
      r += ", ";
      r += data->ідентифікатор->значення;
      r += ")";
      return r;
    }
    if (асд_значення->вид == АСДВидОтриматиЗаПозицією) {
      const auto data =
          static_cast<АСДДаніОтриматиЗаПозицією*>(асд_значення->дані);
      std::string r = "ОтриматиЗаПозицією(";
      r += АСДЗначенняВString(data->обʼєкт);
      r += ", ";
      r += data->позиція ? АСДЗначенняВString(data->позиція) : "ПРОП";
      r += ")";
      return r;
    }
    if (асд_значення->вид == АСДВидЗмінити) {
      const auto data = static_cast<АСДДаніЗмінити*>(асд_значення->дані);
      std::string r = "Змінити(";
      r += АСДЗначенняВString(data->обʼєкт);
      r += ", ";
      r += data->ідентифікатор->значення;
      r += ", ";
      r += АСДЗначенняВString(data->значення);
      r += ")";
      return r;
    }
    if (асд_значення->вид == АСДВидЗмінитиВСекції) {
      const auto data = static_cast<АСДДаніЗмінитиВСекції*>(асд_значення->дані);
      std::string r = "ЗмінитиВСекції(";
      r += АСДЗначенняВString(data->обʼєкт);
      r += ", ";
      r += data->ідентифікатор->значення;
      r += ", ";
      r += АСДЗначенняВString(data->значення);
      r += ")";
      return r;
    }
    if (асд_значення->вид == АСДВидЗмінитиЗаПозицією) {
      const auto data =
          static_cast<АСДДаніЗмінитиЗаПозицією*>(асд_значення->дані);
      std::string r = "ЗмінитиЗаПозицією(";
      r += АСДЗначенняВString(data->обʼєкт);
      r += ", ";
      r += data->позиція ? АСДЗначенняВString(data->позиція) : "ПРОП";
      r += ", ";
      r += АСДЗначенняВString(data->значення);
      r += ")";
      return r;
    }
    if (асд_значення->вид == АСДВидВиконати) {
      const auto data = static_cast<АСДДаніВиконати*>(асд_значення->дані);
      std::string r = "Виконати(";
      r += АСДЗначенняВString(data->обʼєкт);
      r += ", [";
      if (data->аргументи) {
        if (data->аргументи->довжина) {
          for (int i = 0; i < data->аргументи->довжина; ++i) {
            r += АСДЗначенняВString(data->аргументи->елементи[i]);
            if (i != data->аргументи->довжина - 1) {
              r += ", ";
            }
          }
        }
      }
      r += "]";
      r += ")";
      return r;
    }
    if (асд_значення->вид == АСДВидВиконатиШаблон) {
      const auto data = static_cast<АСДДаніВиконатиШаблон*>(асд_значення->дані);
      std::string r = "ВиконатиШаблон(";
      r += АСДЗначенняВString(data->обʼєкт);
      r += ", [";
      if (data->аргументи) {
        if (data->аргументи->довжина) {
          for (int i = 0; i < data->аргументи->довжина; ++i) {
            r += АСДЗначенняВString(data->аргументи->елементи[i]);
            if (i != data->аргументи->довжина - 1) {
              r += ", ";
            }
          }
        }
      }
      r += "]";
      r += ")";
      return r;
    }
    if (асд_значення->вид == АСДВидСтворитиЦіль) {
      const auto data = static_cast<АСДДаніСтворитиЦіль*>(асд_значення->дані);
      std::string r = "СтворитиЦіль(";
      r += data->тип ? АСДЗначенняВString(data->тип) : "ПРОП";
      r += ", ";
      r += data->значення ? АСДЗначенняВString(data->значення) : "ПРОП";
      r += ")";
      return r;
    }
    if (асд_значення->вид == АСДВидДія) {
      const auto data = static_cast<АСДДаніДія*>(асд_значення->дані);
      std::string r = "СтворитиДію(";
      r += data->ідентифікатор->значення;
      r += ", ";
      r += "...";
      r += ", [";
      if (data->тіло) {
        if (data->тіло->довжина) {
          for (int i = 0; i < data->тіло->довжина; ++i) {
            r += АСДЗначенняВString(data->тіло->елементи[i]);
            if (i != data->тіло->довжина - 1) {
              r += ", ";
            }
          }
        }
      }
      r += "])";
      return r;
    }
    if (асд_значення->вид == АСДВидСтруктура) {
      const auto data =
          static_cast<АСДДаніСтруктура*>(асд_значення->дані);
      std::string r = "СтворитиСтруктуру(";
      r += data->ідентифікатор->значення;
      r += ", [";
      if (data->параметри) {
        if (data->кількість_параметрів) {
          for (int i = 0; i < data->кількість_параметрів; ++i) {
            r += data->параметри[i]->ідентифікатор->значення;
            r += ": ";
            r += АСДЗначенняВString(data->параметри[i]->тип);
            if (i != data->кількість_параметрів - 1) {
              r += ", ";
            }
          }
        }
      }
      r += "])";
      return r;
    }
    if (асд_значення->вид == АСДВидСинонім) {
      const auto data =
          static_cast<АСДДаніСинонім*>(асд_значення->дані);
      std::string r = "СтворитиСинонім(";
      r += АСДЗначенняВString(data->значення);
      r += ")";
      return r;
    }
    if (асд_значення->вид == АСДВидШаблон) {
      const auto data = static_cast<АСДДаніШаблон*>(асд_значення->дані);
      std::string r = "СтворитиШаблон(";
      r += "[";
      if (data->параметри) {
        if (data->кількість_параметрів) {
          for (int i = 0; i < data->кількість_параметрів; ++i) {
            r += data->параметри[i]->значення;
            if (i != data->кількість_параметрів - 1) {
              r += ", ";
            }
          }
        }
      }
      r += "], ";
      r += data->значення ? АСДЗначенняВString(data->значення) : "ПРОП";
      r += ")";
      return r;
    }
    if (асд_значення->вид == АСДВидСтворитиСекцію) {
      const auto data = static_cast<АСДДаніСтворитиСекцію*>(асд_значення->дані);
      std::string r = "СтворитиСекцію(";
      r += data->ідентифікатор->значення;
      r += ", [";
      if (data->тіло) {
        if (data->тіло->довжина) {
          for (int i = 0; i < data->тіло->довжина; ++i) {
            r += АСДЗначенняВString(data->тіло->елементи[i]);
            if (i != data->тіло->довжина - 1) {
              r += ", ";
            }
          }
        }
      }
      r += "])";
      return r;
    }
    if (асд_значення->вид == АСДВидЗначенняОбʼєкт) {
    }
    if (асд_значення->вид == АСДВидЗначенняЧисло) {
      const auto data = static_cast<АСДДаніЗначенняЧисло*>(асд_значення->дані);
      std::string r = "Число(";
      r += data->значення;
      r += ")";
      return r;
    }
    if (асд_значення->вид == АСДВидЗначенняТекст) {
      const auto data = static_cast<АСДДаніЗначенняТекст*>(асд_значення->дані);
      std::string r = "Текст([";
      auto s = data->значення;
      while (*s != 0) {
        r += std::to_string(*s);
        s++;
        if (*s != 0) {
          r += ", ";
        }
      }
      r += "])";
      return r;
    }
    if (асд_значення->вид == АСДВидОперація) {
      const auto data = static_cast<АСДДаніОперація*>(асд_значення->дані);
      std::string r = "Операція(";
      r += АСДЗначенняВString(data->ліво);
      r += ", ";
      r += код_операції_в_юнікод(data->операція);
      r += ", ";
      r += АСДЗначенняВString(data->право);
      r += ")";
      return r;
    }
    if (асд_значення->вид == АСДВидЯкщо) {
    }
    if (асд_значення->вид == АСДВидПоки) {
    }
    if (асд_значення->вид == АСДВидВернути) {
      const auto data = static_cast<АСДДаніВернути*>(асд_значення->дані);
      std::string r = "Вернути(";
      r += data->значення ? АСДЗначенняВString(data->значення) : "ПРОП";
      r += ")";
      return r;
    }
    if (асд_значення->вид == АСДВидСтворитиТипДії) {
    }
    if (асд_значення->вид == АСДВидСтворитиТипМасиву) {
    }
    return "Невідомо";
  }

  void TsilParserErrorListener::syntaxError(antlr4::Recognizer* recognizer,
                                            antlr4::Token* offendingSymbol,
                                            size_t line,
                                            size_t charPositionInLine,
                                            const std::string& msg,
                                            std::exception_ptr e) {
    const auto error = new ПомилкаРозборуЦілі();
    error->місцезнаходження = new Місцезнаходження();
    error->місцезнаходження->текст_коду = this->текст_коду;
    error->місцезнаходження->рядок = line;
    error->місцезнаходження->стовпець = charPositionInLine;
    error->повідомлення = strdup(msg.c_str());
    this->errors.push_back(error);
  }

  void TsilParserErrorListener::reportAmbiguity(
      antlr4::Parser* recognizer,
      const antlr4::dfa::DFA& dfa,
      size_t startIndex,
      size_t stopIndex,
      bool exact,
      const antlrcpp::BitSet& ambigAlts,
      antlr4::atn::ATNConfigSet* configs) {}

  void TsilParserErrorListener::reportAttemptingFullContext(
      antlr4::Parser* recognizer,
      const antlr4::dfa::DFA& dfa,
      size_t startIndex,
      size_t stopIndex,
      const antlrcpp::BitSet& conflictingAlts,
      antlr4::atn::ATNConfigSet* configs) {}

  void TsilParserErrorListener::reportContextSensitivity(
      antlr4::Parser* recognizer,
      const antlr4::dfa::DFA& dfa,
      size_t startIndex,
      size_t stopIndex,
      size_t prediction,
      antlr4::atn::ATNConfigSet* configs) {}
} // namespace tsil::parser

extern "C" РезультатРозборуЦілі* розібрати_ціль(ТекстКоду* текст_коду) {
  antlr4::ANTLRInputStream input(текст_коду->значення);

  const auto lexer_error_listener = new tsil::parser::TsilParserErrorListener();
  lexer_error_listener->текст_коду = текст_коду;
  TsilLexer lexer(&input);
  lexer.removeErrorListeners();
  lexer.addErrorListener(lexer_error_listener);

  antlr4::CommonTokenStream tokens(&lexer);

  if (!lexer_error_listener->errors.empty()) {
    const auto error = lexer_error_listener->errors[0];
    delete lexer_error_listener;
    return new РезультатРозборуЦілі{false, {}, error};
  }

  const auto parser_error_listener =
      new tsil::parser::TsilParserErrorListener();
  parser_error_listener->текст_коду = текст_коду;
  TsilParser parser(&tokens);
  parser.removeParseListeners();
  parser.removeErrorListeners();
  parser.addErrorListener(parser_error_listener);

  TsilParser::FileContext* tree = parser.file();

  if (!parser_error_listener->errors.empty()) {
    const auto error = parser_error_listener->errors[0];
    delete lexer_error_listener;
    delete parser_error_listener;
    return new РезультатРозборуЦілі{false, {}, error};
  }

  const auto visitor = new tsil::parser::TsilASTVisitor();
  visitor->tokens = &tokens;
  visitor->текст_коду = текст_коду;

  const auto body = AAVec(visitor->visitFile(tree));
  const auto elements = new АСДЗначення*[body.size()];
  for (size_t i = 0; i < body.size(); i++) {
    elements[i] = body[i];
  }

  delete lexer_error_listener;
  delete parser_error_listener;
  delete visitor;

  return new РезультатРозборуЦілі{
      true, new СписокАСДЗначень{.довжина = body.size(), .елементи = elements},
      nullptr};

} // namespace tsil::parser

extern "C" char* код_операції_в_юнікод(size_t операція) {
  if (операція == АСДОпераціяМноження) {
    return "*";
  }
  if (операція == АСДОпераціяДілення) {
    return "/";
  }
  if (операція == АСДОпераціяМодуль) {
    return "%";
  }
  if (операція == АСДОпераціяДодавання) {
    return "+";
  }
  if (операція == АСДОпераціяВіднімання) {
    return "-";
  }
  if (операція == АСДОпераціяЗсувВліво) {
    return "<<";
  }
  if (операція == АСДОпераціяЗсувВправо) {
    return ">>";
  }
  if (операція == АСДОпераціяЗсувВправоЗнаковий) {
    return ">>>";
  }
  if (операція == АСДОпераціяМенше) {
    return "<";
  }
  if (операція == АСДОпераціяБільше) {
    return ">";
  }
  if (операція == АСДОпераціяМеншеРівне) {
    return "<=";
  }
  if (операція == АСДОпераціяБільшеРівне) {
    return ">=";
  }
  if (операція == АСДОпераціяРівне) {
    return "==";
  }
  if (операція == АСДОпераціяНерівне) {
    return "!=";
  }
  if (операція == АСДОпераціяДІ) {
    return "&";
  }
  if (операція == АСДОпераціяВАБО) {
    return "^";
  }
  if (операція == АСДОпераціяДАБО) {
    return "|";
  }
  if (операція == АСДОпераціяІ) {
    return "&&";
  }
  if (операція == АСДОпераціяАБО) {
    return "||";
  }
  return "НЕВІДОМА_ОПЕРАЦІЯ";
}