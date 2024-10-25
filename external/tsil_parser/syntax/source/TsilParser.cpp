
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
      "if", "while", "exec", "body", "body_element", "return", "simple_type", 
      "single_type", "type", "param"
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
  	4,1,67,641,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,1,0,1,0,1,0,1,1,5,1,83,8,1,10,1,12,1,
  	86,9,1,1,2,1,2,1,2,1,2,1,2,1,2,3,2,94,8,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,5,2,105,8,2,10,2,12,2,108,9,2,3,2,110,8,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,126,8,2,10,2,12,2,129,9,2,3,2,
  	131,8,2,1,2,5,2,134,8,2,10,2,12,2,137,9,2,1,3,1,3,3,3,141,8,3,1,4,1,4,
  	1,4,3,4,146,8,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,158,8,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,3,4,236,8,4,5,4,238,8,4,10,4,12,4,241,9,4,1,5,1,
  	5,1,5,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,
  	10,1,11,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,15,1,15,1,
  	15,1,15,1,15,1,15,5,15,279,8,15,10,15,12,15,282,9,15,1,15,3,15,285,8,
  	15,3,15,287,8,15,1,15,1,15,3,15,291,8,15,1,16,1,16,3,16,295,8,16,1,16,
  	1,16,3,16,299,8,16,1,17,1,17,1,17,1,17,5,17,305,8,17,10,17,12,17,308,
  	9,17,1,17,3,17,311,8,17,3,17,313,8,17,1,17,1,17,1,18,1,18,1,18,1,18,1,
  	18,1,18,5,18,323,8,18,10,18,12,18,326,9,18,1,18,1,18,3,18,330,8,18,1,
  	18,1,18,1,18,5,18,335,8,18,10,18,12,18,338,9,18,1,18,3,18,341,8,18,1,
  	19,1,19,1,19,1,20,1,20,1,20,3,20,349,8,20,1,20,1,20,1,20,1,20,1,20,1,
  	20,5,20,357,8,20,10,20,12,20,360,9,20,1,20,1,20,3,20,364,8,20,1,20,1,
  	20,1,20,1,20,5,20,370,8,20,10,20,12,20,373,9,20,3,20,375,8,20,1,20,1,
  	20,1,20,3,20,380,8,20,1,20,1,20,3,20,384,8,20,1,21,1,21,3,21,388,8,21,
  	1,21,1,21,1,21,1,21,3,21,394,8,21,1,21,1,21,1,21,3,21,399,8,21,3,21,401,
  	8,21,1,21,1,21,1,22,1,22,1,22,1,22,3,22,409,8,22,1,22,1,22,1,23,1,23,
  	1,23,1,23,1,23,1,23,5,23,419,8,23,10,23,12,23,422,9,23,1,23,1,23,3,23,
  	426,8,23,1,23,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,24,5,24,438,8,
  	24,10,24,12,24,441,9,24,1,24,1,24,3,24,445,8,24,1,24,1,24,1,24,1,24,1,
  	24,1,24,1,24,1,25,1,25,1,25,3,25,457,8,25,1,26,1,26,1,26,1,26,1,26,1,
  	26,3,26,465,8,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,3,27,476,
  	8,27,1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,28,1,28,3,28,487,8,28,1,28,
  	1,28,1,29,1,29,1,29,1,29,1,29,1,29,3,29,497,8,29,3,29,499,8,29,1,30,1,
  	30,1,30,1,30,1,31,1,31,1,31,1,31,1,32,1,32,5,32,511,8,32,10,32,12,32,
  	514,9,32,1,32,1,32,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,
  	1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,3,33,537,8,33,1,34,1,34,
  	1,34,3,34,542,8,34,1,34,1,34,1,35,1,35,1,35,1,35,1,35,1,35,1,35,1,35,
  	1,35,1,35,1,35,1,35,5,35,558,8,35,10,35,12,35,561,9,35,1,35,1,35,1,35,
  	1,35,1,35,1,35,1,35,1,35,1,35,5,35,572,8,35,10,35,12,35,575,9,35,1,36,
  	1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,4,36,588,8,36,11,36,
  	12,36,589,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,5,36,601,8,36,
  	10,36,12,36,604,9,36,1,36,1,36,1,36,1,36,1,36,3,36,611,8,36,1,36,1,36,
  	1,36,1,36,5,36,617,8,36,10,36,12,36,620,9,36,1,37,1,37,1,37,1,37,1,37,
  	1,37,1,37,1,37,4,37,630,8,37,11,37,12,37,631,3,37,634,8,37,1,38,1,38,
  	1,38,3,38,639,8,38,1,38,0,4,4,8,70,72,39,0,2,4,6,8,10,12,14,16,18,20,
  	22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,
  	68,70,72,74,76,0,0,714,0,78,1,0,0,0,2,84,1,0,0,0,4,93,1,0,0,0,6,140,1,
  	0,0,0,8,157,1,0,0,0,10,242,1,0,0,0,12,245,1,0,0,0,14,248,1,0,0,0,16,252,
  	1,0,0,0,18,255,1,0,0,0,20,258,1,0,0,0,22,261,1,0,0,0,24,264,1,0,0,0,26,
  	267,1,0,0,0,28,270,1,0,0,0,30,290,1,0,0,0,32,294,1,0,0,0,34,300,1,0,0,
  	0,36,316,1,0,0,0,38,342,1,0,0,0,40,348,1,0,0,0,42,387,1,0,0,0,44,404,
  	1,0,0,0,46,412,1,0,0,0,48,431,1,0,0,0,50,453,1,0,0,0,52,458,1,0,0,0,54,
  	468,1,0,0,0,56,479,1,0,0,0,58,490,1,0,0,0,60,500,1,0,0,0,62,504,1,0,0,
  	0,64,508,1,0,0,0,66,536,1,0,0,0,68,538,1,0,0,0,70,545,1,0,0,0,72,610,
  	1,0,0,0,74,633,1,0,0,0,76,635,1,0,0,0,78,79,3,2,1,0,79,80,5,0,0,1,80,
  	1,1,0,0,0,81,83,3,66,33,0,82,81,1,0,0,0,83,86,1,0,0,0,84,82,1,0,0,0,84,
  	85,1,0,0,0,85,3,1,0,0,0,86,84,1,0,0,0,87,88,6,2,-1,0,88,89,5,41,0,0,89,
  	90,3,30,15,0,90,91,5,42,0,0,91,94,1,0,0,0,92,94,5,62,0,0,93,87,1,0,0,
  	0,93,92,1,0,0,0,94,135,1,0,0,0,95,96,10,5,0,0,96,97,5,46,0,0,97,98,5,
  	46,0,0,98,134,5,62,0,0,99,100,10,4,0,0,100,109,5,31,0,0,101,106,3,74,
  	37,0,102,103,5,51,0,0,103,105,3,74,37,0,104,102,1,0,0,0,105,108,1,0,0,
  	0,106,104,1,0,0,0,106,107,1,0,0,0,107,110,1,0,0,0,108,106,1,0,0,0,109,
  	101,1,0,0,0,109,110,1,0,0,0,110,111,1,0,0,0,111,134,5,30,0,0,112,113,
  	10,3,0,0,113,114,5,32,0,0,114,134,5,62,0,0,115,116,10,2,0,0,116,117,5,
  	43,0,0,117,118,3,30,15,0,118,119,5,44,0,0,119,134,1,0,0,0,120,121,10,
  	1,0,0,121,130,5,41,0,0,122,127,3,6,3,0,123,124,5,51,0,0,124,126,3,6,3,
  	0,125,123,1,0,0,0,126,129,1,0,0,0,127,125,1,0,0,0,127,128,1,0,0,0,128,
  	131,1,0,0,0,129,127,1,0,0,0,130,122,1,0,0,0,130,131,1,0,0,0,131,132,1,
  	0,0,0,132,134,5,42,0,0,133,95,1,0,0,0,133,99,1,0,0,0,133,112,1,0,0,0,
  	133,115,1,0,0,0,133,120,1,0,0,0,134,137,1,0,0,0,135,133,1,0,0,0,135,136,
  	1,0,0,0,136,5,1,0,0,0,137,135,1,0,0,0,138,141,3,30,15,0,139,141,3,34,
  	17,0,140,138,1,0,0,0,140,139,1,0,0,0,141,7,1,0,0,0,142,143,6,4,-1,0,143,
  	158,5,55,0,0,144,146,5,62,0,0,145,144,1,0,0,0,145,146,1,0,0,0,146,147,
  	1,0,0,0,147,158,5,63,0,0,148,158,3,4,2,0,149,150,5,50,0,0,150,158,3,8,
  	4,25,151,152,5,47,0,0,152,158,3,8,4,24,153,154,5,33,0,0,154,158,3,8,4,
  	23,155,156,5,34,0,0,156,158,3,8,4,22,157,142,1,0,0,0,157,145,1,0,0,0,
  	157,148,1,0,0,0,157,149,1,0,0,0,157,151,1,0,0,0,157,153,1,0,0,0,157,155,
  	1,0,0,0,158,239,1,0,0,0,159,160,10,21,0,0,160,161,5,35,0,0,161,238,3,
  	8,4,22,162,163,10,20,0,0,163,164,5,36,0,0,164,238,3,8,4,21,165,166,10,
  	19,0,0,166,167,5,37,0,0,167,238,3,8,4,20,168,169,10,18,0,0,169,170,5,
  	33,0,0,170,238,3,8,4,19,171,172,10,17,0,0,172,173,5,34,0,0,173,238,3,
  	8,4,18,174,175,10,16,0,0,175,176,3,10,5,0,176,177,3,8,4,17,177,238,1,
  	0,0,0,178,179,10,15,0,0,179,180,3,12,6,0,180,181,3,8,4,16,181,238,1,0,
  	0,0,182,183,10,14,0,0,183,184,3,14,7,0,184,185,3,8,4,15,185,238,1,0,0,
  	0,186,187,10,13,0,0,187,188,5,31,0,0,188,238,3,8,4,14,189,190,10,12,0,
  	0,190,191,3,16,8,0,191,192,3,8,4,13,192,238,1,0,0,0,193,194,10,11,0,0,
  	194,195,5,30,0,0,195,238,3,8,4,12,196,197,10,10,0,0,197,198,3,18,9,0,
  	198,199,3,8,4,11,199,238,1,0,0,0,200,201,10,9,0,0,201,202,3,20,10,0,202,
  	203,3,8,4,10,203,238,1,0,0,0,204,205,10,8,0,0,205,206,3,22,11,0,206,207,
  	3,8,4,9,207,238,1,0,0,0,208,209,10,7,0,0,209,210,5,39,0,0,210,238,3,8,
  	4,8,211,212,10,6,0,0,212,213,5,38,0,0,213,238,3,8,4,7,214,215,10,5,0,
  	0,215,216,5,40,0,0,216,238,3,8,4,6,217,218,10,4,0,0,218,219,3,24,12,0,
  	219,220,3,8,4,5,220,238,1,0,0,0,221,222,10,3,0,0,222,223,3,26,13,0,223,
  	224,3,8,4,4,224,238,1,0,0,0,225,226,10,1,0,0,226,227,5,45,0,0,227,228,
  	3,8,4,0,228,229,5,46,0,0,229,230,3,8,4,2,230,238,1,0,0,0,231,232,10,2,
  	0,0,232,235,5,10,0,0,233,236,3,74,37,0,234,236,5,1,0,0,235,233,1,0,0,
  	0,235,234,1,0,0,0,236,238,1,0,0,0,237,159,1,0,0,0,237,162,1,0,0,0,237,
  	165,1,0,0,0,237,168,1,0,0,0,237,171,1,0,0,0,237,174,1,0,0,0,237,178,1,
  	0,0,0,237,182,1,0,0,0,237,186,1,0,0,0,237,189,1,0,0,0,237,193,1,0,0,0,
  	237,196,1,0,0,0,237,200,1,0,0,0,237,204,1,0,0,0,237,208,1,0,0,0,237,211,
  	1,0,0,0,237,214,1,0,0,0,237,217,1,0,0,0,237,221,1,0,0,0,237,225,1,0,0,
  	0,237,231,1,0,0,0,238,241,1,0,0,0,239,237,1,0,0,0,239,240,1,0,0,0,240,
  	9,1,0,0,0,241,239,1,0,0,0,242,243,5,31,0,0,243,244,5,31,0,0,244,11,1,
  	0,0,0,245,246,5,30,0,0,246,247,5,30,0,0,247,13,1,0,0,0,248,249,5,30,0,
  	0,249,250,5,30,0,0,250,251,5,30,0,0,251,15,1,0,0,0,252,253,5,31,0,0,253,
  	254,5,29,0,0,254,17,1,0,0,0,255,256,5,30,0,0,256,257,5,29,0,0,257,19,
  	1,0,0,0,258,259,5,29,0,0,259,260,5,29,0,0,260,21,1,0,0,0,261,262,5,50,
  	0,0,262,263,5,29,0,0,263,23,1,0,0,0,264,265,5,39,0,0,265,266,5,39,0,0,
  	266,25,1,0,0,0,267,268,5,40,0,0,268,269,5,40,0,0,269,27,1,0,0,0,270,271,
  	5,62,0,0,271,29,1,0,0,0,272,291,3,8,4,0,273,274,3,70,35,0,274,286,5,53,
  	0,0,275,280,3,32,16,0,276,277,5,51,0,0,277,279,3,32,16,0,278,276,1,0,
  	0,0,279,282,1,0,0,0,280,278,1,0,0,0,280,281,1,0,0,0,281,284,1,0,0,0,282,
  	280,1,0,0,0,283,285,5,51,0,0,284,283,1,0,0,0,284,285,1,0,0,0,285,287,
  	1,0,0,0,286,275,1,0,0,0,286,287,1,0,0,0,287,288,1,0,0,0,288,289,5,54,
  	0,0,289,291,1,0,0,0,290,272,1,0,0,0,290,273,1,0,0,0,291,31,1,0,0,0,292,
  	293,5,62,0,0,293,295,5,29,0,0,294,292,1,0,0,0,294,295,1,0,0,0,295,298,
  	1,0,0,0,296,299,3,30,15,0,297,299,3,34,17,0,298,296,1,0,0,0,298,297,1,
  	0,0,0,299,33,1,0,0,0,300,312,5,53,0,0,301,306,3,32,16,0,302,303,5,51,
  	0,0,303,305,3,32,16,0,304,302,1,0,0,0,305,308,1,0,0,0,306,304,1,0,0,0,
  	306,307,1,0,0,0,307,310,1,0,0,0,308,306,1,0,0,0,309,311,5,51,0,0,310,
  	309,1,0,0,0,310,311,1,0,0,0,311,313,1,0,0,0,312,301,1,0,0,0,312,313,1,
  	0,0,0,313,314,1,0,0,0,314,315,5,54,0,0,315,35,1,0,0,0,316,317,5,8,0,0,
  	317,329,5,62,0,0,318,319,5,31,0,0,319,324,3,28,14,0,320,321,5,51,0,0,
  	321,323,3,28,14,0,322,320,1,0,0,0,323,326,1,0,0,0,324,322,1,0,0,0,324,
  	325,1,0,0,0,325,327,1,0,0,0,326,324,1,0,0,0,327,328,5,30,0,0,328,330,
  	1,0,0,0,329,318,1,0,0,0,329,330,1,0,0,0,330,340,1,0,0,0,331,341,5,52,
  	0,0,332,336,5,53,0,0,333,335,3,38,19,0,334,333,1,0,0,0,335,338,1,0,0,
  	0,336,334,1,0,0,0,336,337,1,0,0,0,337,339,1,0,0,0,338,336,1,0,0,0,339,
  	341,5,54,0,0,340,331,1,0,0,0,340,332,1,0,0,0,341,37,1,0,0,0,342,343,3,
  	76,38,0,343,344,5,52,0,0,344,39,1,0,0,0,345,349,5,16,0,0,346,349,5,18,
  	0,0,347,349,5,17,0,0,348,345,1,0,0,0,348,346,1,0,0,0,348,347,1,0,0,0,
  	348,349,1,0,0,0,349,350,1,0,0,0,350,351,5,2,0,0,351,363,5,62,0,0,352,
  	353,5,31,0,0,353,358,3,28,14,0,354,355,5,51,0,0,355,357,3,28,14,0,356,
  	354,1,0,0,0,357,360,1,0,0,0,358,356,1,0,0,0,358,359,1,0,0,0,359,361,1,
  	0,0,0,360,358,1,0,0,0,361,362,5,30,0,0,362,364,1,0,0,0,363,352,1,0,0,
  	0,363,364,1,0,0,0,364,365,1,0,0,0,365,374,5,41,0,0,366,371,3,76,38,0,
  	367,368,5,51,0,0,368,370,3,76,38,0,369,367,1,0,0,0,370,373,1,0,0,0,371,
  	369,1,0,0,0,371,372,1,0,0,0,372,375,1,0,0,0,373,371,1,0,0,0,374,366,1,
  	0,0,0,374,375,1,0,0,0,375,376,1,0,0,0,376,379,5,42,0,0,377,378,5,46,0,
  	0,378,380,3,74,37,0,379,377,1,0,0,0,379,380,1,0,0,0,380,383,1,0,0,0,381,
  	384,5,52,0,0,382,384,3,64,32,0,383,381,1,0,0,0,383,382,1,0,0,0,384,41,
  	1,0,0,0,385,388,5,22,0,0,386,388,5,23,0,0,387,385,1,0,0,0,387,386,1,0,
  	0,0,387,388,1,0,0,0,388,389,1,0,0,0,389,390,5,1,0,0,390,393,5,62,0,0,
  	391,392,5,46,0,0,392,394,3,74,37,0,393,391,1,0,0,0,393,394,1,0,0,0,394,
  	400,1,0,0,0,395,398,5,29,0,0,396,399,3,30,15,0,397,399,3,34,17,0,398,
  	396,1,0,0,0,398,397,1,0,0,0,399,401,1,0,0,0,400,395,1,0,0,0,400,401,1,
  	0,0,0,401,402,1,0,0,0,402,403,5,52,0,0,403,43,1,0,0,0,404,405,5,62,0,
  	0,405,408,5,29,0,0,406,409,3,30,15,0,407,409,3,34,17,0,408,406,1,0,0,
  	0,408,407,1,0,0,0,409,410,1,0,0,0,410,411,5,52,0,0,411,45,1,0,0,0,412,
  	413,5,24,0,0,413,425,5,62,0,0,414,415,5,31,0,0,415,420,3,28,14,0,416,
  	417,5,51,0,0,417,419,3,28,14,0,418,416,1,0,0,0,419,422,1,0,0,0,420,418,
  	1,0,0,0,420,421,1,0,0,0,421,423,1,0,0,0,422,420,1,0,0,0,423,424,5,30,
  	0,0,424,426,1,0,0,0,425,414,1,0,0,0,425,426,1,0,0,0,426,427,1,0,0,0,427,
  	428,5,29,0,0,428,429,3,30,15,0,429,430,5,52,0,0,430,47,1,0,0,0,431,432,
  	5,24,0,0,432,444,5,62,0,0,433,434,5,31,0,0,434,439,3,28,14,0,435,436,
  	5,51,0,0,436,438,3,28,14,0,437,435,1,0,0,0,438,441,1,0,0,0,439,437,1,
  	0,0,0,439,440,1,0,0,0,440,442,1,0,0,0,441,439,1,0,0,0,442,443,5,30,0,
  	0,443,445,1,0,0,0,444,433,1,0,0,0,444,445,1,0,0,0,445,446,1,0,0,0,446,
  	447,5,41,0,0,447,448,5,42,0,0,448,449,5,29,0,0,449,450,5,30,0,0,450,451,
  	3,30,15,0,451,452,5,52,0,0,452,49,1,0,0,0,453,454,5,11,0,0,454,456,5,
  	62,0,0,455,457,3,64,32,0,456,455,1,0,0,0,456,457,1,0,0,0,457,51,1,0,0,
  	0,458,459,3,4,2,0,459,460,5,32,0,0,460,461,5,62,0,0,461,464,5,29,0,0,
  	462,465,3,30,15,0,463,465,3,34,17,0,464,462,1,0,0,0,464,463,1,0,0,0,465,
  	466,1,0,0,0,466,467,5,52,0,0,467,53,1,0,0,0,468,469,3,4,2,0,469,470,5,
  	43,0,0,470,471,3,30,15,0,471,472,5,44,0,0,472,475,5,29,0,0,473,476,3,
  	30,15,0,474,476,3,34,17,0,475,473,1,0,0,0,475,474,1,0,0,0,476,477,1,0,
  	0,0,477,478,5,52,0,0,478,55,1,0,0,0,479,480,3,4,2,0,480,481,5,46,0,0,
  	481,482,5,46,0,0,482,483,5,62,0,0,483,486,5,29,0,0,484,487,3,30,15,0,
  	485,487,3,34,17,0,486,484,1,0,0,0,486,485,1,0,0,0,487,488,1,0,0,0,488,
  	489,5,52,0,0,489,57,1,0,0,0,490,491,5,3,0,0,491,492,3,8,4,0,492,498,3,
  	64,32,0,493,496,5,4,0,0,494,497,3,64,32,0,495,497,3,58,29,0,496,494,1,
  	0,0,0,496,495,1,0,0,0,497,499,1,0,0,0,498,493,1,0,0,0,498,499,1,0,0,0,
  	499,59,1,0,0,0,500,501,5,5,0,0,501,502,3,8,4,0,502,503,3,64,32,0,503,
  	61,1,0,0,0,504,505,5,25,0,0,505,506,3,64,32,0,506,507,5,52,0,0,507,63,
  	1,0,0,0,508,512,5,53,0,0,509,511,3,66,33,0,510,509,1,0,0,0,511,514,1,
  	0,0,0,512,510,1,0,0,0,512,513,1,0,0,0,513,515,1,0,0,0,514,512,1,0,0,0,
  	515,516,5,54,0,0,516,65,1,0,0,0,517,537,3,36,18,0,518,537,3,40,20,0,519,
  	537,3,42,21,0,520,537,3,44,22,0,521,537,3,52,26,0,522,537,3,56,28,0,523,
  	537,3,54,27,0,524,537,3,46,23,0,525,537,3,48,24,0,526,537,3,50,25,0,527,
  	537,3,58,29,0,528,537,3,60,30,0,529,530,3,30,15,0,530,531,5,52,0,0,531,
  	537,1,0,0,0,532,537,3,64,32,0,533,537,3,62,31,0,534,537,3,68,34,0,535,
  	537,5,52,0,0,536,517,1,0,0,0,536,518,1,0,0,0,536,519,1,0,0,0,536,520,
  	1,0,0,0,536,521,1,0,0,0,536,522,1,0,0,0,536,523,1,0,0,0,536,524,1,0,0,
  	0,536,525,1,0,0,0,536,526,1,0,0,0,536,527,1,0,0,0,536,528,1,0,0,0,536,
  	529,1,0,0,0,536,532,1,0,0,0,536,533,1,0,0,0,536,534,1,0,0,0,536,535,1,
  	0,0,0,537,67,1,0,0,0,538,541,5,6,0,0,539,542,3,30,15,0,540,542,3,34,17,
  	0,541,539,1,0,0,0,541,540,1,0,0,0,541,542,1,0,0,0,542,543,1,0,0,0,543,
  	544,5,52,0,0,544,69,1,0,0,0,545,546,6,35,-1,0,546,547,5,62,0,0,547,573,
  	1,0,0,0,548,549,10,4,0,0,549,550,5,46,0,0,550,551,5,46,0,0,551,572,5,
  	62,0,0,552,553,10,3,0,0,553,554,5,31,0,0,554,559,3,74,37,0,555,556,5,
  	51,0,0,556,558,3,74,37,0,557,555,1,0,0,0,558,561,1,0,0,0,559,557,1,0,
  	0,0,559,560,1,0,0,0,560,562,1,0,0,0,561,559,1,0,0,0,562,563,5,30,0,0,
  	563,572,1,0,0,0,564,565,10,2,0,0,565,566,5,32,0,0,566,572,5,62,0,0,567,
  	568,10,1,0,0,568,569,5,43,0,0,569,570,5,55,0,0,570,572,5,44,0,0,571,548,
  	1,0,0,0,571,552,1,0,0,0,571,564,1,0,0,0,571,567,1,0,0,0,572,575,1,0,0,
  	0,573,571,1,0,0,0,573,574,1,0,0,0,574,71,1,0,0,0,575,573,1,0,0,0,576,
  	577,6,36,-1,0,577,611,3,70,35,0,578,579,5,41,0,0,579,580,5,42,0,0,580,
  	581,5,34,0,0,581,582,5,30,0,0,582,611,3,74,37,0,583,584,5,41,0,0,584,
  	587,3,74,37,0,585,586,5,51,0,0,586,588,3,74,37,0,587,585,1,0,0,0,588,
  	589,1,0,0,0,589,587,1,0,0,0,589,590,1,0,0,0,590,591,1,0,0,0,591,592,5,
  	42,0,0,592,593,5,34,0,0,593,594,5,30,0,0,594,595,3,74,37,0,595,611,1,
  	0,0,0,596,597,5,41,0,0,597,602,3,76,38,0,598,599,5,51,0,0,599,601,3,76,
  	38,0,600,598,1,0,0,0,601,604,1,0,0,0,602,600,1,0,0,0,602,603,1,0,0,0,
  	603,605,1,0,0,0,604,602,1,0,0,0,605,606,5,42,0,0,606,607,5,34,0,0,607,
  	608,5,30,0,0,608,609,3,74,37,0,609,611,1,0,0,0,610,576,1,0,0,0,610,578,
  	1,0,0,0,610,583,1,0,0,0,610,596,1,0,0,0,611,618,1,0,0,0,612,613,10,3,
  	0,0,613,614,5,34,0,0,614,615,5,30,0,0,615,617,3,74,37,0,616,612,1,0,0,
  	0,617,620,1,0,0,0,618,616,1,0,0,0,618,619,1,0,0,0,619,73,1,0,0,0,620,
  	618,1,0,0,0,621,622,5,41,0,0,622,623,3,74,37,0,623,624,5,42,0,0,624,634,
  	1,0,0,0,625,634,3,72,36,0,626,629,3,72,36,0,627,628,5,40,0,0,628,630,
  	3,72,36,0,629,627,1,0,0,0,630,631,1,0,0,0,631,629,1,0,0,0,631,632,1,0,
  	0,0,632,634,1,0,0,0,633,621,1,0,0,0,633,625,1,0,0,0,633,626,1,0,0,0,634,
  	75,1,0,0,0,635,638,5,62,0,0,636,637,5,46,0,0,637,639,3,74,37,0,638,636,
  	1,0,0,0,638,639,1,0,0,0,639,77,1,0,0,0,62,84,93,106,109,127,130,133,135,
  	140,145,157,235,237,239,280,284,286,290,294,298,306,310,312,324,329,336,
  	340,348,358,363,371,374,379,383,387,393,398,400,408,420,425,439,444,456,
  	464,475,486,496,498,512,536,541,559,571,573,589,602,610,618,631,633,638
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
    setState(78);
    antlrcpp::downCast<FileContext *>(_localctx)->f_program = program();
    setState(79);
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
    setState(84);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -4560877560274679442) != 0)) {
      setState(81);
      body_element();
      setState(86);
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
    setState(93);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::PAREN_OPEN: {
        _localctx = _tracker.createInstance<Atom_nestedContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(88);
        match(TsilParser::PAREN_OPEN);
        setState(89);
        expr();
        setState(90);
        match(TsilParser::PAREN_CLOSE);
        break;
      }

      case TsilParser::ID: {
        _localctx = _tracker.createInstance<Atom_subjectContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(92);
        antlrcpp::downCast<Atom_subjectContext *>(_localctx)->id = match(TsilParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(135);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(133);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Atom_section_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(95);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(96);
          match(TsilParser::COLON);
          setState(97);
          match(TsilParser::COLON);
          setState(98);
          antlrcpp::downCast<Atom_section_getContext *>(_localctx)->id = match(TsilParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Atom_template_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(99);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(100);
          match(TsilParser::LESSER);
          setState(109);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == TsilParser::PAREN_OPEN

          || _la == TsilParser::ID) {
            setState(101);
            type();
            setState(106);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == TsilParser::COMA) {
              setState(102);
              match(TsilParser::COMA);
              setState(103);
              type();
              setState(108);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(111);
          match(TsilParser::GREATER);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Atom_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(112);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(113);
          match(TsilParser::DOT);
          setState(114);
          antlrcpp::downCast<Atom_getContext *>(_localctx)->id = match(TsilParser::ID);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Atom_position_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(115);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(116);
          match(TsilParser::BRACKET_OPEN);
          setState(117);
          antlrcpp::downCast<Atom_position_getContext *>(_localctx)->position = expr();
          setState(118);
          match(TsilParser::BRACKET_CLOSE);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Atom_callContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(120);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(121);
          match(TsilParser::PAREN_OPEN);
          setState(130);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & -4565381159965425664) != 0)) {
            setState(122);
            call_arg();
            setState(127);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == TsilParser::COMA) {
              setState(123);
              match(TsilParser::COMA);
              setState(124);
              call_arg();
              setState(129);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(132);
          match(TsilParser::PAREN_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(137);
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
    setState(140);
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
        setState(138);
        expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        enterOuterAlt(_localctx, 2);
        setState(139);
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
    setState(157);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Operation_numberContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(143);
      match(TsilParser::NUMBER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Operation_stringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(145);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TsilParser::ID) {
        setState(144);
        antlrcpp::downCast<Operation_stringContext *>(_localctx)->tt = match(TsilParser::ID);
      }
      setState(147);
      match(TsilParser::STRING);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Operation_atomContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(148);
      atom(0);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Operation_pre_notContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(149);
      antlrcpp::downCast<Operation_pre_notContext *>(_localctx)->op = match(TsilParser::EXCLAMATION);
      setState(150);
      antlrcpp::downCast<Operation_pre_notContext *>(_localctx)->right = operation(25);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Operation_pre_bw_notContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(151);
      antlrcpp::downCast<Operation_pre_bw_notContext *>(_localctx)->op = match(TsilParser::TILDA);
      setState(152);
      antlrcpp::downCast<Operation_pre_bw_notContext *>(_localctx)->right = operation(24);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<Operation_pre_plusContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(153);
      antlrcpp::downCast<Operation_pre_plusContext *>(_localctx)->op = match(TsilParser::PLUS);
      setState(154);
      antlrcpp::downCast<Operation_pre_plusContext *>(_localctx)->right = operation(23);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<Operation_pre_minusContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(155);
      antlrcpp::downCast<Operation_pre_minusContext *>(_localctx)->op = match(TsilParser::MINUS);
      setState(156);
      antlrcpp::downCast<Operation_pre_minusContext *>(_localctx)->right = operation(22);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(239);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(237);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Operation_mulContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(159);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(160);
          antlrcpp::downCast<Operation_mulContext *>(_localctx)->op = match(TsilParser::MULTIPLY);
          setState(161);
          antlrcpp::downCast<Operation_mulContext *>(_localctx)->right = operation(22);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Operation_divContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(162);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(163);
          antlrcpp::downCast<Operation_divContext *>(_localctx)->op = match(TsilParser::DIVIDE);
          setState(164);
          antlrcpp::downCast<Operation_divContext *>(_localctx)->right = operation(21);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Operation_modContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(165);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(166);
          antlrcpp::downCast<Operation_modContext *>(_localctx)->op = match(TsilParser::MOD);
          setState(167);
          antlrcpp::downCast<Operation_modContext *>(_localctx)->right = operation(20);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Operation_addContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(168);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(169);
          antlrcpp::downCast<Operation_addContext *>(_localctx)->op = match(TsilParser::PLUS);
          setState(170);
          antlrcpp::downCast<Operation_addContext *>(_localctx)->right = operation(19);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Operation_subContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(171);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(172);
          antlrcpp::downCast<Operation_subContext *>(_localctx)->op = match(TsilParser::MINUS);
          setState(173);
          antlrcpp::downCast<Operation_subContext *>(_localctx)->right = operation(18);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<Operation_lshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(174);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(175);
          antlrcpp::downCast<Operation_lshiftContext *>(_localctx)->op = op_lshift();
          setState(176);
          antlrcpp::downCast<Operation_lshiftContext *>(_localctx)->right = operation(17);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<Operation_rshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(178);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(179);
          antlrcpp::downCast<Operation_rshiftContext *>(_localctx)->op = op_rshift();
          setState(180);
          antlrcpp::downCast<Operation_rshiftContext *>(_localctx)->right = operation(16);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<Operation_urshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(182);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(183);
          antlrcpp::downCast<Operation_urshiftContext *>(_localctx)->op = op_urshift();
          setState(184);
          antlrcpp::downCast<Operation_urshiftContext *>(_localctx)->right = operation(15);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<Operation_ltContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(186);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(187);
          antlrcpp::downCast<Operation_ltContext *>(_localctx)->op = match(TsilParser::LESSER);
          setState(188);
          antlrcpp::downCast<Operation_ltContext *>(_localctx)->right = operation(14);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<Operation_lteContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(189);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(190);
          antlrcpp::downCast<Operation_lteContext *>(_localctx)->op = op_lte();
          setState(191);
          antlrcpp::downCast<Operation_lteContext *>(_localctx)->right = operation(13);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<Operation_gtContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(193);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(194);
          antlrcpp::downCast<Operation_gtContext *>(_localctx)->op = match(TsilParser::GREATER);
          setState(195);
          antlrcpp::downCast<Operation_gtContext *>(_localctx)->right = operation(12);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<Operation_gteContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(196);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(197);
          antlrcpp::downCast<Operation_gteContext *>(_localctx)->op = op_gte();
          setState(198);
          antlrcpp::downCast<Operation_gteContext *>(_localctx)->right = operation(11);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<Operation_eqContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(200);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(201);
          antlrcpp::downCast<Operation_eqContext *>(_localctx)->op = op_eq();
          setState(202);
          antlrcpp::downCast<Operation_eqContext *>(_localctx)->right = operation(10);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<Operation_neqContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(204);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(205);
          antlrcpp::downCast<Operation_neqContext *>(_localctx)->op = op_neq();
          setState(206);
          antlrcpp::downCast<Operation_neqContext *>(_localctx)->right = operation(9);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<Operation_andContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(208);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(209);
          antlrcpp::downCast<Operation_andContext *>(_localctx)->op = match(TsilParser::AND);
          setState(210);
          antlrcpp::downCast<Operation_andContext *>(_localctx)->right = operation(8);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<Operation_xorContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(211);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(212);
          antlrcpp::downCast<Operation_xorContext *>(_localctx)->op = match(TsilParser::POWER);
          setState(213);
          antlrcpp::downCast<Operation_xorContext *>(_localctx)->right = operation(7);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<Operation_orContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(214);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(215);
          antlrcpp::downCast<Operation_orContext *>(_localctx)->op = match(TsilParser::OR);
          setState(216);
          antlrcpp::downCast<Operation_orContext *>(_localctx)->right = operation(6);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<Operation_landContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(217);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(218);
          antlrcpp::downCast<Operation_landContext *>(_localctx)->op = op_land();
          setState(219);
          antlrcpp::downCast<Operation_landContext *>(_localctx)->right = operation(5);
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<Operation_lorContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(221);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(222);
          antlrcpp::downCast<Operation_lorContext *>(_localctx)->op = op_lor();
          setState(223);
          antlrcpp::downCast<Operation_lorContext *>(_localctx)->right = operation(4);
          break;
        }

        case 20: {
          auto newContext = _tracker.createInstance<Operation_ternaryContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->cond = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(225);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(226);
          match(TsilParser::QUESTION);
          setState(227);
          antlrcpp::downCast<Operation_ternaryContext *>(_localctx)->ifok = operation(0);
          setState(228);
          match(TsilParser::COLON);
          setState(229);
          antlrcpp::downCast<Operation_ternaryContext *>(_localctx)->ifnot = operation(2);
          break;
        }

        case 21: {
          auto newContext = _tracker.createInstance<Operation_asContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(231);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(232);
          antlrcpp::downCast<Operation_asContext *>(_localctx)->op = match(TsilParser::KW_AS);
          setState(235);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case TsilParser::PAREN_OPEN:
            case TsilParser::ID: {
              setState(233);
              antlrcpp::downCast<Operation_asContext *>(_localctx)->right_type = type();
              break;
            }

            case TsilParser::KW_TSIL: {
              setState(234);
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
      setState(241);
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
    setState(242);
    match(TsilParser::LESSER);
    setState(243);
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
    setState(245);
    match(TsilParser::GREATER);
    setState(246);
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
    setState(248);
    match(TsilParser::GREATER);
    setState(249);
    match(TsilParser::GREATER);
    setState(250);
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
    setState(252);
    match(TsilParser::LESSER);
    setState(253);
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
    setState(255);
    match(TsilParser::GREATER);
    setState(256);
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
    setState(258);
    match(TsilParser::EQUAL);
    setState(259);
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
    setState(261);
    match(TsilParser::EXCLAMATION);
    setState(262);
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
    setState(264);
    match(TsilParser::AND);
    setState(265);
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
    setState(267);
    match(TsilParser::OR);
    setState(268);
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
    setState(270);
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
    setState(290);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TsilParser::Expr_operationContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(272);
      operation(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TsilParser::Expr_objectContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(273);
      simple_type(0);
      setState(274);
      match(TsilParser::QUOTE_OPEN);
      setState(286);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & -4565381159965425664) != 0)) {
        setState(275);
        object_arg();
        setState(280);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(276);
            match(TsilParser::COMA);
            setState(277);
            object_arg(); 
          }
          setState(282);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
        }
        setState(284);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TsilParser::COMA) {
          setState(283);
          match(TsilParser::COMA);
        }
      }
      setState(288);
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
    enterOuterAlt(_localctx, 1);
    setState(294);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(292);
      antlrcpp::downCast<Object_argContext *>(_localctx)->id = match(TsilParser::ID);
      setState(293);
      match(TsilParser::EQUAL);
      break;
    }

    default:
      break;
    }
    setState(298);
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
        setState(296);
        antlrcpp::downCast<Object_argContext *>(_localctx)->value_expr = expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(297);
        antlrcpp::downCast<Object_argContext *>(_localctx)->value_object = typeless_object();
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
    setState(300);
    match(TsilParser::QUOTE_OPEN);
    setState(312);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -4565381159965425664) != 0)) {
      setState(301);
      object_arg();
      setState(306);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(302);
          match(TsilParser::COMA);
          setState(303);
          object_arg(); 
        }
        setState(308);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
      }
      setState(310);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TsilParser::COMA) {
        setState(309);
        match(TsilParser::COMA);
      }
    }
    setState(314);
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
    setState(316);
    match(TsilParser::KW_STRUCT);
    setState(317);
    antlrcpp::downCast<Structure_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(329);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(318);
      match(TsilParser::LESSER);
      setState(319);
      antlrcpp::downCast<Structure_defineContext *>(_localctx)->first_gendef = gendef();
      setState(324);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(320);
        match(TsilParser::COMA);
        setState(321);
        gendef();
        setState(326);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(327);
      match(TsilParser::GREATER);
    }
    setState(340);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::SEMICOLON: {
        setState(331);
        match(TsilParser::SEMICOLON);
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(332);
        match(TsilParser::QUOTE_OPEN);
        setState(336);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == TsilParser::ID) {
          setState(333);
          structure_element();
          setState(338);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(339);
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
    setState(342);
    param();
    setState(343);
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
    setState(348);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(345);
        antlrcpp::downCast<Diia_defineContext *>(_localctx)->extern_ = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(346);
        antlrcpp::downCast<Diia_defineContext *>(_localctx)->local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(347);
        antlrcpp::downCast<Diia_defineContext *>(_localctx)->intern = match(TsilParser::KW_PRIVATE);
        break;
      }

      case TsilParser::KW_DIIA: {
        break;
      }

    default:
      break;
    }
    setState(350);
    match(TsilParser::KW_DIIA);
    setState(351);
    antlrcpp::downCast<Diia_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(363);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(352);
      match(TsilParser::LESSER);
      setState(353);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->first_gendef = gendef();
      setState(358);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(354);
        match(TsilParser::COMA);
        setState(355);
        gendef();
        setState(360);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(361);
      match(TsilParser::GREATER);
    }
    setState(365);
    match(TsilParser::PAREN_OPEN);
    setState(374);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(366);
      param();
      setState(371);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(367);
        match(TsilParser::COMA);
        setState(368);
        param();
        setState(373);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(376);
    match(TsilParser::PAREN_CLOSE);
    setState(379);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(377);
      match(TsilParser::COLON);
      setState(378);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->restyp = type();
    }
    setState(383);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::SEMICOLON: {
        setState(381);
        match(TsilParser::SEMICOLON);
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(382);
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

tree::TerminalNode* TsilParser::Tsil_defineContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

tree::TerminalNode* TsilParser::Tsil_defineContext::KW_TSIL() {
  return getToken(TsilParser::KW_TSIL, 0);
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
    setState(387);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_VAR: {
        setState(385);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_var = match(TsilParser::KW_VAR);
        break;
      }

      case TsilParser::KW_IMMUT: {
        setState(386);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_immut = match(TsilParser::KW_IMMUT);
        break;
      }

      case TsilParser::KW_TSIL: {
        break;
      }

    default:
      break;
    }
    setState(389);
    antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_const = match(TsilParser::KW_TSIL);
    setState(390);
    antlrcpp::downCast<Tsil_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(393);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(391);
      match(TsilParser::COLON);
      setState(392);
      type();
    }
    setState(400);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::EQUAL) {
      setState(395);
      match(TsilParser::EQUAL);
      setState(398);
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
          setState(396);
          antlrcpp::downCast<Tsil_defineContext *>(_localctx)->value_expr = expr();
          break;
        }

        case TsilParser::QUOTE_OPEN: {
          setState(397);
          antlrcpp::downCast<Tsil_defineContext *>(_localctx)->value_object = typeless_object();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
    }
    setState(402);
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

