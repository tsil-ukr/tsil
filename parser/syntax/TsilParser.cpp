
// Generated from TsilParser.g4 by ANTLR 4.13.0


#include "TsilParserListener.h"
#include "TsilParserVisitor.h"

#include "TsilParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct TsilParserStaticData final {
  TsilParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  TsilParserStaticData(const TsilParserStaticData&) = delete;
  TsilParserStaticData(TsilParserStaticData&&) = delete;
  TsilParserStaticData& operator=(const TsilParserStaticData&) = delete;
  TsilParserStaticData& operator=(TsilParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag tsilparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
TsilParserStaticData *tsilparserParserStaticData = nullptr;

void tsilparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (tsilparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(tsilparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<TsilParserStaticData>(
    std::vector<std::string>{
      "file", "program", "program_element", "structure", "structure_generics", 
      "structure_generic", "structure_params", "structure_param", "constructor", 
      "constructor_args", "constructor_arg", "diia_head", "diia", "diia_declaration", 
      "if", "while", "define", "assign", "set", "sizeof", "atom", "molecule", 
      "expr", "identifiers_chain", "type", "args", "params", "param", "body", 
      "body_element_or_return", "body_element", "return_body_element", "bitwise_op", 
      "comparison_op", "logical_op", "number", "string", "identifier"
    },
    std::vector<std::string>{
      "", "'\\u0446\\u0456\\u043B\\u044C'", "'\\u0434\\u0456\\u044F'", "'\\u043F\\u043E\\u043A\\u043B\\u0430\\u0441\\u0442\\u0438'", 
      "'\\u0432\\u0438\\u0434\\u0430\\u043B\\u0438\\u0442\\u0438'", "'\\u044F\\u043A\\u0449\\u043E'", 
      "'\\u0456\\u043D\\u0430\\u043A\\u0448\\u0435'", "'\\u043F\\u043E\\u043A\\u0438'", 
      "'\\u0432\\u0435\\u0440\\u043D\\u0443\\u0442\\u0438'", "'\\u0441\\u0442\\u0440\\u0443\\u043A\\u0442\\u0443\\u0440\\u0430'", 
      "'\\u0435\\u043A\\u0441\\u0442\\u0435\\u0440\\u043D'", "'\\u044F\\u043A'", 
      "'\\u0440\\u043E\\u0437\\u043C\\u0456\\u0440 \\u0442\\u0438\\u043F\\u0443'", 
      "'='", "'>'", "'<'", "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", 
      "'&'", "'|'", "'('", "')'", "'['", "']'", "'\\u003F'", "':'", "'~'", 
      "'''", "'\"'", "'!'", "','", "';'", "'{'", "'}'"
    },
    std::vector<std::string>{
      "", "KW_TSIL", "KW_DIIA", "KW_SAVE", "KW_DELETE", "KW_IF", "KW_ELSE", 
      "KW_WHILE", "KW_RETURN", "KW_STRUCT", "KW_EXTERN", "KW_AS", "KW_SIZEOF", 
      "EQUAL", "GREATER", "LESSER", "DOT", "PLUS", "MINUS", "MULTIPLY", 
      "DIVIDE", "MOD", "POWER", "AND", "OR", "PAREN_OPEN", "PAREN_CLOSE", 
      "BRACKET_OPEN", "BRACKET_CLOSE", "QUESTION", "COLON", "TILDA", "QUOTE", 
      "DOUBLE_QUOTE", "EXCLAMATION", "COMA", "SEMICOLON", "QUOTE_OPEN", 
      "QUOTE_CLOSE", "NUMBER", "ID", "STRING", "NL", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,43,424,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,1,0,1,0,1,0,1,1,5,1,81,8,1,10,1,12,1,84,9,1,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,98,8,2,1,3,1,3,1,3,
  	1,3,1,3,1,3,3,3,106,8,3,1,3,1,3,3,3,110,8,3,1,3,1,3,1,4,1,4,1,4,5,4,117,
  	8,4,10,4,12,4,120,9,4,1,5,1,5,1,6,1,6,1,6,5,6,127,8,6,10,6,12,6,130,9,
  	6,1,6,3,6,133,8,6,1,7,1,7,1,7,1,7,1,8,3,8,140,8,8,1,8,1,8,1,8,3,8,145,
  	8,8,1,8,1,8,1,9,1,9,1,9,5,9,152,8,9,10,9,12,9,155,9,9,1,9,3,9,158,8,9,
  	1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,3,11,168,8,11,1,11,1,11,1,11,
  	1,11,3,11,174,8,11,1,11,1,11,1,11,3,11,179,8,11,1,12,3,12,182,8,12,1,
  	12,1,12,1,12,3,12,187,8,12,1,12,1,12,1,13,3,13,192,8,13,1,13,1,13,1,13,
  	3,13,197,8,13,1,13,1,13,1,14,1,14,1,14,1,14,3,14,205,8,14,1,14,1,14,1,
  	15,1,15,1,15,1,15,3,15,213,8,15,1,15,1,15,1,16,1,16,1,16,1,16,3,16,221,
  	8,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,231,8,16,1,17,1,17,
  	1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,260,8,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,3,20,268,8,20,1,20,5,20,271,8,20,10,20,
  	12,20,274,9,20,1,21,1,21,1,21,3,21,279,8,21,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,3,22,289,8,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,5,22,309,8,22,10,22,
  	12,22,312,9,22,1,23,1,23,1,23,1,23,1,23,1,23,5,23,320,8,23,10,23,12,23,
  	323,9,23,1,24,1,24,1,24,1,24,1,24,5,24,330,8,24,10,24,12,24,333,9,24,
  	1,24,1,24,3,24,337,8,24,1,25,1,25,1,25,5,25,342,8,25,10,25,12,25,345,
  	9,25,1,25,3,25,348,8,25,1,26,1,26,1,26,5,26,353,8,26,10,26,12,26,356,
  	9,26,1,26,3,26,359,8,26,1,27,1,27,1,27,1,27,1,28,4,28,366,8,28,11,28,
  	12,28,367,1,29,1,29,3,29,372,8,29,1,30,1,30,1,30,1,30,1,30,1,30,1,30,
  	1,30,1,30,3,30,383,8,30,1,31,1,31,1,31,1,32,1,32,1,32,1,32,1,32,1,32,
  	1,32,3,32,395,8,32,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,
  	3,33,407,8,33,1,34,1,34,1,34,1,34,3,34,413,8,34,1,35,1,35,1,36,3,36,418,
  	8,36,1,36,1,36,1,37,1,37,1,37,0,3,40,44,46,38,0,2,4,6,8,10,12,14,16,18,
  	20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,
  	66,68,70,72,74,0,2,1,0,19,21,1,0,17,18,459,0,76,1,0,0,0,2,82,1,0,0,0,
  	4,97,1,0,0,0,6,99,1,0,0,0,8,113,1,0,0,0,10,121,1,0,0,0,12,123,1,0,0,0,
  	14,134,1,0,0,0,16,139,1,0,0,0,18,148,1,0,0,0,20,159,1,0,0,0,22,163,1,
  	0,0,0,24,181,1,0,0,0,26,191,1,0,0,0,28,200,1,0,0,0,30,208,1,0,0,0,32,
  	230,1,0,0,0,34,232,1,0,0,0,36,236,1,0,0,0,38,242,1,0,0,0,40,259,1,0,0,
  	0,42,278,1,0,0,0,44,288,1,0,0,0,46,313,1,0,0,0,48,324,1,0,0,0,50,338,
  	1,0,0,0,52,349,1,0,0,0,54,360,1,0,0,0,56,365,1,0,0,0,58,371,1,0,0,0,60,
  	382,1,0,0,0,62,384,1,0,0,0,64,394,1,0,0,0,66,406,1,0,0,0,68,412,1,0,0,
  	0,70,414,1,0,0,0,72,417,1,0,0,0,74,421,1,0,0,0,76,77,3,2,1,0,77,78,5,
  	0,0,1,78,1,1,0,0,0,79,81,3,4,2,0,80,79,1,0,0,0,81,84,1,0,0,0,82,80,1,
  	0,0,0,82,83,1,0,0,0,83,3,1,0,0,0,84,82,1,0,0,0,85,98,3,6,3,0,86,98,3,
  	26,13,0,87,98,3,24,12,0,88,98,3,28,14,0,89,98,3,30,15,0,90,98,3,32,16,
  	0,91,98,3,34,17,0,92,98,3,36,18,0,93,94,3,44,22,0,94,95,5,36,0,0,95,98,
  	1,0,0,0,96,98,5,36,0,0,97,85,1,0,0,0,97,86,1,0,0,0,97,87,1,0,0,0,97,88,
  	1,0,0,0,97,89,1,0,0,0,97,90,1,0,0,0,97,91,1,0,0,0,97,92,1,0,0,0,97,93,
  	1,0,0,0,97,96,1,0,0,0,98,5,1,0,0,0,99,100,5,9,0,0,100,105,3,74,37,0,101,
  	102,5,15,0,0,102,103,3,8,4,0,103,104,5,14,0,0,104,106,1,0,0,0,105,101,
  	1,0,0,0,105,106,1,0,0,0,106,107,1,0,0,0,107,109,5,37,0,0,108,110,3,12,
  	6,0,109,108,1,0,0,0,109,110,1,0,0,0,110,111,1,0,0,0,111,112,5,38,0,0,
  	112,7,1,0,0,0,113,118,3,10,5,0,114,115,5,35,0,0,115,117,3,10,5,0,116,
  	114,1,0,0,0,117,120,1,0,0,0,118,116,1,0,0,0,118,119,1,0,0,0,119,9,1,0,
  	0,0,120,118,1,0,0,0,121,122,3,74,37,0,122,11,1,0,0,0,123,128,3,14,7,0,
  	124,125,5,35,0,0,125,127,3,14,7,0,126,124,1,0,0,0,127,130,1,0,0,0,128,
  	126,1,0,0,0,128,129,1,0,0,0,129,132,1,0,0,0,130,128,1,0,0,0,131,133,5,
  	35,0,0,132,131,1,0,0,0,132,133,1,0,0,0,133,13,1,0,0,0,134,135,3,74,37,
  	0,135,136,5,30,0,0,136,137,3,48,24,0,137,15,1,0,0,0,138,140,5,3,0,0,139,
  	138,1,0,0,0,139,140,1,0,0,0,140,141,1,0,0,0,141,142,3,48,24,0,142,144,
  	5,37,0,0,143,145,3,18,9,0,144,143,1,0,0,0,144,145,1,0,0,0,145,146,1,0,
  	0,0,146,147,5,38,0,0,147,17,1,0,0,0,148,153,3,20,10,0,149,150,5,35,0,
  	0,150,152,3,20,10,0,151,149,1,0,0,0,152,155,1,0,0,0,153,151,1,0,0,0,153,
  	154,1,0,0,0,154,157,1,0,0,0,155,153,1,0,0,0,156,158,5,35,0,0,157,156,
  	1,0,0,0,157,158,1,0,0,0,158,19,1,0,0,0,159,160,3,74,37,0,160,161,5,13,
  	0,0,161,162,3,44,22,0,162,21,1,0,0,0,163,164,5,2,0,0,164,165,3,74,37,
  	0,165,167,5,25,0,0,166,168,3,52,26,0,167,166,1,0,0,0,167,168,1,0,0,0,
  	168,173,1,0,0,0,169,170,5,35,0,0,170,171,5,16,0,0,171,172,5,16,0,0,172,
  	174,5,16,0,0,173,169,1,0,0,0,173,174,1,0,0,0,174,175,1,0,0,0,175,178,
  	5,26,0,0,176,177,5,30,0,0,177,179,3,48,24,0,178,176,1,0,0,0,178,179,1,
  	0,0,0,179,23,1,0,0,0,180,182,5,10,0,0,181,180,1,0,0,0,181,182,1,0,0,0,
  	182,183,1,0,0,0,183,184,3,22,11,0,184,186,5,37,0,0,185,187,3,56,28,0,
  	186,185,1,0,0,0,186,187,1,0,0,0,187,188,1,0,0,0,188,189,5,38,0,0,189,
  	25,1,0,0,0,190,192,5,10,0,0,191,190,1,0,0,0,191,192,1,0,0,0,192,193,1,
  	0,0,0,193,196,3,22,11,0,194,195,5,11,0,0,195,197,3,74,37,0,196,194,1,
  	0,0,0,196,197,1,0,0,0,197,198,1,0,0,0,198,199,5,36,0,0,199,27,1,0,0,0,
  	200,201,5,5,0,0,201,202,3,44,22,0,202,204,5,37,0,0,203,205,3,56,28,0,
  	204,203,1,0,0,0,204,205,1,0,0,0,205,206,1,0,0,0,206,207,5,38,0,0,207,
  	29,1,0,0,0,208,209,5,7,0,0,209,210,3,44,22,0,210,212,5,37,0,0,211,213,
  	3,56,28,0,212,211,1,0,0,0,212,213,1,0,0,0,213,214,1,0,0,0,214,215,5,38,
  	0,0,215,31,1,0,0,0,216,217,5,1,0,0,217,220,3,74,37,0,218,219,5,30,0,0,
  	219,221,3,48,24,0,220,218,1,0,0,0,220,221,1,0,0,0,221,222,1,0,0,0,222,
  	223,5,13,0,0,223,224,3,44,22,0,224,231,1,0,0,0,225,226,5,1,0,0,226,227,
  	3,74,37,0,227,228,5,30,0,0,228,229,3,48,24,0,229,231,1,0,0,0,230,216,
  	1,0,0,0,230,225,1,0,0,0,231,33,1,0,0,0,232,233,3,74,37,0,233,234,5,13,
  	0,0,234,235,3,44,22,0,235,35,1,0,0,0,236,237,3,46,23,0,237,238,5,16,0,
  	0,238,239,3,74,37,0,239,240,5,13,0,0,240,241,3,44,22,0,241,37,1,0,0,0,
  	242,243,5,12,0,0,243,244,3,48,24,0,244,39,1,0,0,0,245,246,6,20,-1,0,246,
  	260,3,74,37,0,247,248,5,17,0,0,248,260,3,40,20,5,249,250,5,18,0,0,250,
  	260,3,40,20,4,251,252,5,34,0,0,252,260,3,40,20,3,253,254,5,31,0,0,254,
  	260,3,40,20,2,255,256,5,25,0,0,256,257,3,44,22,0,257,258,5,26,0,0,258,
  	260,1,0,0,0,259,245,1,0,0,0,259,247,1,0,0,0,259,249,1,0,0,0,259,251,1,
  	0,0,0,259,253,1,0,0,0,259,255,1,0,0,0,260,272,1,0,0,0,261,262,10,7,0,
  	0,262,263,5,16,0,0,263,271,3,74,37,0,264,265,10,6,0,0,265,267,5,25,0,
  	0,266,268,3,50,25,0,267,266,1,0,0,0,267,268,1,0,0,0,268,269,1,0,0,0,269,
  	271,5,26,0,0,270,261,1,0,0,0,270,264,1,0,0,0,271,274,1,0,0,0,272,270,
  	1,0,0,0,272,273,1,0,0,0,273,41,1,0,0,0,274,272,1,0,0,0,275,279,3,40,20,
  	0,276,279,3,70,35,0,277,279,3,72,36,0,278,275,1,0,0,0,278,276,1,0,0,0,
  	278,277,1,0,0,0,279,43,1,0,0,0,280,281,6,22,-1,0,281,289,3,42,21,0,282,
  	289,3,16,8,0,283,289,3,38,19,0,284,285,3,42,21,0,285,286,5,11,0,0,286,
  	287,3,48,24,0,287,289,1,0,0,0,288,280,1,0,0,0,288,282,1,0,0,0,288,283,
  	1,0,0,0,288,284,1,0,0,0,289,310,1,0,0,0,290,291,10,5,0,0,291,292,7,0,
  	0,0,292,309,3,44,22,6,293,294,10,4,0,0,294,295,7,1,0,0,295,309,3,44,22,
  	5,296,297,10,3,0,0,297,298,3,64,32,0,298,299,3,44,22,4,299,309,1,0,0,
  	0,300,301,10,2,0,0,301,302,3,66,33,0,302,303,3,44,22,3,303,309,1,0,0,
  	0,304,305,10,1,0,0,305,306,3,68,34,0,306,307,3,44,22,2,307,309,1,0,0,
  	0,308,290,1,0,0,0,308,293,1,0,0,0,308,296,1,0,0,0,308,300,1,0,0,0,308,
  	304,1,0,0,0,309,312,1,0,0,0,310,308,1,0,0,0,310,311,1,0,0,0,311,45,1,
  	0,0,0,312,310,1,0,0,0,313,314,6,23,-1,0,314,315,5,40,0,0,315,321,1,0,
  	0,0,316,317,10,1,0,0,317,318,5,16,0,0,318,320,5,40,0,0,319,316,1,0,0,
  	0,320,323,1,0,0,0,321,319,1,0,0,0,321,322,1,0,0,0,322,47,1,0,0,0,323,
  	321,1,0,0,0,324,336,3,74,37,0,325,326,5,15,0,0,326,331,3,48,24,0,327,
  	328,5,35,0,0,328,330,3,48,24,0,329,327,1,0,0,0,330,333,1,0,0,0,331,329,
  	1,0,0,0,331,332,1,0,0,0,332,334,1,0,0,0,333,331,1,0,0,0,334,335,5,14,
  	0,0,335,337,1,0,0,0,336,325,1,0,0,0,336,337,1,0,0,0,337,49,1,0,0,0,338,
  	343,3,44,22,0,339,340,5,35,0,0,340,342,3,44,22,0,341,339,1,0,0,0,342,
  	345,1,0,0,0,343,341,1,0,0,0,343,344,1,0,0,0,344,347,1,0,0,0,345,343,1,
  	0,0,0,346,348,5,35,0,0,347,346,1,0,0,0,347,348,1,0,0,0,348,51,1,0,0,0,
  	349,354,3,54,27,0,350,351,5,35,0,0,351,353,3,54,27,0,352,350,1,0,0,0,
  	353,356,1,0,0,0,354,352,1,0,0,0,354,355,1,0,0,0,355,358,1,0,0,0,356,354,
  	1,0,0,0,357,359,5,35,0,0,358,357,1,0,0,0,358,359,1,0,0,0,359,53,1,0,0,
  	0,360,361,3,74,37,0,361,362,5,30,0,0,362,363,3,48,24,0,363,55,1,0,0,0,
  	364,366,3,58,29,0,365,364,1,0,0,0,366,367,1,0,0,0,367,365,1,0,0,0,367,
  	368,1,0,0,0,368,57,1,0,0,0,369,372,3,60,30,0,370,372,3,62,31,0,371,369,
  	1,0,0,0,371,370,1,0,0,0,372,59,1,0,0,0,373,383,3,28,14,0,374,383,3,30,
  	15,0,375,383,3,32,16,0,376,383,3,34,17,0,377,383,3,36,18,0,378,379,3,
  	44,22,0,379,380,5,36,0,0,380,383,1,0,0,0,381,383,5,36,0,0,382,373,1,0,
  	0,0,382,374,1,0,0,0,382,375,1,0,0,0,382,376,1,0,0,0,382,377,1,0,0,0,382,
  	378,1,0,0,0,382,381,1,0,0,0,383,61,1,0,0,0,384,385,5,8,0,0,385,386,3,
  	44,22,0,386,63,1,0,0,0,387,395,5,22,0,0,388,395,5,24,0,0,389,395,5,23,
  	0,0,390,391,5,15,0,0,391,395,5,15,0,0,392,393,5,14,0,0,393,395,5,14,0,
  	0,394,387,1,0,0,0,394,388,1,0,0,0,394,389,1,0,0,0,394,390,1,0,0,0,394,
  	392,1,0,0,0,395,65,1,0,0,0,396,397,5,13,0,0,397,407,5,13,0,0,398,399,
  	5,34,0,0,399,407,5,13,0,0,400,407,5,14,0,0,401,407,5,15,0,0,402,403,5,
  	14,0,0,403,407,5,13,0,0,404,405,5,15,0,0,405,407,5,13,0,0,406,396,1,0,
  	0,0,406,398,1,0,0,0,406,400,1,0,0,0,406,401,1,0,0,0,406,402,1,0,0,0,406,
  	404,1,0,0,0,407,67,1,0,0,0,408,409,5,24,0,0,409,413,5,24,0,0,410,411,
  	5,23,0,0,411,413,5,23,0,0,412,408,1,0,0,0,412,410,1,0,0,0,413,69,1,0,
  	0,0,414,415,5,39,0,0,415,71,1,0,0,0,416,418,5,40,0,0,417,416,1,0,0,0,
  	417,418,1,0,0,0,418,419,1,0,0,0,419,420,5,41,0,0,420,73,1,0,0,0,421,422,
  	5,40,0,0,422,75,1,0,0,0,44,82,97,105,109,118,128,132,139,144,153,157,
  	167,173,178,181,186,191,196,204,212,220,230,259,267,270,272,278,288,308,
  	310,321,331,336,343,347,354,358,367,371,382,394,406,412,417
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  tsilparserParserStaticData = staticData.release();
}

}

TsilParser::TsilParser(TokenStream *input) : TsilParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

TsilParser::TsilParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  TsilParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *tsilparserParserStaticData->atn, tsilparserParserStaticData->decisionToDFA, tsilparserParserStaticData->sharedContextCache, options);
}

TsilParser::~TsilParser() {
  delete _interpreter;
}

const atn::ATN& TsilParser::getATN() const {
  return *tsilparserParserStaticData->atn;
}

std::string TsilParser::getGrammarFileName() const {
  return "TsilParser.g4";
}

const std::vector<std::string>& TsilParser::getRuleNames() const {
  return tsilparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& TsilParser::getVocabulary() const {
  return tsilparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView TsilParser::getSerializedATN() const {
  return tsilparserParserStaticData->serializedATN;
}


//----------------- FileContext ------------------------------------------------------------------

TsilParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::FileContext::EOF() {
  return getToken(TsilParser::EOF, 0);
}

TsilParser::ProgramContext* TsilParser::FileContext::program() {
  return getRuleContext<TsilParser::ProgramContext>(0);
}


size_t TsilParser::FileContext::getRuleIndex() const {
  return TsilParser::RuleFile;
}

void TsilParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void TsilParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}


std::any TsilParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::FileContext* TsilParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, TsilParser::RuleFile);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    antlrcpp::downCast<FileContext *>(_localctx)->f_program = program();
    setState(77);
    match(TsilParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

TsilParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TsilParser::Program_elementContext *> TsilParser::ProgramContext::program_element() {
  return getRuleContexts<TsilParser::Program_elementContext>();
}

TsilParser::Program_elementContext* TsilParser::ProgramContext::program_element(size_t i) {
  return getRuleContext<TsilParser::Program_elementContext>(i);
}


size_t TsilParser::ProgramContext::getRuleIndex() const {
  return TsilParser::RuleProgram;
}

void TsilParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void TsilParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any TsilParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::ProgramContext* TsilParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 2, TsilParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3936371480238) != 0)) {
      setState(79);
      program_element();
      setState(84);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Program_elementContext ------------------------------------------------------------------

TsilParser::Program_elementContext::Program_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TsilParser::StructureContext* TsilParser::Program_elementContext::structure() {
  return getRuleContext<TsilParser::StructureContext>(0);
}

TsilParser::Diia_declarationContext* TsilParser::Program_elementContext::diia_declaration() {
  return getRuleContext<TsilParser::Diia_declarationContext>(0);
}

TsilParser::DiiaContext* TsilParser::Program_elementContext::diia() {
  return getRuleContext<TsilParser::DiiaContext>(0);
}

TsilParser::IfContext* TsilParser::Program_elementContext::if_() {
  return getRuleContext<TsilParser::IfContext>(0);
}

TsilParser::WhileContext* TsilParser::Program_elementContext::while_() {
  return getRuleContext<TsilParser::WhileContext>(0);
}

TsilParser::DefineContext* TsilParser::Program_elementContext::define() {
  return getRuleContext<TsilParser::DefineContext>(0);
}

TsilParser::AssignContext* TsilParser::Program_elementContext::assign() {
  return getRuleContext<TsilParser::AssignContext>(0);
}

TsilParser::SetContext* TsilParser::Program_elementContext::set() {
  return getRuleContext<TsilParser::SetContext>(0);
}

TsilParser::ExprContext* TsilParser::Program_elementContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

tree::TerminalNode* TsilParser::Program_elementContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}


