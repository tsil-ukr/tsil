
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
      "diia_generics", "diia_generic", "section", "section_element", "if", 
      "while", "define", "assign", "set", "sizeof", "atom", "molecule", 
      "expr", "identifiers_chain", "full_type", "simple_function_type_args", 
      "args", "params", "param", "body", "body_element_or_return", "body_element", 
      "return_body_element", "bitwise_op", "comparison_op", "logical_op", 
      "number", "string", "identifier"
    },
    std::vector<std::string>{
      "", "'\\u0446\\u0456\\u043B\\u044C'", "'\\u0434\\u0456\\u044F'", "'\\u044F\\u043A\\u0449\\u043E'", 
      "'\\u0456\\u043D\\u0430\\u043A\\u0448\\u0435'", "'\\u043F\\u043E\\u043A\\u0438'", 
      "'\\u0432\\u0435\\u0440\\u043D\\u0443\\u0442\\u0438'", "'\\u0441\\u0442\\u0440\\u0443\\u043A\\u0442\\u0443\\u0440\\u0430'", 
      "'\\u044F\\u043A'", "'\\u0440\\u043E\\u0437\\u043C\\u0456\\u0440!'", 
      "'\\u0441\\u0435\\u043A\\u0446\\u0456\\u044F'", "'\\u0432\\u0437\\u044F\\u0442\\u0438'", 
      "'\\u0434\\u0430\\u0442\\u0438'", "'\\u043A\\u043E\\u043C\\u043F\\u043E\\u0437\\u0438\\u0446\\u0456\\u044F'", 
      "'\\u0432\\u043B\\u0430\\u0441\\u0442\\u0438\\u0432\\u0456\\u0441\\u0442\\u044C'", 
      "'\\u0437\\u043E\\u0432\\u043D\\u0456\\u0448\\u043D\\u044F'", "'\\u0432\\u043D\\u0443\\u0442\\u0440\\u0456\\u0448\\u043D\\u044F'", 
      "'\\u043C\\u0456\\u0441\\u0446\\u0435\\u0432\\u0430'", "'\\u043D\\u0435'", 
      "'\\u0430\\u0431\\u043E'", "'\\u0456'", "'='", "'>'", "'<'", "'.'", 
      "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'&'", "'|'", "'('", "')'", 
      "'['", "']'", "'\\u003F'", "':'", "'~'", "'''", "'\"'", "'!'", "','", 
      "';'", "'{'", "'}'"
    },
    std::vector<std::string>{
      "", "KW_TSIL", "KW_DIIA", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_RETURN", 
      "KW_STRUCT", "KW_AS", "KW_SIZEOF", "KW_SECTION", "KW_IMPORT", "KW_EXPORT", 
      "KW_COMPOSITION", "KW_PROPERTY", "KW_PUBLIC", "KW_PRIVATE", "KW_LOCAL", 
      "KW_NOT", "KW_OR", "KW_AND", "EQUAL", "GREATER", "LESSER", "DOT", 
      "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MOD", "POWER", "AND", "OR", 
      "PAREN_OPEN", "PAREN_CLOSE", "BRACKET_OPEN", "BRACKET_CLOSE", "QUESTION", 
      "COLON", "TILDA", "QUOTE", "DOUBLE_QUOTE", "EXCLAMATION", "COMA", 
      "SEMICOLON", "QUOTE_OPEN", "QUOTE_CLOSE", "INTEGER", "FLOAT", "HEX", 
      "BIN", "ID", "STRING", "COMMENT", "LINE_COMMENT", "NL", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,56,543,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,1,0,1,0,1,0,1,1,5,1,91,8,1,10,1,12,1,94,9,1,1,2,1,2,1,2,1,2,1,2,3,
  	2,101,8,2,1,3,1,3,1,3,1,3,1,3,1,3,3,3,109,8,3,1,3,1,3,3,3,113,8,3,1,3,
  	1,3,1,4,1,4,1,4,5,4,120,8,4,10,4,12,4,123,9,4,1,5,1,5,1,6,1,6,1,6,5,6,
  	130,8,6,10,6,12,6,133,9,6,1,6,3,6,136,8,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,
  	3,8,145,8,8,1,8,1,8,1,9,1,9,1,9,5,9,152,8,9,10,9,12,9,155,9,9,1,9,3,9,
  	158,8,9,1,10,1,10,1,10,3,10,163,8,10,1,10,1,10,1,11,1,11,1,11,1,11,1,
  	11,1,11,3,11,173,8,11,1,11,1,11,3,11,177,8,11,1,11,1,11,1,11,1,11,3,11,
  	183,8,11,1,11,1,11,1,11,1,11,3,11,189,8,11,1,12,1,12,1,12,3,12,194,8,
  	12,1,12,1,12,1,12,3,12,199,8,12,1,12,1,12,1,13,1,13,1,13,3,13,206,8,13,
  	1,13,1,13,1,13,3,13,211,8,13,1,13,1,13,1,14,1,14,1,14,5,14,218,8,14,10,
  	14,12,14,221,9,14,1,15,1,15,1,16,1,16,1,16,1,16,5,16,229,8,16,10,16,12,
  	16,232,9,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,3,17,241,8,17,1,18,1,18,
  	1,18,1,18,3,18,247,8,18,1,18,1,18,1,18,1,18,3,18,253,8,18,1,18,3,18,256,
  	8,18,1,19,1,19,1,19,1,19,3,19,262,8,19,1,19,1,19,1,20,1,20,1,20,1,20,
  	3,20,270,8,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,280,8,20,1,
  	21,1,21,1,21,1,21,1,22,1,22,1,22,1,22,1,22,1,22,1,23,1,23,1,23,1,23,3,
  	23,296,8,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,
  	24,1,24,1,24,1,24,1,24,3,24,314,8,24,1,24,1,24,1,24,1,24,1,24,1,24,1,
  	24,1,24,5,24,324,8,24,10,24,12,24,327,9,24,1,24,1,24,3,24,331,8,24,1,
  	24,1,24,3,24,335,8,24,1,24,1,24,1,24,1,24,3,24,341,8,24,1,24,5,24,344,
  	8,24,10,24,12,24,347,9,24,1,25,1,25,1,25,3,25,352,8,25,1,26,1,26,1,26,
  	1,26,1,26,1,26,1,26,1,26,1,26,1,26,3,26,364,8,26,1,26,1,26,1,26,1,26,
  	1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,
  	5,26,384,8,26,10,26,12,26,387,9,26,1,27,1,27,1,27,1,27,1,27,1,27,5,27,
  	395,8,27,10,27,12,27,398,9,27,1,28,1,28,1,28,1,28,1,28,1,28,5,28,406,
  	8,28,10,28,12,28,409,9,28,1,28,1,28,3,28,413,8,28,1,28,1,28,3,28,417,
  	8,28,1,28,1,28,1,28,1,28,3,28,423,8,28,1,28,1,28,1,28,1,28,1,28,1,28,
  	1,28,1,28,1,28,5,28,434,8,28,10,28,12,28,437,9,28,1,29,1,29,1,29,5,29,
  	442,8,29,10,29,12,29,445,9,29,1,30,1,30,1,30,5,30,450,8,30,10,30,12,30,
  	453,9,30,1,30,3,30,456,8,30,1,31,1,31,1,31,5,31,461,8,31,10,31,12,31,
  	464,9,31,1,31,3,31,467,8,31,1,32,1,32,1,32,1,32,1,33,4,33,474,8,33,11,
  	33,12,33,475,1,34,1,34,1,34,1,34,3,34,482,8,34,1,35,1,35,1,35,1,35,1,
  	35,1,35,1,35,1,35,1,35,1,35,1,35,1,35,1,35,1,35,1,35,3,35,499,8,35,1,
  	36,1,36,3,36,503,8,36,1,37,1,37,1,37,1,37,1,37,1,37,1,37,3,37,512,8,37,
  	1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,3,38,524,8,38,1,39,
  	1,39,1,39,1,39,1,39,1,39,3,39,532,8,39,1,40,1,40,1,41,3,41,537,8,41,1,
  	41,1,41,1,42,1,42,1,42,0,4,48,52,54,56,43,0,2,4,6,8,10,12,14,16,18,20,
  	22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,
  	68,70,72,74,76,78,80,82,84,0,3,1,0,27,29,1,0,25,26,1,0,47,50,595,0,86,
  	1,0,0,0,2,92,1,0,0,0,4,100,1,0,0,0,6,102,1,0,0,0,8,116,1,0,0,0,10,124,
  	1,0,0,0,12,126,1,0,0,0,14,137,1,0,0,0,16,141,1,0,0,0,18,148,1,0,0,0,20,
  	162,1,0,0,0,22,166,1,0,0,0,24,193,1,0,0,0,26,205,1,0,0,0,28,214,1,0,0,
  	0,30,222,1,0,0,0,32,224,1,0,0,0,34,240,1,0,0,0,36,242,1,0,0,0,38,257,
  	1,0,0,0,40,279,1,0,0,0,42,281,1,0,0,0,44,285,1,0,0,0,46,291,1,0,0,0,48,
  	313,1,0,0,0,50,351,1,0,0,0,52,363,1,0,0,0,54,388,1,0,0,0,56,422,1,0,0,
  	0,58,438,1,0,0,0,60,446,1,0,0,0,62,457,1,0,0,0,64,468,1,0,0,0,66,473,
  	1,0,0,0,68,481,1,0,0,0,70,498,1,0,0,0,72,500,1,0,0,0,74,511,1,0,0,0,76,
  	523,1,0,0,0,78,531,1,0,0,0,80,533,1,0,0,0,82,536,1,0,0,0,84,540,1,0,0,
  	0,86,87,3,2,1,0,87,88,5,0,0,1,88,1,1,0,0,0,89,91,3,4,2,0,90,89,1,0,0,
  	0,91,94,1,0,0,0,92,90,1,0,0,0,92,93,1,0,0,0,93,3,1,0,0,0,94,92,1,0,0,
  	0,95,101,3,6,3,0,96,101,3,26,13,0,97,101,3,24,12,0,98,101,3,32,16,0,99,
  	101,5,44,0,0,100,95,1,0,0,0,100,96,1,0,0,0,100,97,1,0,0,0,100,98,1,0,
  	0,0,100,99,1,0,0,0,101,5,1,0,0,0,102,103,5,7,0,0,103,108,3,84,42,0,104,
  	105,5,23,0,0,105,106,3,8,4,0,106,107,5,22,0,0,107,109,1,0,0,0,108,104,
  	1,0,0,0,108,109,1,0,0,0,109,110,1,0,0,0,110,112,5,45,0,0,111,113,3,12,
  	6,0,112,111,1,0,0,0,112,113,1,0,0,0,113,114,1,0,0,0,114,115,5,46,0,0,
  	115,7,1,0,0,0,116,121,3,10,5,0,117,118,5,43,0,0,118,120,3,10,5,0,119,
  	117,1,0,0,0,120,123,1,0,0,0,121,119,1,0,0,0,121,122,1,0,0,0,122,9,1,0,
  	0,0,123,121,1,0,0,0,124,125,3,84,42,0,125,11,1,0,0,0,126,131,3,14,7,0,
  	127,128,5,43,0,0,128,130,3,14,7,0,129,127,1,0,0,0,130,133,1,0,0,0,131,
  	129,1,0,0,0,131,132,1,0,0,0,132,135,1,0,0,0,133,131,1,0,0,0,134,136,5,
  	43,0,0,135,134,1,0,0,0,135,136,1,0,0,0,136,13,1,0,0,0,137,138,3,84,42,
  	0,138,139,5,38,0,0,139,140,3,56,28,0,140,15,1,0,0,0,141,142,3,56,28,0,
  	142,144,5,45,0,0,143,145,3,18,9,0,144,143,1,0,0,0,144,145,1,0,0,0,145,
  	146,1,0,0,0,146,147,5,46,0,0,147,17,1,0,0,0,148,153,3,20,10,0,149,150,
  	5,43,0,0,150,152,3,20,10,0,151,149,1,0,0,0,152,155,1,0,0,0,153,151,1,
  	0,0,0,153,154,1,0,0,0,154,157,1,0,0,0,155,153,1,0,0,0,156,158,5,43,0,
  	0,157,156,1,0,0,0,157,158,1,0,0,0,158,19,1,0,0,0,159,160,3,84,42,0,160,
  	161,5,21,0,0,161,163,1,0,0,0,162,159,1,0,0,0,162,163,1,0,0,0,163,164,
  	1,0,0,0,164,165,3,52,26,0,165,21,1,0,0,0,166,167,5,2,0,0,167,172,3,84,
  	42,0,168,169,5,23,0,0,169,170,3,28,14,0,170,171,5,22,0,0,171,173,1,0,
  	0,0,172,168,1,0,0,0,172,173,1,0,0,0,173,174,1,0,0,0,174,176,5,33,0,0,
  	175,177,3,62,31,0,176,175,1,0,0,0,176,177,1,0,0,0,177,182,1,0,0,0,178,
  	179,5,43,0,0,179,180,5,24,0,0,180,181,5,24,0,0,181,183,5,24,0,0,182,178,
  	1,0,0,0,182,183,1,0,0,0,183,184,1,0,0,0,184,188,5,34,0,0,185,186,5,26,
  	0,0,186,187,5,22,0,0,187,189,3,56,28,0,188,185,1,0,0,0,188,189,1,0,0,
  	0,189,23,1,0,0,0,190,194,5,15,0,0,191,194,5,17,0,0,192,194,5,16,0,0,193,
  	190,1,0,0,0,193,191,1,0,0,0,193,192,1,0,0,0,193,194,1,0,0,0,194,195,1,
  	0,0,0,195,196,3,22,11,0,196,198,5,45,0,0,197,199,3,66,33,0,198,197,1,
  	0,0,0,198,199,1,0,0,0,199,200,1,0,0,0,200,201,5,46,0,0,201,25,1,0,0,0,
  	202,206,5,15,0,0,203,206,5,17,0,0,204,206,5,16,0,0,205,202,1,0,0,0,205,
  	203,1,0,0,0,205,204,1,0,0,0,205,206,1,0,0,0,206,207,1,0,0,0,207,210,3,
  	22,11,0,208,209,5,8,0,0,209,211,3,84,42,0,210,208,1,0,0,0,210,211,1,0,
  	0,0,211,212,1,0,0,0,212,213,5,44,0,0,213,27,1,0,0,0,214,219,3,30,15,0,
  	215,216,5,43,0,0,216,218,3,30,15,0,217,215,1,0,0,0,218,221,1,0,0,0,219,
  	217,1,0,0,0,219,220,1,0,0,0,220,29,1,0,0,0,221,219,1,0,0,0,222,223,3,
  	84,42,0,223,31,1,0,0,0,224,225,5,10,0,0,225,226,3,84,42,0,226,230,5,45,
  	0,0,227,229,3,34,17,0,228,227,1,0,0,0,229,232,1,0,0,0,230,228,1,0,0,0,
  	230,231,1,0,0,0,231,233,1,0,0,0,232,230,1,0,0,0,233,234,5,46,0,0,234,
  	33,1,0,0,0,235,241,3,6,3,0,236,241,3,26,13,0,237,241,3,24,12,0,238,241,
  	3,32,16,0,239,241,5,44,0,0,240,235,1,0,0,0,240,236,1,0,0,0,240,237,1,
  	0,0,0,240,238,1,0,0,0,240,239,1,0,0,0,241,35,1,0,0,0,242,243,5,3,0,0,
  	243,244,3,52,26,0,244,246,5,45,0,0,245,247,3,66,33,0,246,245,1,0,0,0,
  	246,247,1,0,0,0,247,248,1,0,0,0,248,255,5,46,0,0,249,250,5,4,0,0,250,
  	252,5,45,0,0,251,253,3,66,33,0,252,251,1,0,0,0,252,253,1,0,0,0,253,254,
  	1,0,0,0,254,256,5,46,0,0,255,249,1,0,0,0,255,256,1,0,0,0,256,37,1,0,0,
  	0,257,258,5,5,0,0,258,259,3,52,26,0,259,261,5,45,0,0,260,262,3,66,33,
  	0,261,260,1,0,0,0,261,262,1,0,0,0,262,263,1,0,0,0,263,264,5,46,0,0,264,
  	39,1,0,0,0,265,266,5,1,0,0,266,269,3,84,42,0,267,268,5,38,0,0,268,270,
  	3,56,28,0,269,267,1,0,0,0,269,270,1,0,0,0,270,271,1,0,0,0,271,272,5,21,
  	0,0,272,273,3,52,26,0,273,280,1,0,0,0,274,275,5,1,0,0,275,276,3,84,42,
  	0,276,277,5,38,0,0,277,278,3,56,28,0,278,280,1,0,0,0,279,265,1,0,0,0,
  	279,274,1,0,0,0,280,41,1,0,0,0,281,282,3,84,42,0,282,283,5,21,0,0,283,
  	284,3,52,26,0,284,43,1,0,0,0,285,286,3,54,27,0,286,287,5,24,0,0,287,288,
  	3,84,42,0,288,289,5,21,0,0,289,290,3,52,26,0,290,45,1,0,0,0,291,292,5,
  	9,0,0,292,295,5,33,0,0,293,296,3,56,28,0,294,296,3,52,26,0,295,293,1,
  	0,0,0,295,294,1,0,0,0,296,297,1,0,0,0,297,298,5,34,0,0,298,47,1,0,0,0,
  	299,300,6,24,-1,0,300,314,3,84,42,0,301,302,5,25,0,0,302,314,3,48,24,
  	5,303,304,5,26,0,0,304,314,3,48,24,4,305,306,5,42,0,0,306,314,3,48,24,
  	3,307,308,5,39,0,0,308,314,3,48,24,2,309,310,5,33,0,0,310,311,3,52,26,
  	0,311,312,5,34,0,0,312,314,1,0,0,0,313,299,1,0,0,0,313,301,1,0,0,0,313,
  	303,1,0,0,0,313,305,1,0,0,0,313,307,1,0,0,0,313,309,1,0,0,0,314,345,1,
  	0,0,0,315,316,10,8,0,0,316,317,5,24,0,0,317,344,3,84,42,0,318,330,10,
  	7,0,0,319,320,5,23,0,0,320,325,3,56,28,0,321,322,5,43,0,0,322,324,3,56,
  	28,0,323,321,1,0,0,0,324,327,1,0,0,0,325,323,1,0,0,0,325,326,1,0,0,0,
  	326,328,1,0,0,0,327,325,1,0,0,0,328,329,5,22,0,0,329,331,1,0,0,0,330,
  	319,1,0,0,0,330,331,1,0,0,0,331,332,1,0,0,0,332,334,5,33,0,0,333,335,
  	3,60,30,0,334,333,1,0,0,0,334,335,1,0,0,0,335,336,1,0,0,0,336,344,5,34,
  	0,0,337,338,10,6,0,0,338,340,5,35,0,0,339,341,3,52,26,0,340,339,1,0,0,
  	0,340,341,1,0,0,0,341,342,1,0,0,0,342,344,5,36,0,0,343,315,1,0,0,0,343,
  	318,1,0,0,0,343,337,1,0,0,0,344,347,1,0,0,0,345,343,1,0,0,0,345,346,1,
  	0,0,0,346,49,1,0,0,0,347,345,1,0,0,0,348,352,3,48,24,0,349,352,3,80,40,
  	0,350,352,3,82,41,0,351,348,1,0,0,0,351,349,1,0,0,0,351,350,1,0,0,0,352,
  	51,1,0,0,0,353,354,6,26,-1,0,354,364,3,50,25,0,355,364,3,16,8,0,356,364,
  	3,46,23,0,357,358,3,50,25,0,358,359,5,8,0,0,359,360,3,56,28,0,360,364,
  	1,0,0,0,361,362,5,18,0,0,362,364,3,50,25,0,363,353,1,0,0,0,363,355,1,
  	0,0,0,363,356,1,0,0,0,363,357,1,0,0,0,363,361,1,0,0,0,364,385,1,0,0,0,
  	365,366,10,5,0,0,366,367,7,0,0,0,367,384,3,52,26,6,368,369,10,4,0,0,369,
  	370,7,1,0,0,370,384,3,52,26,5,371,372,10,3,0,0,372,373,3,74,37,0,373,
  	374,3,52,26,4,374,384,1,0,0,0,375,376,10,2,0,0,376,377,3,76,38,0,377,
  	378,3,52,26,3,378,384,1,0,0,0,379,380,10,1,0,0,380,381,3,78,39,0,381,
  	382,3,52,26,2,382,384,1,0,0,0,383,365,1,0,0,0,383,368,1,0,0,0,383,371,
  	1,0,0,0,383,375,1,0,0,0,383,379,1,0,0,0,384,387,1,0,0,0,385,383,1,0,0,
  	0,385,386,1,0,0,0,386,53,1,0,0,0,387,385,1,0,0,0,388,389,6,27,-1,0,389,
  	390,5,51,0,0,390,396,1,0,0,0,391,392,10,1,0,0,392,393,5,24,0,0,393,395,
  	5,51,0,0,394,391,1,0,0,0,395,398,1,0,0,0,396,394,1,0,0,0,396,397,1,0,
  	0,0,397,55,1,0,0,0,398,396,1,0,0,0,399,400,6,28,-1,0,400,412,3,84,42,
  	0,401,402,5,23,0,0,402,407,3,56,28,0,403,404,5,43,0,0,404,406,3,56,28,
  	0,405,403,1,0,0,0,406,409,1,0,0,0,407,405,1,0,0,0,407,408,1,0,0,0,408,
  	410,1,0,0,0,409,407,1,0,0,0,410,411,5,22,0,0,411,413,1,0,0,0,412,401,
  	1,0,0,0,412,413,1,0,0,0,413,423,1,0,0,0,414,416,5,33,0,0,415,417,3,58,
  	29,0,416,415,1,0,0,0,416,417,1,0,0,0,417,418,1,0,0,0,418,419,5,34,0,0,
  	419,420,5,26,0,0,420,421,5,22,0,0,421,423,3,56,28,2,422,399,1,0,0,0,422,
  	414,1,0,0,0,423,435,1,0,0,0,424,425,10,3,0,0,425,426,5,26,0,0,426,427,
  	5,22,0,0,427,434,3,56,28,4,428,429,10,1,0,0,429,430,5,35,0,0,430,431,
  	3,80,40,0,431,432,5,36,0,0,432,434,1,0,0,0,433,424,1,0,0,0,433,428,1,
  	0,0,0,434,437,1,0,0,0,435,433,1,0,0,0,435,436,1,0,0,0,436,57,1,0,0,0,
  	437,435,1,0,0,0,438,443,3,56,28,0,439,440,5,43,0,0,440,442,3,56,28,0,
  	441,439,1,0,0,0,442,445,1,0,0,0,443,441,1,0,0,0,443,444,1,0,0,0,444,59,
  	1,0,0,0,445,443,1,0,0,0,446,451,3,52,26,0,447,448,5,43,0,0,448,450,3,
  	52,26,0,449,447,1,0,0,0,450,453,1,0,0,0,451,449,1,0,0,0,451,452,1,0,0,
  	0,452,455,1,0,0,0,453,451,1,0,0,0,454,456,5,43,0,0,455,454,1,0,0,0,455,
  	456,1,0,0,0,456,61,1,0,0,0,457,462,3,64,32,0,458,459,5,43,0,0,459,461,
  	3,64,32,0,460,458,1,0,0,0,461,464,1,0,0,0,462,460,1,0,0,0,462,463,1,0,
  	0,0,463,466,1,0,0,0,464,462,1,0,0,0,465,467,5,43,0,0,466,465,1,0,0,0,
  	466,467,1,0,0,0,467,63,1,0,0,0,468,469,3,84,42,0,469,470,5,38,0,0,470,
  	471,3,56,28,0,471,65,1,0,0,0,472,474,3,68,34,0,473,472,1,0,0,0,474,475,
  	1,0,0,0,475,473,1,0,0,0,475,476,1,0,0,0,476,67,1,0,0,0,477,482,3,70,35,
  	0,478,479,3,72,36,0,479,480,5,44,0,0,480,482,1,0,0,0,481,477,1,0,0,0,
  	481,478,1,0,0,0,482,69,1,0,0,0,483,499,3,36,18,0,484,499,3,38,19,0,485,
  	486,3,40,20,0,486,487,5,44,0,0,487,499,1,0,0,0,488,489,3,42,21,0,489,
  	490,5,44,0,0,490,499,1,0,0,0,491,492,3,44,22,0,492,493,5,44,0,0,493,499,
  	1,0,0,0,494,495,3,52,26,0,495,496,5,44,0,0,496,499,1,0,0,0,497,499,5,
  	44,0,0,498,483,1,0,0,0,498,484,1,0,0,0,498,485,1,0,0,0,498,488,1,0,0,
  	0,498,491,1,0,0,0,498,494,1,0,0,0,498,497,1,0,0,0,499,71,1,0,0,0,500,
  	502,5,6,0,0,501,503,3,52,26,0,502,501,1,0,0,0,502,503,1,0,0,0,503,73,
  	1,0,0,0,504,512,5,30,0,0,505,512,5,32,0,0,506,512,5,31,0,0,507,508,5,
  	23,0,0,508,512,5,23,0,0,509,510,5,22,0,0,510,512,5,22,0,0,511,504,1,0,
  	0,0,511,505,1,0,0,0,511,506,1,0,0,0,511,507,1,0,0,0,511,509,1,0,0,0,512,
  	75,1,0,0,0,513,514,5,21,0,0,514,524,5,21,0,0,515,516,5,42,0,0,516,524,
  	5,21,0,0,517,524,5,22,0,0,518,524,5,23,0,0,519,520,5,22,0,0,520,524,5,
  	21,0,0,521,522,5,23,0,0,522,524,5,21,0,0,523,513,1,0,0,0,523,515,1,0,
  	0,0,523,517,1,0,0,0,523,518,1,0,0,0,523,519,1,0,0,0,523,521,1,0,0,0,524,
  	77,1,0,0,0,525,526,5,32,0,0,526,532,5,32,0,0,527,528,5,31,0,0,528,532,
  	5,31,0,0,529,532,5,19,0,0,530,532,5,20,0,0,531,525,1,0,0,0,531,527,1,
  	0,0,0,531,529,1,0,0,0,531,530,1,0,0,0,532,79,1,0,0,0,533,534,7,2,0,0,
  	534,81,1,0,0,0,535,537,5,51,0,0,536,535,1,0,0,0,536,537,1,0,0,0,537,538,
  	1,0,0,0,538,539,5,52,0,0,539,83,1,0,0,0,540,541,5,51,0,0,541,85,1,0,0,
  	0,60,92,100,108,112,121,131,135,144,153,157,162,172,176,182,188,193,198,
  	205,210,219,230,240,246,252,255,261,269,279,295,313,325,330,334,340,343,
  	345,351,363,383,385,396,407,412,416,422,433,435,443,451,455,462,466,475,
  	481,498,502,511,523,531,536
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
    setState(92);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17592186274948) != 0)) {
      setState(89);
      program_element();
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

TsilParser::SectionContext* TsilParser::Program_elementContext::section() {
  return getRuleContext<TsilParser::SectionContext>(0);
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
    setState(100);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(95);
      structure();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(96);
      diia_declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(97);
      diia();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(98);
      section();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(99);
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
    setState(102);
    match(TsilParser::KW_STRUCT);
    setState(103);
    antlrcpp::downCast<StructureContext *>(_localctx)->s_name = identifier();
    setState(108);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(104);
      match(TsilParser::LESSER);
      setState(105);
      antlrcpp::downCast<StructureContext *>(_localctx)->s_generics = structure_generics();
      setState(106);
      match(TsilParser::GREATER);
    }
    setState(110);
    match(TsilParser::QUOTE_OPEN);
    setState(112);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(111);
      antlrcpp::downCast<StructureContext *>(_localctx)->s_params = structure_params();
    }
    setState(114);
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
    setState(116);
    structure_generic();
    setState(121);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TsilParser::COMA) {
      setState(117);
      match(TsilParser::COMA);
      setState(118);
      structure_generic();
      setState(123);
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
    setState(124);
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
    setState(126);
    structure_param();
    setState(131);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(127);
        match(TsilParser::COMA);
        setState(128);
        structure_param(); 
      }
      setState(133);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
    setState(135);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COMA) {
      setState(134);
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

TsilParser::Full_typeContext* TsilParser::Structure_paramContext::full_type() {
  return getRuleContext<TsilParser::Full_typeContext>(0);
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
    setState(137);
    antlrcpp::downCast<Structure_paramContext *>(_localctx)->sp_name = identifier();
    setState(138);
    match(TsilParser::COLON);
    setState(139);
    antlrcpp::downCast<Structure_paramContext *>(_localctx)->sp_type = full_type(0);
   
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

TsilParser::Full_typeContext* TsilParser::ConstructorContext::full_type() {
  return getRuleContext<TsilParser::Full_typeContext>(0);
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
    setState(141);
    antlrcpp::downCast<ConstructorContext *>(_localctx)->c_type = full_type(0);
    setState(142);
    match(TsilParser::QUOTE_OPEN);
    setState(144);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8871418259571200) != 0)) {
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
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(149);
        match(TsilParser::COMA);
        setState(150);
        constructor_arg(); 
      }
      setState(155);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
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

