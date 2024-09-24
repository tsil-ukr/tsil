
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
      "file", "program", "atom", "operation", "op_lshift", "op_rshift", 
      "op_urshift", "op_lte", "op_gte", "op_eq", "op_neq", "op_land", "op_lor", 
      "expr", "structure_declare", "structure_define", "structure_element", 
      "diia_declare", "diia_define", "tsil_declare", "tsil_define", "synonym", 
      "section_declare", "section_define", "set", "position_set", "section_set", 
      "if", "while", "body", "body_element", "return", "type", "param"
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
      "'='", "'>'", "'<'", "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", 
      "'&'", "'|'", "'('", "')'", "'['", "']'", "'\\u003F'", "':'", "'~'", 
      "'''", "'\"'", "'!'", "','", "';'", "'{'", "'}'"
    },
    std::vector<std::string>{
      "", "KW_TSIL", "KW_DIIA", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_RETURN", 
      "KW_DEFER", "KW_STRUCT", "KW_VARIATION", "KW_AS", "KW_SECTION", "KW_IMPORT", 
      "KW_EXPORT", "KW_COMPOSITION", "KW_PROPERTY", "KW_PUBLIC", "KW_PRIVATE", 
      "KW_LOCAL", "KW_NOT", "KW_OR", "KW_AND", "KW_VAR", "KW_IMMUT", "KW_SYNONYM", 
      "EQUAL", "GREATER", "LESSER", "DOT", "PLUS", "MINUS", "MULTIPLY", 
      "DIVIDE", "MOD", "POWER", "AND", "OR", "PAREN_OPEN", "PAREN_CLOSE", 
      "BRACKET_OPEN", "BRACKET_CLOSE", "QUESTION", "COLON", "TILDA", "QUOTE", 
      "DOUBLE_QUOTE", "EXCLAMATION", "COMA", "SEMICOLON", "QUOTE_OPEN", 
      "QUOTE_CLOSE", "NUMBER", "INTEGER", "FLOAT", "HEX", "BIN", "ID", "STRING", 
      "COMMENT", "LINE_COMMENT", "WS", "NL"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,61,539,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,1,0,1,0,1,0,1,1,
  	5,1,73,8,1,10,1,12,1,76,9,1,1,2,1,2,1,2,1,2,1,2,1,2,3,2,84,8,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,95,8,2,10,2,12,2,98,9,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,115,8,2,10,2,12,2,
  	118,9,2,1,2,1,2,5,2,122,8,2,10,2,12,2,125,9,2,1,3,1,3,1,3,3,3,130,8,3,
  	1,3,1,3,3,3,134,8,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,5,3,208,8,3,10,3,12,3,211,9,3,1,4,1,4,1,4,
  	1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,10,
  	1,10,1,10,1,11,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,14,1,14,1,14,1,14,
  	1,14,1,14,5,14,249,8,14,10,14,12,14,252,9,14,1,14,3,14,255,8,14,1,14,
  	1,14,1,15,1,15,1,15,1,15,1,15,1,15,5,15,265,8,15,10,15,12,15,268,9,15,
  	1,15,3,15,271,8,15,1,15,1,15,5,15,275,8,15,10,15,12,15,278,9,15,1,15,
  	1,15,1,16,1,16,1,16,1,17,1,17,1,17,3,17,288,8,17,1,17,1,17,1,17,1,17,
  	1,17,1,17,5,17,296,8,17,10,17,12,17,299,9,17,1,17,3,17,302,8,17,1,17,
  	1,17,1,17,1,17,5,17,308,8,17,10,17,12,17,311,9,17,3,17,313,8,17,1,17,
  	1,17,1,17,3,17,318,8,17,1,17,1,17,1,18,1,18,1,18,3,18,325,8,18,1,18,1,
  	18,1,18,1,18,1,18,1,18,5,18,333,8,18,10,18,12,18,336,9,18,1,18,3,18,339,
  	8,18,1,18,1,18,1,18,1,18,5,18,345,8,18,10,18,12,18,348,9,18,3,18,350,
  	8,18,1,18,1,18,1,18,3,18,355,8,18,1,18,1,18,1,19,1,19,1,19,3,19,362,8,
  	19,1,19,1,19,1,19,3,19,367,8,19,1,19,1,19,1,20,1,20,1,20,3,20,374,8,20,
  	1,20,1,20,1,20,3,20,379,8,20,1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,21,
  	1,21,1,21,1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,
  	1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,26,1,26,1,26,1,26,
  	1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,27,3,27,427,8,27,3,27,
  	429,8,27,1,28,1,28,1,28,1,28,1,29,1,29,5,29,437,8,29,10,29,12,29,440,
  	9,29,1,29,1,29,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,
  	1,30,1,30,1,30,1,30,1,30,1,30,1,30,3,30,462,8,30,1,31,1,31,1,31,1,31,
  	1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,4,32,478,8,32,11,32,
  	12,32,479,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,5,32,491,8,32,
  	10,32,12,32,494,9,32,1,32,1,32,1,32,1,32,1,32,3,32,501,8,32,1,32,1,32,
  	1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,5,32,516,8,32,
  	10,32,12,32,519,9,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,5,32,
  	530,8,32,10,32,12,32,533,9,32,1,33,1,33,1,33,1,33,1,33,0,3,4,6,64,34,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,
  	50,52,54,56,58,60,62,64,66,0,0,594,0,68,1,0,0,0,2,74,1,0,0,0,4,83,1,0,
  	0,0,6,133,1,0,0,0,8,212,1,0,0,0,10,215,1,0,0,0,12,218,1,0,0,0,14,222,
  	1,0,0,0,16,225,1,0,0,0,18,228,1,0,0,0,20,231,1,0,0,0,22,234,1,0,0,0,24,
  	237,1,0,0,0,26,240,1,0,0,0,28,242,1,0,0,0,30,258,1,0,0,0,32,281,1,0,0,
  	0,34,287,1,0,0,0,36,324,1,0,0,0,38,361,1,0,0,0,40,373,1,0,0,0,42,384,
  	1,0,0,0,44,390,1,0,0,0,46,393,1,0,0,0,48,397,1,0,0,0,50,404,1,0,0,0,52,
  	412,1,0,0,0,54,420,1,0,0,0,56,430,1,0,0,0,58,434,1,0,0,0,60,461,1,0,0,
  	0,62,463,1,0,0,0,64,500,1,0,0,0,66,534,1,0,0,0,68,69,3,2,1,0,69,70,5,
  	0,0,1,70,1,1,0,0,0,71,73,3,60,30,0,72,71,1,0,0,0,73,76,1,0,0,0,74,72,
  	1,0,0,0,74,75,1,0,0,0,75,3,1,0,0,0,76,74,1,0,0,0,77,78,6,2,-1,0,78,79,
  	5,37,0,0,79,80,3,26,13,0,80,81,5,38,0,0,81,84,1,0,0,0,82,84,5,56,0,0,
  	83,77,1,0,0,0,83,82,1,0,0,0,84,123,1,0,0,0,85,86,10,5,0,0,86,87,5,42,
  	0,0,87,88,5,42,0,0,88,122,5,56,0,0,89,90,10,4,0,0,90,91,5,27,0,0,91,96,
  	3,64,32,0,92,93,5,47,0,0,93,95,3,64,32,0,94,92,1,0,0,0,95,98,1,0,0,0,
  	96,94,1,0,0,0,96,97,1,0,0,0,97,99,1,0,0,0,98,96,1,0,0,0,99,100,5,26,0,
  	0,100,122,1,0,0,0,101,102,10,3,0,0,102,103,5,28,0,0,103,122,5,56,0,0,
  	104,105,10,2,0,0,105,106,5,39,0,0,106,107,3,26,13,0,107,108,5,40,0,0,
  	108,122,1,0,0,0,109,110,10,1,0,0,110,111,5,37,0,0,111,116,3,26,13,0,112,
  	113,5,47,0,0,113,115,3,26,13,0,114,112,1,0,0,0,115,118,1,0,0,0,116,114,
  	1,0,0,0,116,117,1,0,0,0,117,119,1,0,0,0,118,116,1,0,0,0,119,120,5,38,
  	0,0,120,122,1,0,0,0,121,85,1,0,0,0,121,89,1,0,0,0,121,101,1,0,0,0,121,
  	104,1,0,0,0,121,109,1,0,0,0,122,125,1,0,0,0,123,121,1,0,0,0,123,124,1,
  	0,0,0,124,5,1,0,0,0,125,123,1,0,0,0,126,127,6,3,-1,0,127,134,5,51,0,0,
  	128,130,5,56,0,0,129,128,1,0,0,0,129,130,1,0,0,0,130,131,1,0,0,0,131,
  	134,5,57,0,0,132,134,3,4,2,0,133,126,1,0,0,0,133,129,1,0,0,0,133,132,
  	1,0,0,0,134,209,1,0,0,0,135,136,10,20,0,0,136,137,5,31,0,0,137,208,3,
  	6,3,21,138,139,10,19,0,0,139,140,5,32,0,0,140,208,3,6,3,20,141,142,10,
  	18,0,0,142,143,5,33,0,0,143,208,3,6,3,19,144,145,10,17,0,0,145,146,5,
  	29,0,0,146,208,3,6,3,18,147,148,10,16,0,0,148,149,5,30,0,0,149,208,3,
  	6,3,17,150,151,10,15,0,0,151,152,3,8,4,0,152,153,3,6,3,16,153,208,1,0,
  	0,0,154,155,10,14,0,0,155,156,3,10,5,0,156,157,3,6,3,15,157,208,1,0,0,
  	0,158,159,10,13,0,0,159,160,3,12,6,0,160,161,3,6,3,14,161,208,1,0,0,0,
  	162,163,10,12,0,0,163,164,5,27,0,0,164,208,3,6,3,13,165,166,10,11,0,0,
  	166,167,3,14,7,0,167,168,3,6,3,12,168,208,1,0,0,0,169,170,10,10,0,0,170,
  	171,5,26,0,0,171,208,3,6,3,11,172,173,10,9,0,0,173,174,3,16,8,0,174,175,
  	3,6,3,10,175,208,1,0,0,0,176,177,10,8,0,0,177,178,3,18,9,0,178,179,3,
  	6,3,9,179,208,1,0,0,0,180,181,10,7,0,0,181,182,3,20,10,0,182,183,3,6,
  	3,8,183,208,1,0,0,0,184,185,10,6,0,0,185,186,5,35,0,0,186,208,3,6,3,7,
  	187,188,10,5,0,0,188,189,5,34,0,0,189,208,3,6,3,6,190,191,10,4,0,0,191,
  	192,5,36,0,0,192,208,3,6,3,5,193,194,10,3,0,0,194,195,3,22,11,0,195,196,
  	3,6,3,4,196,208,1,0,0,0,197,198,10,2,0,0,198,199,3,24,12,0,199,200,3,
  	6,3,3,200,208,1,0,0,0,201,202,10,1,0,0,202,203,5,41,0,0,203,204,3,6,3,
  	0,204,205,5,42,0,0,205,206,3,6,3,2,206,208,1,0,0,0,207,135,1,0,0,0,207,
  	138,1,0,0,0,207,141,1,0,0,0,207,144,1,0,0,0,207,147,1,0,0,0,207,150,1,
  	0,0,0,207,154,1,0,0,0,207,158,1,0,0,0,207,162,1,0,0,0,207,165,1,0,0,0,
  	207,169,1,0,0,0,207,172,1,0,0,0,207,176,1,0,0,0,207,180,1,0,0,0,207,184,
  	1,0,0,0,207,187,1,0,0,0,207,190,1,0,0,0,207,193,1,0,0,0,207,197,1,0,0,
  	0,207,201,1,0,0,0,208,211,1,0,0,0,209,207,1,0,0,0,209,210,1,0,0,0,210,
  	7,1,0,0,0,211,209,1,0,0,0,212,213,5,27,0,0,213,214,5,27,0,0,214,9,1,0,
  	0,0,215,216,5,26,0,0,216,217,5,26,0,0,217,11,1,0,0,0,218,219,5,26,0,0,
  	219,220,5,26,0,0,220,221,5,26,0,0,221,13,1,0,0,0,222,223,5,27,0,0,223,
  	224,5,25,0,0,224,15,1,0,0,0,225,226,5,26,0,0,226,227,5,25,0,0,227,17,
  	1,0,0,0,228,229,5,25,0,0,229,230,5,25,0,0,230,19,1,0,0,0,231,232,5,46,
  	0,0,232,233,5,25,0,0,233,21,1,0,0,0,234,235,5,35,0,0,235,236,5,35,0,0,
  	236,23,1,0,0,0,237,238,5,36,0,0,238,239,5,36,0,0,239,25,1,0,0,0,240,241,
  	3,6,3,0,241,27,1,0,0,0,242,243,5,8,0,0,243,254,5,56,0,0,244,245,5,27,
  	0,0,245,250,5,56,0,0,246,247,5,47,0,0,247,249,5,56,0,0,248,246,1,0,0,
  	0,249,252,1,0,0,0,250,248,1,0,0,0,250,251,1,0,0,0,251,253,1,0,0,0,252,
  	250,1,0,0,0,253,255,5,26,0,0,254,244,1,0,0,0,254,255,1,0,0,0,255,256,
  	1,0,0,0,256,257,5,48,0,0,257,29,1,0,0,0,258,259,5,8,0,0,259,270,5,56,
  	0,0,260,261,5,27,0,0,261,266,5,56,0,0,262,263,5,47,0,0,263,265,5,56,0,
  	0,264,262,1,0,0,0,265,268,1,0,0,0,266,264,1,0,0,0,266,267,1,0,0,0,267,
  	269,1,0,0,0,268,266,1,0,0,0,269,271,5,26,0,0,270,260,1,0,0,0,270,271,
  	1,0,0,0,271,272,1,0,0,0,272,276,5,49,0,0,273,275,3,32,16,0,274,273,1,
  	0,0,0,275,278,1,0,0,0,276,274,1,0,0,0,276,277,1,0,0,0,277,279,1,0,0,0,
  	278,276,1,0,0,0,279,280,5,50,0,0,280,31,1,0,0,0,281,282,3,66,33,0,282,
  	283,5,48,0,0,283,33,1,0,0,0,284,288,5,16,0,0,285,288,5,18,0,0,286,288,
  	5,17,0,0,287,284,1,0,0,0,287,285,1,0,0,0,287,286,1,0,0,0,287,288,1,0,
  	0,0,288,289,1,0,0,0,289,290,5,2,0,0,290,301,5,56,0,0,291,292,5,27,0,0,
  	292,297,5,56,0,0,293,294,5,47,0,0,294,296,5,56,0,0,295,293,1,0,0,0,296,
  	299,1,0,0,0,297,295,1,0,0,0,297,298,1,0,0,0,298,300,1,0,0,0,299,297,1,
  	0,0,0,300,302,5,26,0,0,301,291,1,0,0,0,301,302,1,0,0,0,302,303,1,0,0,
  	0,303,312,5,37,0,0,304,309,3,66,33,0,305,306,5,47,0,0,306,308,3,66,33,
  	0,307,305,1,0,0,0,308,311,1,0,0,0,309,307,1,0,0,0,309,310,1,0,0,0,310,
  	313,1,0,0,0,311,309,1,0,0,0,312,304,1,0,0,0,312,313,1,0,0,0,313,314,1,
  	0,0,0,314,317,5,38,0,0,315,316,5,42,0,0,316,318,3,64,32,0,317,315,1,0,
  	0,0,317,318,1,0,0,0,318,319,1,0,0,0,319,320,5,48,0,0,320,35,1,0,0,0,321,
  	325,5,16,0,0,322,325,5,18,0,0,323,325,5,17,0,0,324,321,1,0,0,0,324,322,
  	1,0,0,0,324,323,1,0,0,0,324,325,1,0,0,0,325,326,1,0,0,0,326,327,5,2,0,
  	0,327,338,5,56,0,0,328,329,5,27,0,0,329,334,5,56,0,0,330,331,5,47,0,0,
  	331,333,5,56,0,0,332,330,1,0,0,0,333,336,1,0,0,0,334,332,1,0,0,0,334,
  	335,1,0,0,0,335,337,1,0,0,0,336,334,1,0,0,0,337,339,5,26,0,0,338,328,
  	1,0,0,0,338,339,1,0,0,0,339,340,1,0,0,0,340,349,5,37,0,0,341,346,3,66,
  	33,0,342,343,5,47,0,0,343,345,3,66,33,0,344,342,1,0,0,0,345,348,1,0,0,
  	0,346,344,1,0,0,0,346,347,1,0,0,0,347,350,1,0,0,0,348,346,1,0,0,0,349,
  	341,1,0,0,0,349,350,1,0,0,0,350,351,1,0,0,0,351,354,5,38,0,0,352,353,
  	5,42,0,0,353,355,3,64,32,0,354,352,1,0,0,0,354,355,1,0,0,0,355,356,1,
  	0,0,0,356,357,3,58,29,0,357,37,1,0,0,0,358,362,5,22,0,0,359,362,5,23,
  	0,0,360,362,5,1,0,0,361,358,1,0,0,0,361,359,1,0,0,0,361,360,1,0,0,0,362,
  	363,1,0,0,0,363,366,5,56,0,0,364,365,5,42,0,0,365,367,3,64,32,0,366,364,
  	1,0,0,0,366,367,1,0,0,0,367,368,1,0,0,0,368,369,5,48,0,0,369,39,1,0,0,
  	0,370,374,5,22,0,0,371,374,5,23,0,0,372,374,5,1,0,0,373,370,1,0,0,0,373,
  	371,1,0,0,0,373,372,1,0,0,0,374,375,1,0,0,0,375,378,5,56,0,0,376,377,
  	5,42,0,0,377,379,3,64,32,0,378,376,1,0,0,0,378,379,1,0,0,0,379,380,1,
  	0,0,0,380,381,5,25,0,0,381,382,3,26,13,0,382,383,5,48,0,0,383,41,1,0,
  	0,0,384,385,5,24,0,0,385,386,5,56,0,0,386,387,5,25,0,0,387,388,3,26,13,
  	0,388,389,5,48,0,0,389,43,1,0,0,0,390,391,5,11,0,0,391,392,5,56,0,0,392,
  	45,1,0,0,0,393,394,5,11,0,0,394,395,5,56,0,0,395,396,3,58,29,0,396,47,
  	1,0,0,0,397,398,3,4,2,0,398,399,5,28,0,0,399,400,5,56,0,0,400,401,5,25,
  	0,0,401,402,3,26,13,0,402,403,5,48,0,0,403,49,1,0,0,0,404,405,3,4,2,0,
  	405,406,5,39,0,0,406,407,3,26,13,0,407,408,5,40,0,0,408,409,5,25,0,0,
  	409,410,3,26,13,0,410,411,5,48,0,0,411,51,1,0,0,0,412,413,3,4,2,0,413,
  	414,5,42,0,0,414,415,5,42,0,0,415,416,5,56,0,0,416,417,5,25,0,0,417,418,
  	3,26,13,0,418,419,5,48,0,0,419,53,1,0,0,0,420,421,5,3,0,0,421,422,3,6,
  	3,0,422,428,3,58,29,0,423,426,5,4,0,0,424,427,3,58,29,0,425,427,3,54,
  	27,0,426,424,1,0,0,0,426,425,1,0,0,0,427,429,1,0,0,0,428,423,1,0,0,0,
  	428,429,1,0,0,0,429,55,1,0,0,0,430,431,5,5,0,0,431,432,3,6,3,0,432,433,
  	3,58,29,0,433,57,1,0,0,0,434,438,5,49,0,0,435,437,3,60,30,0,436,435,1,
  	0,0,0,437,440,1,0,0,0,438,436,1,0,0,0,438,439,1,0,0,0,439,441,1,0,0,0,
  	440,438,1,0,0,0,441,442,5,50,0,0,442,59,1,0,0,0,443,462,3,28,14,0,444,
  	462,3,30,15,0,445,462,3,34,17,0,446,462,3,36,18,0,447,462,3,38,19,0,448,
  	462,3,40,20,0,449,462,3,48,24,0,450,462,3,52,26,0,451,462,3,50,25,0,452,
  	462,3,42,21,0,453,462,3,44,22,0,454,462,3,46,23,0,455,462,3,26,13,0,456,
  	462,3,54,27,0,457,462,3,56,28,0,458,462,3,58,29,0,459,462,3,62,31,0,460,
  	462,5,48,0,0,461,443,1,0,0,0,461,444,1,0,0,0,461,445,1,0,0,0,461,446,
  	1,0,0,0,461,447,1,0,0,0,461,448,1,0,0,0,461,449,1,0,0,0,461,450,1,0,0,
  	0,461,451,1,0,0,0,461,452,1,0,0,0,461,453,1,0,0,0,461,454,1,0,0,0,461,
  	455,1,0,0,0,461,456,1,0,0,0,461,457,1,0,0,0,461,458,1,0,0,0,461,459,1,
  	0,0,0,461,460,1,0,0,0,462,61,1,0,0,0,463,464,5,6,0,0,464,465,3,26,13,
  	0,465,466,5,48,0,0,466,63,1,0,0,0,467,468,6,32,-1,0,468,469,5,37,0,0,
  	469,470,3,64,32,0,470,471,5,38,0,0,471,501,1,0,0,0,472,501,5,56,0,0,473,
  	474,5,37,0,0,474,477,3,64,32,0,475,476,5,47,0,0,476,478,3,64,32,0,477,
  	475,1,0,0,0,478,479,1,0,0,0,479,477,1,0,0,0,479,480,1,0,0,0,480,481,1,
  	0,0,0,481,482,5,38,0,0,482,483,5,30,0,0,483,484,5,26,0,0,484,485,3,64,
  	32,2,485,501,1,0,0,0,486,487,5,37,0,0,487,492,3,66,33,0,488,489,5,47,
  	0,0,489,491,3,66,33,0,490,488,1,0,0,0,491,494,1,0,0,0,492,490,1,0,0,0,
  	492,493,1,0,0,0,493,495,1,0,0,0,494,492,1,0,0,0,495,496,5,38,0,0,496,
  	497,5,30,0,0,497,498,5,26,0,0,498,499,3,64,32,1,499,501,1,0,0,0,500,467,
  	1,0,0,0,500,472,1,0,0,0,500,473,1,0,0,0,500,486,1,0,0,0,501,531,1,0,0,
  	0,502,503,10,3,0,0,503,504,5,30,0,0,504,505,5,26,0,0,505,530,3,64,32,
  	4,506,507,10,7,0,0,507,508,5,42,0,0,508,509,5,42,0,0,509,530,5,56,0,0,
  	510,511,10,6,0,0,511,512,5,27,0,0,512,517,3,64,32,0,513,514,5,47,0,0,
  	514,516,3,64,32,0,515,513,1,0,0,0,516,519,1,0,0,0,517,515,1,0,0,0,517,
  	518,1,0,0,0,518,520,1,0,0,0,519,517,1,0,0,0,520,521,5,26,0,0,521,530,
  	1,0,0,0,522,523,10,5,0,0,523,524,5,28,0,0,524,530,5,56,0,0,525,526,10,
  	4,0,0,526,527,5,39,0,0,527,528,5,51,0,0,528,530,5,40,0,0,529,502,1,0,
  	0,0,529,506,1,0,0,0,529,510,1,0,0,0,529,522,1,0,0,0,529,525,1,0,0,0,530,
  	533,1,0,0,0,531,529,1,0,0,0,531,532,1,0,0,0,532,65,1,0,0,0,533,531,1,
  	0,0,0,534,535,5,56,0,0,535,536,5,42,0,0,536,537,3,64,32,0,537,67,1,0,
  	0,0,41,74,83,96,116,121,123,129,133,207,209,250,254,266,270,276,287,297,
  	301,309,312,317,324,334,338,346,349,354,361,366,373,378,426,428,438,461,
  	479,492,500,517,529,531
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
    setState(68);
    antlrcpp::downCast<FileContext *>(_localctx)->f_program = program();
    setState(69);
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
    setState(74);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 219269144326375790) != 0)) {
      setState(71);
      body_element();
      setState(76);
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

std::vector<TsilParser::TypeContext *> TsilParser::Atom_template_getContext::type() {
  return getRuleContexts<TsilParser::TypeContext>();
}

TsilParser::TypeContext* TsilParser::Atom_template_getContext::type(size_t i) {
  return getRuleContext<TsilParser::TypeContext>(i);
}

tree::TerminalNode* TsilParser::Atom_template_getContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

TsilParser::AtomContext* TsilParser::Atom_template_getContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
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

std::vector<TsilParser::ExprContext *> TsilParser::Atom_callContext::expr() {
  return getRuleContexts<TsilParser::ExprContext>();
}

TsilParser::ExprContext* TsilParser::Atom_callContext::expr(size_t i) {
  return getRuleContext<TsilParser::ExprContext>(i);
}

tree::TerminalNode* TsilParser::Atom_callContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

TsilParser::AtomContext* TsilParser::Atom_callContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
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
    setState(83);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::PAREN_OPEN: {
        _localctx = _tracker.createInstance<Atom_nestedContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(78);
        match(TsilParser::PAREN_OPEN);
        setState(79);
        expr();
        setState(80);
        match(TsilParser::PAREN_CLOSE);
        break;
      }

      case TsilParser::ID: {
        _localctx = _tracker.createInstance<Atom_subjectContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(82);
        antlrcpp::downCast<Atom_subjectContext *>(_localctx)->id = match(TsilParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(123);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(121);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Atom_section_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(85);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(86);
          match(TsilParser::COLON);
          setState(87);
          match(TsilParser::COLON);
          setState(88);
          antlrcpp::downCast<Atom_section_getContext *>(_localctx)->id = match(TsilParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Atom_template_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(89);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(90);
          match(TsilParser::LESSER);
          setState(91);
          type(0);
          setState(96);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == TsilParser::COMA) {
            setState(92);
            match(TsilParser::COMA);
            setState(93);
            type(0);
            setState(98);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(99);
          match(TsilParser::GREATER);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Atom_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(101);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(102);
          match(TsilParser::DOT);
          setState(103);
          antlrcpp::downCast<Atom_getContext *>(_localctx)->id = match(TsilParser::ID);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Atom_position_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(104);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(105);
          match(TsilParser::BRACKET_OPEN);
          setState(106);
          antlrcpp::downCast<Atom_position_getContext *>(_localctx)->position = expr();
          setState(107);
          match(TsilParser::BRACKET_CLOSE);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Atom_callContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(109);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(110);
          match(TsilParser::PAREN_OPEN);
          setState(111);
          expr();
          setState(116);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == TsilParser::COMA) {
            setState(112);
            match(TsilParser::COMA);
            setState(113);
            expr();
            setState(118);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(119);
          match(TsilParser::PAREN_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(125);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
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
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, TsilParser::RuleOperation, precedence);

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
    setState(133);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Operation_numberContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(127);
      match(TsilParser::NUMBER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Operation_stringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(129);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TsilParser::ID) {
        setState(128);
        antlrcpp::downCast<Operation_stringContext *>(_localctx)->tt = match(TsilParser::ID);
      }
      setState(131);
      match(TsilParser::STRING);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Operation_atomContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(132);
      atom(0);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(209);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(207);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Operation_mulContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(135);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(136);
          antlrcpp::downCast<Operation_mulContext *>(_localctx)->op = match(TsilParser::MULTIPLY);
          setState(137);
          antlrcpp::downCast<Operation_mulContext *>(_localctx)->right = operation(21);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Operation_divContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(138);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(139);
          antlrcpp::downCast<Operation_divContext *>(_localctx)->op = match(TsilParser::DIVIDE);
          setState(140);
          antlrcpp::downCast<Operation_divContext *>(_localctx)->right = operation(20);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Operation_modContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(141);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(142);
          antlrcpp::downCast<Operation_modContext *>(_localctx)->op = match(TsilParser::MOD);
          setState(143);
          antlrcpp::downCast<Operation_modContext *>(_localctx)->right = operation(19);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Operation_addContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(144);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(145);
          antlrcpp::downCast<Operation_addContext *>(_localctx)->op = match(TsilParser::PLUS);
          setState(146);
          antlrcpp::downCast<Operation_addContext *>(_localctx)->right = operation(18);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Operation_subContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(147);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(148);
          antlrcpp::downCast<Operation_subContext *>(_localctx)->op = match(TsilParser::MINUS);
          setState(149);
          antlrcpp::downCast<Operation_subContext *>(_localctx)->right = operation(17);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<Operation_lshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(150);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(151);
          antlrcpp::downCast<Operation_lshiftContext *>(_localctx)->op = op_lshift();
          setState(152);
          antlrcpp::downCast<Operation_lshiftContext *>(_localctx)->right = operation(16);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<Operation_rshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(154);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(155);
          antlrcpp::downCast<Operation_rshiftContext *>(_localctx)->op = op_rshift();
          setState(156);
          antlrcpp::downCast<Operation_rshiftContext *>(_localctx)->right = operation(15);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<Operation_urshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(158);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(159);
          antlrcpp::downCast<Operation_urshiftContext *>(_localctx)->op = op_urshift();
          setState(160);
          antlrcpp::downCast<Operation_urshiftContext *>(_localctx)->right = operation(14);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<Operation_ltContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(162);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(163);
          antlrcpp::downCast<Operation_ltContext *>(_localctx)->op = match(TsilParser::LESSER);
          setState(164);
          antlrcpp::downCast<Operation_ltContext *>(_localctx)->right = operation(13);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<Operation_lteContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(165);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(166);
          antlrcpp::downCast<Operation_lteContext *>(_localctx)->op = op_lte();
          setState(167);
          antlrcpp::downCast<Operation_lteContext *>(_localctx)->right = operation(12);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<Operation_gtContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(169);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(170);
          antlrcpp::downCast<Operation_gtContext *>(_localctx)->op = match(TsilParser::GREATER);
          setState(171);
          antlrcpp::downCast<Operation_gtContext *>(_localctx)->right = operation(11);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<Operation_gteContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(172);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(173);
          antlrcpp::downCast<Operation_gteContext *>(_localctx)->op = op_gte();
          setState(174);
          antlrcpp::downCast<Operation_gteContext *>(_localctx)->right = operation(10);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<Operation_eqContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(176);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(177);
          antlrcpp::downCast<Operation_eqContext *>(_localctx)->op = op_eq();
          setState(178);
          antlrcpp::downCast<Operation_eqContext *>(_localctx)->right = operation(9);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<Operation_neqContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(180);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(181);
          antlrcpp::downCast<Operation_neqContext *>(_localctx)->op = op_neq();
          setState(182);
          antlrcpp::downCast<Operation_neqContext *>(_localctx)->right = operation(8);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<Operation_andContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(184);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(185);
          antlrcpp::downCast<Operation_andContext *>(_localctx)->op = match(TsilParser::AND);
          setState(186);
          antlrcpp::downCast<Operation_andContext *>(_localctx)->right = operation(7);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<Operation_xorContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(187);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(188);
          antlrcpp::downCast<Operation_xorContext *>(_localctx)->op = match(TsilParser::POWER);
          setState(189);
          antlrcpp::downCast<Operation_xorContext *>(_localctx)->right = operation(6);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<Operation_orContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(190);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(191);
          antlrcpp::downCast<Operation_orContext *>(_localctx)->op = match(TsilParser::OR);
          setState(192);
          antlrcpp::downCast<Operation_orContext *>(_localctx)->right = operation(5);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<Operation_landContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(193);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(194);
          antlrcpp::downCast<Operation_landContext *>(_localctx)->op = op_land();
          setState(195);
          antlrcpp::downCast<Operation_landContext *>(_localctx)->right = operation(4);
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<Operation_lorContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(197);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(198);
          antlrcpp::downCast<Operation_lorContext *>(_localctx)->op = op_lor();
          setState(199);
          antlrcpp::downCast<Operation_lorContext *>(_localctx)->right = operation(3);
          break;
        }

        case 20: {
          auto newContext = _tracker.createInstance<Operation_ternaryContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->cond = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(201);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(202);
          match(TsilParser::QUESTION);
          setState(203);
          antlrcpp::downCast<Operation_ternaryContext *>(_localctx)->ifok = operation(0);
          setState(204);
          match(TsilParser::COLON);
          setState(205);
          antlrcpp::downCast<Operation_ternaryContext *>(_localctx)->ifnot = operation(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(211);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
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
  enterRule(_localctx, 8, TsilParser::RuleOp_lshift);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    match(TsilParser::LESSER);
    setState(213);
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
  enterRule(_localctx, 10, TsilParser::RuleOp_rshift);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    match(TsilParser::GREATER);
    setState(216);
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
  enterRule(_localctx, 12, TsilParser::RuleOp_urshift);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    match(TsilParser::GREATER);
    setState(219);
    match(TsilParser::GREATER);
    setState(220);
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
  enterRule(_localctx, 14, TsilParser::RuleOp_lte);

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
    match(TsilParser::LESSER);
    setState(223);
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
  enterRule(_localctx, 16, TsilParser::RuleOp_gte);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    match(TsilParser::GREATER);
    setState(226);
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
  enterRule(_localctx, 18, TsilParser::RuleOp_eq);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(228);
    match(TsilParser::EQUAL);
    setState(229);
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
  enterRule(_localctx, 20, TsilParser::RuleOp_neq);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(231);
    match(TsilParser::EXCLAMATION);
    setState(232);
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
  enterRule(_localctx, 22, TsilParser::RuleOp_land);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(234);
    match(TsilParser::AND);
    setState(235);
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
  enterRule(_localctx, 24, TsilParser::RuleOp_lor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    match(TsilParser::OR);
    setState(238);
    match(TsilParser::OR);
   
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
  enterRule(_localctx, 26, TsilParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<TsilParser::Expr_operationContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(240);
    operation(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Structure_declareContext ------------------------------------------------------------------

TsilParser::Structure_declareContext::Structure_declareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Structure_declareContext::KW_STRUCT() {
  return getToken(TsilParser::KW_STRUCT, 0);
}

tree::TerminalNode* TsilParser::Structure_declareContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> TsilParser::Structure_declareContext::ID() {
  return getTokens(TsilParser::ID);
}

tree::TerminalNode* TsilParser::Structure_declareContext::ID(size_t i) {
  return getToken(TsilParser::ID, i);
}

tree::TerminalNode* TsilParser::Structure_declareContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::Structure_declareContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

std::vector<tree::TerminalNode *> TsilParser::Structure_declareContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Structure_declareContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::Structure_declareContext::getRuleIndex() const {
  return TsilParser::RuleStructure_declare;
}

void TsilParser::Structure_declareContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructure_declare(this);
}

void TsilParser::Structure_declareContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructure_declare(this);
}


std::any TsilParser::Structure_declareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitStructure_declare(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Structure_declareContext* TsilParser::structure_declare() {
  Structure_declareContext *_localctx = _tracker.createInstance<Structure_declareContext>(_ctx, getState());
  enterRule(_localctx, 28, TsilParser::RuleStructure_declare);
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
    match(TsilParser::KW_STRUCT);
    setState(243);
    antlrcpp::downCast<Structure_declareContext *>(_localctx)->id = match(TsilParser::ID);
    setState(254);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(244);
      match(TsilParser::LESSER);
      setState(245);
      antlrcpp::downCast<Structure_declareContext *>(_localctx)->generic_id = match(TsilParser::ID);
      setState(250);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(246);
        match(TsilParser::COMA);
        setState(247);
        antlrcpp::downCast<Structure_declareContext *>(_localctx)->generic_id = match(TsilParser::ID);
        setState(252);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(253);
      match(TsilParser::GREATER);
    }
    setState(256);
    match(TsilParser::SEMICOLON);
   
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

tree::TerminalNode* TsilParser::Structure_defineContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::Structure_defineContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}

std::vector<tree::TerminalNode *> TsilParser::Structure_defineContext::ID() {
  return getTokens(TsilParser::ID);
}

tree::TerminalNode* TsilParser::Structure_defineContext::ID(size_t i) {
  return getToken(TsilParser::ID, i);
}

tree::TerminalNode* TsilParser::Structure_defineContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::Structure_defineContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

std::vector<TsilParser::Structure_elementContext *> TsilParser::Structure_defineContext::structure_element() {
  return getRuleContexts<TsilParser::Structure_elementContext>();
}

TsilParser::Structure_elementContext* TsilParser::Structure_defineContext::structure_element(size_t i) {
  return getRuleContext<TsilParser::Structure_elementContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Structure_defineContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Structure_defineContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
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
  enterRule(_localctx, 30, TsilParser::RuleStructure_define);
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
    setState(258);
    match(TsilParser::KW_STRUCT);
    setState(259);
    antlrcpp::downCast<Structure_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(270);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(260);
      match(TsilParser::LESSER);
      setState(261);
      antlrcpp::downCast<Structure_defineContext *>(_localctx)->generic_id = match(TsilParser::ID);
      setState(266);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(262);
        match(TsilParser::COMA);
        setState(263);
        antlrcpp::downCast<Structure_defineContext *>(_localctx)->generic_id = match(TsilParser::ID);
        setState(268);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(269);
      match(TsilParser::GREATER);
    }
    setState(272);
    match(TsilParser::QUOTE_OPEN);
    setState(276);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TsilParser::ID) {
      setState(273);
      structure_element();
      setState(278);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(279);
    match(TsilParser::QUOTE_CLOSE);
   
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
  enterRule(_localctx, 32, TsilParser::RuleStructure_element);

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
    param();
    setState(282);
    match(TsilParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Diia_declareContext ------------------------------------------------------------------

TsilParser::Diia_declareContext::Diia_declareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Diia_declareContext::KW_DIIA() {
  return getToken(TsilParser::KW_DIIA, 0);
}

tree::TerminalNode* TsilParser::Diia_declareContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

tree::TerminalNode* TsilParser::Diia_declareContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

tree::TerminalNode* TsilParser::Diia_declareContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> TsilParser::Diia_declareContext::ID() {
  return getTokens(TsilParser::ID);
}

tree::TerminalNode* TsilParser::Diia_declareContext::ID(size_t i) {
  return getToken(TsilParser::ID, i);
}

tree::TerminalNode* TsilParser::Diia_declareContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::Diia_declareContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

std::vector<TsilParser::ParamContext *> TsilParser::Diia_declareContext::param() {
  return getRuleContexts<TsilParser::ParamContext>();
}

TsilParser::ParamContext* TsilParser::Diia_declareContext::param(size_t i) {
  return getRuleContext<TsilParser::ParamContext>(i);
}

tree::TerminalNode* TsilParser::Diia_declareContext::COLON() {
  return getToken(TsilParser::COLON, 0);
}

tree::TerminalNode* TsilParser::Diia_declareContext::KW_PUBLIC() {
  return getToken(TsilParser::KW_PUBLIC, 0);
}

tree::TerminalNode* TsilParser::Diia_declareContext::KW_LOCAL() {
  return getToken(TsilParser::KW_LOCAL, 0);
}

tree::TerminalNode* TsilParser::Diia_declareContext::KW_PRIVATE() {
  return getToken(TsilParser::KW_PRIVATE, 0);
}

TsilParser::TypeContext* TsilParser::Diia_declareContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> TsilParser::Diia_declareContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Diia_declareContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::Diia_declareContext::getRuleIndex() const {
  return TsilParser::RuleDiia_declare;
}

void TsilParser::Diia_declareContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiia_declare(this);
}

void TsilParser::Diia_declareContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiia_declare(this);
}


std::any TsilParser::Diia_declareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitDiia_declare(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Diia_declareContext* TsilParser::diia_declare() {
  Diia_declareContext *_localctx = _tracker.createInstance<Diia_declareContext>(_ctx, getState());
  enterRule(_localctx, 34, TsilParser::RuleDiia_declare);
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
    setState(287);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(284);
        antlrcpp::downCast<Diia_declareContext *>(_localctx)->extern_ = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(285);
        antlrcpp::downCast<Diia_declareContext *>(_localctx)->local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(286);
        antlrcpp::downCast<Diia_declareContext *>(_localctx)->intern = match(TsilParser::KW_PRIVATE);
        break;
      }

      case TsilParser::KW_DIIA: {
        break;
      }

    default:
      break;
    }
    setState(289);
    match(TsilParser::KW_DIIA);
    setState(290);
    antlrcpp::downCast<Diia_declareContext *>(_localctx)->id = match(TsilParser::ID);
    setState(301);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(291);
      match(TsilParser::LESSER);
      setState(292);
      antlrcpp::downCast<Diia_declareContext *>(_localctx)->generic_id = match(TsilParser::ID);
      setState(297);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(293);
        match(TsilParser::COMA);
        setState(294);
        antlrcpp::downCast<Diia_declareContext *>(_localctx)->generic_id = match(TsilParser::ID);
        setState(299);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(300);
      match(TsilParser::GREATER);
    }
    setState(303);
    match(TsilParser::PAREN_OPEN);
    setState(312);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(304);
      param();
      setState(309);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(305);
        match(TsilParser::COMA);
        setState(306);
        param();
        setState(311);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(314);
    match(TsilParser::PAREN_CLOSE);
    setState(317);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(315);
      match(TsilParser::COLON);
      setState(316);
      antlrcpp::downCast<Diia_declareContext *>(_localctx)->restyp = type(0);
    }
    setState(319);
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

TsilParser::BodyContext* TsilParser::Diia_defineContext::body() {
  return getRuleContext<TsilParser::BodyContext>(0);
}

std::vector<tree::TerminalNode *> TsilParser::Diia_defineContext::ID() {
  return getTokens(TsilParser::ID);
}

tree::TerminalNode* TsilParser::Diia_defineContext::ID(size_t i) {
  return getToken(TsilParser::ID, i);
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
  enterRule(_localctx, 36, TsilParser::RuleDiia_define);
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
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(321);
        antlrcpp::downCast<Diia_defineContext *>(_localctx)->extern_ = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(322);
        antlrcpp::downCast<Diia_defineContext *>(_localctx)->local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(323);
        antlrcpp::downCast<Diia_defineContext *>(_localctx)->intern = match(TsilParser::KW_PRIVATE);
        break;
      }

      case TsilParser::KW_DIIA: {
        break;
      }

    default:
      break;
    }
    setState(326);
    match(TsilParser::KW_DIIA);
    setState(327);
    antlrcpp::downCast<Diia_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(338);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(328);
      match(TsilParser::LESSER);
      setState(329);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->generic_id = match(TsilParser::ID);
      setState(334);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(330);
        match(TsilParser::COMA);
        setState(331);
        antlrcpp::downCast<Diia_defineContext *>(_localctx)->generic_id = match(TsilParser::ID);
        setState(336);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(337);
      match(TsilParser::GREATER);
    }
    setState(340);
    match(TsilParser::PAREN_OPEN);
    setState(349);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(341);
      param();
      setState(346);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(342);
        match(TsilParser::COMA);
        setState(343);
        param();
        setState(348);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(351);
    match(TsilParser::PAREN_CLOSE);
    setState(354);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(352);
      match(TsilParser::COLON);
      setState(353);
      antlrcpp::downCast<Diia_defineContext *>(_localctx)->restyp = type(0);
    }
    setState(356);
    body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Tsil_declareContext ------------------------------------------------------------------