size_t TsilParser::Program_elementContext::getRuleIndex() const {
  return TsilParser::RuleProgram_element;
}

void TsilParser::Program_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram_element(this);
}

void TsilParser::Program_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram_element(this);
}


std::any TsilParser::Program_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitProgram_element(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Program_elementContext* TsilParser::program_element() {
  Program_elementContext *_localctx = _tracker.createInstance<Program_elementContext>(_ctx, getState());
  enterRule(_localctx, 4, TsilParser::RuleProgram_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(97);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(85);
      structure();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(86);
      diia_declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(87);
      diia();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(88);
      if_();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(89);
      while_();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(90);
      define();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(91);
      assign();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(92);
      set();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(93);
      expr(0);
      setState(94);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(96);
      match(TsilParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructureContext ------------------------------------------------------------------

TsilParser::StructureContext::StructureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::StructureContext::KW_STRUCT() {
  return getToken(TsilParser::KW_STRUCT, 0);
}

tree::TerminalNode* TsilParser::StructureContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::StructureContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}

TsilParser::IdentifierContext* TsilParser::StructureContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
}

tree::TerminalNode* TsilParser::StructureContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::StructureContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

TsilParser::Structure_genericsContext* TsilParser::StructureContext::structure_generics() {
  return getRuleContext<TsilParser::Structure_genericsContext>(0);
}

TsilParser::Structure_paramsContext* TsilParser::StructureContext::structure_params() {
  return getRuleContext<TsilParser::Structure_paramsContext>(0);
}


size_t TsilParser::StructureContext::getRuleIndex() const {
  return TsilParser::RuleStructure;
}

void TsilParser::StructureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructure(this);
}

void TsilParser::StructureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructure(this);
}