TsilParser::ExprContext* TsilParser::Constructor_argContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

tree::TerminalNode* TsilParser::Constructor_argContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}

TsilParser::IdentifierContext* TsilParser::Constructor_argContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
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
    setState(162);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(159);
      antlrcpp::downCast<Constructor_argContext *>(_localctx)->ca_name = identifier();
      setState(160);
      match(TsilParser::EQUAL);
      break;
    }

    default:
      break;
    }
    setState(164);
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

tree::TerminalNode* TsilParser::Diia_headContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

std::vector<tree::TerminalNode *> TsilParser::Diia_headContext::GREATER() {
  return getTokens(TsilParser::GREATER);
}

tree::TerminalNode* TsilParser::Diia_headContext::GREATER(size_t i) {
  return getToken(TsilParser::GREATER, i);
}

std::vector<tree::TerminalNode *> TsilParser::Diia_headContext::DOT() {
  return getTokens(TsilParser::DOT);
}

tree::TerminalNode* TsilParser::Diia_headContext::DOT(size_t i) {
  return getToken(TsilParser::DOT, i);
}

tree::TerminalNode* TsilParser::Diia_headContext::MINUS() {
  return getToken(TsilParser::MINUS, 0);
}

TsilParser::Diia_genericsContext* TsilParser::Diia_headContext::diia_generics() {
  return getRuleContext<TsilParser::Diia_genericsContext>(0);
}

