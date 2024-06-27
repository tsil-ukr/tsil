
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
      "file", "program", "program_element", "identifier", "section_access", 
      "number", "string", "take", "take_parts", "synonym", "synonym_value", 
      "section", "section_element", "structure", "structure_generics", "structure_generic", 
      "structure_params", "structure_param", "variation", "variation_params", 
      "variation_param", "diia_head", "diia", "diia_generics", "diia_generic", 
      "diia_declaration", "params", "param", "body", "body_element", "return_body_element", 
      "block", "defer", "if", "while", "declare", "define", "assign", "set", 
      "particle", "args", "atom", "molecule", "operation", "expr", "construct_args", 
      "construct_arg", "basic_type", "full_type", "complex_function_type_args", 
      "bitwise_op", "comparison_op", "logical_op"
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
      "'\\u0441\\u0438\\u043D\\u043E\\u043D\\u0456\\u043C'", "'='", "'>'", 
      "'<'", "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'&'", "'|'", 
      "'('", "')'", "'['", "']'", "'\\u003F'", "':'", "'~'", "'''", "'\"'", 
      "'!'", "','", "';'", "'{'", "'}'"
    },
    std::vector<std::string>{
      "", "KW_TSIL", "KW_DIIA", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_RETURN", 
      "KW_DEFER", "KW_STRUCT", "KW_VARIATION", "KW_AS", "KW_SECTION", "KW_IMPORT", 
      "KW_EXPORT", "KW_COMPOSITION", "KW_PROPERTY", "KW_PUBLIC", "KW_PRIVATE", 
      "KW_LOCAL", "KW_NOT", "KW_OR", "KW_AND", "KW_VAR", "KW_SYNONYM", "EQUAL", 
      "GREATER", "LESSER", "DOT", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", 
      "MOD", "POWER", "AND", "OR", "PAREN_OPEN", "PAREN_CLOSE", "BRACKET_OPEN", 
      "BRACKET_CLOSE", "QUESTION", "COLON", "TILDA", "QUOTE", "DOUBLE_QUOTE", 
      "EXCLAMATION", "COMA", "SEMICOLON", "QUOTE_OPEN", "QUOTE_CLOSE", "NUMBER", 
      "INTEGER", "FLOAT", "HEX", "BIN", "ID", "STRING", "COMMENT", "LINE_COMMENT", 
      "WS", "NL"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,60,684,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,1,0,1,0,1,0,1,1,5,1,111,8,1,10,1,12,
  	1,114,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,3,2,133,8,2,1,3,1,3,1,4,1,4,1,4,1,4,5,4,141,8,4,10,4,12,4,144,
  	9,4,1,5,1,5,3,5,148,8,5,1,6,3,6,151,8,6,1,6,1,6,1,7,1,7,1,7,1,7,3,7,159,
  	8,7,1,8,3,8,162,8,8,1,8,1,8,1,8,5,8,167,8,8,10,8,12,8,170,9,8,1,9,1,9,
  	1,9,1,9,1,9,1,10,1,10,1,10,3,10,180,8,10,1,11,1,11,1,11,1,11,5,11,186,
  	8,11,10,11,12,11,189,9,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,207,8,12,1,13,1,13,1,13,1,13,
  	1,13,1,13,3,13,215,8,13,1,13,1,13,3,13,219,8,13,1,13,1,13,3,13,223,8,
  	13,1,14,1,14,1,14,5,14,228,8,14,10,14,12,14,231,9,14,1,15,1,15,1,16,1,
  	16,1,16,4,16,238,8,16,11,16,12,16,239,1,17,1,17,1,17,1,17,1,18,1,18,1,
  	18,1,18,3,18,250,8,18,1,18,1,18,3,18,254,8,18,1,18,1,18,3,18,258,8,18,
  	1,19,1,19,1,19,4,19,263,8,19,11,19,12,19,264,1,20,1,20,1,20,1,20,1,21,
  	1,21,1,21,1,21,1,21,1,21,3,21,277,8,21,1,21,1,21,3,21,281,8,21,1,21,1,
  	21,1,21,1,21,3,21,287,8,21,1,21,1,21,1,21,3,21,292,8,21,1,22,1,22,1,22,
  	3,22,297,8,22,1,22,1,22,1,22,3,22,302,8,22,1,22,1,22,1,23,1,23,1,23,5,
  	23,309,8,23,10,23,12,23,312,9,23,1,24,1,24,1,25,1,25,1,25,3,25,319,8,
  	25,1,25,1,25,1,25,3,25,324,8,25,1,25,1,25,1,26,1,26,1,26,5,26,331,8,26,
  	10,26,12,26,334,9,26,1,26,3,26,337,8,26,1,27,1,27,1,27,1,27,1,28,4,28,
  	344,8,28,11,28,12,28,345,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,
  	1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,
  	1,29,1,29,1,29,1,29,1,29,3,29,376,8,29,1,30,1,30,3,30,380,8,30,1,31,1,
  	31,1,31,1,31,1,32,1,32,1,32,1,32,3,32,390,8,32,1,33,1,33,1,33,1,33,3,
  	33,396,8,33,1,33,1,33,1,33,1,33,3,33,402,8,33,1,33,1,33,3,33,406,8,33,
  	3,33,408,8,33,1,34,1,34,1,34,1,34,3,34,414,8,34,1,34,1,34,1,35,1,35,1,
  	35,3,35,421,8,35,1,35,1,35,3,35,425,8,35,1,35,1,35,1,35,1,35,1,36,1,36,
  	1,36,3,36,434,8,36,1,36,1,36,3,36,438,8,36,1,36,1,36,1,36,3,36,443,8,
  	36,1,36,1,36,1,36,1,37,1,37,1,37,1,37,1,38,1,38,1,38,1,38,1,38,1,38,1,
  	38,3,38,459,8,38,1,38,1,38,1,38,1,39,1,39,1,39,1,39,1,39,1,39,3,39,470,
  	8,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,5,39,480,8,39,10,39,12,39,
  	483,9,39,1,39,1,39,1,39,1,39,1,39,3,39,490,8,39,1,39,1,39,1,39,1,39,3,
  	39,496,8,39,1,39,5,39,499,8,39,10,39,12,39,502,9,39,1,40,1,40,1,40,5,
  	40,507,8,40,10,40,12,40,510,9,40,1,40,3,40,513,8,40,1,41,1,41,1,41,3,
  	41,518,8,41,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,3,42,529,8,42,
  	1,43,1,43,1,43,1,43,1,43,1,43,3,43,537,8,43,1,43,1,43,1,43,1,43,1,43,
  	1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,5,43,
  	557,8,43,10,43,12,43,560,9,43,1,44,1,44,1,44,3,44,565,8,44,1,44,1,44,
  	1,44,3,44,570,8,44,1,45,1,45,1,45,5,45,575,8,45,10,45,12,45,578,9,45,
  	1,45,3,45,581,8,45,1,46,1,46,3,46,585,8,46,1,46,1,46,1,47,1,47,1,47,1,
  	47,1,47,1,47,5,47,595,8,47,10,47,12,47,598,9,47,1,47,1,47,3,47,602,8,
  	47,1,47,1,47,1,47,1,47,3,47,608,8,47,1,47,1,47,1,47,1,47,5,47,614,8,47,
  	10,47,12,47,617,9,47,1,48,1,48,1,48,1,48,4,48,623,8,48,11,48,12,48,624,
  	1,48,1,48,1,48,3,48,630,8,48,1,48,1,48,1,48,1,48,3,48,636,8,48,1,48,1,
  	48,1,48,1,48,5,48,642,8,48,10,48,12,48,645,9,48,1,49,1,49,1,49,5,49,650,
  	8,49,10,49,12,49,653,9,49,1,50,1,50,1,50,1,50,1,50,1,50,1,50,3,50,662,
  	8,50,1,51,1,51,1,51,1,51,1,51,1,51,1,51,1,51,1,51,1,51,3,51,674,8,51,
  	1,52,1,52,1,52,1,52,1,52,1,52,3,52,682,8,52,1,52,0,4,78,86,94,96,53,0,
  	2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,
  	52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,
  	98,100,102,104,0,2,1,0,30,32,1,0,28,29,758,0,106,1,0,0,0,2,112,1,0,0,
  	0,4,132,1,0,0,0,6,134,1,0,0,0,8,136,1,0,0,0,10,145,1,0,0,0,12,150,1,0,
  	0,0,14,154,1,0,0,0,16,161,1,0,0,0,18,171,1,0,0,0,20,179,1,0,0,0,22,181,
  	1,0,0,0,24,206,1,0,0,0,26,208,1,0,0,0,28,224,1,0,0,0,30,232,1,0,0,0,32,
  	237,1,0,0,0,34,241,1,0,0,0,36,245,1,0,0,0,38,262,1,0,0,0,40,266,1,0,0,
  	0,42,270,1,0,0,0,44,296,1,0,0,0,46,305,1,0,0,0,48,313,1,0,0,0,50,318,
  	1,0,0,0,52,327,1,0,0,0,54,338,1,0,0,0,56,343,1,0,0,0,58,375,1,0,0,0,60,
  	377,1,0,0,0,62,381,1,0,0,0,64,385,1,0,0,0,66,391,1,0,0,0,68,409,1,0,0,
  	0,70,420,1,0,0,0,72,433,1,0,0,0,74,447,1,0,0,0,76,451,1,0,0,0,78,469,
  	1,0,0,0,80,503,1,0,0,0,82,517,1,0,0,0,84,528,1,0,0,0,86,536,1,0,0,0,88,
  	569,1,0,0,0,90,571,1,0,0,0,92,584,1,0,0,0,94,607,1,0,0,0,96,635,1,0,0,
  	0,98,646,1,0,0,0,100,661,1,0,0,0,102,673,1,0,0,0,104,681,1,0,0,0,106,
  	107,3,2,1,0,107,108,5,0,0,1,108,1,1,0,0,0,109,111,3,4,2,0,110,109,1,0,
  	0,0,111,114,1,0,0,0,112,110,1,0,0,0,112,113,1,0,0,0,113,3,1,0,0,0,114,
  	112,1,0,0,0,115,116,3,14,7,0,116,117,5,47,0,0,117,133,1,0,0,0,118,119,
  	3,18,9,0,119,120,5,47,0,0,120,133,1,0,0,0,121,122,3,70,35,0,122,123,5,
  	47,0,0,123,133,1,0,0,0,124,125,3,72,36,0,125,126,5,47,0,0,126,133,1,0,
  	0,0,127,133,3,22,11,0,128,133,3,26,13,0,129,133,3,50,25,0,130,133,3,44,
  	22,0,131,133,5,47,0,0,132,115,1,0,0,0,132,118,1,0,0,0,132,121,1,0,0,0,
  	132,124,1,0,0,0,132,127,1,0,0,0,132,128,1,0,0,0,132,129,1,0,0,0,132,130,
  	1,0,0,0,132,131,1,0,0,0,133,5,1,0,0,0,134,135,5,55,0,0,135,7,1,0,0,0,
  	136,142,3,6,3,0,137,138,5,41,0,0,138,139,5,41,0,0,139,141,3,6,3,0,140,
  	137,1,0,0,0,141,144,1,0,0,0,142,140,1,0,0,0,142,143,1,0,0,0,143,9,1,0,
  	0,0,144,142,1,0,0,0,145,147,5,50,0,0,146,148,3,6,3,0,147,146,1,0,0,0,
  	147,148,1,0,0,0,148,11,1,0,0,0,149,151,5,55,0,0,150,149,1,0,0,0,150,151,
  	1,0,0,0,151,152,1,0,0,0,152,153,5,56,0,0,153,13,1,0,0,0,154,155,5,12,
  	0,0,155,158,5,55,0,0,156,159,5,56,0,0,157,159,3,16,8,0,158,156,1,0,0,
  	0,158,157,1,0,0,0,159,15,1,0,0,0,160,162,5,27,0,0,161,160,1,0,0,0,161,
  	162,1,0,0,0,162,163,1,0,0,0,163,168,5,55,0,0,164,165,5,31,0,0,165,167,
  	5,55,0,0,166,164,1,0,0,0,167,170,1,0,0,0,168,166,1,0,0,0,168,169,1,0,
  	0,0,169,17,1,0,0,0,170,168,1,0,0,0,171,172,5,23,0,0,172,173,5,55,0,0,
  	173,174,5,24,0,0,174,175,3,20,10,0,175,19,1,0,0,0,176,180,3,96,48,0,177,
  	180,3,10,5,0,178,180,3,12,6,0,179,176,1,0,0,0,179,177,1,0,0,0,179,178,
  	1,0,0,0,180,21,1,0,0,0,181,182,5,11,0,0,182,183,5,55,0,0,183,187,5,48,
  	0,0,184,186,3,24,12,0,185,184,1,0,0,0,186,189,1,0,0,0,187,185,1,0,0,0,
  	187,188,1,0,0,0,188,190,1,0,0,0,189,187,1,0,0,0,190,191,5,49,0,0,191,
  	23,1,0,0,0,192,193,3,18,9,0,193,194,5,47,0,0,194,207,1,0,0,0,195,196,
  	3,70,35,0,196,197,5,47,0,0,197,207,1,0,0,0,198,199,3,72,36,0,199,200,
  	5,47,0,0,200,207,1,0,0,0,201,207,3,22,11,0,202,207,3,26,13,0,203,207,
  	3,50,25,0,204,207,3,44,22,0,205,207,5,47,0,0,206,192,1,0,0,0,206,195,
  	1,0,0,0,206,198,1,0,0,0,206,201,1,0,0,0,206,202,1,0,0,0,206,203,1,0,0,
  	0,206,204,1,0,0,0,206,205,1,0,0,0,207,25,1,0,0,0,208,209,5,8,0,0,209,
  	214,5,55,0,0,210,211,5,26,0,0,211,212,3,28,14,0,212,213,5,25,0,0,213,
  	215,1,0,0,0,214,210,1,0,0,0,214,215,1,0,0,0,215,222,1,0,0,0,216,218,5,
  	48,0,0,217,219,3,32,16,0,218,217,1,0,0,0,218,219,1,0,0,0,219,220,1,0,
  	0,0,220,223,5,49,0,0,221,223,5,47,0,0,222,216,1,0,0,0,222,221,1,0,0,0,
  	223,27,1,0,0,0,224,229,3,30,15,0,225,226,5,46,0,0,226,228,3,30,15,0,227,
  	225,1,0,0,0,228,231,1,0,0,0,229,227,1,0,0,0,229,230,1,0,0,0,230,29,1,
  	0,0,0,231,229,1,0,0,0,232,233,5,55,0,0,233,31,1,0,0,0,234,235,3,34,17,
  	0,235,236,5,47,0,0,236,238,1,0,0,0,237,234,1,0,0,0,238,239,1,0,0,0,239,
  	237,1,0,0,0,239,240,1,0,0,0,240,33,1,0,0,0,241,242,5,55,0,0,242,243,5,
  	41,0,0,243,244,3,96,48,0,244,35,1,0,0,0,245,246,5,9,0,0,246,249,5,55,
  	0,0,247,248,5,41,0,0,248,250,3,96,48,0,249,247,1,0,0,0,249,250,1,0,0,
  	0,250,257,1,0,0,0,251,253,5,48,0,0,252,254,3,38,19,0,253,252,1,0,0,0,
  	253,254,1,0,0,0,254,255,1,0,0,0,255,258,5,49,0,0,256,258,5,47,0,0,257,
  	251,1,0,0,0,257,256,1,0,0,0,258,37,1,0,0,0,259,260,3,40,20,0,260,261,
  	5,47,0,0,261,263,1,0,0,0,262,259,1,0,0,0,263,264,1,0,0,0,264,262,1,0,
  	0,0,264,265,1,0,0,0,265,39,1,0,0,0,266,267,5,55,0,0,267,268,5,41,0,0,
  	268,269,3,96,48,0,269,41,1,0,0,0,270,271,5,2,0,0,271,276,5,55,0,0,272,
  	273,5,26,0,0,273,274,3,46,23,0,274,275,5,25,0,0,275,277,1,0,0,0,276,272,
  	1,0,0,0,276,277,1,0,0,0,277,278,1,0,0,0,278,280,5,36,0,0,279,281,3,52,
  	26,0,280,279,1,0,0,0,280,281,1,0,0,0,281,286,1,0,0,0,282,283,5,46,0,0,
  	283,284,5,27,0,0,284,285,5,27,0,0,285,287,5,27,0,0,286,282,1,0,0,0,286,
  	287,1,0,0,0,287,288,1,0,0,0,288,291,5,37,0,0,289,290,5,41,0,0,290,292,
  	3,96,48,0,291,289,1,0,0,0,291,292,1,0,0,0,292,43,1,0,0,0,293,297,5,16,
  	0,0,294,297,5,18,0,0,295,297,5,17,0,0,296,293,1,0,0,0,296,294,1,0,0,0,
  	296,295,1,0,0,0,296,297,1,0,0,0,297,298,1,0,0,0,298,299,3,42,21,0,299,
  	301,5,48,0,0,300,302,3,56,28,0,301,300,1,0,0,0,301,302,1,0,0,0,302,303,
  	1,0,0,0,303,304,5,49,0,0,304,45,1,0,0,0,305,310,3,48,24,0,306,307,5,46,
  	0,0,307,309,3,48,24,0,308,306,1,0,0,0,309,312,1,0,0,0,310,308,1,0,0,0,
  	310,311,1,0,0,0,311,47,1,0,0,0,312,310,1,0,0,0,313,314,5,55,0,0,314,49,
  	1,0,0,0,315,319,5,16,0,0,316,319,5,18,0,0,317,319,5,17,0,0,318,315,1,
  	0,0,0,318,316,1,0,0,0,318,317,1,0,0,0,318,319,1,0,0,0,319,320,1,0,0,0,
  	320,323,3,42,21,0,321,322,5,10,0,0,322,324,5,55,0,0,323,321,1,0,0,0,323,
  	324,1,0,0,0,324,325,1,0,0,0,325,326,5,47,0,0,326,51,1,0,0,0,327,332,3,
  	54,27,0,328,329,5,46,0,0,329,331,3,54,27,0,330,328,1,0,0,0,331,334,1,
  	0,0,0,332,330,1,0,0,0,332,333,1,0,0,0,333,336,1,0,0,0,334,332,1,0,0,0,
  	335,337,5,46,0,0,336,335,1,0,0,0,336,337,1,0,0,0,337,53,1,0,0,0,338,339,
  	5,55,0,0,339,340,5,41,0,0,340,341,3,96,48,0,341,55,1,0,0,0,342,344,3,
  	58,29,0,343,342,1,0,0,0,344,345,1,0,0,0,345,343,1,0,0,0,345,346,1,0,0,
  	0,346,57,1,0,0,0,347,376,3,66,33,0,348,376,3,68,34,0,349,350,3,18,9,0,
  	350,351,5,47,0,0,351,376,1,0,0,0,352,353,3,70,35,0,353,354,5,47,0,0,354,
  	376,1,0,0,0,355,356,3,72,36,0,356,357,5,47,0,0,357,376,1,0,0,0,358,359,
  	3,74,37,0,359,360,5,47,0,0,360,376,1,0,0,0,361,362,3,76,38,0,362,363,
  	5,47,0,0,363,376,1,0,0,0,364,365,3,88,44,0,365,366,5,47,0,0,366,376,1,
  	0,0,0,367,368,3,60,30,0,368,369,5,47,0,0,369,376,1,0,0,0,370,371,3,64,
  	32,0,371,372,5,47,0,0,372,376,1,0,0,0,373,376,3,62,31,0,374,376,5,47,
  	0,0,375,347,1,0,0,0,375,348,1,0,0,0,375,349,1,0,0,0,375,352,1,0,0,0,375,
  	355,1,0,0,0,375,358,1,0,0,0,375,361,1,0,0,0,375,364,1,0,0,0,375,367,1,
  	0,0,0,375,370,1,0,0,0,375,373,1,0,0,0,375,374,1,0,0,0,376,59,1,0,0,0,
  	377,379,5,6,0,0,378,380,3,88,44,0,379,378,1,0,0,0,379,380,1,0,0,0,380,
  	61,1,0,0,0,381,382,5,48,0,0,382,383,3,56,28,0,383,384,5,49,0,0,384,63,
  	1,0,0,0,385,389,5,7,0,0,386,390,3,74,37,0,387,390,3,76,38,0,388,390,3,
  	88,44,0,389,386,1,0,0,0,389,387,1,0,0,0,389,388,1,0,0,0,390,65,1,0,0,
  	0,391,392,5,3,0,0,392,393,3,88,44,0,393,395,5,48,0,0,394,396,3,56,28,
  	0,395,394,1,0,0,0,395,396,1,0,0,0,396,397,1,0,0,0,397,407,5,49,0,0,398,
  	405,5,4,0,0,399,401,5,48,0,0,400,402,3,56,28,0,401,400,1,0,0,0,401,402,
  	1,0,0,0,402,403,1,0,0,0,403,406,5,49,0,0,404,406,3,66,33,0,405,399,1,
  	0,0,0,405,404,1,0,0,0,406,408,1,0,0,0,407,398,1,0,0,0,407,408,1,0,0,0,
  	408,67,1,0,0,0,409,410,5,5,0,0,410,411,3,88,44,0,411,413,5,48,0,0,412,
  	414,3,56,28,0,413,412,1,0,0,0,413,414,1,0,0,0,414,415,1,0,0,0,415,416,
  	5,49,0,0,416,69,1,0,0,0,417,421,5,16,0,0,418,421,5,18,0,0,419,421,5,17,
  	0,0,420,417,1,0,0,0,420,418,1,0,0,0,420,419,1,0,0,0,420,421,1,0,0,0,421,
  	424,1,0,0,0,422,425,5,1,0,0,423,425,5,22,0,0,424,422,1,0,0,0,424,423,
  	1,0,0,0,425,426,1,0,0,0,426,427,5,55,0,0,427,428,5,41,0,0,428,429,3,96,
  	48,0,429,71,1,0,0,0,430,434,5,16,0,0,431,434,5,18,0,0,432,434,5,17,0,
  	0,433,430,1,0,0,0,433,431,1,0,0,0,433,432,1,0,0,0,433,434,1,0,0,0,434,
  	437,1,0,0,0,435,438,5,1,0,0,436,438,5,22,0,0,437,435,1,0,0,0,437,436,
  	1,0,0,0,438,439,1,0,0,0,439,442,5,55,0,0,440,441,5,41,0,0,441,443,3,96,
  	48,0,442,440,1,0,0,0,442,443,1,0,0,0,443,444,1,0,0,0,444,445,5,24,0,0,
  	445,446,3,88,44,0,446,73,1,0,0,0,447,448,5,55,0,0,448,449,5,24,0,0,449,
  	450,3,88,44,0,450,75,1,0,0,0,451,458,3,78,39,0,452,453,5,27,0,0,453,459,
  	5,55,0,0,454,455,5,38,0,0,455,456,3,88,44,0,456,457,5,39,0,0,457,459,
  	1,0,0,0,458,452,1,0,0,0,458,454,1,0,0,0,459,460,1,0,0,0,460,461,5,24,
  	0,0,461,462,3,88,44,0,462,77,1,0,0,0,463,464,6,39,-1,0,464,470,3,8,4,
  	0,465,466,5,36,0,0,466,467,3,88,44,0,467,468,5,37,0,0,468,470,1,0,0,0,
  	469,463,1,0,0,0,469,465,1,0,0,0,470,500,1,0,0,0,471,472,10,5,0,0,472,
  	473,5,27,0,0,473,499,5,55,0,0,474,475,10,4,0,0,475,476,5,26,0,0,476,481,
  	3,96,48,0,477,478,5,46,0,0,478,480,3,96,48,0,479,477,1,0,0,0,480,483,
  	1,0,0,0,481,479,1,0,0,0,481,482,1,0,0,0,482,484,1,0,0,0,483,481,1,0,0,
  	0,484,485,5,25,0,0,485,499,1,0,0,0,486,487,10,3,0,0,487,489,5,38,0,0,
  	488,490,3,88,44,0,489,488,1,0,0,0,489,490,1,0,0,0,490,491,1,0,0,0,491,
  	499,5,39,0,0,492,493,10,2,0,0,493,495,5,36,0,0,494,496,3,80,40,0,495,
  	494,1,0,0,0,495,496,1,0,0,0,496,497,1,0,0,0,497,499,5,37,0,0,498,471,
  	1,0,0,0,498,474,1,0,0,0,498,486,1,0,0,0,498,492,1,0,0,0,499,502,1,0,0,
  	0,500,498,1,0,0,0,500,501,1,0,0,0,501,79,1,0,0,0,502,500,1,0,0,0,503,
  	508,3,88,44,0,504,505,5,46,0,0,505,507,3,88,44,0,506,504,1,0,0,0,507,
  	510,1,0,0,0,508,506,1,0,0,0,508,509,1,0,0,0,509,512,1,0,0,0,510,508,1,
  	0,0,0,511,513,5,46,0,0,512,511,1,0,0,0,512,513,1,0,0,0,513,81,1,0,0,0,
  	514,518,3,78,39,0,515,518,3,10,5,0,516,518,3,12,6,0,517,514,1,0,0,0,517,
  	515,1,0,0,0,517,516,1,0,0,0,518,83,1,0,0,0,519,529,3,82,41,0,520,521,
  	5,45,0,0,521,529,3,84,42,0,522,523,5,28,0,0,523,529,3,82,41,0,524,525,
  	5,29,0,0,525,529,3,82,41,0,526,527,5,42,0,0,527,529,3,82,41,0,528,519,
  	1,0,0,0,528,520,1,0,0,0,528,522,1,0,0,0,528,524,1,0,0,0,528,526,1,0,0,
  	0,529,85,1,0,0,0,530,531,6,43,-1,0,531,537,3,84,42,0,532,533,3,84,42,
  	0,533,534,5,10,0,0,534,535,3,96,48,0,535,537,1,0,0,0,536,530,1,0,0,0,
  	536,532,1,0,0,0,537,558,1,0,0,0,538,539,10,5,0,0,539,540,7,0,0,0,540,
  	557,3,86,43,6,541,542,10,4,0,0,542,543,7,1,0,0,543,557,3,86,43,5,544,
  	545,10,3,0,0,545,546,3,100,50,0,546,547,3,86,43,4,547,557,1,0,0,0,548,
  	549,10,2,0,0,549,550,3,102,51,0,550,551,3,86,43,3,551,557,1,0,0,0,552,
  	553,10,1,0,0,553,554,3,104,52,0,554,555,3,86,43,2,555,557,1,0,0,0,556,
  	538,1,0,0,0,556,541,1,0,0,0,556,544,1,0,0,0,556,548,1,0,0,0,556,552,1,
  	0,0,0,557,560,1,0,0,0,558,556,1,0,0,0,558,559,1,0,0,0,559,87,1,0,0,0,
  	560,558,1,0,0,0,561,562,3,96,48,0,562,564,5,48,0,0,563,565,3,90,45,0,
  	564,563,1,0,0,0,564,565,1,0,0,0,565,566,1,0,0,0,566,567,5,49,0,0,567,
  	570,1,0,0,0,568,570,3,86,43,0,569,561,1,0,0,0,569,568,1,0,0,0,570,89,
  	1,0,0,0,571,576,3,92,46,0,572,573,5,46,0,0,573,575,3,92,46,0,574,572,
  	1,0,0,0,575,578,1,0,0,0,576,574,1,0,0,0,576,577,1,0,0,0,577,580,1,0,0,
  	0,578,576,1,0,0,0,579,581,5,46,0,0,580,579,1,0,0,0,580,581,1,0,0,0,581,
  	91,1,0,0,0,582,583,5,55,0,0,583,585,5,24,0,0,584,582,1,0,0,0,584,585,
  	1,0,0,0,585,586,1,0,0,0,586,587,3,88,44,0,587,93,1,0,0,0,588,589,6,47,
  	-1,0,589,601,3,8,4,0,590,591,5,26,0,0,591,596,3,96,48,0,592,593,5,46,
  	0,0,593,595,3,96,48,0,594,592,1,0,0,0,595,598,1,0,0,0,596,594,1,0,0,0,
  	596,597,1,0,0,0,597,599,1,0,0,0,598,596,1,0,0,0,599,600,5,25,0,0,600,
  	602,1,0,0,0,601,590,1,0,0,0,601,602,1,0,0,0,602,608,1,0,0,0,603,604,5,
  	36,0,0,604,605,3,96,48,0,605,606,5,37,0,0,606,608,1,0,0,0,607,588,1,0,
  	0,0,607,603,1,0,0,0,608,615,1,0,0,0,609,610,10,2,0,0,610,611,5,38,0,0,
  	611,612,5,50,0,0,612,614,5,39,0,0,613,609,1,0,0,0,614,617,1,0,0,0,615,
  	613,1,0,0,0,615,616,1,0,0,0,616,95,1,0,0,0,617,615,1,0,0,0,618,619,6,
  	48,-1,0,619,622,3,94,47,0,620,621,5,35,0,0,621,623,3,94,47,0,622,620,
  	1,0,0,0,623,624,1,0,0,0,624,622,1,0,0,0,624,625,1,0,0,0,625,636,1,0,0,
  	0,626,636,3,94,47,0,627,629,5,36,0,0,628,630,3,98,49,0,629,628,1,0,0,
  	0,629,630,1,0,0,0,630,631,1,0,0,0,631,632,5,37,0,0,632,633,5,29,0,0,633,
  	634,5,25,0,0,634,636,3,96,48,2,635,618,1,0,0,0,635,626,1,0,0,0,635,627,
  	1,0,0,0,636,643,1,0,0,0,637,638,10,1,0,0,638,639,5,29,0,0,639,640,5,25,
  	0,0,640,642,3,96,48,2,641,637,1,0,0,0,642,645,1,0,0,0,643,641,1,0,0,0,
  	643,644,1,0,0,0,644,97,1,0,0,0,645,643,1,0,0,0,646,651,3,96,48,0,647,
  	648,5,46,0,0,648,650,3,96,48,0,649,647,1,0,0,0,650,653,1,0,0,0,651,649,
  	1,0,0,0,651,652,1,0,0,0,652,99,1,0,0,0,653,651,1,0,0,0,654,662,5,33,0,
  	0,655,662,5,35,0,0,656,662,5,34,0,0,657,658,5,26,0,0,658,662,5,26,0,0,
  	659,660,5,25,0,0,660,662,5,25,0,0,661,654,1,0,0,0,661,655,1,0,0,0,661,
  	656,1,0,0,0,661,657,1,0,0,0,661,659,1,0,0,0,662,101,1,0,0,0,663,664,5,
  	24,0,0,664,674,5,24,0,0,665,666,5,45,0,0,666,674,5,24,0,0,667,674,5,25,
  	0,0,668,674,5,26,0,0,669,670,5,25,0,0,670,674,5,24,0,0,671,672,5,26,0,
  	0,672,674,5,24,0,0,673,663,1,0,0,0,673,665,1,0,0,0,673,667,1,0,0,0,673,
  	668,1,0,0,0,673,669,1,0,0,0,673,671,1,0,0,0,674,103,1,0,0,0,675,676,5,
  	35,0,0,676,682,5,35,0,0,677,678,5,34,0,0,678,682,5,34,0,0,679,682,5,20,
  	0,0,680,682,5,21,0,0,681,675,1,0,0,0,681,677,1,0,0,0,681,679,1,0,0,0,
  	681,680,1,0,0,0,682,105,1,0,0,0,76,112,132,142,147,150,158,161,168,179,
  	187,206,214,218,222,229,239,249,253,257,264,276,280,286,291,296,301,310,
  	318,323,332,336,345,375,379,389,395,401,405,407,413,420,424,433,437,442,
  	458,469,481,489,495,498,500,508,512,517,528,536,556,558,564,569,576,580,
  	584,596,601,607,615,624,629,635,643,651,661,673,681
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
    setState(106);
    antlrcpp::downCast<FileContext *>(_localctx)->f_program = program();
    setState(107);
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
    setState(112);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 140737501403398) != 0)) {
      setState(109);
      program_element();
      setState(114);
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

TsilParser::TakeContext* TsilParser::Program_elementContext::take() {
  return getRuleContext<TsilParser::TakeContext>(0);
}

tree::TerminalNode* TsilParser::Program_elementContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

TsilParser::SynonymContext* TsilParser::Program_elementContext::synonym() {
  return getRuleContext<TsilParser::SynonymContext>(0);
}

TsilParser::DeclareContext* TsilParser::Program_elementContext::declare() {
  return getRuleContext<TsilParser::DeclareContext>(0);
}

TsilParser::DefineContext* TsilParser::Program_elementContext::define() {
  return getRuleContext<TsilParser::DefineContext>(0);
}

TsilParser::SectionContext* TsilParser::Program_elementContext::section() {
  return getRuleContext<TsilParser::SectionContext>(0);
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
    setState(132);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(115);
      take();
      setState(116);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(118);
      synonym();
      setState(119);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(121);
      declare();
      setState(122);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(124);
      define();
      setState(125);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(127);
      section();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(128);
      structure();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(129);
      diia_declaration();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(130);
      diia();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(131);
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
  enterRule(_localctx, 6, TsilParser::RuleIdentifier);

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
    match(TsilParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Section_accessContext ------------------------------------------------------------------

TsilParser::Section_accessContext::Section_accessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TsilParser::Section_accessContext::getRuleIndex() const {
  return TsilParser::RuleSection_access;
}

void TsilParser::Section_accessContext::copyFrom(Section_accessContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Real_section_accessContext ------------------------------------------------------------------

std::vector<TsilParser::IdentifierContext *> TsilParser::Real_section_accessContext::identifier() {
  return getRuleContexts<TsilParser::IdentifierContext>();
}

TsilParser::IdentifierContext* TsilParser::Real_section_accessContext::identifier(size_t i) {
  return getRuleContext<TsilParser::IdentifierContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Real_section_accessContext::COLON() {
  return getTokens(TsilParser::COLON);
}

tree::TerminalNode* TsilParser::Real_section_accessContext::COLON(size_t i) {
  return getToken(TsilParser::COLON, i);
}

TsilParser::Real_section_accessContext::Real_section_accessContext(Section_accessContext *ctx) { copyFrom(ctx); }

void TsilParser::Real_section_accessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReal_section_access(this);
}
void TsilParser::Real_section_accessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReal_section_access(this);
}

std::any TsilParser::Real_section_accessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitReal_section_access(this);
  else
    return visitor->visitChildren(this);
}
TsilParser::Section_accessContext* TsilParser::section_access() {
  Section_accessContext *_localctx = _tracker.createInstance<Section_accessContext>(_ctx, getState());
  enterRule(_localctx, 8, TsilParser::RuleSection_access);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    _localctx = _tracker.createInstance<TsilParser::Real_section_accessContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(136);
    identifier();
    setState(142);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(137);
        match(TsilParser::COLON);
        setState(138);
        match(TsilParser::COLON);
        setState(139);
        identifier(); 
      }
      setState(144);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
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

TsilParser::IdentifierContext* TsilParser::NumberContext::identifier() {
  return getRuleContext<TsilParser::IdentifierContext>(0);
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
  enterRule(_localctx, 10, TsilParser::RuleNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    match(TsilParser::NUMBER);
    setState(147);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(146);
      antlrcpp::downCast<NumberContext *>(_localctx)->id = identifier();
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
  enterRule(_localctx, 12, TsilParser::RuleString);
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
    setState(150);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(149);
      antlrcpp::downCast<StringContext *>(_localctx)->s_prefix = match(TsilParser::ID);
    }
    setState(152);
    match(TsilParser::STRING);
   
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

tree::TerminalNode* TsilParser::TakeContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::TakeContext::STRING() {
  return getToken(TsilParser::STRING, 0);
}

TsilParser::Take_partsContext* TsilParser::TakeContext::take_parts() {
  return getRuleContext<TsilParser::Take_partsContext>(0);
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
  enterRule(_localctx, 14, TsilParser::RuleTake);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    match(TsilParser::KW_IMPORT);
    setState(155);
    antlrcpp::downCast<TakeContext *>(_localctx)->t_type = match(TsilParser::ID);
    setState(158);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::STRING: {
        setState(156);
        antlrcpp::downCast<TakeContext *>(_localctx)->t_string = match(TsilParser::STRING);
        break;
      }

      case TsilParser::DOT:
      case TsilParser::ID: {
        setState(157);
        antlrcpp::downCast<TakeContext *>(_localctx)->t_parts = take_parts();
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

//----------------- Take_partsContext ------------------------------------------------------------------

TsilParser::Take_partsContext::Take_partsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TsilParser::Take_partsContext::ID() {
  return getTokens(TsilParser::ID);
}

tree::TerminalNode* TsilParser::Take_partsContext::ID(size_t i) {
  return getToken(TsilParser::ID, i);
}

std::vector<tree::TerminalNode *> TsilParser::Take_partsContext::DIVIDE() {
  return getTokens(TsilParser::DIVIDE);
}

tree::TerminalNode* TsilParser::Take_partsContext::DIVIDE(size_t i) {
  return getToken(TsilParser::DIVIDE, i);
}

tree::TerminalNode* TsilParser::Take_partsContext::DOT() {
  return getToken(TsilParser::DOT, 0);
}


size_t TsilParser::Take_partsContext::getRuleIndex() const {
  return TsilParser::RuleTake_parts;
}

void TsilParser::Take_partsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTake_parts(this);
}

void TsilParser::Take_partsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTake_parts(this);
}


std::any TsilParser::Take_partsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitTake_parts(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Take_partsContext* TsilParser::take_parts() {
  Take_partsContext *_localctx = _tracker.createInstance<Take_partsContext>(_ctx, getState());
  enterRule(_localctx, 16, TsilParser::RuleTake_parts);
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
    setState(161);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::DOT) {
      setState(160);
      antlrcpp::downCast<Take_partsContext *>(_localctx)->tp_relative = match(TsilParser::DOT);
    }
    setState(163);
    match(TsilParser::ID);
    setState(168);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TsilParser::DIVIDE) {
      setState(164);
      match(TsilParser::DIVIDE);
      setState(165);
      match(TsilParser::ID);
      setState(170);
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

tree::TerminalNode* TsilParser::SynonymContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::Synonym_valueContext* TsilParser::SynonymContext::synonym_value() {
  return getRuleContext<TsilParser::Synonym_valueContext>(0);
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
  enterRule(_localctx, 18, TsilParser::RuleSynonym);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    match(TsilParser::KW_SYNONYM);
    setState(172);
    antlrcpp::downCast<SynonymContext *>(_localctx)->s_name = match(TsilParser::ID);
    setState(173);
    match(TsilParser::EQUAL);
    setState(174);
    antlrcpp::downCast<SynonymContext *>(_localctx)->s_value = synonym_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Synonym_valueContext ------------------------------------------------------------------

TsilParser::Synonym_valueContext::Synonym_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TsilParser::Full_typeContext* TsilParser::Synonym_valueContext::full_type() {
  return getRuleContext<TsilParser::Full_typeContext>(0);
}

TsilParser::NumberContext* TsilParser::Synonym_valueContext::number() {
  return getRuleContext<TsilParser::NumberContext>(0);
}

TsilParser::StringContext* TsilParser::Synonym_valueContext::string() {
  return getRuleContext<TsilParser::StringContext>(0);
}


size_t TsilParser::Synonym_valueContext::getRuleIndex() const {
  return TsilParser::RuleSynonym_value;
}

void TsilParser::Synonym_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSynonym_value(this);
}

void TsilParser::Synonym_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSynonym_value(this);
}


std::any TsilParser::Synonym_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSynonym_value(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Synonym_valueContext* TsilParser::synonym_value() {
  Synonym_valueContext *_localctx = _tracker.createInstance<Synonym_valueContext>(_ctx, getState());
  enterRule(_localctx, 20, TsilParser::RuleSynonym_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(179);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(176);
      full_type(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(177);
      number();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(178);
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

tree::TerminalNode* TsilParser::SectionContext::ID() {
  return getToken(TsilParser::ID, 0);
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
  enterRule(_localctx, 22, TsilParser::RuleSection);
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
    match(TsilParser::KW_SECTION);
    setState(182);
    antlrcpp::downCast<SectionContext *>(_localctx)->s_name = match(TsilParser::ID);
    setState(183);
    match(TsilParser::QUOTE_OPEN);
    setState(187);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 140737501399302) != 0)) {
      setState(184);
      section_element();
      setState(189);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(190);
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

TsilParser::SynonymContext* TsilParser::Section_elementContext::synonym() {
  return getRuleContext<TsilParser::SynonymContext>(0);
}

tree::TerminalNode* TsilParser::Section_elementContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

TsilParser::DeclareContext* TsilParser::Section_elementContext::declare() {
  return getRuleContext<TsilParser::DeclareContext>(0);
}

TsilParser::DefineContext* TsilParser::Section_elementContext::define() {
  return getRuleContext<TsilParser::DefineContext>(0);
}

TsilParser::SectionContext* TsilParser::Section_elementContext::section() {
  return getRuleContext<TsilParser::SectionContext>(0);
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
  enterRule(_localctx, 24, TsilParser::RuleSection_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(206);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(192);
      synonym();
      setState(193);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(195);
      declare();
      setState(196);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(198);
      define();
      setState(199);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(201);
      section();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(202);
      structure();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(203);
      diia_declaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(204);
      diia();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(205);
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

tree::TerminalNode* TsilParser::StructureContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::StructureContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::StructureContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}

tree::TerminalNode* TsilParser::StructureContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
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
  enterRule(_localctx, 26, TsilParser::RuleStructure);
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
    match(TsilParser::KW_STRUCT);
    setState(209);
    antlrcpp::downCast<StructureContext *>(_localctx)->s_name = match(TsilParser::ID);
    setState(214);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(210);
      match(TsilParser::LESSER);
      setState(211);
      antlrcpp::downCast<StructureContext *>(_localctx)->s_generics = structure_generics();
      setState(212);
      match(TsilParser::GREATER);
    }
    setState(222);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::QUOTE_OPEN: {
        setState(216);
        match(TsilParser::QUOTE_OPEN);
        setState(218);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TsilParser::ID) {
          setState(217);
          antlrcpp::downCast<StructureContext *>(_localctx)->s_params = structure_params();
        }
        setState(220);
        match(TsilParser::QUOTE_CLOSE);
        break;
      }

      case TsilParser::SEMICOLON: {
        setState(221);
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
  enterRule(_localctx, 28, TsilParser::RuleStructure_generics);
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
    structure_generic();
    setState(229);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TsilParser::COMA) {
      setState(225);
      match(TsilParser::COMA);
      setState(226);
      structure_generic();
      setState(231);
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

tree::TerminalNode* TsilParser::Structure_genericContext::ID() {
  return getToken(TsilParser::ID, 0);
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
  enterRule(_localctx, 30, TsilParser::RuleStructure_generic);

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
    antlrcpp::downCast<Structure_genericContext *>(_localctx)->sg_name = match(TsilParser::ID);
   
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

std::vector<tree::TerminalNode *> TsilParser::Structure_paramsContext::SEMICOLON() {
  return getTokens(TsilParser::SEMICOLON);
}

tree::TerminalNode* TsilParser::Structure_paramsContext::SEMICOLON(size_t i) {
  return getToken(TsilParser::SEMICOLON, i);
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
  enterRule(_localctx, 32, TsilParser::RuleStructure_params);
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
    setState(237); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(234);
      structure_param();
      setState(235);
      match(TsilParser::SEMICOLON);
      setState(239); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TsilParser::ID);
   
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

tree::TerminalNode* TsilParser::Structure_paramContext::ID() {
  return getToken(TsilParser::ID, 0);
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
  enterRule(_localctx, 34, TsilParser::RuleStructure_param);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    antlrcpp::downCast<Structure_paramContext *>(_localctx)->sp_name = match(TsilParser::ID);
    setState(242);
    match(TsilParser::COLON);
    setState(243);
    antlrcpp::downCast<Structure_paramContext *>(_localctx)->sp_type = full_type(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariationContext ------------------------------------------------------------------

TsilParser::VariationContext::VariationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::VariationContext::KW_VARIATION() {
  return getToken(TsilParser::KW_VARIATION, 0);
}

tree::TerminalNode* TsilParser::VariationContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::VariationContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::VariationContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}

tree::TerminalNode* TsilParser::VariationContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

tree::TerminalNode* TsilParser::VariationContext::COLON() {
  return getToken(TsilParser::COLON, 0);
}

TsilParser::Full_typeContext* TsilParser::VariationContext::full_type() {
  return getRuleContext<TsilParser::Full_typeContext>(0);
}

TsilParser::Variation_paramsContext* TsilParser::VariationContext::variation_params() {
  return getRuleContext<TsilParser::Variation_paramsContext>(0);
}


size_t TsilParser::VariationContext::getRuleIndex() const {
  return TsilParser::RuleVariation;
}

void TsilParser::VariationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariation(this);
}

void TsilParser::VariationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariation(this);
}


std::any TsilParser::VariationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitVariation(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::VariationContext* TsilParser::variation() {
  VariationContext *_localctx = _tracker.createInstance<VariationContext>(_ctx, getState());
  enterRule(_localctx, 36, TsilParser::RuleVariation);
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
    setState(245);
    match(TsilParser::KW_VARIATION);
    setState(246);
    antlrcpp::downCast<VariationContext *>(_localctx)->v_name = match(TsilParser::ID);
    setState(249);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(247);
      match(TsilParser::COLON);
      setState(248);
      antlrcpp::downCast<VariationContext *>(_localctx)->v_type = full_type(0);
    }
    setState(257);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::QUOTE_OPEN: {
        setState(251);
        match(TsilParser::QUOTE_OPEN);
        setState(253);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TsilParser::ID) {
          setState(252);
          antlrcpp::downCast<VariationContext *>(_localctx)->v_params = variation_params();
        }
        setState(255);
        match(TsilParser::QUOTE_CLOSE);
        break;
      }

      case TsilParser::SEMICOLON: {
        setState(256);
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

//----------------- Variation_paramsContext ------------------------------------------------------------------

TsilParser::Variation_paramsContext::Variation_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TsilParser::Variation_paramContext *> TsilParser::Variation_paramsContext::variation_param() {
  return getRuleContexts<TsilParser::Variation_paramContext>();
}

TsilParser::Variation_paramContext* TsilParser::Variation_paramsContext::variation_param(size_t i) {
  return getRuleContext<TsilParser::Variation_paramContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Variation_paramsContext::SEMICOLON() {
  return getTokens(TsilParser::SEMICOLON);
}

tree::TerminalNode* TsilParser::Variation_paramsContext::SEMICOLON(size_t i) {
  return getToken(TsilParser::SEMICOLON, i);
}


size_t TsilParser::Variation_paramsContext::getRuleIndex() const {
  return TsilParser::RuleVariation_params;
}

void TsilParser::Variation_paramsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariation_params(this);
}

void TsilParser::Variation_paramsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariation_params(this);
}


std::any TsilParser::Variation_paramsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitVariation_params(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Variation_paramsContext* TsilParser::variation_params() {
  Variation_paramsContext *_localctx = _tracker.createInstance<Variation_paramsContext>(_ctx, getState());
  enterRule(_localctx, 38, TsilParser::RuleVariation_params);
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
    setState(262); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(259);
      variation_param();
      setState(260);
      match(TsilParser::SEMICOLON);
      setState(264); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TsilParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variation_paramContext ------------------------------------------------------------------

TsilParser::Variation_paramContext::Variation_paramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::Variation_paramContext::COLON() {
  return getToken(TsilParser::COLON, 0);
}

tree::TerminalNode* TsilParser::Variation_paramContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::Full_typeContext* TsilParser::Variation_paramContext::full_type() {
  return getRuleContext<TsilParser::Full_typeContext>(0);
}


size_t TsilParser::Variation_paramContext::getRuleIndex() const {
  return TsilParser::RuleVariation_param;
}

void TsilParser::Variation_paramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariation_param(this);
}

void TsilParser::Variation_paramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariation_param(this);
}


std::any TsilParser::Variation_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitVariation_param(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Variation_paramContext* TsilParser::variation_param() {
  Variation_paramContext *_localctx = _tracker.createInstance<Variation_paramContext>(_ctx, getState());
  enterRule(_localctx, 40, TsilParser::RuleVariation_param);

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
    antlrcpp::downCast<Variation_paramContext *>(_localctx)->vp_name = match(TsilParser::ID);
    setState(267);
    match(TsilParser::COLON);
    setState(268);
    antlrcpp::downCast<Variation_paramContext *>(_localctx)->vp_type = full_type(0);
   
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

tree::TerminalNode* TsilParser::Diia_headContext::ID() {
  return getToken(TsilParser::ID, 0);
}

tree::TerminalNode* TsilParser::Diia_headContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::Diia_headContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
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
  enterRule(_localctx, 42, TsilParser::RuleDiia_head);
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
    setState(270);
    match(TsilParser::KW_DIIA);
    setState(271);
    antlrcpp::downCast<Diia_headContext *>(_localctx)->d_name = match(TsilParser::ID);
    setState(276);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(272);
      match(TsilParser::LESSER);
      setState(273);
      antlrcpp::downCast<Diia_headContext *>(_localctx)->d_generics = diia_generics();
      setState(274);
      match(TsilParser::GREATER);
    }
    setState(278);
    match(TsilParser::PAREN_OPEN);
    setState(280);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(279);
      antlrcpp::downCast<Diia_headContext *>(_localctx)->d_params = params();
    }
    setState(286);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COMA) {
      setState(282);
      antlrcpp::downCast<Diia_headContext *>(_localctx)->d_variadic = match(TsilParser::COMA);
      setState(283);
      match(TsilParser::DOT);
      setState(284);
      match(TsilParser::DOT);
      setState(285);
      match(TsilParser::DOT);
    }
    setState(288);
    match(TsilParser::PAREN_CLOSE);
    setState(291);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(289);
      match(TsilParser::COLON);
      setState(290);
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
  enterRule(_localctx, 44, TsilParser::RuleDiia);
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
    setState(296);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(293);
        antlrcpp::downCast<DiiaContext *>(_localctx)->d_extern = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(294);
        antlrcpp::downCast<DiiaContext *>(_localctx)->d_local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(295);
        antlrcpp::downCast<DiiaContext *>(_localctx)->d_internal = match(TsilParser::KW_PRIVATE);
        break;
      }

      case TsilParser::KW_DIIA: {
        break;
      }

    default:
      break;
    }
    setState(298);
    antlrcpp::downCast<DiiaContext *>(_localctx)->d_head = diia_head();
    setState(299);
    match(TsilParser::QUOTE_OPEN);
    setState(301);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 109674155385225450) != 0)) {
      setState(300);
      antlrcpp::downCast<DiiaContext *>(_localctx)->d_body = body();
    }
    setState(303);
    match(TsilParser::QUOTE_CLOSE);
   
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
  enterRule(_localctx, 46, TsilParser::RuleDiia_generics);
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
    setState(305);
    diia_generic();
    setState(310);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TsilParser::COMA) {
      setState(306);
      match(TsilParser::COMA);
      setState(307);
      diia_generic();
      setState(312);
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

tree::TerminalNode* TsilParser::Diia_genericContext::ID() {
  return getToken(TsilParser::ID, 0);
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
  enterRule(_localctx, 48, TsilParser::RuleDiia_generic);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(313);
    antlrcpp::downCast<Diia_genericContext *>(_localctx)->dg_name = match(TsilParser::ID);
   
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

tree::TerminalNode* TsilParser::Diia_declarationContext::ID() {
  return getToken(TsilParser::ID, 0);
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
  enterRule(_localctx, 50, TsilParser::RuleDiia_declaration);
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
    setState(318);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(315);
        antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_extern = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(316);
        antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(317);
        antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_internal = match(TsilParser::KW_PRIVATE);
        break;
      }

      case TsilParser::KW_DIIA: {
        break;
      }

    default:
      break;
    }
    setState(320);
    antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_head = diia_head();
    setState(323);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::KW_AS) {
      setState(321);
      match(TsilParser::KW_AS);
      setState(322);
      antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_as = match(TsilParser::ID);
    }
    setState(325);
    match(TsilParser::SEMICOLON);
   
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
    setState(327);
    param();
    setState(332);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(328);
        match(TsilParser::COMA);
        setState(329);
        param(); 
      }
      setState(334);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
    setState(336);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(335);
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