std::any TsilParser::StructureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitStructure(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::StructureContext* TsilParser::structure() {
  StructureContext *_localctx = _tracker.createInstance<StructureContext>(_ctx, getState());
  enterRule(_localctx, 6, TsilParser::RuleStructure);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    match(TsilParser::KW_STRUCT);
    setState(100);
    antlrcpp::downCast<StructureContext *>(_localctx)->s_name = identifier();
    setState(105);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(101);
      match(TsilParser::LESSER);
      setState(102);
      antlrcpp::downCast<StructureContext *>(_localctx)->s_generics = structure_generics();
      setState(103);
      match(TsilParser::GREATER);
    }
    setState(107);
    match(TsilParser::QUOTE_OPEN);
    setState(109);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(108);
      antlrcpp::downCast<StructureContext *>(_localctx)->s_params = structure_params();
    }
    setState(111);
    match(TsilParser::QUOTE_CLOSE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Structure_genericsContext ------------------------------------------------------------------

TsilParser::Structure_genericsContext::Structure_genericsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TsilParser::Structure_genericContext *> TsilParser::Structure_genericsContext::structure_generic() {
  return getRuleContexts<TsilParser::Structure_genericContext>();
}

TsilParser::Structure_genericContext* TsilParser::Structure_genericsContext::structure_generic(size_t i) {
  return getRuleContext<TsilParser::Structure_genericContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Structure_genericsContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Structure_genericsContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::Structure_genericsContext::getRuleIndex() const {
  return TsilParser::RuleStructure_generics;
}

void TsilParser::Structure_genericsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructure_generics(this);
}

void TsilParser::Structure_genericsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructure_generics(this);
}


std::any TsilParser::Structure_genericsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitStructure_generics(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Structure_genericsContext* TsilParser::structure_generics() {
  Structure_genericsContext *_localctx = _tracker.createInstance<Structure_genericsContext>(_ctx, getState());
  enterRule(_localctx, 8, TsilParser::RuleStructure_generics);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    structure_generic();
    setState(118);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TsilParser::COMA) {
      setState(114);
      match(TsilParser::COMA);
      setState(115);
      structure_generic();
      setState(120);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Structure_genericContext ------------------------------------------------------------------

TsilParser::Structure_genericContext::Structure_genericContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TsilParser::IdentifierContext* TsilParser::Structure_genericContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
}


size_t TsilParser::Structure_genericContext::getRuleIndex() const {
  return TsilParser::RuleStructure_generic;
}

void TsilParser::Structure_genericContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructure_generic(this);
}

void TsilParser::Structure_genericContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructure_generic(this);
}


std::any TsilParser::Structure_genericContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitStructure_generic(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Structure_genericContext* TsilParser::structure_generic() {
  Structure_genericContext *_localctx = _tracker.createInstance<Structure_genericContext>(_ctx, getState());
  enterRule(_localctx, 10, TsilParser::RuleStructure_generic);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    antlrcpp::downCast<Structure_genericContext *>(_localctx)->sg_name = identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Structure_paramsContext ------------------------------------------------------------------

TsilParser::Structure_paramsContext::Structure_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TsilParser::Structure_paramContext *> TsilParser::Structure_paramsContext::structure_param() {
  return getRuleContexts<TsilParser::Structure_paramContext>();
}

TsilParser::Structure_paramContext* TsilParser::Structure_paramsContext::structure_param(size_t i) {
  return getRuleContext<TsilParser::Structure_paramContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Structure_paramsContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Structure_paramsContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::Structure_paramsContext::getRuleIndex() const {
  return TsilParser::RuleStructure_params;
}

void TsilParser::Structure_paramsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructure_params(this);
}

void TsilParser::Structure_paramsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructure_params(this);
}


std::any TsilParser::Structure_paramsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitStructure_params(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Structure_paramsContext* TsilParser::structure_params() {
  Structure_paramsContext *_localctx = _tracker.createInstance<Structure_paramsContext>(_ctx, getState());
  enterRule(_localctx, 12, TsilParser::RuleStructure_params);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(123);
    structure_param();
    setState(128);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(124);
        match(TsilParser::COMA);
        setState(125);
        structure_param(); 
      }
      setState(130);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
    setState(132);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COMA) {
      setState(131);
      match(TsilParser::COMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Structure_paramContext ------------------------------------------------------------------

TsilParser::Structure_paramContext::Structure_paramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Structure_paramContext::COLON() {
  return getToken(TsilParser::COLON, 0);
}

TsilParser::IdentifierContext* TsilParser::Structure_paramContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
}

TsilParser::TypeContext* TsilParser::Structure_paramContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}


size_t TsilParser::Structure_paramContext::getRuleIndex() const {
  return TsilParser::RuleStructure_param;
}

void TsilParser::Structure_paramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructure_param(this);
}

void TsilParser::Structure_paramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructure_param(this);
}