TsilParser::ParamsContext* TsilParser::Diia_headContext::params() {
  return getRuleContext<TsilParser::ParamsContext>(0);
}

tree::TerminalNode* TsilParser::Diia_headContext::COMA() {
  return getToken(TsilParser::COMA, 0);
}

TsilParser::Full_typeContext* TsilParser::Diia_headContext::full_type() {
  return getRuleContext<TsilParser::Full_typeContext>(0);
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
    setState(166);
    match(TsilParser::KW_DIIA);
    setState(167);
    antlrcpp::downCast<Diia_headContext *>(_localctx)->d_name = identifier();
    setState(172);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(168);
      match(TsilParser::LESSER);
      setState(169);
      antlrcpp::downCast<Diia_headContext *>(_localctx)->d_generics = diia_generics();
      setState(170);
      match(TsilParser::GREATER);
    }
    setState(174);
    match(TsilParser::PAREN_OPEN);
    setState(176);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(175);
      antlrcpp::downCast<Diia_headContext *>(_localctx)->d_params = params();
    }
    setState(182);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COMA) {
      setState(178);
      antlrcpp::downCast<Diia_headContext *>(_localctx)->d_variadic = match(TsilParser::COMA);
      setState(179);
      match(TsilParser::DOT);
      setState(180);
      match(TsilParser::DOT);
      setState(181);
      match(TsilParser::DOT);
    }
    setState(184);
    match(TsilParser::PAREN_CLOSE);
    setState(188);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::MINUS) {
      setState(185);
      match(TsilParser::MINUS);
      setState(186);
      match(TsilParser::GREATER);
      setState(187);
      antlrcpp::downCast<Diia_headContext *>(_localctx)->d_type = full_type(0);
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

tree::TerminalNode* TsilParser::DiiaContext::KW_PUBLIC() {
  return getToken(TsilParser::KW_PUBLIC, 0);
}

tree::TerminalNode* TsilParser::DiiaContext::KW_LOCAL() {
  return getToken(TsilParser::KW_LOCAL, 0);
}

tree::TerminalNode* TsilParser::DiiaContext::KW_PRIVATE() {
  return getToken(TsilParser::KW_PRIVATE, 0);
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
    setState(193);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(190);
        antlrcpp::downCast<DiiaContext *>(_localctx)->d_extern = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(191);
        antlrcpp::downCast<DiiaContext *>(_localctx)->d_local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(192);
        antlrcpp::downCast<DiiaContext *>(_localctx)->d_internal = match(TsilParser::KW_PRIVATE);
        break;
      }

      case TsilParser::KW_DIIA: {
        break;
      }

    default:
      break;
    }
    setState(195);
    antlrcpp::downCast<DiiaContext *>(_localctx)->d_head = diia_head();
    setState(196);
    match(TsilParser::QUOTE_OPEN);
    setState(198);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8889010445615722) != 0)) {
      setState(197);
      antlrcpp::downCast<DiiaContext *>(_localctx)->d_body = body();
    }
    setState(200);
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

