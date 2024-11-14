
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
      "file", "program", "atom", "call_arg", "operation", "op_lshift", "op_rshift", 
      "op_urshift", "op_lte", "op_gte", "op_eq", "op_neq", "op_land", "op_lor", 
      "gendef", "expr", "object_arg", "typeless_object", "structure_define", 
      "structure_element", "diia_define", "tsil_define", "assign", "synonym", 
      "synonym_fn", "section_define", "set", "position_set", "section_set", 
      "assign_op", "if", "while", "exec", "body", "body_element", "return", 
      "simple_type", "single_type", "type", "param", "preproc", "take", 
      "take_element"
    },
    std::vector<std::string>{
      "", "'\\u0446\\u0456\\u043B\\u044C'", "'\\u0434\\u0456\\u044F'", "'\\u044F\\u043A\\u0449\\u043E'", 
      "'\\u0456\\u043D\\u0430\\u043A\\u0448\\u0435'", "'\\u043F\\u043E\\u043A\\u0438'", 
      "'\\u0432\\u0435\\u0440\\u043D\\u0443\\u0442\\u0438'", "'\\u0432\\u0456\\u0434\\u043A\\u043B\\u0430\\u0441\\u0442\\u0438'", 
      "'\\u0441\\u0442\\u0440\\u0443\\u043A\\u0442\\u0443\\u0440\\u0430'", 
      "'\\u0432\\u0430\\u0440\\u0456\\u0430\\u0446\\u0456\\u044F'", "'\\u044F\\u043A'", 
      "'\\u0441\\u0435\\u043A\\u0446\\u0456\\u044F'", "'\\u0432\\u0437\\u044F\\u0442\\u0438'", 
      "'\\u0434\\u0430\\u0442\\u0438'", "'\\u043A\\u043E\\u043C\\u043F\\u043E\\u0437\\u0438\\u0446\\u0456\\u044F'", 
      "'\\u0432\\u043B\\u0430\\u0441\\u0442\\u0438\\u0432\\u0456\\u0441\\u0442\\u044C'", 
      "'\\u0437\\u043E\\u0432\\u043D\\u0456\\u0448\\u043D\\u044F'", "'\\u0432\\u043D\\u0443\\u0442\\u0440\\u0456\\u0448\\u043D\\u044F'", 
      "'\\u043C\\u0456\\u0441\\u0446\\u0435\\u0432\\u0430'", "'\\u043D\\u0435'", 
      "'\\u0430\\u0431\\u043E'", "'\\u0456'", "'\\u0437\\u043C\\u0456\\u043D\\u043D\\u0430'", 
      "'\\u0441\\u0442\\u0430\\u043B\\u0430'", "'\\u0441\\u0438\\u043D\\u043E\\u043D\\u0456\\u043C'", 
      "'\\u0432\\u0438\\u043A\\u043E\\u043D\\u0430\\u0442\\u0438'", "'\\u0441\\u043F\\u0440\\u043E\\u0431\\u0443\\u0432\\u0430\\u0442\\u0438'", 
      "'\\u0437\\u043B\\u043E\\u0432\\u0438\\u0442\\u0438'", "'\\u0432\\u043F\\u0430\\u0441\\u0442\\u0438'", 
      "'='", "'>'", "'<'", "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", 
      "'&'", "'|'", "'('", "')'", "'['", "']'", "'\\u003F'", "':'", "'~'", 
      "'''", "'\"'", "'!'", "','", "';'", "'{'", "'}'"
    },
    std::vector<std::string>{
      "", "KW_TSIL", "KW_DIIA", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_RETURN", 
      "KW_DEFER", "KW_STRUCT", "KW_VARIATION", "KW_AS", "KW_SECTION", "KW_IMPORT", 
      "KW_EXPORT", "KW_COMPOSITION", "KW_PROPERTY", "KW_PUBLIC", "KW_PRIVATE", 
      "KW_LOCAL", "KW_NOT", "KW_OR", "KW_AND", "KW_VAR", "KW_IMMUT", "KW_SYNONYM", 
      "KW_EXEC", "KW_TRY", "KW_CATCH", "KW_THROW", "EQUAL", "GREATER", "LESSER", 
      "DOT", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MOD", "POWER", "AND", 
      "OR", "PAREN_OPEN", "PAREN_CLOSE", "BRACKET_OPEN", "BRACKET_CLOSE", 
      "QUESTION", "COLON", "TILDA", "QUOTE", "DOUBLE_QUOTE", "EXCLAMATION", 
      "COMA", "SEMICOLON", "QUOTE_OPEN", "QUOTE_CLOSE", "NUMBER", "TYPED_INTEGER", 
      "INTEGER", "TYPED_FLOAT", "FLOAT", "HEX", "BIN", "ID", "STRING", "COMMENT", 
      "LINE_COMMENT", "WS", "NL"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,67,742,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,1,0,1,0,1,0,1,1,5,1,91,8,1,10,1,12,1,94,9,1,1,2,1,2,1,2,1,2,1,2,1,
  	2,3,2,102,8,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,113,8,2,10,2,12,
  	2,116,9,2,3,2,118,8,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,5,2,134,8,2,10,2,12,2,137,9,2,3,2,139,8,2,1,2,5,2,142,8,2,10,
  	2,12,2,145,9,2,1,3,1,3,3,3,149,8,3,1,4,1,4,1,4,3,4,154,8,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,166,8,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,
  	244,8,4,5,4,246,8,4,10,4,12,4,249,9,4,1,5,1,5,1,5,1,6,1,6,1,6,1,7,1,7,
  	1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,12,1,
  	12,1,12,1,13,1,13,1,13,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,5,15,287,
  	8,15,10,15,12,15,290,9,15,1,15,3,15,293,8,15,3,15,295,8,15,1,15,1,15,
  	3,15,299,8,15,1,16,1,16,3,16,303,8,16,1,16,1,16,3,16,307,8,16,1,16,1,
  	16,1,16,3,16,312,8,16,1,17,1,17,1,17,1,17,5,17,318,8,17,10,17,12,17,321,
  	9,17,1,17,3,17,324,8,17,3,17,326,8,17,1,17,1,17,1,18,1,18,1,18,1,18,1,
  	18,1,18,5,18,336,8,18,10,18,12,18,339,9,18,1,18,1,18,3,18,343,8,18,1,
  	18,1,18,1,18,5,18,348,8,18,10,18,12,18,351,9,18,1,18,3,18,354,8,18,1,
  	19,1,19,1,19,1,20,1,20,1,20,3,20,362,8,20,1,20,1,20,1,20,1,20,1,20,1,
  	20,5,20,370,8,20,10,20,12,20,373,9,20,1,20,1,20,3,20,377,8,20,1,20,1,
  	20,1,20,1,20,5,20,383,8,20,10,20,12,20,386,9,20,3,20,388,8,20,1,20,1,
  	20,1,20,3,20,393,8,20,1,20,1,20,3,20,397,8,20,1,21,1,21,1,21,3,21,402,
  	8,21,1,21,1,21,3,21,406,8,21,1,21,1,21,1,21,1,21,3,21,412,8,21,1,21,1,
  	21,1,21,3,21,417,8,21,3,21,419,8,21,1,21,1,21,1,22,1,22,1,22,1,22,3,22,
  	427,8,22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,5,23,437,8,23,10,23,
  	12,23,440,9,23,1,23,1,23,3,23,444,8,23,1,23,1,23,1,23,1,23,3,23,450,8,
  	23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,24,5,24,460,8,24,10,24,12,24,
  	463,9,24,1,24,1,24,3,24,467,8,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,3,
  	24,476,8,24,1,24,1,24,1,25,1,25,1,25,3,25,483,8,25,1,26,1,26,1,26,1,26,
  	1,26,1,26,3,26,491,8,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,
  	3,27,502,8,27,1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,28,1,28,3,28,513,8,
  	28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,3,
  	29,528,8,29,1,29,1,29,1,30,1,30,1,30,1,30,1,30,1,30,3,30,538,8,30,3,30,
  	540,8,30,1,31,1,31,1,31,1,31,1,32,1,32,1,32,1,32,1,33,1,33,5,33,552,8,
  	33,10,33,12,33,555,9,33,1,33,1,33,1,34,1,34,1,34,1,34,1,34,1,34,1,34,
  	1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,
  	3,34,580,8,34,1,35,1,35,1,35,3,35,585,8,35,1,35,1,35,1,36,1,36,1,36,1,
  	36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,5,36,601,8,36,10,36,12,36,
  	604,9,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,5,36,615,8,36,10,
  	36,12,36,618,9,36,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,
  	37,5,37,631,8,37,10,37,12,37,634,9,37,1,37,1,37,1,37,1,37,1,37,1,37,1,
  	37,1,37,1,37,5,37,645,8,37,10,37,12,37,648,9,37,1,37,1,37,1,37,1,37,1,
  	37,3,37,655,8,37,1,37,1,37,1,37,1,37,5,37,661,8,37,10,37,12,37,664,9,
  	37,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,4,38,674,8,38,11,38,12,38,
  	675,3,38,678,8,38,1,39,1,39,1,39,3,39,683,8,39,1,40,1,40,1,40,1,40,1,
  	40,1,40,5,40,691,8,40,10,40,12,40,694,9,40,1,40,1,40,1,40,1,40,1,40,5,
  	40,701,8,40,10,40,12,40,704,9,40,3,40,706,8,40,1,40,1,40,1,40,1,40,1,
  	40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,3,40,720,8,40,1,41,1,41,3,41,724,
  	8,41,1,41,1,41,3,41,728,8,41,1,41,1,41,1,41,5,41,733,8,41,10,41,12,41,
  	736,9,41,1,41,1,41,1,42,1,42,1,42,0,4,4,8,72,74,43,0,2,4,6,8,10,12,14,
  	16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,
  	62,64,66,68,70,72,74,76,78,80,82,84,0,1,1,0,62,63,839,0,86,1,0,0,0,2,
  	92,1,0,0,0,4,101,1,0,0,0,6,148,1,0,0,0,8,165,1,0,0,0,10,250,1,0,0,0,12,
  	253,1,0,0,0,14,256,1,0,0,0,16,260,1,0,0,0,18,263,1,0,0,0,20,266,1,0,0,
  	0,22,269,1,0,0,0,24,272,1,0,0,0,26,275,1,0,0,0,28,278,1,0,0,0,30,298,
  	1,0,0,0,32,311,1,0,0,0,34,313,1,0,0,0,36,329,1,0,0,0,38,355,1,0,0,0,40,
  	361,1,0,0,0,42,401,1,0,0,0,44,422,1,0,0,0,46,430,1,0,0,0,48,453,1,0,0,
  	0,50,479,1,0,0,0,52,484,1,0,0,0,54,494,1,0,0,0,56,505,1,0,0,0,58,527,
  	1,0,0,0,60,531,1,0,0,0,62,541,1,0,0,0,64,545,1,0,0,0,66,549,1,0,0,0,68,
  	579,1,0,0,0,70,581,1,0,0,0,72,588,1,0,0,0,74,654,1,0,0,0,76,677,1,0,0,
  	0,78,679,1,0,0,0,80,719,1,0,0,0,82,721,1,0,0,0,84,739,1,0,0,0,86,87,3,
  	2,1,0,87,88,5,0,0,1,88,1,1,0,0,0,89,91,3,68,34,0,90,89,1,0,0,0,91,94,
  	1,0,0,0,92,90,1,0,0,0,92,93,1,0,0,0,93,3,1,0,0,0,94,92,1,0,0,0,95,96,
  	6,2,-1,0,96,97,5,41,0,0,97,98,3,30,15,0,98,99,5,42,0,0,99,102,1,0,0,0,
  	100,102,5,62,0,0,101,95,1,0,0,0,101,100,1,0,0,0,102,143,1,0,0,0,103,104,
  	10,5,0,0,104,105,5,46,0,0,105,106,5,46,0,0,106,142,5,62,0,0,107,108,10,
  	4,0,0,108,117,5,31,0,0,109,114,3,76,38,0,110,111,5,51,0,0,111,113,3,76,
  	38,0,112,110,1,0,0,0,113,116,1,0,0,0,114,112,1,0,0,0,114,115,1,0,0,0,
  	115,118,1,0,0,0,116,114,1,0,0,0,117,109,1,0,0,0,117,118,1,0,0,0,118,119,
  	1,0,0,0,119,142,5,30,0,0,120,121,10,3,0,0,121,122,5,32,0,0,122,142,5,
  	62,0,0,123,124,10,2,0,0,124,125,5,43,0,0,125,126,3,30,15,0,126,127,5,
  	44,0,0,127,142,1,0,0,0,128,129,10,1,0,0,129,138,5,41,0,0,130,135,3,6,
  	3,0,131,132,5,51,0,0,132,134,3,6,3,0,133,131,1,0,0,0,134,137,1,0,0,0,
  	135,133,1,0,0,0,135,136,1,0,0,0,136,139,1,0,0,0,137,135,1,0,0,0,138,130,
  	1,0,0,0,138,139,1,0,0,0,139,140,1,0,0,0,140,142,5,42,0,0,141,103,1,0,
  	0,0,141,107,1,0,0,0,141,120,1,0,0,0,141,123,1,0,0,0,141,128,1,0,0,0,142,
  	145,1,0,0,0,143,141,1,0,0,0,143,144,1,0,0,0,144,5,1,0,0,0,145,143,1,0,
  	0,0,146,149,3,30,15,0,147,149,3,34,17,0,148,146,1,0,0,0,148,147,1,0,0,
  	0,149,7,1,0,0,0,150,151,6,4,-1,0,151,166,5,55,0,0,152,154,5,62,0,0,153,
  	152,1,0,0,0,153,154,1,0,0,0,154,155,1,0,0,0,155,166,5,63,0,0,156,166,
  	3,4,2,0,157,158,5,50,0,0,158,166,3,8,4,24,159,160,5,47,0,0,160,166,3,
  	8,4,23,161,162,5,33,0,0,162,166,3,8,4,22,163,164,5,34,0,0,164,166,3,8,
  	4,21,165,150,1,0,0,0,165,153,1,0,0,0,165,156,1,0,0,0,165,157,1,0,0,0,
  	165,159,1,0,0,0,165,161,1,0,0,0,165,163,1,0,0,0,166,247,1,0,0,0,167,168,
  	10,20,0,0,168,169,5,35,0,0,169,246,3,8,4,21,170,171,10,19,0,0,171,172,
  	5,36,0,0,172,246,3,8,4,20,173,174,10,18,0,0,174,175,5,37,0,0,175,246,
  	3,8,4,19,176,177,10,17,0,0,177,178,5,33,0,0,178,246,3,8,4,18,179,180,
  	10,16,0,0,180,181,5,34,0,0,181,246,3,8,4,17,182,183,10,15,0,0,183,184,
  	3,10,5,0,184,185,3,8,4,16,185,246,1,0,0,0,186,187,10,14,0,0,187,188,3,
  	12,6,0,188,189,3,8,4,15,189,246,1,0,0,0,190,191,10,13,0,0,191,192,3,14,
  	7,0,192,193,3,8,4,14,193,246,1,0,0,0,194,195,10,12,0,0,195,196,5,31,0,
  	0,196,246,3,8,4,13,197,198,10,11,0,0,198,199,3,16,8,0,199,200,3,8,4,12,
  	200,246,1,0,0,0,201,202,10,10,0,0,202,203,5,30,0,0,203,246,3,8,4,11,204,
  	205,10,9,0,0,205,206,3,18,9,0,206,207,3,8,4,10,207,246,1,0,0,0,208,209,
  	10,8,0,0,209,210,3,20,10,0,210,211,3,8,4,9,211,246,1,0,0,0,212,213,10,
  	7,0,0,213,214,3,22,11,0,214,215,3,8,4,8,215,246,1,0,0,0,216,217,10,6,
  	0,0,217,218,5,39,0,0,218,246,3,8,4,7,219,220,10,5,0,0,220,221,5,38,0,
  	0,221,246,3,8,4,6,222,223,10,4,0,0,223,224,5,40,0,0,224,246,3,8,4,5,225,
  	226,10,3,0,0,226,227,3,24,12,0,227,228,3,8,4,4,228,246,1,0,0,0,229,230,
  	10,2,0,0,230,231,3,26,13,0,231,232,3,8,4,3,232,246,1,0,0,0,233,234,10,
  	1,0,0,234,235,5,45,0,0,235,236,3,8,4,0,236,237,5,46,0,0,237,238,3,8,4,
  	2,238,246,1,0,0,0,239,240,10,25,0,0,240,243,5,10,0,0,241,244,3,76,38,
  	0,242,244,5,1,0,0,243,241,1,0,0,0,243,242,1,0,0,0,244,246,1,0,0,0,245,
  	167,1,0,0,0,245,170,1,0,0,0,245,173,1,0,0,0,245,176,1,0,0,0,245,179,1,
  	0,0,0,245,182,1,0,0,0,245,186,1,0,0,0,245,190,1,0,0,0,245,194,1,0,0,0,
  	245,197,1,0,0,0,245,201,1,0,0,0,245,204,1,0,0,0,245,208,1,0,0,0,245,212,
  	1,0,0,0,245,216,1,0,0,0,245,219,1,0,0,0,245,222,1,0,0,0,245,225,1,0,0,
  	0,245,229,1,0,0,0,245,233,1,0,0,0,245,239,1,0,0,0,246,249,1,0,0,0,247,
  	245,1,0,0,0,247,248,1,0,0,0,248,9,1,0,0,0,249,247,1,0,0,0,250,251,5,31,
  	0,0,251,252,5,31,0,0,252,11,1,0,0,0,253,254,5,30,0,0,254,255,5,30,0,0,
  	255,13,1,0,0,0,256,257,5,30,0,0,257,258,5,30,0,0,258,259,5,30,0,0,259,
  	15,1,0,0,0,260,261,5,31,0,0,261,262,5,29,0,0,262,17,1,0,0,0,263,264,5,
  	30,0,0,264,265,5,29,0,0,265,19,1,0,0,0,266,267,5,29,0,0,267,268,5,29,
  	0,0,268,21,1,0,0,0,269,270,5,50,0,0,270,271,5,29,0,0,271,23,1,0,0,0,272,
  	273,5,39,0,0,273,274,5,39,0,0,274,25,1,0,0,0,275,276,5,40,0,0,276,277,
  	5,40,0,0,277,27,1,0,0,0,278,279,5,62,0,0,279,29,1,0,0,0,280,299,3,8,4,
  	0,281,282,3,72,36,0,282,294,5,53,0,0,283,288,3,32,16,0,284,285,5,51,0,
  	0,285,287,3,32,16,0,286,284,1,0,0,0,287,290,1,0,0,0,288,286,1,0,0,0,288,
  	289,1,0,0,0,289,292,1,0,0,0,290,288,1,0,0,0,291,293,5,51,0,0,292,291,
  	1,0,0,0,292,293,1,0,0,0,293,295,1,0,0,0,294,283,1,0,0,0,294,295,1,0,0,
  	0,295,296,1,0,0,0,296,297,5,54,0,0,297,299,1,0,0,0,298,280,1,0,0,0,298,
  	281,1,0,0,0,299,31,1,0,0,0,300,301,5,62,0,0,301,303,5,29,0,0,302,300,
  	1,0,0,0,302,303,1,0,0,0,303,306,1,0,0,0,304,307,3,30,15,0,305,307,3,34,
  	17,0,306,304,1,0,0,0,306,305,1,0,0,0,307,312,1,0,0,0,308,309,5,32,0,0,
  	309,310,5,32,0,0,310,312,5,32,0,0,311,302,1,0,0,0,311,308,1,0,0,0,312,
  	33,1,0,0,0,313,325,5,53,0,0,314,319,3,32,16,0,315,316,5,51,0,0,316,318,
  	3,32,16,0,317,315,1,0,0,0,318,321,1,0,0,0,319,317,1,0,0,0,319,320,1,0,
  	0,0,320,323,1,0,0,0,321,319,1,0,0,0,322,324,5,51,0,0,323,322,1,0,0,0,
  	323,324,1,0,0,0,324,326,1,0,0,0,325,314,1,0,0,0,325,326,1,0,0,0,326,327,
  	1,0,0,0,327,328,5,54,0,0,328,35,1,0,0,0,329,330,5,8,0,0,330,342,5,62,
  	0,0,331,332,5,31,0,0,332,337,3,28,14,0,333,334,5,51,0,0,334,336,3,28,
  	14,0,335,333,1,0,0,0,336,339,1,0,0,0,337,335,1,0,0,0,337,338,1,0,0,0,
  	338,340,1,0,0,0,339,337,1,0,0,0,340,341,5,30,0,0,341,343,1,0,0,0,342,
  	331,1,0,0,0,342,343,1,0,0,0,343,353,1,0,0,0,344,354,5,52,0,0,345,349,
  	5,53,0,0,346,348,3,38,19,0,347,346,1,0,0,0,348,351,1,0,0,0,349,347,1,
  	0,0,0,349,350,1,0,0,0,350,352,1,0,0,0,351,349,1,0,0,0,352,354,5,54,0,
  	0,353,344,1,0,0,0,353,345,1,0,0,0,354,37,1,0,0,0,355,356,3,78,39,0,356,
  	357,5,52,0,0,357,39,1,0,0,0,358,362,5,16,0,0,359,362,5,18,0,0,360,362,
  	5,17,0,0,361,358,1,0,0,0,361,359,1,0,0,0,361,360,1,0,0,0,361,362,1,0,
  	0,0,362,363,1,0,0,0,363,364,5,2,0,0,364,376,5,62,0,0,365,366,5,31,0,0,
  	366,371,3,28,14,0,367,368,5,51,0,0,368,370,3,28,14,0,369,367,1,0,0,0,
  	370,373,1,0,0,0,371,369,1,0,0,0,371,372,1,0,0,0,372,374,1,0,0,0,373,371,
  	1,0,0,0,374,375,5,30,0,0,375,377,1,0,0,0,376,365,1,0,0,0,376,377,1,0,
  	0,0,377,378,1,0,0,0,378,387,5,41,0,0,379,384,3,78,39,0,380,381,5,51,0,
  	0,381,383,3,78,39,0,382,380,1,0,0,0,383,386,1,0,0,0,384,382,1,0,0,0,384,
  	385,1,0,0,0,385,388,1,0,0,0,386,384,1,0,0,0,387,379,1,0,0,0,387,388,1,
  	0,0,0,388,389,1,0,0,0,389,392,5,42,0,0,390,391,5,46,0,0,391,393,3,76,
  	38,0,392,390,1,0,0,0,392,393,1,0,0,0,393,396,1,0,0,0,394,397,5,52,0,0,
  	395,397,3,66,33,0,396,394,1,0,0,0,396,395,1,0,0,0,397,41,1,0,0,0,398,
  	402,5,16,0,0,399,402,5,18,0,0,400,402,5,17,0,0,401,398,1,0,0,0,401,399,
  	1,0,0,0,401,400,1,0,0,0,401,402,1,0,0,0,402,405,1,0,0,0,403,406,5,22,
  	0,0,404,406,5,23,0,0,405,403,1,0,0,0,405,404,1,0,0,0,405,406,1,0,0,0,
  	406,407,1,0,0,0,407,408,5,1,0,0,408,411,5,62,0,0,409,410,5,46,0,0,410,
  	412,3,76,38,0,411,409,1,0,0,0,411,412,1,0,0,0,412,418,1,0,0,0,413,416,
  	5,29,0,0,414,417,3,30,15,0,415,417,3,34,17,0,416,414,1,0,0,0,416,415,
  	1,0,0,0,417,419,1,0,0,0,418,413,1,0,0,0,418,419,1,0,0,0,419,420,1,0,0,
  	0,420,421,5,52,0,0,421,43,1,0,0,0,422,423,5,62,0,0,423,426,3,58,29,0,
  	424,427,3,30,15,0,425,427,3,34,17,0,426,424,1,0,0,0,426,425,1,0,0,0,427,
  	428,1,0,0,0,428,429,5,52,0,0,429,45,1,0,0,0,430,431,5,24,0,0,431,443,
  	5,62,0,0,432,433,5,31,0,0,433,438,3,28,14,0,434,435,5,51,0,0,435,437,
  	3,28,14,0,436,434,1,0,0,0,437,440,1,0,0,0,438,436,1,0,0,0,438,439,1,0,
  	0,0,439,441,1,0,0,0,440,438,1,0,0,0,441,442,5,30,0,0,442,444,1,0,0,0,
  	443,432,1,0,0,0,443,444,1,0,0,0,444,445,1,0,0,0,445,449,5,29,0,0,446,
  	450,3,30,15,0,447,450,3,34,17,0,448,450,3,76,38,0,449,446,1,0,0,0,449,
  	447,1,0,0,0,449,448,1,0,0,0,450,451,1,0,0,0,451,452,5,52,0,0,452,47,1,
  	0,0,0,453,454,5,24,0,0,454,466,5,62,0,0,455,456,5,31,0,0,456,461,3,28,
  	14,0,457,458,5,51,0,0,458,460,3,28,14,0,459,457,1,0,0,0,460,463,1,0,0,
  	0,461,459,1,0,0,0,461,462,1,0,0,0,462,464,1,0,0,0,463,461,1,0,0,0,464,
  	465,5,30,0,0,465,467,1,0,0,0,466,455,1,0,0,0,466,467,1,0,0,0,467,468,
  	1,0,0,0,468,469,5,41,0,0,469,470,5,42,0,0,470,471,5,29,0,0,471,475,5,
  	30,0,0,472,476,3,30,15,0,473,476,3,34,17,0,474,476,3,76,38,0,475,472,
  	1,0,0,0,475,473,1,0,0,0,475,474,1,0,0,0,476,477,1,0,0,0,477,478,5,52,
  	0,0,478,49,1,0,0,0,479,480,5,11,0,0,480,482,5,62,0,0,481,483,3,66,33,
  	0,482,481,1,0,0,0,482,483,1,0,0,0,483,51,1,0,0,0,484,485,3,4,2,0,485,
  	486,5,32,0,0,486,487,5,62,0,0,487,490,3,58,29,0,488,491,3,30,15,0,489,
  	491,3,34,17,0,490,488,1,0,0,0,490,489,1,0,0,0,491,492,1,0,0,0,492,493,
  	5,52,0,0,493,53,1,0,0,0,494,495,3,4,2,0,495,496,5,43,0,0,496,497,3,30,
  	15,0,497,498,5,44,0,0,498,501,3,58,29,0,499,502,3,30,15,0,500,502,3,34,
  	17,0,501,499,1,0,0,0,501,500,1,0,0,0,502,503,1,0,0,0,503,504,5,52,0,0,
  	504,55,1,0,0,0,505,506,3,4,2,0,506,507,5,46,0,0,507,508,5,46,0,0,508,
  	509,5,62,0,0,509,512,3,58,29,0,510,513,3,30,15,0,511,513,3,34,17,0,512,
  	510,1,0,0,0,512,511,1,0,0,0,513,514,1,0,0,0,514,515,5,52,0,0,515,57,1,
  	0,0,0,516,528,5,35,0,0,517,528,5,36,0,0,518,528,5,37,0,0,519,528,5,33,
  	0,0,520,528,5,34,0,0,521,528,3,10,5,0,522,528,3,12,6,0,523,528,3,14,7,
  	0,524,528,5,39,0,0,525,528,5,38,0,0,526,528,5,40,0,0,527,516,1,0,0,0,
  	527,517,1,0,0,0,527,518,1,0,0,0,527,519,1,0,0,0,527,520,1,0,0,0,527,521,
  	1,0,0,0,527,522,1,0,0,0,527,523,1,0,0,0,527,524,1,0,0,0,527,525,1,0,0,
  	0,527,526,1,0,0,0,527,528,1,0,0,0,528,529,1,0,0,0,529,530,5,29,0,0,530,
  	59,1,0,0,0,531,532,5,3,0,0,532,533,3,8,4,0,533,539,3,66,33,0,534,537,
  	5,4,0,0,535,538,3,66,33,0,536,538,3,60,30,0,537,535,1,0,0,0,537,536,1,
  	0,0,0,538,540,1,0,0,0,539,534,1,0,0,0,539,540,1,0,0,0,540,61,1,0,0,0,
  	541,542,5,5,0,0,542,543,3,8,4,0,543,544,3,66,33,0,544,63,1,0,0,0,545,
  	546,5,25,0,0,546,547,3,66,33,0,547,548,5,52,0,0,548,65,1,0,0,0,549,553,
  	5,53,0,0,550,552,3,68,34,0,551,550,1,0,0,0,552,555,1,0,0,0,553,551,1,
  	0,0,0,553,554,1,0,0,0,554,556,1,0,0,0,555,553,1,0,0,0,556,557,5,54,0,
  	0,557,67,1,0,0,0,558,580,3,36,18,0,559,580,3,40,20,0,560,580,3,42,21,
  	0,561,580,3,44,22,0,562,580,3,52,26,0,563,580,3,56,28,0,564,580,3,54,
  	27,0,565,580,3,46,23,0,566,580,3,48,24,0,567,580,3,50,25,0,568,580,3,
  	60,30,0,569,580,3,62,31,0,570,571,3,30,15,0,571,572,5,52,0,0,572,580,
  	1,0,0,0,573,580,3,66,33,0,574,580,3,64,32,0,575,580,3,70,35,0,576,580,
  	3,80,40,0,577,580,3,82,41,0,578,580,5,52,0,0,579,558,1,0,0,0,579,559,
  	1,0,0,0,579,560,1,0,0,0,579,561,1,0,0,0,579,562,1,0,0,0,579,563,1,0,0,
  	0,579,564,1,0,0,0,579,565,1,0,0,0,579,566,1,0,0,0,579,567,1,0,0,0,579,
  	568,1,0,0,0,579,569,1,0,0,0,579,570,1,0,0,0,579,573,1,0,0,0,579,574,1,
  	0,0,0,579,575,1,0,0,0,579,576,1,0,0,0,579,577,1,0,0,0,579,578,1,0,0,0,
  	580,69,1,0,0,0,581,584,5,6,0,0,582,585,3,30,15,0,583,585,3,34,17,0,584,
  	582,1,0,0,0,584,583,1,0,0,0,584,585,1,0,0,0,585,586,1,0,0,0,586,587,5,
  	52,0,0,587,71,1,0,0,0,588,589,6,36,-1,0,589,590,5,62,0,0,590,616,1,0,
  	0,0,591,592,10,4,0,0,592,593,5,46,0,0,593,594,5,46,0,0,594,615,5,62,0,
  	0,595,596,10,3,0,0,596,597,5,31,0,0,597,602,3,76,38,0,598,599,5,51,0,
  	0,599,601,3,76,38,0,600,598,1,0,0,0,601,604,1,0,0,0,602,600,1,0,0,0,602,
  	603,1,0,0,0,603,605,1,0,0,0,604,602,1,0,0,0,605,606,5,30,0,0,606,615,
  	1,0,0,0,607,608,10,2,0,0,608,609,5,32,0,0,609,615,5,62,0,0,610,611,10,
  	1,0,0,611,612,5,43,0,0,612,613,5,55,0,0,613,615,5,44,0,0,614,591,1,0,
  	0,0,614,595,1,0,0,0,614,607,1,0,0,0,614,610,1,0,0,0,615,618,1,0,0,0,616,
  	614,1,0,0,0,616,617,1,0,0,0,617,73,1,0,0,0,618,616,1,0,0,0,619,620,6,
  	37,-1,0,620,655,3,72,36,0,621,622,5,41,0,0,622,623,5,42,0,0,623,624,5,
  	34,0,0,624,625,5,30,0,0,625,655,3,76,38,0,626,627,5,41,0,0,627,632,3,
  	76,38,0,628,629,5,51,0,0,629,631,3,76,38,0,630,628,1,0,0,0,631,634,1,
  	0,0,0,632,630,1,0,0,0,632,633,1,0,0,0,633,635,1,0,0,0,634,632,1,0,0,0,
  	635,636,5,42,0,0,636,637,5,34,0,0,637,638,5,30,0,0,638,639,3,76,38,0,
  	639,655,1,0,0,0,640,641,5,41,0,0,641,646,3,78,39,0,642,643,5,51,0,0,643,
  	645,3,78,39,0,644,642,1,0,0,0,645,648,1,0,0,0,646,644,1,0,0,0,646,647,
  	1,0,0,0,647,649,1,0,0,0,648,646,1,0,0,0,649,650,5,42,0,0,650,651,5,34,
  	0,0,651,652,5,30,0,0,652,653,3,76,38,0,653,655,1,0,0,0,654,619,1,0,0,
  	0,654,621,1,0,0,0,654,626,1,0,0,0,654,640,1,0,0,0,655,662,1,0,0,0,656,
  	657,10,3,0,0,657,658,5,34,0,0,658,659,5,30,0,0,659,661,3,76,38,0,660,
  	656,1,0,0,0,661,664,1,0,0,0,662,660,1,0,0,0,662,663,1,0,0,0,663,75,1,
  	0,0,0,664,662,1,0,0,0,665,666,5,41,0,0,666,667,3,76,38,0,667,668,5,42,
  	0,0,668,678,1,0,0,0,669,678,3,74,37,0,670,673,3,74,37,0,671,672,5,40,
  	0,0,672,674,3,74,37,0,673,671,1,0,0,0,674,675,1,0,0,0,675,673,1,0,0,0,
  	675,676,1,0,0,0,676,678,1,0,0,0,677,665,1,0,0,0,677,669,1,0,0,0,677,670,
  	1,0,0,0,678,77,1,0,0,0,679,682,5,62,0,0,680,681,5,46,0,0,681,683,3,76,
  	38,0,682,680,1,0,0,0,682,683,1,0,0,0,683,79,1,0,0,0,684,685,5,37,0,0,
  	685,686,5,43,0,0,686,687,5,3,0,0,687,688,3,8,4,0,688,692,5,44,0,0,689,
  	691,3,68,34,0,690,689,1,0,0,0,691,694,1,0,0,0,692,690,1,0,0,0,692,693,
  	1,0,0,0,693,705,1,0,0,0,694,692,1,0,0,0,695,696,5,37,0,0,696,697,5,43,
  	0,0,697,698,5,4,0,0,698,702,5,44,0,0,699,701,3,68,34,0,700,699,1,0,0,
  	0,701,704,1,0,0,0,702,700,1,0,0,0,702,703,1,0,0,0,703,706,1,0,0,0,704,
  	702,1,0,0,0,705,695,1,0,0,0,705,706,1,0,0,0,706,707,1,0,0,0,707,708,5,
  	37,0,0,708,709,5,43,0,0,709,710,5,36,0,0,710,711,5,3,0,0,711,712,5,44,
  	0,0,712,720,1,0,0,0,713,714,5,37,0,0,714,715,5,43,0,0,715,716,5,28,0,
  	0,716,717,3,8,4,0,717,718,5,44,0,0,718,720,1,0,0,0,719,684,1,0,0,0,719,
  	713,1,0,0,0,720,81,1,0,0,0,721,723,5,12,0,0,722,724,5,62,0,0,723,722,
  	1,0,0,0,723,724,1,0,0,0,724,727,1,0,0,0,725,726,5,32,0,0,726,728,5,36,
  	0,0,727,725,1,0,0,0,727,728,1,0,0,0,728,729,1,0,0,0,729,734,3,84,42,0,
  	730,731,5,36,0,0,731,733,3,84,42,0,732,730,1,0,0,0,733,736,1,0,0,0,734,
  	732,1,0,0,0,734,735,1,0,0,0,735,737,1,0,0,0,736,734,1,0,0,0,737,738,5,
  	52,0,0,738,83,1,0,0,0,739,740,7,0,0,0,740,85,1,0,0,0,74,92,101,114,117,
  	135,138,141,143,148,153,165,243,245,247,288,292,294,298,302,306,311,319,
  	323,325,337,342,349,353,361,371,376,384,387,392,396,401,405,411,416,418,
  	426,438,443,449,461,466,475,482,490,501,512,527,537,539,553,579,584,602,
  	614,616,632,646,654,662,675,677,682,692,702,705,719,723,727,734
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
    setState(86);
    antlrcpp::downCast<FileContext *>(_localctx)->f_program = program();
    setState(87);
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

std::vector<TsilParser::Body_elementContext *> TsilParser::ProgramContext::body_element() {
  return getRuleContexts<TsilParser::Body_elementContext>();
}

TsilParser::Body_elementContext* TsilParser::ProgramContext::body_element(size_t i) {
  return getRuleContext<TsilParser::Body_elementContext>(i);
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
    setState(92);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -4560877422835721874) != 0)) {
      setState(89);
      body_element();
      setState(94);
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

//----------------- Atom_nestedContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Atom_nestedContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

TsilParser::ExprContext* TsilParser::Atom_nestedContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

tree::TerminalNode* TsilParser::Atom_nestedContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

TsilParser::Atom_nestedContext::Atom_nestedContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::Atom_nestedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_nested(this);
}
void TsilParser::Atom_nestedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_nested(this);
}