std::any TsilParser::Structure_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitStructure_param(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Structure_paramContext* TsilParser::structure_param() {
  Structure_paramContext *_localctx = _tracker.createInstance<Structure_paramContext>(_ctx, getState());
  enterRule(_localctx, 14, TsilParser::RuleStructure_param);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    antlrcpp::downCast<Structure_paramContext *>(_localctx)->sp_name = identifier();
    setState(135);
    match(TsilParser::COLON);
    setState(136);
    antlrcpp::downCast<Structure_paramContext *>(_localctx)->sp_type = type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstructorContext ------------------------------------------------------------------

TsilParser::ConstructorContext::ConstructorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::ConstructorContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::ConstructorContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}

TsilParser::TypeContext* TsilParser::ConstructorContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

tree::TerminalNode* TsilParser::ConstructorContext::KW_SAVE() {
  return getToken(TsilParser::KW_SAVE, 0);
}

TsilParser::Constructor_argsContext* TsilParser::ConstructorContext::constructor_args() {
  return getRuleContext<TsilParser::Constructor_argsContext>(0);
}


size_t TsilParser::ConstructorContext::getRuleIndex() const {
  return TsilParser::RuleConstructor;
}

void TsilParser::ConstructorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstructor(this);
}

void TsilParser::ConstructorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstructor(this);
}


std::any TsilParser::ConstructorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitConstructor(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::ConstructorContext* TsilParser::constructor() {
  ConstructorContext *_localctx = _tracker.createInstance<ConstructorContext>(_ctx, getState());
  enterRule(_localctx, 16, TsilParser::RuleConstructor);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::KW_SAVE) {
      setState(138);
      antlrcpp::downCast<ConstructorContext *>(_localctx)->c_new = match(TsilParser::KW_SAVE);
    }
    setState(141);
    antlrcpp::downCast<ConstructorContext *>(_localctx)->c_type = type();
    setState(142);
    match(TsilParser::QUOTE_OPEN);
    setState(144);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(143);
      antlrcpp::downCast<ConstructorContext *>(_localctx)->c_args = constructor_args();
    }
    setState(146);
    match(TsilParser::QUOTE_CLOSE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constructor_argsContext ------------------------------------------------------------------

TsilParser::Constructor_argsContext::Constructor_argsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TsilParser::Constructor_argContext *> TsilParser::Constructor_argsContext::constructor_arg() {
  return getRuleContexts<TsilParser::Constructor_argContext>();
}

TsilParser::Constructor_argContext* TsilParser::Constructor_argsContext::constructor_arg(size_t i) {
  return getRuleContext<TsilParser::Constructor_argContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Constructor_argsContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Constructor_argsContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::Constructor_argsContext::getRuleIndex() const {
  return TsilParser::RuleConstructor_args;
}

void TsilParser::Constructor_argsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstructor_args(this);
}

void TsilParser::Constructor_argsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstructor_args(this);
}


std::any TsilParser::Constructor_argsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitConstructor_args(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Constructor_argsContext* TsilParser::constructor_args() {
  Constructor_argsContext *_localctx = _tracker.createInstance<Constructor_argsContext>(_ctx, getState());
  enterRule(_localctx, 18, TsilParser::RuleConstructor_args);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(148);
    constructor_arg();
    setState(153);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(149);
        match(TsilParser::COMA);
        setState(150);
        constructor_arg(); 
      }
      setState(155);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
    setState(157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COMA) {
      setState(156);
      match(TsilParser::COMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constructor_argContext ------------------------------------------------------------------

TsilParser::Constructor_argContext::Constructor_argContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Constructor_argContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}

TsilParser::IdentifierContext* TsilParser::Constructor_argContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
}

TsilParser::ExprContext* TsilParser::Constructor_argContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}


size_t TsilParser::Constructor_argContext::getRuleIndex() const {
  return TsilParser::RuleConstructor_arg;
}

void TsilParser::Constructor_argContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstructor_arg(this);
}

void TsilParser::Constructor_argContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstructor_arg(this);
}


std::any TsilParser::Constructor_argContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitConstructor_arg(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Constructor_argContext* TsilParser::constructor_arg() {
  Constructor_argContext *_localctx = _tracker.createInstance<Constructor_argContext>(_ctx, getState());
  enterRule(_localctx, 20, TsilParser::RuleConstructor_arg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    antlrcpp::downCast<Constructor_argContext *>(_localctx)->ca_name = identifier();
    setState(160);
    match(TsilParser::EQUAL);
    setState(161);
    antlrcpp::downCast<Constructor_argContext *>(_localctx)->ca_value = expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Diia_headContext ------------------------------------------------------------------

TsilParser::Diia_headContext::Diia_headContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Diia_headContext::KW_DIIA() {
  return getToken(TsilParser::KW_DIIA, 0);
}

tree::TerminalNode* TsilParser::Diia_headContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

tree::TerminalNode* TsilParser::Diia_headContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

TsilParser::IdentifierContext* TsilParser::Diia_headContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
}

std::vector<tree::TerminalNode *> TsilParser::Diia_headContext::DOT() {
  return getTokens(TsilParser::DOT);
}

tree::TerminalNode* TsilParser::Diia_headContext::DOT(size_t i) {
  return getToken(TsilParser::DOT, i);
}

tree::TerminalNode* TsilParser::Diia_headContext::COLON() {
  return getToken(TsilParser::COLON, 0);
}

TsilParser::ParamsContext* TsilParser::Diia_headContext::params() {
  return getRuleContext<TsilParser::ParamsContext>(0);
}

tree::TerminalNode* TsilParser::Diia_headContext::COMA() {
  return getToken(TsilParser::COMA, 0);
}

TsilParser::TypeContext* TsilParser::Diia_headContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}


size_t TsilParser::Diia_headContext::getRuleIndex() const {
  return TsilParser::RuleDiia_head;
}

void TsilParser::Diia_headContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiia_head(this);
}

void TsilParser::Diia_headContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiia_head(this);
}


std::any TsilParser::Diia_headContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitDiia_head(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Diia_headContext* TsilParser::diia_head() {
  Diia_headContext *_localctx = _tracker.createInstance<Diia_headContext>(_ctx, getState());
  enterRule(_localctx, 22, TsilParser::RuleDiia_head);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    match(TsilParser::KW_DIIA);
    setState(164);
    antlrcpp::downCast<Diia_headContext *>(_localctx)->d_name = identifier();
    setState(165);
    match(TsilParser::PAREN_OPEN);
    setState(167);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(166);
      antlrcpp::downCast<Diia_headContext *>(_localctx)->d_params = params();
    }
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COMA) {
      setState(169);
      antlrcpp::downCast<Diia_headContext *>(_localctx)->d_variadic = match(TsilParser::COMA);
      setState(170);
      match(TsilParser::DOT);
      setState(171);
      match(TsilParser::DOT);
      setState(172);
      match(TsilParser::DOT);
    }
    setState(175);
    match(TsilParser::PAREN_CLOSE);
    setState(178);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(176);
      match(TsilParser::COLON);
      setState(177);
      antlrcpp::downCast<Diia_headContext *>(_localctx)->d_type = type();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DiiaContext ------------------------------------------------------------------

TsilParser::DiiaContext::DiiaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::DiiaContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::DiiaContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}

TsilParser::Diia_headContext* TsilParser::DiiaContext::diia_head() {
  return getRuleContext<TsilParser::Diia_headContext>(0);
}

tree::TerminalNode* TsilParser::DiiaContext::KW_EXTERN() {
  return getToken(TsilParser::KW_EXTERN, 0);
}

TsilParser::BodyContext* TsilParser::DiiaContext::body() {
  return getRuleContext<TsilParser::BodyContext>(0);
}


size_t TsilParser::DiiaContext::getRuleIndex() const {
  return TsilParser::RuleDiia;
}

void TsilParser::DiiaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiia(this);
}

void TsilParser::DiiaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiia(this);
}


std::any TsilParser::DiiaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitDiia(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::DiiaContext* TsilParser::diia() {
  DiiaContext *_localctx = _tracker.createInstance<DiiaContext>(_ctx, getState());
  enterRule(_localctx, 24, TsilParser::RuleDiia);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::KW_EXTERN) {
      setState(180);
      antlrcpp::downCast<DiiaContext *>(_localctx)->d_extern = match(TsilParser::KW_EXTERN);
    }
    setState(183);
    antlrcpp::downCast<DiiaContext *>(_localctx)->d_head = diia_head();
    setState(184);
    match(TsilParser::QUOTE_OPEN);
    setState(186);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3936371478954) != 0)) {
      setState(185);
      antlrcpp::downCast<DiiaContext *>(_localctx)->d_body = body();
    }
    setState(188);
    match(TsilParser::QUOTE_CLOSE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Diia_declarationContext ------------------------------------------------------------------

TsilParser::Diia_declarationContext::Diia_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Diia_declarationContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

TsilParser::Diia_headContext* TsilParser::Diia_declarationContext::diia_head() {
  return getRuleContext<TsilParser::Diia_headContext>(0);
}

tree::TerminalNode* TsilParser::Diia_declarationContext::KW_AS() {
  return getToken(TsilParser::KW_AS, 0);
}

tree::TerminalNode* TsilParser::Diia_declarationContext::KW_EXTERN() {
  return getToken(TsilParser::KW_EXTERN, 0);
}

TsilParser::IdentifierContext* TsilParser::Diia_declarationContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
}


size_t TsilParser::Diia_declarationContext::getRuleIndex() const {
  return TsilParser::RuleDiia_declaration;
}

void TsilParser::Diia_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiia_declaration(this);
}

void TsilParser::Diia_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiia_declaration(this);
}


std::any TsilParser::Diia_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitDiia_declaration(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Diia_declarationContext* TsilParser::diia_declaration() {
  Diia_declarationContext *_localctx = _tracker.createInstance<Diia_declarationContext>(_ctx, getState());
  enterRule(_localctx, 26, TsilParser::RuleDiia_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::KW_EXTERN) {
      setState(190);
      antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_extern = match(TsilParser::KW_EXTERN);
    }
    setState(193);
    antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_head = diia_head();
    setState(196);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::KW_AS) {
      setState(194);
      match(TsilParser::KW_AS);
      setState(195);
      antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_as = identifier();
    }
    setState(198);
    match(TsilParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfContext ------------------------------------------------------------------

TsilParser::IfContext::IfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::IfContext::KW_IF() {
  return getToken(TsilParser::KW_IF, 0);
}

tree::TerminalNode* TsilParser::IfContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::IfContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}

TsilParser::ExprContext* TsilParser::IfContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

TsilParser::BodyContext* TsilParser::IfContext::body() {
  return getRuleContext<TsilParser::BodyContext>(0);
}


size_t TsilParser::IfContext::getRuleIndex() const {
  return TsilParser::RuleIf;
}

void TsilParser::IfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf(this);
}

