
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
      "structure_element", "enum_define", "enum_element", "diia_define", 
      "tsil_define", "assign", "synonym", "synonym_fn", "section_define", 
      "set", "position_set", "section_set", "assign_op", "if", "while", 
      "exec", "body", "body_element", "return", "label", "goto", "simple_type", 
      "single_type", "type", "param", "preproc", "take", "take_element"
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
      "'\\u0441\\u0442\\u0440\\u0438\\u0431\\u043D\\u0443\\u0442\\u0438'", 
      "'\\u043F\\u0435\\u0440\\u0435\\u043B\\u0456\\u043A'", "'\\u043F\\u0435\\u0440\\u0435\\u043B\\u0456\\u0447\\u0438\\u0442\\u0438'", 
      "'\\u0454'", "'='", "'>'", "'<'", "'.'", "'+'", "'-'", "'*'", "'/'", 
      "'%'", "'^'", "'&'", "'|'", "'('", "')'", "'['", "']'", "'\\u003F'", 
      "':'", "'~'", "'''", "'\"'", "'!'", "','", "';'", "'{'", "'}'"
    },
    std::vector<std::string>{
      "", "KW_TSIL", "KW_DIIA", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_RETURN", 
      "KW_DEFER", "KW_STRUCT", "KW_VARIATION", "KW_AS", "KW_SECTION", "KW_IMPORT", 
      "KW_EXPORT", "KW_COMPOSITION", "KW_PROPERTY", "KW_PUBLIC", "KW_PRIVATE", 
      "KW_LOCAL", "KW_NOT", "KW_OR", "KW_AND", "KW_VAR", "KW_IMMUT", "KW_SYNONYM", 
      "KW_EXEC", "KW_TRY", "KW_CATCH", "KW_THROW", "KW_GOTO", "KW_ENUM", 
      "KW_ENUMERATE", "KW_IS", "EQUAL", "GREATER", "LESSER", "DOT", "PLUS", 
      "MINUS", "MULTIPLY", "DIVIDE", "MOD", "POWER", "AND", "OR", "PAREN_OPEN", 
      "PAREN_CLOSE", "BRACKET_OPEN", "BRACKET_CLOSE", "QUESTION", "COLON", 
      "TILDA", "QUOTE", "DOUBLE_QUOTE", "EXCLAMATION", "COMA", "SEMICOLON", 
      "QUOTE_OPEN", "QUOTE_CLOSE", "NUMBER", "TYPED_INTEGER", "INTEGER", 
      "TYPED_FLOAT", "FLOAT", "HEX", "BIN", "ID", "STRING", "COMMENT", "LINE_COMMENT", 
      "WS", "NL"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,71,796,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,1,0,1,0,1,0,1,1,5,1,99,8,1,
  	10,1,12,1,102,9,1,1,2,1,2,1,2,1,2,1,2,1,2,3,2,110,8,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,5,2,121,8,2,10,2,12,2,124,9,2,3,2,126,8,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,142,8,2,10,2,12,2,
  	145,9,2,3,2,147,8,2,1,2,5,2,150,8,2,10,2,12,2,153,9,2,1,3,1,3,3,3,157,
  	8,3,1,4,1,4,1,4,3,4,162,8,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,
  	4,174,8,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,252,8,4,1,4,1,4,1,4,5,4,257,8,4,
  	10,4,12,4,260,9,4,1,5,1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,
  	1,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,
  	13,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,5,15,298,8,15,10,15,12,15,
  	301,9,15,1,15,3,15,304,8,15,3,15,306,8,15,1,15,1,15,3,15,310,8,15,1,16,
  	1,16,3,16,314,8,16,1,16,1,16,3,16,318,8,16,1,16,1,16,1,16,3,16,323,8,
  	16,1,17,1,17,1,17,1,17,5,17,329,8,17,10,17,12,17,332,9,17,1,17,3,17,335,
  	8,17,3,17,337,8,17,1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,18,5,18,347,8,
  	18,10,18,12,18,350,9,18,1,18,1,18,3,18,354,8,18,1,18,1,18,1,18,5,18,359,
  	8,18,10,18,12,18,362,9,18,1,18,3,18,365,8,18,1,19,1,19,1,19,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,5,20,377,8,20,10,20,12,20,380,9,20,1,20,3,20,
  	383,8,20,3,20,385,8,20,1,20,3,20,388,8,20,1,21,1,21,1,21,1,21,1,21,5,
  	21,395,8,21,10,21,12,21,398,9,21,1,21,3,21,401,8,21,1,22,1,22,1,22,3,
  	22,406,8,22,1,22,1,22,1,22,1,22,1,22,1,22,5,22,414,8,22,10,22,12,22,417,
  	9,22,1,22,1,22,3,22,421,8,22,1,22,1,22,1,22,1,22,5,22,427,8,22,10,22,
  	12,22,430,9,22,3,22,432,8,22,1,22,1,22,1,22,3,22,437,8,22,1,22,1,22,3,
  	22,441,8,22,1,23,1,23,1,23,3,23,446,8,23,1,23,1,23,3,23,450,8,23,1,23,
  	1,23,1,23,1,23,3,23,456,8,23,1,23,1,23,1,23,3,23,461,8,23,3,23,463,8,
  	23,1,23,1,23,1,24,1,24,1,24,1,24,3,24,471,8,24,1,24,1,24,1,25,1,25,1,
  	25,1,25,1,25,1,25,5,25,481,8,25,10,25,12,25,484,9,25,1,25,1,25,3,25,488,
  	8,25,1,25,1,25,1,25,1,25,3,25,494,8,25,1,25,1,25,1,26,1,26,1,26,1,26,
  	1,26,1,26,5,26,504,8,26,10,26,12,26,507,9,26,1,26,1,26,3,26,511,8,26,
  	1,26,1,26,1,26,1,26,1,26,1,26,1,26,3,26,520,8,26,1,26,1,26,1,27,1,27,
  	1,27,3,27,527,8,27,1,28,1,28,1,28,1,28,1,28,1,28,3,28,535,8,28,1,28,1,
  	28,1,29,1,29,1,29,1,29,1,29,1,29,1,29,3,29,546,8,29,1,29,1,29,1,30,1,
  	30,1,30,1,30,1,30,1,30,1,30,3,30,557,8,30,1,30,1,30,1,31,1,31,1,31,1,
  	31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,3,31,572,8,31,1,31,1,31,1,32,1,
  	32,1,32,1,32,1,32,1,32,3,32,582,8,32,3,32,584,8,32,1,33,1,33,1,33,1,33,
  	1,34,1,34,1,34,1,34,1,35,1,35,5,35,596,8,35,10,35,12,35,599,9,35,1,35,
  	1,35,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,
  	1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,3,36,627,8,36,
  	1,37,1,37,1,37,3,37,632,8,37,1,37,1,37,1,38,1,38,1,38,1,39,1,39,1,39,
  	1,39,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,5,40,
  	655,8,40,10,40,12,40,658,9,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,
  	1,40,5,40,669,8,40,10,40,12,40,672,9,40,1,41,1,41,1,41,1,41,1,41,1,41,
  	1,41,1,41,1,41,1,41,1,41,5,41,685,8,41,10,41,12,41,688,9,41,1,41,1,41,
  	1,41,1,41,1,41,1,41,1,41,1,41,1,41,5,41,699,8,41,10,41,12,41,702,9,41,
  	1,41,1,41,1,41,1,41,1,41,3,41,709,8,41,1,41,1,41,1,41,1,41,5,41,715,8,
  	41,10,41,12,41,718,9,41,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,4,42,
  	728,8,42,11,42,12,42,729,3,42,732,8,42,1,43,1,43,1,43,3,43,737,8,43,1,
  	44,1,44,1,44,1,44,1,44,1,44,5,44,745,8,44,10,44,12,44,748,9,44,1,44,1,
  	44,1,44,1,44,1,44,5,44,755,8,44,10,44,12,44,758,9,44,3,44,760,8,44,1,
  	44,1,44,1,44,1,44,1,44,1,44,1,44,1,44,1,44,1,44,1,44,1,44,3,44,774,8,
  	44,1,45,1,45,3,45,778,8,45,1,45,1,45,3,45,782,8,45,1,45,1,45,1,45,5,45,
  	787,8,45,10,45,12,45,790,9,45,1,45,1,45,1,46,1,46,1,46,0,4,4,8,80,82,
  	47,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,
  	48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,
  	0,1,1,0,66,67,899,0,94,1,0,0,0,2,100,1,0,0,0,4,109,1,0,0,0,6,156,1,0,
  	0,0,8,173,1,0,0,0,10,261,1,0,0,0,12,264,1,0,0,0,14,267,1,0,0,0,16,271,
  	1,0,0,0,18,274,1,0,0,0,20,277,1,0,0,0,22,280,1,0,0,0,24,283,1,0,0,0,26,
  	286,1,0,0,0,28,289,1,0,0,0,30,309,1,0,0,0,32,322,1,0,0,0,34,324,1,0,0,
  	0,36,340,1,0,0,0,38,366,1,0,0,0,40,369,1,0,0,0,42,389,1,0,0,0,44,405,
  	1,0,0,0,46,445,1,0,0,0,48,466,1,0,0,0,50,474,1,0,0,0,52,497,1,0,0,0,54,
  	523,1,0,0,0,56,528,1,0,0,0,58,538,1,0,0,0,60,549,1,0,0,0,62,571,1,0,0,
  	0,64,575,1,0,0,0,66,585,1,0,0,0,68,589,1,0,0,0,70,593,1,0,0,0,72,626,
  	1,0,0,0,74,628,1,0,0,0,76,635,1,0,0,0,78,638,1,0,0,0,80,642,1,0,0,0,82,
  	708,1,0,0,0,84,731,1,0,0,0,86,733,1,0,0,0,88,773,1,0,0,0,90,775,1,0,0,
  	0,92,793,1,0,0,0,94,95,3,2,1,0,95,96,5,0,0,1,96,1,1,0,0,0,97,99,3,72,
  	36,0,98,97,1,0,0,0,99,102,1,0,0,0,100,98,1,0,0,0,100,101,1,0,0,0,101,
  	3,1,0,0,0,102,100,1,0,0,0,103,104,6,2,-1,0,104,105,5,45,0,0,105,106,3,
  	30,15,0,106,107,5,46,0,0,107,110,1,0,0,0,108,110,5,66,0,0,109,103,1,0,
  	0,0,109,108,1,0,0,0,110,151,1,0,0,0,111,112,10,5,0,0,112,113,5,50,0,0,
  	113,114,5,50,0,0,114,150,5,66,0,0,115,116,10,4,0,0,116,125,5,35,0,0,117,
  	122,3,84,42,0,118,119,5,55,0,0,119,121,3,84,42,0,120,118,1,0,0,0,121,
  	124,1,0,0,0,122,120,1,0,0,0,122,123,1,0,0,0,123,126,1,0,0,0,124,122,1,
  	0,0,0,125,117,1,0,0,0,125,126,1,0,0,0,126,127,1,0,0,0,127,150,5,34,0,
  	0,128,129,10,3,0,0,129,130,5,36,0,0,130,150,5,66,0,0,131,132,10,2,0,0,
  	132,133,5,47,0,0,133,134,3,30,15,0,134,135,5,48,0,0,135,150,1,0,0,0,136,
  	137,10,1,0,0,137,146,5,45,0,0,138,143,3,6,3,0,139,140,5,55,0,0,140,142,
  	3,6,3,0,141,139,1,0,0,0,142,145,1,0,0,0,143,141,1,0,0,0,143,144,1,0,0,
  	0,144,147,1,0,0,0,145,143,1,0,0,0,146,138,1,0,0,0,146,147,1,0,0,0,147,
  	148,1,0,0,0,148,150,5,46,0,0,149,111,1,0,0,0,149,115,1,0,0,0,149,128,
  	1,0,0,0,149,131,1,0,0,0,149,136,1,0,0,0,150,153,1,0,0,0,151,149,1,0,0,
  	0,151,152,1,0,0,0,152,5,1,0,0,0,153,151,1,0,0,0,154,157,3,30,15,0,155,
  	157,3,34,17,0,156,154,1,0,0,0,156,155,1,0,0,0,157,7,1,0,0,0,158,159,6,
  	4,-1,0,159,174,5,59,0,0,160,162,5,66,0,0,161,160,1,0,0,0,161,162,1,0,
  	0,0,162,163,1,0,0,0,163,174,5,67,0,0,164,174,3,4,2,0,165,166,5,54,0,0,
  	166,174,3,8,4,25,167,168,5,51,0,0,168,174,3,8,4,24,169,170,5,37,0,0,170,
  	174,3,8,4,23,171,172,5,38,0,0,172,174,3,8,4,22,173,158,1,0,0,0,173,161,
  	1,0,0,0,173,164,1,0,0,0,173,165,1,0,0,0,173,167,1,0,0,0,173,169,1,0,0,
  	0,173,171,1,0,0,0,174,258,1,0,0,0,175,176,10,21,0,0,176,177,5,39,0,0,
  	177,257,3,8,4,22,178,179,10,20,0,0,179,180,5,40,0,0,180,257,3,8,4,21,
  	181,182,10,19,0,0,182,183,5,41,0,0,183,257,3,8,4,20,184,185,10,18,0,0,
  	185,186,5,37,0,0,186,257,3,8,4,19,187,188,10,17,0,0,188,189,5,38,0,0,
  	189,257,3,8,4,18,190,191,10,16,0,0,191,192,3,10,5,0,192,193,3,8,4,17,
  	193,257,1,0,0,0,194,195,10,15,0,0,195,196,3,12,6,0,196,197,3,8,4,16,197,
  	257,1,0,0,0,198,199,10,14,0,0,199,200,3,14,7,0,200,201,3,8,4,15,201,257,
  	1,0,0,0,202,203,10,13,0,0,203,204,5,35,0,0,204,257,3,8,4,14,205,206,10,
  	12,0,0,206,207,3,16,8,0,207,208,3,8,4,13,208,257,1,0,0,0,209,210,10,11,
  	0,0,210,211,5,34,0,0,211,257,3,8,4,12,212,213,10,10,0,0,213,214,3,18,
  	9,0,214,215,3,8,4,11,215,257,1,0,0,0,216,217,10,8,0,0,217,218,3,20,10,
  	0,218,219,3,8,4,9,219,257,1,0,0,0,220,221,10,7,0,0,221,222,3,22,11,0,
  	222,223,3,8,4,8,223,257,1,0,0,0,224,225,10,6,0,0,225,226,5,43,0,0,226,
  	257,3,8,4,7,227,228,10,5,0,0,228,229,5,42,0,0,229,257,3,8,4,6,230,231,
  	10,4,0,0,231,232,5,44,0,0,232,257,3,8,4,5,233,234,10,3,0,0,234,235,3,
  	24,12,0,235,236,3,8,4,4,236,257,1,0,0,0,237,238,10,2,0,0,238,239,3,26,
  	13,0,239,240,3,8,4,3,240,257,1,0,0,0,241,242,10,1,0,0,242,243,5,49,0,
  	0,243,244,3,8,4,0,244,245,5,50,0,0,245,246,3,8,4,2,246,257,1,0,0,0,247,
  	248,10,26,0,0,248,251,5,10,0,0,249,252,3,84,42,0,250,252,5,1,0,0,251,
  	249,1,0,0,0,251,250,1,0,0,0,252,257,1,0,0,0,253,254,10,9,0,0,254,255,
  	5,32,0,0,255,257,3,84,42,0,256,175,1,0,0,0,256,178,1,0,0,0,256,181,1,
  	0,0,0,256,184,1,0,0,0,256,187,1,0,0,0,256,190,1,0,0,0,256,194,1,0,0,0,
  	256,198,1,0,0,0,256,202,1,0,0,0,256,205,1,0,0,0,256,209,1,0,0,0,256,212,
  	1,0,0,0,256,216,1,0,0,0,256,220,1,0,0,0,256,224,1,0,0,0,256,227,1,0,0,
  	0,256,230,1,0,0,0,256,233,1,0,0,0,256,237,1,0,0,0,256,241,1,0,0,0,256,
  	247,1,0,0,0,256,253,1,0,0,0,257,260,1,0,0,0,258,256,1,0,0,0,258,259,1,
  	0,0,0,259,9,1,0,0,0,260,258,1,0,0,0,261,262,5,35,0,0,262,263,5,35,0,0,
  	263,11,1,0,0,0,264,265,5,34,0,0,265,266,5,34,0,0,266,13,1,0,0,0,267,268,
  	5,34,0,0,268,269,5,34,0,0,269,270,5,34,0,0,270,15,1,0,0,0,271,272,5,35,
  	0,0,272,273,5,33,0,0,273,17,1,0,0,0,274,275,5,34,0,0,275,276,5,33,0,0,
  	276,19,1,0,0,0,277,278,5,33,0,0,278,279,5,33,0,0,279,21,1,0,0,0,280,281,
  	5,54,0,0,281,282,5,33,0,0,282,23,1,0,0,0,283,284,5,43,0,0,284,285,5,43,
  	0,0,285,25,1,0,0,0,286,287,5,44,0,0,287,288,5,44,0,0,288,27,1,0,0,0,289,
  	290,5,66,0,0,290,29,1,0,0,0,291,310,3,8,4,0,292,293,3,80,40,0,293,305,
  	5,57,0,0,294,299,3,32,16,0,295,296,5,55,0,0,296,298,3,32,16,0,297,295,
  	1,0,0,0,298,301,1,0,0,0,299,297,1,0,0,0,299,300,1,0,0,0,300,303,1,0,0,
  	0,301,299,1,0,0,0,302,304,5,55,0,0,303,302,1,0,0,0,303,304,1,0,0,0,304,
  	306,1,0,0,0,305,294,1,0,0,0,305,306,1,0,0,0,306,307,1,0,0,0,307,308,5,
  	58,0,0,308,310,1,0,0,0,309,291,1,0,0,0,309,292,1,0,0,0,310,31,1,0,0,0,
  	311,312,5,66,0,0,312,314,5,33,0,0,313,311,1,0,0,0,313,314,1,0,0,0,314,
  	317,1,0,0,0,315,318,3,30,15,0,316,318,3,34,17,0,317,315,1,0,0,0,317,316,
  	1,0,0,0,318,323,1,0,0,0,319,320,5,36,0,0,320,321,5,36,0,0,321,323,5,36,
  	0,0,322,313,1,0,0,0,322,319,1,0,0,0,323,33,1,0,0,0,324,336,5,57,0,0,325,
  	330,3,32,16,0,326,327,5,55,0,0,327,329,3,32,16,0,328,326,1,0,0,0,329,
  	332,1,0,0,0,330,328,1,0,0,0,330,331,1,0,0,0,331,334,1,0,0,0,332,330,1,
  	0,0,0,333,335,5,55,0,0,334,333,1,0,0,0,334,335,1,0,0,0,335,337,1,0,0,
  	0,336,325,1,0,0,0,336,337,1,0,0,0,337,338,1,0,0,0,338,339,5,58,0,0,339,
  	35,1,0,0,0,340,341,5,8,0,0,341,353,5,66,0,0,342,343,5,35,0,0,343,348,
  	3,28,14,0,344,345,5,55,0,0,345,347,3,28,14,0,346,344,1,0,0,0,347,350,
  	1,0,0,0,348,346,1,0,0,0,348,349,1,0,0,0,349,351,1,0,0,0,350,348,1,0,0,
  	0,351,352,5,34,0,0,352,354,1,0,0,0,353,342,1,0,0,0,353,354,1,0,0,0,354,
  	364,1,0,0,0,355,365,5,56,0,0,356,360,5,57,0,0,357,359,3,38,19,0,358,357,
  	1,0,0,0,359,362,1,0,0,0,360,358,1,0,0,0,360,361,1,0,0,0,361,363,1,0,0,
  	0,362,360,1,0,0,0,363,365,5,58,0,0,364,355,1,0,0,0,364,356,1,0,0,0,365,
  	37,1,0,0,0,366,367,3,86,43,0,367,368,5,56,0,0,368,39,1,0,0,0,369,370,
  	5,30,0,0,370,387,5,66,0,0,371,388,5,56,0,0,372,384,5,57,0,0,373,378,3,
  	42,21,0,374,375,5,55,0,0,375,377,3,42,21,0,376,374,1,0,0,0,377,380,1,
  	0,0,0,378,376,1,0,0,0,378,379,1,0,0,0,379,382,1,0,0,0,380,378,1,0,0,0,
  	381,383,5,55,0,0,382,381,1,0,0,0,382,383,1,0,0,0,383,385,1,0,0,0,384,
  	373,1,0,0,0,384,385,1,0,0,0,385,386,1,0,0,0,386,388,5,58,0,0,387,371,
  	1,0,0,0,387,372,1,0,0,0,388,41,1,0,0,0,389,400,5,66,0,0,390,396,5,57,
  	0,0,391,392,3,86,43,0,392,393,5,56,0,0,393,395,1,0,0,0,394,391,1,0,0,
  	0,395,398,1,0,0,0,396,394,1,0,0,0,396,397,1,0,0,0,397,399,1,0,0,0,398,
  	396,1,0,0,0,399,401,5,58,0,0,400,390,1,0,0,0,400,401,1,0,0,0,401,43,1,
  	0,0,0,402,406,5,16,0,0,403,406,5,18,0,0,404,406,5,17,0,0,405,402,1,0,
  	0,0,405,403,1,0,0,0,405,404,1,0,0,0,405,406,1,0,0,0,406,407,1,0,0,0,407,
  	408,5,2,0,0,408,420,5,66,0,0,409,410,5,35,0,0,410,415,3,28,14,0,411,412,
  	5,55,0,0,412,414,3,28,14,0,413,411,1,0,0,0,414,417,1,0,0,0,415,413,1,
  	0,0,0,415,416,1,0,0,0,416,418,1,0,0,0,417,415,1,0,0,0,418,419,5,34,0,
  	0,419,421,1,0,0,0,420,409,1,0,0,0,420,421,1,0,0,0,421,422,1,0,0,0,422,
  	431,5,45,0,0,423,428,3,86,43,0,424,425,5,55,0,0,425,427,3,86,43,0,426,
  	424,1,0,0,0,427,430,1,0,0,0,428,426,1,0,0,0,428,429,1,0,0,0,429,432,1,
  	0,0,0,430,428,1,0,0,0,431,423,1,0,0,0,431,432,1,0,0,0,432,433,1,0,0,0,
  	433,436,5,46,0,0,434,435,5,50,0,0,435,437,3,84,42,0,436,434,1,0,0,0,436,
  	437,1,0,0,0,437,440,1,0,0,0,438,441,5,56,0,0,439,441,3,70,35,0,440,438,
  	1,0,0,0,440,439,1,0,0,0,441,45,1,0,0,0,442,446,5,16,0,0,443,446,5,18,
  	0,0,444,446,5,17,0,0,445,442,1,0,0,0,445,443,1,0,0,0,445,444,1,0,0,0,
  	445,446,1,0,0,0,446,449,1,0,0,0,447,450,5,22,0,0,448,450,5,23,0,0,449,
  	447,1,0,0,0,449,448,1,0,0,0,449,450,1,0,0,0,450,451,1,0,0,0,451,452,5,
  	1,0,0,452,455,5,66,0,0,453,454,5,50,0,0,454,456,3,84,42,0,455,453,1,0,
  	0,0,455,456,1,0,0,0,456,462,1,0,0,0,457,460,5,33,0,0,458,461,3,30,15,
  	0,459,461,3,34,17,0,460,458,1,0,0,0,460,459,1,0,0,0,461,463,1,0,0,0,462,
  	457,1,0,0,0,462,463,1,0,0,0,463,464,1,0,0,0,464,465,5,56,0,0,465,47,1,
  	0,0,0,466,467,5,66,0,0,467,470,3,62,31,0,468,471,3,30,15,0,469,471,3,
  	34,17,0,470,468,1,0,0,0,470,469,1,0,0,0,471,472,1,0,0,0,472,473,5,56,
  	0,0,473,49,1,0,0,0,474,475,5,24,0,0,475,487,5,66,0,0,476,477,5,35,0,0,
  	477,482,3,28,14,0,478,479,5,55,0,0,479,481,3,28,14,0,480,478,1,0,0,0,
  	481,484,1,0,0,0,482,480,1,0,0,0,482,483,1,0,0,0,483,485,1,0,0,0,484,482,
  	1,0,0,0,485,486,5,34,0,0,486,488,1,0,0,0,487,476,1,0,0,0,487,488,1,0,
  	0,0,488,489,1,0,0,0,489,493,5,33,0,0,490,494,3,30,15,0,491,494,3,34,17,
  	0,492,494,3,84,42,0,493,490,1,0,0,0,493,491,1,0,0,0,493,492,1,0,0,0,494,
  	495,1,0,0,0,495,496,5,56,0,0,496,51,1,0,0,0,497,498,5,24,0,0,498,510,
  	5,66,0,0,499,500,5,35,0,0,500,505,3,28,14,0,501,502,5,55,0,0,502,504,
  	3,28,14,0,503,501,1,0,0,0,504,507,1,0,0,0,505,503,1,0,0,0,505,506,1,0,
  	0,0,506,508,1,0,0,0,507,505,1,0,0,0,508,509,5,34,0,0,509,511,1,0,0,0,
  	510,499,1,0,0,0,510,511,1,0,0,0,511,512,1,0,0,0,512,513,5,45,0,0,513,
  	514,5,46,0,0,514,515,5,33,0,0,515,519,5,34,0,0,516,520,3,30,15,0,517,
  	520,3,34,17,0,518,520,3,84,42,0,519,516,1,0,0,0,519,517,1,0,0,0,519,518,
  	1,0,0,0,520,521,1,0,0,0,521,522,5,56,0,0,522,53,1,0,0,0,523,524,5,11,
  	0,0,524,526,5,66,0,0,525,527,3,70,35,0,526,525,1,0,0,0,526,527,1,0,0,
  	0,527,55,1,0,0,0,528,529,3,4,2,0,529,530,5,36,0,0,530,531,5,66,0,0,531,
  	534,3,62,31,0,532,535,3,30,15,0,533,535,3,34,17,0,534,532,1,0,0,0,534,
  	533,1,0,0,0,535,536,1,0,0,0,536,537,5,56,0,0,537,57,1,0,0,0,538,539,3,
  	4,2,0,539,540,5,47,0,0,540,541,3,30,15,0,541,542,5,48,0,0,542,545,3,62,
  	31,0,543,546,3,30,15,0,544,546,3,34,17,0,545,543,1,0,0,0,545,544,1,0,
  	0,0,546,547,1,0,0,0,547,548,5,56,0,0,548,59,1,0,0,0,549,550,3,4,2,0,550,
  	551,5,50,0,0,551,552,5,50,0,0,552,553,5,66,0,0,553,556,3,62,31,0,554,
  	557,3,30,15,0,555,557,3,34,17,0,556,554,1,0,0,0,556,555,1,0,0,0,557,558,
  	1,0,0,0,558,559,5,56,0,0,559,61,1,0,0,0,560,572,5,39,0,0,561,572,5,40,
  	0,0,562,572,5,41,0,0,563,572,5,37,0,0,564,572,5,38,0,0,565,572,3,10,5,
  	0,566,572,3,12,6,0,567,572,3,14,7,0,568,572,5,43,0,0,569,572,5,42,0,0,
  	570,572,5,44,0,0,571,560,1,0,0,0,571,561,1,0,0,0,571,562,1,0,0,0,571,
  	563,1,0,0,0,571,564,1,0,0,0,571,565,1,0,0,0,571,566,1,0,0,0,571,567,1,
  	0,0,0,571,568,1,0,0,0,571,569,1,0,0,0,571,570,1,0,0,0,571,572,1,0,0,0,
  	572,573,1,0,0,0,573,574,5,33,0,0,574,63,1,0,0,0,575,576,5,3,0,0,576,577,
  	3,8,4,0,577,583,3,70,35,0,578,581,5,4,0,0,579,582,3,70,35,0,580,582,3,
  	64,32,0,581,579,1,0,0,0,581,580,1,0,0,0,582,584,1,0,0,0,583,578,1,0,0,
  	0,583,584,1,0,0,0,584,65,1,0,0,0,585,586,5,5,0,0,586,587,3,8,4,0,587,
  	588,3,70,35,0,588,67,1,0,0,0,589,590,5,25,0,0,590,591,3,70,35,0,591,592,
  	5,56,0,0,592,69,1,0,0,0,593,597,5,57,0,0,594,596,3,72,36,0,595,594,1,
  	0,0,0,596,599,1,0,0,0,597,595,1,0,0,0,597,598,1,0,0,0,598,600,1,0,0,0,
  	599,597,1,0,0,0,600,601,5,58,0,0,601,71,1,0,0,0,602,627,3,36,18,0,603,
  	627,3,40,20,0,604,627,3,44,22,0,605,627,3,46,23,0,606,627,3,48,24,0,607,
  	627,3,56,28,0,608,627,3,60,30,0,609,627,3,58,29,0,610,627,3,50,25,0,611,
  	627,3,52,26,0,612,627,3,54,27,0,613,627,3,64,32,0,614,627,3,66,33,0,615,
  	616,3,30,15,0,616,617,5,56,0,0,617,627,1,0,0,0,618,627,3,70,35,0,619,
  	627,3,68,34,0,620,627,3,74,37,0,621,627,3,88,44,0,622,627,3,90,45,0,623,
  	627,3,76,38,0,624,627,3,78,39,0,625,627,5,56,0,0,626,602,1,0,0,0,626,
  	603,1,0,0,0,626,604,1,0,0,0,626,605,1,0,0,0,626,606,1,0,0,0,626,607,1,
  	0,0,0,626,608,1,0,0,0,626,609,1,0,0,0,626,610,1,0,0,0,626,611,1,0,0,0,
  	626,612,1,0,0,0,626,613,1,0,0,0,626,614,1,0,0,0,626,615,1,0,0,0,626,618,
  	1,0,0,0,626,619,1,0,0,0,626,620,1,0,0,0,626,621,1,0,0,0,626,622,1,0,0,
  	0,626,623,1,0,0,0,626,624,1,0,0,0,626,625,1,0,0,0,627,73,1,0,0,0,628,
  	631,5,6,0,0,629,632,3,30,15,0,630,632,3,34,17,0,631,629,1,0,0,0,631,630,
  	1,0,0,0,631,632,1,0,0,0,632,633,1,0,0,0,633,634,5,56,0,0,634,75,1,0,0,
  	0,635,636,5,66,0,0,636,637,5,50,0,0,637,77,1,0,0,0,638,639,5,29,0,0,639,
  	640,5,66,0,0,640,641,5,56,0,0,641,79,1,0,0,0,642,643,6,40,-1,0,643,644,
  	5,66,0,0,644,670,1,0,0,0,645,646,10,4,0,0,646,647,5,50,0,0,647,648,5,
  	50,0,0,648,669,5,66,0,0,649,650,10,3,0,0,650,651,5,35,0,0,651,656,3,84,
  	42,0,652,653,5,55,0,0,653,655,3,84,42,0,654,652,1,0,0,0,655,658,1,0,0,
  	0,656,654,1,0,0,0,656,657,1,0,0,0,657,659,1,0,0,0,658,656,1,0,0,0,659,
  	660,5,34,0,0,660,669,1,0,0,0,661,662,10,2,0,0,662,663,5,36,0,0,663,669,
  	5,66,0,0,664,665,10,1,0,0,665,666,5,47,0,0,666,667,5,59,0,0,667,669,5,
  	48,0,0,668,645,1,0,0,0,668,649,1,0,0,0,668,661,1,0,0,0,668,664,1,0,0,
  	0,669,672,1,0,0,0,670,668,1,0,0,0,670,671,1,0,0,0,671,81,1,0,0,0,672,
  	670,1,0,0,0,673,674,6,41,-1,0,674,709,3,80,40,0,675,676,5,45,0,0,676,
  	677,5,46,0,0,677,678,5,38,0,0,678,679,5,34,0,0,679,709,3,84,42,0,680,
  	681,5,45,0,0,681,686,3,84,42,0,682,683,5,55,0,0,683,685,3,84,42,0,684,
  	682,1,0,0,0,685,688,1,0,0,0,686,684,1,0,0,0,686,687,1,0,0,0,687,689,1,
  	0,0,0,688,686,1,0,0,0,689,690,5,46,0,0,690,691,5,38,0,0,691,692,5,34,
  	0,0,692,693,3,84,42,0,693,709,1,0,0,0,694,695,5,45,0,0,695,700,3,86,43,
  	0,696,697,5,55,0,0,697,699,3,86,43,0,698,696,1,0,0,0,699,702,1,0,0,0,
  	700,698,1,0,0,0,700,701,1,0,0,0,701,703,1,0,0,0,702,700,1,0,0,0,703,704,
  	5,46,0,0,704,705,5,38,0,0,705,706,5,34,0,0,706,707,3,84,42,0,707,709,
  	1,0,0,0,708,673,1,0,0,0,708,675,1,0,0,0,708,680,1,0,0,0,708,694,1,0,0,
  	0,709,716,1,0,0,0,710,711,10,3,0,0,711,712,5,38,0,0,712,713,5,34,0,0,
  	713,715,3,84,42,0,714,710,1,0,0,0,715,718,1,0,0,0,716,714,1,0,0,0,716,
  	717,1,0,0,0,717,83,1,0,0,0,718,716,1,0,0,0,719,720,5,45,0,0,720,721,3,
  	84,42,0,721,722,5,46,0,0,722,732,1,0,0,0,723,732,3,82,41,0,724,727,3,
  	82,41,0,725,726,5,44,0,0,726,728,3,82,41,0,727,725,1,0,0,0,728,729,1,
  	0,0,0,729,727,1,0,0,0,729,730,1,0,0,0,730,732,1,0,0,0,731,719,1,0,0,0,
  	731,723,1,0,0,0,731,724,1,0,0,0,732,85,1,0,0,0,733,736,5,66,0,0,734,735,
  	5,50,0,0,735,737,3,84,42,0,736,734,1,0,0,0,736,737,1,0,0,0,737,87,1,0,
  	0,0,738,739,5,41,0,0,739,740,5,47,0,0,740,741,5,3,0,0,741,742,3,8,4,0,
  	742,746,5,48,0,0,743,745,3,72,36,0,744,743,1,0,0,0,745,748,1,0,0,0,746,
  	744,1,0,0,0,746,747,1,0,0,0,747,759,1,0,0,0,748,746,1,0,0,0,749,750,5,
  	41,0,0,750,751,5,47,0,0,751,752,5,4,0,0,752,756,5,48,0,0,753,755,3,72,
  	36,0,754,753,1,0,0,0,755,758,1,0,0,0,756,754,1,0,0,0,756,757,1,0,0,0,
  	757,760,1,0,0,0,758,756,1,0,0,0,759,749,1,0,0,0,759,760,1,0,0,0,760,761,
  	1,0,0,0,761,762,5,41,0,0,762,763,5,47,0,0,763,764,5,40,0,0,764,765,5,
  	3,0,0,765,766,5,48,0,0,766,774,1,0,0,0,767,768,5,41,0,0,768,769,5,47,
  	0,0,769,770,5,28,0,0,770,771,3,8,4,0,771,772,5,48,0,0,772,774,1,0,0,0,
  	773,738,1,0,0,0,773,767,1,0,0,0,774,89,1,0,0,0,775,777,5,12,0,0,776,778,
  	5,66,0,0,777,776,1,0,0,0,777,778,1,0,0,0,778,781,1,0,0,0,779,780,5,36,
  	0,0,780,782,5,40,0,0,781,779,1,0,0,0,781,782,1,0,0,0,782,783,1,0,0,0,
  	783,788,3,92,46,0,784,785,5,40,0,0,785,787,3,92,46,0,786,784,1,0,0,0,
  	787,790,1,0,0,0,788,786,1,0,0,0,788,789,1,0,0,0,789,791,1,0,0,0,790,788,
  	1,0,0,0,791,792,5,56,0,0,792,91,1,0,0,0,793,794,7,0,0,0,794,93,1,0,0,
  	0,80,100,109,122,125,143,146,149,151,156,161,173,251,256,258,299,303,
  	305,309,313,317,322,330,334,336,348,353,360,364,378,382,384,387,396,400,
  	405,415,420,428,431,436,440,445,449,455,460,462,470,482,487,493,505,510,
  	519,526,534,545,556,571,581,583,597,626,631,656,668,670,686,700,708,716,
  	729,731,736,746,756,759,773,777,781,788
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
    setState(94);
    antlrcpp::downCast<FileContext *>(_localctx)->f_program = program();
    setState(95);
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
    setState(100);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 812937530126571886) != 0) || _la == TsilParser::ID

    || _la == TsilParser::STRING) {
      setState(97);
      body_element();
      setState(102);
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
    setState(109);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::PAREN_OPEN: {
        _localctx = _tracker.createInstance<Atom_nestedContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(104);
        match(TsilParser::PAREN_OPEN);
        setState(105);
        expr();
        setState(106);
        match(TsilParser::PAREN_CLOSE);
        break;
      }

      case TsilParser::ID: {
        _localctx = _tracker.createInstance<Atom_subjectContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(108);
        antlrcpp::downCast<Atom_subjectContext *>(_localctx)->id = match(TsilParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(151);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(149);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Atom_section_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(111);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(112);
          match(TsilParser::COLON);
          setState(113);
          match(TsilParser::COLON);
          setState(114);
          antlrcpp::downCast<Atom_section_getContext *>(_localctx)->id = match(TsilParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Atom_template_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(115);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(116);
          match(TsilParser::LESSER);
          setState(125);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == TsilParser::PAREN_OPEN

          || _la == TsilParser::ID) {
            setState(117);
            type();
            setState(122);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == TsilParser::COMA) {
              setState(118);
              match(TsilParser::COMA);
              setState(119);
              type();
              setState(124);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(127);
          match(TsilParser::GREATER);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Atom_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(128);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(129);
          match(TsilParser::DOT);
          setState(130);
          antlrcpp::downCast<Atom_getContext *>(_localctx)->id = match(TsilParser::ID);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Atom_position_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(131);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(132);
          match(TsilParser::BRACKET_OPEN);
          setState(133);
          antlrcpp::downCast<Atom_position_getContext *>(_localctx)->position = expr();
          setState(134);
          match(TsilParser::BRACKET_CLOSE);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Atom_callContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(136);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(137);
          match(TsilParser::PAREN_OPEN);
          setState(146);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 37) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 37)) & 1616003331) != 0)) {
            setState(138);
            call_arg();
            setState(143);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == TsilParser::COMA) {
              setState(139);
              match(TsilParser::COMA);
              setState(140);
              call_arg();
              setState(145);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(148);
          match(TsilParser::PAREN_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(153);
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
    setState(156);
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
        setState(154);
        expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        enterOuterAlt(_localctx, 2);
        setState(155);
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
//----------------- Operation_isContext ------------------------------------------------------------------

TsilParser::OperationContext* TsilParser::Operation_isContext::operation() {
  return getRuleContext<TsilParser::OperationContext>(0);
}

tree::TerminalNode* TsilParser::Operation_isContext::KW_IS() {
  return getToken(TsilParser::KW_IS, 0);
}

TsilParser::TypeContext* TsilParser::Operation_isContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

TsilParser::Operation_isContext::Operation_isContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_isContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_is(this);
}
void TsilParser::Operation_isContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_is(this);
}

