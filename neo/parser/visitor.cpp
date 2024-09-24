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
      elements.push_back(AAV(visitBody_element(element)));
    }
    return AAVecToList(elements);
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
    // todo: ...
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
      асд_дані_значення_юнікод->значення = strdup(ctx->getText().c_str());
      return AV(this, ctx, АСДВидЗначенняЮнікод, асд_дані_значення_юнікод);
    } else {
      const auto асд_дані_значення_текст = new АСДДаніЗначенняТекст();
      асд_дані_значення_текст->значення = strdup(ctx->getText().c_str());
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
    // todo: ...
  }

  std::any TsilASTVisitor::visitExpr_operation(
      TsilParser::Expr_operationContext* ctx) {
    return visitContext(ctx->operation());
  }

  std::any TsilASTVisitor::visitStructure_declare(
      TsilParser::Structure_declareContext* ctx) {}

  std::any TsilASTVisitor::visitStructure_define(
      TsilParser::Structure_defineContext* ctx) {}

  std::any TsilASTVisitor::visitDiia_declare(
      TsilParser::Diia_declareContext* ctx) {}

  std::any TsilASTVisitor::visitDiia_define(
      TsilParser::Diia_defineContext* ctx) {}

  std::any TsilASTVisitor::visitTsil_declare(
      TsilParser::Tsil_declareContext* ctx) {}

  std::any TsilASTVisitor::visitTsil_define(
      TsilParser::Tsil_defineContext* ctx) {}

  std::any TsilASTVisitor::visitSynonym(TsilParser::SynonymContext* ctx) {}

  std::any TsilASTVisitor::visitSection_declare(
      TsilParser::Section_declareContext* ctx) {}

  std::any TsilASTVisitor::visitSection_define(
      TsilParser::Section_defineContext* ctx) {}

  std::any TsilASTVisitor::visitSet(TsilParser::SetContext* ctx) {}

  std::any TsilASTVisitor::visitPosition_set(
      TsilParser::Position_setContext* ctx) {}

  std::any TsilASTVisitor::visitSection_set(
      TsilParser::Section_setContext* ctx) {}

  std::any TsilASTVisitor::visitIf(TsilParser::IfContext* ctx) {}

  std::any TsilASTVisitor::visitWhile(TsilParser::WhileContext* ctx) {}

  std::any TsilASTVisitor::visitBody(TsilParser::BodyContext* ctx) {}

  std::any TsilASTVisitor::visitBody_element(
      TsilParser::Body_elementContext* ctx) {}

  std::any TsilASTVisitor::visitType_nested(
      TsilParser::Type_nestedContext* ctx) {}

  std::any TsilASTVisitor::visitType_subject(
      TsilParser::Type_subjectContext* ctx) {}

  std::any TsilASTVisitor::visitType_section_get(
      TsilParser::Type_section_getContext* ctx) {}

  std::any TsilASTVisitor::visitType_template_get(
      TsilParser::Type_template_getContext* ctx) {}

  std::any TsilASTVisitor::visitType_get(TsilParser::Type_getContext* ctx) {}

  std::any TsilASTVisitor::visitType_array(TsilParser::Type_arrayContext* ctx) {
  }

  std::any TsilASTVisitor::visitType_fn_simple(
      TsilParser::Type_fn_simpleContext* ctx) {}

  std::any TsilASTVisitor::visitType_fn_complex(
      TsilParser::Type_fn_complexContext* ctx) {}

  std::any TsilASTVisitor::visitType_fn_complex_named(
      TsilParser::Type_fn_complex_namedContext* ctx) {}

  std::any TsilASTVisitor::visitParam(TsilParser::ParamContext* ctx) {}

} // namespace tsil::parser