tree::TerminalNode* TsilParser::ParamContext::ID() {
  return getToken(TsilParser::ID, 0);
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
    setState(338);
    antlrcpp::downCast<ParamContext *>(_localctx)->p_name = match(TsilParser::ID);
    setState(339);
    match(TsilParser::COLON);
    setState(340);
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
    setState(343); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(342);
      body_element();
      setState(345); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 109674155385225450) != 0));
   
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

TsilParser::SynonymContext* TsilParser::Body_elementContext::synonym() {
  return getRuleContext<TsilParser::SynonymContext>(0);
}

tree::TerminalNode* TsilParser::Body_elementContext::SEMICOLON() {
  return getToken(TsilParser::SEMICOLON, 0);
}

TsilParser::DeclareContext* TsilParser::Body_elementContext::declare() {
  return getRuleContext<TsilParser::DeclareContext>(0);
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

TsilParser::Return_body_elementContext* TsilParser::Body_elementContext::return_body_element() {
  return getRuleContext<TsilParser::Return_body_elementContext>(0);
}

TsilParser::DeferContext* TsilParser::Body_elementContext::defer() {
  return getRuleContext<TsilParser::DeferContext>(0);
}

TsilParser::BlockContext* TsilParser::Body_elementContext::block() {
  return getRuleContext<TsilParser::BlockContext>(0);
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
  enterRule(_localctx, 58, TsilParser::RuleBody_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(375);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(347);
      if_();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(348);
      while_();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(349);
      synonym();
      setState(350);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(352);
      declare();
      setState(353);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(355);
      define();
      setState(356);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(358);
      assign();
      setState(359);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(361);
      set();
      setState(362);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(364);
      expr();
      setState(365);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(367);
      return_body_element();
      setState(368);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(370);
      defer();
      setState(371);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(373);
      block();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(374);
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
  enterRule(_localctx, 60, TsilParser::RuleReturn_body_element);
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
    setState(377);
    match(TsilParser::KW_RETURN);
    setState(379);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 109251942907117568) != 0)) {
      setState(378);
      antlrcpp::downCast<Return_body_elementContext *>(_localctx)->rbl_value = expr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

TsilParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::BlockContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

TsilParser::BodyContext* TsilParser::BlockContext::body() {
  return getRuleContext<TsilParser::BodyContext>(0);
}

tree::TerminalNode* TsilParser::BlockContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}


