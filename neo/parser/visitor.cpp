#include "parser.h"

namespace tsil::parser {
  std::any TsilASTVisitor::visitContext(antlr4::ParserRuleContext* context) {
    if (const auto ctx = dynamic_cast<TsilParser::FileContext*>(context)) {
      return visitFile(ctx);
    }
    if (const auto ctx = dynamic_cast<TsilParser::ProgramContext*>(context)) {
      return visitProgram(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Atom_nestedContext*>(context)) {
      return visitAtom_nested(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Atom_subjectContext*>(context)) {
      return visitAtom_subject(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Atom_section_getContext*>(context)) {
      return visitAtom_section_get(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Atom_template_getContext*>(context)) {
      return visitAtom_template_get(ctx);
    }
    if (const auto ctx = dynamic_cast<TsilParser::Atom_getContext*>(context)) {
      return visitAtom_get(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Atom_position_getContext*>(context)) {
      return visitAtom_position_get(ctx);
    }
    if (const auto ctx = dynamic_cast<TsilParser::Atom_callContext*>(context)) {
      return visitAtom_call(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_numberContext*>(context)) {
      return visitOperation_number(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_stringContext*>(context)) {
      return visitOperation_string(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_atomContext*>(context)) {
      return visitOperation_atom(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_mulContext*>(context)) {
      return visitOperation_mul(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_divContext*>(context)) {
      return visitOperation_div(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_modContext*>(context)) {
      return visitOperation_mod(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_addContext*>(context)) {
      return visitOperation_add(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_subContext*>(context)) {
      return visitOperation_sub(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_lshiftContext*>(context)) {
      return visitOperation_lshift(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_rshiftContext*>(context)) {
      return visitOperation_rshift(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_urshiftContext*>(context)) {
      return visitOperation_urshift(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_ltContext*>(context)) {
      return visitOperation_lt(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_lteContext*>(context)) {
      return visitOperation_lte(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_gtContext*>(context)) {
      return visitOperation_gt(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_gteContext*>(context)) {
      return visitOperation_gte(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_eqContext*>(context)) {
      return visitOperation_eq(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_neqContext*>(context)) {
      return visitOperation_neq(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_andContext*>(context)) {
      return visitOperation_and(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_xorContext*>(context)) {
      return visitOperation_xor(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_orContext*>(context)) {
      return visitOperation_or(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_landContext*>(context)) {
      return visitOperation_land(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_lorContext*>(context)) {
      return visitOperation_lor(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_ternaryContext*>(context)) {
      return visitOperation_ternary(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Expr_operationContext*>(context)) {
      return visitExpr_operation(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Expr_objectContext*>(context)) {
      return visitExpr_object(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Structure_declareContext*>(context)) {
      return visitStructure_declare(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Structure_defineContext*>(context)) {
      return visitStructure_define(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Diia_declareContext*>(context)) {
      return visitDiia_declare(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Diia_defineContext*>(context)) {
      return visitDiia_define(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Tsil_declareContext*>(context)) {
      return visitTsil_declare(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Tsil_defineContext*>(context)) {
      return visitTsil_define(ctx);
    }
    if (const auto ctx = dynamic_cast<TsilParser::SynonymContext*>(context)) {
      return visitSynonym(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Section_declareContext*>(context)) {
      return visitSection_declare(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Section_defineContext*>(context)) {
      return visitSection_define(ctx);
    }
    if (const auto ctx = dynamic_cast<TsilParser::SetContext*>(context)) {
      return visitSet(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Position_setContext*>(context)) {
      return visitPosition_set(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Section_setContext*>(context)) {
      return visitSection_set(ctx);
    }
    if (const auto ctx = dynamic_cast<TsilParser::IfContext*>(context)) {
      return visitIf(ctx);
    }
    if (const auto ctx = dynamic_cast<TsilParser::WhileContext*>(context)) {
      return visitWhile(ctx);
    }
    if (const auto body_context =
            dynamic_cast<TsilParser::Body_elementContext*>(context)) {
      return visitBody_element(body_context);
    }
    if (const auto ctx = dynamic_cast<TsilParser::ReturnContext*>(context)) {
      return visitReturn(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Type_nestedContext*>(context)) {
      return visitType_nested(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Type_subjectContext*>(context)) {
      return visitType_subject(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Type_section_getContext*>(context)) {
      return visitType_section_get(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Type_template_getContext*>(context)) {
      return visitType_template_get(ctx);
    }
    if (const auto ctx = dynamic_cast<TsilParser::Type_getContext*>(context)) {
      return visitType_get(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Type_arrayContext*>(context)) {
      return visitType_array(ctx);
    }
    if (const auto ctx = dynamic_cast<TsilParser::Type_fnContext*>(context)) {
      return visitType_fn(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Type_fn_simpleContext*>(context)) {
      return visitType_fn_simple(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Type_fn_complexContext*>(context)) {
      return visitType_fn_complex(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Type_fn_complex_namedContext*>(context)) {
      return visitType_fn_complex_named(ctx);
    }
    if (const auto ctx = dynamic_cast<TsilParser::ParamContext*>(context)) {
      return visitParam(ctx);
    }
    return nullptr;
  }

  std::any TsilASTVisitor::visitFile(TsilParser::FileContext* ctx) {
    return visitProgram(ctx->program());
  }

  std::any TsilASTVisitor::visitProgram(TsilParser::ProgramContext* ctx) {
    std::vector<АСДЗначення*> elements;
    for (const auto& element : ctx->body_element()) {
      if (element->SEMICOLON() == nullptr) {
        elements.push_back(AAV(visitBody_element(element)));
      }
    }
    return elements;
  }

  std::any TsilASTVisitor::visitAtom_nested(
      TsilParser::Atom_nestedContext* ctx) {
    return visitContext(ctx->expr());
  }

  std::any TsilASTVisitor::visitAtom_subject(
      TsilParser::Atom_subjectContext* ctx) {
    const auto асд_дані_звернутись = new АСДДаніЗвернутись();
    асд_дані_звернутись->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
  }

  std::any TsilASTVisitor::visitAtom_section_get(
      TsilParser::Atom_section_getContext* ctx) {
    const auto асд_дані_отримати_зі_секції = new АСДДаніОтриматиЗіСекції();
    асд_дані_отримати_зі_секції->обʼєкт = AAV(visitContext(ctx->object));
    асд_дані_отримати_зі_секції->ідентифікатор =
        ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидОтриматиЗіСекції, асд_дані_отримати_зі_секції);
  }

  std::any TsilASTVisitor::visitAtom_template_get(
      TsilParser::Atom_template_getContext* ctx) {
    const auto асд_дані_виконати_шаблон = new АСДДаніВиконатиШаблон();
    асд_дані_виконати_шаблон->обʼєкт = AAV(visitContext(ctx->object));
    std::vector<АСДЗначення*> arguments;
    for (const auto& argument : ctx->type()) {
      arguments.push_back(AAV(visitContext(argument)));
    }
    асд_дані_виконати_шаблон->аргументи = AAVecToList(arguments);
    return AV(this, ctx, АСДВидВиконатиШаблон, асд_дані_виконати_шаблон);
  }

  std::any TsilASTVisitor::visitAtom_get(TsilParser::Atom_getContext* ctx) {
    const auto асд_дані_отримати = new АСДДаніОтримати();
    асд_дані_отримати->обʼєкт = AAV(visitContext(ctx->object));
    асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
  }

  std::any TsilASTVisitor::visitAtom_position_get(
      TsilParser::Atom_position_getContext* ctx) {
    const auto асд_дані_отримати_за_позицією = new АСДДаніОтриматиЗаПозицією();
    асд_дані_отримати_за_позицією->обʼєкт = AAV(visitContext(ctx->object));
    асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->position));
    return AV(this, ctx, АСДВидОтриматиЗаПозицією,
              асд_дані_отримати_за_позицією);
  }

  std::any TsilASTVisitor::visitAtom_call(TsilParser::Atom_callContext* ctx) {
    const auto асд_дані_виконати = new АСДДаніВиконати();
    асд_дані_виконати->обʼєкт = AAV(visitContext(ctx->object));
    std::vector<АСДЗначення*> arguments;
    for (const auto& argument : ctx->expr()) {
      arguments.push_back(AAV(visitContext(argument)));
    }
    асд_дані_виконати->аргументи = AAVecToList(arguments);
    return AV(this, ctx, АСДВидВиконати, асд_дані_виконати);
  }

  std::any TsilASTVisitor::visitOperation_number(
      TsilParser::Operation_numberContext* ctx) {
    const auto асд_дані_значення_число = new АСДДаніЗначенняЧисло();
    асд_дані_значення_число->значення = strdup(ctx->getText().c_str());
    return AV(this, ctx, АСДВидЗначенняЧисло, асд_дані_значення_число);
  }

  std::any TsilASTVisitor::visitOperation_string(
      TsilParser::Operation_stringContext* ctx) {
    if (ctx->tt) {
      const auto асд_дані_значення_юнікод = new АСДДаніЗначенняЮнікод();
      асд_дані_значення_юнікод->ідентифікатор =
          ІД(this, ctx->tt, ctx->tt->getText());
      асд_дані_значення_юнікод->значення =
          strdup(ctx->STRING()
                     ->getText()
                     .substr(1, ctx->STRING()->getText().size() - 2)
                     .c_str());
      return AV(this, ctx, АСДВидЗначенняЮнікод, асд_дані_значення_юнікод);
    } else {
      const auto асд_дані_значення_текст = new АСДДаніЗначенняТекст();
      асд_дані_значення_текст->значення =
          strdup(ctx->STRING()
                     ->getText()
                     .substr(1, ctx->STRING()->getText().size() - 2)
                     .c_str());
      return AV(this, ctx, АСДВидЗначенняТекст, асд_дані_значення_текст);
    }
  }

  std::any TsilASTVisitor::visitOperation_atom(
      TsilParser::Operation_atomContext* ctx) {
    return visitContext(ctx->atom());
  }

  std::any TsilASTVisitor::visitOperation_mul(
      TsilParser::Operation_mulContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяМноження;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_div(
      TsilParser::Operation_divContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяДілення;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_mod(
      TsilParser::Operation_modContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяМодуль;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_add(
      TsilParser::Operation_addContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяДодавання;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_sub(
      TsilParser::Operation_subContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяВіднімання;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_lshift(
      TsilParser::Operation_lshiftContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяЗсувВліво;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_rshift(
      TsilParser::Operation_rshiftContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяЗсувВправо;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_urshift(
      TsilParser::Operation_urshiftContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяЗсувВправоЗнаковий;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_lt(
      TsilParser::Operation_ltContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяМенше;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_lte(
      TsilParser::Operation_lteContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяМеншеРівне;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_gt(
      TsilParser::Operation_gtContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяБільше;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_gte(
      TsilParser::Operation_gteContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяБільшеРівне;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_eq(
      TsilParser::Operation_eqContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяРівне;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_neq(
      TsilParser::Operation_neqContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяНерівне;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_and(
      TsilParser::Operation_andContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяДІ;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_xor(
      TsilParser::Operation_xorContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяВАБО;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_or(
      TsilParser::Operation_orContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяДАБО;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_land(
      TsilParser::Operation_landContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяІ;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_lor(
      TsilParser::Operation_lorContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяАБО;
    асд_дані_операція->право = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидОперація, асд_дані_операція);
  }

  std::any TsilASTVisitor::visitOperation_ternary(
      TsilParser::Operation_ternaryContext* ctx) {
    const auto асд_дані_значення_якщо = new АСДДаніЗначенняЯкщо();
    асд_дані_значення_якщо->умова = AAV(visitContext(ctx->cond));
    асд_дані_значення_якщо->значення_так = AAV(visitContext(ctx->ifok));
    асд_дані_значення_якщо->значення_ні = AAV(visitContext(ctx->ifnot));
    return AV(this, ctx, АСДВидЗначенняЯкщо, асд_дані_значення_якщо);
  }

  std::any TsilASTVisitor::visitExpr_operation(
      TsilParser::Expr_operationContext* ctx) {
    return visitContext(ctx->operation());
  }

  std::any TsilASTVisitor::visitExpr_object(
      TsilParser::Expr_objectContext* ctx) {
    const auto асд_дані_створити_обʼєкт = new АСДДаніСтворитиОбʼєкт();
    асд_дані_створити_обʼєкт->тип = AAV(visitContext(ctx->type()));
    std::vector<АСДЗначення*> args;
    for (const auto& argument : ctx->expr()) {
      args.push_back(AAV(visitContext(argument)));
    }
    асд_дані_створити_обʼєкт->аргументи = AAVecToList(args);
    return AV(this, ctx, АСДВидСтворитиОбʼєкт, асд_дані_створити_обʼєкт);
  }

  std::any TsilASTVisitor::visitStructure_declare(
      TsilParser::Structure_declareContext* ctx) {
    const auto асд_дані_створити_структуру = new АСДДаніСтворитиСтруктуру();
    асд_дані_створити_структуру->ідентифікатор =
        ІД(this, ctx->id, ctx->id->getText());
    const auto асд_значення_створити_структуру =
        AV(this, ctx, АСДВидСтворитиСтруктуру, асд_дані_створити_структуру);
    const auto асд_дані_визначити = new АСДДаніВизначити();
    if (ctx->first_gendef == nullptr) {
      асд_дані_визначити->обʼєкт = асд_значення_створити_структуру;
    } else {
      const auto асд_дані_створити_шаблон = new АСДДаніСтворитиШаблон();
      асд_дані_створити_шаблон->значення = асд_значення_створити_структуру;
      std::vector<Ідентифікатор*> params;
      for (const auto& gendef : ctx->gendef()) {
        params.push_back(ІД(this, gendef, gendef->getText()));
      }
      асд_дані_створити_шаблон->кількість_параметрів = params.size();
      асд_дані_створити_шаблон->параметри = VecToArr(params);
      асд_дані_визначити->обʼєкт =
          AV(this, ctx, АСДВидСтворитиШаблон, асд_дані_створити_шаблон);
    }
    асд_дані_визначити->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидВизначити, асд_дані_визначити);
  }

  std::any TsilASTVisitor::visitStructure_define(
      TsilParser::Structure_defineContext* ctx) {
    const auto асд_дані_створити_структуру = new АСДДаніСтворитиСтруктуру();
    асд_дані_створити_структуру->ідентифікатор =
        ІД(this, ctx->id, ctx->id->getText());
    std::vector<Параметр*> params;
    for (const auto& structureElement : ctx->structure_element()) {
      const auto any_param = visitParam(structureElement->param());
      params.push_back(std::any_cast<Параметр*>(any_param));
    }
    асд_дані_створити_структуру->кількість_параметрів = params.size();
    асд_дані_створити_структуру->параметри = VecToArr(params);
    const auto асд_значення_створити_структуру =
        AV(this, ctx, АСДВидСтворитиСтруктуру, асд_дані_створити_структуру);
    const auto асд_дані_визначити = new АСДДаніВизначити();
    if (ctx->first_gendef == nullptr) {
      асд_дані_визначити->обʼєкт = асд_значення_створити_структуру;
    } else {
      const auto асд_дані_створити_шаблон = new АСДДаніСтворитиШаблон();
      асд_дані_створити_шаблон->значення = асд_значення_створити_структуру;
      std::vector<Ідентифікатор*> params;
      for (const auto& gendef : ctx->gendef()) {
        params.push_back(ІД(this, gendef, gendef->getText()));
      }
      асд_дані_створити_шаблон->кількість_параметрів = params.size();
      асд_дані_створити_шаблон->параметри = VecToArr(params);
      асд_дані_визначити->обʼєкт =
          AV(this, ctx, АСДВидСтворитиШаблон, асд_дані_створити_шаблон);
    }
    асд_дані_визначити->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидВизначити, асд_дані_визначити);
  }

  std::any TsilASTVisitor::visitDiia_declare(
      TsilParser::Diia_declareContext* ctx) {
    const auto асд_дані_створити_дію = new АСДДаніСтворитиДію();
    асд_дані_створити_дію->ідентифікатор =
        ІД(this, ctx->id, ctx->id->getText());
    std::vector<Параметр*> params;
    for (const auto& param : ctx->param()) {
      const auto any_param = visitParam(param);
      params.push_back(std::any_cast<Параметр*>(any_param));
    }
    const auto створити_тип_дії = new АСДДаніСтворитиТипДії();
    створити_тип_дії->кількість_параметрів = params.size();
    створити_тип_дії->параметри = VecToArr(params);
    if (ctx->restyp) {
      створити_тип_дії->тип_результату = AAV(visitContext(ctx->restyp));
    } else {
      створити_тип_дії->тип_результату = nullptr;
    }
    асд_дані_створити_дію->тип =
        AV(this, ctx, АСДВидСтворитиТипДії, створити_тип_дії);
    const auto асд_значення_створити_дію =
        AV(this, ctx, АСДВидСтворитиДію, асд_дані_створити_дію);
    const auto асд_дані_визначити = new АСДДаніВизначити();
    if (ctx->first_gendef == nullptr) {
      асд_дані_визначити->обʼєкт = асд_значення_створити_дію;
    } else {
      const auto асд_дані_створити_шаблон = new АСДДаніСтворитиШаблон();
      асд_дані_створити_шаблон->значення = асд_значення_створити_дію;
      std::vector<Ідентифікатор*> params;
      for (const auto& gendef : ctx->gendef()) {
        params.push_back(ІД(this, gendef, gendef->getText()));
      }
      асд_дані_створити_шаблон->кількість_параметрів = params.size();
      асд_дані_створити_шаблон->параметри = VecToArr(params);
      асд_дані_визначити->обʼєкт =
          AV(this, ctx, АСДВидСтворитиШаблон, асд_дані_створити_шаблон);
    }
    асд_дані_визначити->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидВизначити, асд_дані_визначити);
  }

  std::any TsilASTVisitor::visitDiia_define(
      TsilParser::Diia_defineContext* ctx) {
    const auto асд_дані_створити_дію = new АСДДаніСтворитиДію();
    асд_дані_створити_дію->ідентифікатор =
        ІД(this, ctx->id, ctx->id->getText());
    std::vector<Параметр*> params;
    for (const auto& param : ctx->param()) {
      const auto any_param = visitParam(param);
      params.push_back(std::any_cast<Параметр*>(any_param));
    }
    const auto створити_тип_дії = new АСДДаніСтворитиТипДії();
    створити_тип_дії->кількість_параметрів = params.size();
    створити_тип_дії->параметри = VecToArr(params);
    if (ctx->restyp) {
      створити_тип_дії->тип_результату = AAV(visitContext(ctx->restyp));
    } else {
      створити_тип_дії->тип_результату = nullptr;
    }
    асд_дані_створити_дію->тип =
        AV(this, ctx, АСДВидСтворитиТипДії, створити_тип_дії);
    асд_дані_створити_дію->тіло = AAVecToList(AAVec(visitBody(ctx->body())));
    const auto асд_значення_створити_дію =
        AV(this, ctx, АСДВидСтворитиДію, асд_дані_створити_дію);
    const auto асд_дані_визначити = new АСДДаніВизначити();
    if (ctx->first_gendef == nullptr) {
      асд_дані_визначити->обʼєкт = асд_значення_створити_дію;
    } else {
      const auto асд_дані_створити_шаблон = new АСДДаніСтворитиШаблон();
      асд_дані_створити_шаблон->значення = асд_значення_створити_дію;
      std::vector<Ідентифікатор*> params;
      for (const auto& gendef : ctx->gendef()) {
        params.push_back(ІД(this, gendef, gendef->getText()));
      }
      асд_дані_створити_шаблон->кількість_параметрів = params.size();
      асд_дані_створити_шаблон->параметри = VecToArr(params);
      асд_дані_визначити->обʼєкт =
          AV(this, ctx, АСДВидСтворитиШаблон, асд_дані_створити_шаблон);
    }
    асд_дані_визначити->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидВизначити, асд_дані_визначити);
  }

  std::any TsilASTVisitor::visitTsil_declare(
      TsilParser::Tsil_declareContext* ctx) {
    const auto асд_дані_створити_ціль = new АСДДаніСтворитиЦіль();
    if (ctx->type() != nullptr) {
      асд_дані_створити_ціль->тип = AAV(visitContext(ctx->type()));
    } else {
      асд_дані_створити_ціль->тип = nullptr;
    }
    асд_дані_створити_ціль->значення = nullptr;
    const auto асд_значення_створити_ціль =
        AV(this, ctx, АСДВидСтворитиЦіль, асд_дані_створити_ціль);
    const auto асд_дані_визначити = new АСДДаніВизначити();
    асд_дані_визначити->обʼєкт = асд_значення_створити_ціль;
    асд_дані_визначити->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидВизначити, асд_дані_визначити);
  }

  std::any TsilASTVisitor::visitTsil_define(
      TsilParser::Tsil_defineContext* ctx) {
    const auto асд_дані_створити_ціль = new АСДДаніСтворитиЦіль();
    if (ctx->type() != nullptr) {
      асд_дані_створити_ціль->тип = AAV(visitContext(ctx->type()));
    } else {
      асд_дані_створити_ціль->тип = nullptr;
    }
    асд_дані_створити_ціль->значення = AAV(visitContext(ctx->expr()));
    const auto асд_значення_створити_ціль =
        AV(this, ctx, АСДВидСтворитиЦіль, асд_дані_створити_ціль);
    const auto асд_дані_визначити = new АСДДаніВизначити();
    асд_дані_визначити->обʼєкт = асд_значення_створити_ціль;
    асд_дані_визначити->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидВизначити, асд_дані_визначити);
  }

  std::any TsilASTVisitor::visitSynonym(TsilParser::SynonymContext* ctx) {
    const auto асд_дані_створити_синонім = new АСДДаніСтворитиСинонім();
    асд_дані_створити_синонім->значення = AAV(visitContext(ctx->expr()));
    const auto асд_значення_створити_синонім =
        AV(this, ctx, АСДВидСтворитиСинонім, асд_дані_створити_синонім);
    const auto асд_дані_визначити = new АСДДаніВизначити();
    асд_дані_визначити->обʼєкт = асд_значення_створити_синонім;
    асд_дані_визначити->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидВизначити, асд_дані_визначити);
  }

  std::any TsilASTVisitor::visitSection_declare(
      TsilParser::Section_declareContext* ctx) {
    const auto асд_дані_створити_секцію = new АСДДаніСтворитиСекцію();
    асд_дані_створити_секцію->ідентифікатор =
        ІД(this, ctx->id, ctx->id->getText());
    асд_дані_створити_секцію->тіло = nullptr;
    const auto асд_значення_створити_секцію =
        AV(this, ctx, АСДВидСтворитиСекцію, асд_дані_створити_секцію);
    const auto асд_дані_визначити = new АСДДаніВизначити();
    асд_дані_визначити->обʼєкт = асд_значення_створити_секцію;
    асд_дані_визначити->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидВизначити, асд_дані_визначити);
  }

  std::any TsilASTVisitor::visitSection_define(
      TsilParser::Section_defineContext* ctx) {
    const auto асд_дані_створити_секцію = new АСДДаніСтворитиСекцію();
    асд_дані_створити_секцію->ідентифікатор =
        ІД(this, ctx->id, ctx->id->getText());
    асд_дані_створити_секцію->тіло = AAVecToList(AAVec(visitBody(ctx->body())));
    const auto асд_значення_створити_секцію =
        AV(this, ctx, АСДВидСтворитиСекцію, асд_дані_створити_секцію);
    const auto асд_дані_визначити = new АСДДаніВизначити();
    асд_дані_визначити->обʼєкт = асд_значення_створити_секцію;
    асд_дані_визначити->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидВизначити, асд_дані_визначити);
  }

  std::any TsilASTVisitor::visitSet(TsilParser::SetContext* ctx) {
    const auto асд_дані_змінити = new АСДДаніЗмінити();
    асд_дані_змінити->обʼєкт = AAV(visitContext(ctx->object));
    асд_дані_змінити->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    асд_дані_змінити->значення = AAV(visitContext(ctx->value));
    return AV(this, ctx, АСДВидЗмінити, асд_дані_змінити);
  }

  std::any TsilASTVisitor::visitPosition_set(
      TsilParser::Position_setContext* ctx) {
    const auto асд_дані_змінити_за_позицією = new АСДДаніЗмінитиЗаПозицією();
    асд_дані_змінити_за_позицією->обʼєкт = AAV(visitContext(ctx->object));
    асд_дані_змінити_за_позицією->позиція = AAV(visitContext(ctx->idx));
    асд_дані_змінити_за_позицією->значення = AAV(visitContext(ctx->value));
    return AV(this, ctx, АСДВидЗмінитиЗаПозицією, асд_дані_змінити_за_позицією);
  }

  std::any TsilASTVisitor::visitSection_set(
      TsilParser::Section_setContext* ctx) {
    const auto асд_дані_змінити_в_секції = new АСДДаніЗмінитиВСекції();
    асд_дані_змінити_в_секції->обʼєкт = AAV(visitContext(ctx->object));
    асд_дані_змінити_в_секції->ідентифікатор =
        ІД(this, ctx->id, ctx->id->getText());
    асд_дані_змінити_в_секції->значення = AAV(visitContext(ctx->value));
    return AV(this, ctx, АСДВидЗмінитиВСекції, асд_дані_змінити_в_секції);
  }

  std::any TsilASTVisitor::visitIf(TsilParser::IfContext* ctx) {
    const auto асд_дані_якщо = new АСДДаніЯкщо();
    асд_дані_якщо->умова = AAV(visitContext(ctx->cond));
    асд_дані_якщо->тіло = AAVecToList(AAVec(visitBody(ctx->ifok)));
    if (ctx->ifnot != nullptr) {
      асд_дані_якщо->тіло_інакше = AAVecToList(AAVec(visitBody(ctx->ifnot)));
    } else if (ctx->ifnotif != nullptr) {
      асд_дані_якщо->тіло_інакше = AAVecToList({AAV(visitIf(ctx->ifnotif))});
    } else {
      асд_дані_якщо->тіло_інакше = AAVecToList({});
    }
    return AV(this, ctx, АСДВидЯкщо, асд_дані_якщо);
  }

  std::any TsilASTVisitor::visitWhile(TsilParser::WhileContext* ctx) {
    const auto асд_дані_поки = new АСДДаніПоки();
    асд_дані_поки->умова = AAV(visitContext(ctx->cond));
    асд_дані_поки->тіло = AAVecToList(AAVec(visitBody(ctx->body())));
    return AV(this, ctx, АСДВидПоки, асд_дані_поки);
  }

  std::any TsilASTVisitor::visitBody(TsilParser::BodyContext* ctx) {
    std::vector<АСДЗначення*> elements;
    for (const auto& bodyElement : ctx->body_element()) {
      if (bodyElement->SEMICOLON() == nullptr) {
        const auto any_асд = visitBody_element(bodyElement);
        elements.push_back(AAV(any_асд));
      }
    }
    return elements;
  }

  std::any TsilASTVisitor::visitBody_element(
      TsilParser::Body_elementContext* ctx) {
    if (ctx->structure_declare() != nullptr) {
      return visitStructure_declare(ctx->structure_declare());
    }
    if (ctx->structure_define() != nullptr) {
      return visitStructure_define(ctx->structure_define());
    }
    if (ctx->diia_declare() != nullptr) {
      return visitDiia_declare(ctx->diia_declare());
    }
    if (ctx->diia_define() != nullptr) {
      return visitDiia_define(ctx->diia_define());
    }
    if (ctx->tsil_declare() != nullptr) {
      return visitTsil_declare(ctx->tsil_declare());
    }
    if (ctx->tsil_define() != nullptr) {
      return visitTsil_define(ctx->tsil_define());
    }
    if (ctx->synonym() != nullptr) {
      return visitSynonym(ctx->synonym());
    }
    if (ctx->section_declare() != nullptr) {
      return visitSection_declare(ctx->section_declare());
    }
    if (ctx->section_define() != nullptr) {
      return visitSection_define(ctx->section_define());
    }
    if (ctx->set() != nullptr) {
      return visitSet(ctx->set());
    }
    if (ctx->position_set() != nullptr) {
      return visitPosition_set(ctx->position_set());
    }
    if (ctx->section_set() != nullptr) {
      return visitSection_set(ctx->section_set());
    }
    if (ctx->if_() != nullptr) {
      return visitIf(ctx->if_());
    }
    if (ctx->while_() != nullptr) {
      return visitWhile(ctx->while_());
    }
    if (ctx->expr() != nullptr) {
      return visitContext(ctx->expr());
    }
    if (ctx->return_() != nullptr) {
      return visitReturn(ctx->return_());
    }
    std::cout << "Unknown body element" << std::endl;
    return nullptr;
  }

  std::any TsilASTVisitor::visitReturn(TsilParser::ReturnContext* ctx) {
    const auto асд_дані_вернути = new АСДДаніВернути();
    асд_дані_вернути->значення = AAV(visitContext(ctx->value));
    return AV(this, ctx, АСДВидВернути, асд_дані_вернути);
  }

  std::any TsilASTVisitor::visitType_nested(
      TsilParser::Type_nestedContext* ctx) {
    return visitContext(ctx->type());
  }

  std::any TsilASTVisitor::visitType_subject(
      TsilParser::Type_subjectContext* ctx) {
    const auto асд_дані_звернутись = new АСДДаніЗвернутись();
    асд_дані_звернутись->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
  }

  std::any TsilASTVisitor::visitType_section_get(
      TsilParser::Type_section_getContext* ctx) {
    const auto асд_дані_отримати_зі_секції = new АСДДаніОтриматиЗіСекції();
    асд_дані_отримати_зі_секції->обʼєкт = AAV(visitContext(ctx->object));
    асд_дані_отримати_зі_секції->ідентифікатор =
        ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидОтриматиЗіСекції, асд_дані_отримати_зі_секції);
  }

  std::any TsilASTVisitor::visitType_template_get(
      TsilParser::Type_template_getContext* ctx) {
    const auto асд_дані_виконати_шаблон = new АСДДаніВиконатиШаблон();
    асд_дані_виконати_шаблон->обʼєкт = AAV(visitContext(ctx->object));
    std::vector<АСДЗначення*> args;
    for (const auto& argument : ctx->type()) {
      if (argument != ctx->object) {
        args.push_back(AAV(visitContext(argument)));
      }
    }
    асд_дані_виконати_шаблон->аргументи = AAVecToList(args);
    return AV(this, ctx, АСДВидВиконатиШаблон, асд_дані_виконати_шаблон);
  }

  std::any TsilASTVisitor::visitType_get(TsilParser::Type_getContext* ctx) {
    const auto асд_дані_отримати = new АСДДаніОтримати();
    асд_дані_отримати->обʼєкт = AAV(visitContext(ctx->object));
    асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
  }

  std::any TsilASTVisitor::visitType_array(TsilParser::Type_arrayContext* ctx) {
    const auto асд_дані_створити_тип_масиву = new АСДДаніСтворитиТипМасиву();
    асд_дані_створити_тип_масиву->тип = AAV(visitContext(ctx->type()));
    const auto асд_дані_значення_число = new АСДДаніЗначенняЧисло();
    асд_дані_значення_число->значення =
        strdup(ctx->NUMBER()->getText().c_str());
    асд_дані_створити_тип_масиву->розмір =
        AV(this, ctx, АСДВидЗначенняЧисло, асд_дані_значення_число);
    return AV(this, ctx, АСДВидСтворитиТипМасиву, асд_дані_створити_тип_масиву);
  }

  std::any TsilASTVisitor::visitType_fn(TsilParser::Type_fnContext* ctx) {
    const auto створити_тип_дії = new АСДДаніСтворитиТипДії();
    створити_тип_дії->кількість_параметрів = 0;
    створити_тип_дії->параметри = nullptr;
    створити_тип_дії->тип_результату = AAV(visitContext(ctx->restyp));
    return AV(this, ctx, АСДВидСтворитиТипДії, створити_тип_дії);
  }

  std::any TsilASTVisitor::visitType_fn_simple(
      TsilParser::Type_fn_simpleContext* ctx) {
    const auto створити_тип_дії = new АСДДаніСтворитиТипДії();
    std::vector<Параметр*> params;
    const auto t = AAV(visitContext(ctx->param_type));
    const auto параметр = new Параметр();
    параметр->ідентифікатор = nullptr;
    параметр->тип = t;
    params.push_back(параметр);
    створити_тип_дії->кількість_параметрів = params.size();
    створити_тип_дії->параметри = VecToArr(params);
    створити_тип_дії->тип_результату = AAV(visitContext(ctx->restyp));
    return AV(this, ctx, АСДВидСтворитиТипДії, створити_тип_дії);
  }

  std::any TsilASTVisitor::visitType_fn_complex(
      TsilParser::Type_fn_complexContext* ctx) {
    const auto створити_тип_дії = new АСДДаніСтворитиТипДії();
    std::vector<Параметр*> params;
    for (const auto& param : ctx->type()) {
      if (param != ctx->restyp) {
        const auto t = AAV(visitContext(param));
        const auto параметр = new Параметр();
        параметр->ідентифікатор = nullptr;
        параметр->тип = t;
        params.push_back(параметр);
      }
    }
    створити_тип_дії->кількість_параметрів = params.size();
    створити_тип_дії->параметри = VecToArr(params);
    створити_тип_дії->тип_результату = AAV(visitContext(ctx->restyp));
    return AV(this, ctx, АСДВидСтворитиТипДії, створити_тип_дії);
  }

  std::any TsilASTVisitor::visitType_fn_complex_named(
      TsilParser::Type_fn_complex_namedContext* ctx) {
    const auto створити_тип_дії = new АСДДаніСтворитиТипДії();
    std::vector<Параметр*> params;
    for (const auto& param : ctx->param()) {
      const auto параметр = any_cast<Параметр*>(visitParam(param));
      params.push_back(параметр);
    }
    створити_тип_дії->кількість_параметрів = params.size();
    створити_тип_дії->параметри = VecToArr(params);
    створити_тип_дії->тип_результату = AAV(visitContext(ctx->restyp));
    return AV(this, ctx, АСДВидСтворитиТипДії, створити_тип_дії);
  }

  std::any TsilASTVisitor::visitParam(TsilParser::ParamContext* ctx) {
    const auto параметр = new Параметр();
    if (ctx->id) {
      параметр->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    }
    if (ctx->type()) {
      параметр->тип = AAV(visitContext(ctx->type()));
    }
    return параметр;
  }

} // namespace tsil::parser