std::any TsilParser::Atom_nestedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAtom_nested(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_template_getContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Atom_template_getContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::Atom_template_getContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

TsilParser::AtomContext* TsilParser::Atom_template_getContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

std::vector<TsilParser::TypeContext *> TsilParser::Atom_template_getContext::type() {
  return getRuleContexts<TsilParser::TypeContext>();
}

TsilParser::TypeContext* TsilParser::Atom_template_getContext::type(size_t i) {
  return getRuleContext<TsilParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Atom_template_getContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Atom_template_getContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}

TsilParser::Atom_template_getContext::Atom_template_getContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::Atom_template_getContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_template_get(this);
}
void TsilParser::Atom_template_getContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_template_get(this);
}

std::any TsilParser::Atom_template_getContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAtom_template_get(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_getContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Atom_getContext::DOT() {
  return getToken(TsilParser::DOT, 0);
}

TsilParser::AtomContext* TsilParser::Atom_getContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

tree::TerminalNode* TsilParser::Atom_getContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::Atom_getContext::Atom_getContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::Atom_getContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_get(this);
}
void TsilParser::Atom_getContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_get(this);
}

std::any TsilParser::Atom_getContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAtom_get(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_section_getContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> TsilParser::Atom_section_getContext::COLON() {
  return getTokens(TsilParser::COLON);
}

tree::TerminalNode* TsilParser::Atom_section_getContext::COLON(size_t i) {
  return getToken(TsilParser::COLON, i);
}

TsilParser::AtomContext* TsilParser::Atom_section_getContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

tree::TerminalNode* TsilParser::Atom_section_getContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::Atom_section_getContext::Atom_section_getContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::Atom_section_getContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_section_get(this);
}
void TsilParser::Atom_section_getContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_section_get(this);
}