size_t TsilParser::BlockContext::getRuleIndex() const {
  return TsilParser::RuleBlock;
}

void TsilParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void TsilParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any TsilParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::BlockContext* TsilParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 62, TsilParser::RuleBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(381);
    match(TsilParser::QUOTE_OPEN);
    setState(382);
    body();
    setState(383);
    match(TsilParser::QUOTE_CLOSE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeferContext ------------------------------------------------------------------

TsilParser::DeferContext::DeferContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::DeferContext::KW_DEFER() {
  return getToken(TsilParser::KW_DEFER, 0);
}

TsilParser::AssignContext* TsilParser::DeferContext::assign() {
  return getRuleContext<TsilParser::AssignContext>(0);
}

TsilParser::SetContext* TsilParser::DeferContext::set() {
  return getRuleContext<TsilParser::SetContext>(0);
}

TsilParser::ExprContext* TsilParser::DeferContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}


size_t TsilParser::DeferContext::getRuleIndex() const {
  return TsilParser::RuleDefer;
}

void TsilParser::DeferContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefer(this);
}

void TsilParser::DeferContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefer(this);
}


std::any TsilParser::DeferContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitDefer(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::DeferContext* TsilParser::defer() {
  DeferContext *_localctx = _tracker.createInstance<DeferContext>(_ctx, getState());
  enterRule(_localctx, 64, TsilParser::RuleDefer);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(385);
    match(TsilParser::KW_DEFER);
    setState(389);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      setState(386);
      assign();
      break;
    }

    case 2: {
      setState(387);
      set();
      break;
    }

    case 3: {
      setState(388);
      expr();
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
  enterRule(_localctx, 66, TsilParser::RuleIf);
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
    setState(391);
    match(TsilParser::KW_IF);
    setState(392);
    antlrcpp::downCast<IfContext *>(_localctx)->i_value = expr();
    setState(393);
    match(TsilParser::QUOTE_OPEN);
    setState(395);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 109674155385225450) != 0)) {
      setState(394);
      antlrcpp::downCast<IfContext *>(_localctx)->i_body = body();
    }
    setState(397);
    match(TsilParser::QUOTE_CLOSE);
    setState(407);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::KW_ELSE) {
      setState(398);
      match(TsilParser::KW_ELSE);
      setState(405);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TsilParser::QUOTE_OPEN: {
          setState(399);
          match(TsilParser::QUOTE_OPEN);
          setState(401);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 109674155385225450) != 0)) {
            setState(400);
            antlrcpp::downCast<IfContext *>(_localctx)->i_else_body = body();
          }
          setState(403);
          match(TsilParser::QUOTE_CLOSE);
          break;
        }

        case TsilParser::KW_IF: {
          setState(404);
          antlrcpp::downCast<IfContext *>(_localctx)->i_else_if = if_();
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
  enterRule(_localctx, 68, TsilParser::RuleWhile);
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
    setState(409);
    match(TsilParser::KW_WHILE);
    setState(410);
    antlrcpp::downCast<WhileContext *>(_localctx)->w_value = expr();
    setState(411);
    match(TsilParser::QUOTE_OPEN);
    setState(413);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 109674155385225450) != 0)) {
      setState(412);
      antlrcpp::downCast<WhileContext *>(_localctx)->w_body = body();
    }
    setState(415);
    match(TsilParser::QUOTE_CLOSE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclareContext ------------------------------------------------------------------

TsilParser::DeclareContext::DeclareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TsilParser::DeclareContext::COLON() {
  return getToken(TsilParser::COLON, 0);
}

tree::TerminalNode* TsilParser::DeclareContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::Full_typeContext* TsilParser::DeclareContext::full_type() {
  return getRuleContext<TsilParser::Full_typeContext>(0);
}

tree::TerminalNode* TsilParser::DeclareContext::KW_TSIL() {
  return getToken(TsilParser::KW_TSIL, 0);
}

tree::TerminalNode* TsilParser::DeclareContext::KW_VAR() {
  return getToken(TsilParser::KW_VAR, 0);
}

tree::TerminalNode* TsilParser::DeclareContext::KW_PUBLIC() {
  return getToken(TsilParser::KW_PUBLIC, 0);
}

tree::TerminalNode* TsilParser::DeclareContext::KW_LOCAL() {
  return getToken(TsilParser::KW_LOCAL, 0);
}

tree::TerminalNode* TsilParser::DeclareContext::KW_PRIVATE() {
  return getToken(TsilParser::KW_PRIVATE, 0);
}


size_t TsilParser::DeclareContext::getRuleIndex() const {
  return TsilParser::RuleDeclare;
}

void TsilParser::DeclareContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclare(this);
}