TsilParser::Tsil_declareContext::Tsil_declareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Tsil_declareContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

tree::TerminalNode* TsilParser::Tsil_declareContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::Tsil_declareContext::KW_VAR() {
  return getToken(TsilParser::KW_VAR, 0);
}

tree::TerminalNode* TsilParser::Tsil_declareContext::KW_IMMUT() {
  return getToken(TsilParser::KW_IMMUT, 0);
}

tree::TerminalNode* TsilParser::Tsil_declareContext::KW_TSIL() {
  return getToken(TsilParser::KW_TSIL, 0);
}

tree::TerminalNode* TsilParser::Tsil_declareContext::COLON() {
  return getToken(TsilParser::COLON, 0);
}

TsilParser::TypeContext* TsilParser::Tsil_declareContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}


size_t TsilParser::Tsil_declareContext::getRuleIndex() const {
  return TsilParser::RuleTsil_declare;
}

void TsilParser::Tsil_declareContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTsil_declare(this);
}

void TsilParser::Tsil_declareContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTsil_declare(this);
}


std::any TsilParser::Tsil_declareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitTsil_declare(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Tsil_declareContext* TsilParser::tsil_declare() {
  Tsil_declareContext *_localctx = _tracker.createInstance<Tsil_declareContext>(_ctx, getState());
  enterRule(_localctx, 38, TsilParser::RuleTsil_declare);
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
      case TsilParser::KW_VAR: {
        setState(358);
        antlrcpp::downCast<Tsil_declareContext *>(_localctx)->td_var = match(TsilParser::KW_VAR);
        break;
      }

      case TsilParser::KW_IMMUT: {
        setState(359);
        antlrcpp::downCast<Tsil_declareContext *>(_localctx)->td_immut = match(TsilParser::KW_IMMUT);
        break;
      }

      case TsilParser::KW_TSIL: {
        setState(360);
        antlrcpp::downCast<Tsil_declareContext *>(_localctx)->td_const = match(TsilParser::KW_TSIL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(363);
    antlrcpp::downCast<Tsil_declareContext *>(_localctx)->id = match(TsilParser::ID);
    setState(366);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(364);
      match(TsilParser::COLON);
      setState(365);
      type(0);
    }
    setState(368);
    match(TsilParser::SEMICOLON);
   
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

tree::TerminalNode* TsilParser::Tsil_defineContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}

TsilParser::ExprContext* TsilParser::Tsil_defineContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

tree::TerminalNode* TsilParser::Tsil_defineContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

tree::TerminalNode* TsilParser::Tsil_defineContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::Tsil_defineContext::KW_VAR() {
  return getToken(TsilParser::KW_VAR, 0);
}

tree::TerminalNode* TsilParser::Tsil_defineContext::KW_IMMUT() {
  return getToken(TsilParser::KW_IMMUT, 0);
}

tree::TerminalNode* TsilParser::Tsil_defineContext::KW_TSIL() {
  return getToken(TsilParser::KW_TSIL, 0);
}

tree::TerminalNode* TsilParser::Tsil_defineContext::COLON() {
  return getToken(TsilParser::COLON, 0);
}

TsilParser::TypeContext* TsilParser::Tsil_defineContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
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
  enterRule(_localctx, 40, TsilParser::RuleTsil_define);
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
    setState(373);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_VAR: {
        setState(370);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_var = match(TsilParser::KW_VAR);
        break;
      }

      case TsilParser::KW_IMMUT: {
        setState(371);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_immut = match(TsilParser::KW_IMMUT);
        break;
      }

      case TsilParser::KW_TSIL: {
        setState(372);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_const = match(TsilParser::KW_TSIL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(375);
    antlrcpp::downCast<Tsil_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(378);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(376);
      match(TsilParser::COLON);
      setState(377);
      type(0);
    }
    setState(380);
    match(TsilParser::EQUAL);
    setState(381);
    expr();
    setState(382);
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
  enterRule(_localctx, 42, TsilParser::RuleSynonym);

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
    match(TsilParser::KW_SYNONYM);
    setState(385);
    antlrcpp::downCast<SynonymContext *>(_localctx)->id = match(TsilParser::ID);
    setState(386);
    match(TsilParser::EQUAL);
    setState(387);
    expr();
    setState(388);
    match(TsilParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Section_declareContext ------------------------------------------------------------------

TsilParser::Section_declareContext::Section_declareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Section_declareContext::KW_SECTION() {
  return getToken(TsilParser::KW_SECTION, 0);
}

tree::TerminalNode* TsilParser::Section_declareContext::ID() {
  return getToken(TsilParser::ID, 0);
}


size_t TsilParser::Section_declareContext::getRuleIndex() const {
  return TsilParser::RuleSection_declare;
}

void TsilParser::Section_declareContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSection_declare(this);
}

void TsilParser::Section_declareContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSection_declare(this);
}


std::any TsilParser::Section_declareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSection_declare(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Section_declareContext* TsilParser::section_declare() {
  Section_declareContext *_localctx = _tracker.createInstance<Section_declareContext>(_ctx, getState());
  enterRule(_localctx, 44, TsilParser::RuleSection_declare);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(390);
    match(TsilParser::KW_SECTION);
    setState(391);
    antlrcpp::downCast<Section_declareContext *>(_localctx)->id = match(TsilParser::ID);
   
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

TsilParser::BodyContext* TsilParser::Section_defineContext::body() {
  return getRuleContext<TsilParser::BodyContext>(0);
}

tree::TerminalNode* TsilParser::Section_defineContext::ID() {
  return getToken(TsilParser::ID, 0);
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
  enterRule(_localctx, 46, TsilParser::RuleSection_define);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(393);
    match(TsilParser::KW_SECTION);
    setState(394);
    antlrcpp::downCast<Section_defineContext *>(_localctx)->id = match(TsilParser::ID);
    setState(395);
    body();
   
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
  enterRule(_localctx, 48, TsilParser::RuleSet);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(397);
    antlrcpp::downCast<SetContext *>(_localctx)->object = atom(0);
    setState(398);
    match(TsilParser::DOT);
    setState(399);
    antlrcpp::downCast<SetContext *>(_localctx)->id = match(TsilParser::ID);
    setState(400);
    match(TsilParser::EQUAL);
    setState(401);
    antlrcpp::downCast<SetContext *>(_localctx)->value = expr();
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
  enterRule(_localctx, 50, TsilParser::RulePosition_set);

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
    antlrcpp::downCast<Position_setContext *>(_localctx)->object = atom(0);
    setState(405);
    match(TsilParser::BRACKET_OPEN);
    setState(406);
    antlrcpp::downCast<Position_setContext *>(_localctx)->idx = expr();
    setState(407);
    match(TsilParser::BRACKET_CLOSE);
    setState(408);
    match(TsilParser::EQUAL);
    setState(409);
    antlrcpp::downCast<Position_setContext *>(_localctx)->value = expr();
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
  enterRule(_localctx, 52, TsilParser::RuleSection_set);

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
    antlrcpp::downCast<Section_setContext *>(_localctx)->object = atom(0);
    setState(413);
    match(TsilParser::COLON);
    setState(414);
    match(TsilParser::COLON);
    setState(415);
    antlrcpp::downCast<Section_setContext *>(_localctx)->id = match(TsilParser::ID);
    setState(416);
    match(TsilParser::EQUAL);
    setState(417);
    antlrcpp::downCast<Section_setContext *>(_localctx)->value = expr();
    setState(418);
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
  enterRule(_localctx, 54, TsilParser::RuleIf);
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
    setState(420);
    match(TsilParser::KW_IF);
    setState(421);
    antlrcpp::downCast<IfContext *>(_localctx)->cond = operation(0);
    setState(422);
    antlrcpp::downCast<IfContext *>(_localctx)->ifok = body();
    setState(428);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::KW_ELSE) {
      setState(423);
      match(TsilParser::KW_ELSE);
      setState(426);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TsilParser::QUOTE_OPEN: {
          setState(424);
          antlrcpp::downCast<IfContext *>(_localctx)->ifnot = body();
          break;
        }

        case TsilParser::KW_IF: {
          setState(425);
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
  enterRule(_localctx, 56, TsilParser::RuleWhile);

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
    match(TsilParser::KW_WHILE);
    setState(431);
    antlrcpp::downCast<WhileContext *>(_localctx)->cond = operation(0);
    setState(432);
    body();
   
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
  enterRule(_localctx, 58, TsilParser::RuleBody);
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
    setState(434);
    match(TsilParser::QUOTE_OPEN);
    setState(438);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 219269144326375790) != 0)) {
      setState(435);
      body_element();
      setState(440);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(441);
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

TsilParser::Structure_declareContext* TsilParser::Body_elementContext::structure_declare() {
  return getRuleContext<TsilParser::Structure_declareContext>(0);
}

TsilParser::Structure_defineContext* TsilParser::Body_elementContext::structure_define() {
  return getRuleContext<TsilParser::Structure_defineContext>(0);
}

TsilParser::Diia_declareContext* TsilParser::Body_elementContext::diia_declare() {
  return getRuleContext<TsilParser::Diia_declareContext>(0);
}

TsilParser::Diia_defineContext* TsilParser::Body_elementContext::diia_define() {
  return getRuleContext<TsilParser::Diia_defineContext>(0);
}

TsilParser::Tsil_declareContext* TsilParser::Body_elementContext::tsil_declare() {
  return getRuleContext<TsilParser::Tsil_declareContext>(0);
}

TsilParser::Tsil_defineContext* TsilParser::Body_elementContext::tsil_define() {
  return getRuleContext<TsilParser::Tsil_defineContext>(0);
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

TsilParser::Section_declareContext* TsilParser::Body_elementContext::section_declare() {
  return getRuleContext<TsilParser::Section_declareContext>(0);
}

TsilParser::Section_defineContext* TsilParser::Body_elementContext::section_define() {
  return getRuleContext<TsilParser::Section_defineContext>(0);
}

TsilParser::ExprContext* TsilParser::Body_elementContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

TsilParser::IfContext* TsilParser::Body_elementContext::if_() {
  return getRuleContext<TsilParser::IfContext>(0);
}

TsilParser::WhileContext* TsilParser::Body_elementContext::while_() {
  return getRuleContext<TsilParser::WhileContext>(0);
}

TsilParser::BodyContext* TsilParser::Body_elementContext::body() {
  return getRuleContext<TsilParser::BodyContext>(0);
}

TsilParser::ReturnContext* TsilParser::Body_elementContext::return_() {
  return getRuleContext<TsilParser::ReturnContext>(0);
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
    setState(461);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(443);
      structure_declare();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(444);
      structure_define();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(445);
      diia_declare();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(446);
      diia_define();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(447);
      tsil_declare();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(448);
      tsil_define();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(449);
      set();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(450);
      section_set();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(451);
      position_set();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(452);
      synonym();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(453);
      section_declare();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(454);
      section_define();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(455);
      expr();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(456);
      if_();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(457);
      while_();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(458);
      body();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(459);
      return_();
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(460);
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
  enterRule(_localctx, 62, TsilParser::RuleReturn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(463);
    match(TsilParser::KW_RETURN);
    setState(464);
    antlrcpp::downCast<ReturnContext *>(_localctx)->value = expr();
    setState(465);
    match(TsilParser::SEMICOLON);
   
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

//----------------- Type_getContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Type_getContext::DOT() {
  return getToken(TsilParser::DOT, 0);
}

TsilParser::TypeContext* TsilParser::Type_getContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

tree::TerminalNode* TsilParser::Type_getContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::Type_getContext::Type_getContext(TypeContext *ctx) { copyFrom(ctx); }

void TsilParser::Type_getContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_get(this);
}
void TsilParser::Type_getContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_get(this);
}

std::any TsilParser::Type_getContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitType_get(this);
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
//----------------- Type_subjectContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Type_subjectContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::Type_subjectContext::Type_subjectContext(TypeContext *ctx) { copyFrom(ctx); }

void TsilParser::Type_subjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_subject(this);
}
void TsilParser::Type_subjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_subject(this);
}

std::any TsilParser::Type_subjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitType_subject(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Type_arrayContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Type_arrayContext::BRACKET_OPEN() {
  return getToken(TsilParser::BRACKET_OPEN, 0);
}

tree::TerminalNode* TsilParser::Type_arrayContext::BRACKET_CLOSE() {
  return getToken(TsilParser::BRACKET_CLOSE, 0);
}

TsilParser::TypeContext* TsilParser::Type_arrayContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

tree::TerminalNode* TsilParser::Type_arrayContext::NUMBER() {
  return getToken(TsilParser::NUMBER, 0);
}

TsilParser::Type_arrayContext::Type_arrayContext(TypeContext *ctx) { copyFrom(ctx); }

void TsilParser::Type_arrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_array(this);
}
void TsilParser::Type_arrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_array(this);
}

std::any TsilParser::Type_arrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitType_array(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Type_fn_complexContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Type_fn_complexContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
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

std::vector<TsilParser::TypeContext *> TsilParser::Type_fn_complexContext::type() {
  return getRuleContexts<TsilParser::TypeContext>();
}

TsilParser::TypeContext* TsilParser::Type_fn_complexContext::type(size_t i) {
  return getRuleContext<TsilParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Type_fn_complexContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Type_fn_complexContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}

TsilParser::Type_fn_complexContext::Type_fn_complexContext(TypeContext *ctx) { copyFrom(ctx); }

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
//----------------- Type_template_getContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Type_template_getContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::Type_template_getContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

std::vector<TsilParser::TypeContext *> TsilParser::Type_template_getContext::type() {
  return getRuleContexts<TsilParser::TypeContext>();
}

TsilParser::TypeContext* TsilParser::Type_template_getContext::type(size_t i) {
  return getRuleContext<TsilParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Type_template_getContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Type_template_getContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}

TsilParser::Type_template_getContext::Type_template_getContext(TypeContext *ctx) { copyFrom(ctx); }

void TsilParser::Type_template_getContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_template_get(this);
}
void TsilParser::Type_template_getContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_template_get(this);
}