tree::TerminalNode* TsilParser::AssignContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
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
    setState(404);
    antlrcpp::downCast<AssignContext *>(_localctx)->id = match(TsilParser::ID);
    setState(405);
    match(TsilParser::EQUAL);
    setState(408);
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
        setState(406);
        antlrcpp::downCast<AssignContext *>(_localctx)->value_expr = expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(407);
        antlrcpp::downCast<AssignContext *>(_localctx)->value_object = typeless_object();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(410);
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

TsilParser::ExprContext* TsilParser::SynonymContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
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
    setState(412);
    match(TsilParser::KW_SYNONYM);
    setState(413);
    antlrcpp::downCast<SynonymContext *>(_localctx)->id = match(TsilParser::ID);
    setState(425);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(414);
      match(TsilParser::LESSER);
      setState(415);
      antlrcpp::downCast<SynonymContext *>(_localctx)->first_gendef = gendef();
      setState(420);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(416);
        match(TsilParser::COMA);
        setState(417);
        gendef();
        setState(422);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(423);
      match(TsilParser::GREATER);
    }
    setState(427);
    match(TsilParser::EQUAL);
    setState(428);
    expr();
    setState(429);
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

TsilParser::ExprContext* TsilParser::Synonym_fnContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
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
    setState(431);
    match(TsilParser::KW_SYNONYM);
    setState(432);
    antlrcpp::downCast<Synonym_fnContext *>(_localctx)->id = match(TsilParser::ID);
    setState(444);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(433);
      match(TsilParser::LESSER);
      setState(434);
      antlrcpp::downCast<Synonym_fnContext *>(_localctx)->first_gendef = gendef();
      setState(439);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(435);
        match(TsilParser::COMA);
        setState(436);
        gendef();
        setState(441);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(442);
      match(TsilParser::GREATER);
    }
    setState(446);
    match(TsilParser::PAREN_OPEN);
    setState(447);
    match(TsilParser::PAREN_CLOSE);
    setState(448);
    match(TsilParser::EQUAL);
    setState(449);
    match(TsilParser::GREATER);
    setState(450);
    expr();
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
    setState(453);
    match(TsilParser::KW_SECTION);
    setState(454);
    antlrcpp::downCast<Section_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(456);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      setState(455);
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