void TsilParser::DeclareContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclare(this);
}


std::any TsilParser::DeclareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitDeclare(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::DeclareContext* TsilParser::declare() {
  DeclareContext *_localctx = _tracker.createInstance<DeclareContext>(_ctx, getState());
  enterRule(_localctx, 70, TsilParser::RuleDeclare);

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
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(417);
        antlrcpp::downCast<DeclareContext *>(_localctx)->d_extern = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(418);
        antlrcpp::downCast<DeclareContext *>(_localctx)->d_local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(419);
        antlrcpp::downCast<DeclareContext *>(_localctx)->d_internal = match(TsilParser::KW_PRIVATE);
        break;
      }

      case TsilParser::KW_TSIL:
      case TsilParser::KW_VAR: {
        break;
      }

    default:
      break;
    }
    setState(424);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_TSIL: {
        setState(422);
        antlrcpp::downCast<DeclareContext *>(_localctx)->d_tsil = match(TsilParser::KW_TSIL);
        break;
      }

      case TsilParser::KW_VAR: {
        setState(423);
        antlrcpp::downCast<DeclareContext *>(_localctx)->d_var = match(TsilParser::KW_VAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(426);
    antlrcpp::downCast<DeclareContext *>(_localctx)->d_id = match(TsilParser::ID);
    setState(427);
    match(TsilParser::COLON);
    setState(428);
    antlrcpp::downCast<DeclareContext *>(_localctx)->d_type = full_type(0);
   
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

tree::TerminalNode* TsilParser::DefineContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}

tree::TerminalNode* TsilParser::DefineContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::ExprContext* TsilParser::DefineContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

tree::TerminalNode* TsilParser::DefineContext::KW_TSIL() {
  return getToken(TsilParser::KW_TSIL, 0);
}

tree::TerminalNode* TsilParser::DefineContext::KW_VAR() {
  return getToken(TsilParser::KW_VAR, 0);
}

tree::TerminalNode* TsilParser::DefineContext::COLON() {
  return getToken(TsilParser::COLON, 0);
}

tree::TerminalNode* TsilParser::DefineContext::KW_PUBLIC() {
  return getToken(TsilParser::KW_PUBLIC, 0);
}

tree::TerminalNode* TsilParser::DefineContext::KW_LOCAL() {
  return getToken(TsilParser::KW_LOCAL, 0);
}

tree::TerminalNode* TsilParser::DefineContext::KW_PRIVATE() {
  return getToken(TsilParser::KW_PRIVATE, 0);
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
  enterRule(_localctx, 72, TsilParser::RuleDefine);
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
    setState(433);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(430);
        antlrcpp::downCast<DefineContext *>(_localctx)->d_extern = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(431);
        antlrcpp::downCast<DefineContext *>(_localctx)->d_local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(432);
        antlrcpp::downCast<DefineContext *>(_localctx)->d_internal = match(TsilParser::KW_PRIVATE);
        break;
      }

      case TsilParser::KW_TSIL:
      case TsilParser::KW_VAR: {
        break;
      }

    default:
      break;
    }
    setState(437);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_TSIL: {
        setState(435);
        antlrcpp::downCast<DefineContext *>(_localctx)->d_tsil = match(TsilParser::KW_TSIL);
        break;
      }

      case TsilParser::KW_VAR: {
        setState(436);
        antlrcpp::downCast<DefineContext *>(_localctx)->d_var = match(TsilParser::KW_VAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(439);
    antlrcpp::downCast<DefineContext *>(_localctx)->d_id = match(TsilParser::ID);
    setState(442);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(440);
      match(TsilParser::COLON);
      setState(441);
      antlrcpp::downCast<DefineContext *>(_localctx)->d_type = full_type(0);
    }
    setState(444);
    match(TsilParser::EQUAL);
    setState(445);
    antlrcpp::downCast<DefineContext *>(_localctx)->d_value = expr();
   
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

tree::TerminalNode* TsilParser::AssignContext::ID() {
  return getToken(TsilParser::ID, 0);
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
  enterRule(_localctx, 74, TsilParser::RuleAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(447);
    antlrcpp::downCast<AssignContext *>(_localctx)->a_id = match(TsilParser::ID);
    setState(448);
    match(TsilParser::EQUAL);
    setState(449);
    antlrcpp::downCast<AssignContext *>(_localctx)->a_value = expr();
   
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

tree::TerminalNode* TsilParser::SetContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}

TsilParser::ParticleContext* TsilParser::SetContext::particle() {
  return getRuleContext<TsilParser::ParticleContext>(0);
}

std::vector<TsilParser::ExprContext *> TsilParser::SetContext::expr() {
  return getRuleContexts<TsilParser::ExprContext>();
}

TsilParser::ExprContext* TsilParser::SetContext::expr(size_t i) {
  return getRuleContext<TsilParser::ExprContext>(i);
}

tree::TerminalNode* TsilParser::SetContext::DOT() {
  return getToken(TsilParser::DOT, 0);
}

tree::TerminalNode* TsilParser::SetContext::BRACKET_OPEN() {
  return getToken(TsilParser::BRACKET_OPEN, 0);
}

tree::TerminalNode* TsilParser::SetContext::BRACKET_CLOSE() {
  return getToken(TsilParser::BRACKET_CLOSE, 0);
}

tree::TerminalNode* TsilParser::SetContext::ID() {
  return getToken(TsilParser::ID, 0);
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
  enterRule(_localctx, 76, TsilParser::RuleSet);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(451);
    antlrcpp::downCast<SetContext *>(_localctx)->s_left = particle(0);
    setState(458);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::DOT: {
        setState(452);
        match(TsilParser::DOT);
        setState(453);
        antlrcpp::downCast<SetContext *>(_localctx)->s_id = match(TsilParser::ID);
        break;
      }

      case TsilParser::BRACKET_OPEN: {
        setState(454);
        match(TsilParser::BRACKET_OPEN);
        setState(455);
        antlrcpp::downCast<SetContext *>(_localctx)->s_index = expr();
        setState(456);
        match(TsilParser::BRACKET_CLOSE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(460);
    match(TsilParser::EQUAL);
    setState(461);
    antlrcpp::downCast<SetContext *>(_localctx)->s_value = expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParticleContext ------------------------------------------------------------------

TsilParser::ParticleContext::ParticleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TsilParser::ParticleContext::getRuleIndex() const {
  return TsilParser::RuleParticle;
}

void TsilParser::ParticleContext::copyFrom(ParticleContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CallContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::CallContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

tree::TerminalNode* TsilParser::CallContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

TsilParser::ParticleContext* TsilParser::CallContext::particle() {
  return getRuleContext<TsilParser::ParticleContext>(0);
}

TsilParser::ArgsContext* TsilParser::CallContext::args() {
  return getRuleContext<TsilParser::ArgsContext>(0);
}

TsilParser::CallContext::CallContext(ParticleContext *ctx) { copyFrom(ctx); }

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
//----------------- AccessContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::AccessContext::BRACKET_OPEN() {
  return getToken(TsilParser::BRACKET_OPEN, 0);
}

tree::TerminalNode* TsilParser::AccessContext::BRACKET_CLOSE() {
  return getToken(TsilParser::BRACKET_CLOSE, 0);
}

TsilParser::ParticleContext* TsilParser::AccessContext::particle() {
  return getRuleContext<TsilParser::ParticleContext>(0);
}

TsilParser::ExprContext* TsilParser::AccessContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

TsilParser::AccessContext::AccessContext(ParticleContext *ctx) { copyFrom(ctx); }

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
//----------------- GetContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::GetContext::DOT() {
  return getToken(TsilParser::DOT, 0);
}

TsilParser::ParticleContext* TsilParser::GetContext::particle() {
  return getRuleContext<TsilParser::ParticleContext>(0);
}

tree::TerminalNode* TsilParser::GetContext::ID() {
  return getToken(TsilParser::ID, 0);
}

TsilParser::GetContext::GetContext(ParticleContext *ctx) { copyFrom(ctx); }

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
//----------------- Particle_section_accessContext ------------------------------------------------------------------

TsilParser::Section_accessContext* TsilParser::Particle_section_accessContext::section_access() {
  return getRuleContext<TsilParser::Section_accessContext>(0);
}

TsilParser::Particle_section_accessContext::Particle_section_accessContext(ParticleContext *ctx) { copyFrom(ctx); }

void TsilParser::Particle_section_accessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParticle_section_access(this);
}
void TsilParser::Particle_section_accessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParticle_section_access(this);
}

std::any TsilParser::Particle_section_accessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitParticle_section_access(this);
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

TsilParser::NestedContext::NestedContext(ParticleContext *ctx) { copyFrom(ctx); }

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
//----------------- GenericContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::GenericContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::GenericContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

TsilParser::ParticleContext* TsilParser::GenericContext::particle() {
  return getRuleContext<TsilParser::ParticleContext>(0);
}

std::vector<TsilParser::Full_typeContext *> TsilParser::GenericContext::full_type() {
  return getRuleContexts<TsilParser::Full_typeContext>();
}

TsilParser::Full_typeContext* TsilParser::GenericContext::full_type(size_t i) {
  return getRuleContext<TsilParser::Full_typeContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::GenericContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::GenericContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}

TsilParser::GenericContext::GenericContext(ParticleContext *ctx) { copyFrom(ctx); }

void TsilParser::GenericContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeneric(this);
}
void TsilParser::GenericContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeneric(this);
}