void TsilParser::IfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf(this);
}


std::any TsilParser::IfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitIf(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::IfContext* TsilParser::if_() {
  IfContext *_localctx = _tracker.createInstance<IfContext>(_ctx, getState());
  enterRule(_localctx, 28, TsilParser::RuleIf);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    match(TsilParser::KW_IF);
    setState(201);
    antlrcpp::downCast<IfContext *>(_localctx)->i_value = expr(0);
    setState(202);
    match(TsilParser::QUOTE_OPEN);
    setState(204);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3936371478954) != 0)) {
      setState(203);
      antlrcpp::downCast<IfContext *>(_localctx)->i_body = body();
    }
    setState(206);
    match(TsilParser::QUOTE_CLOSE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileContext ------------------------------------------------------------------

TsilParser::WhileContext::WhileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::WhileContext::KW_WHILE() {
  return getToken(TsilParser::KW_WHILE, 0);
}

tree::TerminalNode* TsilParser::WhileContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::WhileContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}

TsilParser::ExprContext* TsilParser::WhileContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

TsilParser::BodyContext* TsilParser::WhileContext::body() {
  return getRuleContext<TsilParser::BodyContext>(0);
}


size_t TsilParser::WhileContext::getRuleIndex() const {
  return TsilParser::RuleWhile;
}

void TsilParser::WhileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile(this);
}

void TsilParser::WhileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile(this);
}


std::any TsilParser::WhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitWhile(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::WhileContext* TsilParser::while_() {
  WhileContext *_localctx = _tracker.createInstance<WhileContext>(_ctx, getState());
  enterRule(_localctx, 30, TsilParser::RuleWhile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(208);
    match(TsilParser::KW_WHILE);
    setState(209);
    antlrcpp::downCast<WhileContext *>(_localctx)->w_value = expr(0);
    setState(210);
    match(TsilParser::QUOTE_OPEN);
    setState(212);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3936371478954) != 0)) {
      setState(211);
      antlrcpp::downCast<WhileContext *>(_localctx)->w_body = body();
    }
    setState(214);
    match(TsilParser::QUOTE_CLOSE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefineContext ------------------------------------------------------------------

TsilParser::DefineContext::DefineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::DefineContext::KW_TSIL() {
  return getToken(TsilParser::KW_TSIL, 0);
}

tree::TerminalNode* TsilParser::DefineContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}

TsilParser::IdentifierContext* TsilParser::DefineContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
}

TsilParser::ExprContext* TsilParser::DefineContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

tree::TerminalNode* TsilParser::DefineContext::COLON() {
  return getToken(TsilParser::COLON, 0);
}

TsilParser::TypeContext* TsilParser::DefineContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}


size_t TsilParser::DefineContext::getRuleIndex() const {
  return TsilParser::RuleDefine;
}

void TsilParser::DefineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefine(this);
}

void TsilParser::DefineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefine(this);
}


std::any TsilParser::DefineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitDefine(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::DefineContext* TsilParser::define() {
  DefineContext *_localctx = _tracker.createInstance<DefineContext>(_ctx, getState());
  enterRule(_localctx, 32, TsilParser::RuleDefine);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(230);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(216);
      match(TsilParser::KW_TSIL);
      setState(217);
      antlrcpp::downCast<DefineContext *>(_localctx)->d_id = identifier();
      setState(220);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TsilParser::COLON) {
        setState(218);
        match(TsilParser::COLON);
        setState(219);
        antlrcpp::downCast<DefineContext *>(_localctx)->d_type = type();
      }
      setState(222);
      match(TsilParser::EQUAL);
      setState(223);
      antlrcpp::downCast<DefineContext *>(_localctx)->d_value = expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(225);
      match(TsilParser::KW_TSIL);
      setState(226);
      antlrcpp::downCast<DefineContext *>(_localctx)->d_id = identifier();
      setState(227);
      match(TsilParser::COLON);
      setState(228);
      antlrcpp::downCast<DefineContext *>(_localctx)->d_type = type();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

TsilParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::AssignContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}

TsilParser::IdentifierContext* TsilParser::AssignContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
}

TsilParser::ExprContext* TsilParser::AssignContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}


size_t TsilParser::AssignContext::getRuleIndex() const {
  return TsilParser::RuleAssign;
}

void TsilParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}

void TsilParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}


std::any TsilParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::AssignContext* TsilParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 34, TsilParser::RuleAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    antlrcpp::downCast<AssignContext *>(_localctx)->a_id = identifier();
    setState(233);
    match(TsilParser::EQUAL);
    setState(234);
    antlrcpp::downCast<AssignContext *>(_localctx)->a_value = expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetContext ------------------------------------------------------------------

TsilParser::SetContext::SetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::SetContext::DOT() {
  return getToken(TsilParser::DOT, 0);
}

tree::TerminalNode* TsilParser::SetContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}

TsilParser::Identifiers_chainContext* TsilParser::SetContext::identifiers_chain() {
  return getRuleContext<TsilParser::Identifiers_chainContext>(0);
}

TsilParser::IdentifierContext* TsilParser::SetContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
}

TsilParser::ExprContext* TsilParser::SetContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}


size_t TsilParser::SetContext::getRuleIndex() const {
  return TsilParser::RuleSet;
}

void TsilParser::SetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSet(this);
}

void TsilParser::SetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSet(this);
}


std::any TsilParser::SetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSet(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::SetContext* TsilParser::set() {
  SetContext *_localctx = _tracker.createInstance<SetContext>(_ctx, getState());
  enterRule(_localctx, 36, TsilParser::RuleSet);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(236);
    antlrcpp::downCast<SetContext *>(_localctx)->s_left = identifiers_chain(0);
    setState(237);
    match(TsilParser::DOT);
    setState(238);
    antlrcpp::downCast<SetContext *>(_localctx)->s_id = identifier();
    setState(239);
    match(TsilParser::EQUAL);
    setState(240);
    antlrcpp::downCast<SetContext *>(_localctx)->s_value = expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SizeofContext ------------------------------------------------------------------

TsilParser::SizeofContext::SizeofContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::SizeofContext::KW_SIZEOF() {
  return getToken(TsilParser::KW_SIZEOF, 0);
}

TsilParser::TypeContext* TsilParser::SizeofContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}


size_t TsilParser::SizeofContext::getRuleIndex() const {
  return TsilParser::RuleSizeof;
}

void TsilParser::SizeofContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSizeof(this);
}

void TsilParser::SizeofContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSizeof(this);
}


std::any TsilParser::SizeofContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSizeof(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::SizeofContext* TsilParser::sizeof_() {
  SizeofContext *_localctx = _tracker.createInstance<SizeofContext>(_ctx, getState());
  enterRule(_localctx, 38, TsilParser::RuleSizeof);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    match(TsilParser::KW_SIZEOF);
    setState(243);
    antlrcpp::downCast<SizeofContext *>(_localctx)->s_type = type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

TsilParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TsilParser::AtomContext::getRuleIndex() const {
  return TsilParser::RuleAtom;
}

void TsilParser::AtomContext::copyFrom(AtomContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CallContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::CallContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

tree::TerminalNode* TsilParser::CallContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

TsilParser::AtomContext* TsilParser::CallContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

TsilParser::ArgsContext* TsilParser::CallContext::args() {
  return getRuleContext<TsilParser::ArgsContext>(0);
}

TsilParser::CallContext::CallContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}
void TsilParser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}

std::any TsilParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegativeContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::NegativeContext::MINUS() {
  return getToken(TsilParser::MINUS, 0);
}

TsilParser::AtomContext* TsilParser::NegativeContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

TsilParser::NegativeContext::NegativeContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::NegativeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegative(this);
}
void TsilParser::NegativeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegative(this);
}

std::any TsilParser::NegativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitNegative(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::NotContext::EXCLAMATION() {
  return getToken(TsilParser::EXCLAMATION, 0);
}

TsilParser::AtomContext* TsilParser::NotContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

TsilParser::NotContext::NotContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::NotContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNot(this);
}
void TsilParser::NotContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNot(this);
}

std::any TsilParser::NotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitNot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Bitwise_notContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Bitwise_notContext::TILDA() {
  return getToken(TsilParser::TILDA, 0);
}

TsilParser::AtomContext* TsilParser::Bitwise_notContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

TsilParser::Bitwise_notContext::Bitwise_notContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::Bitwise_notContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwise_not(this);
}
void TsilParser::Bitwise_notContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwise_not(this);
}

std::any TsilParser::Bitwise_notContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitBitwise_not(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GetContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::GetContext::DOT() {
  return getToken(TsilParser::DOT, 0);
}

TsilParser::AtomContext* TsilParser::GetContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

TsilParser::IdentifierContext* TsilParser::GetContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
}

TsilParser::GetContext::GetContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::GetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGet(this);
}
void TsilParser::GetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGet(this);
}

std::any TsilParser::GetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitGet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_identifierContext ------------------------------------------------------------------

TsilParser::IdentifierContext* TsilParser::Atom_identifierContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
}

TsilParser::Atom_identifierContext::Atom_identifierContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::Atom_identifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_identifier(this);
}
void TsilParser::Atom_identifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_identifier(this);
}

std::any TsilParser::Atom_identifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAtom_identifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PositiveContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::PositiveContext::PLUS() {
  return getToken(TsilParser::PLUS, 0);
}

TsilParser::AtomContext* TsilParser::PositiveContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

TsilParser::PositiveContext::PositiveContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::PositiveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPositive(this);
}
void TsilParser::PositiveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPositive(this);
}

std::any TsilParser::PositiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitPositive(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NestedContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::NestedContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

tree::TerminalNode* TsilParser::NestedContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

TsilParser::ExprContext* TsilParser::NestedContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

TsilParser::NestedContext::NestedContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::NestedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNested(this);
}
void TsilParser::NestedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNested(this);
}