tree::TerminalNode* TsilParser::SetContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
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
    setState(458);
    antlrcpp::downCast<SetContext *>(_localctx)->object = atom(0);
    setState(459);
    match(TsilParser::DOT);
    setState(460);
    antlrcpp::downCast<SetContext *>(_localctx)->id = match(TsilParser::ID);
    setState(461);
    match(TsilParser::EQUAL);
    setState(464);
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
        setState(462);
        antlrcpp::downCast<SetContext *>(_localctx)->value_expr = expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(463);
        antlrcpp::downCast<SetContext *>(_localctx)->value_object = typeless_object();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(466);
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

tree::TerminalNode* TsilParser::Position_setContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
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
    setState(468);
    antlrcpp::downCast<Position_setContext *>(_localctx)->object = atom(0);
    setState(469);
    match(TsilParser::BRACKET_OPEN);
    setState(470);
    antlrcpp::downCast<Position_setContext *>(_localctx)->idx = expr();
    setState(471);
    match(TsilParser::BRACKET_CLOSE);
    setState(472);
    match(TsilParser::EQUAL);
    setState(475);
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
        setState(473);
        antlrcpp::downCast<Position_setContext *>(_localctx)->value_expr = expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(474);
        antlrcpp::downCast<Position_setContext *>(_localctx)->value_object = typeless_object();
        break;
      }

    default:
      throw NoViableAltException(this);
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