std::any TsilParser::GenericContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitGeneric(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::ParticleContext* TsilParser::particle() {
   return particle(0);
}

TsilParser::ParticleContext* TsilParser::particle(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TsilParser::ParticleContext *_localctx = _tracker.createInstance<ParticleContext>(_ctx, parentState);
  TsilParser::ParticleContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 78;
  enterRecursionRule(_localctx, 78, TsilParser::RuleParticle, precedence);

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
    setState(469);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::ID: {
        _localctx = _tracker.createInstance<Particle_section_accessContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(464);
        section_access();
        break;
      }

      case TsilParser::PAREN_OPEN: {
        _localctx = _tracker.createInstance<NestedContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(465);
        match(TsilParser::PAREN_OPEN);
        setState(466);
        antlrcpp::downCast<NestedContext *>(_localctx)->n_value = expr();
        setState(467);
        match(TsilParser::PAREN_CLOSE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(500);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(498);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<GetContext>(_tracker.createInstance<ParticleContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->g_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleParticle);
          setState(471);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(472);
          match(TsilParser::DOT);
          setState(473);
          antlrcpp::downCast<GetContext *>(_localctx)->g_id = match(TsilParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<GenericContext>(_tracker.createInstance<ParticleContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->g_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleParticle);
          setState(474);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(475);
          match(TsilParser::LESSER);
          setState(476);
          antlrcpp::downCast<GenericContext *>(_localctx)->sa_generic_value = full_type(0);
          setState(481);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == TsilParser::COMA) {
            setState(477);
            match(TsilParser::COMA);
            setState(478);
            full_type(0);
            setState(483);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(484);
          match(TsilParser::GREATER);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AccessContext>(_tracker.createInstance<ParticleContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->a_value = previousContext;
          pushNewRecursionContext(newContext, startState, RuleParticle);
          setState(486);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(487);
          match(TsilParser::BRACKET_OPEN);
          setState(489);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 109251942907117568) != 0)) {
            setState(488);
            antlrcpp::downCast<AccessContext *>(_localctx)->a_index = expr();
          }
          setState(491);
          match(TsilParser::BRACKET_CLOSE);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CallContext>(_tracker.createInstance<ParticleContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->c_value = previousContext;
          pushNewRecursionContext(newContext, startState, RuleParticle);
          setState(492);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(493);
          match(TsilParser::PAREN_OPEN);
          setState(495);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 109251942907117568) != 0)) {
            setState(494);
            antlrcpp::downCast<CallContext *>(_localctx)->c_args = args();
          }
          setState(497);
          match(TsilParser::PAREN_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(502);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
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
  enterRule(_localctx, 80, TsilParser::RuleArgs);
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
    setState(503);
    expr();
    setState(508);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(504);
        match(TsilParser::COMA);
        setState(505);
        expr(); 
      }
      setState(510);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    }
    setState(512);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COMA) {
      setState(511);
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

//----------------- Atom_particleContext ------------------------------------------------------------------

TsilParser::ParticleContext* TsilParser::Atom_particleContext::particle() {
  return getRuleContext<TsilParser::ParticleContext>(0);
}

TsilParser::Atom_particleContext::Atom_particleContext(AtomContext *ctx) { copyFrom(ctx); }

void TsilParser::Atom_particleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_particle(this);
}
void TsilParser::Atom_particleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_particle(this);
}

