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
            dynamic_cast<TsilParser::Operation_pre_notContext*>(context)) {
      return visitOperation_pre_not(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_pre_bw_notContext*>(context)) {
      return visitOperation_pre_bw_not(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_pre_plusContext*>(context)) {
      return visitOperation_pre_plus(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Operation_pre_minusContext*>(context)) {
      return visitOperation_pre_minus(ctx);
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
            dynamic_cast<TsilParser::Operation_isContext*>(context)) {
      return visitOperation_is(ctx);
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
            dynamic_cast<TsilParser::Operation_asContext*>(context)) {
      return visitOperation_as(ctx);
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
            dynamic_cast<TsilParser::Typeless_objectContext*>(context)) {
      return visitTypeless_object(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Structure_defineContext*>(context)) {
      return visitStructure_define(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Enum_defineContext*>(context)) {
      return visitEnum_define(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Diia_defineContext*>(context)) {
      return visitDiia_define(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Tsil_defineContext*>(context)) {
      return visitTsil_define(ctx);
    }
    if (const auto ctx = dynamic_cast<TsilParser::AssignContext*>(context)) {
      return visitAssign(ctx);
    }
    if (const auto ctx = dynamic_cast<TsilParser::SynonymContext*>(context)) {
      return visitSynonym(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Synonym_fnContext*>(context)) {
      return visitSynonym_fn(ctx);
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
    if (const auto ctx = dynamic_cast<TsilParser::LabelContext*>(context)) {
      return visitLabel(ctx);
    }
    if (const auto ctx = dynamic_cast<TsilParser::GotoContext*>(context)) {
      return visitGoto(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Simple_type_subjectContext*>(context)) {
      return visitSimple_type_subject(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Simple_type_section_getContext*>(
                context)) {
      return visitSimple_type_section_get(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Simple_type_template_getContext*>(
                context)) {
      return visitSimple_type_template_get(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Simple_type_getContext*>(context)) {
      return visitSimple_type_get(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Simple_type_arrayContext*>(context)) {
      return visitSimple_type_array(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Type_simple_typeContext*>(context)) {
      return visitContext(ctx->simple_type());
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
    if (const auto ctx =
            dynamic_cast<TsilParser::Type_nestedContext*>(context)) {
      return visitType_nested(ctx);
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Type_singleContext*>(context)) {
      return visitContext(ctx->single_type());
    }
    if (const auto ctx =
            dynamic_cast<TsilParser::Type_variationContext*>(context)) {
      return visitType_variation(ctx);
    }
    if (const auto ctx = dynamic_cast<TsilParser::ParamContext*>(context)) {
      return visitParam(ctx);
    }
    if (const auto ctx = dynamic_cast<TsilParser::TakeContext*>(context)) {
      return visitTake(ctx);
    }
    std::cout << "[PARSER] Unknown context: " << context->getText()
              << std::endl;
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
    for (const auto& argument : ctx->call_arg()) {
      if (argument->expr()) {
        arguments.push_back(AAV(visitContext(argument->expr())));
      } else if (argument->typeless_object()) {
        arguments.push_back(AAV(visitContext(argument->typeless_object())));
      }
    }
    асд_дані_виконати->аргументи = AAVecToList(arguments);
    return AV(this, ctx, АСДВидВиконати, асд_дані_виконати);
  }

  std::any TsilASTVisitor::visitOperation_number(
      TsilParser::Operation_numberContext* ctx) {
    const auto асд_дані_значення_число = new АСДДаніЗначенняЧисло();
    auto value = ctx->getText();
    асд_дані_значення_число->база = 0;
    асд_дані_значення_число->значення = nullptr;
    асд_дані_значення_число->розмір_значення = 0;
    асд_дані_значення_число->тип = АСДТипЧислаАВТО;
    асд_дані_значення_число->дробове = false;
    if (value.starts_with("0ш") || value.starts_with("0Ш")) {
      value = value.substr(3);
      асд_дані_значення_число->база = 16;
    } else if (value.starts_with("0д") || value.starts_with("0Д")) {
      value = value.substr(3);
      асд_дані_значення_число->база = 2;
    } else {
      асд_дані_значення_число->база = 10;
    }
    if (value.ends_with("ц8")) {
      value = value.substr(0, value.size() - 3);
      асд_дані_значення_число->тип = АСДТипЧислаЦ8;
    } else if (value.ends_with("ц16")) {
      value = value.substr(0, value.size() - 4);
      асд_дані_значення_число->тип = АСДТипЧислаЦ16;
    } else if (value.ends_with("ц32")) {
      value = value.substr(0, value.size() - 4);
      асд_дані_значення_число->тип = АСДТипЧислаЦ32;
    } else if (value.ends_with("ц64")) {
      value = value.substr(0, value.size() - 4);
      асд_дані_значення_число->тип = АСДТипЧислаЦ64;
    } else if (value.ends_with("п8")) {
      value = value.substr(0, value.size() - 3);
      асд_дані_значення_число->тип = АСДТипЧислаП8;
    } else if (value.ends_with("п16")) {
      value = value.substr(0, value.size() - 4);
      асд_дані_значення_число->тип = АСДТипЧислаП16;
    } else if (value.ends_with("п32")) {
      value = value.substr(0, value.size() - 4);
      асд_дані_значення_число->тип = АСДТипЧислаП32;
    } else if (value.ends_with("п64")) {
      value = value.substr(0, value.size() - 4);
      асд_дані_значення_число->тип = АСДТипЧислаП64;
    } else if (value.ends_with("д32")) {
      value = value.substr(0, value.size() - 4);
      асд_дані_значення_число->тип = АСДТипЧислаД32;
    } else if (value.ends_with("д64")) {
      value = value.substr(0, value.size() - 4);
      асд_дані_значення_число->тип = АСДТипЧислаД64;
    }
    if (value.find('.') != std::string::npos) {
      асд_дані_значення_число->дробове = true;
    }
    асд_дані_значення_число->значення = strdup(value.c_str());
    асд_дані_значення_число->розмір_значення = strlen(value.c_str());
    return AV(this, ctx, АСДВидЗначенняЧисло, асд_дані_значення_число);
  }

  std::any TsilASTVisitor::visitOperation_string(
      TsilParser::Operation_stringContext* ctx) {
    const auto асд_дані_значення_текст = new АСДДаніЗначенняТекст();
    if (ctx->tt != nullptr) {
      асд_дані_значення_текст->ідентифікатор =
          ІД(this, ctx->tt, ctx->tt->getText());
    }
    асд_дані_значення_текст->значення =
        strdup(ctx->STRING()
                   ->getText()
                   .substr(1, ctx->STRING()->getText().size() - 2)
                   .c_str());
    асд_дані_значення_текст->розмір_значення =
        strlen(ctx->STRING()
                   ->getText()
                   .substr(1, ctx->STRING()->getText().size() - 2)
                   .c_str());
    return AV(this, ctx, АСДВидЗначенняТекст, асд_дані_значення_текст);
  }

  std::any TsilASTVisitor::visitOperation_atom(
      TsilParser::Operation_atomContext* ctx) {
    return visitContext(ctx->atom());
  }

  std::any TsilASTVisitor::visitOperation_pre_not(
      TsilParser::Operation_pre_notContext* ctx) {
    const auto асд_дані_само_операція = new АСДДаніСамоОперація();
    асд_дані_само_операція->операція = АСДСамоОпераціяЛогічнеНі;
    асд_дані_само_операція->обʼєкт = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидСамоОперація, асд_дані_само_операція);
  }

  std::any TsilASTVisitor::visitOperation_pre_bw_not(
      TsilParser::Operation_pre_bw_notContext* ctx) {
    const auto асд_дані_само_операція = new АСДДаніСамоОперація();
    асд_дані_само_операція->операція = АСДСамоОпераціяДвійковеНі;
    асд_дані_само_операція->обʼєкт = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидСамоОперація, асд_дані_само_операція);
  }

  std::any TsilASTVisitor::visitOperation_pre_plus(
      TsilParser::Operation_pre_plusContext* ctx) {
    const auto асд_дані_само_операція = new АСДДаніСамоОперація();
    асд_дані_само_операція->операція = АСДСамоОпераціяПлюс;
    асд_дані_само_операція->обʼєкт = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидСамоОперація, асд_дані_само_операція);
  }

  std::any TsilASTVisitor::visitOperation_pre_minus(
      TsilParser::Operation_pre_minusContext* ctx) {
    const auto асд_дані_само_операція = new АСДДаніСамоОперація();
    асд_дані_само_операція->операція = АСДСамоОпераціяМінус;
    асд_дані_само_операція->обʼєкт = AAV(visitContext(ctx->right));
    return AV(this, ctx, АСДВидСамоОперація, асд_дані_само_операція);
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

  std::any TsilASTVisitor::visitOperation_is(
      TsilParser::Operation_isContext* ctx) {
    const auto асд_дані_операція = new АСДДаніОперація();
    асд_дані_операція->ліво = AAV(visitContext(ctx->left));
    асд_дані_операція->операція = АСДОпераціяЄ;
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

  std::any TsilASTVisitor::visitOperation_as(
      TsilParser::Operation_asContext* ctx) {
    const auto асд_дані_як = new АСДДаніЯк();
    асд_дані_як->значення = AAV(visitContext(ctx->left));
    if (ctx->right_type) {
      асд_дані_як->тип = AAV(visitContext(ctx->right_type));
    } else {
      асд_дані_як->тип = nullptr;
    }
    return AV(this, ctx, АСДВидЯк, асд_дані_як);
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
    const auto асд_дані_значення_обʼєкт = new АСДДаніЗначенняОбʼєкт();
    асд_дані_значення_обʼєкт->тип = AAV(visitContext(ctx->simple_type()));
    std::vector<АргументОбʼєкта*> args;
    for (const auto& argument : ctx->object_arg()) {
      if (argument->autofill) {
        асд_дані_значення_обʼєкт->автозаповнення = true;
      } else {
        const auto аргумент_обʼєкта = new АргументОбʼєкта();
        if (argument->id) {
          аргумент_обʼєкта->ідентифікатор =
              ІД(this, argument->id, argument->id->getText());
        } else {
          аргумент_обʼєкта->ідентифікатор = nullptr;
        }
        if (argument->value_expr) {
          аргумент_обʼєкта->значення = AAV(visitContext(argument->value_expr));
        } else if (argument->value_object) {
          аргумент_обʼєкта->значення =
              AAV(visitContext(argument->value_object));
        } else {
          аргумент_обʼєкта->значення = nullptr;
        }
        аргумент_обʼєкта->місцезнаходження = LOC(this, ctx);
        args.push_back(аргумент_обʼєкта);
      }
    }
    асд_дані_значення_обʼєкт->кількість_аргументів = args.size();
    асд_дані_значення_обʼєкт->аргументи = VecToArr(args);
    return AV(this, ctx, АСДВидЗначенняОбʼєкт, асд_дані_значення_обʼєкт);
  }

  std::any TsilASTVisitor::visitTypeless_object(
      TsilParser::Typeless_objectContext* ctx) {
    const auto асд_дані_значення_безтиповий_обʼєкт =
        new АСДДаніЗначенняБезтиповийОбʼєкт();
    std::vector<АргументОбʼєкта*> args;
    for (const auto& argument : ctx->object_arg()) {
      if (argument->autofill) {
        асд_дані_значення_безтиповий_обʼєкт->автозаповнення = true;
      } else {
        const auto аргумент_обʼєкта = new АргументОбʼєкта();
        if (argument->id) {
          аргумент_обʼєкта->ідентифікатор =
              ІД(this, argument->id, argument->id->getText());
        } else {
          аргумент_обʼєкта->ідентифікатор = nullptr;
        }
        if (argument->value_expr) {
          аргумент_обʼєкта->значення = AAV(visitContext(argument->value_expr));
        } else if (argument->value_object) {
          аргумент_обʼєкта->значення =
              AAV(visitContext(argument->value_object));
        } else {
          аргумент_обʼєкта->значення = nullptr;
        }
        аргумент_обʼєкта->місцезнаходження = LOC(this, ctx);
        args.push_back(аргумент_обʼєкта);
      }
    }
    асд_дані_значення_безтиповий_обʼєкт->кількість_аргументів = args.size();
    асд_дані_значення_безтиповий_обʼєкт->аргументи = VecToArr(args);
    return AV(this, ctx, АСДВидЗначенняБезтиповийОбʼєкт,
              асд_дані_значення_безтиповий_обʼєкт);
  }

  std::any TsilASTVisitor::visitStructure_define(
      TsilParser::Structure_defineContext* ctx) {
    const auto асд_дані_структура = new АСДДаніСтруктура();
    асд_дані_структура->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    std::vector<Параметр*> params;
    for (const auto& structureElement : ctx->structure_element()) {
      const auto any_param = visitParam(structureElement->param());
      params.push_back(std::any_cast<Параметр*>(any_param));
    }
    асд_дані_структура->кількість_параметрів = params.size();
    асд_дані_структура->параметри = VecToArr(params);
    const auto асд_значення_структура =
        AV(this, ctx, АСДВидСтруктура, асд_дані_структура);
    if (ctx->first_gendef == nullptr) {
      return асд_значення_структура;
    } else {
      const auto асд_дані_шаблон = new АСДДаніШаблон();
      асд_дані_шаблон->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      асд_дані_шаблон->значення = асд_значення_структура;
      std::vector<Ідентифікатор*> params;
      for (const auto& gendef : ctx->gendef()) {
        params.push_back(ІД(this, gendef, gendef->getText()));
      }
      асд_дані_шаблон->кількість_параметрів = params.size();
      асд_дані_шаблон->параметри = VecToArr(params);
      return AV(this, ctx, АСДВидШаблон, асд_дані_шаблон);
    }
  }

  std::any TsilASTVisitor::visitEnum_define(
      TsilParser::Enum_defineContext* ctx) {
    const auto асд_дані_перелік = new АСДДаніПерелік();
    асд_дані_перелік->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    std::vector<ЕлементПереліку*> elements;
    for (const auto& enumElement : ctx->enum_element()) {
      const auto елемент_переліку = new ЕлементПереліку();
      елемент_переліку->ідентифікатор =
          ІД(this, enumElement->id, enumElement->id->getText());
      if (enumElement->param().empty()) {
        елемент_переліку->структура_ = nullptr;
      } else {
        const auto асд_дані_структура = new АСДДаніСтруктура();
        асд_дані_структура->ідентифікатор =
            ІД(this, enumElement->id, enumElement->id->getText());
        std::vector<Параметр*> params;
        for (const auto& param : enumElement->param()) {
          const auto any_param = visitParam(param);
          params.push_back(std::any_cast<Параметр*>(any_param));
        }
        асд_дані_структура->кількість_параметрів = params.size();
        асд_дані_структура->параметри = VecToArr(params);
        елемент_переліку->структура_ = асд_дані_структура;
      }
      елемент_переліку->місцезнаходження = LOC(this, enumElement);
      elements.push_back(елемент_переліку);
    }
    асд_дані_перелік->кількість_елементів = elements.size();
    асд_дані_перелік->елементи = VecToArr(elements);
    const auto асд_значення_перелік =
        AV(this, ctx, АСДВидПерелік, асд_дані_перелік);
    return асд_значення_перелік;
    //    if (ctx->first_gendef == nullptr) {
    //      return асд_значення_перелік;
    //    } else {
    //      const auto асд_дані_шаблон = new АСДДаніШаблон();
    //      асд_дані_шаблон->ідентифікатор = ІД(this, ctx->id,
    //      ctx->id->getText()); асд_дані_шаблон->значення =
    //      асд_значення_перелік; std::vector<Ідентифікатор*> params; for (const
    //      auto& gendef : ctx->gendef()) {
    //        params.push_back(ІД(this, gendef, gendef->getText()));
    //      }
    //      асд_дані_шаблон->кількість_параметрів = params.size();
    //      асд_дані_шаблон->параметри = VecToArr(params);
    //      return AV(this, ctx, АСДВидШаблон, асд_дані_шаблон);
    //    }
  }

  std::any TsilASTVisitor::visitDiia_define(
      TsilParser::Diia_defineContext* ctx) {
    const auto асд_дані_дія = new АСДДаніДія();
    if (ctx->extern_) {
      асд_дані_дія->видимість = АСДВидимістьЗовнішня;
    } else if (ctx->local) {
      асд_дані_дія->видимість = АСДВидимістьМісцева;
    } else {
      асд_дані_дія->видимість = АСДВидимістьВнутрішня;
    }
    асд_дані_дія->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    std::vector<Параметр*> params;
    for (const auto& param : ctx->param()) {
      const auto any_param = visitParam(param);
      params.push_back(std::any_cast<Параметр*>(any_param));
    }
    асд_дані_дія->кількість_параметрів = params.size();
    асд_дані_дія->параметри = VecToArr(params);
    if (ctx->restyp) {
      асд_дані_дія->тип_результату = AAV(visitContext(ctx->restyp));
    } else {
      асд_дані_дія->тип_результату = nullptr;
    }
    if (ctx->body()) {
      асд_дані_дія->тіло = AAVecToList(AAVec(visitBody(ctx->body())));
    } else {
      асд_дані_дія->тіло = nullptr;
    }
    const auto асд_значення_дія = AV(this, ctx, АСДВидДія, асд_дані_дія);
    if (ctx->first_gendef == nullptr) {
      return асд_значення_дія;
    } else {
      const auto асд_дані_шаблон = new АСДДаніШаблон();
      асд_дані_шаблон->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      асд_дані_шаблон->значення = асд_значення_дія;
      std::vector<Ідентифікатор*> params;
      for (const auto& gendef : ctx->gendef()) {
        params.push_back(ІД(this, gendef, gendef->getText()));
      }
      асд_дані_шаблон->кількість_параметрів = params.size();
      асд_дані_шаблон->параметри = VecToArr(params);
      return AV(this, ctx, АСДВидШаблон, асд_дані_шаблон);
    }
  }

  std::any TsilASTVisitor::visitTsil_define(
      TsilParser::Tsil_defineContext* ctx) {
    const auto асд_дані_ціль = new АСДДаніЦіль();
    асд_дані_ціль->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    if (ctx->td_external) {
      асд_дані_ціль->видимість = АСДВидимістьЗовнішня;
    } else if (ctx->td_local) {
      асд_дані_ціль->видимість = АСДВидимістьМісцева;
    } else {
      асд_дані_ціль->видимість = АСДВидимістьВнутрішня;
    }
    if (ctx->td_var) {
      асд_дані_ціль->модифікатор = АСДМодифікаторЗмінна;
    } else if (ctx->td_immut) {
      асд_дані_ціль->модифікатор = АСДМодифікаторСтала;
    } else {
      асд_дані_ціль->модифікатор = АСДМодифікаторЦіль;
    }
    if (ctx->type() != nullptr) {
      асд_дані_ціль->тип = AAV(visitContext(ctx->type()));
    } else {
      асд_дані_ціль->тип = nullptr;
    }
    if (ctx->value_expr) {
      асд_дані_ціль->значення = AAV(visitContext(ctx->value_expr));
    } else if (ctx->value_object) {
      асд_дані_ціль->значення = AAV(visitContext(ctx->value_object));
    } else {
      асд_дані_ціль->значення = nullptr;
    }
    return AV(this, ctx, АСДВидЦіль, асд_дані_ціль);
  }

  std::any TsilASTVisitor::visitAssign(TsilParser::AssignContext* ctx) {
    const auto асд_дані_перезаписати = new АСДДаніПерезаписати();
    асд_дані_перезаписати->ідентифікатор =
        ІД(this, ctx->id, ctx->id->getText());
    АСДЗначення* значення;
    if (ctx->value_expr) {
      значення = AAV(visitContext(ctx->value_expr));
    } else if (ctx->value_object) {
      значення = AAV(visitContext(ctx->value_object));
    } else {
      значення = nullptr;
    }
    if (ctx->assign_op()->aop_mul) {
      const auto асд_дані_звернутись = new АСДДаніЗвернутись();
      асд_дані_звернутись->ідентифікатор =
          ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_звернутись =
          AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_звернутись;
      асд_дані_операція->операція = АСДОпераціяМноження;
      асд_дані_операція->право = значення;
      асд_дані_перезаписати->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_div) {
      const auto асд_дані_звернутись = new АСДДаніЗвернутись();
      асд_дані_звернутись->ідентифікатор =
          ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_звернутись =
          AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_звернутись;
      асд_дані_операція->операція = АСДОпераціяДілення;
      асд_дані_операція->право = значення;
      асд_дані_перезаписати->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_mod) {
      const auto асд_дані_звернутись = new АСДДаніЗвернутись();
      асд_дані_звернутись->ідентифікатор =
          ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_звернутись =
          AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_звернутись;
      асд_дані_операція->операція = АСДОпераціяМодуль;
      асд_дані_операція->право = значення;
      асд_дані_перезаписати->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_plus) {
      const auto асд_дані_звернутись = new АСДДаніЗвернутись();
      асд_дані_звернутись->ідентифікатор =
          ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_звернутись =
          AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_звернутись;
      асд_дані_операція->операція = АСДОпераціяДодавання;
      асд_дані_операція->право = значення;
      асд_дані_перезаписати->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_minus) {
      const auto асд_дані_звернутись = new АСДДаніЗвернутись();
      асд_дані_звернутись->ідентифікатор =
          ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_звернутись =
          AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_звернутись;
      асд_дані_операція->операція = АСДОпераціяВіднімання;
      асд_дані_операція->право = значення;
      асд_дані_перезаписати->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->op_lshift()) {
      const auto асд_дані_звернутись = new АСДДаніЗвернутись();
      асд_дані_звернутись->ідентифікатор =
          ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_звернутись =
          AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_звернутись;
      асд_дані_операція->операція = АСДОпераціяЗсувВліво;
      асд_дані_операція->право = значення;
      асд_дані_перезаписати->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->op_rshift()) {
      const auto асд_дані_звернутись = new АСДДаніЗвернутись();
      асд_дані_звернутись->ідентифікатор =
          ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_звернутись =
          AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_звернутись;
      асд_дані_операція->операція = АСДОпераціяЗсувВправо;
      асд_дані_операція->право = значення;
      асд_дані_перезаписати->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->op_urshift()) {
      const auto асд_дані_звернутись = new АСДДаніЗвернутись();
      асд_дані_звернутись->ідентифікатор =
          ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_звернутись =
          AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_звернутись;
      асд_дані_операція->операція = АСДОпераціяЗсувВправоЗнаковий;
      асд_дані_операція->право = значення;
      асд_дані_перезаписати->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_and) {
      const auto асд_дані_звернутись = new АСДДаніЗвернутись();
      асд_дані_звернутись->ідентифікатор =
          ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_звернутись =
          AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_звернутись;
      асд_дані_операція->операція = АСДОпераціяДІ;
      асд_дані_операція->право = значення;
      асд_дані_перезаписати->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_xor) {
      const auto асд_дані_звернутись = new АСДДаніЗвернутись();
      асд_дані_звернутись->ідентифікатор =
          ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_звернутись =
          AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_звернутись;
      асд_дані_операція->операція = АСДОпераціяВАБО;
      асд_дані_операція->право = значення;
      асд_дані_перезаписати->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_or) {
      const auto асд_дані_звернутись = new АСДДаніЗвернутись();
      асд_дані_звернутись->ідентифікатор =
          ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_звернутись =
          AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_звернутись;
      асд_дані_операція->операція = АСДОпераціяДАБО;
      асд_дані_операція->право = значення;
      асд_дані_перезаписати->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else {
      асд_дані_перезаписати->значення = значення;
    }
    return AV(this, ctx, АСДВидПерезаписати, асд_дані_перезаписати);
  }

  std::any TsilASTVisitor::visitSynonym(TsilParser::SynonymContext* ctx) {
    const auto асд_дані_синонім = new АСДДаніСинонім();
    асд_дані_синонім->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    if (ctx->value_expr) {
      асд_дані_синонім->значення = AAV(visitContext(ctx->value_expr));
    } else if (ctx->value_object) {
      асд_дані_синонім->значення = AAV(visitContext(ctx->value_object));
    } else if (ctx->value_type) {
      асд_дані_синонім->значення = AAV(visitContext(ctx->value_type));
    } else {
      асд_дані_синонім->значення = nullptr;
    }
    const auto асд_значення_синонім =
        AV(this, ctx, АСДВидСинонім, асд_дані_синонім);
    if (ctx->first_gendef == nullptr) {
      return асд_значення_синонім;
    } else {
      const auto асд_дані_шаблон = new АСДДаніШаблон();
      асд_дані_шаблон->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      асд_дані_шаблон->значення = асд_значення_синонім;
      std::vector<Ідентифікатор*> params;
      for (const auto& gendef : ctx->gendef()) {
        params.push_back(ІД(this, gendef, gendef->getText()));
      }
      асд_дані_шаблон->кількість_параметрів = params.size();
      асд_дані_шаблон->параметри = VecToArr(params);
      return AV(this, ctx, АСДВидШаблон, асд_дані_шаблон);
    }
  }

  std::any TsilASTVisitor::visitSynonym_fn(TsilParser::Synonym_fnContext* ctx) {
    const auto асд_дані_синонім = new АСДДаніСинонімДія();
    асд_дані_синонім->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    асд_дані_синонім->значення = AAV(visitContext(ctx->expr()));
    const auto асд_значення_синонім_дія =
        AV(this, ctx, АСДВидСинонімДія, асд_дані_синонім);
    if (ctx->first_gendef == nullptr) {
      return асд_значення_синонім_дія;
    } else {
      const auto асд_дані_шаблон = new АСДДаніШаблон();
      асд_дані_шаблон->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      асд_дані_шаблон->значення = асд_значення_синонім_дія;
      std::vector<Ідентифікатор*> params;
      for (const auto& gendef : ctx->gendef()) {
        params.push_back(ІД(this, gendef, gendef->getText()));
      }
      асд_дані_шаблон->кількість_параметрів = params.size();
      асд_дані_шаблон->параметри = VecToArr(params);
      return AV(this, ctx, АСДВидШаблон, асд_дані_шаблон);
    }
  }

  std::any TsilASTVisitor::visitSection_define(
      TsilParser::Section_defineContext* ctx) {
    const auto асд_дані_секція = new АСДДаніСекція();
    асд_дані_секція->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    if (ctx->body()) {
      асд_дані_секція->тіло = AAVecToList(AAVec(visitBody(ctx->body())));
    } else {
      асд_дані_секція->тіло = nullptr;
    }
    return AV(this, ctx, АСДВидСекція, асд_дані_секція);
  }

  std::any TsilASTVisitor::visitSet(TsilParser::SetContext* ctx) {
    const auto асд_дані_змінити = new АСДДаніЗмінити();
    асд_дані_змінити->обʼєкт = AAV(visitContext(ctx->object));
    асд_дані_змінити->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    АСДЗначення* значення;
    if (ctx->value_expr) {
      значення = AAV(visitContext(ctx->value_expr));
    } else if (ctx->value_object) {
      значення = AAV(visitContext(ctx->value_object));
    } else {
      значення = nullptr;
    }
    if (ctx->assign_op()->aop_mul) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_отримати =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати;
      асд_дані_операція->операція = АСДОпераціяМноження;
      асд_дані_операція->право = значення;
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_div) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_отримати =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати;
      асд_дані_операція->операція = АСДОпераціяДілення;
      асд_дані_операція->право = значення;
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_mod) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_отримати =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати;
      асд_дані_операція->операція = АСДОпераціяМодуль;
      асд_дані_операція->право = значення;
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_plus) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_отримати =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати;
      асд_дані_операція->операція = АСДОпераціяДодавання;
      асд_дані_операція->право = значення;
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_minus) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_отримати =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати;
      асд_дані_операція->операція = АСДОпераціяВіднімання;
      асд_дані_операція->право = значення;
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->op_lshift()) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_отримати =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати;
      асд_дані_операція->операція = АСДОпераціяЗсувВліво;
      асд_дані_операція->право = значення;
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->op_rshift()) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_отримати =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати;
      асд_дані_операція->операція = АСДОпераціяЗсувВправо;
      асд_дані_операція->право = значення;
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->op_urshift()) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_отримати =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати;
      асд_дані_операція->операція = АСДОпераціяЗсувВправоЗнаковий;
      асд_дані_операція->право = значення;
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_and) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_отримати =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати;
      асд_дані_операція->операція = АСДОпераціяДІ;
      асд_дані_операція->право = значення;
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_xor) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_отримати =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати;
      асд_дані_операція->операція = АСДОпераціяВАБО;
      асд_дані_операція->право = значення;
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_or) {
      const auto асд_дані_отримати = new АСДДаніОтримати();
      асд_дані_отримати->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
      const auto асд_значення_отримати =
          AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати;
      асд_дані_операція->операція = АСДОпераціяДАБО;
      асд_дані_операція->право = значення;
      асд_дані_змінити->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else {
      асд_дані_змінити->значення = значення;
    }
    return AV(this, ctx, АСДВидЗмінити, асд_дані_змінити);
  }

  std::any TsilASTVisitor::visitPosition_set(
      TsilParser::Position_setContext* ctx) {
    const auto асд_дані_змінити_за_позицією = new АСДДаніЗмінитиЗаПозицією();
    асд_дані_змінити_за_позицією->обʼєкт = AAV(visitContext(ctx->object));
    асд_дані_змінити_за_позицією->позиція = AAV(visitContext(ctx->idx));
    АСДЗначення* значення;
    if (ctx->value_expr) {
      значення = AAV(visitContext(ctx->value_expr));
    } else if (ctx->value_object) {
      значення = AAV(visitContext(ctx->value_object));
    } else {
      значення = nullptr;
    }
    if (ctx->assign_op()->aop_mul) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_значення_отримати_за_позицією = AV(
          this, ctx, АСДВидОтриматиЗаПозицією, асд_дані_отримати_за_позицією);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати_за_позицією;
      асд_дані_операція->операція = АСДОпераціяМноження;
      асд_дані_операція->право = значення;
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_div) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_значення_отримати_за_позицією = AV(
          this, ctx, АСДВидОтриматиЗаПозицією, асд_дані_отримати_за_позицією);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати_за_позицією;
      асд_дані_операція->операція = АСДОпераціяДілення;
      асд_дані_операція->право = значення;
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_mod) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_значення_отримати_за_позицією = AV(
          this, ctx, АСДВидОтриматиЗаПозицією, асд_дані_отримати_за_позицією);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати_за_позицією;
      асд_дані_операція->операція = АСДОпераціяМодуль;
      асд_дані_операція->право = значення;
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_plus) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_значення_отримати_за_позицією = AV(
          this, ctx, АСДВидОтриматиЗаПозицією, асд_дані_отримати_за_позицією);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати_за_позицією;
      асд_дані_операція->операція = АСДОпераціяДодавання;
      асд_дані_операція->право = значення;
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_minus) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_значення_отримати_за_позицією = AV(
          this, ctx, АСДВидОтриматиЗаПозицією, асд_дані_отримати_за_позицією);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати_за_позицією;
      асд_дані_операція->операція = АСДОпераціяВіднімання;
      асд_дані_операція->право = значення;
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->op_lshift()) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_значення_отримати_за_позицією = AV(
          this, ctx, АСДВидОтриматиЗаПозицією, асд_дані_отримати_за_позицією);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати_за_позицією;
      асд_дані_операція->операція = АСДОпераціяЗсувВліво;
      асд_дані_операція->право = значення;
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->op_rshift()) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_значення_отримати_за_позицією = AV(
          this, ctx, АСДВидОтриматиЗаПозицією, асд_дані_отримати_за_позицією);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати_за_позицією;
      асд_дані_операція->операція = АСДОпераціяЗсувВправо;
      асд_дані_операція->право = значення;
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->op_urshift()) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_значення_отримати_за_позицією = AV(
          this, ctx, АСДВидОтриматиЗаПозицією, асд_дані_отримати_за_позицією);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати_за_позицією;
      асд_дані_операція->операція = АСДОпераціяЗсувВправоЗнаковий;
      асд_дані_операція->право = значення;
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_and) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_значення_отримати_за_позицією = AV(
          this, ctx, АСДВидОтриматиЗаПозицією, асд_дані_отримати_за_позицією);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати_за_позицією;
      асд_дані_операція->операція = АСДОпераціяДІ;
      асд_дані_операція->право = значення;
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_xor) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_значення_отримати_за_позицією = AV(
          this, ctx, АСДВидОтриматиЗаПозицією, асд_дані_отримати_за_позицією);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати_за_позицією;
      асд_дані_операція->операція = АСДОпераціяВАБО;
      асд_дані_операція->право = значення;
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else if (ctx->assign_op()->aop_or) {
      const auto асд_дані_отримати_за_позицією =
          new АСДДаніОтриматиЗаПозицією();
      асд_дані_отримати_за_позицією->обʼєкт = AAV(visitContext(ctx->object));
      асд_дані_отримати_за_позицією->позиція = AAV(visitContext(ctx->idx));
      const auto асд_значення_отримати_за_позицією = AV(
          this, ctx, АСДВидОтриматиЗаПозицією, асд_дані_отримати_за_позицією);
      const auto асд_дані_операція = new АСДДаніОперація();
      асд_дані_операція->ліво = асд_значення_отримати_за_позицією;
      асд_дані_операція->операція = АСДОпераціяДАБО;
      асд_дані_операція->право = значення;
      асд_дані_змінити_за_позицією->значення =
          AV(this, ctx, АСДВидОперація, асд_дані_операція);
    } else {
      асд_дані_змінити_за_позицією->значення = значення;
    }
    return AV(this, ctx, АСДВидЗмінитиЗаПозицією, асд_дані_змінити_за_позицією);
  }

  std::any TsilASTVisitor::visitSection_set(
      TsilParser::Section_setContext* ctx) {
    const auto асд_дані_змінити_в_секції = new АСДДаніЗмінитиВСекції();
    асд_дані_змінити_в_секції->обʼєкт = AAV(visitContext(ctx->object));
    асд_дані_змінити_в_секції->ідентифікатор =
        ІД(this, ctx->id, ctx->id->getText());
    if (ctx->value_expr) {
      асд_дані_змінити_в_секції->значення = AAV(visitContext(ctx->value_expr));
    } else if (ctx->value_object) {
      асд_дані_змінити_в_секції->значення =
          AAV(visitContext(ctx->value_object));
    } else {
      асд_дані_змінити_в_секції->значення = nullptr;
    }
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
      if (bodyElement->semi == nullptr) {
        const auto any_асд = visitBody_element(bodyElement);
        elements.push_back(AAV(any_асд));
      }
    }
    return elements;
  }

  std::any TsilASTVisitor::visitBody_element(
      TsilParser::Body_elementContext* ctx) {
    if (ctx->structure_define() != nullptr) {
      return visitStructure_define(ctx->structure_define());
    }
    if (ctx->enum_define() != nullptr) {
      return visitEnum_define(ctx->enum_define());
    }
    if (ctx->diia_define() != nullptr) {
      return visitDiia_define(ctx->diia_define());
    }
    if (ctx->tsil_define() != nullptr) {
      return visitTsil_define(ctx->tsil_define());
    }
    if (ctx->assign() != nullptr) {
      return visitAssign(ctx->assign());
    }
    if (ctx->synonym() != nullptr) {
      return visitSynonym(ctx->synonym());
    }
    if (ctx->synonym_fn() != nullptr) {
      return visitSynonym_fn(ctx->synonym_fn());
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
    if (ctx->label() != nullptr) {
      return visitLabel(ctx->label());
    }
    if (ctx->goto_() != nullptr) {
      return visitGoto(ctx->goto_());
    }
    if (ctx->take() != nullptr) {
      return visitTake(ctx->take());
    }
    std::cout << "Unknown body element" << std::endl;
    return nullptr;
  }

  std::any TsilASTVisitor::visitReturn(TsilParser::ReturnContext* ctx) {
    const auto асд_дані_вернути = new АСДДаніВернути();
    if (ctx->value_expr) {
      асд_дані_вернути->значення = AAV(visitContext(ctx->value_expr));
    } else if (ctx->value_object) {
      асд_дані_вернути->значення = AAV(visitContext(ctx->value_object));
    } else {
      асд_дані_вернути->значення = nullptr;
    }
    return AV(this, ctx, АСДВидВернути, асд_дані_вернути);
  }

  std::any TsilASTVisitor::visitLabel(TsilParser::LabelContext* ctx) {
    const auto асд_дані_мітка = new АСДДаніМітка();
    асд_дані_мітка->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидМітка, асд_дані_мітка);
  }

  std::any TsilASTVisitor::visitGoto(TsilParser::GotoContext* ctx) {
    const auto асд_дані_стрибнути = new АСДДаніСтрибнути();
    асд_дані_стрибнути->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидСтрибнути, асд_дані_стрибнути);
  }

  std::any TsilASTVisitor::visitSimple_type_subject(
      TsilParser::Simple_type_subjectContext* ctx) {
    const auto асд_дані_звернутись = new АСДДаніЗвернутись();
    асд_дані_звернутись->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидЗвернутись, асд_дані_звернутись);
  }

  std::any TsilASTVisitor::visitSimple_type_section_get(
      TsilParser::Simple_type_section_getContext* ctx) {
    const auto асд_дані_отримати_зі_секції = new АСДДаніОтриматиЗіСекції();
    асд_дані_отримати_зі_секції->обʼєкт = AAV(visitContext(ctx->object));
    асд_дані_отримати_зі_секції->ідентифікатор =
        ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидОтриматиЗіСекції, асд_дані_отримати_зі_секції);
  }

  std::any TsilASTVisitor::visitSimple_type_template_get(
      TsilParser::Simple_type_template_getContext* ctx) {
    const auto асд_дані_виконати_шаблон = new АСДДаніВиконатиШаблон();
    асд_дані_виконати_шаблон->обʼєкт = AAV(visitContext(ctx->object));
    std::vector<АСДЗначення*> args;
    for (const auto& argument : ctx->type()) {
      args.push_back(AAV(visitContext(argument)));
    }
    асд_дані_виконати_шаблон->аргументи = AAVecToList(args);
    return AV(this, ctx, АСДВидВиконатиШаблон, асд_дані_виконати_шаблон);
  }

  std::any TsilASTVisitor::visitSimple_type_get(
      TsilParser::Simple_type_getContext* ctx) {
    const auto асд_дані_отримати = new АСДДаніОтримати();
    асд_дані_отримати->обʼєкт = AAV(visitContext(ctx->object));
    асд_дані_отримати->ідентифікатор = ІД(this, ctx->id, ctx->id->getText());
    return AV(this, ctx, АСДВидОтримати, асд_дані_отримати);
  }

  std::any TsilASTVisitor::visitSimple_type_array(
      TsilParser::Simple_type_arrayContext* ctx) {
    const auto асд_дані_тип_масиву = new АСДДаніТипМасиву();
    асд_дані_тип_масиву->тип = AAV(visitContext(ctx->simple_type()));
    const auto асд_дані_значення_число = new АСДДаніЗначенняЧисло();
    асд_дані_значення_число->значення =
        strdup(ctx->NUMBER()->getText().c_str());
    асд_дані_значення_число->розмір_значення =
        strlen(ctx->NUMBER()->getText().c_str());
    асд_дані_тип_масиву->розмір =
        AV(this, ctx, АСДВидЗначенняЧисло, асд_дані_значення_число);
    return AV(this, ctx, АСДВидТипМасиву, асд_дані_тип_масиву);
  }

  std::any TsilASTVisitor::visitType_nested(
      TsilParser::Type_nestedContext* ctx) {
    return visitContext(ctx->type());
  }

  std::any TsilASTVisitor::visitType_fn(TsilParser::Type_fnContext* ctx) {
    const auto асд_дані_тип_дії = new АСДДаніТипДії();
    асд_дані_тип_дії->кількість_параметрів = 0;
    асд_дані_тип_дії->параметри = nullptr;
    асд_дані_тип_дії->тип_результату = AAV(visitContext(ctx->restyp));
    return AV(this, ctx, АСДВидТипДії, асд_дані_тип_дії);
  }

  std::any TsilASTVisitor::visitType_fn_simple(
      TsilParser::Type_fn_simpleContext* ctx) {
    const auto асд_дані_тип_дії = new АСДДаніТипДії();
    std::vector<Параметр*> params;
    const auto t = AAV(visitContext(ctx->param_type));
    const auto параметр = new Параметр();
    параметр->ідентифікатор = nullptr;
    параметр->тип = t;
    params.push_back(параметр);
    асд_дані_тип_дії->кількість_параметрів = params.size();
    асд_дані_тип_дії->параметри = VecToArr(params);
    асд_дані_тип_дії->тип_результату = AAV(visitContext(ctx->restyp));
    return AV(this, ctx, АСДВидТипДії, асд_дані_тип_дії);
  }

  std::any TsilASTVisitor::visitType_fn_complex(
      TsilParser::Type_fn_complexContext* ctx) {
    const auto асд_дані_тип_дії = new АСДДаніТипДії();
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
    асд_дані_тип_дії->кількість_параметрів = params.size();
    асд_дані_тип_дії->параметри = VecToArr(params);
    асд_дані_тип_дії->тип_результату = AAV(visitContext(ctx->restyp));
    return AV(this, ctx, АСДВидТипДії, асд_дані_тип_дії);
  }

  std::any TsilASTVisitor::visitType_fn_complex_named(
      TsilParser::Type_fn_complex_namedContext* ctx) {
    const auto асд_дані_тип_дії = new АСДДаніТипДії();
    std::vector<Параметр*> params;
    for (const auto& param : ctx->param()) {
      const auto параметр = any_cast<Параметр*>(visitParam(param));
      params.push_back(параметр);
    }
    асд_дані_тип_дії->кількість_параметрів = params.size();
    асд_дані_тип_дії->параметри = VecToArr(params);
    асд_дані_тип_дії->тип_результату = AAV(visitContext(ctx->restyp));
    return AV(this, ctx, АСДВидТипДії, асд_дані_тип_дії);
  }

  std::any TsilASTVisitor::visitType_variation(
      TsilParser::Type_variationContext* ctx) {
    const auto асд_дані_тип_варіація = new АСДДаніТипВаріація();
    std::vector<АСДЗначення*> types;
    for (const auto& type : ctx->single_type()) {
      types.push_back(AAV(visitContext(type)));
    }
    асд_дані_тип_варіація->типи = AAVecToList(types);
    return AV(this, ctx, АСДВидТипВаріація, асд_дані_тип_варіація);
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

  std::any TsilASTVisitor::visitTake(TsilParser::TakeContext* ctx) {
    const auto асд_дані_взяти = new АСДДаніВзяти();
    асд_дані_взяти->тип = ІД(this, ctx->type_id, ctx->type_id->getText());
    std::vector<Ідентифікатор*> шлях;
    for (const auto& take_element : ctx->take_element()) {
      шлях.push_back(ІД(this, take_element, take_element->getText()));
    }
    асд_дані_взяти->довжина_шляху = шлях.size();
    асд_дані_взяти->шлях = VecToArr(шлях);
    асд_дані_взяти->відносно = ctx->relative ? 1 : 0;
    return AV(this, ctx, АСДВидВзяти, асд_дані_взяти);
  }

} // namespace tsil::parser