std::any TsilParser::Operation_isContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_is(this);
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
    setState(173);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Operation_numberContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(159);
      match(TsilParser::NUMBER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Operation_stringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(161);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TsilParser::ID) {
        setState(160);
        antlrcpp::downCast<Operation_stringContext *>(_localctx)->tt = match(TsilParser::ID);
      }
      setState(163);
      match(TsilParser::STRING);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Operation_atomContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(164);
      atom(0);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Operation_pre_notContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(165);
      antlrcpp::downCast<Operation_pre_notContext *>(_localctx)->op = match(TsilParser::EXCLAMATION);
      setState(166);
      antlrcpp::downCast<Operation_pre_notContext *>(_localctx)->right = operation(25);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Operation_pre_bw_notContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(167);
      antlrcpp::downCast<Operation_pre_bw_notContext *>(_localctx)->op = match(TsilParser::TILDA);
      setState(168);
      antlrcpp::downCast<Operation_pre_bw_notContext *>(_localctx)->right = operation(24);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<Operation_pre_plusContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(169);
      antlrcpp::downCast<Operation_pre_plusContext *>(_localctx)->op = match(TsilParser::PLUS);
      setState(170);
      antlrcpp::downCast<Operation_pre_plusContext *>(_localctx)->right = operation(23);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<Operation_pre_minusContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(171);
      antlrcpp::downCast<Operation_pre_minusContext *>(_localctx)->op = match(TsilParser::MINUS);
      setState(172);
      antlrcpp::downCast<Operation_pre_minusContext *>(_localctx)->right = operation(22);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(258);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(256);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Operation_mulContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(175);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(176);
          antlrcpp::downCast<Operation_mulContext *>(_localctx)->op = match(TsilParser::MULTIPLY);
          setState(177);
          antlrcpp::downCast<Operation_mulContext *>(_localctx)->right = operation(22);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Operation_divContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(178);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(179);
          antlrcpp::downCast<Operation_divContext *>(_localctx)->op = match(TsilParser::DIVIDE);
          setState(180);
          antlrcpp::downCast<Operation_divContext *>(_localctx)->right = operation(21);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Operation_modContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(181);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(182);
          antlrcpp::downCast<Operation_modContext *>(_localctx)->op = match(TsilParser::MOD);
          setState(183);
          antlrcpp::downCast<Operation_modContext *>(_localctx)->right = operation(20);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Operation_addContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(184);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(185);
          antlrcpp::downCast<Operation_addContext *>(_localctx)->op = match(TsilParser::PLUS);
          setState(186);
          antlrcpp::downCast<Operation_addContext *>(_localctx)->right = operation(19);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Operation_subContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(187);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(188);
          antlrcpp::downCast<Operation_subContext *>(_localctx)->op = match(TsilParser::MINUS);
          setState(189);
          antlrcpp::downCast<Operation_subContext *>(_localctx)->right = operation(18);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<Operation_lshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(190);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(191);
          antlrcpp::downCast<Operation_lshiftContext *>(_localctx)->op = op_lshift();
          setState(192);
          antlrcpp::downCast<Operation_lshiftContext *>(_localctx)->right = operation(17);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<Operation_rshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(194);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(195);
          antlrcpp::downCast<Operation_rshiftContext *>(_localctx)->op = op_rshift();
          setState(196);
          antlrcpp::downCast<Operation_rshiftContext *>(_localctx)->right = operation(16);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<Operation_urshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(198);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(199);
          antlrcpp::downCast<Operation_urshiftContext *>(_localctx)->op = op_urshift();
          setState(200);
          antlrcpp::downCast<Operation_urshiftContext *>(_localctx)->right = operation(15);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<Operation_ltContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(202);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(203);
          antlrcpp::downCast<Operation_ltContext *>(_localctx)->op = match(TsilParser::LESSER);
          setState(204);
          antlrcpp::downCast<Operation_ltContext *>(_localctx)->right = operation(14);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<Operation_lteContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(205);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(206);
          antlrcpp::downCast<Operation_lteContext *>(_localctx)->op = op_lte();
          setState(207);
          antlrcpp::downCast<Operation_lteContext *>(_localctx)->right = operation(13);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<Operation_gtContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(209);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(210);
          antlrcpp::downCast<Operation_gtContext *>(_localctx)->op = match(TsilParser::GREATER);
          setState(211);
          antlrcpp::downCast<Operation_gtContext *>(_localctx)->right = operation(12);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<Operation_gteContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(212);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(213);
          antlrcpp::downCast<Operation_gteContext *>(_localctx)->op = op_gte();
          setState(214);
          antlrcpp::downCast<Operation_gteContext *>(_localctx)->right = operation(11);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<Operation_eqContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(216);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(217);
          antlrcpp::downCast<Operation_eqContext *>(_localctx)->op = op_eq();
          setState(218);
          antlrcpp::downCast<Operation_eqContext *>(_localctx)->right = operation(9);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<Operation_neqContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(220);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(221);
          antlrcpp::downCast<Operation_neqContext *>(_localctx)->op = op_neq();
          setState(222);
          antlrcpp::downCast<Operation_neqContext *>(_localctx)->right = operation(8);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<Operation_andContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(224);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(225);
          antlrcpp::downCast<Operation_andContext *>(_localctx)->op = match(TsilParser::AND);
          setState(226);
          antlrcpp::downCast<Operation_andContext *>(_localctx)->right = operation(7);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<Operation_xorContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(227);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(228);
          antlrcpp::downCast<Operation_xorContext *>(_localctx)->op = match(TsilParser::POWER);
          setState(229);
          antlrcpp::downCast<Operation_xorContext *>(_localctx)->right = operation(6);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<Operation_orContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(230);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(231);
          antlrcpp::downCast<Operation_orContext *>(_localctx)->op = match(TsilParser::OR);
          setState(232);
          antlrcpp::downCast<Operation_orContext *>(_localctx)->right = operation(5);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<Operation_landContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(233);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(234);
          antlrcpp::downCast<Operation_landContext *>(_localctx)->op = op_land();
          setState(235);
          antlrcpp::downCast<Operation_landContext *>(_localctx)->right = operation(4);
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<Operation_lorContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(237);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(238);
          antlrcpp::downCast<Operation_lorContext *>(_localctx)->op = op_lor();
          setState(239);
          antlrcpp::downCast<Operation_lorContext *>(_localctx)->right = operation(3);
          break;
        }

        case 20: {
          auto newContext = _tracker.createInstance<Operation_ternaryContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->cond = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(241);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(242);
          match(TsilParser::QUESTION);
          setState(243);
          antlrcpp::downCast<Operation_ternaryContext *>(_localctx)->ifok = operation(0);
          setState(244);
          match(TsilParser::COLON);
          setState(245);
          antlrcpp::downCast<Operation_ternaryContext *>(_localctx)->ifnot = operation(2);
          break;
        }

        case 21: {
          auto newContext = _tracker.createInstance<Operation_asContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(247);

          if (!(precpred(_ctx, 26))) throw FailedPredicateException(this, "precpred(_ctx, 26)");
          setState(248);
          antlrcpp::downCast<Operation_asContext *>(_localctx)->op = match(TsilParser::KW_AS);
          setState(251);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case TsilParser::PAREN_OPEN:
            case TsilParser::ID: {
              setState(249);
              antlrcpp::downCast<Operation_asContext *>(_localctx)->right_type = type();
              break;
            }

            case TsilParser::KW_TSIL: {
              setState(250);
              antlrcpp::downCast<Operation_asContext *>(_localctx)->right_tsil = match(TsilParser::KW_TSIL);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          break;
        }

        case 22: {
          auto newContext = _tracker.createInstance<Operation_isContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(253);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(254);
          antlrcpp::downCast<Operation_isContext *>(_localctx)->op = match(TsilParser::KW_IS);
          setState(255);
          antlrcpp::downCast<Operation_isContext *>(_localctx)->right = type();
          break;
        }

        default:
          break;
        } 
      }
      setState(260);
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
    setState(261);
    match(TsilParser::LESSER);
    setState(262);
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
    setState(264);
    match(TsilParser::GREATER);
    setState(265);
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
    setState(267);
    match(TsilParser::GREATER);
    setState(268);
    match(TsilParser::GREATER);
    setState(269);
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
    setState(271);
    match(TsilParser::LESSER);
    setState(272);
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
    setState(274);
    match(TsilParser::GREATER);
    setState(275);
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
    setState(277);
    match(TsilParser::EQUAL);
    setState(278);
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
    setState(280);
    match(TsilParser::EXCLAMATION);
    setState(281);
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
    setState(283);
    match(TsilParser::AND);
    setState(284);
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
    setState(286);
    match(TsilParser::OR);
    setState(287);
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
    setState(289);
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
    setState(309);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TsilParser::Expr_operationContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(291);
      operation(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TsilParser::Expr_objectContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(292);
      simple_type(0);
      setState(293);
      match(TsilParser::QUOTE_OPEN);
      setState(305);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 36) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 36)) & 3232006663) != 0)) {
        setState(294);
        object_arg();
        setState(299);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(295);
            match(TsilParser::COMA);
            setState(296);
            object_arg(); 
          }
          setState(301);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
        }
        setState(303);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TsilParser::COMA) {
          setState(302);
          match(TsilParser::COMA);
        }
      }
      setState(307);
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
    setState(322);
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
        setState(313);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          setState(311);
          antlrcpp::downCast<Object_argContext *>(_localctx)->id = match(TsilParser::ID);
          setState(312);
          match(TsilParser::EQUAL);
          break;
        }

        default:
          break;
        }
        setState(317);
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
            setState(315);
            antlrcpp::downCast<Object_argContext *>(_localctx)->value_expr = expr();
            break;
          }

          case TsilParser::QUOTE_OPEN: {
            setState(316);
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
        setState(319);
        antlrcpp::downCast<Object_argContext *>(_localctx)->autofill = match(TsilParser::DOT);
        setState(320);
        match(TsilParser::DOT);
        setState(321);
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
    setState(324);
    match(TsilParser::QUOTE_OPEN);
    setState(336);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 36) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 36)) & 3232006663) != 0)) {
      setState(325);
      object_arg();
      setState(330);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(326);
          match(TsilParser::COMA);
          setState(327);
          object_arg(); 
        }
        setState(332);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
      }
      setState(334);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TsilParser::COMA) {
        setState(333);
        match(TsilParser::COMA);
      }
    }
    setState(338);
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
    setState(340);
    match(TsilParser::KW_STRUCT);
    setState(341);
    antlrcpp::downCast<Structure_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(353);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(342);
      match(TsilParser::LESSER);
      setState(343);
      antlrcpp::downCast<Structure_defineContext *>(_localctx)->first_gendef = gendef();
      setState(348);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(344);
        match(TsilParser::COMA);
        setState(345);
        gendef();
        setState(350);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(351);
      match(TsilParser::GREATER);
    }
    setState(364);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::SEMICOLON: {
        setState(355);
        match(TsilParser::SEMICOLON);
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(356);
        match(TsilParser::QUOTE_OPEN);
        setState(360);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == TsilParser::ID) {
          setState(357);
          structure_element();
          setState(362);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(363);
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
    setState(366);
    param();
    setState(367);
    match(TsilParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_defineContext ------------------------------------------------------------------

TsilParser::Enum_defineContext::Enum_defineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Enum_defineContext::KW_ENUM() {
  return getToken(TsilParser::KW_ENUM, 0);
}

tree::TerminalNode* TsilParser::Enum_defineContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::Enum_defineContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

tree::TerminalNode* TsilParser::Enum_defineContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::Enum_defineContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}

std::vector<TsilParser::Enum_elementContext *> TsilParser::Enum_defineContext::enum_element() {
  return getRuleContexts<TsilParser::Enum_elementContext>();
}

TsilParser::Enum_elementContext* TsilParser::Enum_defineContext::enum_element(size_t i) {
  return getRuleContext<TsilParser::Enum_elementContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Enum_defineContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Enum_defineContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::Enum_defineContext::getRuleIndex() const {
  return TsilParser::RuleEnum_define;
}

void TsilParser::Enum_defineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_define(this);
}

void TsilParser::Enum_defineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_define(this);
}