tree::TerminalNode* TsilParser::Diia_declarationContext::KW_PUBLIC() {
  return getToken(TsilParser::KW_PUBLIC, 0);
}

tree::TerminalNode* TsilParser::Diia_declarationContext::KW_LOCAL() {
  return getToken(TsilParser::KW_LOCAL, 0);
}

tree::TerminalNode* TsilParser::Diia_declarationContext::KW_PRIVATE() {
  return getToken(TsilParser::KW_PRIVATE, 0);
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
    setState(205);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(202);
        antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_extern = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(203);
        antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(204);
        antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_internal = match(TsilParser::KW_PRIVATE);
        break;
      }

      case TsilParser::KW_DIIA: {
        break;
      }

    default:
      break;
    }
    setState(207);
    antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_head = diia_head();
    setState(210);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::KW_AS) {
      setState(208);
      match(TsilParser::KW_AS);
      setState(209);
      antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_as = identifier();
    }
    setState(212);
    match(TsilParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Diia_genericsContext ------------------------------------------------------------------

TsilParser::Diia_genericsContext::Diia_genericsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TsilParser::Diia_genericContext *> TsilParser::Diia_genericsContext::diia_generic() {
  return getRuleContexts<TsilParser::Diia_genericContext>();
}

TsilParser::Diia_genericContext* TsilParser::Diia_genericsContext::diia_generic(size_t i) {
  return getRuleContext<TsilParser::Diia_genericContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Diia_genericsContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Diia_genericsContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::Diia_genericsContext::getRuleIndex() const {
  return TsilParser::RuleDiia_generics;
}

void TsilParser::Diia_genericsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiia_generics(this);
}

void TsilParser::Diia_genericsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiia_generics(this);
}