std::any TsilParser::Atom_section_getContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAtom_section_get(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_subjectContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Atom_subjectContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::Atom_subjectContext::Atom_subjectContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::Atom_subjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_subject(this);
}
void TsilParser::Atom_subjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_subject(this);
}

std::any TsilParser::Atom_subjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAtom_subject(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_position_getContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Atom_position_getContext::BRACKET_OPEN() {
  return getToken(TsilParser::BRACKET_OPEN, 0);
}

tree::TerminalNode* TsilParser::Atom_position_getContext::BRACKET_CLOSE() {
  return getToken(TsilParser::BRACKET_CLOSE, 0);
}

TsilParser::AtomContext* TsilParser::Atom_position_getContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

TsilParser::ExprContext* TsilParser::Atom_position_getContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

TsilParser::Atom_position_getContext::Atom_position_getContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::Atom_position_getContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_position_get(this);
}
void TsilParser::Atom_position_getContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_position_get(this);
}

std::any TsilParser::Atom_position_getContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAtom_position_get(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_callContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Atom_callContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

tree::TerminalNode* TsilParser::Atom_callContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

TsilParser::AtomContext* TsilParser::Atom_callContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

std::vector<TsilParser::Call_argContext *> TsilParser::Atom_callContext::call_arg() {
  return getRuleContexts<TsilParser::Call_argContext>();
}

TsilParser::Call_argContext* TsilParser::Atom_callContext::call_arg(size_t i) {
  return getRuleContext<TsilParser::Call_argContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Atom_callContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Atom_callContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}

TsilParser::Atom_callContext::Atom_callContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::Atom_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_call(this);
}
void TsilParser::Atom_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_call(this);
}

std::any TsilParser::Atom_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAtom_call(this);
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
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, TsilParser::RuleAtom, precedence);

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
    setState(101);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::PAREN_OPEN: {
        _localctx = _tracker.createInstance<Atom_nestedContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(96);
        match(TsilParser::PAREN_OPEN);
        setState(97);
        expr();
        setState(98);
        match(TsilParser::PAREN_CLOSE);
        break;
      }

      case TsilParser::ID: {
        _localctx = _tracker.createInstance<Atom_subjectContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(100);
        antlrcpp::downCast<Atom_subjectContext *>(_localctx)->id = match(TsilParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(143);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(141);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Atom_section_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(103);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(104);
          match(TsilParser::COLON);
          setState(105);
          match(TsilParser::COLON);
          setState(106);
          antlrcpp::downCast<Atom_section_getContext *>(_localctx)->id = match(TsilParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Atom_template_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(107);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(108);
          match(TsilParser::LESSER);
          setState(117);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == TsilParser::PAREN_OPEN

          || _la == TsilParser::ID) {
            setState(109);
            type();
            setState(114);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == TsilParser::COMA) {
              setState(110);
              match(TsilParser::COMA);
              setState(111);
              type();
              setState(116);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(119);
          match(TsilParser::GREATER);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Atom_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(120);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(121);
          match(TsilParser::DOT);
          setState(122);
          antlrcpp::downCast<Atom_getContext *>(_localctx)->id = match(TsilParser::ID);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Atom_position_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(123);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(124);
          match(TsilParser::BRACKET_OPEN);
          setState(125);
          antlrcpp::downCast<Atom_position_getContext *>(_localctx)->position = expr();
          setState(126);
          match(TsilParser::BRACKET_CLOSE);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Atom_callContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(128);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(129);
          match(TsilParser::PAREN_OPEN);
          setState(138);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & -4565381159965425664) != 0)) {
            setState(130);
            call_arg();
            setState(135);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == TsilParser::COMA) {
              setState(131);
              match(TsilParser::COMA);
              setState(132);
              call_arg();
              setState(137);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(140);
          match(TsilParser::PAREN_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(145);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Call_argContext ------------------------------------------------------------------

TsilParser::Call_argContext::Call_argContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TsilParser::ExprContext* TsilParser::Call_argContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

TsilParser::Typeless_objectContext* TsilParser::Call_argContext::typeless_object() {
  return getRuleContext<TsilParser::Typeless_objectContext>(0);
}


size_t TsilParser::Call_argContext::getRuleIndex() const {
  return TsilParser::RuleCall_arg;
}

void TsilParser::Call_argContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall_arg(this);
}

void TsilParser::Call_argContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall_arg(this);
}


std::any TsilParser::Call_argContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitCall_arg(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Call_argContext* TsilParser::call_arg() {
  Call_argContext *_localctx = _tracker.createInstance<Call_argContext>(_ctx, getState());
  enterRule(_localctx, 6, TsilParser::RuleCall_arg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(148);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::PLUS:
      case TsilParser::MINUS:
      case TsilParser::PAREN_OPEN:
      case TsilParser::TILDA:
      case TsilParser::EXCLAMATION:
      case TsilParser::NUMBER:
      case TsilParser::ID:
      case TsilParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(146);
        expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        enterOuterAlt(_localctx, 2);
        setState(147);
        typeless_object();
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

//----------------- OperationContext ------------------------------------------------------------------

TsilParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TsilParser::OperationContext::getRuleIndex() const {
  return TsilParser::RuleOperation;
}

void TsilParser::OperationContext::copyFrom(OperationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Operation_gteContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_gteContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_gteContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

TsilParser::Op_gteContext* TsilParser::Operation_gteContext::op_gte() {
  return getRuleContext<TsilParser::Op_gteContext>(0);
}

TsilParser::Operation_gteContext::Operation_gteContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_gteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_gte(this);
}
void TsilParser::Operation_gteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_gte(this);
}

std::any TsilParser::Operation_gteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_gte(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_neqContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_neqContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_neqContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

TsilParser::Op_neqContext* TsilParser::Operation_neqContext::op_neq() {
  return getRuleContext<TsilParser::Op_neqContext>(0);
}

TsilParser::Operation_neqContext::Operation_neqContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_neqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_neq(this);
}
void TsilParser::Operation_neqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_neq(this);
}

std::any TsilParser::Operation_neqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_neq(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_xorContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_xorContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_xorContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

tree::TerminalNode* TsilParser::Operation_xorContext::POWER() {
  return getToken(TsilParser::POWER, 0);
}

TsilParser::Operation_xorContext::Operation_xorContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_xorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_xor(this);
}
void TsilParser::Operation_xorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_xor(this);
}

std::any TsilParser::Operation_xorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_xor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_lteContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_lteContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_lteContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

TsilParser::Op_lteContext* TsilParser::Operation_lteContext::op_lte() {
  return getRuleContext<TsilParser::Op_lteContext>(0);
}

TsilParser::Operation_lteContext::Operation_lteContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_lteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_lte(this);
}
void TsilParser::Operation_lteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_lte(this);
}

std::any TsilParser::Operation_lteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_lte(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_pre_plusContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Operation_pre_plusContext::PLUS() {
  return getToken(TsilParser::PLUS, 0);
}

TsilParser::OperationContext* TsilParser::Operation_pre_plusContext::operation() {
  return getRuleContext<TsilParser::OperationContext>(0);
}

TsilParser::Operation_pre_plusContext::Operation_pre_plusContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_pre_plusContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_pre_plus(this);
}
void TsilParser::Operation_pre_plusContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_pre_plus(this);
}

std::any TsilParser::Operation_pre_plusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_pre_plus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_addContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_addContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_addContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

tree::TerminalNode* TsilParser::Operation_addContext::PLUS() {
  return getToken(TsilParser::PLUS, 0);
}

TsilParser::Operation_addContext::Operation_addContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_addContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_add(this);
}
void TsilParser::Operation_addContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_add(this);
}

std::any TsilParser::Operation_addContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_add(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_ltContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_ltContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_ltContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

tree::TerminalNode* TsilParser::Operation_ltContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

TsilParser::Operation_ltContext::Operation_ltContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_ltContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_lt(this);
}
void TsilParser::Operation_ltContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_lt(this);
}

std::any TsilParser::Operation_ltContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_lt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_pre_minusContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Operation_pre_minusContext::MINUS() {
  return getToken(TsilParser::MINUS, 0);
}

TsilParser::OperationContext* TsilParser::Operation_pre_minusContext::operation() {
  return getRuleContext<TsilParser::OperationContext>(0);
}

TsilParser::Operation_pre_minusContext::Operation_pre_minusContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_pre_minusContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_pre_minus(this);
}
void TsilParser::Operation_pre_minusContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_pre_minus(this);
}

std::any TsilParser::Operation_pre_minusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_pre_minus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_landContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_landContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_landContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

TsilParser::Op_landContext* TsilParser::Operation_landContext::op_land() {
  return getRuleContext<TsilParser::Op_landContext>(0);
}

TsilParser::Operation_landContext::Operation_landContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_landContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_land(this);
}
void TsilParser::Operation_landContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_land(this);
}

std::any TsilParser::Operation_landContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_land(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_orContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_orContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_orContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

tree::TerminalNode* TsilParser::Operation_orContext::OR() {
  return getToken(TsilParser::OR, 0);
}

TsilParser::Operation_orContext::Operation_orContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_orContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_or(this);
}
void TsilParser::Operation_orContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_or(this);
}

std::any TsilParser::Operation_orContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_or(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_pre_notContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Operation_pre_notContext::EXCLAMATION() {
  return getToken(TsilParser::EXCLAMATION, 0);
}

TsilParser::OperationContext* TsilParser::Operation_pre_notContext::operation() {
  return getRuleContext<TsilParser::OperationContext>(0);
}

TsilParser::Operation_pre_notContext::Operation_pre_notContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_pre_notContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_pre_not(this);
}
void TsilParser::Operation_pre_notContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_pre_not(this);
}

std::any TsilParser::Operation_pre_notContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_pre_not(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_asContext ------------------------------------------------------------------

TsilParser::OperationContext* TsilParser::Operation_asContext::operation() {
  return getRuleContext<TsilParser::OperationContext>(0);
}

tree::TerminalNode* TsilParser::Operation_asContext::KW_AS() {
  return getToken(TsilParser::KW_AS, 0);
}

TsilParser::TypeContext* TsilParser::Operation_asContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

tree::TerminalNode* TsilParser::Operation_asContext::KW_TSIL() {
  return getToken(TsilParser::KW_TSIL, 0);
}

TsilParser::Operation_asContext::Operation_asContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_asContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_as(this);
}
void TsilParser::Operation_asContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_as(this);
}

std::any TsilParser::Operation_asContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_as(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_atomContext ------------------------------------------------------------------

TsilParser::AtomContext* TsilParser::Operation_atomContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

TsilParser::Operation_atomContext::Operation_atomContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_atomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_atom(this);
}
void TsilParser::Operation_atomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_atom(this);
}

std::any TsilParser::Operation_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_atom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_subContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_subContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_subContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

tree::TerminalNode* TsilParser::Operation_subContext::MINUS() {
  return getToken(TsilParser::MINUS, 0);
}

TsilParser::Operation_subContext::Operation_subContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_subContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_sub(this);
}
void TsilParser::Operation_subContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_sub(this);
}

std::any TsilParser::Operation_subContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_sub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_modContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_modContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_modContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

tree::TerminalNode* TsilParser::Operation_modContext::MOD() {
  return getToken(TsilParser::MOD, 0);
}

TsilParser::Operation_modContext::Operation_modContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_modContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_mod(this);
}
void TsilParser::Operation_modContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_mod(this);
}

std::any TsilParser::Operation_modContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_mod(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_mulContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_mulContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_mulContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

tree::TerminalNode* TsilParser::Operation_mulContext::MULTIPLY() {
  return getToken(TsilParser::MULTIPLY, 0);
}

TsilParser::Operation_mulContext::Operation_mulContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_mulContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_mul(this);
}
void TsilParser::Operation_mulContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_mul(this);
}

std::any TsilParser::Operation_mulContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_mul(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_gtContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_gtContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_gtContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

tree::TerminalNode* TsilParser::Operation_gtContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

TsilParser::Operation_gtContext::Operation_gtContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_gtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_gt(this);
}
void TsilParser::Operation_gtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_gt(this);
}

std::any TsilParser::Operation_gtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_gt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_eqContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_eqContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_eqContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

TsilParser::Op_eqContext* TsilParser::Operation_eqContext::op_eq() {
  return getRuleContext<TsilParser::Op_eqContext>(0);
}

TsilParser::Operation_eqContext::Operation_eqContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_eqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_eq(this);
}
void TsilParser::Operation_eqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_eq(this);
}

std::any TsilParser::Operation_eqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_eq(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_stringContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Operation_stringContext::STRING() {
  return getToken(TsilParser::STRING, 0);
}

tree::TerminalNode* TsilParser::Operation_stringContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::Operation_stringContext::Operation_stringContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_stringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_string(this);
}
void TsilParser::Operation_stringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_string(this);
}

std::any TsilParser::Operation_stringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_string(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_pre_bw_notContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Operation_pre_bw_notContext::TILDA() {
  return getToken(TsilParser::TILDA, 0);
}

TsilParser::OperationContext* TsilParser::Operation_pre_bw_notContext::operation() {
  return getRuleContext<TsilParser::OperationContext>(0);
}

TsilParser::Operation_pre_bw_notContext::Operation_pre_bw_notContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_pre_bw_notContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_pre_bw_not(this);
}
void TsilParser::Operation_pre_bw_notContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_pre_bw_not(this);
}

std::any TsilParser::Operation_pre_bw_notContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_pre_bw_not(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_lorContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_lorContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_lorContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

TsilParser::Op_lorContext* TsilParser::Operation_lorContext::op_lor() {
  return getRuleContext<TsilParser::Op_lorContext>(0);
}

TsilParser::Operation_lorContext::Operation_lorContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_lorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_lor(this);
}
void TsilParser::Operation_lorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_lor(this);
}

std::any TsilParser::Operation_lorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_lor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_ternaryContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Operation_ternaryContext::QUESTION() {
  return getToken(TsilParser::QUESTION, 0);
}

tree::TerminalNode* TsilParser::Operation_ternaryContext::COLON() {
  return getToken(TsilParser::COLON, 0);
}

std::vector<TsilParser::OperationContext *> TsilParser::Operation_ternaryContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_ternaryContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

TsilParser::Operation_ternaryContext::Operation_ternaryContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_ternaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_ternary(this);
}
void TsilParser::Operation_ternaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_ternary(this);
}

std::any TsilParser::Operation_ternaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_ternary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_urshiftContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_urshiftContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_urshiftContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