std::any TsilParser::NestedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitNested(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::AtomContext* TsilParser::atom() {
   return atom(0);
}

TsilParser::AtomContext* TsilParser::atom(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TsilParser::AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, parentState);
  TsilParser::AtomContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, TsilParser::RuleAtom, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(259);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::ID: {
        _localctx = _tracker.createInstance<Atom_identifierContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(246);
        identifier();
        break;
      }

      case TsilParser::PLUS: {
        _localctx = _tracker.createInstance<PositiveContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(247);
        match(TsilParser::PLUS);
        setState(248);
        antlrcpp::downCast<PositiveContext *>(_localctx)->p_value = atom(5);
        break;
      }

      case TsilParser::MINUS: {
        _localctx = _tracker.createInstance<NegativeContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(249);
        match(TsilParser::MINUS);
        setState(250);
        antlrcpp::downCast<NegativeContext *>(_localctx)->n_value = atom(4);
        break;
      }

      case TsilParser::EXCLAMATION: {
        _localctx = _tracker.createInstance<NotContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(251);
        match(TsilParser::EXCLAMATION);
        setState(252);
        antlrcpp::downCast<NotContext *>(_localctx)->n_value = atom(3);
        break;
      }

      case TsilParser::TILDA: {
        _localctx = _tracker.createInstance<Bitwise_notContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(253);
        match(TsilParser::TILDA);
        setState(254);
        antlrcpp::downCast<Bitwise_notContext *>(_localctx)->bn_value = atom(2);
        break;
      }

      case TsilParser::PAREN_OPEN: {
        _localctx = _tracker.createInstance<NestedContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(255);
        match(TsilParser::PAREN_OPEN);
        setState(256);
        antlrcpp::downCast<NestedContext *>(_localctx)->n_value = expr(0);
        setState(257);
        match(TsilParser::PAREN_CLOSE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(272);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(270);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<GetContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->g_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(261);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(262);
          match(TsilParser::DOT);
          setState(263);
          antlrcpp::downCast<GetContext *>(_localctx)->g_id = identifier();
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<CallContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->c_value = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(264);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(265);
          match(TsilParser::PAREN_OPEN);
          setState(267);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 3867652001800) != 0)) {
            setState(266);
            antlrcpp::downCast<CallContext *>(_localctx)->c_args = args();
          }
          setState(269);
          match(TsilParser::PAREN_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(274);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MoleculeContext ------------------------------------------------------------------

TsilParser::MoleculeContext::MoleculeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TsilParser::MoleculeContext::getRuleIndex() const {
  return TsilParser::RuleMolecule;
}

void TsilParser::MoleculeContext::copyFrom(MoleculeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Atom_numberContext ------------------------------------------------------------------

TsilParser::NumberContext* TsilParser::Atom_numberContext::number() {
  return getRuleContext<TsilParser::NumberContext>(0);
}

TsilParser::Atom_numberContext::Atom_numberContext(MoleculeContext *ctx) { copyFrom(ctx); }

void TsilParser::Atom_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_number(this);
}
void TsilParser::Atom_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_number(this);
}

std::any TsilParser::Atom_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAtom_number(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Value_atomContext ------------------------------------------------------------------

TsilParser::AtomContext* TsilParser::Value_atomContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

TsilParser::Value_atomContext::Value_atomContext(MoleculeContext *ctx) { copyFrom(ctx); }

void TsilParser::Value_atomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue_atom(this);
}
void TsilParser::Value_atomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue_atom(this);
}

std::any TsilParser::Value_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitValue_atom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_stringContext ------------------------------------------------------------------

TsilParser::StringContext* TsilParser::Atom_stringContext::string() {
  return getRuleContext<TsilParser::StringContext>(0);
}

TsilParser::Atom_stringContext::Atom_stringContext(MoleculeContext *ctx) { copyFrom(ctx); }

void TsilParser::Atom_stringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_string(this);
}
void TsilParser::Atom_stringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_string(this);
}

std::any TsilParser::Atom_stringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAtom_string(this);
  else
    return visitor->visitChildren(this);
}
TsilParser::MoleculeContext* TsilParser::molecule() {
  MoleculeContext *_localctx = _tracker.createInstance<MoleculeContext>(_ctx, getState());
  enterRule(_localctx, 42, TsilParser::RuleMolecule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(278);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TsilParser::Value_atomContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(275);
      atom(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TsilParser::Atom_numberContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(276);
      number();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<TsilParser::Atom_stringContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(277);
      string();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

TsilParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TsilParser::ExprContext::getRuleIndex() const {
  return TsilParser::RuleExpr;
}

void TsilParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Arithmetic_mulContext ------------------------------------------------------------------

std::vector<TsilParser::ExprContext *> TsilParser::Arithmetic_mulContext::expr() {
  return getRuleContexts<TsilParser::ExprContext>();
}

TsilParser::ExprContext* TsilParser::Arithmetic_mulContext::expr(size_t i) {
  return getRuleContext<TsilParser::ExprContext>(i);
}

tree::TerminalNode* TsilParser::Arithmetic_mulContext::MULTIPLY() {
  return getToken(TsilParser::MULTIPLY, 0);
}

tree::TerminalNode* TsilParser::Arithmetic_mulContext::DIVIDE() {
  return getToken(TsilParser::DIVIDE, 0);
}

tree::TerminalNode* TsilParser::Arithmetic_mulContext::MOD() {
  return getToken(TsilParser::MOD, 0);
}

TsilParser::Arithmetic_mulContext::Arithmetic_mulContext(ExprContext *ctx) { copyFrom(ctx); }

void TsilParser::Arithmetic_mulContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic_mul(this);
}
void TsilParser::Arithmetic_mulContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic_mul(this);
}

std::any TsilParser::Arithmetic_mulContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitArithmetic_mul(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AsContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::AsContext::KW_AS() {
  return getToken(TsilParser::KW_AS, 0);
}

TsilParser::MoleculeContext* TsilParser::AsContext::molecule() {
  return getRuleContext<TsilParser::MoleculeContext>(0);
}

TsilParser::TypeContext* TsilParser::AsContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

TsilParser::AsContext::AsContext(ExprContext *ctx) { copyFrom(ctx); }

void TsilParser::AsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAs(this);
}
void TsilParser::AsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAs(this);
}

std::any TsilParser::AsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAs(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Arithmetic_addContext ------------------------------------------------------------------

std::vector<TsilParser::ExprContext *> TsilParser::Arithmetic_addContext::expr() {
  return getRuleContexts<TsilParser::ExprContext>();
}

TsilParser::ExprContext* TsilParser::Arithmetic_addContext::expr(size_t i) {
  return getRuleContext<TsilParser::ExprContext>(i);
}

tree::TerminalNode* TsilParser::Arithmetic_addContext::PLUS() {
  return getToken(TsilParser::PLUS, 0);
}

tree::TerminalNode* TsilParser::Arithmetic_addContext::MINUS() {
  return getToken(TsilParser::MINUS, 0);
}

TsilParser::Arithmetic_addContext::Arithmetic_addContext(ExprContext *ctx) { copyFrom(ctx); }

void TsilParser::Arithmetic_addContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic_add(this);
}
void TsilParser::Arithmetic_addContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic_add(this);
}

std::any TsilParser::Arithmetic_addContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitArithmetic_add(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ComparisonContext ------------------------------------------------------------------

std::vector<TsilParser::ExprContext *> TsilParser::ComparisonContext::expr() {
  return getRuleContexts<TsilParser::ExprContext>();
}

TsilParser::ExprContext* TsilParser::ComparisonContext::expr(size_t i) {
  return getRuleContext<TsilParser::ExprContext>(i);
}

TsilParser::Comparison_opContext* TsilParser::ComparisonContext::comparison_op() {
  return getRuleContext<TsilParser::Comparison_opContext>(0);
}

TsilParser::ComparisonContext::ComparisonContext(ExprContext *ctx) { copyFrom(ctx); }

void TsilParser::ComparisonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison(this);
}
void TsilParser::ComparisonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison(this);
}

std::any TsilParser::ComparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitComparison(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_constructorContext ------------------------------------------------------------------

TsilParser::ConstructorContext* TsilParser::Atom_constructorContext::constructor() {
  return getRuleContext<TsilParser::ConstructorContext>(0);
}

TsilParser::Atom_constructorContext::Atom_constructorContext(ExprContext *ctx) { copyFrom(ctx); }

void TsilParser::Atom_constructorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_constructor(this);
}
void TsilParser::Atom_constructorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_constructor(this);
}

std::any TsilParser::Atom_constructorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAtom_constructor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseContext ------------------------------------------------------------------

std::vector<TsilParser::ExprContext *> TsilParser::BitwiseContext::expr() {
  return getRuleContexts<TsilParser::ExprContext>();
}

TsilParser::ExprContext* TsilParser::BitwiseContext::expr(size_t i) {
  return getRuleContext<TsilParser::ExprContext>(i);
}

TsilParser::Bitwise_opContext* TsilParser::BitwiseContext::bitwise_op() {
  return getRuleContext<TsilParser::Bitwise_opContext>(0);
}

TsilParser::BitwiseContext::BitwiseContext(ExprContext *ctx) { copyFrom(ctx); }

void TsilParser::BitwiseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwise(this);
}
void TsilParser::BitwiseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwise(this);
}

std::any TsilParser::BitwiseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitBitwise(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_moleculeContext ------------------------------------------------------------------

TsilParser::MoleculeContext* TsilParser::Expr_moleculeContext::molecule() {
  return getRuleContext<TsilParser::MoleculeContext>(0);
}

TsilParser::Expr_moleculeContext::Expr_moleculeContext(ExprContext *ctx) { copyFrom(ctx); }

void TsilParser::Expr_moleculeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_molecule(this);
}
void TsilParser::Expr_moleculeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_molecule(this);
}

std::any TsilParser::Expr_moleculeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitExpr_molecule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalContext ------------------------------------------------------------------

std::vector<TsilParser::ExprContext *> TsilParser::LogicalContext::expr() {
  return getRuleContexts<TsilParser::ExprContext>();
}

TsilParser::ExprContext* TsilParser::LogicalContext::expr(size_t i) {
  return getRuleContext<TsilParser::ExprContext>(i);
}

TsilParser::Logical_opContext* TsilParser::LogicalContext::logical_op() {
  return getRuleContext<TsilParser::Logical_opContext>(0);
}

TsilParser::LogicalContext::LogicalContext(ExprContext *ctx) { copyFrom(ctx); }

void TsilParser::LogicalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical(this);
}
void TsilParser::LogicalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical(this);
}