std::any TsilParser::Diia_genericsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitDiia_generics(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Diia_genericsContext* TsilParser::diia_generics() {
  Diia_genericsContext *_localctx = _tracker.createInstance<Diia_genericsContext>(_ctx, getState());
  enterRule(_localctx, 28, TsilParser::RuleDiia_generics);
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
    setState(214);
    diia_generic();
    setState(219);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TsilParser::COMA) {
      setState(215);
      match(TsilParser::COMA);
      setState(216);
      diia_generic();
      setState(221);
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

//----------------- Diia_genericContext ------------------------------------------------------------------

TsilParser::Diia_genericContext::Diia_genericContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TsilParser::IdentifierContext* TsilParser::Diia_genericContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
}


size_t TsilParser::Diia_genericContext::getRuleIndex() const {
  return TsilParser::RuleDiia_generic;
}

void TsilParser::Diia_genericContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiia_generic(this);
}

void TsilParser::Diia_genericContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiia_generic(this);
}


std::any TsilParser::Diia_genericContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitDiia_generic(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Diia_genericContext* TsilParser::diia_generic() {
  Diia_genericContext *_localctx = _tracker.createInstance<Diia_genericContext>(_ctx, getState());
  enterRule(_localctx, 30, TsilParser::RuleDiia_generic);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    antlrcpp::downCast<Diia_genericContext *>(_localctx)->dg_name = identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SectionContext ------------------------------------------------------------------

TsilParser::SectionContext::SectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::SectionContext::KW_SECTION() {
  return getToken(TsilParser::KW_SECTION, 0);
}

tree::TerminalNode* TsilParser::SectionContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::SectionContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}

TsilParser::IdentifierContext* TsilParser::SectionContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
}

std::vector<TsilParser::Section_elementContext *> TsilParser::SectionContext::section_element() {
  return getRuleContexts<TsilParser::Section_elementContext>();
}

TsilParser::Section_elementContext* TsilParser::SectionContext::section_element(size_t i) {
  return getRuleContext<TsilParser::Section_elementContext>(i);
}


size_t TsilParser::SectionContext::getRuleIndex() const {
  return TsilParser::RuleSection;
}

void TsilParser::SectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSection(this);
}

void TsilParser::SectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSection(this);
}


std::any TsilParser::SectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSection(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::SectionContext* TsilParser::section() {
  SectionContext *_localctx = _tracker.createInstance<SectionContext>(_ctx, getState());
  enterRule(_localctx, 32, TsilParser::RuleSection);
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
    setState(224);
    match(TsilParser::KW_SECTION);
    setState(225);
    antlrcpp::downCast<SectionContext *>(_localctx)->s_name = identifier();
    setState(226);
    match(TsilParser::QUOTE_OPEN);
    setState(230);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17592186274948) != 0)) {
      setState(227);
      section_element();
      setState(232);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(233);
    match(TsilParser::QUOTE_CLOSE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Section_elementContext ------------------------------------------------------------------

TsilParser::Section_elementContext::Section_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TsilParser::StructureContext* TsilParser::Section_elementContext::structure() {
  return getRuleContext<TsilParser::StructureContext>(0);
}

TsilParser::Diia_declarationContext* TsilParser::Section_elementContext::diia_declaration() {
  return getRuleContext<TsilParser::Diia_declarationContext>(0);
}

TsilParser::DiiaContext* TsilParser::Section_elementContext::diia() {
  return getRuleContext<TsilParser::DiiaContext>(0);
}

TsilParser::SectionContext* TsilParser::Section_elementContext::section() {
  return getRuleContext<TsilParser::SectionContext>(0);
}

tree::TerminalNode* TsilParser::Section_elementContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}


size_t TsilParser::Section_elementContext::getRuleIndex() const {
  return TsilParser::RuleSection_element;
}

void TsilParser::Section_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSection_element(this);
}

void TsilParser::Section_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSection_element(this);
}


std::any TsilParser::Section_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSection_element(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Section_elementContext* TsilParser::section_element() {
  Section_elementContext *_localctx = _tracker.createInstance<Section_elementContext>(_ctx, getState());
  enterRule(_localctx, 34, TsilParser::RuleSection_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(240);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(235);
      structure();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(236);
      diia_declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(237);
      diia();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(238);
      section();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(239);
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

//----------------- IfContext ------------------------------------------------------------------

TsilParser::IfContext::IfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::IfContext::KW_IF() {
  return getToken(TsilParser::KW_IF, 0);
}

std::vector<tree::TerminalNode *> TsilParser::IfContext::QUOTE_OPEN() {
  return getTokens(TsilParser::QUOTE_OPEN);
}

tree::TerminalNode* TsilParser::IfContext::QUOTE_OPEN(size_t i) {
  return getToken(TsilParser::QUOTE_OPEN, i);
}

std::vector<tree::TerminalNode *> TsilParser::IfContext::QUOTE_CLOSE() {
  return getTokens(TsilParser::QUOTE_CLOSE);
}

tree::TerminalNode* TsilParser::IfContext::QUOTE_CLOSE(size_t i) {
  return getToken(TsilParser::QUOTE_CLOSE, i);
}

TsilParser::ExprContext* TsilParser::IfContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

tree::TerminalNode* TsilParser::IfContext::KW_ELSE() {
  return getToken(TsilParser::KW_ELSE, 0);
}

std::vector<TsilParser::BodyContext *> TsilParser::IfContext::body() {
  return getRuleContexts<TsilParser::BodyContext>();
}

TsilParser::BodyContext* TsilParser::IfContext::body(size_t i) {
  return getRuleContext<TsilParser::BodyContext>(i);
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
  enterRule(_localctx, 36, TsilParser::RuleIf);
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
    setState(242);
    match(TsilParser::KW_IF);
    setState(243);
    antlrcpp::downCast<IfContext *>(_localctx)->i_value = expr(0);
    setState(244);
    match(TsilParser::QUOTE_OPEN);
    setState(246);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8889010445615722) != 0)) {
      setState(245);
      antlrcpp::downCast<IfContext *>(_localctx)->i_body = body();
    }
    setState(248);
    match(TsilParser::QUOTE_CLOSE);
    setState(255);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::KW_ELSE) {
      setState(249);
      match(TsilParser::KW_ELSE);
      setState(250);
      match(TsilParser::QUOTE_OPEN);
      setState(252);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8889010445615722) != 0)) {
        setState(251);
        antlrcpp::downCast<IfContext *>(_localctx)->i_else_body = body();
      }
      setState(254);
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
  enterRule(_localctx, 38, TsilParser::RuleWhile);
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
    setState(257);
    match(TsilParser::KW_WHILE);
    setState(258);
    antlrcpp::downCast<WhileContext *>(_localctx)->w_value = expr(0);
    setState(259);
    match(TsilParser::QUOTE_OPEN);
    setState(261);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8889010445615722) != 0)) {
      setState(260);
      antlrcpp::downCast<WhileContext *>(_localctx)->w_body = body();
    }
    setState(263);
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