std::any TsilParser::Atom_particleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAtom_particle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_numberContext ------------------------------------------------------------------

TsilParser::NumberContext* TsilParser::Atom_numberContext::number() {
  return getRuleContext<TsilParser::NumberContext>(0);
}

TsilParser::Atom_numberContext::Atom_numberContext(AtomContext *ctx) { copyFrom(ctx); }

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
//----------------- Atom_stringContext ------------------------------------------------------------------

TsilParser::StringContext* TsilParser::Atom_stringContext::string() {
  return getRuleContext<TsilParser::StringContext>(0);
}

TsilParser::Atom_stringContext::Atom_stringContext(AtomContext *ctx) { copyFrom(ctx); }

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
TsilParser::AtomContext* TsilParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 82, TsilParser::RuleAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(517);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TsilParser::Atom_particleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(514);
      particle(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TsilParser::Atom_numberContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(515);
      number();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<TsilParser::Atom_stringContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(516);
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

//----------------- Molecule_atomContext ------------------------------------------------------------------

TsilParser::AtomContext* TsilParser::Molecule_atomContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

TsilParser::Molecule_atomContext::Molecule_atomContext(MoleculeContext *ctx) { copyFrom(ctx); }

void TsilParser::Molecule_atomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMolecule_atom(this);
}
void TsilParser::Molecule_atomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMolecule_atom(this);
}

std::any TsilParser::Molecule_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitMolecule_atom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::NotContext::EXCLAMATION() {
  return getToken(TsilParser::EXCLAMATION, 0);
}