std::any TsilParser::LogicalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitLogical(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_sizeofContext ------------------------------------------------------------------

TsilParser::SizeofContext* TsilParser::Atom_sizeofContext::sizeof_() {
  return getRuleContext<TsilParser::SizeofContext>(0);
}

TsilParser::Atom_sizeofContext::Atom_sizeofContext(ExprContext *ctx) { copyFrom(ctx); }

void TsilParser::Atom_sizeofContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_sizeof(this);
}
void TsilParser::Atom_sizeofContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_sizeof(this);
}

std::any TsilParser::Atom_sizeofContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAtom_sizeof(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::ExprContext* TsilParser::expr() {
   return expr(0);
}

TsilParser::ExprContext* TsilParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TsilParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  TsilParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, TsilParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(288);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Expr_moleculeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(281);
      molecule();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Atom_constructorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(282);
      constructor();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Atom_sizeofContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(283);
      sizeof_();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<AsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(284);
      antlrcpp::downCast<AsContext *>(_localctx)->a_left = molecule();
      setState(285);
      match(TsilParser::KW_AS);
      setState(286);
      antlrcpp::downCast<AsContext *>(_localctx)->a_type = type();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(310);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(308);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Arithmetic_mulContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->a_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(290);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(291);
          antlrcpp::downCast<Arithmetic_mulContext *>(_localctx)->a_operation = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 3670016) != 0))) {
            antlrcpp::downCast<Arithmetic_mulContext *>(_localctx)->a_operation = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(292);
          antlrcpp::downCast<Arithmetic_mulContext *>(_localctx)->a_right = expr(6);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Arithmetic_addContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->a_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(293);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(294);
          antlrcpp::downCast<Arithmetic_addContext *>(_localctx)->a_operation = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == TsilParser::PLUS

          || _la == TsilParser::MINUS)) {
            antlrcpp::downCast<Arithmetic_addContext *>(_localctx)->a_operation = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(295);
          antlrcpp::downCast<Arithmetic_addContext *>(_localctx)->a_right = expr(5);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BitwiseContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->b_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(296);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(297);
          antlrcpp::downCast<BitwiseContext *>(_localctx)->b_operation = bitwise_op();
          setState(298);
          antlrcpp::downCast<BitwiseContext *>(_localctx)->b_right = expr(4);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ComparisonContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->c_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(300);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(301);
          antlrcpp::downCast<ComparisonContext *>(_localctx)->c_operation = comparison_op();
          setState(302);
          antlrcpp::downCast<ComparisonContext *>(_localctx)->c_right = expr(3);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<LogicalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->t_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(304);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(305);
          antlrcpp::downCast<LogicalContext *>(_localctx)->t_operation = logical_op();
          setState(306);
          antlrcpp::downCast<LogicalContext *>(_localctx)->t_right = expr(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(312);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Identifiers_chainContext ------------------------------------------------------------------

TsilParser::Identifiers_chainContext::Identifiers_chainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Identifiers_chainContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::Identifiers_chainContext::DOT() {
  return getToken(TsilParser::DOT, 0);
}

TsilParser::Identifiers_chainContext* TsilParser::Identifiers_chainContext::identifiers_chain() {
  return getRuleContext<TsilParser::Identifiers_chainContext>(0);
}


size_t TsilParser::Identifiers_chainContext::getRuleIndex() const {
  return TsilParser::RuleIdentifiers_chain;
}

void TsilParser::Identifiers_chainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifiers_chain(this);
}

void TsilParser::Identifiers_chainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifiers_chain(this);
}


std::any TsilParser::Identifiers_chainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitIdentifiers_chain(this);
  else
    return visitor->visitChildren(this);
}


TsilParser::Identifiers_chainContext* TsilParser::identifiers_chain() {
   return identifiers_chain(0);
}

TsilParser::Identifiers_chainContext* TsilParser::identifiers_chain(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TsilParser::Identifiers_chainContext *_localctx = _tracker.createInstance<Identifiers_chainContext>(_ctx, parentState);
  TsilParser::Identifiers_chainContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, TsilParser::RuleIdentifiers_chain, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(314);
    antlrcpp::downCast<Identifiers_chainContext *>(_localctx)->ic_id = match(TsilParser::ID);
    _ctx->stop = _input->LT(-1);
    setState(321);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Identifiers_chainContext>(parentContext, parentState);
        _localctx->ic_left = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleIdentifiers_chain);
        setState(316);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(317);
        match(TsilParser::DOT);
        setState(318);
        antlrcpp::downCast<Identifiers_chainContext *>(_localctx)->ic_right = match(TsilParser::ID); 
      }
      setState(323);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

TsilParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TsilParser::IdentifierContext* TsilParser::TypeContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
}

tree::TerminalNode* TsilParser::TypeContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::TypeContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

std::vector<TsilParser::TypeContext *> TsilParser::TypeContext::type() {
  return getRuleContexts<TsilParser::TypeContext>();
}

TsilParser::TypeContext* TsilParser::TypeContext::type(size_t i) {
  return getRuleContext<TsilParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::TypeContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::TypeContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::TypeContext::getRuleIndex() const {
  return TsilParser::RuleType;
}

void TsilParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void TsilParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


std::any TsilParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::TypeContext* TsilParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 48, TsilParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    identifier();
    setState(336);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(325);
      match(TsilParser::LESSER);
      setState(326);
      antlrcpp::downCast<TypeContext *>(_localctx)->t_first_generic_type = type();
      setState(331);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(327);
        match(TsilParser::COMA);
        setState(328);
        type();
        setState(333);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(334);
      match(TsilParser::GREATER);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgsContext ------------------------------------------------------------------

TsilParser::ArgsContext::ArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TsilParser::ExprContext *> TsilParser::ArgsContext::expr() {
  return getRuleContexts<TsilParser::ExprContext>();
}

TsilParser::ExprContext* TsilParser::ArgsContext::expr(size_t i) {
  return getRuleContext<TsilParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::ArgsContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::ArgsContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::ArgsContext::getRuleIndex() const {
  return TsilParser::RuleArgs;
}

void TsilParser::ArgsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgs(this);
}

void TsilParser::ArgsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgs(this);
}


std::any TsilParser::ArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitArgs(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::ArgsContext* TsilParser::args() {
  ArgsContext *_localctx = _tracker.createInstance<ArgsContext>(_ctx, getState());
  enterRule(_localctx, 50, TsilParser::RuleArgs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(338);
    expr(0);
    setState(343);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(339);
        match(TsilParser::COMA);
        setState(340);
        expr(0); 
      }
      setState(345);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
    setState(347);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COMA) {
      setState(346);
      match(TsilParser::COMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsContext ------------------------------------------------------------------

TsilParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TsilParser::ParamContext *> TsilParser::ParamsContext::param() {
  return getRuleContexts<TsilParser::ParamContext>();
}

TsilParser::ParamContext* TsilParser::ParamsContext::param(size_t i) {
  return getRuleContext<TsilParser::ParamContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::ParamsContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::ParamsContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::ParamsContext::getRuleIndex() const {
  return TsilParser::RuleParams;
}

void TsilParser::ParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParams(this);
}

void TsilParser::ParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParams(this);
}


std::any TsilParser::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::ParamsContext* TsilParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 52, TsilParser::RuleParams);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(349);
    param();
    setState(354);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(350);
        match(TsilParser::COMA);
        setState(351);
        param(); 
      }
      setState(356);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
    setState(358);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(357);
      match(TsilParser::COMA);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

TsilParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::ParamContext::COLON() {
  return getToken(TsilParser::COLON, 0);
}

TsilParser::IdentifierContext* TsilParser::ParamContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
}

TsilParser::TypeContext* TsilParser::ParamContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}


size_t TsilParser::ParamContext::getRuleIndex() const {
  return TsilParser::RuleParam;
}

void TsilParser::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void TsilParser::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}


std::any TsilParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::ParamContext* TsilParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 54, TsilParser::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(360);
    antlrcpp::downCast<ParamContext *>(_localctx)->p_name = identifier();
    setState(361);
    match(TsilParser::COLON);
    setState(362);
    antlrcpp::downCast<ParamContext *>(_localctx)->p_type = type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BodyContext ------------------------------------------------------------------

TsilParser::BodyContext::BodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TsilParser::Body_element_or_returnContext *> TsilParser::BodyContext::body_element_or_return() {
  return getRuleContexts<TsilParser::Body_element_or_returnContext>();
}

TsilParser::Body_element_or_returnContext* TsilParser::BodyContext::body_element_or_return(size_t i) {
  return getRuleContext<TsilParser::Body_element_or_returnContext>(i);
}


size_t TsilParser::BodyContext::getRuleIndex() const {
  return TsilParser::RuleBody;
}

void TsilParser::BodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBody(this);
}

void TsilParser::BodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBody(this);
}


std::any TsilParser::BodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitBody(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::BodyContext* TsilParser::body() {
  BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
  enterRule(_localctx, 56, TsilParser::RuleBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(365); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(364);
      body_element_or_return();
      setState(367); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3936371478954) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Body_element_or_returnContext ------------------------------------------------------------------

TsilParser::Body_element_or_returnContext::Body_element_or_returnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TsilParser::Body_elementContext* TsilParser::Body_element_or_returnContext::body_element() {
  return getRuleContext<TsilParser::Body_elementContext>(0);
}

TsilParser::Return_body_elementContext* TsilParser::Body_element_or_returnContext::return_body_element() {
  return getRuleContext<TsilParser::Return_body_elementContext>(0);
}


size_t TsilParser::Body_element_or_returnContext::getRuleIndex() const {
  return TsilParser::RuleBody_element_or_return;
}

void TsilParser::Body_element_or_returnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBody_element_or_return(this);
}

void TsilParser::Body_element_or_returnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBody_element_or_return(this);
}