std::any TsilParser::Enum_defineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitEnum_define(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Enum_defineContext* TsilParser::enum_define() {
  Enum_defineContext *_localctx = _tracker.createInstance<Enum_defineContext>(_ctx, getState());
  enterRule(_localctx, 40, TsilParser::RuleEnum_define);
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
    setState(369);
    match(TsilParser::KW_ENUM);
    setState(370);
    antlrcpp::downCast<Enum_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(387);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::SEMICOLON: {
        setState(371);
        match(TsilParser::SEMICOLON);
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(372);
        match(TsilParser::QUOTE_OPEN);
        setState(384);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TsilParser::ID) {
          setState(373);
          enum_element();
          setState(378);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(374);
              match(TsilParser::COMA);
              setState(375);
              enum_element(); 
            }
            setState(380);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
          }
          setState(382);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == TsilParser::COMA) {
            setState(381);
            match(TsilParser::COMA);
          }
        }
        setState(386);
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

//----------------- Enum_elementContext ------------------------------------------------------------------

TsilParser::Enum_elementContext::Enum_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Enum_elementContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::Enum_elementContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::Enum_elementContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}

std::vector<TsilParser::ParamContext *> TsilParser::Enum_elementContext::param() {
  return getRuleContexts<TsilParser::ParamContext>();
}