TsilParser::Full_typeContext* TsilParser::DefineContext::full_type() {
  return getRuleContext<TsilParser::Full_typeContext>(0);
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
  enterRule(_localctx, 40, TsilParser::RuleDefine);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(279);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(265);
      match(TsilParser::KW_TSIL);
      setState(266);
      antlrcpp::downCast<DefineContext *>(_localctx)->d_id = identifier();
      setState(269);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TsilParser::COLON) {
        setState(267);
        match(TsilParser::COLON);
        setState(268);
        antlrcpp::downCast<DefineContext *>(_localctx)->d_type = full_type(0);
      }
      setState(271);
      match(TsilParser::EQUAL);
      setState(272);
      antlrcpp::downCast<DefineContext *>(_localctx)->d_value = expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(274);
      match(TsilParser::KW_TSIL);
      setState(275);
      antlrcpp::downCast<DefineContext *>(_localctx)->d_id = identifier();
      setState(276);
      match(TsilParser::COLON);
      setState(277);
      antlrcpp::downCast<DefineContext *>(_localctx)->d_type = full_type(0);
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
  enterRule(_localctx, 42, TsilParser::RuleAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    antlrcpp::downCast<AssignContext *>(_localctx)->a_id = identifier();
    setState(282);
    match(TsilParser::EQUAL);
    setState(283);
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
  enterRule(_localctx, 44, TsilParser::RuleSet);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
    antlrcpp::downCast<SetContext *>(_localctx)->s_left = identifiers_chain(0);
    setState(286);
    match(TsilParser::DOT);
    setState(287);
    antlrcpp::downCast<SetContext *>(_localctx)->s_id = identifier();
    setState(288);
    match(TsilParser::EQUAL);
    setState(289);
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

tree::TerminalNode* TsilParser::SizeofContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

tree::TerminalNode* TsilParser::SizeofContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

TsilParser::Full_typeContext* TsilParser::SizeofContext::full_type() {
  return getRuleContext<TsilParser::Full_typeContext>(0);
}

TsilParser::ExprContext* TsilParser::SizeofContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
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
  enterRule(_localctx, 46, TsilParser::RuleSizeof);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
    match(TsilParser::KW_SIZEOF);
    setState(292);
    match(TsilParser::PAREN_OPEN);
    setState(295);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      setState(293);
      antlrcpp::downCast<SizeofContext *>(_localctx)->s_type = full_type(0);
      break;
    }

    case 2: {
      setState(294);
      antlrcpp::downCast<SizeofContext *>(_localctx)->s_value = expr(0);
      break;
    }

    default:
      break;
    }
    setState(297);
    match(TsilParser::PAREN_CLOSE);
   
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

tree::TerminalNode* TsilParser::CallContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::CallContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

std::vector<TsilParser::Full_typeContext *> TsilParser::CallContext::full_type() {
  return getRuleContexts<TsilParser::Full_typeContext>();
}

TsilParser::Full_typeContext* TsilParser::CallContext::full_type(size_t i) {
  return getRuleContext<TsilParser::Full_typeContext>(i);
}

TsilParser::ArgsContext* TsilParser::CallContext::args() {
  return getRuleContext<TsilParser::ArgsContext>(0);
}

std::vector<tree::TerminalNode *> TsilParser::CallContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::CallContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
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
//----------------- AccessContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::AccessContext::BRACKET_OPEN() {
  return getToken(TsilParser::BRACKET_OPEN, 0);
}

tree::TerminalNode* TsilParser::AccessContext::BRACKET_CLOSE() {
  return getToken(TsilParser::BRACKET_CLOSE, 0);
}

TsilParser::AtomContext* TsilParser::AccessContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

TsilParser::ExprContext* TsilParser::AccessContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

TsilParser::AccessContext::AccessContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::AccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAccess(this);
}
void TsilParser::AccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAccess(this);
}

std::any TsilParser::AccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAccess(this);
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
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, TsilParser::RuleAtom, precedence);

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
    setState(313);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::ID: {
        _localctx = _tracker.createInstance<Atom_identifierContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(300);
        identifier();
        break;
      }

      case TsilParser::PLUS: {
        _localctx = _tracker.createInstance<PositiveContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(301);
        match(TsilParser::PLUS);
        setState(302);
        antlrcpp::downCast<PositiveContext *>(_localctx)->p_value = atom(5);
        break;
      }

      case TsilParser::MINUS: {
        _localctx = _tracker.createInstance<NegativeContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(303);
        match(TsilParser::MINUS);
        setState(304);
        antlrcpp::downCast<NegativeContext *>(_localctx)->n_value = atom(4);
        break;
      }

      case TsilParser::EXCLAMATION: {
        _localctx = _tracker.createInstance<NotContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(305);
        match(TsilParser::EXCLAMATION);
        setState(306);
        antlrcpp::downCast<NotContext *>(_localctx)->n_value = atom(3);
        break;
      }

      case TsilParser::TILDA: {
        _localctx = _tracker.createInstance<Bitwise_notContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(307);
        match(TsilParser::TILDA);
        setState(308);
        antlrcpp::downCast<Bitwise_notContext *>(_localctx)->bn_value = atom(2);
        break;
      }

      case TsilParser::PAREN_OPEN: {
        _localctx = _tracker.createInstance<NestedContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(309);
        match(TsilParser::PAREN_OPEN);
        setState(310);
        antlrcpp::downCast<NestedContext *>(_localctx)->n_value = expr(0);
        setState(311);
        match(TsilParser::PAREN_CLOSE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(345);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(343);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<GetContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->g_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(315);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(316);
          match(TsilParser::DOT);
          setState(317);
          antlrcpp::downCast<GetContext *>(_localctx)->g_id = identifier();
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<CallContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->c_value = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(318);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(330);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == TsilParser::LESSER) {
            setState(319);
            match(TsilParser::LESSER);
            setState(320);
            antlrcpp::downCast<CallContext *>(_localctx)->c_first_generic_type = full_type(0);
            setState(325);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == TsilParser::COMA) {
              setState(321);
              match(TsilParser::COMA);
              setState(322);
              full_type(0);
              setState(327);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            setState(328);
            match(TsilParser::GREATER);
          }
          setState(332);
          match(TsilParser::PAREN_OPEN);
          setState(334);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 8871418259571200) != 0)) {
            setState(333);
            antlrcpp::downCast<CallContext *>(_localctx)->c_args = args();
          }
          setState(336);
          match(TsilParser::PAREN_CLOSE);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AccessContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->a_value = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(337);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(338);
          match(TsilParser::BRACKET_OPEN);
          setState(340);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 8871418259571200) != 0)) {
            setState(339);
            antlrcpp::downCast<AccessContext *>(_localctx)->a_index = expr(0);
          }
          setState(342);
          match(TsilParser::BRACKET_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(347);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
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
  enterRule(_localctx, 50, TsilParser::RuleMolecule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(351);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TsilParser::Value_atomContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(348);
      atom(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TsilParser::Atom_numberContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(349);
      number();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<TsilParser::Atom_stringContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(350);
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
//----------------- Not_textContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Not_textContext::KW_NOT() {
  return getToken(TsilParser::KW_NOT, 0);
}

TsilParser::MoleculeContext* TsilParser::Not_textContext::molecule() {
  return getRuleContext<TsilParser::MoleculeContext>(0);
}

TsilParser::Not_textContext::Not_textContext(ExprContext *ctx) { copyFrom(ctx); }

void TsilParser::Not_textContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNot_text(this);
}
void TsilParser::Not_textContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNot_text(this);
}

std::any TsilParser::Not_textContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitNot_text(this);
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