std::any TsilParser::Body_element_or_returnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitBody_element_or_return(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Body_element_or_returnContext* TsilParser::body_element_or_return() {
  Body_element_or_returnContext *_localctx = _tracker.createInstance<Body_element_or_returnContext>(_ctx, getState());
  enterRule(_localctx, 58, TsilParser::RuleBody_element_or_return);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(371);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_TSIL:
      case TsilParser::KW_SAVE:
      case TsilParser::KW_IF:
      case TsilParser::KW_WHILE:
      case TsilParser::KW_SIZEOF:
      case TsilParser::PLUS:
      case TsilParser::MINUS:
      case TsilParser::PAREN_OPEN:
      case TsilParser::TILDA:
      case TsilParser::EXCLAMATION:
      case TsilParser::SEMICOLON:
      case TsilParser::NUMBER:
      case TsilParser::ID:
      case TsilParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(369);
        body_element();
        break;
      }

      case TsilParser::KW_RETURN: {
        enterOuterAlt(_localctx, 2);
        setState(370);
        return_body_element();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Body_elementContext ------------------------------------------------------------------

TsilParser::Body_elementContext::Body_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TsilParser::IfContext* TsilParser::Body_elementContext::if_() {
  return getRuleContext<TsilParser::IfContext>(0);
}

TsilParser::WhileContext* TsilParser::Body_elementContext::while_() {
  return getRuleContext<TsilParser::WhileContext>(0);
}

TsilParser::DefineContext* TsilParser::Body_elementContext::define() {
  return getRuleContext<TsilParser::DefineContext>(0);
}

TsilParser::AssignContext* TsilParser::Body_elementContext::assign() {
  return getRuleContext<TsilParser::AssignContext>(0);
}

TsilParser::SetContext* TsilParser::Body_elementContext::set() {
  return getRuleContext<TsilParser::SetContext>(0);
}

TsilParser::ExprContext* TsilParser::Body_elementContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

tree::TerminalNode* TsilParser::Body_elementContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}


size_t TsilParser::Body_elementContext::getRuleIndex() const {
  return TsilParser::RuleBody_element;
}

void TsilParser::Body_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBody_element(this);
}

void TsilParser::Body_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBody_element(this);
}


std::any TsilParser::Body_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitBody_element(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Body_elementContext* TsilParser::body_element() {
  Body_elementContext *_localctx = _tracker.createInstance<Body_elementContext>(_ctx, getState());
  enterRule(_localctx, 60, TsilParser::RuleBody_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(382);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(373);
      if_();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(374);
      while_();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(375);
      define();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(376);
      assign();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(377);
      set();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(378);
      expr(0);
      setState(379);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(381);
      match(TsilParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_body_elementContext ------------------------------------------------------------------

TsilParser::Return_body_elementContext::Return_body_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Return_body_elementContext::KW_RETURN() {
  return getToken(TsilParser::KW_RETURN, 0);
}

TsilParser::ExprContext* TsilParser::Return_body_elementContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}


size_t TsilParser::Return_body_elementContext::getRuleIndex() const {
  return TsilParser::RuleReturn_body_element;
}

void TsilParser::Return_body_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_body_element(this);
}

void TsilParser::Return_body_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_body_element(this);
}


std::any TsilParser::Return_body_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitReturn_body_element(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Return_body_elementContext* TsilParser::return_body_element() {
  Return_body_elementContext *_localctx = _tracker.createInstance<Return_body_elementContext>(_ctx, getState());
  enterRule(_localctx, 62, TsilParser::RuleReturn_body_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(384);
    match(TsilParser::KW_RETURN);
    setState(385);
    antlrcpp::downCast<Return_body_elementContext *>(_localctx)->rbl_value = expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bitwise_opContext ------------------------------------------------------------------

TsilParser::Bitwise_opContext::Bitwise_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Bitwise_opContext::POWER() {
  return getToken(TsilParser::POWER, 0);
}

tree::TerminalNode* TsilParser::Bitwise_opContext::OR() {
  return getToken(TsilParser::OR, 0);
}

tree::TerminalNode* TsilParser::Bitwise_opContext::AND() {
  return getToken(TsilParser::AND, 0);
}

std::vector<tree::TerminalNode *> TsilParser::Bitwise_opContext::LESSER() {
  return getTokens(TsilParser::LESSER);
}

tree::TerminalNode* TsilParser::Bitwise_opContext::LESSER(size_t i) {
  return getToken(TsilParser::LESSER, i);
}

std::vector<tree::TerminalNode *> TsilParser::Bitwise_opContext::GREATER() {
  return getTokens(TsilParser::GREATER);
}

tree::TerminalNode* TsilParser::Bitwise_opContext::GREATER(size_t i) {
  return getToken(TsilParser::GREATER, i);
}


size_t TsilParser::Bitwise_opContext::getRuleIndex() const {
  return TsilParser::RuleBitwise_op;
}

void TsilParser::Bitwise_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwise_op(this);
}

void TsilParser::Bitwise_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwise_op(this);
}


std::any TsilParser::Bitwise_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitBitwise_op(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Bitwise_opContext* TsilParser::bitwise_op() {
  Bitwise_opContext *_localctx = _tracker.createInstance<Bitwise_opContext>(_ctx, getState());
  enterRule(_localctx, 64, TsilParser::RuleBitwise_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(394);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::POWER: {
        enterOuterAlt(_localctx, 1);
        setState(387);
        match(TsilParser::POWER);
        break;
      }

      case TsilParser::OR: {
        enterOuterAlt(_localctx, 2);
        setState(388);
        match(TsilParser::OR);
        break;
      }

      case TsilParser::AND: {
        enterOuterAlt(_localctx, 3);
        setState(389);
        match(TsilParser::AND);
        break;
      }

      case TsilParser::LESSER: {
        enterOuterAlt(_localctx, 4);
        setState(390);
        match(TsilParser::LESSER);
        setState(391);
        match(TsilParser::LESSER);
        break;
      }

      case TsilParser::GREATER: {
        enterOuterAlt(_localctx, 5);
        setState(392);
        match(TsilParser::GREATER);
        setState(393);
        match(TsilParser::GREATER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Comparison_opContext ------------------------------------------------------------------

TsilParser::Comparison_opContext::Comparison_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TsilParser::Comparison_opContext::EQUAL() {
  return getTokens(TsilParser::EQUAL);
}

tree::TerminalNode* TsilParser::Comparison_opContext::EQUAL(size_t i) {
  return getToken(TsilParser::EQUAL, i);
}

tree::TerminalNode* TsilParser::Comparison_opContext::EXCLAMATION() {
  return getToken(TsilParser::EXCLAMATION, 0);
}

tree::TerminalNode* TsilParser::Comparison_opContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

tree::TerminalNode* TsilParser::Comparison_opContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}


size_t TsilParser::Comparison_opContext::getRuleIndex() const {
  return TsilParser::RuleComparison_op;
}

void TsilParser::Comparison_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison_op(this);
}

void TsilParser::Comparison_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison_op(this);
}


std::any TsilParser::Comparison_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitComparison_op(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Comparison_opContext* TsilParser::comparison_op() {
  Comparison_opContext *_localctx = _tracker.createInstance<Comparison_opContext>(_ctx, getState());
  enterRule(_localctx, 66, TsilParser::RuleComparison_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(406);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(396);
      match(TsilParser::EQUAL);
      setState(397);
      match(TsilParser::EQUAL);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(398);
      match(TsilParser::EXCLAMATION);
      setState(399);
      match(TsilParser::EQUAL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(400);
      match(TsilParser::GREATER);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(401);
      match(TsilParser::LESSER);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(402);
      match(TsilParser::GREATER);
      setState(403);
      match(TsilParser::EQUAL);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(404);
      match(TsilParser::LESSER);
      setState(405);
      match(TsilParser::EQUAL);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logical_opContext ------------------------------------------------------------------

TsilParser::Logical_opContext::Logical_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TsilParser::Logical_opContext::OR() {
  return getTokens(TsilParser::OR);
}

tree::TerminalNode* TsilParser::Logical_opContext::OR(size_t i) {
  return getToken(TsilParser::OR, i);
}

std::vector<tree::TerminalNode *> TsilParser::Logical_opContext::AND() {
  return getTokens(TsilParser::AND);
}

tree::TerminalNode* TsilParser::Logical_opContext::AND(size_t i) {
  return getToken(TsilParser::AND, i);
}


size_t TsilParser::Logical_opContext::getRuleIndex() const {
  return TsilParser::RuleLogical_op;
}

void TsilParser::Logical_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical_op(this);
}

void TsilParser::Logical_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical_op(this);
}


std::any TsilParser::Logical_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitLogical_op(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Logical_opContext* TsilParser::logical_op() {
  Logical_opContext *_localctx = _tracker.createInstance<Logical_opContext>(_ctx, getState());
  enterRule(_localctx, 68, TsilParser::RuleLogical_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(412);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::OR: {
        enterOuterAlt(_localctx, 1);
        setState(408);
        match(TsilParser::OR);
        setState(409);
        match(TsilParser::OR);
        break;
      }

      case TsilParser::AND: {
        enterOuterAlt(_localctx, 2);
        setState(410);
        match(TsilParser::AND);
        setState(411);
        match(TsilParser::AND);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

TsilParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::NumberContext::NUMBER() {
  return getToken(TsilParser::NUMBER, 0);
}


size_t TsilParser::NumberContext::getRuleIndex() const {
  return TsilParser::RuleNumber;
}

void TsilParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void TsilParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}


std::any TsilParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::NumberContext* TsilParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 70, TsilParser::RuleNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(414);
    match(TsilParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

TsilParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::StringContext::STRING() {
  return getToken(TsilParser::STRING, 0);
}

tree::TerminalNode* TsilParser::StringContext::ID() {
  return getToken(TsilParser::ID, 0);
}


size_t TsilParser::StringContext::getRuleIndex() const {
  return TsilParser::RuleString;
}

void TsilParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void TsilParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}


std::any TsilParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::StringContext* TsilParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 72, TsilParser::RuleString);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(417);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(416);
      antlrcpp::downCast<StringContext *>(_localctx)->s_prefix = match(TsilParser::ID);
    }
    setState(419);
    match(TsilParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

TsilParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::IdentifierContext::ID() {
  return getToken(TsilParser::ID, 0);
}


size_t TsilParser::IdentifierContext::getRuleIndex() const {
  return TsilParser::RuleIdentifier;
}

void TsilParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}

void TsilParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}


std::any TsilParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::IdentifierContext* TsilParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 74, TsilParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(421);
    match(TsilParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool TsilParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 20: return atomSempred(antlrcpp::downCast<AtomContext *>(context), predicateIndex);
    case 22: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 23: return identifiers_chainSempred(antlrcpp::downCast<Identifiers_chainContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TsilParser::atomSempred(AtomContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

bool TsilParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 2);
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool TsilParser::identifiers_chainSempred(Identifiers_chainContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void TsilParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  tsilparserParserInitialize();
#else
  ::antlr4::internal::call_once(tsilparserParserOnceFlag, tsilparserParserInitialize);
#endif
}