TsilParser::Op_urshiftContext* TsilParser::Operation_urshiftContext::op_urshift() {
  return getRuleContext<TsilParser::Op_urshiftContext>(0);
}

TsilParser::Operation_urshiftContext::Operation_urshiftContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_urshiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_urshift(this);
}
void TsilParser::Operation_urshiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_urshift(this);
}

std::any TsilParser::Operation_urshiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_urshift(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_divContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_divContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_divContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

tree::TerminalNode* TsilParser::Operation_divContext::DIVIDE() {
  return getToken(TsilParser::DIVIDE, 0);
}

TsilParser::Operation_divContext::Operation_divContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_divContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_div(this);
}
void TsilParser::Operation_divContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_div(this);
}

std::any TsilParser::Operation_divContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_div(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_rshiftContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_rshiftContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_rshiftContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

TsilParser::Op_rshiftContext* TsilParser::Operation_rshiftContext::op_rshift() {
  return getRuleContext<TsilParser::Op_rshiftContext>(0);
}

TsilParser::Operation_rshiftContext::Operation_rshiftContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_rshiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_rshift(this);
}
void TsilParser::Operation_rshiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_rshift(this);
}

std::any TsilParser::Operation_rshiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_rshift(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_lshiftContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_lshiftContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_lshiftContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

TsilParser::Op_lshiftContext* TsilParser::Operation_lshiftContext::op_lshift() {
  return getRuleContext<TsilParser::Op_lshiftContext>(0);
}

TsilParser::Operation_lshiftContext::Operation_lshiftContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_lshiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_lshift(this);
}
void TsilParser::Operation_lshiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_lshift(this);
}

std::any TsilParser::Operation_lshiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_lshift(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_numberContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Operation_numberContext::NUMBER() {
  return getToken(TsilParser::NUMBER, 0);
}

TsilParser::Operation_numberContext::Operation_numberContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_number(this);
}
void TsilParser::Operation_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_number(this);
}

std::any TsilParser::Operation_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_number(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Operation_andContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::Operation_andContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_andContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

tree::TerminalNode* TsilParser::Operation_andContext::AND() {
  return getToken(TsilParser::AND, 0);
}

TsilParser::Operation_andContext::Operation_andContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_andContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_and(this);
}
void TsilParser::Operation_andContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_and(this);
}

std::any TsilParser::Operation_andContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_and(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::OperationContext* TsilParser::operation() {
   return operation(0);
}

TsilParser::OperationContext* TsilParser::operation(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TsilParser::OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, parentState);
  TsilParser::OperationContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, TsilParser::RuleOperation, precedence);

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
    setState(165);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Operation_numberContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(151);
      match(TsilParser::NUMBER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Operation_stringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(153);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TsilParser::ID) {
        setState(152);
        antlrcpp::downCast<Operation_stringContext *>(_localctx)->tt = match(TsilParser::ID);
      }
      setState(155);
      match(TsilParser::STRING);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Operation_atomContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(156);
      atom(0);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Operation_pre_notContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(157);
      antlrcpp::downCast<Operation_pre_notContext *>(_localctx)->op = match(TsilParser::EXCLAMATION);
      setState(158);
      antlrcpp::downCast<Operation_pre_notContext *>(_localctx)->right = operation(24);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Operation_pre_bw_notContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(159);
      antlrcpp::downCast<Operation_pre_bw_notContext *>(_localctx)->op = match(TsilParser::TILDA);
      setState(160);
      antlrcpp::downCast<Operation_pre_bw_notContext *>(_localctx)->right = operation(23);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<Operation_pre_plusContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(161);
      antlrcpp::downCast<Operation_pre_plusContext *>(_localctx)->op = match(TsilParser::PLUS);
      setState(162);
      antlrcpp::downCast<Operation_pre_plusContext *>(_localctx)->right = operation(22);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<Operation_pre_minusContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(163);
      antlrcpp::downCast<Operation_pre_minusContext *>(_localctx)->op = match(TsilParser::MINUS);
      setState(164);
      antlrcpp::downCast<Operation_pre_minusContext *>(_localctx)->right = operation(21);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(247);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(245);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Operation_mulContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(167);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(168);
          antlrcpp::downCast<Operation_mulContext *>(_localctx)->op = match(TsilParser::MULTIPLY);
          setState(169);
          antlrcpp::downCast<Operation_mulContext *>(_localctx)->right = operation(21);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Operation_divContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(170);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(171);
          antlrcpp::downCast<Operation_divContext *>(_localctx)->op = match(TsilParser::DIVIDE);
          setState(172);
          antlrcpp::downCast<Operation_divContext *>(_localctx)->right = operation(20);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Operation_modContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(173);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(174);
          antlrcpp::downCast<Operation_modContext *>(_localctx)->op = match(TsilParser::MOD);
          setState(175);
          antlrcpp::downCast<Operation_modContext *>(_localctx)->right = operation(19);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Operation_addContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(176);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(177);
          antlrcpp::downCast<Operation_addContext *>(_localctx)->op = match(TsilParser::PLUS);
          setState(178);
          antlrcpp::downCast<Operation_addContext *>(_localctx)->right = operation(18);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Operation_subContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(179);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(180);
          antlrcpp::downCast<Operation_subContext *>(_localctx)->op = match(TsilParser::MINUS);
          setState(181);
          antlrcpp::downCast<Operation_subContext *>(_localctx)->right = operation(17);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<Operation_lshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(182);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(183);
          antlrcpp::downCast<Operation_lshiftContext *>(_localctx)->op = op_lshift();
          setState(184);
          antlrcpp::downCast<Operation_lshiftContext *>(_localctx)->right = operation(16);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<Operation_rshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(186);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(187);
          antlrcpp::downCast<Operation_rshiftContext *>(_localctx)->op = op_rshift();
          setState(188);
          antlrcpp::downCast<Operation_rshiftContext *>(_localctx)->right = operation(15);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<Operation_urshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(190);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(191);
          antlrcpp::downCast<Operation_urshiftContext *>(_localctx)->op = op_urshift();
          setState(192);
          antlrcpp::downCast<Operation_urshiftContext *>(_localctx)->right = operation(14);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<Operation_ltContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(194);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(195);
          antlrcpp::downCast<Operation_ltContext *>(_localctx)->op = match(TsilParser::LESSER);
          setState(196);
          antlrcpp::downCast<Operation_ltContext *>(_localctx)->right = operation(13);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<Operation_lteContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(197);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(198);
          antlrcpp::downCast<Operation_lteContext *>(_localctx)->op = op_lte();
          setState(199);
          antlrcpp::downCast<Operation_lteContext *>(_localctx)->right = operation(12);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<Operation_gtContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(201);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(202);
          antlrcpp::downCast<Operation_gtContext *>(_localctx)->op = match(TsilParser::GREATER);
          setState(203);
          antlrcpp::downCast<Operation_gtContext *>(_localctx)->right = operation(11);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<Operation_gteContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(204);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(205);
          antlrcpp::downCast<Operation_gteContext *>(_localctx)->op = op_gte();
          setState(206);
          antlrcpp::downCast<Operation_gteContext *>(_localctx)->right = operation(10);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<Operation_eqContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(208);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(209);
          antlrcpp::downCast<Operation_eqContext *>(_localctx)->op = op_eq();
          setState(210);
          antlrcpp::downCast<Operation_eqContext *>(_localctx)->right = operation(9);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<Operation_neqContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(212);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(213);
          antlrcpp::downCast<Operation_neqContext *>(_localctx)->op = op_neq();
          setState(214);
          antlrcpp::downCast<Operation_neqContext *>(_localctx)->right = operation(8);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<Operation_andContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(216);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(217);
          antlrcpp::downCast<Operation_andContext *>(_localctx)->op = match(TsilParser::AND);
          setState(218);
          antlrcpp::downCast<Operation_andContext *>(_localctx)->right = operation(7);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<Operation_xorContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(219);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(220);
          antlrcpp::downCast<Operation_xorContext *>(_localctx)->op = match(TsilParser::POWER);
          setState(221);
          antlrcpp::downCast<Operation_xorContext *>(_localctx)->right = operation(6);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<Operation_orContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(222);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(223);
          antlrcpp::downCast<Operation_orContext *>(_localctx)->op = match(TsilParser::OR);
          setState(224);
          antlrcpp::downCast<Operation_orContext *>(_localctx)->right = operation(5);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<Operation_landContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(225);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(226);
          antlrcpp::downCast<Operation_landContext *>(_localctx)->op = op_land();
          setState(227);
          antlrcpp::downCast<Operation_landContext *>(_localctx)->right = operation(4);
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<Operation_lorContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(229);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(230);
          antlrcpp::downCast<Operation_lorContext *>(_localctx)->op = op_lor();
          setState(231);
          antlrcpp::downCast<Operation_lorContext *>(_localctx)->right = operation(3);
          break;
        }

        case 20: {
          auto newContext = _tracker.createInstance<Operation_ternaryContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->cond = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(233);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(234);
          match(TsilParser::QUESTION);
          setState(235);
          antlrcpp::downCast<Operation_ternaryContext *>(_localctx)->ifok = operation(0);
          setState(236);
          match(TsilParser::COLON);
          setState(237);
          antlrcpp::downCast<Operation_ternaryContext *>(_localctx)->ifnot = operation(2);
          break;
        }

        case 21: {
          auto newContext = _tracker.createInstance<Operation_asContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(239);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(240);
          antlrcpp::downCast<Operation_asContext *>(_localctx)->op = match(TsilParser::KW_AS);
          setState(243);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case TsilParser::PAREN_OPEN:
            case TsilParser::ID: {
              setState(241);
              antlrcpp::downCast<Operation_asContext *>(_localctx)->right_type = type();
              break;
            }

            case TsilParser::KW_TSIL: {
              setState(242);
              antlrcpp::downCast<Operation_asContext *>(_localctx)->right_tsil = match(TsilParser::KW_TSIL);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          break;
        }

        default:
          break;
        } 
      }
      setState(249);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Op_lshiftContext ------------------------------------------------------------------

TsilParser::Op_lshiftContext::Op_lshiftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TsilParser::Op_lshiftContext::LESSER() {
  return getTokens(TsilParser::LESSER);
}

tree::TerminalNode* TsilParser::Op_lshiftContext::LESSER(size_t i) {
  return getToken(TsilParser::LESSER, i);
}


size_t TsilParser::Op_lshiftContext::getRuleIndex() const {
  return TsilParser::RuleOp_lshift;
}

void TsilParser::Op_lshiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_lshift(this);
}

void TsilParser::Op_lshiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_lshift(this);
}


std::any TsilParser::Op_lshiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOp_lshift(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Op_lshiftContext* TsilParser::op_lshift() {
  Op_lshiftContext *_localctx = _tracker.createInstance<Op_lshiftContext>(_ctx, getState());
  enterRule(_localctx, 10, TsilParser::RuleOp_lshift);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    match(TsilParser::LESSER);
    setState(251);
    match(TsilParser::LESSER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_rshiftContext ------------------------------------------------------------------

TsilParser::Op_rshiftContext::Op_rshiftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TsilParser::Op_rshiftContext::GREATER() {
  return getTokens(TsilParser::GREATER);
}

tree::TerminalNode* TsilParser::Op_rshiftContext::GREATER(size_t i) {
  return getToken(TsilParser::GREATER, i);
}


size_t TsilParser::Op_rshiftContext::getRuleIndex() const {
  return TsilParser::RuleOp_rshift;
}

void TsilParser::Op_rshiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_rshift(this);
}

void TsilParser::Op_rshiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_rshift(this);
}


std::any TsilParser::Op_rshiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOp_rshift(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Op_rshiftContext* TsilParser::op_rshift() {
  Op_rshiftContext *_localctx = _tracker.createInstance<Op_rshiftContext>(_ctx, getState());
  enterRule(_localctx, 12, TsilParser::RuleOp_rshift);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(TsilParser::GREATER);
    setState(254);
    match(TsilParser::GREATER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_urshiftContext ------------------------------------------------------------------

TsilParser::Op_urshiftContext::Op_urshiftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TsilParser::Op_urshiftContext::GREATER() {
  return getTokens(TsilParser::GREATER);
}

tree::TerminalNode* TsilParser::Op_urshiftContext::GREATER(size_t i) {
  return getToken(TsilParser::GREATER, i);
}


size_t TsilParser::Op_urshiftContext::getRuleIndex() const {
  return TsilParser::RuleOp_urshift;
}

void TsilParser::Op_urshiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_urshift(this);
}

void TsilParser::Op_urshiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_urshift(this);
}


std::any TsilParser::Op_urshiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOp_urshift(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Op_urshiftContext* TsilParser::op_urshift() {
  Op_urshiftContext *_localctx = _tracker.createInstance<Op_urshiftContext>(_ctx, getState());
  enterRule(_localctx, 14, TsilParser::RuleOp_urshift);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(256);
    match(TsilParser::GREATER);
    setState(257);
    match(TsilParser::GREATER);
    setState(258);
    match(TsilParser::GREATER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_lteContext ------------------------------------------------------------------

TsilParser::Op_lteContext::Op_lteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Op_lteContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::Op_lteContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}


size_t TsilParser::Op_lteContext::getRuleIndex() const {
  return TsilParser::RuleOp_lte;
}

void TsilParser::Op_lteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_lte(this);
}

void TsilParser::Op_lteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_lte(this);
}


std::any TsilParser::Op_lteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOp_lte(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Op_lteContext* TsilParser::op_lte() {
  Op_lteContext *_localctx = _tracker.createInstance<Op_lteContext>(_ctx, getState());
  enterRule(_localctx, 16, TsilParser::RuleOp_lte);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    match(TsilParser::LESSER);
    setState(261);
    match(TsilParser::EQUAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_gteContext ------------------------------------------------------------------

TsilParser::Op_gteContext::Op_gteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Op_gteContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

tree::TerminalNode* TsilParser::Op_gteContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}


size_t TsilParser::Op_gteContext::getRuleIndex() const {
  return TsilParser::RuleOp_gte;
}

void TsilParser::Op_gteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_gte(this);
}

void TsilParser::Op_gteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_gte(this);
}


std::any TsilParser::Op_gteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOp_gte(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Op_gteContext* TsilParser::op_gte() {
  Op_gteContext *_localctx = _tracker.createInstance<Op_gteContext>(_ctx, getState());
  enterRule(_localctx, 18, TsilParser::RuleOp_gte);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    match(TsilParser::GREATER);
    setState(264);
    match(TsilParser::EQUAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_eqContext ------------------------------------------------------------------

TsilParser::Op_eqContext::Op_eqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TsilParser::Op_eqContext::EQUAL() {
  return getTokens(TsilParser::EQUAL);
}

tree::TerminalNode* TsilParser::Op_eqContext::EQUAL(size_t i) {
  return getToken(TsilParser::EQUAL, i);
}


size_t TsilParser::Op_eqContext::getRuleIndex() const {
  return TsilParser::RuleOp_eq;
}

void TsilParser::Op_eqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_eq(this);
}

void TsilParser::Op_eqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_eq(this);
}


std::any TsilParser::Op_eqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOp_eq(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Op_eqContext* TsilParser::op_eq() {
  Op_eqContext *_localctx = _tracker.createInstance<Op_eqContext>(_ctx, getState());
  enterRule(_localctx, 20, TsilParser::RuleOp_eq);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(266);
    match(TsilParser::EQUAL);
    setState(267);
    match(TsilParser::EQUAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_neqContext ------------------------------------------------------------------

TsilParser::Op_neqContext::Op_neqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Op_neqContext::EXCLAMATION() {
  return getToken(TsilParser::EXCLAMATION, 0);
}

tree::TerminalNode* TsilParser::Op_neqContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}


size_t TsilParser::Op_neqContext::getRuleIndex() const {
  return TsilParser::RuleOp_neq;
}

void TsilParser::Op_neqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_neq(this);
}

void TsilParser::Op_neqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_neq(this);
}


std::any TsilParser::Op_neqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOp_neq(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Op_neqContext* TsilParser::op_neq() {
  Op_neqContext *_localctx = _tracker.createInstance<Op_neqContext>(_ctx, getState());
  enterRule(_localctx, 22, TsilParser::RuleOp_neq);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    match(TsilParser::EXCLAMATION);
    setState(270);
    match(TsilParser::EQUAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_landContext ------------------------------------------------------------------

TsilParser::Op_landContext::Op_landContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TsilParser::Op_landContext::AND() {
  return getTokens(TsilParser::AND);
}

tree::TerminalNode* TsilParser::Op_landContext::AND(size_t i) {
  return getToken(TsilParser::AND, i);
}


size_t TsilParser::Op_landContext::getRuleIndex() const {
  return TsilParser::RuleOp_land;
}

void TsilParser::Op_landContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_land(this);
}

void TsilParser::Op_landContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_land(this);
}


std::any TsilParser::Op_landContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOp_land(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Op_landContext* TsilParser::op_land() {
  Op_landContext *_localctx = _tracker.createInstance<Op_landContext>(_ctx, getState());
  enterRule(_localctx, 24, TsilParser::RuleOp_land);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(272);
    match(TsilParser::AND);
    setState(273);
    match(TsilParser::AND);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op_lorContext ------------------------------------------------------------------

TsilParser::Op_lorContext::Op_lorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TsilParser::Op_lorContext::OR() {
  return getTokens(TsilParser::OR);
}

tree::TerminalNode* TsilParser::Op_lorContext::OR(size_t i) {
  return getToken(TsilParser::OR, i);
}


size_t TsilParser::Op_lorContext::getRuleIndex() const {
  return TsilParser::RuleOp_lor;
}

void TsilParser::Op_lorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_lor(this);
}

void TsilParser::Op_lorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_lor(this);
}


std::any TsilParser::Op_lorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOp_lor(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Op_lorContext* TsilParser::op_lor() {
  Op_lorContext *_localctx = _tracker.createInstance<Op_lorContext>(_ctx, getState());
  enterRule(_localctx, 26, TsilParser::RuleOp_lor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
    match(TsilParser::OR);
    setState(276);
    match(TsilParser::OR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GendefContext ------------------------------------------------------------------

TsilParser::GendefContext::GendefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::GendefContext::ID() {
  return getToken(TsilParser::ID, 0);
}


size_t TsilParser::GendefContext::getRuleIndex() const {
  return TsilParser::RuleGendef;
}

void TsilParser::GendefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGendef(this);
}

void TsilParser::GendefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGendef(this);
}


std::any TsilParser::GendefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitGendef(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::GendefContext* TsilParser::gendef() {
  GendefContext *_localctx = _tracker.createInstance<GendefContext>(_ctx, getState());
  enterRule(_localctx, 28, TsilParser::RuleGendef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    match(TsilParser::ID);
   
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

//----------------- Expr_objectContext ------------------------------------------------------------------

TsilParser::Simple_typeContext* TsilParser::Expr_objectContext::simple_type() {
  return getRuleContext<TsilParser::Simple_typeContext>(0);
}

tree::TerminalNode* TsilParser::Expr_objectContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::Expr_objectContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}

std::vector<TsilParser::Object_argContext *> TsilParser::Expr_objectContext::object_arg() {
  return getRuleContexts<TsilParser::Object_argContext>();
}

TsilParser::Object_argContext* TsilParser::Expr_objectContext::object_arg(size_t i) {
  return getRuleContext<TsilParser::Object_argContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Expr_objectContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Expr_objectContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}

TsilParser::Expr_objectContext::Expr_objectContext(ExprContext *ctx) { copyFrom(ctx); }

void TsilParser::Expr_objectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_object(this);
}
void TsilParser::Expr_objectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_object(this);
}

std::any TsilParser::Expr_objectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitExpr_object(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_operationContext ------------------------------------------------------------------

TsilParser::OperationContext* TsilParser::Expr_operationContext::operation() {
  return getRuleContext<TsilParser::OperationContext>(0);
}

TsilParser::Expr_operationContext::Expr_operationContext(ExprContext *ctx) { copyFrom(ctx); }

void TsilParser::Expr_operationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_operation(this);
}
void TsilParser::Expr_operationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_operation(this);
}

std::any TsilParser::Expr_operationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitExpr_operation(this);
  else
    return visitor->visitChildren(this);
}
TsilParser::ExprContext* TsilParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 30, TsilParser::RuleExpr);
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
    setState(298);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TsilParser::Expr_operationContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(280);
      operation(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TsilParser::Expr_objectContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(281);
      simple_type(0);
      setState(282);
      match(TsilParser::QUOTE_OPEN);
      setState(294);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & -4565381155670458368) != 0)) {
        setState(283);
        object_arg();
        setState(288);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(284);
            match(TsilParser::COMA);
            setState(285);
            object_arg(); 
          }
          setState(290);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
        }
        setState(292);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TsilParser::COMA) {
          setState(291);
          match(TsilParser::COMA);
        }
      }
      setState(296);
      match(TsilParser::QUOTE_CLOSE);
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