TsilParser::ParamContext* TsilParser::Enum_elementContext::param(size_t i) {
  return getRuleContext<TsilParser::ParamContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Enum_elementContext::SEMICOLON() {
  return getTokens(TsilParser::SEMICOLON);
}

tree::TerminalNode* TsilParser::Enum_elementContext::SEMICOLON(size_t i) {
  return getToken(TsilParser::SEMICOLON, i);
}


size_t TsilParser::Enum_elementContext::getRuleIndex() const {
  return TsilParser::RuleEnum_element;
}

void TsilParser::Enum_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_element(this);
}

void TsilParser::Enum_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_element(this);
}


std::any TsilParser::Enum_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitEnum_element(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Enum_elementContext* TsilParser::enum_element() {
  Enum_elementContext *_localctx = _tracker.createInstance<Enum_elementContext>(_ctx, getState());
  enterRule(_localctx, 42, TsilParser::RuleEnum_element);
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
    setState(389);
    antlrcpp::downCast<Enum_elementContext *>(_localctx)->id = match(TsilParser::ID);
    setState(400);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::QUOTE_OPEN) {
      setState(390);
      match(TsilParser::QUOTE_OPEN);
      setState(396);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::ID) {
        setState(391);
        param();
        setState(392);
        match(TsilParser::SEMICOLON);
        setState(398);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(399);
      match(TsilParser::QUOTE_CLOSE);
    }
   
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
  enterRule(_localctx, 44, TsilParser::RuleDiia_define);
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
    setState(405);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(402);
        antlrcpp::downCast<Diia_defineContext *>(_localctx)->extern_ = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(403);
        antlrcpp::downCast<Diia_defineContext *>(_localctx)->local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(404);
        antlrcpp::downCast<Diia_defineContext *>(_localctx)->intern = match(TsilParser::KW_PRIVATE);
        break;
      }

      case TsilParser::KW_DIIA: {
        break;
      }

    default:
      break;
    }
    setState(407);
    match(TsilParser::KW_DIIA);
    setState(408);
    antlrcpp::downCast<Diia_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(420);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(409);
      match(TsilParser::LESSER);
      setState(410);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->first_gendef = gendef();
      setState(415);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(411);
        match(TsilParser::COMA);
        setState(412);
        gendef();
        setState(417);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(418);
      match(TsilParser::GREATER);
    }
    setState(422);
    match(TsilParser::PAREN_OPEN);
    setState(431);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(423);
      param();
      setState(428);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(424);
        match(TsilParser::COMA);
        setState(425);
        param();
        setState(430);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(433);
    match(TsilParser::PAREN_CLOSE);
    setState(436);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(434);
      match(TsilParser::COLON);
      setState(435);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->restyp = type();
    }
    setState(440);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::SEMICOLON: {
        setState(438);
        match(TsilParser::SEMICOLON);
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(439);
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
  enterRule(_localctx, 46, TsilParser::RuleTsil_define);
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
    setState(445);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(442);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_external = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(443);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(444);
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
    setState(449);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_VAR: {
        setState(447);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_var = match(TsilParser::KW_VAR);
        break;
      }

      case TsilParser::KW_IMMUT: {
        setState(448);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_immut = match(TsilParser::KW_IMMUT);
        break;
      }

      case TsilParser::KW_TSIL: {
        break;
      }

    default:
      break;
    }
    setState(451);
    match(TsilParser::KW_TSIL);
    setState(452);
    antlrcpp::downCast<Tsil_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(455);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(453);
      match(TsilParser::COLON);
      setState(454);
      type();
    }
    setState(462);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::EQUAL) {
      setState(457);
      match(TsilParser::EQUAL);
      setState(460);
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
          setState(458);
          antlrcpp::downCast<Tsil_defineContext *>(_localctx)->value_expr = expr();
          break;
        }

        case TsilParser::QUOTE_OPEN: {
          setState(459);
          antlrcpp::downCast<Tsil_defineContext *>(_localctx)->value_object = typeless_object();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
    }
    setState(464);
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
  enterRule(_localctx, 48, TsilParser::RuleAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(466);
    antlrcpp::downCast<AssignContext *>(_localctx)->id = match(TsilParser::ID);
    setState(467);
    assign_op();
    setState(470);
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
        setState(468);
        antlrcpp::downCast<AssignContext *>(_localctx)->value_expr = expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(469);
        antlrcpp::downCast<AssignContext *>(_localctx)->value_object = typeless_object();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(472);
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
  enterRule(_localctx, 50, TsilParser::RuleSynonym);
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
    setState(474);
    match(TsilParser::KW_SYNONYM);
    setState(475);
    antlrcpp::downCast<SynonymContext *>(_localctx)->id = match(TsilParser::ID);
    setState(487);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(476);
      match(TsilParser::LESSER);
      setState(477);
      antlrcpp::downCast<SynonymContext *>(_localctx)->first_gendef = gendef();
      setState(482);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(478);
        match(TsilParser::COMA);
        setState(479);
        gendef();
        setState(484);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(485);
      match(TsilParser::GREATER);
    }
    setState(489);
    match(TsilParser::EQUAL);
    setState(493);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      setState(490);
      antlrcpp::downCast<SynonymContext *>(_localctx)->value_expr = expr();
      break;
    }

    case 2: {
      setState(491);
      antlrcpp::downCast<SynonymContext *>(_localctx)->value_object = typeless_object();
      break;
    }

    case 3: {
      setState(492);
      antlrcpp::downCast<SynonymContext *>(_localctx)->value_type = type();
      break;
    }

    default:
      break;
    }
    setState(495);
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
  enterRule(_localctx, 52, TsilParser::RuleSynonym_fn);
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
    setState(497);
    match(TsilParser::KW_SYNONYM);
    setState(498);
    antlrcpp::downCast<Synonym_fnContext *>(_localctx)->id = match(TsilParser::ID);
    setState(510);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(499);
      match(TsilParser::LESSER);
      setState(500);
      antlrcpp::downCast<Synonym_fnContext *>(_localctx)->first_gendef = gendef();
      setState(505);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(501);
        match(TsilParser::COMA);
        setState(502);
        gendef();
        setState(507);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(508);
      match(TsilParser::GREATER);
    }
    setState(512);
    match(TsilParser::PAREN_OPEN);
    setState(513);
    match(TsilParser::PAREN_CLOSE);
    setState(514);
    match(TsilParser::EQUAL);
    setState(515);
    match(TsilParser::GREATER);
    setState(519);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
    case 1: {
      setState(516);
      antlrcpp::downCast<Synonym_fnContext *>(_localctx)->value_expr = expr();
      break;
    }

    case 2: {
      setState(517);
      antlrcpp::downCast<Synonym_fnContext *>(_localctx)->value_object = typeless_object();
      break;
    }

    case 3: {
      setState(518);
      antlrcpp::downCast<Synonym_fnContext *>(_localctx)->value_type = type();
      break;
    }

    default:
      break;
    }
    setState(521);
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
  enterRule(_localctx, 54, TsilParser::RuleSection_define);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(523);
    match(TsilParser::KW_SECTION);
    setState(524);
    antlrcpp::downCast<Section_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(526);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      setState(525);
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
  enterRule(_localctx, 56, TsilParser::RuleSet);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(528);
    antlrcpp::downCast<SetContext *>(_localctx)->object = atom(0);
    setState(529);
    match(TsilParser::DOT);
    setState(530);
    antlrcpp::downCast<SetContext *>(_localctx)->id = match(TsilParser::ID);
    setState(531);
    assign_op();
    setState(534);
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
        setState(532);
        antlrcpp::downCast<SetContext *>(_localctx)->value_expr = expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(533);
        antlrcpp::downCast<SetContext *>(_localctx)->value_object = typeless_object();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(536);
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
  enterRule(_localctx, 58, TsilParser::RulePosition_set);

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
    antlrcpp::downCast<Position_setContext *>(_localctx)->object = atom(0);
    setState(539);
    match(TsilParser::BRACKET_OPEN);
    setState(540);
    antlrcpp::downCast<Position_setContext *>(_localctx)->idx = expr();
    setState(541);
    match(TsilParser::BRACKET_CLOSE);
    setState(542);
    assign_op();
    setState(545);
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
        setState(543);
        antlrcpp::downCast<Position_setContext *>(_localctx)->value_expr = expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(544);
        antlrcpp::downCast<Position_setContext *>(_localctx)->value_object = typeless_object();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
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
  enterRule(_localctx, 60, TsilParser::RuleSection_set);

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
    antlrcpp::downCast<Section_setContext *>(_localctx)->object = atom(0);
    setState(550);
    match(TsilParser::COLON);
    setState(551);
    match(TsilParser::COLON);
    setState(552);
    antlrcpp::downCast<Section_setContext *>(_localctx)->id = match(TsilParser::ID);
    setState(553);
    assign_op();
    setState(556);
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
        setState(554);
        antlrcpp::downCast<Section_setContext *>(_localctx)->value_expr = expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(555);
        antlrcpp::downCast<Section_setContext *>(_localctx)->value_object = typeless_object();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(558);
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
  enterRule(_localctx, 62, TsilParser::RuleAssign_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(571);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
    case 1: {
      setState(560);
      antlrcpp::downCast<Assign_opContext *>(_localctx)->aop_mul = match(TsilParser::MULTIPLY);
      break;
    }

    case 2: {
      setState(561);
      antlrcpp::downCast<Assign_opContext *>(_localctx)->aop_div = match(TsilParser::DIVIDE);
      break;
    }

    case 3: {
      setState(562);
      antlrcpp::downCast<Assign_opContext *>(_localctx)->aop_mod = match(TsilParser::MOD);
      break;
    }

    case 4: {
      setState(563);
      antlrcpp::downCast<Assign_opContext *>(_localctx)->aop_plus = match(TsilParser::PLUS);
      break;
    }

    case 5: {
      setState(564);
      antlrcpp::downCast<Assign_opContext *>(_localctx)->aop_minus = match(TsilParser::MINUS);
      break;
    }

    case 6: {
      setState(565);
      op_lshift();
      break;
    }

    case 7: {
      setState(566);
      op_rshift();
      break;
    }

    case 8: {
      setState(567);
      op_urshift();
      break;
    }

    case 9: {
      setState(568);
      antlrcpp::downCast<Assign_opContext *>(_localctx)->aop_and = match(TsilParser::AND);
      break;
    }

    case 10: {
      setState(569);
      antlrcpp::downCast<Assign_opContext *>(_localctx)->aop_xor = match(TsilParser::POWER);
      break;
    }

    case 11: {
      setState(570);
      antlrcpp::downCast<Assign_opContext *>(_localctx)->aop_or = match(TsilParser::OR);
      break;
    }

    default:
      break;
    }
    setState(573);
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
  enterRule(_localctx, 64, TsilParser::RuleIf);
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
    setState(575);
    match(TsilParser::KW_IF);
    setState(576);
    antlrcpp::downCast<IfContext *>(_localctx)->cond = operation(0);
    setState(577);
    antlrcpp::downCast<IfContext *>(_localctx)->ifok = body();
    setState(583);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::KW_ELSE) {
      setState(578);
      match(TsilParser::KW_ELSE);
      setState(581);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TsilParser::QUOTE_OPEN: {
          setState(579);
          antlrcpp::downCast<IfContext *>(_localctx)->ifnot = body();
          break;
        }

        case TsilParser::KW_IF: {
          setState(580);
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
  enterRule(_localctx, 66, TsilParser::RuleWhile);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(585);
    match(TsilParser::KW_WHILE);
    setState(586);
    antlrcpp::downCast<WhileContext *>(_localctx)->cond = operation(0);
    setState(587);
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
  enterRule(_localctx, 68, TsilParser::RuleExec);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(589);
    match(TsilParser::KW_EXEC);
    setState(590);
    body();
    setState(591);
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
  enterRule(_localctx, 70, TsilParser::RuleBody);
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
    setState(593);
    match(TsilParser::QUOTE_OPEN);
    setState(597);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 812937530126571886) != 0) || _la == TsilParser::ID

    || _la == TsilParser::STRING) {
      setState(594);
      body_element();
      setState(599);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(600);
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

TsilParser::Enum_defineContext* TsilParser::Body_elementContext::enum_define() {
  return getRuleContext<TsilParser::Enum_defineContext>(0);
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

TsilParser::LabelContext* TsilParser::Body_elementContext::label() {
  return getRuleContext<TsilParser::LabelContext>(0);
}

TsilParser::GotoContext* TsilParser::Body_elementContext::goto_() {
  return getRuleContext<TsilParser::GotoContext>(0);
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
  enterRule(_localctx, 72, TsilParser::RuleBody_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(626);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(602);
      structure_define();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(603);
      enum_define();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(604);
      diia_define();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(605);
      tsil_define();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(606);
      assign();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(607);
      set();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(608);
      section_set();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(609);
      position_set();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(610);
      synonym();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(611);
      synonym_fn();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(612);
      section_define();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(613);
      if_();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(614);
      while_();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(615);
      expr();
      setState(616);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(618);
      body();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(619);
      exec();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(620);
      return_();
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(621);
      preproc();
      break;
    }

    case 19: {
      enterOuterAlt(_localctx, 19);
      setState(622);
      take();
      break;
    }

    case 20: {
      enterOuterAlt(_localctx, 20);
      setState(623);
      label();
      break;
    }

    case 21: {
      enterOuterAlt(_localctx, 21);
      setState(624);
      goto_();
      break;
    }

    case 22: {
      enterOuterAlt(_localctx, 22);
      setState(625);
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
  enterRule(_localctx, 74, TsilParser::RuleReturn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(628);
    match(TsilParser::KW_RETURN);
    setState(631);
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
        setState(629);
        antlrcpp::downCast<ReturnContext *>(_localctx)->value_expr = expr();
        break;
      }

      case TsilParser::QUOTE_OPEN: {
        setState(630);
        antlrcpp::downCast<ReturnContext *>(_localctx)->value_object = typeless_object();
        break;
      }

      case TsilParser::SEMICOLON: {
        break;
      }

    default:
      break;
    }
    setState(633);
    match(TsilParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelContext ------------------------------------------------------------------

TsilParser::LabelContext::LabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::LabelContext::COLON() {
  return getToken(TsilParser::COLON, 0);
}

tree::TerminalNode* TsilParser::LabelContext::ID() {
  return getToken(TsilParser::ID, 0);
}


size_t TsilParser::LabelContext::getRuleIndex() const {
  return TsilParser::RuleLabel;
}

void TsilParser::LabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabel(this);
}

void TsilParser::LabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabel(this);
}


std::any TsilParser::LabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitLabel(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::LabelContext* TsilParser::label() {
  LabelContext *_localctx = _tracker.createInstance<LabelContext>(_ctx, getState());
  enterRule(_localctx, 76, TsilParser::RuleLabel);

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
    antlrcpp::downCast<LabelContext *>(_localctx)->id = match(TsilParser::ID);
    setState(636);
    match(TsilParser::COLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GotoContext ------------------------------------------------------------------

TsilParser::GotoContext::GotoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::GotoContext::KW_GOTO() {
  return getToken(TsilParser::KW_GOTO, 0);
}

tree::TerminalNode* TsilParser::GotoContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

tree::TerminalNode* TsilParser::GotoContext::ID() {
  return getToken(TsilParser::ID, 0);
}


size_t TsilParser::GotoContext::getRuleIndex() const {
  return TsilParser::RuleGoto;
}

void TsilParser::GotoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGoto(this);
}

void TsilParser::GotoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGoto(this);
}


std::any TsilParser::GotoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitGoto(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::GotoContext* TsilParser::goto_() {
  GotoContext *_localctx = _tracker.createInstance<GotoContext>(_ctx, getState());
  enterRule(_localctx, 78, TsilParser::RuleGoto);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(638);
    match(TsilParser::KW_GOTO);
    setState(639);
    antlrcpp::downCast<GotoContext *>(_localctx)->id = match(TsilParser::ID);
    setState(640);
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
  size_t startState = 80;
  enterRecursionRule(_localctx, 80, TsilParser::RuleSimple_type, precedence);

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

    setState(643);
    antlrcpp::downCast<Simple_type_subjectContext *>(_localctx)->id = match(TsilParser::ID);
    _ctx->stop = _input->LT(-1);
    setState(670);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(668);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Simple_type_section_getContext>(_tracker.createInstance<Simple_typeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleSimple_type);
          setState(645);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(646);
          match(TsilParser::COLON);
          setState(647);
          match(TsilParser::COLON);
          setState(648);
          antlrcpp::downCast<Simple_type_section_getContext *>(_localctx)->id = match(TsilParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Simple_type_template_getContext>(_tracker.createInstance<Simple_typeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleSimple_type);
          setState(649);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(650);
          match(TsilParser::LESSER);
          setState(651);
          type();
          setState(656);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == TsilParser::COMA) {
            setState(652);
            match(TsilParser::COMA);
            setState(653);
            type();
            setState(658);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(659);
          match(TsilParser::GREATER);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Simple_type_getContext>(_tracker.createInstance<Simple_typeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleSimple_type);
          setState(661);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(662);
          match(TsilParser::DOT);
          setState(663);
          antlrcpp::downCast<Simple_type_getContext *>(_localctx)->id = match(TsilParser::ID);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Simple_type_arrayContext>(_tracker.createInstance<Simple_typeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleSimple_type);
          setState(664);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(665);
          match(TsilParser::BRACKET_OPEN);
          setState(666);
          antlrcpp::downCast<Simple_type_arrayContext *>(_localctx)->size = match(TsilParser::NUMBER);
          setState(667);
          match(TsilParser::BRACKET_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(672);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
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
  size_t startState = 82;
  enterRecursionRule(_localctx, 82, TsilParser::RuleSingle_type, precedence);

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
    setState(708);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Type_simple_typeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(674);
      simple_type(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Type_fnContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(675);
      match(TsilParser::PAREN_OPEN);
      setState(676);
      match(TsilParser::PAREN_CLOSE);
      setState(677);
      match(TsilParser::MINUS);
      setState(678);
      match(TsilParser::GREATER);
      setState(679);
      antlrcpp::downCast<Type_fnContext *>(_localctx)->restyp = type();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Type_fn_complexContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(680);
      match(TsilParser::PAREN_OPEN);
      setState(681);
      type();
      setState(686);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(682);
        match(TsilParser::COMA);
        setState(683);
        type();
        setState(688);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(689);
      match(TsilParser::PAREN_CLOSE);
      setState(690);
      match(TsilParser::MINUS);
      setState(691);
      match(TsilParser::GREATER);
      setState(692);
      antlrcpp::downCast<Type_fn_complexContext *>(_localctx)->restyp = type();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Type_fn_complex_namedContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(694);
      match(TsilParser::PAREN_OPEN);
      setState(695);
      param();
      setState(700);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(696);
        match(TsilParser::COMA);
        setState(697);
        param();
        setState(702);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(703);
      match(TsilParser::PAREN_CLOSE);
      setState(704);
      match(TsilParser::MINUS);
      setState(705);
      match(TsilParser::GREATER);
      setState(706);
      antlrcpp::downCast<Type_fn_complex_namedContext *>(_localctx)->restyp = type();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(716);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Type_fn_simpleContext>(_tracker.createInstance<Single_typeContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->param_type = previousContext;
        pushNewRecursionContext(newContext, startState, RuleSingle_type);
        setState(710);

        if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
        setState(711);
        match(TsilParser::MINUS);
        setState(712);
        match(TsilParser::GREATER);
        setState(713);
        antlrcpp::downCast<Type_fn_simpleContext *>(_localctx)->restyp = type(); 
      }
      setState(718);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
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
  enterRule(_localctx, 84, TsilParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(731);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TsilParser::Type_nestedContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(719);
      match(TsilParser::PAREN_OPEN);
      setState(720);
      type();
      setState(721);
      match(TsilParser::PAREN_CLOSE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TsilParser::Type_singleContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(723);
      single_type(0);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<TsilParser::Type_variationContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(724);
      single_type(0);
      setState(727); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(725);
                match(TsilParser::OR);
                setState(726);
                single_type(0);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(729); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
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
  enterRule(_localctx, 86, TsilParser::RuleParam);
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
    setState(733);
    antlrcpp::downCast<ParamContext *>(_localctx)->id = match(TsilParser::ID);
    setState(736);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(734);
      match(TsilParser::COLON);
      setState(735);
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
  enterRule(_localctx, 88, TsilParser::RulePreproc);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(773);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TsilParser::Preproc_ifContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(738);
      match(TsilParser::MOD);
      setState(739);
      match(TsilParser::BRACKET_OPEN);
      setState(740);
      match(TsilParser::KW_IF);
      setState(741);
      antlrcpp::downCast<Preproc_ifContext *>(_localctx)->cond = operation(0);
      setState(742);
      match(TsilParser::BRACKET_CLOSE);
      setState(746);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(743);
          body_element(); 
        }
        setState(748);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
      }
      setState(759);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx)) {
      case 1: {
        setState(749);
        match(TsilParser::MOD);
        setState(750);
        match(TsilParser::BRACKET_OPEN);
        setState(751);
        match(TsilParser::KW_ELSE);
        setState(752);
        match(TsilParser::BRACKET_CLOSE);
        setState(756);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(753);
            body_element(); 
          }
          setState(758);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
        }
        break;
      }

      default:
        break;
      }
      setState(761);
      match(TsilParser::MOD);
      setState(762);
      match(TsilParser::BRACKET_OPEN);
      setState(763);
      match(TsilParser::DIVIDE);
      setState(764);
      match(TsilParser::KW_IF);
      setState(765);
      match(TsilParser::BRACKET_CLOSE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TsilParser::Preproc_throwContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(767);
      match(TsilParser::MOD);
      setState(768);
      match(TsilParser::BRACKET_OPEN);
      setState(769);
      match(TsilParser::KW_THROW);
      setState(770);
      antlrcpp::downCast<Preproc_throwContext *>(_localctx)->cond = operation(0);
      setState(771);
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
  enterRule(_localctx, 90, TsilParser::RuleTake);
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
    setState(775);
    match(TsilParser::KW_IMPORT);
    setState(777);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx)) {
    case 1: {
      setState(776);
      antlrcpp::downCast<TakeContext *>(_localctx)->type_id = match(TsilParser::ID);
      break;
    }

    default:
      break;
    }
    setState(781);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::DOT) {
      setState(779);
      antlrcpp::downCast<TakeContext *>(_localctx)->relative = match(TsilParser::DOT);
      setState(780);
      match(TsilParser::DIVIDE);
    }
    setState(783);
    take_element();
    setState(788);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TsilParser::DIVIDE) {
      setState(784);
      match(TsilParser::DIVIDE);
      setState(785);
      take_element();
      setState(790);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(791);
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
  enterRule(_localctx, 92, TsilParser::RuleTake_element);
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
    setState(793);
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
    case 40: return simple_typeSempred(antlrcpp::downCast<Simple_typeContext *>(context), predicateIndex);
    case 41: return single_typeSempred(antlrcpp::downCast<Single_typeContext *>(context), predicateIndex);

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
    case 17: return precpred(_ctx, 8);
    case 18: return precpred(_ctx, 7);
    case 19: return precpred(_ctx, 6);
    case 20: return precpred(_ctx, 5);
    case 21: return precpred(_ctx, 4);
    case 22: return precpred(_ctx, 3);
    case 23: return precpred(_ctx, 2);
    case 24: return precpred(_ctx, 1);
    case 25: return precpred(_ctx, 26);
    case 26: return precpred(_ctx, 9);

  default:
    break;
  }
  return true;
}

bool TsilParser::simple_typeSempred(Simple_typeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 27: return precpred(_ctx, 4);
    case 28: return precpred(_ctx, 3);
    case 29: return precpred(_ctx, 2);
    case 30: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool TsilParser::single_typeSempred(Single_typeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 31: return precpred(_ctx, 3);

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