tree::TerminalNode* TsilParser::Section_setContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
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
    setState(479);
    antlrcpp::downCast<Section_setContext *>(_localctx)->object = atom(0);
    setState(480);
    match(TsilParser::COLON);
    setState(481);
    match(TsilParser::COLON);
    setState(482);
    antlrcpp::downCast<Section_setContext *>(_localctx)->id = match(TsilParser::ID);
    setState(483);
    match(TsilParser::EQUAL);
    setState(486);
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
        setState(484);
        antlrcpp::downCast<Section_setContext *>(_localctx)->value_expr = expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(485);
        antlrcpp::downCast<Section_setContext *>(_localctx)->value_object = typeless_object();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(488);
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
  enterRule(_localctx, 58, TsilParser::RuleIf);
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
    setState(490);
    match(TsilParser::KW_IF);
    setState(491);
    antlrcpp::downCast<IfContext *>(_localctx)->cond = operation(0);
    setState(492);
    antlrcpp::downCast<IfContext *>(_localctx)->ifok = body();
    setState(498);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::KW_ELSE) {
      setState(493);
      match(TsilParser::KW_ELSE);
      setState(496);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TsilParser::QUOTE_OPEN: {
          setState(494);
          antlrcpp::downCast<IfContext *>(_localctx)->ifnot = body();
          break;
        }

        case TsilParser::KW_IF: {
          setState(495);
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
  enterRule(_localctx, 60, TsilParser::RuleWhile);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(500);
    match(TsilParser::KW_WHILE);
    setState(501);
    antlrcpp::downCast<WhileContext *>(_localctx)->cond = operation(0);
    setState(502);
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
  enterRule(_localctx, 62, TsilParser::RuleExec);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(504);
    match(TsilParser::KW_EXEC);
    setState(505);
    body();
    setState(506);
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
  enterRule(_localctx, 64, TsilParser::RuleBody);
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
    setState(508);
    match(TsilParser::QUOTE_OPEN);
    setState(512);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -4560877560274679442) != 0)) {
      setState(509);
      body_element();
      setState(514);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(515);
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
  enterRule(_localctx, 66, TsilParser::RuleBody_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(536);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(517);
      structure_define();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(518);
      diia_define();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(519);
      tsil_define();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(520);
      assign();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(521);
      set();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(522);
      section_set();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(523);
      position_set();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(524);
      synonym();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(525);
      synonym_fn();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(526);
      section_define();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(527);
      if_();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(528);
      while_();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(529);
      expr();
      setState(530);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(532);
      body();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(533);
      exec();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(534);
      return_();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(535);
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
  enterRule(_localctx, 68, TsilParser::RuleReturn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(538);
    match(TsilParser::KW_RETURN);
    setState(541);
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
        setState(539);
        antlrcpp::downCast<ReturnContext *>(_localctx)->value_expr = expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(540);
        antlrcpp::downCast<ReturnContext *>(_localctx)->value_object = typeless_object();
        break;
      }

      case TsilParser::SEMICOLON: {
        break;
      }

    default:
      break;
    }
    setState(543);
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
  size_t startState = 70;
  enterRecursionRule(_localctx, 70, TsilParser::RuleSimple_type, precedence);

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

    setState(546);
    antlrcpp::downCast<Simple_type_subjectContext *>(_localctx)->id = match(TsilParser::ID);
    _ctx->stop = _input->LT(-1);
    setState(573);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(571);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Simple_type_section_getContext>(_tracker.createInstance<Simple_typeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleSimple_type);
          setState(548);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(549);
          match(TsilParser::COLON);
          setState(550);
          match(TsilParser::COLON);
          setState(551);
          antlrcpp::downCast<Simple_type_section_getContext *>(_localctx)->id = match(TsilParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Simple_type_template_getContext>(_tracker.createInstance<Simple_typeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleSimple_type);
          setState(552);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(553);
          match(TsilParser::LESSER);
          setState(554);
          type();
          setState(559);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == TsilParser::COMA) {
            setState(555);
            match(TsilParser::COMA);
            setState(556);
            type();
            setState(561);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(562);
          match(TsilParser::GREATER);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Simple_type_getContext>(_tracker.createInstance<Simple_typeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleSimple_type);
          setState(564);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(565);
          match(TsilParser::DOT);
          setState(566);
          antlrcpp::downCast<Simple_type_getContext *>(_localctx)->id = match(TsilParser::ID);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Simple_type_arrayContext>(_tracker.createInstance<Simple_typeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleSimple_type);
          setState(567);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(568);
          match(TsilParser::BRACKET_OPEN);
          setState(569);
          antlrcpp::downCast<Simple_type_arrayContext *>(_localctx)->size = match(TsilParser::NUMBER);
          setState(570);
          match(TsilParser::BRACKET_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(575);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
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
  size_t startState = 72;
  enterRecursionRule(_localctx, 72, TsilParser::RuleSingle_type, precedence);

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
    setState(610);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Type_simple_typeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(577);
      simple_type(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Type_fnContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(578);
      match(TsilParser::PAREN_OPEN);
      setState(579);
      match(TsilParser::PAREN_CLOSE);
      setState(580);
      match(TsilParser::MINUS);
      setState(581);
      match(TsilParser::GREATER);
      setState(582);
      antlrcpp::downCast<Type_fnContext *>(_localctx)->restyp = type();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Type_fn_complexContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(583);
      match(TsilParser::PAREN_OPEN);
      setState(584);
      type();
      setState(587); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(585);
        match(TsilParser::COMA);
        setState(586);
        type();
        setState(589); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TsilParser::COMA);
      setState(591);
      match(TsilParser::PAREN_CLOSE);
      setState(592);
      match(TsilParser::MINUS);
      setState(593);
      match(TsilParser::GREATER);
      setState(594);
      antlrcpp::downCast<Type_fn_complexContext *>(_localctx)->restyp = type();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Type_fn_complex_namedContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(596);
      match(TsilParser::PAREN_OPEN);
      setState(597);
      param();
      setState(602);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(598);
        match(TsilParser::COMA);
        setState(599);
        param();
        setState(604);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(605);
      match(TsilParser::PAREN_CLOSE);
      setState(606);
      match(TsilParser::MINUS);
      setState(607);
      match(TsilParser::GREATER);
      setState(608);
      antlrcpp::downCast<Type_fn_complex_namedContext *>(_localctx)->restyp = type();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(618);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Type_fn_simpleContext>(_tracker.createInstance<Single_typeContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->param_type = previousContext;
        pushNewRecursionContext(newContext, startState, RuleSingle_type);
        setState(612);

        if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
        setState(613);
        match(TsilParser::MINUS);
        setState(614);
        match(TsilParser::GREATER);
        setState(615);
        antlrcpp::downCast<Type_fn_simpleContext *>(_localctx)->restyp = type(); 
      }
      setState(620);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
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
  enterRule(_localctx, 74, TsilParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(633);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TsilParser::Type_nestedContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(621);
      match(TsilParser::PAREN_OPEN);
      setState(622);
      type();
      setState(623);
      match(TsilParser::PAREN_CLOSE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TsilParser::Type_singleContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(625);
      single_type(0);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<TsilParser::Type_variationContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(626);
      single_type(0);
      setState(629); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(627);
                match(TsilParser::OR);
                setState(628);
                single_type(0);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(631); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
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
  enterRule(_localctx, 76, TsilParser::RuleParam);
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
    setState(635);
    antlrcpp::downCast<ParamContext *>(_localctx)->id = match(TsilParser::ID);
    setState(638);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(636);
      match(TsilParser::COLON);
      setState(637);
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

bool TsilParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return atomSempred(antlrcpp::downCast<AtomContext *>(context), predicateIndex);
    case 4: return operationSempred(antlrcpp::downCast<OperationContext *>(context), predicateIndex);
    case 35: return simple_typeSempred(antlrcpp::downCast<Simple_typeContext *>(context), predicateIndex);
    case 36: return single_typeSempred(antlrcpp::downCast<Single_typeContext *>(context), predicateIndex);

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
    case 5: return precpred(_ctx, 21);
    case 6: return precpred(_ctx, 20);
    case 7: return precpred(_ctx, 19);
    case 8: return precpred(_ctx, 18);
    case 9: return precpred(_ctx, 17);
    case 10: return precpred(_ctx, 16);
    case 11: return precpred(_ctx, 15);
    case 12: return precpred(_ctx, 14);
    case 13: return precpred(_ctx, 13);
    case 14: return precpred(_ctx, 12);
    case 15: return precpred(_ctx, 11);
    case 16: return precpred(_ctx, 10);
    case 17: return precpred(_ctx, 9);
    case 18: return precpred(_ctx, 8);
    case 19: return precpred(_ctx, 7);
    case 20: return precpred(_ctx, 6);
    case 21: return precpred(_ctx, 5);
    case 22: return precpred(_ctx, 4);
    case 23: return precpred(_ctx, 3);
    case 24: return precpred(_ctx, 1);
    case 25: return precpred(_ctx, 2);

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