//----------------- Object_argContext ------------------------------------------------------------------

TsilParser::Object_argContext::Object_argContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Object_argContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}

TsilParser::ExprContext* TsilParser::Object_argContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

TsilParser::Typeless_objectContext* TsilParser::Object_argContext::typeless_object() {
  return getRuleContext<TsilParser::Typeless_objectContext>(0);
}

tree::TerminalNode* TsilParser::Object_argContext::ID() {
  return getToken(TsilParser::ID, 0);
}

std::vector<tree::TerminalNode *> TsilParser::Object_argContext::DOT() {
  return getTokens(TsilParser::DOT);
}

tree::TerminalNode* TsilParser::Object_argContext::DOT(size_t i) {
  return getToken(TsilParser::DOT, i);
}


size_t TsilParser::Object_argContext::getRuleIndex() const {
  return TsilParser::RuleObject_arg;
}

void TsilParser::Object_argContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObject_arg(this);
}

void TsilParser::Object_argContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObject_arg(this);
}


std::any TsilParser::Object_argContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitObject_arg(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Object_argContext* TsilParser::object_arg() {
  Object_argContext *_localctx = _tracker.createInstance<Object_argContext>(_ctx, getState());
  enterRule(_localctx, 32, TsilParser::RuleObject_arg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(311);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::PLUS:
      case TsilParser::MINUS:
      case TsilParser::PAREN_OPEN:
      case TsilParser::TILDA:
      case TsilParser::EXCLAMATION:
      case TsilParser::QUOTE_OPEN:
      case TsilParser::NUMBER:
      case TsilParser::ID:
      case TsilParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(302);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          setState(300);
          antlrcpp::downCast<Object_argContext *>(_localctx)->id = match(TsilParser::ID);
          setState(301);
          match(TsilParser::EQUAL);
          break;
        }

        default:
          break;
        }
        setState(306);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TsilParser::PLUS:
          case TsilParser::MINUS:
          case TsilParser::PAREN_OPEN:
          case TsilParser::TILDA:
          case TsilParser::EXCLAMATION:
          case TsilParser::NUMBER:
          case TsilParser::ID:
          case TsilParser::STRING: {
            setState(304);
            antlrcpp::downCast<Object_argContext *>(_localctx)->value_expr = expr();
            break;
          }

          case TsilParser::QUOTE_OPEN: {
            setState(305);
            antlrcpp::downCast<Object_argContext *>(_localctx)->value_object = typeless_object();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case TsilParser::DOT: {
        enterOuterAlt(_localctx, 2);
        setState(308);
        antlrcpp::downCast<Object_argContext *>(_localctx)->autofill = match(TsilParser::DOT);
        setState(309);
        match(TsilParser::DOT);
        setState(310);
        match(TsilParser::DOT);
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

//----------------- Typeless_objectContext ------------------------------------------------------------------

TsilParser::Typeless_objectContext::Typeless_objectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Typeless_objectContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::Typeless_objectContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}

std::vector<TsilParser::Object_argContext *> TsilParser::Typeless_objectContext::object_arg() {
  return getRuleContexts<TsilParser::Object_argContext>();
}

TsilParser::Object_argContext* TsilParser::Typeless_objectContext::object_arg(size_t i) {
  return getRuleContext<TsilParser::Object_argContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Typeless_objectContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Typeless_objectContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::Typeless_objectContext::getRuleIndex() const {
  return TsilParser::RuleTypeless_object;
}

void TsilParser::Typeless_objectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeless_object(this);
}

void TsilParser::Typeless_objectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeless_object(this);
}


std::any TsilParser::Typeless_objectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitTypeless_object(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Typeless_objectContext* TsilParser::typeless_object() {
  Typeless_objectContext *_localctx = _tracker.createInstance<Typeless_objectContext>(_ctx, getState());
  enterRule(_localctx, 34, TsilParser::RuleTypeless_object);
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
    setState(313);
    match(TsilParser::QUOTE_OPEN);
    setState(325);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -4565381155670458368) != 0)) {
      setState(314);
      object_arg();
      setState(319);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(315);
          match(TsilParser::COMA);
          setState(316);
          object_arg(); 
        }
        setState(321);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
      }
      setState(323);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TsilParser::COMA) {
        setState(322);
        match(TsilParser::COMA);
      }
    }
    setState(327);
    match(TsilParser::QUOTE_CLOSE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Structure_defineContext ------------------------------------------------------------------

TsilParser::Structure_defineContext::Structure_defineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Structure_defineContext::KW_STRUCT() {
  return getToken(TsilParser::KW_STRUCT, 0);
}

tree::TerminalNode* TsilParser::Structure_defineContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::Structure_defineContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

tree::TerminalNode* TsilParser::Structure_defineContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::Structure_defineContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

std::vector<TsilParser::GendefContext *> TsilParser::Structure_defineContext::gendef() {
  return getRuleContexts<TsilParser::GendefContext>();
}

TsilParser::GendefContext* TsilParser::Structure_defineContext::gendef(size_t i) {
  return getRuleContext<TsilParser::GendefContext>(i);
}

tree::TerminalNode* TsilParser::Structure_defineContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::Structure_defineContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}

std::vector<tree::TerminalNode *> TsilParser::Structure_defineContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Structure_defineContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}

std::vector<TsilParser::Structure_elementContext *> TsilParser::Structure_defineContext::structure_element() {
  return getRuleContexts<TsilParser::Structure_elementContext>();
}

TsilParser::Structure_elementContext* TsilParser::Structure_defineContext::structure_element(size_t i) {
  return getRuleContext<TsilParser::Structure_elementContext>(i);
}


size_t TsilParser::Structure_defineContext::getRuleIndex() const {
  return TsilParser::RuleStructure_define;
}

void TsilParser::Structure_defineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructure_define(this);
}

void TsilParser::Structure_defineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructure_define(this);
}


std::any TsilParser::Structure_defineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitStructure_define(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Structure_defineContext* TsilParser::structure_define() {
  Structure_defineContext *_localctx = _tracker.createInstance<Structure_defineContext>(_ctx, getState());
  enterRule(_localctx, 36, TsilParser::RuleStructure_define);
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
    setState(329);
    match(TsilParser::KW_STRUCT);
    setState(330);
    antlrcpp::downCast<Structure_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(342);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(331);
      match(TsilParser::LESSER);
      setState(332);
      antlrcpp::downCast<Structure_defineContext *>(_localctx)->first_gendef = gendef();
      setState(337);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(333);
        match(TsilParser::COMA);
        setState(334);
        gendef();
        setState(339);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(340);
      match(TsilParser::GREATER);
    }
    setState(353);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::SEMICOLON: {
        setState(344);
        match(TsilParser::SEMICOLON);
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(345);
        match(TsilParser::QUOTE_OPEN);
        setState(349);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == TsilParser::ID) {
          setState(346);
          structure_element();
          setState(351);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(352);
        match(TsilParser::QUOTE_CLOSE);
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

//----------------- Structure_elementContext ------------------------------------------------------------------

TsilParser::Structure_elementContext::Structure_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TsilParser::ParamContext* TsilParser::Structure_elementContext::param() {
  return getRuleContext<TsilParser::ParamContext>(0);
}

tree::TerminalNode* TsilParser::Structure_elementContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}


size_t TsilParser::Structure_elementContext::getRuleIndex() const {
  return TsilParser::RuleStructure_element;
}

void TsilParser::Structure_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructure_element(this);
}

void TsilParser::Structure_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructure_element(this);
}


std::any TsilParser::Structure_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitStructure_element(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Structure_elementContext* TsilParser::structure_element() {
  Structure_elementContext *_localctx = _tracker.createInstance<Structure_elementContext>(_ctx, getState());
  enterRule(_localctx, 38, TsilParser::RuleStructure_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(355);
    param();
    setState(356);
    match(TsilParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Diia_defineContext ------------------------------------------------------------------

TsilParser::Diia_defineContext::Diia_defineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Diia_defineContext::KW_DIIA() {
  return getToken(TsilParser::KW_DIIA, 0);
}

tree::TerminalNode* TsilParser::Diia_defineContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

tree::TerminalNode* TsilParser::Diia_defineContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

tree::TerminalNode* TsilParser::Diia_defineContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::Diia_defineContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

TsilParser::BodyContext* TsilParser::Diia_defineContext::body() {
  return getRuleContext<TsilParser::BodyContext>(0);
}

tree::TerminalNode* TsilParser::Diia_defineContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::Diia_defineContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

std::vector<TsilParser::ParamContext *> TsilParser::Diia_defineContext::param() {
  return getRuleContexts<TsilParser::ParamContext>();
}

TsilParser::ParamContext* TsilParser::Diia_defineContext::param(size_t i) {
  return getRuleContext<TsilParser::ParamContext>(i);
}

tree::TerminalNode* TsilParser::Diia_defineContext::COLON() {
  return getToken(TsilParser::COLON, 0);
}

tree::TerminalNode* TsilParser::Diia_defineContext::KW_PUBLIC() {
  return getToken(TsilParser::KW_PUBLIC, 0);
}

tree::TerminalNode* TsilParser::Diia_defineContext::KW_LOCAL() {
  return getToken(TsilParser::KW_LOCAL, 0);
}

tree::TerminalNode* TsilParser::Diia_defineContext::KW_PRIVATE() {
  return getToken(TsilParser::KW_PRIVATE, 0);
}

std::vector<TsilParser::GendefContext *> TsilParser::Diia_defineContext::gendef() {
  return getRuleContexts<TsilParser::GendefContext>();
}

TsilParser::GendefContext* TsilParser::Diia_defineContext::gendef(size_t i) {
  return getRuleContext<TsilParser::GendefContext>(i);
}

TsilParser::TypeContext* TsilParser::Diia_defineContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> TsilParser::Diia_defineContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Diia_defineContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::Diia_defineContext::getRuleIndex() const {
  return TsilParser::RuleDiia_define;
}

void TsilParser::Diia_defineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiia_define(this);
}

void TsilParser::Diia_defineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiia_define(this);
}


std::any TsilParser::Diia_defineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitDiia_define(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Diia_defineContext* TsilParser::diia_define() {
  Diia_defineContext *_localctx = _tracker.createInstance<Diia_defineContext>(_ctx, getState());
  enterRule(_localctx, 40, TsilParser::RuleDiia_define);
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
    setState(361);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(358);
        antlrcpp::downCast<Diia_defineContext *>(_localctx)->extern_ = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(359);
        antlrcpp::downCast<Diia_defineContext *>(_localctx)->local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(360);
        antlrcpp::downCast<Diia_defineContext *>(_localctx)->intern = match(TsilParser::KW_PRIVATE);
        break;
      }

      case TsilParser::KW_DIIA: {
        break;
      }

    default:
      break;
    }
    setState(363);
    match(TsilParser::KW_DIIA);
    setState(364);
    antlrcpp::downCast<Diia_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(376);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(365);
      match(TsilParser::LESSER);
      setState(366);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->first_gendef = gendef();
      setState(371);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(367);
        match(TsilParser::COMA);
        setState(368);
        gendef();
        setState(373);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(374);
      match(TsilParser::GREATER);
    }
    setState(378);
    match(TsilParser::PAREN_OPEN);
    setState(387);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(379);
      param();
      setState(384);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(380);
        match(TsilParser::COMA);
        setState(381);
        param();
        setState(386);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(389);
    match(TsilParser::PAREN_CLOSE);
    setState(392);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(390);
      match(TsilParser::COLON);
      setState(391);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->restyp = type();
    }
    setState(396);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::SEMICOLON: {
        setState(394);
        match(TsilParser::SEMICOLON);
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(395);
        body();
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

//----------------- Tsil_defineContext ------------------------------------------------------------------

TsilParser::Tsil_defineContext::Tsil_defineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Tsil_defineContext::KW_TSIL() {
  return getToken(TsilParser::KW_TSIL, 0);
}

tree::TerminalNode* TsilParser::Tsil_defineContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

tree::TerminalNode* TsilParser::Tsil_defineContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::Tsil_defineContext::COLON() {
  return getToken(TsilParser::COLON, 0);
}

TsilParser::TypeContext* TsilParser::Tsil_defineContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

tree::TerminalNode* TsilParser::Tsil_defineContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}

tree::TerminalNode* TsilParser::Tsil_defineContext::KW_PUBLIC() {
  return getToken(TsilParser::KW_PUBLIC, 0);
}

tree::TerminalNode* TsilParser::Tsil_defineContext::KW_LOCAL() {
  return getToken(TsilParser::KW_LOCAL, 0);
}

tree::TerminalNode* TsilParser::Tsil_defineContext::KW_PRIVATE() {
  return getToken(TsilParser::KW_PRIVATE, 0);
}

tree::TerminalNode* TsilParser::Tsil_defineContext::KW_VAR() {
  return getToken(TsilParser::KW_VAR, 0);
}

tree::TerminalNode* TsilParser::Tsil_defineContext::KW_IMMUT() {
  return getToken(TsilParser::KW_IMMUT, 0);
}

TsilParser::ExprContext* TsilParser::Tsil_defineContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

TsilParser::Typeless_objectContext* TsilParser::Tsil_defineContext::typeless_object() {
  return getRuleContext<TsilParser::Typeless_objectContext>(0);
}


size_t TsilParser::Tsil_defineContext::getRuleIndex() const {
  return TsilParser::RuleTsil_define;
}

void TsilParser::Tsil_defineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTsil_define(this);
}

void TsilParser::Tsil_defineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTsil_define(this);
}


