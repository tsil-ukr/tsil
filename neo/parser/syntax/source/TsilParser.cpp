
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
      "file", "program", "atom", "operation", "expr", "structure_declare", 
      "structure_define", "structure_element", "diia_declare", "diia_define", 
      "tsil_declare", "tsil_define", "synonym", "section_declare", "section_define", 
      "set", "section_set", "position_set", "if", "while", "body", "body_element", 
      "type", "param"
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
  	4,1,61,472,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,1,0,1,0,1,0,1,1,5,1,53,8,1,10,1,12,1,56,9,1,1,
  	2,1,2,1,2,1,2,1,2,1,2,3,2,64,8,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	5,2,75,8,2,10,2,12,2,78,9,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,5,2,95,8,2,10,2,12,2,98,9,2,1,2,1,2,5,2,102,8,2,10,
  	2,12,2,105,9,2,1,3,1,3,1,3,1,3,3,3,111,8,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,5,3,186,8,3,10,
  	3,12,3,189,9,3,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,5,5,199,8,5,10,5,12,5,
  	202,9,5,1,5,3,5,205,8,5,1,6,1,6,1,6,1,6,1,6,1,6,5,6,213,8,6,10,6,12,6,
  	216,9,6,1,6,3,6,219,8,6,1,6,1,6,5,6,223,8,6,10,6,12,6,226,9,6,1,6,1,6,
  	1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,5,8,240,8,8,10,8,12,8,243,9,8,
  	1,8,3,8,246,8,8,1,8,1,8,1,8,1,8,5,8,252,8,8,10,8,12,8,255,9,8,3,8,257,
  	8,8,1,8,1,8,1,8,3,8,262,8,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,271,8,9,10,
  	9,12,9,274,9,9,1,9,3,9,277,8,9,1,9,1,9,1,9,1,9,5,9,283,8,9,10,9,12,9,
  	286,9,9,3,9,288,8,9,1,9,1,9,1,9,3,9,293,8,9,1,9,1,9,1,10,1,10,1,10,3,
  	10,300,8,10,1,10,1,10,1,10,3,10,305,8,10,1,10,1,10,1,11,1,11,1,11,3,11,
  	312,8,11,1,11,1,11,1,11,3,11,317,8,11,1,11,1,11,1,11,1,11,1,12,1,12,1,
  	12,1,12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,17,1,17,1,
  	17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,18,3,18,365,8,
  	18,3,18,367,8,18,1,19,1,19,1,19,1,19,1,20,1,20,5,20,375,8,20,10,20,12,
  	20,378,9,20,1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,
  	21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,3,21,399,8,21,1,22,1,22,1,22,1,
  	22,1,22,1,22,1,22,1,22,1,22,1,22,4,22,411,8,22,11,22,12,22,412,1,22,1,
  	22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,5,22,424,8,22,10,22,12,22,427,9,
  	22,1,22,1,22,1,22,1,22,1,22,3,22,434,8,22,1,22,1,22,1,22,1,22,1,22,1,
  	22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,5,22,449,8,22,10,22,12,22,452,9,
  	22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,5,22,463,8,22,10,22,12,
  	22,466,9,22,1,23,1,23,1,23,1,23,1,23,0,3,4,6,44,24,0,2,4,6,8,10,12,14,
  	16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,0,1,1,0,16,18,529,0,48,
  	1,0,0,0,2,54,1,0,0,0,4,63,1,0,0,0,6,110,1,0,0,0,8,190,1,0,0,0,10,192,
  	1,0,0,0,12,206,1,0,0,0,14,229,1,0,0,0,16,232,1,0,0,0,18,263,1,0,0,0,20,
  	299,1,0,0,0,22,311,1,0,0,0,24,322,1,0,0,0,26,328,1,0,0,0,28,331,1,0,0,
  	0,30,335,1,0,0,0,32,342,1,0,0,0,34,350,1,0,0,0,36,358,1,0,0,0,38,368,
  	1,0,0,0,40,372,1,0,0,0,42,398,1,0,0,0,44,433,1,0,0,0,46,467,1,0,0,0,48,
  	49,3,2,1,0,49,50,5,0,0,1,50,1,1,0,0,0,51,53,3,42,21,0,52,51,1,0,0,0,53,
  	56,1,0,0,0,54,52,1,0,0,0,54,55,1,0,0,0,55,3,1,0,0,0,56,54,1,0,0,0,57,
  	58,6,2,-1,0,58,59,5,37,0,0,59,60,3,8,4,0,60,61,5,38,0,0,61,64,1,0,0,0,
  	62,64,5,56,0,0,63,57,1,0,0,0,63,62,1,0,0,0,64,103,1,0,0,0,65,66,10,5,
  	0,0,66,67,5,42,0,0,67,68,5,42,0,0,68,102,5,56,0,0,69,70,10,4,0,0,70,71,
  	5,27,0,0,71,76,3,44,22,0,72,73,5,47,0,0,73,75,3,44,22,0,74,72,1,0,0,0,
  	75,78,1,0,0,0,76,74,1,0,0,0,76,77,1,0,0,0,77,79,1,0,0,0,78,76,1,0,0,0,
  	79,80,5,26,0,0,80,102,1,0,0,0,81,82,10,3,0,0,82,83,5,28,0,0,83,102,5,
  	56,0,0,84,85,10,2,0,0,85,86,5,39,0,0,86,87,3,8,4,0,87,88,5,40,0,0,88,
  	102,1,0,0,0,89,90,10,1,0,0,90,91,5,37,0,0,91,96,3,8,4,0,92,93,5,47,0,
  	0,93,95,3,8,4,0,94,92,1,0,0,0,95,98,1,0,0,0,96,94,1,0,0,0,96,97,1,0,0,
  	0,97,99,1,0,0,0,98,96,1,0,0,0,99,100,5,38,0,0,100,102,1,0,0,0,101,65,
  	1,0,0,0,101,69,1,0,0,0,101,81,1,0,0,0,101,84,1,0,0,0,101,89,1,0,0,0,102,
  	105,1,0,0,0,103,101,1,0,0,0,103,104,1,0,0,0,104,5,1,0,0,0,105,103,1,0,
  	0,0,106,107,6,3,-1,0,107,111,5,51,0,0,108,111,5,57,0,0,109,111,3,4,2,
  	0,110,106,1,0,0,0,110,108,1,0,0,0,110,109,1,0,0,0,111,187,1,0,0,0,112,
  	113,10,20,0,0,113,114,5,31,0,0,114,186,3,6,3,21,115,116,10,19,0,0,116,
  	117,5,32,0,0,117,186,3,6,3,20,118,119,10,18,0,0,119,120,5,33,0,0,120,
  	186,3,6,3,19,121,122,10,17,0,0,122,123,5,29,0,0,123,186,3,6,3,18,124,
  	125,10,16,0,0,125,126,5,30,0,0,126,186,3,6,3,17,127,128,10,15,0,0,128,
  	129,5,27,0,0,129,130,5,27,0,0,130,186,3,6,3,16,131,132,10,14,0,0,132,
  	133,5,26,0,0,133,134,5,26,0,0,134,186,3,6,3,15,135,136,10,13,0,0,136,
  	137,5,26,0,0,137,138,5,26,0,0,138,139,5,26,0,0,139,186,3,6,3,14,140,141,
  	10,12,0,0,141,142,5,27,0,0,142,186,3,6,3,13,143,144,10,11,0,0,144,145,
  	5,27,0,0,145,146,5,25,0,0,146,186,3,6,3,12,147,148,10,10,0,0,148,149,
  	5,26,0,0,149,186,3,6,3,11,150,151,10,9,0,0,151,152,5,26,0,0,152,153,5,
  	25,0,0,153,186,3,6,3,10,154,155,10,8,0,0,155,156,5,25,0,0,156,157,5,25,
  	0,0,157,186,3,6,3,9,158,159,10,7,0,0,159,160,5,46,0,0,160,161,5,25,0,
  	0,161,186,3,6,3,8,162,163,10,6,0,0,163,164,5,35,0,0,164,186,3,6,3,7,165,
  	166,10,5,0,0,166,167,5,34,0,0,167,186,3,6,3,6,168,169,10,4,0,0,169,170,
  	5,36,0,0,170,186,3,6,3,5,171,172,10,3,0,0,172,173,5,35,0,0,173,174,5,
  	35,0,0,174,186,3,6,3,4,175,176,10,2,0,0,176,177,5,36,0,0,177,178,5,36,
  	0,0,178,186,3,6,3,3,179,180,10,1,0,0,180,181,5,41,0,0,181,182,3,6,3,0,
  	182,183,5,42,0,0,183,184,3,6,3,2,184,186,1,0,0,0,185,112,1,0,0,0,185,
  	115,1,0,0,0,185,118,1,0,0,0,185,121,1,0,0,0,185,124,1,0,0,0,185,127,1,
  	0,0,0,185,131,1,0,0,0,185,135,1,0,0,0,185,140,1,0,0,0,185,143,1,0,0,0,
  	185,147,1,0,0,0,185,150,1,0,0,0,185,154,1,0,0,0,185,158,1,0,0,0,185,162,
  	1,0,0,0,185,165,1,0,0,0,185,168,1,0,0,0,185,171,1,0,0,0,185,175,1,0,0,
  	0,185,179,1,0,0,0,186,189,1,0,0,0,187,185,1,0,0,0,187,188,1,0,0,0,188,
  	7,1,0,0,0,189,187,1,0,0,0,190,191,3,6,3,0,191,9,1,0,0,0,192,193,5,8,0,
  	0,193,204,5,56,0,0,194,195,5,27,0,0,195,200,5,56,0,0,196,197,5,47,0,0,
  	197,199,5,56,0,0,198,196,1,0,0,0,199,202,1,0,0,0,200,198,1,0,0,0,200,
  	201,1,0,0,0,201,203,1,0,0,0,202,200,1,0,0,0,203,205,5,26,0,0,204,194,
  	1,0,0,0,204,205,1,0,0,0,205,11,1,0,0,0,206,207,5,8,0,0,207,218,5,56,0,
  	0,208,209,5,27,0,0,209,214,5,56,0,0,210,211,5,47,0,0,211,213,5,56,0,0,
  	212,210,1,0,0,0,213,216,1,0,0,0,214,212,1,0,0,0,214,215,1,0,0,0,215,217,
  	1,0,0,0,216,214,1,0,0,0,217,219,5,26,0,0,218,208,1,0,0,0,218,219,1,0,
  	0,0,219,220,1,0,0,0,220,224,5,49,0,0,221,223,3,14,7,0,222,221,1,0,0,0,
  	223,226,1,0,0,0,224,222,1,0,0,0,224,225,1,0,0,0,225,227,1,0,0,0,226,224,
  	1,0,0,0,227,228,5,50,0,0,228,13,1,0,0,0,229,230,3,46,23,0,230,231,5,48,
  	0,0,231,15,1,0,0,0,232,233,7,0,0,0,233,234,5,2,0,0,234,245,5,56,0,0,235,
  	236,5,27,0,0,236,241,5,56,0,0,237,238,5,47,0,0,238,240,5,56,0,0,239,237,
  	1,0,0,0,240,243,1,0,0,0,241,239,1,0,0,0,241,242,1,0,0,0,242,244,1,0,0,
  	0,243,241,1,0,0,0,244,246,5,26,0,0,245,235,1,0,0,0,245,246,1,0,0,0,246,
  	247,1,0,0,0,247,256,5,37,0,0,248,253,3,46,23,0,249,250,5,47,0,0,250,252,
  	3,46,23,0,251,249,1,0,0,0,252,255,1,0,0,0,253,251,1,0,0,0,253,254,1,0,
  	0,0,254,257,1,0,0,0,255,253,1,0,0,0,256,248,1,0,0,0,256,257,1,0,0,0,257,
  	258,1,0,0,0,258,261,5,38,0,0,259,260,5,42,0,0,260,262,3,44,22,0,261,259,
  	1,0,0,0,261,262,1,0,0,0,262,17,1,0,0,0,263,264,7,0,0,0,264,265,5,2,0,
  	0,265,276,5,56,0,0,266,267,5,27,0,0,267,272,5,56,0,0,268,269,5,47,0,0,
  	269,271,5,56,0,0,270,268,1,0,0,0,271,274,1,0,0,0,272,270,1,0,0,0,272,
  	273,1,0,0,0,273,275,1,0,0,0,274,272,1,0,0,0,275,277,5,26,0,0,276,266,
  	1,0,0,0,276,277,1,0,0,0,277,278,1,0,0,0,278,287,5,37,0,0,279,284,3,46,
  	23,0,280,281,5,47,0,0,281,283,3,46,23,0,282,280,1,0,0,0,283,286,1,0,0,
  	0,284,282,1,0,0,0,284,285,1,0,0,0,285,288,1,0,0,0,286,284,1,0,0,0,287,
  	279,1,0,0,0,287,288,1,0,0,0,288,289,1,0,0,0,289,292,5,38,0,0,290,291,
  	5,42,0,0,291,293,3,44,22,0,292,290,1,0,0,0,292,293,1,0,0,0,293,294,1,
  	0,0,0,294,295,3,40,20,0,295,19,1,0,0,0,296,300,5,22,0,0,297,300,5,23,
  	0,0,298,300,5,1,0,0,299,296,1,0,0,0,299,297,1,0,0,0,299,298,1,0,0,0,300,
  	301,1,0,0,0,301,304,5,56,0,0,302,303,5,42,0,0,303,305,3,44,22,0,304,302,
  	1,0,0,0,304,305,1,0,0,0,305,306,1,0,0,0,306,307,5,48,0,0,307,21,1,0,0,
  	0,308,312,5,22,0,0,309,312,5,23,0,0,310,312,5,1,0,0,311,308,1,0,0,0,311,
  	309,1,0,0,0,311,310,1,0,0,0,312,313,1,0,0,0,313,316,5,56,0,0,314,315,
  	5,42,0,0,315,317,3,44,22,0,316,314,1,0,0,0,316,317,1,0,0,0,317,318,1,
  	0,0,0,318,319,5,25,0,0,319,320,3,8,4,0,320,321,5,48,0,0,321,23,1,0,0,
  	0,322,323,5,24,0,0,323,324,5,56,0,0,324,325,5,25,0,0,325,326,3,8,4,0,
  	326,327,5,48,0,0,327,25,1,0,0,0,328,329,5,11,0,0,329,330,5,56,0,0,330,
  	27,1,0,0,0,331,332,5,11,0,0,332,333,5,56,0,0,333,334,3,40,20,0,334,29,
  	1,0,0,0,335,336,3,4,2,0,336,337,5,28,0,0,337,338,5,56,0,0,338,339,5,25,
  	0,0,339,340,3,8,4,0,340,341,5,48,0,0,341,31,1,0,0,0,342,343,3,4,2,0,343,
  	344,5,42,0,0,344,345,5,42,0,0,345,346,5,56,0,0,346,347,5,25,0,0,347,348,
  	3,8,4,0,348,349,5,48,0,0,349,33,1,0,0,0,350,351,3,4,2,0,351,352,5,39,
  	0,0,352,353,3,8,4,0,353,354,5,40,0,0,354,355,5,25,0,0,355,356,3,8,4,0,
  	356,357,5,48,0,0,357,35,1,0,0,0,358,359,5,3,0,0,359,360,3,6,3,0,360,366,
  	3,40,20,0,361,364,5,4,0,0,362,365,3,40,20,0,363,365,3,36,18,0,364,362,
  	1,0,0,0,364,363,1,0,0,0,365,367,1,0,0,0,366,361,1,0,0,0,366,367,1,0,0,
  	0,367,37,1,0,0,0,368,369,5,5,0,0,369,370,3,6,3,0,370,371,3,40,20,0,371,
  	39,1,0,0,0,372,376,5,49,0,0,373,375,3,42,21,0,374,373,1,0,0,0,375,378,
  	1,0,0,0,376,374,1,0,0,0,376,377,1,0,0,0,377,379,1,0,0,0,378,376,1,0,0,
  	0,379,380,5,50,0,0,380,41,1,0,0,0,381,399,3,10,5,0,382,399,3,12,6,0,383,
  	399,3,16,8,0,384,399,3,18,9,0,385,399,3,20,10,0,386,399,3,22,11,0,387,
  	399,3,30,15,0,388,399,3,32,16,0,389,399,3,34,17,0,390,399,3,24,12,0,391,
  	399,3,26,13,0,392,399,3,28,14,0,393,399,3,8,4,0,394,399,3,36,18,0,395,
  	399,3,38,19,0,396,399,3,40,20,0,397,399,5,48,0,0,398,381,1,0,0,0,398,
  	382,1,0,0,0,398,383,1,0,0,0,398,384,1,0,0,0,398,385,1,0,0,0,398,386,1,
  	0,0,0,398,387,1,0,0,0,398,388,1,0,0,0,398,389,1,0,0,0,398,390,1,0,0,0,
  	398,391,1,0,0,0,398,392,1,0,0,0,398,393,1,0,0,0,398,394,1,0,0,0,398,395,
  	1,0,0,0,398,396,1,0,0,0,398,397,1,0,0,0,399,43,1,0,0,0,400,401,6,22,-1,
  	0,401,402,5,37,0,0,402,403,3,44,22,0,403,404,5,38,0,0,404,434,1,0,0,0,
  	405,434,5,56,0,0,406,407,5,37,0,0,407,410,3,44,22,0,408,409,5,47,0,0,
  	409,411,3,44,22,0,410,408,1,0,0,0,411,412,1,0,0,0,412,410,1,0,0,0,412,
  	413,1,0,0,0,413,414,1,0,0,0,414,415,5,38,0,0,415,416,5,30,0,0,416,417,
  	5,26,0,0,417,418,3,44,22,2,418,434,1,0,0,0,419,420,5,37,0,0,420,425,3,
  	46,23,0,421,422,5,47,0,0,422,424,3,46,23,0,423,421,1,0,0,0,424,427,1,
  	0,0,0,425,423,1,0,0,0,425,426,1,0,0,0,426,428,1,0,0,0,427,425,1,0,0,0,
  	428,429,5,38,0,0,429,430,5,30,0,0,430,431,5,26,0,0,431,432,3,44,22,1,
  	432,434,1,0,0,0,433,400,1,0,0,0,433,405,1,0,0,0,433,406,1,0,0,0,433,419,
  	1,0,0,0,434,464,1,0,0,0,435,436,10,3,0,0,436,437,5,30,0,0,437,438,5,26,
  	0,0,438,463,3,44,22,4,439,440,10,7,0,0,440,441,5,42,0,0,441,442,5,42,
  	0,0,442,463,5,56,0,0,443,444,10,6,0,0,444,445,5,27,0,0,445,450,3,44,22,
  	0,446,447,5,47,0,0,447,449,3,44,22,0,448,446,1,0,0,0,449,452,1,0,0,0,
  	450,448,1,0,0,0,450,451,1,0,0,0,451,453,1,0,0,0,452,450,1,0,0,0,453,454,
  	5,26,0,0,454,463,1,0,0,0,455,456,10,5,0,0,456,457,5,28,0,0,457,463,5,
  	56,0,0,458,459,10,4,0,0,459,460,5,39,0,0,460,461,5,51,0,0,461,463,5,40,
  	0,0,462,435,1,0,0,0,462,439,1,0,0,0,462,443,1,0,0,0,462,455,1,0,0,0,462,
  	458,1,0,0,0,463,466,1,0,0,0,464,462,1,0,0,0,464,465,1,0,0,0,465,45,1,
  	0,0,0,466,464,1,0,0,0,467,468,5,56,0,0,468,469,5,42,0,0,469,470,3,44,
  	22,0,470,47,1,0,0,0,38,54,63,76,96,101,103,110,185,187,200,204,214,218,
  	224,241,245,253,256,261,272,276,284,287,292,299,304,311,316,364,366,376,
  	398,412,425,433,450,462,464
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
    setState(48);
    antlrcpp::downCast<FileContext *>(_localctx)->f_program = program();
    setState(49);
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
    setState(54);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 219269144326375722) != 0)) {
      setState(51);
      body_element();
      setState(56);
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

TsilParser::AtomContext* TsilParser::Atom_template_getContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

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

TsilParser::AtomContext* TsilParser::Atom_getContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

tree::TerminalNode* TsilParser::Atom_getContext::DOT() {
  return getToken(TsilParser::DOT, 0);
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

TsilParser::AtomContext* TsilParser::Atom_section_getContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

std::vector<tree::TerminalNode *> TsilParser::Atom_section_getContext::COLON() {
  return getTokens(TsilParser::COLON);
}

tree::TerminalNode* TsilParser::Atom_section_getContext::COLON(size_t i) {
  return getToken(TsilParser::COLON, i);
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

TsilParser::AtomContext* TsilParser::Atom_position_getContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

tree::TerminalNode* TsilParser::Atom_position_getContext::BRACKET_OPEN() {
  return getToken(TsilParser::BRACKET_OPEN, 0);
}

TsilParser::ExprContext* TsilParser::Atom_position_getContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

tree::TerminalNode* TsilParser::Atom_position_getContext::BRACKET_CLOSE() {
  return getToken(TsilParser::BRACKET_CLOSE, 0);
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

TsilParser::AtomContext* TsilParser::Atom_callContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

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
    setState(63);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::PAREN_OPEN: {
        _localctx = _tracker.createInstance<Atom_nestedContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(58);
        match(TsilParser::PAREN_OPEN);
        setState(59);
        expr();
        setState(60);
        match(TsilParser::PAREN_CLOSE);
        break;
      }

      case TsilParser::ID: {
        _localctx = _tracker.createInstance<Atom_subjectContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(62);
        match(TsilParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(103);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(101);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Atom_section_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(65);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(66);
          match(TsilParser::COLON);
          setState(67);
          match(TsilParser::COLON);
          setState(68);
          match(TsilParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Atom_template_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(69);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(70);
          match(TsilParser::LESSER);
          setState(71);
          type(0);
          setState(76);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == TsilParser::COMA) {
            setState(72);
            match(TsilParser::COMA);
            setState(73);
            type(0);
            setState(78);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(79);
          match(TsilParser::GREATER);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Atom_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(81);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(82);
          match(TsilParser::DOT);
          setState(83);
          match(TsilParser::ID);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Atom_position_getContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(84);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(85);
          match(TsilParser::BRACKET_OPEN);
          setState(86);
          expr();
          setState(87);
          match(TsilParser::BRACKET_CLOSE);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Atom_callContext>(_tracker.createInstance<AtomContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleAtom);
          setState(89);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(90);
          match(TsilParser::PAREN_OPEN);
          setState(91);
          expr();
          setState(96);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == TsilParser::COMA) {
            setState(92);
            match(TsilParser::COMA);
            setState(93);
            expr();
            setState(98);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(99);
          match(TsilParser::PAREN_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(105);
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

tree::TerminalNode* TsilParser::Operation_gteContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

tree::TerminalNode* TsilParser::Operation_gteContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
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

tree::TerminalNode* TsilParser::Operation_neqContext::EXCLAMATION() {
  return getToken(TsilParser::EXCLAMATION, 0);
}

tree::TerminalNode* TsilParser::Operation_neqContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
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

tree::TerminalNode* TsilParser::Operation_lteContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::Operation_lteContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
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

std::vector<tree::TerminalNode *> TsilParser::Operation_eqContext::EQUAL() {
  return getTokens(TsilParser::EQUAL);
}

tree::TerminalNode* TsilParser::Operation_eqContext::EQUAL(size_t i) {
  return getToken(TsilParser::EQUAL, i);
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

std::vector<tree::TerminalNode *> TsilParser::Operation_landContext::AND() {
  return getTokens(TsilParser::AND);
}

tree::TerminalNode* TsilParser::Operation_landContext::AND(size_t i) {
  return getToken(TsilParser::AND, i);
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

std::vector<tree::TerminalNode *> TsilParser::Operation_lorContext::OR() {
  return getTokens(TsilParser::OR);
}

tree::TerminalNode* TsilParser::Operation_lorContext::OR(size_t i) {
  return getToken(TsilParser::OR, i);
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

std::vector<TsilParser::OperationContext *> TsilParser::Operation_ternaryContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::Operation_ternaryContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

tree::TerminalNode* TsilParser::Operation_ternaryContext::QUESTION() {
  return getToken(TsilParser::QUESTION, 0);
}

tree::TerminalNode* TsilParser::Operation_ternaryContext::COLON() {
  return getToken(TsilParser::COLON, 0);
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

std::vector<tree::TerminalNode *> TsilParser::Operation_urshiftContext::GREATER() {
  return getTokens(TsilParser::GREATER);
}

tree::TerminalNode* TsilParser::Operation_urshiftContext::GREATER(size_t i) {
  return getToken(TsilParser::GREATER, i);
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

std::vector<tree::TerminalNode *> TsilParser::Operation_rshiftContext::GREATER() {
  return getTokens(TsilParser::GREATER);
}

tree::TerminalNode* TsilParser::Operation_rshiftContext::GREATER(size_t i) {
  return getToken(TsilParser::GREATER, i);
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

std::vector<tree::TerminalNode *> TsilParser::Operation_lshiftContext::LESSER() {
  return getTokens(TsilParser::LESSER);
}

tree::TerminalNode* TsilParser::Operation_lshiftContext::LESSER(size_t i) {
  return getToken(TsilParser::LESSER, i);
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
    setState(110);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::NUMBER: {
        _localctx = _tracker.createInstance<Operation_numberContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(107);
        match(TsilParser::NUMBER);
        break;
      }

      case TsilParser::STRING: {
        _localctx = _tracker.createInstance<Operation_stringContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(108);
        match(TsilParser::STRING);
        break;
      }

      case TsilParser::PAREN_OPEN:
      case TsilParser::ID: {
        _localctx = _tracker.createInstance<Operation_atomContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(109);
        atom(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(187);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(185);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Operation_mulContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(112);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(113);
          match(TsilParser::MULTIPLY);
          setState(114);
          operation(21);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Operation_divContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(115);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(116);
          match(TsilParser::DIVIDE);
          setState(117);
          operation(20);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Operation_modContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(118);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(119);
          match(TsilParser::MOD);
          setState(120);
          operation(19);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Operation_addContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(121);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(122);
          match(TsilParser::PLUS);
          setState(123);
          operation(18);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Operation_subContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(124);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(125);
          match(TsilParser::MINUS);
          setState(126);
          operation(17);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<Operation_lshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(127);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(128);
          match(TsilParser::LESSER);
          setState(129);
          match(TsilParser::LESSER);
          setState(130);
          operation(16);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<Operation_rshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(131);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(132);
          match(TsilParser::GREATER);
          setState(133);
          match(TsilParser::GREATER);
          setState(134);
          operation(15);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<Operation_urshiftContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(135);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(136);
          match(TsilParser::GREATER);
          setState(137);
          match(TsilParser::GREATER);
          setState(138);
          match(TsilParser::GREATER);
          setState(139);
          operation(14);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<Operation_ltContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(140);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(141);
          match(TsilParser::LESSER);
          setState(142);
          operation(13);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<Operation_lteContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(143);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(144);
          match(TsilParser::LESSER);
          setState(145);
          match(TsilParser::EQUAL);
          setState(146);
          operation(12);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<Operation_gtContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(147);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(148);
          match(TsilParser::GREATER);
          setState(149);
          operation(11);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<Operation_gteContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(150);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(151);
          match(TsilParser::GREATER);
          setState(152);
          match(TsilParser::EQUAL);
          setState(153);
          operation(10);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<Operation_eqContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(154);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(155);
          match(TsilParser::EQUAL);
          setState(156);
          match(TsilParser::EQUAL);
          setState(157);
          operation(9);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<Operation_neqContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(158);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(159);
          match(TsilParser::EXCLAMATION);
          setState(160);
          match(TsilParser::EQUAL);
          setState(161);
          operation(8);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<Operation_andContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(162);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(163);
          match(TsilParser::AND);
          setState(164);
          operation(7);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<Operation_xorContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(165);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(166);
          match(TsilParser::POWER);
          setState(167);
          operation(6);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<Operation_orContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(168);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(169);
          match(TsilParser::OR);
          setState(170);
          operation(5);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<Operation_landContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(171);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(172);
          match(TsilParser::AND);
          setState(173);
          match(TsilParser::AND);
          setState(174);
          operation(4);
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<Operation_lorContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(175);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(176);
          match(TsilParser::OR);
          setState(177);
          match(TsilParser::OR);
          setState(178);
          operation(3);
          break;
        }

        case 20: {
          auto newContext = _tracker.createInstance<Operation_ternaryContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(179);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(180);
          match(TsilParser::QUESTION);
          setState(181);
          operation(0);
          setState(182);
          match(TsilParser::COLON);
          setState(183);
          operation(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(189);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
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
  enterRule(_localctx, 8, TsilParser::RuleExpr);

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
    setState(190);
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
  enterRule(_localctx, 10, TsilParser::RuleStructure_declare);
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
    setState(192);
    match(TsilParser::KW_STRUCT);
    setState(193);
    match(TsilParser::ID);
    setState(204);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(194);
      match(TsilParser::LESSER);
      setState(195);
      match(TsilParser::ID);
      setState(200);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(196);
        match(TsilParser::COMA);
        setState(197);
        match(TsilParser::ID);
        setState(202);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(203);
      match(TsilParser::GREATER);
    }
   
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

std::vector<tree::TerminalNode *> TsilParser::Structure_defineContext::ID() {
  return getTokens(TsilParser::ID);
}

tree::TerminalNode* TsilParser::Structure_defineContext::ID(size_t i) {
  return getToken(TsilParser::ID, i);
}

tree::TerminalNode* TsilParser::Structure_defineContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::Structure_defineContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
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
  enterRule(_localctx, 12, TsilParser::RuleStructure_define);
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
    setState(206);
    match(TsilParser::KW_STRUCT);
    setState(207);
    match(TsilParser::ID);
    setState(218);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(208);
      match(TsilParser::LESSER);
      setState(209);
      match(TsilParser::ID);
      setState(214);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(210);
        match(TsilParser::COMA);
        setState(211);
        match(TsilParser::ID);
        setState(216);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(217);
      match(TsilParser::GREATER);
    }
    setState(220);
    match(TsilParser::QUOTE_OPEN);
    setState(224);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TsilParser::ID) {
      setState(221);
      structure_element();
      setState(226);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(227);
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
  enterRule(_localctx, 14, TsilParser::RuleStructure_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    param();
    setState(230);
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

std::vector<tree::TerminalNode *> TsilParser::Diia_declareContext::ID() {
  return getTokens(TsilParser::ID);
}

tree::TerminalNode* TsilParser::Diia_declareContext::ID(size_t i) {
  return getToken(TsilParser::ID, i);
}

tree::TerminalNode* TsilParser::Diia_declareContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

tree::TerminalNode* TsilParser::Diia_declareContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
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
  enterRule(_localctx, 16, TsilParser::RuleDiia_declare);
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
    setState(232);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 458752) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(233);
    match(TsilParser::KW_DIIA);
    setState(234);
    match(TsilParser::ID);
    setState(245);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(235);
      match(TsilParser::LESSER);
      setState(236);
      match(TsilParser::ID);
      setState(241);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(237);
        match(TsilParser::COMA);
        setState(238);
        match(TsilParser::ID);
        setState(243);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(244);
      match(TsilParser::GREATER);
    }
    setState(247);
    match(TsilParser::PAREN_OPEN);
    setState(256);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(248);
      param();
      setState(253);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(249);
        match(TsilParser::COMA);
        setState(250);
        param();
        setState(255);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(258);
    match(TsilParser::PAREN_CLOSE);
    setState(261);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(259);
      match(TsilParser::COLON);
      setState(260);
      type(0);
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

std::vector<tree::TerminalNode *> TsilParser::Diia_defineContext::ID() {
  return getTokens(TsilParser::ID);
}

tree::TerminalNode* TsilParser::Diia_defineContext::ID(size_t i) {
  return getToken(TsilParser::ID, i);
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

tree::TerminalNode* TsilParser::Diia_defineContext::KW_PUBLIC() {
  return getToken(TsilParser::KW_PUBLIC, 0);
}

tree::TerminalNode* TsilParser::Diia_defineContext::KW_LOCAL() {
  return getToken(TsilParser::KW_LOCAL, 0);
}

tree::TerminalNode* TsilParser::Diia_defineContext::KW_PRIVATE() {
  return getToken(TsilParser::KW_PRIVATE, 0);
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
  enterRule(_localctx, 18, TsilParser::RuleDiia_define);
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
    setState(263);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 458752) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(264);
    match(TsilParser::KW_DIIA);
    setState(265);
    match(TsilParser::ID);
    setState(276);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(266);
      match(TsilParser::LESSER);
      setState(267);
      match(TsilParser::ID);
      setState(272);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(268);
        match(TsilParser::COMA);
        setState(269);
        match(TsilParser::ID);
        setState(274);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(275);
      match(TsilParser::GREATER);
    }
    setState(278);
    match(TsilParser::PAREN_OPEN);
    setState(287);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(279);
      param();
      setState(284);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(280);
        match(TsilParser::COMA);
        setState(281);
        param();
        setState(286);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(289);
    match(TsilParser::PAREN_CLOSE);
    setState(292);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(290);
      match(TsilParser::COLON);
      setState(291);
      type(0);
    }
    setState(294);
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

tree::TerminalNode* TsilParser::Tsil_declareContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::Tsil_declareContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
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
  enterRule(_localctx, 20, TsilParser::RuleTsil_declare);
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
    setState(299);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_VAR: {
        setState(296);
        antlrcpp::downCast<Tsil_declareContext *>(_localctx)->td_var = match(TsilParser::KW_VAR);
        break;
      }

      case TsilParser::KW_IMMUT: {
        setState(297);
        antlrcpp::downCast<Tsil_declareContext *>(_localctx)->td_immut = match(TsilParser::KW_IMMUT);
        break;
      }

      case TsilParser::KW_TSIL: {
        setState(298);
        antlrcpp::downCast<Tsil_declareContext *>(_localctx)->td_const = match(TsilParser::KW_TSIL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(301);
    match(TsilParser::ID);
    setState(304);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(302);
      match(TsilParser::COLON);
      setState(303);
      type(0);
    }
    setState(306);
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

tree::TerminalNode* TsilParser::Tsil_defineContext::ID() {
  return getToken(TsilParser::ID, 0);
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
  enterRule(_localctx, 22, TsilParser::RuleTsil_define);
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
    setState(311);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_VAR: {
        setState(308);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_var = match(TsilParser::KW_VAR);
        break;
      }

      case TsilParser::KW_IMMUT: {
        setState(309);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_immut = match(TsilParser::KW_IMMUT);
        break;
      }

      case TsilParser::KW_TSIL: {
        setState(310);
        antlrcpp::downCast<Tsil_defineContext *>(_localctx)->td_const = match(TsilParser::KW_TSIL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(313);
    match(TsilParser::ID);
    setState(316);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(314);
      match(TsilParser::COLON);
      setState(315);
      type(0);
    }
    setState(318);
    match(TsilParser::EQUAL);
    setState(319);
    expr();
    setState(320);
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

tree::TerminalNode* TsilParser::SynonymContext::ID() {
  return getToken(TsilParser::ID, 0);
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
  enterRule(_localctx, 24, TsilParser::RuleSynonym);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(322);
    match(TsilParser::KW_SYNONYM);
    setState(323);
    match(TsilParser::ID);
    setState(324);
    match(TsilParser::EQUAL);
    setState(325);
    expr();
    setState(326);
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
  enterRule(_localctx, 26, TsilParser::RuleSection_declare);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(328);
    match(TsilParser::KW_SECTION);
    setState(329);
    match(TsilParser::ID);
   
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
  enterRule(_localctx, 28, TsilParser::RuleSection_define);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(331);
    match(TsilParser::KW_SECTION);
    setState(332);
    match(TsilParser::ID);
    setState(333);
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

TsilParser::AtomContext* TsilParser::SetContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

tree::TerminalNode* TsilParser::SetContext::DOT() {
  return getToken(TsilParser::DOT, 0);
}

tree::TerminalNode* TsilParser::SetContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::SetContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}

TsilParser::ExprContext* TsilParser::SetContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

tree::TerminalNode* TsilParser::SetContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
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
  enterRule(_localctx, 30, TsilParser::RuleSet);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
    atom(0);
    setState(336);
    match(TsilParser::DOT);
    setState(337);
    match(TsilParser::ID);
    setState(338);
    match(TsilParser::EQUAL);
    setState(339);
    expr();
    setState(340);
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

TsilParser::AtomContext* TsilParser::Section_setContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

std::vector<tree::TerminalNode *> TsilParser::Section_setContext::COLON() {
  return getTokens(TsilParser::COLON);
}

tree::TerminalNode* TsilParser::Section_setContext::COLON(size_t i) {
  return getToken(TsilParser::COLON, i);
}

tree::TerminalNode* TsilParser::Section_setContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::Section_setContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}

TsilParser::ExprContext* TsilParser::Section_setContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

tree::TerminalNode* TsilParser::Section_setContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
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
  enterRule(_localctx, 32, TsilParser::RuleSection_set);

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
    atom(0);
    setState(343);
    match(TsilParser::COLON);
    setState(344);
    match(TsilParser::COLON);
    setState(345);
    match(TsilParser::ID);
    setState(346);
    match(TsilParser::EQUAL);
    setState(347);
    expr();
    setState(348);
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

TsilParser::AtomContext* TsilParser::Position_setContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

tree::TerminalNode* TsilParser::Position_setContext::BRACKET_OPEN() {
  return getToken(TsilParser::BRACKET_OPEN, 0);
}

std::vector<TsilParser::ExprContext *> TsilParser::Position_setContext::expr() {
  return getRuleContexts<TsilParser::ExprContext>();
}

TsilParser::ExprContext* TsilParser::Position_setContext::expr(size_t i) {
  return getRuleContext<TsilParser::ExprContext>(i);
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
  enterRule(_localctx, 34, TsilParser::RulePosition_set);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    atom(0);
    setState(351);
    match(TsilParser::BRACKET_OPEN);
    setState(352);
    expr();
    setState(353);
    match(TsilParser::BRACKET_CLOSE);
    setState(354);
    match(TsilParser::EQUAL);
    setState(355);
    expr();
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
    setState(358);
    match(TsilParser::KW_IF);
    setState(359);
    operation(0);
    setState(360);
    body();
    setState(366);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::KW_ELSE) {
      setState(361);
      match(TsilParser::KW_ELSE);
      setState(364);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TsilParser::QUOTE_OPEN: {
          setState(362);
          body();
          break;
        }

        case TsilParser::KW_IF: {
          setState(363);
          if_();
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

TsilParser::OperationContext* TsilParser::WhileContext::operation() {
  return getRuleContext<TsilParser::OperationContext>(0);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(368);
    match(TsilParser::KW_WHILE);
    setState(369);
    operation(0);
    setState(370);
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
  enterRule(_localctx, 40, TsilParser::RuleBody);
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
    setState(372);
    match(TsilParser::QUOTE_OPEN);
    setState(376);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 219269144326375722) != 0)) {
      setState(373);
      body_element();
      setState(378);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(379);
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
  enterRule(_localctx, 42, TsilParser::RuleBody_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(398);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(381);
      structure_declare();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(382);
      structure_define();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(383);
      diia_declare();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(384);
      diia_define();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(385);
      tsil_declare();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(386);
      tsil_define();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(387);
      set();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(388);
      section_set();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(389);
      position_set();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(390);
      synonym();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(391);
      section_declare();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(392);
      section_define();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(393);
      expr();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(394);
      if_();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(395);
      while_();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(396);
      body();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(397);
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

TsilParser::TypeContext* TsilParser::Type_getContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

tree::TerminalNode* TsilParser::Type_getContext::DOT() {
  return getToken(TsilParser::DOT, 0);
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

TsilParser::TypeContext* TsilParser::Type_arrayContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

tree::TerminalNode* TsilParser::Type_arrayContext::BRACKET_OPEN() {
  return getToken(TsilParser::BRACKET_OPEN, 0);
}

tree::TerminalNode* TsilParser::Type_arrayContext::NUMBER() {
  return getToken(TsilParser::NUMBER, 0);
}

tree::TerminalNode* TsilParser::Type_arrayContext::BRACKET_CLOSE() {
  return getToken(TsilParser::BRACKET_CLOSE, 0);
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

std::vector<TsilParser::TypeContext *> TsilParser::Type_template_getContext::type() {
  return getRuleContexts<TsilParser::TypeContext>();
}

TsilParser::TypeContext* TsilParser::Type_template_getContext::type(size_t i) {
  return getRuleContext<TsilParser::TypeContext>(i);
}

tree::TerminalNode* TsilParser::Type_template_getContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::Type_template_getContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
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

std::vector<TsilParser::TypeContext *> TsilParser::Type_fn_simpleContext::type() {
  return getRuleContexts<TsilParser::TypeContext>();
}

TsilParser::TypeContext* TsilParser::Type_fn_simpleContext::type(size_t i) {
  return getRuleContext<TsilParser::TypeContext>(i);
}

tree::TerminalNode* TsilParser::Type_fn_simpleContext::MINUS() {
  return getToken(TsilParser::MINUS, 0);
}

tree::TerminalNode* TsilParser::Type_fn_simpleContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
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

TsilParser::TypeContext* TsilParser::Type_section_getContext::type() {
  return getRuleContext<TsilParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> TsilParser::Type_section_getContext::COLON() {
  return getTokens(TsilParser::COLON);
}

tree::TerminalNode* TsilParser::Type_section_getContext::COLON(size_t i) {
  return getToken(TsilParser::COLON, i);
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
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, TsilParser::RuleType, precedence);

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
    setState(433);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Type_nestedContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(401);
      match(TsilParser::PAREN_OPEN);
      setState(402);
      type(0);
      setState(403);
      match(TsilParser::PAREN_CLOSE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Type_subjectContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(405);
      match(TsilParser::ID);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Type_fn_complexContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(406);
      match(TsilParser::PAREN_OPEN);
      setState(407);
      type(0);
      setState(410); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(408);
        match(TsilParser::COMA);
        setState(409);
        type(0);
        setState(412); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TsilParser::COMA);
      setState(414);
      match(TsilParser::PAREN_CLOSE);
      setState(415);
      match(TsilParser::MINUS);
      setState(416);
      match(TsilParser::GREATER);
      setState(417);
      type(2);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Type_fn_complex_namedContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(419);
      match(TsilParser::PAREN_OPEN);
      setState(420);
      param();
      setState(425);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TsilParser::COMA) {
        setState(421);
        match(TsilParser::COMA);
        setState(422);
        param();
        setState(427);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(428);
      match(TsilParser::PAREN_CLOSE);
      setState(429);
      match(TsilParser::MINUS);
      setState(430);
      match(TsilParser::GREATER);
      setState(431);
      type(1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(464);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(462);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Type_fn_simpleContext>(_tracker.createInstance<TypeContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleType);
          setState(435);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(436);
          match(TsilParser::MINUS);
          setState(437);
          match(TsilParser::GREATER);
          setState(438);
          type(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Type_section_getContext>(_tracker.createInstance<TypeContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleType);
          setState(439);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(440);
          match(TsilParser::COLON);
          setState(441);
          match(TsilParser::COLON);
          setState(442);
          match(TsilParser::ID);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Type_template_getContext>(_tracker.createInstance<TypeContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleType);
          setState(443);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(444);
          match(TsilParser::LESSER);
          setState(445);
          type(0);
          setState(450);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == TsilParser::COMA) {
            setState(446);
            match(TsilParser::COMA);
            setState(447);
            type(0);
            setState(452);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(453);
          match(TsilParser::GREATER);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Type_getContext>(_tracker.createInstance<TypeContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleType);
          setState(455);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(456);
          match(TsilParser::DOT);
          setState(457);
          match(TsilParser::ID);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Type_arrayContext>(_tracker.createInstance<TypeContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleType);
          setState(458);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(459);
          match(TsilParser::BRACKET_OPEN);
          setState(460);
          match(TsilParser::NUMBER);
          setState(461);
          match(TsilParser::BRACKET_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(466);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
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
  enterRule(_localctx, 46, TsilParser::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(467);
    match(TsilParser::ID);
    setState(468);
    match(TsilParser::COLON);
    setState(469);
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
    case 22: return typeSempred(antlrcpp::downCast<TypeContext *>(context), predicateIndex);

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