TsilParser::Full_typeContext* TsilParser::AsContext::full_type() {
  return getRuleContext<TsilParser::Full_typeContext>(0);
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
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, TsilParser::RuleExpr, precedence);

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
    setState(363);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Expr_moleculeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(354);
      molecule();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Atom_constructorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(355);
      constructor();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Atom_sizeofContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(356);
      sizeof_();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<AsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(357);
      antlrcpp::downCast<AsContext *>(_localctx)->a_left = molecule();
      setState(358);
      match(TsilParser::KW_AS);
      setState(359);
      antlrcpp::downCast<AsContext *>(_localctx)->a_type = full_type(0);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Not_textContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(361);
      match(TsilParser::KW_NOT);
      setState(362);
      antlrcpp::downCast<Not_textContext *>(_localctx)->nt_value = molecule();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(385);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(383);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Arithmetic_mulContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->a_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(365);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(366);
          antlrcpp::downCast<Arithmetic_mulContext *>(_localctx)->a_operation = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 939524096) != 0))) {
            antlrcpp::downCast<Arithmetic_mulContext *>(_localctx)->a_operation = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(367);
          antlrcpp::downCast<Arithmetic_mulContext *>(_localctx)->a_right = expr(6);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Arithmetic_addContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->a_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(368);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(369);
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
          setState(370);
          antlrcpp::downCast<Arithmetic_addContext *>(_localctx)->a_right = expr(5);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BitwiseContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->b_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(371);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(372);
          antlrcpp::downCast<BitwiseContext *>(_localctx)->b_operation = bitwise_op();
          setState(373);
          antlrcpp::downCast<BitwiseContext *>(_localctx)->b_right = expr(4);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ComparisonContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->c_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(375);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(376);
          antlrcpp::downCast<ComparisonContext *>(_localctx)->c_operation = comparison_op();
          setState(377);
          antlrcpp::downCast<ComparisonContext *>(_localctx)->c_right = expr(3);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<LogicalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->t_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(379);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(380);
          antlrcpp::downCast<LogicalContext *>(_localctx)->t_operation = logical_op();
          setState(381);
          antlrcpp::downCast<LogicalContext *>(_localctx)->t_right = expr(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(387);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
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
  size_t startState = 54;
  enterRecursionRule(_localctx, 54, TsilParser::RuleIdentifiers_chain, precedence);

    

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
    setState(389);
    antlrcpp::downCast<Identifiers_chainContext *>(_localctx)->ic_id = match(TsilParser::ID);
    _ctx->stop = _input->LT(-1);
    setState(396);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Identifiers_chainContext>(parentContext, parentState);
        _localctx->ic_left = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleIdentifiers_chain);
        setState(391);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(392);
        match(TsilParser::DOT);
        setState(393);
        antlrcpp::downCast<Identifiers_chainContext *>(_localctx)->ic_right = match(TsilParser::ID); 
      }
      setState(398);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Full_typeContext ------------------------------------------------------------------

TsilParser::Full_typeContext::Full_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TsilParser::Full_typeContext::getRuleIndex() const {
  return TsilParser::RuleFull_type;
}

void TsilParser::Full_typeContext::copyFrom(Full_typeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Simple_function_typeContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Simple_function_typeContext::MINUS() {
  return getToken(TsilParser::MINUS, 0);
}

tree::TerminalNode* TsilParser::Simple_function_typeContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

std::vector<TsilParser::Full_typeContext *> TsilParser::Simple_function_typeContext::full_type() {
  return getRuleContexts<TsilParser::Full_typeContext>();
}

TsilParser::Full_typeContext* TsilParser::Simple_function_typeContext::full_type(size_t i) {
  return getRuleContext<TsilParser::Full_typeContext>(i);
}

TsilParser::Simple_function_typeContext::Simple_function_typeContext(Full_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Simple_function_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_function_type(this);
}
void TsilParser::Simple_function_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_function_type(this);
}

std::any TsilParser::Simple_function_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSimple_function_type(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Complex_function_typeContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Complex_function_typeContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

tree::TerminalNode* TsilParser::Complex_function_typeContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

tree::TerminalNode* TsilParser::Complex_function_typeContext::MINUS() {
  return getToken(TsilParser::MINUS, 0);
}

tree::TerminalNode* TsilParser::Complex_function_typeContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

TsilParser::Full_typeContext* TsilParser::Complex_function_typeContext::full_type() {
  return getRuleContext<TsilParser::Full_typeContext>(0);
}

TsilParser::Simple_function_type_argsContext* TsilParser::Complex_function_typeContext::simple_function_type_args() {
  return getRuleContext<TsilParser::Simple_function_type_argsContext>(0);
}

TsilParser::Complex_function_typeContext::Complex_function_typeContext(Full_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Complex_function_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComplex_function_type(this);
}
void TsilParser::Complex_function_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComplex_function_type(this);
}

std::any TsilParser::Complex_function_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitComplex_function_type(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Array_typeContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Array_typeContext::BRACKET_OPEN() {
  return getToken(TsilParser::BRACKET_OPEN, 0);
}

tree::TerminalNode* TsilParser::Array_typeContext::BRACKET_CLOSE() {
  return getToken(TsilParser::BRACKET_CLOSE, 0);
}

TsilParser::Full_typeContext* TsilParser::Array_typeContext::full_type() {
  return getRuleContext<TsilParser::Full_typeContext>(0);
}

TsilParser::NumberContext* TsilParser::Array_typeContext::number() {
  return getRuleContext<TsilParser::NumberContext>(0);
}

TsilParser::Array_typeContext::Array_typeContext(Full_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Array_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_type(this);
}
void TsilParser::Array_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_type(this);
}

std::any TsilParser::Array_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitArray_type(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeContext ------------------------------------------------------------------

TsilParser::IdentifierContext* TsilParser::TypeContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
}

tree::TerminalNode* TsilParser::TypeContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::TypeContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

std::vector<TsilParser::Full_typeContext *> TsilParser::TypeContext::full_type() {
  return getRuleContexts<TsilParser::Full_typeContext>();
}

TsilParser::Full_typeContext* TsilParser::TypeContext::full_type(size_t i) {
  return getRuleContext<TsilParser::Full_typeContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::TypeContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::TypeContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}

TsilParser::TypeContext::TypeContext(Full_typeContext *ctx) { copyFrom(ctx); }

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

TsilParser::Full_typeContext* TsilParser::full_type() {
   return full_type(0);
}