std::any TsilParser::Tsil_defineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitTsil_define(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Tsil_defineContext* TsilParser::tsil_define() {
  Tsil_defineContext *_localctx = _tracker.createInstance<Tsil_defineContext>(_ctx, getState());
  enterRule(_localctx, 42, TsilParser::RuleTsil_define);
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
    setState(401);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(398);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_external = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(399);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(400);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_internal = match(TsilParser::KW_PRIVATE);
        break;
      }

      case TsilParser::KW_TSIL:
      case TsilParser::KW_VAR:
      case TsilParser::KW_IMMUT: {
        break;
      }

    default:
      break;
    }
    setState(405);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_VAR: {
        setState(403);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_var = match(TsilParser::KW_VAR);
        break;
      }

      case TsilParser::KW_IMMUT: {
        setState(404);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_immut = match(TsilParser::KW_IMMUT);
        break;
      }

      case TsilParser::KW_TSIL: {
        break;
      }

    default:
      break;
    }
    setState(407);
    match(TsilParser::KW_TSIL);
    setState(408);
    antlrcpp::downCast<Tsil_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(411);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(409);
      match(TsilParser::COLON);
      setState(410);
      type();
    }
    setState(418);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::EQUAL) {
      setState(413);
      match(TsilParser::EQUAL);
      setState(416);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TsilParser::PLUS:
        case TsilParser::MINUS:
        case TsilParser::PAREN_OPEN:
        case TsilParser::TILDA:
        case TsilParser::EXCLAMATION:
        case TsilParser::NUMBER:
        case TsilParser::ID:
        case TsilParser::STRING: {
          setState(414);
          antlrcpp::downCast<Tsil_defineContext *>(_localctx)->value_expr = expr();
          break;
        }

        case TsilParser::QUOTE_OPEN: {
          setState(415);
          antlrcpp::downCast<Tsil_defineContext *>(_localctx)->value_object = typeless_object();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
    }
    setState(420);
    match(TsilParser::SEMICOLON);
   
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

TsilParser::Assign_opContext* TsilParser::AssignContext::assign_op() {
  return getRuleContext<TsilParser::Assign_opContext>(0);
}

tree::TerminalNode* TsilParser::AssignContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

tree::TerminalNode* TsilParser::AssignContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::ExprContext* TsilParser::AssignContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

TsilParser::Typeless_objectContext* TsilParser::AssignContext::typeless_object() {
  return getRuleContext<TsilParser::Typeless_objectContext>(0);
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
  enterRule(_localctx, 44, TsilParser::RuleAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(422);
    antlrcpp::downCast<AssignContext *>(_localctx)->id = match(TsilParser::ID);
    setState(423);
    assign_op();
    setState(426);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::PLUS:
      case TsilParser::MINUS:
      case TsilParser::PAREN_OPEN:
      case TsilParser::TILDA:
      case TsilParser::EXCLAMATION:
      case TsilParser::NUMBER:
      case TsilParser::ID:
      case TsilParser::STRING: {
        setState(424);
        antlrcpp::downCast<AssignContext *>(_localctx)->value_expr = expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(425);
        antlrcpp::downCast<AssignContext *>(_localctx)->value_object = typeless_object();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(428);
    match(TsilParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SynonymContext ------------------------------------------------------------------

TsilParser::SynonymContext::SynonymContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::SynonymContext::KW_SYNONYM() {
  return getToken(TsilParser::KW_SYNONYM, 0);
}

tree::TerminalNode* TsilParser::SynonymContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}

tree::TerminalNode* TsilParser::SynonymContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

tree::TerminalNode* TsilParser::SynonymContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::SynonymContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::SynonymContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

TsilParser::ExprContext* TsilParser::SynonymContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

TsilParser::Typeless_objectContext* TsilParser::SynonymContext::typeless_object() {
  return getRuleContext<TsilParser::Typeless_objectContext>(0);
}

TsilParser::TypeContext* TsilParser::SynonymContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

std::vector<TsilParser::GendefContext *> TsilParser::SynonymContext::gendef() {
  return getRuleContexts<TsilParser::GendefContext>();
}

TsilParser::GendefContext* TsilParser::SynonymContext::gendef(size_t i) {
  return getRuleContext<TsilParser::GendefContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::SynonymContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::SynonymContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::SynonymContext::getRuleIndex() const {
  return TsilParser::RuleSynonym;
}

void TsilParser::SynonymContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSynonym(this);
}

void TsilParser::SynonymContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSynonym(this);
}


std::any TsilParser::SynonymContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSynonym(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::SynonymContext* TsilParser::synonym() {
  SynonymContext *_localctx = _tracker.createInstance<SynonymContext>(_ctx, getState());
  enterRule(_localctx, 46, TsilParser::RuleSynonym);
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
    setState(430);
    match(TsilParser::KW_SYNONYM);
    setState(431);
    antlrcpp::downCast<SynonymContext *>(_localctx)->id = match(TsilParser::ID);
    setState(443);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(432);
      match(TsilParser::LESSER);
      setState(433);
      antlrcpp::downCast<SynonymContext *>(_localctx)->first_gendef = gendef();
      setState(438);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(434);
        match(TsilParser::COMA);
        setState(435);
        gendef();
        setState(440);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(441);
      match(TsilParser::GREATER);
    }
    setState(445);
    match(TsilParser::EQUAL);
    setState(449);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      setState(446);
      antlrcpp::downCast<SynonymContext *>(_localctx)->value_expr = expr();
      break;
    }

    case 2: {
      setState(447);
      antlrcpp::downCast<SynonymContext *>(_localctx)->value_object = typeless_object();
      break;
    }

    case 3: {
      setState(448);
      antlrcpp::downCast<SynonymContext *>(_localctx)->value_type = type();
      break;
    }

    default:
      break;
    }
    setState(451);
    match(TsilParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Synonym_fnContext ------------------------------------------------------------------

TsilParser::Synonym_fnContext::Synonym_fnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Synonym_fnContext::KW_SYNONYM() {
  return getToken(TsilParser::KW_SYNONYM, 0);
}

tree::TerminalNode* TsilParser::Synonym_fnContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

tree::TerminalNode* TsilParser::Synonym_fnContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

tree::TerminalNode* TsilParser::Synonym_fnContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}

std::vector<tree::TerminalNode *> TsilParser::Synonym_fnContext::GREATER() {
  return getTokens(TsilParser::GREATER);
}

tree::TerminalNode* TsilParser::Synonym_fnContext::GREATER(size_t i) {
  return getToken(TsilParser::GREATER, i);
}

tree::TerminalNode* TsilParser::Synonym_fnContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

tree::TerminalNode* TsilParser::Synonym_fnContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::Synonym_fnContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

TsilParser::ExprContext* TsilParser::Synonym_fnContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

TsilParser::Typeless_objectContext* TsilParser::Synonym_fnContext::typeless_object() {
  return getRuleContext<TsilParser::Typeless_objectContext>(0);
}

TsilParser::TypeContext* TsilParser::Synonym_fnContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

std::vector<TsilParser::GendefContext *> TsilParser::Synonym_fnContext::gendef() {
  return getRuleContexts<TsilParser::GendefContext>();
}

TsilParser::GendefContext* TsilParser::Synonym_fnContext::gendef(size_t i) {
  return getRuleContext<TsilParser::GendefContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Synonym_fnContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Synonym_fnContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::Synonym_fnContext::getRuleIndex() const {
  return TsilParser::RuleSynonym_fn;
}

void TsilParser::Synonym_fnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSynonym_fn(this);
}

void TsilParser::Synonym_fnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSynonym_fn(this);
}


std::any TsilParser::Synonym_fnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSynonym_fn(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Synonym_fnContext* TsilParser::synonym_fn() {
  Synonym_fnContext *_localctx = _tracker.createInstance<Synonym_fnContext>(_ctx, getState());
  enterRule(_localctx, 48, TsilParser::RuleSynonym_fn);
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
    setState(453);
    match(TsilParser::KW_SYNONYM);
    setState(454);
    antlrcpp::downCast<Synonym_fnContext *>(_localctx)->id = match(TsilParser::ID);
    setState(466);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(455);
      match(TsilParser::LESSER);
      setState(456);
      antlrcpp::downCast<Synonym_fnContext *>(_localctx)->first_gendef = gendef();
      setState(461);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(457);
        match(TsilParser::COMA);
        setState(458);
        gendef();
        setState(463);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(464);
      match(TsilParser::GREATER);
    }
    setState(468);
    match(TsilParser::PAREN_OPEN);
    setState(469);
    match(TsilParser::PAREN_CLOSE);
    setState(470);
    match(TsilParser::EQUAL);
    setState(471);
    match(TsilParser::GREATER);
    setState(475);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      setState(472);
      antlrcpp::downCast<Synonym_fnContext *>(_localctx)->value_expr = expr();
      break;
    }

    case 2: {
      setState(473);
      antlrcpp::downCast<Synonym_fnContext *>(_localctx)->value_object = typeless_object();
      break;
    }

    case 3: {
      setState(474);
      antlrcpp::downCast<Synonym_fnContext *>(_localctx)->value_type = type();
      break;
    }

    default:
      break;
    }
    setState(477);
    match(TsilParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Section_defineContext ------------------------------------------------------------------

TsilParser::Section_defineContext::Section_defineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Section_defineContext::KW_SECTION() {
  return getToken(TsilParser::KW_SECTION, 0);
}

tree::TerminalNode* TsilParser::Section_defineContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::BodyContext* TsilParser::Section_defineContext::body() {
  return getRuleContext<TsilParser::BodyContext>(0);
}


size_t TsilParser::Section_defineContext::getRuleIndex() const {
  return TsilParser::RuleSection_define;
}

void TsilParser::Section_defineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSection_define(this);
}

void TsilParser::Section_defineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSection_define(this);
}