std::any TsilParser::Type_template_getContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitType_template_get(this);
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

TsilParser::Type_fn_complex_namedContext::Type_fn_complex_namedContext(TypeContext *ctx) { copyFrom(ctx); }

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

std::vector<TsilParser::TypeContext *> TsilParser::Type_fn_simpleContext::type() {
  return getRuleContexts<TsilParser::TypeContext>();
}

TsilParser::TypeContext* TsilParser::Type_fn_simpleContext::type(size_t i) {
  return getRuleContext<TsilParser::TypeContext>(i);
}

TsilParser::Type_fn_simpleContext::Type_fn_simpleContext(TypeContext *ctx) { copyFrom(ctx); }

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
//----------------- Type_section_getContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> TsilParser::Type_section_getContext::COLON() {
  return getTokens(TsilParser::COLON);
}

tree::TerminalNode* TsilParser::Type_section_getContext::COLON(size_t i) {
  return getToken(TsilParser::COLON, i);
}

TsilParser::TypeContext* TsilParser::Type_section_getContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

tree::TerminalNode* TsilParser::Type_section_getContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::Type_section_getContext::Type_section_getContext(TypeContext *ctx) { copyFrom(ctx); }

void TsilParser::Type_section_getContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_section_get(this);
}
void TsilParser::Type_section_getContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_section_get(this);
}