TsilParser::MoleculeContext* TsilParser::NotContext::molecule() {
  return getRuleContext<TsilParser::MoleculeContext>(0);
}

TsilParser::NotContext::NotContext(MoleculeContext *ctx) { copyFrom(ctx); }

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
//----------------- NegativeContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::NegativeContext::MINUS() {
  return getToken(TsilParser::MINUS, 0);
}

TsilParser::AtomContext* TsilParser::NegativeContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

TsilParser::NegativeContext::NegativeContext(MoleculeContext *ctx) { copyFrom(ctx); }

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
//----------------- Bitwise_notContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Bitwise_notContext::TILDA() {
  return getToken(TsilParser::TILDA, 0);
}

TsilParser::AtomContext* TsilParser::Bitwise_notContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

TsilParser::Bitwise_notContext::Bitwise_notContext(MoleculeContext *ctx) { copyFrom(ctx); }

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
//----------------- PositiveContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::PositiveContext::PLUS() {
  return getToken(TsilParser::PLUS, 0);
}

TsilParser::AtomContext* TsilParser::PositiveContext::atom() {
  return getRuleContext<TsilParser::AtomContext>(0);
}

TsilParser::PositiveContext::PositiveContext(MoleculeContext *ctx) { copyFrom(ctx); }

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
TsilParser::MoleculeContext* TsilParser::molecule() {
  MoleculeContext *_localctx = _tracker.createInstance<MoleculeContext>(_ctx, getState());
  enterRule(_localctx, 84, TsilParser::RuleMolecule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(528);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::PAREN_OPEN:
      case TsilParser::NUMBER:
      case TsilParser::ID:
      case TsilParser::STRING: {
        _localctx = _tracker.createInstance<TsilParser::Molecule_atomContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(519);
        atom();
        break;
      }

      case TsilParser::EXCLAMATION: {
        _localctx = _tracker.createInstance<TsilParser::NotContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(520);
        match(TsilParser::EXCLAMATION);
        setState(521);
        antlrcpp::downCast<NotContext *>(_localctx)->n_value = molecule();
        break;
      }

      case TsilParser::PLUS: {
        _localctx = _tracker.createInstance<TsilParser::PositiveContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(522);
        match(TsilParser::PLUS);
        setState(523);
        antlrcpp::downCast<PositiveContext *>(_localctx)->p_value = atom();
        break;
      }

      case TsilParser::MINUS: {
        _localctx = _tracker.createInstance<TsilParser::NegativeContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(524);
        match(TsilParser::MINUS);
        setState(525);
        antlrcpp::downCast<NegativeContext *>(_localctx)->n_value = atom();
        break;
      }

      case TsilParser::TILDA: {
        _localctx = _tracker.createInstance<TsilParser::Bitwise_notContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(526);
        match(TsilParser::TILDA);
        setState(527);
        antlrcpp::downCast<Bitwise_notContext *>(_localctx)->bn_value = atom();
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

//----------------- AddContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::AddContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::AddContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

tree::TerminalNode* TsilParser::AddContext::PLUS() {
  return getToken(TsilParser::PLUS, 0);
}

tree::TerminalNode* TsilParser::AddContext::MINUS() {
  return getToken(TsilParser::MINUS, 0);
}

TsilParser::AddContext::AddContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::AddContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdd(this);
}
void TsilParser::AddContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdd(this);
}

std::any TsilParser::AddContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitAdd(this);
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

TsilParser::AsContext::AsContext(OperationContext *ctx) { copyFrom(ctx); }

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
//----------------- ComparisonContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::ComparisonContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::ComparisonContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

TsilParser::Comparison_opContext* TsilParser::ComparisonContext::comparison_op() {
  return getRuleContext<TsilParser::Comparison_opContext>(0);
}

TsilParser::ComparisonContext::ComparisonContext(OperationContext *ctx) { copyFrom(ctx); }

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
//----------------- MulContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::MulContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::MulContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

tree::TerminalNode* TsilParser::MulContext::MULTIPLY() {
  return getToken(TsilParser::MULTIPLY, 0);
}

tree::TerminalNode* TsilParser::MulContext::DIVIDE() {
  return getToken(TsilParser::DIVIDE, 0);
}

tree::TerminalNode* TsilParser::MulContext::MOD() {
  return getToken(TsilParser::MOD, 0);
}

TsilParser::MulContext::MulContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::MulContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMul(this);
}
void TsilParser::MulContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMul(this);
}

std::any TsilParser::MulContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitMul(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::BitwiseContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::BitwiseContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

TsilParser::Bitwise_opContext* TsilParser::BitwiseContext::bitwise_op() {
  return getRuleContext<TsilParser::Bitwise_opContext>(0);
}

TsilParser::BitwiseContext::BitwiseContext(OperationContext *ctx) { copyFrom(ctx); }

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
//----------------- Operation_moleculeContext ------------------------------------------------------------------

TsilParser::MoleculeContext* TsilParser::Operation_moleculeContext::molecule() {
  return getRuleContext<TsilParser::MoleculeContext>(0);
}

TsilParser::Operation_moleculeContext::Operation_moleculeContext(OperationContext *ctx) { copyFrom(ctx); }

void TsilParser::Operation_moleculeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation_molecule(this);
}
void TsilParser::Operation_moleculeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation_molecule(this);
}

std::any TsilParser::Operation_moleculeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitOperation_molecule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalContext ------------------------------------------------------------------

std::vector<TsilParser::OperationContext *> TsilParser::LogicalContext::operation() {
  return getRuleContexts<TsilParser::OperationContext>();
}

TsilParser::OperationContext* TsilParser::LogicalContext::operation(size_t i) {
  return getRuleContext<TsilParser::OperationContext>(i);
}

TsilParser::Logical_opContext* TsilParser::LogicalContext::logical_op() {
  return getRuleContext<TsilParser::Logical_opContext>(0);
}

TsilParser::LogicalContext::LogicalContext(OperationContext *ctx) { copyFrom(ctx); }

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

TsilParser::OperationContext* TsilParser::operation() {
   return operation(0);
}

TsilParser::OperationContext* TsilParser::operation(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TsilParser::OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, parentState);
  TsilParser::OperationContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 86;
  enterRecursionRule(_localctx, 86, TsilParser::RuleOperation, precedence);

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
    setState(536);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Operation_moleculeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(531);
      molecule();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<AsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(532);
      antlrcpp::downCast<AsContext *>(_localctx)->a_left = molecule();
      setState(533);
      match(TsilParser::KW_AS);
      setState(534);
      antlrcpp::downCast<AsContext *>(_localctx)->a_type = full_type(0);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(558);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(556);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->a_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(538);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(539);
          antlrcpp::downCast<MulContext *>(_localctx)->a_operation = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 7516192768) != 0))) {
            antlrcpp::downCast<MulContext *>(_localctx)->a_operation = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(540);
          antlrcpp::downCast<MulContext *>(_localctx)->a_right = operation(6);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->a_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(541);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(542);
          antlrcpp::downCast<AddContext *>(_localctx)->a_operation = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == TsilParser::PLUS

          || _la == TsilParser::MINUS)) {
            antlrcpp::downCast<AddContext *>(_localctx)->a_operation = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(543);
          antlrcpp::downCast<AddContext *>(_localctx)->a_right = operation(5);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BitwiseContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->b_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(544);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(545);
          antlrcpp::downCast<BitwiseContext *>(_localctx)->b_operation = bitwise_op();
          setState(546);
          antlrcpp::downCast<BitwiseContext *>(_localctx)->b_right = operation(4);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ComparisonContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->c_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(548);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(549);
          antlrcpp::downCast<ComparisonContext *>(_localctx)->c_operation = comparison_op();
          setState(550);
          antlrcpp::downCast<ComparisonContext *>(_localctx)->c_right = operation(3);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<LogicalContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->t_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(552);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(553);
          antlrcpp::downCast<LogicalContext *>(_localctx)->t_operation = logical_op();
          setState(554);
          antlrcpp::downCast<LogicalContext *>(_localctx)->t_right = operation(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(560);
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
//----------------- ConstructContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::ConstructContext::QUOTE_OPEN() {
  return getToken(TsilParser::QUOTE_OPEN, 0);
}

tree::TerminalNode* TsilParser::ConstructContext::QUOTE_CLOSE() {
  return getToken(TsilParser::QUOTE_CLOSE, 0);
}

TsilParser::Full_typeContext* TsilParser::ConstructContext::full_type() {
  return getRuleContext<TsilParser::Full_typeContext>(0);
}

TsilParser::Construct_argsContext* TsilParser::ConstructContext::construct_args() {
  return getRuleContext<TsilParser::Construct_argsContext>(0);
}

TsilParser::ConstructContext::ConstructContext(ExprContext *ctx) { copyFrom(ctx); }

void TsilParser::ConstructContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstruct(this);
}
void TsilParser::ConstructContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstruct(this);
}

std::any TsilParser::ConstructContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitConstruct(this);
  else
    return visitor->visitChildren(this);
}
TsilParser::ExprContext* TsilParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 88, TsilParser::RuleExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(569);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TsilParser::ConstructContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(561);
      antlrcpp::downCast<ConstructContext *>(_localctx)->c_type = full_type(0);
      setState(562);
      match(TsilParser::QUOTE_OPEN);
      setState(564);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 109251942907117568) != 0)) {
        setState(563);
        antlrcpp::downCast<ConstructContext *>(_localctx)->c_args = construct_args();
      }
      setState(566);
      match(TsilParser::QUOTE_CLOSE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TsilParser::Expr_operationContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(568);
      operation(0);
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

//----------------- Construct_argsContext ------------------------------------------------------------------

TsilParser::Construct_argsContext::Construct_argsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TsilParser::Construct_argContext *> TsilParser::Construct_argsContext::construct_arg() {
  return getRuleContexts<TsilParser::Construct_argContext>();
}

TsilParser::Construct_argContext* TsilParser::Construct_argsContext::construct_arg(size_t i) {
  return getRuleContext<TsilParser::Construct_argContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Construct_argsContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Construct_argsContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::Construct_argsContext::getRuleIndex() const {
  return TsilParser::RuleConstruct_args;
}

void TsilParser::Construct_argsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstruct_args(this);
}

void TsilParser::Construct_argsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstruct_args(this);
}


std::any TsilParser::Construct_argsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitConstruct_args(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Construct_argsContext* TsilParser::construct_args() {
  Construct_argsContext *_localctx = _tracker.createInstance<Construct_argsContext>(_ctx, getState());
  enterRule(_localctx, 90, TsilParser::RuleConstruct_args);
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
    setState(571);
    construct_arg();
    setState(576);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(572);
        match(TsilParser::COMA);
        setState(573);
        construct_arg(); 
      }
      setState(578);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    }
    setState(580);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COMA) {
      setState(579);
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

//----------------- Construct_argContext ------------------------------------------------------------------

TsilParser::Construct_argContext::Construct_argContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TsilParser::ExprContext* TsilParser::Construct_argContext::expr() {
  return getRuleContext<TsilParser::ExprContext>(0);
}

tree::TerminalNode* TsilParser::Construct_argContext::EQUAL() {
  return getToken(TsilParser::EQUAL, 0);
}

tree::TerminalNode* TsilParser::Construct_argContext::ID() {
  return getToken(TsilParser::ID, 0);
}


size_t TsilParser::Construct_argContext::getRuleIndex() const {
  return TsilParser::RuleConstruct_arg;
}

void TsilParser::Construct_argContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstruct_arg(this);
}

void TsilParser::Construct_argContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstruct_arg(this);
}