std::any TsilParser::Section_defineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSection_define(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Section_defineContext* TsilParser::section_define() {
  Section_defineContext *_localctx = _tracker.createInstance<Section_defineContext>(_ctx, getState());
  enterRule(_localctx, 50, TsilParser::RuleSection_define);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(479);
    match(TsilParser::KW_SECTION);
    setState(480);
    antlrcpp::downCast<Section_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(482);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      setState(481);
      body();
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

//----------------- SetContext ------------------------------------------------------------------

TsilParser::SetContext::SetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::SetContext::DOT() {
  return getToken(TsilParser::DOT, 0);
}

TsilParser::Assign_opContext* TsilParser::SetContext::assign_op() {
  return getRuleContext<TsilParser::Assign_opContext>(0);
}

tree::TerminalNode* TsilParser::SetContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

TsilParser::AtomContext* TsilParser::SetContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

tree::TerminalNode* TsilParser::SetContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::ExprContext* TsilParser::SetContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

TsilParser::Typeless_objectContext* TsilParser::SetContext::typeless_object() {
  return getRuleContext<TsilParser::Typeless_objectContext>(0);
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
  enterRule(_localctx, 52, TsilParser::RuleSet);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(484);
    antlrcpp::downCast<SetContext *>(_localctx)->object = atom(0);
    setState(485);
    match(TsilParser::DOT);
    setState(486);
    antlrcpp::downCast<SetContext *>(_localctx)->id = match(TsilParser::ID);
    setState(487);
    assign_op();
    setState(490);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::PLUS:
      case TsilParser::MINUS:
      case TsilParser::PAREN_OPEN:
      case TsilParser::TILDA:
      case TsilParser::EXCLAMATION:
      case TsilParser::NUMBER:
      case TsilParser::ID:
      case TsilParser::STRING: {
        setState(488);
        antlrcpp::downCast<SetContext *>(_localctx)->value_expr = expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(489);
        antlrcpp::downCast<SetContext *>(_localctx)->value_object = typeless_object();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(492);
    match(TsilParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Position_setContext ------------------------------------------------------------------

TsilParser::Position_setContext::Position_setContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Position_setContext::BRACKET_OPEN() {
  return getToken(TsilParser::BRACKET_OPEN, 0);
}

tree::TerminalNode* TsilParser::Position_setContext::BRACKET_CLOSE() {
  return getToken(TsilParser::BRACKET_CLOSE, 0);
}

TsilParser::Assign_opContext* TsilParser::Position_setContext::assign_op() {
  return getRuleContext<TsilParser::Assign_opContext>(0);
}

tree::TerminalNode* TsilParser::Position_setContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

TsilParser::AtomContext* TsilParser::Position_setContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

std::vector<TsilParser::ExprContext *> TsilParser::Position_setContext::expr() {
  return getRuleContexts<TsilParser::ExprContext>();
}

TsilParser::ExprContext* TsilParser::Position_setContext::expr(size_t i) {
  return getRuleContext<TsilParser::ExprContext>(i);
}

TsilParser::Typeless_objectContext* TsilParser::Position_setContext::typeless_object() {
  return getRuleContext<TsilParser::Typeless_objectContext>(0);
}


size_t TsilParser::Position_setContext::getRuleIndex() const {
  return TsilParser::RulePosition_set;
}

void TsilParser::Position_setContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPosition_set(this);
}

void TsilParser::Position_setContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPosition_set(this);
}


std::any TsilParser::Position_setContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitPosition_set(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Position_setContext* TsilParser::position_set() {
  Position_setContext *_localctx = _tracker.createInstance<Position_setContext>(_ctx, getState());
  enterRule(_localctx, 54, TsilParser::RulePosition_set);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(494);
    antlrcpp::downCast<Position_setContext *>(_localctx)->object = atom(0);
    setState(495);
    match(TsilParser::BRACKET_OPEN);
    setState(496);
    antlrcpp::downCast<Position_setContext *>(_localctx)->idx = expr();
    setState(497);
    match(TsilParser::BRACKET_CLOSE);
    setState(498);
    assign_op();
    setState(501);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::PLUS:
      case TsilParser::MINUS:
      case TsilParser::PAREN_OPEN:
      case TsilParser::TILDA:
      case TsilParser::EXCLAMATION:
      case TsilParser::NUMBER:
      case TsilParser::ID:
      case TsilParser::STRING: {
        setState(499);
        antlrcpp::downCast<Position_setContext *>(_localctx)->value_expr = expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(500);
        antlrcpp::downCast<Position_setContext *>(_localctx)->value_object = typeless_object();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(503);
    match(TsilParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Section_setContext ------------------------------------------------------------------

TsilParser::Section_setContext::Section_setContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TsilParser::Section_setContext::COLON() {
  return getTokens(TsilParser::COLON);
}

tree::TerminalNode* TsilParser::Section_setContext::COLON(size_t i) {
  return getToken(TsilParser::COLON, i);
}

TsilParser::Assign_opContext* TsilParser::Section_setContext::assign_op() {
  return getRuleContext<TsilParser::Assign_opContext>(0);
}

tree::TerminalNode* TsilParser::Section_setContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

TsilParser::AtomContext* TsilParser::Section_setContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

tree::TerminalNode* TsilParser::Section_setContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::ExprContext* TsilParser::Section_setContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

TsilParser::Typeless_objectContext* TsilParser::Section_setContext::typeless_object() {
  return getRuleContext<TsilParser::Typeless_objectContext>(0);
}


size_t TsilParser::Section_setContext::getRuleIndex() const {
  return TsilParser::RuleSection_set;
}

void TsilParser::Section_setContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSection_set(this);
}

void TsilParser::Section_setContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSection_set(this);
}


std::any TsilParser::Section_setContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSection_set(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Section_setContext* TsilParser::section_set() {
  Section_setContext *_localctx = _tracker.createInstance<Section_setContext>(_ctx, getState());
  enterRule(_localctx, 56, TsilParser::RuleSection_set);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(505);
    antlrcpp::downCast<Section_setContext *>(_localctx)->object = atom(0);
    setState(506);
    match(TsilParser::COLON);
    setState(507);
    match(TsilParser::COLON);
    setState(508);
    antlrcpp::downCast<Section_setContext *>(_localctx)->id = match(TsilParser::ID);
    setState(509);
    assign_op();
    setState(512);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::PLUS:
      case TsilParser::MINUS:
      case TsilParser::PAREN_OPEN:
      case TsilParser::TILDA:
      case TsilParser::EXCLAMATION:
      case TsilParser::NUMBER:
      case TsilParser::ID:
      case TsilParser::STRING: {
        setState(510);
        antlrcpp::downCast<Section_setContext *>(_localctx)->value_expr = expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(511);
        antlrcpp::downCast<Section_setContext *>(_localctx)->value_object = typeless_object();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(514);
    match(TsilParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assign_opContext ------------------------------------------------------------------

TsilParser::Assign_opContext::Assign_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Assign_opContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}

TsilParser::Op_lshiftContext* TsilParser::Assign_opContext::op_lshift() {
  return getRuleContext<TsilParser::Op_lshiftContext>(0);
}

TsilParser::Op_rshiftContext* TsilParser::Assign_opContext::op_rshift() {
  return getRuleContext<TsilParser::Op_rshiftContext>(0);
}

TsilParser::Op_urshiftContext* TsilParser::Assign_opContext::op_urshift() {
  return getRuleContext<TsilParser::Op_urshiftContext>(0);
}

tree::TerminalNode* TsilParser::Assign_opContext::MULTIPLY() {
  return getToken(TsilParser::MULTIPLY, 0);
}

tree::TerminalNode* TsilParser::Assign_opContext::DIVIDE() {
  return getToken(TsilParser::DIVIDE, 0);
}

tree::TerminalNode* TsilParser::Assign_opContext::MOD() {
  return getToken(TsilParser::MOD, 0);
}

tree::TerminalNode* TsilParser::Assign_opContext::PLUS() {
  return getToken(TsilParser::PLUS, 0);
}

tree::TerminalNode* TsilParser::Assign_opContext::MINUS() {
  return getToken(TsilParser::MINUS, 0);
}

tree::TerminalNode* TsilParser::Assign_opContext::AND() {
  return getToken(TsilParser::AND, 0);
}

tree::TerminalNode* TsilParser::Assign_opContext::POWER() {
  return getToken(TsilParser::POWER, 0);
}

tree::TerminalNode* TsilParser::Assign_opContext::OR() {
  return getToken(TsilParser::OR, 0);
}


size_t TsilParser::Assign_opContext::getRuleIndex() const {
  return TsilParser::RuleAssign_op;
}

void TsilParser::Assign_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign_op(this);
}

void TsilParser::Assign_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign_op(this);
}


std::any TsilParser::Assign_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAssign_op(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Assign_opContext* TsilParser::assign_op() {
  Assign_opContext *_localctx = _tracker.createInstance<Assign_opContext>(_ctx, getState());
  enterRule(_localctx, 58, TsilParser::RuleAssign_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(527);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      setState(516);
      antlrcpp::downCast<Assign_opContext *>(_localctx)->aop_mul = match(TsilParser::MULTIPLY);
      break;
    }

    case 2: {
      setState(517);
      antlrcpp::downCast<Assign_opContext *>(_localctx)->aop_div = match(TsilParser::DIVIDE);
      break;
    }

    case 3: {
      setState(518);
      antlrcpp::downCast<Assign_opContext *>(_localctx)->aop_mod = match(TsilParser::MOD);
      break;
    }

    case 4: {
      setState(519);
      antlrcpp::downCast<Assign_opContext *>(_localctx)->aop_plus = match(TsilParser::PLUS);
      break;
    }

    case 5: {
      setState(520);
      antlrcpp::downCast<Assign_opContext *>(_localctx)->aop_minus = match(TsilParser::MINUS);
      break;
    }

    case 6: {
      setState(521);
      op_lshift();
      break;
    }

    case 7: {
      setState(522);
      op_rshift();
      break;
    }

    case 8: {
      setState(523);
      op_urshift();
      break;
    }

    case 9: {
      setState(524);
      antlrcpp::downCast<Assign_opContext *>(_localctx)->aop_and = match(TsilParser::AND);
      break;
    }

    case 10: {
      setState(525);
      antlrcpp::downCast<Assign_opContext *>(_localctx)->aop_xor = match(TsilParser::POWER);
      break;
    }

    case 11: {
      setState(526);
      antlrcpp::downCast<Assign_opContext *>(_localctx)->aop_or = match(TsilParser::OR);
      break;
    }

    default:
      break;
    }
    setState(529);
    match(TsilParser::EQUAL);
   
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

TsilParser::OperationContext* TsilParser::IfContext::operation() {
  return getRuleContext<TsilParser::OperationContext>(0);
}

std::vector<TsilParser::BodyContext *> TsilParser::IfContext::body() {
  return getRuleContexts<TsilParser::BodyContext>();
}

TsilParser::BodyContext* TsilParser::IfContext::body(size_t i) {
  return getRuleContext<TsilParser::BodyContext>(i);
}

tree::TerminalNode* TsilParser::IfContext::KW_ELSE() {
  return getToken(TsilParser::KW_ELSE, 0);
}

TsilParser::IfContext* TsilParser::IfContext::if_() {
  return getRuleContext<TsilParser::IfContext>(0);
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
  enterRule(_localctx, 60, TsilParser::RuleIf);
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
    setState(531);
    match(TsilParser::KW_IF);
    setState(532);
    antlrcpp::downCast<IfContext *>(_localctx)->cond = operation(0);
    setState(533);
    antlrcpp::downCast<IfContext *>(_localctx)->ifok = body();
    setState(539);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::KW_ELSE) {
      setState(534);
      match(TsilParser::KW_ELSE);
      setState(537);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TsilParser::QUOTE_OPEN: {
          setState(535);
          antlrcpp::downCast<IfContext *>(_localctx)->ifnot = body();
          break;
        }

        case TsilParser::KW_IF: {
          setState(536);
          antlrcpp::downCast<IfContext *>(_localctx)->ifnotif = if_();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
    }
   
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

TsilParser::BodyContext* TsilParser::WhileContext::body() {
  return getRuleContext<TsilParser::BodyContext>(0);
}

TsilParser::OperationContext* TsilParser::WhileContext::operation() {
  return getRuleContext<TsilParser::OperationContext>(0);
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
  enterRule(_localctx, 62, TsilParser::RuleWhile);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(541);
    match(TsilParser::KW_WHILE);
    setState(542);
    antlrcpp::downCast<WhileContext *>(_localctx)->cond = operation(0);
    setState(543);
    body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExecContext ------------------------------------------------------------------

TsilParser::ExecContext::ExecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::ExecContext::KW_EXEC() {
  return getToken(TsilParser::KW_EXEC, 0);
}

TsilParser::BodyContext* TsilParser::ExecContext::body() {
  return getRuleContext<TsilParser::BodyContext>(0);
}

tree::TerminalNode* TsilParser::ExecContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}


size_t TsilParser::ExecContext::getRuleIndex() const {
  return TsilParser::RuleExec;
}

void TsilParser::ExecContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExec(this);
}

void TsilParser::ExecContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExec(this);
}


std::any TsilParser::ExecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitExec(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::ExecContext* TsilParser::exec() {
  ExecContext *_localctx = _tracker.createInstance<ExecContext>(_ctx, getState());
  enterRule(_localctx, 64, TsilParser::RuleExec);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(545);
    match(TsilParser::KW_EXEC);
    setState(546);
    body();
    setState(547);
    match(TsilParser::SEMICOLON);
   
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

tree::TerminalNode* TsilParser::BodyContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::BodyContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}

std::vector<TsilParser::Body_elementContext *> TsilParser::BodyContext::body_element() {
  return getRuleContexts<TsilParser::Body_elementContext>();
}

TsilParser::Body_elementContext* TsilParser::BodyContext::body_element(size_t i) {
  return getRuleContext<TsilParser::Body_elementContext>(i);
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
  enterRule(_localctx, 66, TsilParser::RuleBody);
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
    setState(549);
    match(TsilParser::QUOTE_OPEN);
    setState(553);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -4560877422835721874) != 0)) {
      setState(550);
      body_element();
      setState(555);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(556);
    match(TsilParser::QUOTE_CLOSE);
   
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

TsilParser::Structure_defineContext* TsilParser::Body_elementContext::structure_define() {
  return getRuleContext<TsilParser::Structure_defineContext>(0);
}

TsilParser::Diia_defineContext* TsilParser::Body_elementContext::diia_define() {
  return getRuleContext<TsilParser::Diia_defineContext>(0);
}

TsilParser::Tsil_defineContext* TsilParser::Body_elementContext::tsil_define() {
  return getRuleContext<TsilParser::Tsil_defineContext>(0);
}

TsilParser::AssignContext* TsilParser::Body_elementContext::assign() {
  return getRuleContext<TsilParser::AssignContext>(0);
}

TsilParser::SetContext* TsilParser::Body_elementContext::set() {
  return getRuleContext<TsilParser::SetContext>(0);
}

TsilParser::Section_setContext* TsilParser::Body_elementContext::section_set() {
  return getRuleContext<TsilParser::Section_setContext>(0);
}

TsilParser::Position_setContext* TsilParser::Body_elementContext::position_set() {
  return getRuleContext<TsilParser::Position_setContext>(0);
}

TsilParser::SynonymContext* TsilParser::Body_elementContext::synonym() {
  return getRuleContext<TsilParser::SynonymContext>(0);
}

TsilParser::Synonym_fnContext* TsilParser::Body_elementContext::synonym_fn() {
  return getRuleContext<TsilParser::Synonym_fnContext>(0);
}

TsilParser::Section_defineContext* TsilParser::Body_elementContext::section_define() {
  return getRuleContext<TsilParser::Section_defineContext>(0);
}

TsilParser::IfContext* TsilParser::Body_elementContext::if_() {
  return getRuleContext<TsilParser::IfContext>(0);
}

TsilParser::WhileContext* TsilParser::Body_elementContext::while_() {
  return getRuleContext<TsilParser::WhileContext>(0);
}

TsilParser::ExprContext* TsilParser::Body_elementContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

tree::TerminalNode* TsilParser::Body_elementContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

TsilParser::BodyContext* TsilParser::Body_elementContext::body() {
  return getRuleContext<TsilParser::BodyContext>(0);
}

TsilParser::ExecContext* TsilParser::Body_elementContext::exec() {
  return getRuleContext<TsilParser::ExecContext>(0);
}

TsilParser::ReturnContext* TsilParser::Body_elementContext::return_() {
  return getRuleContext<TsilParser::ReturnContext>(0);
}

TsilParser::PreprocContext* TsilParser::Body_elementContext::preproc() {
  return getRuleContext<TsilParser::PreprocContext>(0);
}

TsilParser::TakeContext* TsilParser::Body_elementContext::take() {
  return getRuleContext<TsilParser::TakeContext>(0);
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
  enterRule(_localctx, 68, TsilParser::RuleBody_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(579);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(558);
      structure_define();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(559);
      diia_define();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(560);
      tsil_define();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(561);
      assign();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(562);
      set();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(563);
      section_set();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(564);
      position_set();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(565);
      synonym();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(566);
      synonym_fn();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(567);
      section_define();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(568);
      if_();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(569);
      while_();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(570);
      expr();
      setState(571);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(573);
      body();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(574);
      exec();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(575);
      return_();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(576);
      preproc();
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(577);
      take();
      break;
    }

    case 19: {
      enterOuterAlt(_localctx, 19);
      setState(578);
      antlrcpp::downCast<Body_elementContext *>(_localctx)->semi = match(TsilParser::SEMICOLON);
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

//----------------- ReturnContext ------------------------------------------------------------------

TsilParser::ReturnContext::ReturnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::ReturnContext::KW_RETURN() {
  return getToken(TsilParser::KW_RETURN, 0);
}

tree::TerminalNode* TsilParser::ReturnContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

TsilParser::ExprContext* TsilParser::ReturnContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

TsilParser::Typeless_objectContext* TsilParser::ReturnContext::typeless_object() {
  return getRuleContext<TsilParser::Typeless_objectContext>(0);
}


size_t TsilParser::ReturnContext::getRuleIndex() const {
  return TsilParser::RuleReturn;
}

void TsilParser::ReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn(this);
}

void TsilParser::ReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn(this);
}


std::any TsilParser::ReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitReturn(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::ReturnContext* TsilParser::return_() {
  ReturnContext *_localctx = _tracker.createInstance<ReturnContext>(_ctx, getState());
  enterRule(_localctx, 70, TsilParser::RuleReturn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(581);
    match(TsilParser::KW_RETURN);
    setState(584);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::PLUS:
      case TsilParser::MINUS:
      case TsilParser::PAREN_OPEN:
      case TsilParser::TILDA:
      case TsilParser::EXCLAMATION:
      case TsilParser::NUMBER:
      case TsilParser::ID:
      case TsilParser::STRING: {
        setState(582);
        antlrcpp::downCast<ReturnContext *>(_localctx)->value_expr = expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(583);
        antlrcpp::downCast<ReturnContext *>(_localctx)->value_object = typeless_object();
        break;
      }

      case TsilParser::SEMICOLON: {
        break;
      }

    default:
      break;
    }
    setState(586);
    match(TsilParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_typeContext ------------------------------------------------------------------

TsilParser::Simple_typeContext::Simple_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TsilParser::Simple_typeContext::getRuleIndex() const {
  return TsilParser::RuleSimple_type;
}

void TsilParser::Simple_typeContext::copyFrom(Simple_typeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Simple_type_section_getContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> TsilParser::Simple_type_section_getContext::COLON() {
  return getTokens(TsilParser::COLON);
}

tree::TerminalNode* TsilParser::Simple_type_section_getContext::COLON(size_t i) {
  return getToken(TsilParser::COLON, i);
}

TsilParser::Simple_typeContext* TsilParser::Simple_type_section_getContext::simple_type() {
  return getRuleContext<TsilParser::Simple_typeContext>(0);
}

tree::TerminalNode* TsilParser::Simple_type_section_getContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::Simple_type_section_getContext::Simple_type_section_getContext(Simple_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Simple_type_section_getContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_type_section_get(this);
}
void TsilParser::Simple_type_section_getContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_type_section_get(this);
}

std::any TsilParser::Simple_type_section_getContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSimple_type_section_get(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Simple_type_subjectContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Simple_type_subjectContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::Simple_type_subjectContext::Simple_type_subjectContext(Simple_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Simple_type_subjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_type_subject(this);
}
void TsilParser::Simple_type_subjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_type_subject(this);
}

std::any TsilParser::Simple_type_subjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSimple_type_subject(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Simple_type_template_getContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Simple_type_template_getContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

std::vector<TsilParser::TypeContext *> TsilParser::Simple_type_template_getContext::type() {
  return getRuleContexts<TsilParser::TypeContext>();
}

TsilParser::TypeContext* TsilParser::Simple_type_template_getContext::type(size_t i) {
  return getRuleContext<TsilParser::TypeContext>(i);
}

tree::TerminalNode* TsilParser::Simple_type_template_getContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

TsilParser::Simple_typeContext* TsilParser::Simple_type_template_getContext::simple_type() {
  return getRuleContext<TsilParser::Simple_typeContext>(0);
}

std::vector<tree::TerminalNode *> TsilParser::Simple_type_template_getContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Simple_type_template_getContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}

TsilParser::Simple_type_template_getContext::Simple_type_template_getContext(Simple_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Simple_type_template_getContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_type_template_get(this);
}
void TsilParser::Simple_type_template_getContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_type_template_get(this);
}

std::any TsilParser::Simple_type_template_getContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSimple_type_template_get(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Simple_type_arrayContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Simple_type_arrayContext::BRACKET_OPEN() {
  return getToken(TsilParser::BRACKET_OPEN, 0);
}

tree::TerminalNode* TsilParser::Simple_type_arrayContext::BRACKET_CLOSE() {
  return getToken(TsilParser::BRACKET_CLOSE, 0);
}

TsilParser::Simple_typeContext* TsilParser::Simple_type_arrayContext::simple_type() {
  return getRuleContext<TsilParser::Simple_typeContext>(0);
}

tree::TerminalNode* TsilParser::Simple_type_arrayContext::NUMBER() {
  return getToken(TsilParser::NUMBER, 0);
}

TsilParser::Simple_type_arrayContext::Simple_type_arrayContext(Simple_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Simple_type_arrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_type_array(this);
}
void TsilParser::Simple_type_arrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_type_array(this);
}

std::any TsilParser::Simple_type_arrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSimple_type_array(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Simple_type_getContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Simple_type_getContext::DOT() {
  return getToken(TsilParser::DOT, 0);
}

TsilParser::Simple_typeContext* TsilParser::Simple_type_getContext::simple_type() {
  return getRuleContext<TsilParser::Simple_typeContext>(0);
}

tree::TerminalNode* TsilParser::Simple_type_getContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::Simple_type_getContext::Simple_type_getContext(Simple_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Simple_type_getContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_type_get(this);
}
void TsilParser::Simple_type_getContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_type_get(this);
}

std::any TsilParser::Simple_type_getContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSimple_type_get(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Simple_typeContext* TsilParser::simple_type() {
   return simple_type(0);
}

TsilParser::Simple_typeContext* TsilParser::simple_type(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TsilParser::Simple_typeContext *_localctx = _tracker.createInstance<Simple_typeContext>(_ctx, parentState);
  TsilParser::Simple_typeContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 72;
  enterRecursionRule(_localctx, 72, TsilParser::RuleSimple_type, precedence);

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
    _localctx = _tracker.createInstance<Simple_type_subjectContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(589);
    antlrcpp::downCast<Simple_type_subjectContext *>(_localctx)->id = match(TsilParser::ID);
    _ctx->stop = _input->LT(-1);
    setState(616);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(614);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Simple_type_section_getContext>(_tracker.createInstance<Simple_typeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleSimple_type);
          setState(591);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(592);
          match(TsilParser::COLON);
          setState(593);
          match(TsilParser::COLON);
          setState(594);
          antlrcpp::downCast<Simple_type_section_getContext *>(_localctx)->id = match(TsilParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Simple_type_template_getContext>(_tracker.createInstance<Simple_typeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleSimple_type);
          setState(595);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(596);
          match(TsilParser::LESSER);
          setState(597);
          type();
          setState(602);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == TsilParser::COMA) {
            setState(598);
            match(TsilParser::COMA);
            setState(599);
            type();
            setState(604);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(605);
          match(TsilParser::GREATER);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Simple_type_getContext>(_tracker.createInstance<Simple_typeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleSimple_type);
          setState(607);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(608);
          match(TsilParser::DOT);
          setState(609);
          antlrcpp::downCast<Simple_type_getContext *>(_localctx)->id = match(TsilParser::ID);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Simple_type_arrayContext>(_tracker.createInstance<Simple_typeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleSimple_type);
          setState(610);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(611);
          match(TsilParser::BRACKET_OPEN);
          setState(612);
          antlrcpp::downCast<Simple_type_arrayContext *>(_localctx)->size = match(TsilParser::NUMBER);
          setState(613);
          match(TsilParser::BRACKET_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(618);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Single_typeContext ------------------------------------------------------------------

TsilParser::Single_typeContext::Single_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TsilParser::Single_typeContext::getRuleIndex() const {
  return TsilParser::RuleSingle_type;
}

void TsilParser::Single_typeContext::copyFrom(Single_typeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Type_simple_typeContext ------------------------------------------------------------------

TsilParser::Simple_typeContext* TsilParser::Type_simple_typeContext::simple_type() {
  return getRuleContext<TsilParser::Simple_typeContext>(0);
}

TsilParser::Type_simple_typeContext::Type_simple_typeContext(Single_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Type_simple_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_simple_type(this);
}
void TsilParser::Type_simple_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_simple_type(this);
}

std::any TsilParser::Type_simple_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitType_simple_type(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Type_fn_complexContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Type_fn_complexContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

std::vector<TsilParser::TypeContext *> TsilParser::Type_fn_complexContext::type() {
  return getRuleContexts<TsilParser::TypeContext>();
}

TsilParser::TypeContext* TsilParser::Type_fn_complexContext::type(size_t i) {
  return getRuleContext<TsilParser::TypeContext>(i);
}

tree::TerminalNode* TsilParser::Type_fn_complexContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

tree::TerminalNode* TsilParser::Type_fn_complexContext::MINUS() {
  return getToken(TsilParser::MINUS, 0);
}

tree::TerminalNode* TsilParser::Type_fn_complexContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

std::vector<tree::TerminalNode *> TsilParser::Type_fn_complexContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Type_fn_complexContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}

TsilParser::Type_fn_complexContext::Type_fn_complexContext(Single_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Type_fn_complexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_fn_complex(this);
}
void TsilParser::Type_fn_complexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_fn_complex(this);
}

std::any TsilParser::Type_fn_complexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitType_fn_complex(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Type_fn_complex_namedContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Type_fn_complex_namedContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

std::vector<TsilParser::ParamContext *> TsilParser::Type_fn_complex_namedContext::param() {
  return getRuleContexts<TsilParser::ParamContext>();
}

TsilParser::ParamContext* TsilParser::Type_fn_complex_namedContext::param(size_t i) {
  return getRuleContext<TsilParser::ParamContext>(i);
}

tree::TerminalNode* TsilParser::Type_fn_complex_namedContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

tree::TerminalNode* TsilParser::Type_fn_complex_namedContext::MINUS() {
  return getToken(TsilParser::MINUS, 0);
}

tree::TerminalNode* TsilParser::Type_fn_complex_namedContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

TsilParser::TypeContext* TsilParser::Type_fn_complex_namedContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> TsilParser::Type_fn_complex_namedContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Type_fn_complex_namedContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}

TsilParser::Type_fn_complex_namedContext::Type_fn_complex_namedContext(Single_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Type_fn_complex_namedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_fn_complex_named(this);
}
void TsilParser::Type_fn_complex_namedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_fn_complex_named(this);
}

std::any TsilParser::Type_fn_complex_namedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitType_fn_complex_named(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Type_fn_simpleContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Type_fn_simpleContext::MINUS() {
  return getToken(TsilParser::MINUS, 0);
}

tree::TerminalNode* TsilParser::Type_fn_simpleContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

TsilParser::Single_typeContext* TsilParser::Type_fn_simpleContext::single_type() {
  return getRuleContext<TsilParser::Single_typeContext>(0);
}

TsilParser::TypeContext* TsilParser::Type_fn_simpleContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

TsilParser::Type_fn_simpleContext::Type_fn_simpleContext(Single_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Type_fn_simpleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_fn_simple(this);
}
void TsilParser::Type_fn_simpleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_fn_simple(this);
}

std::any TsilParser::Type_fn_simpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitType_fn_simple(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Type_fnContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Type_fnContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

tree::TerminalNode* TsilParser::Type_fnContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

tree::TerminalNode* TsilParser::Type_fnContext::MINUS() {
  return getToken(TsilParser::MINUS, 0);
}

tree::TerminalNode* TsilParser::Type_fnContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

TsilParser::TypeContext* TsilParser::Type_fnContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

TsilParser::Type_fnContext::Type_fnContext(Single_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Type_fnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_fn(this);
}
void TsilParser::Type_fnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_fn(this);
}

std::any TsilParser::Type_fnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitType_fn(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Single_typeContext* TsilParser::single_type() {
   return single_type(0);
}

TsilParser::Single_typeContext* TsilParser::single_type(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TsilParser::Single_typeContext *_localctx = _tracker.createInstance<Single_typeContext>(_ctx, parentState);
  TsilParser::Single_typeContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 74;
  enterRecursionRule(_localctx, 74, TsilParser::RuleSingle_type, precedence);

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
    setState(654);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Type_simple_typeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(620);
      simple_type(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Type_fnContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(621);
      match(TsilParser::PAREN_OPEN);
      setState(622);
      match(TsilParser::PAREN_CLOSE);
      setState(623);
      match(TsilParser::MINUS);
      setState(624);
      match(TsilParser::GREATER);
      setState(625);
      antlrcpp::downCast<Type_fnContext *>(_localctx)->restyp = type();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Type_fn_complexContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(626);
      match(TsilParser::PAREN_OPEN);
      setState(627);
      type();
      setState(632);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(628);
        match(TsilParser::COMA);
        setState(629);
        type();
        setState(634);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(635);
      match(TsilParser::PAREN_CLOSE);
      setState(636);
      match(TsilParser::MINUS);
      setState(637);
      match(TsilParser::GREATER);
      setState(638);
      antlrcpp::downCast<Type_fn_complexContext *>(_localctx)->restyp = type();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Type_fn_complex_namedContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(640);
      match(TsilParser::PAREN_OPEN);
      setState(641);
      param();
      setState(646);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(642);
        match(TsilParser::COMA);
        setState(643);
        param();
        setState(648);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(649);
      match(TsilParser::PAREN_CLOSE);
      setState(650);
      match(TsilParser::MINUS);
      setState(651);
      match(TsilParser::GREATER);
      setState(652);
      antlrcpp::downCast<Type_fn_complex_namedContext *>(_localctx)->restyp = type();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(662);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Type_fn_simpleContext>(_tracker.createInstance<Single_typeContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->param_type = previousContext;
        pushNewRecursionContext(newContext, startState, RuleSingle_type);
        setState(656);

        if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
        setState(657);
        match(TsilParser::MINUS);
        setState(658);
        match(TsilParser::GREATER);
        setState(659);
        antlrcpp::downCast<Type_fn_simpleContext *>(_localctx)->restyp = type(); 
      }
      setState(664);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
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


size_t TsilParser::TypeContext::getRuleIndex() const {
  return TsilParser::RuleType;
}

void TsilParser::TypeContext::copyFrom(TypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Type_variationContext ------------------------------------------------------------------

std::vector<TsilParser::Single_typeContext *> TsilParser::Type_variationContext::single_type() {
  return getRuleContexts<TsilParser::Single_typeContext>();
}

TsilParser::Single_typeContext* TsilParser::Type_variationContext::single_type(size_t i) {
  return getRuleContext<TsilParser::Single_typeContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Type_variationContext::OR() {
  return getTokens(TsilParser::OR);
}

tree::TerminalNode* TsilParser::Type_variationContext::OR(size_t i) {
  return getToken(TsilParser::OR, i);
}

TsilParser::Type_variationContext::Type_variationContext(TypeContext *ctx) { copyFrom(ctx); }

void TsilParser::Type_variationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_variation(this);
}
void TsilParser::Type_variationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_variation(this);
}

std::any TsilParser::Type_variationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitType_variation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Type_nestedContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Type_nestedContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

TsilParser::TypeContext* TsilParser::Type_nestedContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

tree::TerminalNode* TsilParser::Type_nestedContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

TsilParser::Type_nestedContext::Type_nestedContext(TypeContext *ctx) { copyFrom(ctx); }

void TsilParser::Type_nestedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_nested(this);
}
void TsilParser::Type_nestedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_nested(this);
}

std::any TsilParser::Type_nestedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitType_nested(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Type_singleContext ------------------------------------------------------------------

TsilParser::Single_typeContext* TsilParser::Type_singleContext::single_type() {
  return getRuleContext<TsilParser::Single_typeContext>(0);
}

TsilParser::Type_singleContext::Type_singleContext(TypeContext *ctx) { copyFrom(ctx); }

void TsilParser::Type_singleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_single(this);
}
void TsilParser::Type_singleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_single(this);
}

std::any TsilParser::Type_singleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitType_single(this);
  else
    return visitor->visitChildren(this);
}
TsilParser::TypeContext* TsilParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 76, TsilParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(677);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TsilParser::Type_nestedContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(665);
      match(TsilParser::PAREN_OPEN);
      setState(666);
      type();
      setState(667);
      match(TsilParser::PAREN_CLOSE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TsilParser::Type_singleContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(669);
      single_type(0);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<TsilParser::Type_variationContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(670);
      single_type(0);
      setState(673); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(671);
                match(TsilParser::OR);
                setState(672);
                single_type(0);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(675); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
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

tree::TerminalNode* TsilParser::ParamContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::ParamContext::COLON() {
  return getToken(TsilParser::COLON, 0);
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
  enterRule(_localctx, 78, TsilParser::RuleParam);
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
    setState(679);
    antlrcpp::downCast<ParamContext *>(_localctx)->id = match(TsilParser::ID);
    setState(682);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(680);
      match(TsilParser::COLON);
      setState(681);
      type();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PreprocContext ------------------------------------------------------------------

TsilParser::PreprocContext::PreprocContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TsilParser::PreprocContext::getRuleIndex() const {
  return TsilParser::RulePreproc;
}

void TsilParser::PreprocContext::copyFrom(PreprocContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Preproc_ifContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> TsilParser::Preproc_ifContext::MOD() {
  return getTokens(TsilParser::MOD);
}

tree::TerminalNode* TsilParser::Preproc_ifContext::MOD(size_t i) {
  return getToken(TsilParser::MOD, i);
}

std::vector<tree::TerminalNode *> TsilParser::Preproc_ifContext::BRACKET_OPEN() {
  return getTokens(TsilParser::BRACKET_OPEN);
}

tree::TerminalNode* TsilParser::Preproc_ifContext::BRACKET_OPEN(size_t i) {
  return getToken(TsilParser::BRACKET_OPEN, i);
}

std::vector<tree::TerminalNode *> TsilParser::Preproc_ifContext::KW_IF() {
  return getTokens(TsilParser::KW_IF);
}

tree::TerminalNode* TsilParser::Preproc_ifContext::KW_IF(size_t i) {
  return getToken(TsilParser::KW_IF, i);
}

std::vector<tree::TerminalNode *> TsilParser::Preproc_ifContext::BRACKET_CLOSE() {
  return getTokens(TsilParser::BRACKET_CLOSE);
}

tree::TerminalNode* TsilParser::Preproc_ifContext::BRACKET_CLOSE(size_t i) {
  return getToken(TsilParser::BRACKET_CLOSE, i);
}

tree::TerminalNode* TsilParser::Preproc_ifContext::DIVIDE() {
  return getToken(TsilParser::DIVIDE, 0);
}

TsilParser::OperationContext* TsilParser::Preproc_ifContext::operation() {
  return getRuleContext<TsilParser::OperationContext>(0);
}

std::vector<TsilParser::Body_elementContext *> TsilParser::Preproc_ifContext::body_element() {
  return getRuleContexts<TsilParser::Body_elementContext>();
}

TsilParser::Body_elementContext* TsilParser::Preproc_ifContext::body_element(size_t i) {
  return getRuleContext<TsilParser::Body_elementContext>(i);
}

tree::TerminalNode* TsilParser::Preproc_ifContext::KW_ELSE() {
  return getToken(TsilParser::KW_ELSE, 0);
}

TsilParser::Preproc_ifContext::Preproc_ifContext(PreprocContext *ctx) { copyFrom(ctx); }

void TsilParser::Preproc_ifContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPreproc_if(this);
}
void TsilParser::Preproc_ifContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPreproc_if(this);
}

std::any TsilParser::Preproc_ifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitPreproc_if(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Preproc_throwContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Preproc_throwContext::MOD() {
  return getToken(TsilParser::MOD, 0);
}

tree::TerminalNode* TsilParser::Preproc_throwContext::BRACKET_OPEN() {
  return getToken(TsilParser::BRACKET_OPEN, 0);
}

tree::TerminalNode* TsilParser::Preproc_throwContext::KW_THROW() {
  return getToken(TsilParser::KW_THROW, 0);
}

tree::TerminalNode* TsilParser::Preproc_throwContext::BRACKET_CLOSE() {
  return getToken(TsilParser::BRACKET_CLOSE, 0);
}

TsilParser::OperationContext* TsilParser::Preproc_throwContext::operation() {
  return getRuleContext<TsilParser::OperationContext>(0);
}

TsilParser::Preproc_throwContext::Preproc_throwContext(PreprocContext *ctx) { copyFrom(ctx); }

void TsilParser::Preproc_throwContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPreproc_throw(this);
}
void TsilParser::Preproc_throwContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPreproc_throw(this);
}

std::any TsilParser::Preproc_throwContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitPreproc_throw(this);
  else
    return visitor->visitChildren(this);
}
TsilParser::PreprocContext* TsilParser::preproc() {
  PreprocContext *_localctx = _tracker.createInstance<PreprocContext>(_ctx, getState());
  enterRule(_localctx, 80, TsilParser::RulePreproc);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(719);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TsilParser::Preproc_ifContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(684);
      match(TsilParser::MOD);
      setState(685);
      match(TsilParser::BRACKET_OPEN);
      setState(686);
      match(TsilParser::KW_IF);
      setState(687);
      antlrcpp::downCast<Preproc_ifContext *>(_localctx)->cond = operation(0);
      setState(688);
      match(TsilParser::BRACKET_CLOSE);
      setState(692);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(689);
          body_element(); 
        }
        setState(694);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      }
      setState(705);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx)) {
      case 1: {
        setState(695);
        match(TsilParser::MOD);
        setState(696);
        match(TsilParser::BRACKET_OPEN);
        setState(697);
        match(TsilParser::KW_ELSE);
        setState(698);
        match(TsilParser::BRACKET_CLOSE);
        setState(702);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(699);
            body_element(); 
          }
          setState(704);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
        }
        break;
      }

      default:
        break;
      }
      setState(707);
      match(TsilParser::MOD);
      setState(708);
      match(TsilParser::BRACKET_OPEN);
      setState(709);
      match(TsilParser::DIVIDE);
      setState(710);
      match(TsilParser::KW_IF);
      setState(711);
      match(TsilParser::BRACKET_CLOSE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TsilParser::Preproc_throwContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(713);
      match(TsilParser::MOD);
      setState(714);
      match(TsilParser::BRACKET_OPEN);
      setState(715);
      match(TsilParser::KW_THROW);
      setState(716);
      antlrcpp::downCast<Preproc_throwContext *>(_localctx)->cond = operation(0);
      setState(717);
      match(TsilParser::BRACKET_CLOSE);
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

//----------------- TakeContext ------------------------------------------------------------------

TsilParser::TakeContext::TakeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::TakeContext::KW_IMPORT() {
  return getToken(TsilParser::KW_IMPORT, 0);
}

std::vector<TsilParser::Take_elementContext *> TsilParser::TakeContext::take_element() {
  return getRuleContexts<TsilParser::Take_elementContext>();
}

TsilParser::Take_elementContext* TsilParser::TakeContext::take_element(size_t i) {
  return getRuleContext<TsilParser::Take_elementContext>(i);
}

tree::TerminalNode* TsilParser::TakeContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> TsilParser::TakeContext::DIVIDE() {
  return getTokens(TsilParser::DIVIDE);
}

tree::TerminalNode* TsilParser::TakeContext::DIVIDE(size_t i) {
  return getToken(TsilParser::DIVIDE, i);
}

tree::TerminalNode* TsilParser::TakeContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::TakeContext::DOT() {
  return getToken(TsilParser::DOT, 0);
}


size_t TsilParser::TakeContext::getRuleIndex() const {
  return TsilParser::RuleTake;
}

void TsilParser::TakeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTake(this);
}

void TsilParser::TakeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTake(this);
}


std::any TsilParser::TakeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitTake(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::TakeContext* TsilParser::take() {
  TakeContext *_localctx = _tracker.createInstance<TakeContext>(_ctx, getState());
  enterRule(_localctx, 82, TsilParser::RuleTake);
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
    setState(721);
    match(TsilParser::KW_IMPORT);
    setState(723);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx)) {
    case 1: {
      setState(722);
      antlrcpp::downCast<TakeContext *>(_localctx)->type_id = match(TsilParser::ID);
      break;
    }

    default:
      break;
    }
    setState(727);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::DOT) {
      setState(725);
      antlrcpp::downCast<TakeContext *>(_localctx)->relative = match(TsilParser::DOT);
      setState(726);
      match(TsilParser::DIVIDE);
    }
    setState(729);
    take_element();
    setState(734);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TsilParser::DIVIDE) {
      setState(730);
      match(TsilParser::DIVIDE);
      setState(731);
      take_element();
      setState(736);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(737);
    match(TsilParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Take_elementContext ------------------------------------------------------------------

TsilParser::Take_elementContext::Take_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Take_elementContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::Take_elementContext::STRING() {
  return getToken(TsilParser::STRING, 0);
}


size_t TsilParser::Take_elementContext::getRuleIndex() const {
  return TsilParser::RuleTake_element;
}

void TsilParser::Take_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTake_element(this);
}

void TsilParser::Take_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTake_element(this);
}