TsilParser::Full_typeContext* TsilParser::full_type(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TsilParser::Full_typeContext *_localctx = _tracker.createInstance<Full_typeContext>(_ctx, parentState);
  TsilParser::Full_typeContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, TsilParser::RuleFull_type, precedence);

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
    setState(422);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::ID: {
        _localctx = _tracker.createInstance<TypeContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(400);
        identifier();
        setState(412);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
        case 1: {
          setState(401);
          match(TsilParser::LESSER);
          setState(402);
          antlrcpp::downCast<TypeContext *>(_localctx)->t_first_generic_type = full_type(0);
          setState(407);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == TsilParser::COMA) {
            setState(403);
            match(TsilParser::COMA);
            setState(404);
            full_type(0);
            setState(409);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(410);
          match(TsilParser::GREATER);
          break;
        }

        default:
          break;
        }
        break;
      }

      case TsilParser::PAREN_OPEN: {
        _localctx = _tracker.createInstance<Complex_function_typeContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(414);
        match(TsilParser::PAREN_OPEN);
        setState(416);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TsilParser::PAREN_OPEN

        || _la == TsilParser::ID) {
          setState(415);
          antlrcpp::downCast<Complex_function_typeContext *>(_localctx)->cft_args = simple_function_type_args();
        }
        setState(418);
        match(TsilParser::PAREN_CLOSE);
        setState(419);
        match(TsilParser::MINUS);
        setState(420);
        match(TsilParser::GREATER);
        setState(421);
        antlrcpp::downCast<Complex_function_typeContext *>(_localctx)->cft_ret = full_type(2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(435);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(433);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Simple_function_typeContext>(_tracker.createInstance<Full_typeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->sft_arg = previousContext;
          pushNewRecursionContext(newContext, startState, RuleFull_type);
          setState(424);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(425);
          match(TsilParser::MINUS);
          setState(426);
          match(TsilParser::GREATER);
          setState(427);
          antlrcpp::downCast<Simple_function_typeContext *>(_localctx)->sft_ret = full_type(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Array_typeContext>(_tracker.createInstance<Full_typeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->at_type = previousContext;
          pushNewRecursionContext(newContext, startState, RuleFull_type);
          setState(428);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(429);
          match(TsilParser::BRACKET_OPEN);
          setState(430);
          antlrcpp::downCast<Array_typeContext *>(_localctx)->at_size = number();
          setState(431);
          match(TsilParser::BRACKET_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(437);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Simple_function_type_argsContext ------------------------------------------------------------------

TsilParser::Simple_function_type_argsContext::Simple_function_type_argsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TsilParser::Full_typeContext *> TsilParser::Simple_function_type_argsContext::full_type() {
  return getRuleContexts<TsilParser::Full_typeContext>();
}

TsilParser::Full_typeContext* TsilParser::Simple_function_type_argsContext::full_type(size_t i) {
  return getRuleContext<TsilParser::Full_typeContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Simple_function_type_argsContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Simple_function_type_argsContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::Simple_function_type_argsContext::getRuleIndex() const {
  return TsilParser::RuleSimple_function_type_args;
}

void TsilParser::Simple_function_type_argsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_function_type_args(this);
}

void TsilParser::Simple_function_type_argsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_function_type_args(this);
}


std::any TsilParser::Simple_function_type_argsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSimple_function_type_args(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Simple_function_type_argsContext* TsilParser::simple_function_type_args() {
  Simple_function_type_argsContext *_localctx = _tracker.createInstance<Simple_function_type_argsContext>(_ctx, getState());
  enterRule(_localctx, 58, TsilParser::RuleSimple_function_type_args);
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
    setState(438);
    full_type(0);
    setState(443);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TsilParser::COMA) {
      setState(439);
      match(TsilParser::COMA);
      setState(440);
      full_type(0);
      setState(445);
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
  enterRule(_localctx, 60, TsilParser::RuleArgs);
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
    setState(446);
    expr(0);
    setState(451);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(447);
        match(TsilParser::COMA);
        setState(448);
        expr(0); 
      }
      setState(453);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    }
    setState(455);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COMA) {
      setState(454);
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
  enterRule(_localctx, 62, TsilParser::RuleParams);

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
    setState(457);
    param();
    setState(462);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(458);
        match(TsilParser::COMA);
        setState(459);
        param(); 
      }
      setState(464);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    }
    setState(466);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      setState(465);
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

TsilParser::Full_typeContext* TsilParser::ParamContext::full_type() {
  return getRuleContext<TsilParser::Full_typeContext>(0);
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
  enterRule(_localctx, 64, TsilParser::RuleParam);

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
    antlrcpp::downCast<ParamContext *>(_localctx)->p_name = identifier();
    setState(469);
    match(TsilParser::COLON);
    setState(470);
    antlrcpp::downCast<ParamContext *>(_localctx)->p_type = full_type(0);
   
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
    setState(473); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(472);
      body_element_or_return();
      setState(475); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8889010445615722) != 0));
   
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

tree::TerminalNode* TsilParser::Body_element_or_returnContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
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
  enterRule(_localctx, 68, TsilParser::RuleBody_element_or_return);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(481);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_TSIL:
      case TsilParser::KW_IF:
      case TsilParser::KW_WHILE:
      case TsilParser::KW_SIZEOF:
      case TsilParser::KW_NOT:
      case TsilParser::PLUS:
      case TsilParser::MINUS:
      case TsilParser::PAREN_OPEN:
      case TsilParser::TILDA:
      case TsilParser::EXCLAMATION:
      case TsilParser::SEMICOLON:
      case TsilParser::INTEGER:
      case TsilParser::FLOAT:
      case TsilParser::HEX:
      case TsilParser::BIN:
      case TsilParser::ID:
      case TsilParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(477);
        body_element();
        break;
      }

      case TsilParser::KW_RETURN: {
        enterOuterAlt(_localctx, 2);
        setState(478);
        return_body_element();
        setState(479);
        match(TsilParser::SEMICOLON);
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

tree::TerminalNode* TsilParser::Body_elementContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
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
  enterRule(_localctx, 70, TsilParser::RuleBody_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(498);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(483);
      if_();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(484);
      while_();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(485);
      define();
      setState(486);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(488);
      assign();
      setState(489);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(491);
      set();
      setState(492);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(494);
      expr(0);
      setState(495);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(497);
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
  enterRule(_localctx, 72, TsilParser::RuleReturn_body_element);
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
    setState(500);
    match(TsilParser::KW_RETURN);
    setState(502);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8871418259571200) != 0)) {
      setState(501);
      antlrcpp::downCast<Return_body_elementContext *>(_localctx)->rbl_value = expr(0);
    }
   
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
  enterRule(_localctx, 74, TsilParser::RuleBitwise_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(511);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::POWER: {
        enterOuterAlt(_localctx, 1);
        setState(504);
        match(TsilParser::POWER);
        break;
      }

      case TsilParser::OR: {
        enterOuterAlt(_localctx, 2);
        setState(505);
        match(TsilParser::OR);
        break;
      }

      case TsilParser::AND: {
        enterOuterAlt(_localctx, 3);
        setState(506);
        match(TsilParser::AND);
        break;
      }

      case TsilParser::LESSER: {
        enterOuterAlt(_localctx, 4);
        setState(507);
        match(TsilParser::LESSER);
        setState(508);
        match(TsilParser::LESSER);
        break;
      }

      case TsilParser::GREATER: {
        enterOuterAlt(_localctx, 5);
        setState(509);
        match(TsilParser::GREATER);
        setState(510);
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
  enterRule(_localctx, 76, TsilParser::RuleComparison_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(523);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(513);
      match(TsilParser::EQUAL);
      setState(514);
      match(TsilParser::EQUAL);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(515);
      match(TsilParser::EXCLAMATION);
      setState(516);
      match(TsilParser::EQUAL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(517);
      match(TsilParser::GREATER);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(518);
      match(TsilParser::LESSER);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(519);
      match(TsilParser::GREATER);
      setState(520);
      match(TsilParser::EQUAL);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(521);
      match(TsilParser::LESSER);
      setState(522);
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

tree::TerminalNode* TsilParser::Logical_opContext::KW_OR() {
  return getToken(TsilParser::KW_OR, 0);
}

tree::TerminalNode* TsilParser::Logical_opContext::KW_AND() {
  return getToken(TsilParser::KW_AND, 0);
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
  enterRule(_localctx, 78, TsilParser::RuleLogical_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(531);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::OR: {
        enterOuterAlt(_localctx, 1);
        setState(525);
        match(TsilParser::OR);
        setState(526);
        match(TsilParser::OR);
        break;
      }

      case TsilParser::AND: {
        enterOuterAlt(_localctx, 2);
        setState(527);
        match(TsilParser::AND);
        setState(528);
        match(TsilParser::AND);
        break;
      }

      case TsilParser::KW_OR: {
        enterOuterAlt(_localctx, 3);
        setState(529);
        match(TsilParser::KW_OR);
        break;
      }

      case TsilParser::KW_AND: {
        enterOuterAlt(_localctx, 4);
        setState(530);
        match(TsilParser::KW_AND);
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

tree::TerminalNode* TsilParser::NumberContext::INTEGER() {
  return getToken(TsilParser::INTEGER, 0);
}

tree::TerminalNode* TsilParser::NumberContext::FLOAT() {
  return getToken(TsilParser::FLOAT, 0);
}

tree::TerminalNode* TsilParser::NumberContext::HEX() {
  return getToken(TsilParser::HEX, 0);
}

tree::TerminalNode* TsilParser::NumberContext::BIN() {
  return getToken(TsilParser::BIN, 0);
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
  enterRule(_localctx, 80, TsilParser::RuleNumber);
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
    setState(533);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2111062325329920) != 0))) {
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
  enterRule(_localctx, 82, TsilParser::RuleString);
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
    setState(536);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(535);
      antlrcpp::downCast<StringContext *>(_localctx)->s_prefix = match(TsilParser::ID);
    }
    setState(538);
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
  enterRule(_localctx, 84, TsilParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(540);
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
    case 24: return atomSempred(antlrcpp::downCast<AtomContext *>(context), predicateIndex);
    case 26: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 27: return identifiers_chainSempred(antlrcpp::downCast<Identifiers_chainContext *>(context), predicateIndex);
    case 28: return full_typeSempred(antlrcpp::downCast<Full_typeContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TsilParser::atomSempred(AtomContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

bool TsilParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 2);
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool TsilParser::identifiers_chainSempred(Identifiers_chainContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool TsilParser::full_typeSempred(Full_typeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 3);
    case 10: return precpred(_ctx, 1);

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