std::any TsilParser::Construct_argContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitConstruct_arg(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Construct_argContext* TsilParser::construct_arg() {
  Construct_argContext *_localctx = _tracker.createInstance<Construct_argContext>(_ctx, getState());
  enterRule(_localctx, 92, TsilParser::RuleConstruct_arg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(584);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
    case 1: {
      setState(582);
      antlrcpp::downCast<Construct_argContext *>(_localctx)->ca_name = match(TsilParser::ID);
      setState(583);
      match(TsilParser::EQUAL);
      break;
    }

    default:
      break;
    }
    setState(586);
    antlrcpp::downCast<Construct_argContext *>(_localctx)->ca_value = expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Basic_typeContext ------------------------------------------------------------------

TsilParser::Basic_typeContext::Basic_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TsilParser::Basic_typeContext::getRuleIndex() const {
  return TsilParser::RuleBasic_type;
}

void TsilParser::Basic_typeContext::copyFrom(Basic_typeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Simple_typeContext ------------------------------------------------------------------

TsilParser::Section_accessContext* TsilParser::Simple_typeContext::section_access() {
  return getRuleContext<TsilParser::Section_accessContext>(0);
}

tree::TerminalNode* TsilParser::Simple_typeContext::LESSER() {
  return getToken(TsilParser::LESSER, 0);
}

tree::TerminalNode* TsilParser::Simple_typeContext::GREATER() {
  return getToken(TsilParser::GREATER, 0);
}

std::vector<TsilParser::Full_typeContext *> TsilParser::Simple_typeContext::full_type() {
  return getRuleContexts<TsilParser::Full_typeContext>();
}

TsilParser::Full_typeContext* TsilParser::Simple_typeContext::full_type(size_t i) {
  return getRuleContext<TsilParser::Full_typeContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Simple_typeContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Simple_typeContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}

TsilParser::Simple_typeContext::Simple_typeContext(Basic_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Simple_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_type(this);
}
void TsilParser::Simple_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_type(this);
}

std::any TsilParser::Simple_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitSimple_type(this);
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

TsilParser::Basic_typeContext* TsilParser::Array_typeContext::basic_type() {
  return getRuleContext<TsilParser::Basic_typeContext>(0);
}

tree::TerminalNode* TsilParser::Array_typeContext::NUMBER() {
  return getToken(TsilParser::NUMBER, 0);
}

TsilParser::Array_typeContext::Array_typeContext(Basic_typeContext *ctx) { copyFrom(ctx); }

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
//----------------- Full_type_nestedContext ------------------------------------------------------------------

tree::TerminalNode* TsilParser::Full_type_nestedContext::PAREN_OPEN() {
  return getToken(TsilParser::PAREN_OPEN, 0);
}

TsilParser::Full_typeContext* TsilParser::Full_type_nestedContext::full_type() {
  return getRuleContext<TsilParser::Full_typeContext>(0);
}

tree::TerminalNode* TsilParser::Full_type_nestedContext::PAREN_CLOSE() {
  return getToken(TsilParser::PAREN_CLOSE, 0);
}

TsilParser::Full_type_nestedContext::Full_type_nestedContext(Basic_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Full_type_nestedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFull_type_nested(this);
}
void TsilParser::Full_type_nestedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFull_type_nested(this);
}

std::any TsilParser::Full_type_nestedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitFull_type_nested(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Basic_typeContext* TsilParser::basic_type() {
   return basic_type(0);
}

TsilParser::Basic_typeContext* TsilParser::basic_type(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TsilParser::Basic_typeContext *_localctx = _tracker.createInstance<Basic_typeContext>(_ctx, parentState);
  TsilParser::Basic_typeContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 94;
  enterRecursionRule(_localctx, 94, TsilParser::RuleBasic_type, precedence);

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
    setState(607);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::ID: {
        _localctx = _tracker.createInstance<Simple_typeContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(589);
        section_access();
        setState(601);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
        case 1: {
          setState(590);
          match(TsilParser::LESSER);
          setState(591);
          antlrcpp::downCast<Simple_typeContext *>(_localctx)->t_first_generic_type = full_type(0);
          setState(596);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == TsilParser::COMA) {
            setState(592);
            match(TsilParser::COMA);
            setState(593);
            full_type(0);
            setState(598);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(599);
          match(TsilParser::GREATER);
          break;
        }

        default:
          break;
        }
        break;
      }

      case TsilParser::PAREN_OPEN: {
        _localctx = _tracker.createInstance<Full_type_nestedContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(603);
        match(TsilParser::PAREN_OPEN);
        setState(604);
        full_type(0);
        setState(605);
        match(TsilParser::PAREN_CLOSE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(615);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Array_typeContext>(_tracker.createInstance<Basic_typeContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->at_type = previousContext;
        pushNewRecursionContext(newContext, startState, RuleBasic_type);
        setState(609);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(610);
        match(TsilParser::BRACKET_OPEN);
        setState(611);
        antlrcpp::downCast<Array_typeContext *>(_localctx)->at_size = match(TsilParser::NUMBER);
        setState(612);
        match(TsilParser::BRACKET_CLOSE); 
      }
      setState(617);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
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
//----------------- Basic_type_real_basicContext ------------------------------------------------------------------

TsilParser::Basic_typeContext* TsilParser::Basic_type_real_basicContext::basic_type() {
  return getRuleContext<TsilParser::Basic_typeContext>(0);
}

TsilParser::Basic_type_real_basicContext::Basic_type_real_basicContext(Full_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Basic_type_real_basicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasic_type_real_basic(this);
}
void TsilParser::Basic_type_real_basicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasic_type_real_basic(this);
}

std::any TsilParser::Basic_type_real_basicContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitBasic_type_real_basic(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Variation_typeContext ------------------------------------------------------------------

std::vector<TsilParser::Basic_typeContext *> TsilParser::Variation_typeContext::basic_type() {
  return getRuleContexts<TsilParser::Basic_typeContext>();
}

TsilParser::Basic_typeContext* TsilParser::Variation_typeContext::basic_type(size_t i) {
  return getRuleContext<TsilParser::Basic_typeContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Variation_typeContext::OR() {
  return getTokens(TsilParser::OR);
}

tree::TerminalNode* TsilParser::Variation_typeContext::OR(size_t i) {
  return getToken(TsilParser::OR, i);
}

TsilParser::Variation_typeContext::Variation_typeContext(Full_typeContext *ctx) { copyFrom(ctx); }

void TsilParser::Variation_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariation_type(this);
}
void TsilParser::Variation_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariation_type(this);
}

std::any TsilParser::Variation_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitVariation_type(this);
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

TsilParser::Complex_function_type_argsContext* TsilParser::Complex_function_typeContext::complex_function_type_args() {
  return getRuleContext<TsilParser::Complex_function_type_argsContext>(0);
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

TsilParser::Full_typeContext* TsilParser::full_type() {
   return full_type(0);
}

TsilParser::Full_typeContext* TsilParser::full_type(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TsilParser::Full_typeContext *_localctx = _tracker.createInstance<Full_typeContext>(_ctx, parentState);
  TsilParser::Full_typeContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 96;
  enterRecursionRule(_localctx, 96, TsilParser::RuleFull_type, precedence);

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
    setState(635);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Variation_typeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(619);
      basic_type(0);
      setState(622); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(620);
                match(TsilParser::OR);
                setState(621);
                basic_type(0);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(624); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Basic_type_real_basicContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(626);
      basic_type(0);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Complex_function_typeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(627);
      match(TsilParser::PAREN_OPEN);
      setState(629);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TsilParser::PAREN_OPEN

      || _la == TsilParser::ID) {
        setState(628);
        antlrcpp::downCast<Complex_function_typeContext *>(_localctx)->cft_args = complex_function_type_args();
      }
      setState(631);
      match(TsilParser::PAREN_CLOSE);
      setState(632);
      match(TsilParser::MINUS);
      setState(633);
      match(TsilParser::GREATER);
      setState(634);
      antlrcpp::downCast<Complex_function_typeContext *>(_localctx)->cft_ret = full_type(2);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(643);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Simple_function_typeContext>(_tracker.createInstance<Full_typeContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->sft_arg = previousContext;
        pushNewRecursionContext(newContext, startState, RuleFull_type);
        setState(637);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(638);
        match(TsilParser::MINUS);
        setState(639);
        match(TsilParser::GREATER);
        setState(640);
        antlrcpp::downCast<Simple_function_typeContext *>(_localctx)->sft_ret = full_type(2); 
      }
      setState(645);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Complex_function_type_argsContext ------------------------------------------------------------------

TsilParser::Complex_function_type_argsContext::Complex_function_type_argsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TsilParser::Full_typeContext *> TsilParser::Complex_function_type_argsContext::full_type() {
  return getRuleContexts<TsilParser::Full_typeContext>();
}

TsilParser::Full_typeContext* TsilParser::Complex_function_type_argsContext::full_type(size_t i) {
  return getRuleContext<TsilParser::Full_typeContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Complex_function_type_argsContext::COMA() {
  return getTokens(TsilParser::COMA);
}

tree::TerminalNode* TsilParser::Complex_function_type_argsContext::COMA(size_t i) {
  return getToken(TsilParser::COMA, i);
}


size_t TsilParser::Complex_function_type_argsContext::getRuleIndex() const {
  return TsilParser::RuleComplex_function_type_args;
}

void TsilParser::Complex_function_type_argsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComplex_function_type_args(this);
}

void TsilParser::Complex_function_type_argsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TsilParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComplex_function_type_args(this);
}


std::any TsilParser::Complex_function_type_argsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TsilParserVisitor*>(visitor))
    return parserVisitor->visitComplex_function_type_args(this);
  else
    return visitor->visitChildren(this);
}

TsilParser::Complex_function_type_argsContext* TsilParser::complex_function_type_args() {
  Complex_function_type_argsContext *_localctx = _tracker.createInstance<Complex_function_type_argsContext>(_ctx, getState());
  enterRule(_localctx, 98, TsilParser::RuleComplex_function_type_args);
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
    setState(646);
    full_type(0);
    setState(651);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TsilParser::COMA) {
      setState(647);
      match(TsilParser::COMA);
      setState(648);
      full_type(0);
      setState(653);
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
  enterRule(_localctx, 100, TsilParser::RuleBitwise_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(661);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::POWER: {
        enterOuterAlt(_localctx, 1);
        setState(654);
        match(TsilParser::POWER);
        break;
      }

      case TsilParser::OR: {
        enterOuterAlt(_localctx, 2);
        setState(655);
        match(TsilParser::OR);
        break;
      }

      case TsilParser::AND: {
        enterOuterAlt(_localctx, 3);
        setState(656);
        match(TsilParser::AND);
        break;
      }

      case TsilParser::LESSER: {
        enterOuterAlt(_localctx, 4);
        setState(657);
        match(TsilParser::LESSER);
        setState(658);
        match(TsilParser::LESSER);
        break;
      }

      case TsilParser::GREATER: {
        enterOuterAlt(_localctx, 5);
        setState(659);
        match(TsilParser::GREATER);
        setState(660);
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
  enterRule(_localctx, 102, TsilParser::RuleComparison_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(673);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(663);
      match(TsilParser::EQUAL);
      setState(664);
      match(TsilParser::EQUAL);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(665);
      match(TsilParser::EXCLAMATION);
      setState(666);
      match(TsilParser::EQUAL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(667);
      match(TsilParser::GREATER);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(668);
      match(TsilParser::LESSER);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(669);
      match(TsilParser::GREATER);
      setState(670);
      match(TsilParser::EQUAL);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(671);
      match(TsilParser::LESSER);
      setState(672);
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
  enterRule(_localctx, 104, TsilParser::RuleLogical_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(681);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::OR: {
        enterOuterAlt(_localctx, 1);
        setState(675);
        match(TsilParser::OR);
        setState(676);
        match(TsilParser::OR);
        break;
      }

      case TsilParser::AND: {
        enterOuterAlt(_localctx, 2);
        setState(677);
        match(TsilParser::AND);
        setState(678);
        match(TsilParser::AND);
        break;
      }

      case TsilParser::KW_OR: {
        enterOuterAlt(_localctx, 3);
        setState(679);
        match(TsilParser::KW_OR);
        break;
      }

      case TsilParser::KW_AND: {
        enterOuterAlt(_localctx, 4);
        setState(680);
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

bool TsilParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 39: return particleSempred(antlrcpp::downCast<ParticleContext *>(context), predicateIndex);
    case 43: return operationSempred(antlrcpp::downCast<OperationContext *>(context), predicateIndex);
    case 47: return basic_typeSempred(antlrcpp::downCast<Basic_typeContext *>(context), predicateIndex);
    case 48: return full_typeSempred(antlrcpp::downCast<Full_typeContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TsilParser::particleSempred(ParticleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);
    case 3: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool TsilParser::operationSempred(OperationContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 5);
    case 5: return precpred(_ctx, 4);
    case 6: return precpred(_ctx, 3);
    case 7: return precpred(_ctx, 2);
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool TsilParser::basic_typeSempred(Basic_typeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool TsilParser::full_typeSempred(Full_typeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
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