std::any TsilParser::Take_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitTake_element(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Take_elementContext* TsilParser::take_element() {
  Take_elementContext *_localctx = _tracker.createInstance<Take_elementContext>(_ctx, getState());
  enterRule(_localctx, 84, TsilParser::RuleTake_element);
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
    setState(739);
    _la = _input->LA(1);
    if (!(_la == TsilParser::ID

    || _la == TsilParser::STRING)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
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
    case 2: return atomSempred(antlrcpp::downCast<AtomContext *>(context), predicateIndex);
    case 4: return operationSempred(antlrcpp::downCast<OperationContext *>(context), predicateIndex);
    case 36: return simple_typeSempred(antlrcpp::downCast<Simple_typeContext *>(context), predicateIndex);
    case 37: return single_typeSempred(antlrcpp::downCast<Single_typeContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TsilParser::atomSempred(AtomContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);
    case 3: return precpred(_ctx, 2);
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool TsilParser::operationSempred(OperationContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 20);
    case 6: return precpred(_ctx, 19);
    case 7: return precpred(_ctx, 18);
    case 8: return precpred(_ctx, 17);
    case 9: return precpred(_ctx, 16);
    case 10: return precpred(_ctx, 15);
    case 11: return precpred(_ctx, 14);
    case 12: return precpred(_ctx, 13);
    case 13: return precpred(_ctx, 12);
    case 14: return precpred(_ctx, 11);
    case 15: return precpred(_ctx, 10);
    case 16: return precpred(_ctx, 9);
    case 17: return precpred(_ctx, 8);
    case 18: return precpred(_ctx, 7);
    case 19: return precpred(_ctx, 6);
    case 20: return precpred(_ctx, 5);
    case 21: return precpred(_ctx, 4);
    case 22: return precpred(_ctx, 3);
    case 23: return precpred(_ctx, 2);
    case 24: return precpred(_ctx, 1);
    case 25: return precpred(_ctx, 25);

  default:
    break;
  }
  return true;
}

bool TsilParser::simple_typeSempred(Simple_typeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 26: return precpred(_ctx, 4);
    case 27: return precpred(_ctx, 3);
    case 28: return precpred(_ctx, 2);
    case 29: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool TsilParser::single_typeSempred(Single_typeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 30: return precpred(_ctx, 3);

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