std::any TsilParser::Type_section_getContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitType_section_get(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::TypeContext* TsilParser::type() {
   return type(0);
}

TsilParser::TypeContext* TsilParser::type(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TsilParser::TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, parentState);
  TsilParser::TypeContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 64;
  enterRecursionRule(_localctx, 64, TsilParser::RuleType, precedence);

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
    setState(500);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Type_nestedContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(468);
      match(TsilParser::PAREN_OPEN);
      setState(469);
      type(0);
      setState(470);
      match(TsilParser::PAREN_CLOSE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Type_subjectContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(472);
      antlrcpp::downCast<Type_subjectContext *>(_localctx)->id = match(TsilParser::ID);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Type_fn_complexContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(473);
      match(TsilParser::PAREN_OPEN);
      setState(474);
      antlrcpp::downCast<Type_fn_complexContext *>(_localctx)->param_type = type(0);
      setState(477); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(475);
        match(TsilParser::COMA);
        setState(476);
        antlrcpp::downCast<Type_fn_complexContext *>(_localctx)->param_type = type(0);
        setState(479); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TsilParser::COMA);
      setState(481);
      match(TsilParser::PAREN_CLOSE);
      setState(482);
      match(TsilParser::MINUS);
      setState(483);
      match(TsilParser::GREATER);
      setState(484);
      antlrcpp::downCast<Type_fn_complexContext *>(_localctx)->restyp = type(2);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Type_fn_complex_namedContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(486);
      match(TsilParser::PAREN_OPEN);
      setState(487);
      param();
      setState(492);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(488);
        match(TsilParser::COMA);
        setState(489);
        param();
        setState(494);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(495);
      match(TsilParser::PAREN_CLOSE);
      setState(496);
      match(TsilParser::MINUS);
      setState(497);
      match(TsilParser::GREATER);
      setState(498);
      antlrcpp::downCast<Type_fn_complex_namedContext *>(_localctx)->restyp = type(1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(531);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(529);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Type_fn_simpleContext>(_tracker.createInstance<TypeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->param_type = previousContext;
          pushNewRecursionContext(newContext, startState, RuleType);
          setState(502);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(503);
          match(TsilParser::MINUS);
          setState(504);
          match(TsilParser::GREATER);
          setState(505);
          antlrcpp::downCast<Type_fn_simpleContext *>(_localctx)->restyp = type(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Type_section_getContext>(_tracker.createInstance<TypeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleType);
          setState(506);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(507);
          match(TsilParser::COLON);
          setState(508);
          match(TsilParser::COLON);
          setState(509);
          antlrcpp::downCast<Type_section_getContext *>(_localctx)->id = match(TsilParser::ID);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Type_template_getContext>(_tracker.createInstance<TypeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleType);
          setState(510);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(511);
          match(TsilParser::LESSER);
          setState(512);
          antlrcpp::downCast<Type_template_getContext *>(_localctx)->template_type = type(0);
          setState(517);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == TsilParser::COMA) {
            setState(513);
            match(TsilParser::COMA);
            setState(514);
            antlrcpp::downCast<Type_template_getContext *>(_localctx)->template_type = type(0);
            setState(519);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(520);
          match(TsilParser::GREATER);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Type_getContext>(_tracker.createInstance<TypeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleType);
          setState(522);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(523);
          match(TsilParser::DOT);
          setState(524);
          antlrcpp::downCast<Type_getContext *>(_localctx)->id = match(TsilParser::ID);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Type_arrayContext>(_tracker.createInstance<TypeContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleType);
          setState(525);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(526);
          match(TsilParser::BRACKET_OPEN);
          setState(527);
          antlrcpp::downCast<Type_arrayContext *>(_localctx)->size = match(TsilParser::NUMBER);
          setState(528);
          match(TsilParser::BRACKET_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(533);
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
  enterRule(_localctx, 66, TsilParser::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(534);
    match(TsilParser::ID);
    setState(535);
    match(TsilParser::COLON);
    setState(536);
    type(0);
   
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
    case 3: return operationSempred(antlrcpp::downCast<OperationContext *>(context), predicateIndex);
    case 32: return typeSempred(antlrcpp::downCast<TypeContext *>(context), predicateIndex);

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

  default:
    break;
  }
  return true;
}

bool TsilParser::typeSempred(TypeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 25: return precpred(_ctx, 3);
    case 26: return precpred(_ctx, 7);
    case 27: return precpred(_ctx, 6);
    case 28: return precpred(_ctx, 5);
    case 29: return precpred(_ctx, 4);

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
