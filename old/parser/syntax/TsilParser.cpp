
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
  	4,1,60,697,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,1,0,1,0,1,0,1,1,5,1,111,8,1,10,1,12,
  	1,114,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,3,2,133,8,2,1,3,1,3,1,4,1,4,1,4,1,4,5,4,141,8,4,10,4,12,4,144,
  	9,4,1,5,1,5,1,5,3,5,149,8,5,1,6,3,6,152,8,6,1,6,1,6,1,7,1,7,1,7,1,7,3,
  	7,160,8,7,1,8,1,8,3,8,164,8,8,1,8,1,8,1,8,5,8,169,8,8,10,8,12,8,172,9,
  	8,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,3,10,182,8,10,1,11,1,11,1,11,1,11,
  	5,11,188,8,11,10,11,12,11,191,9,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,209,8,12,1,13,1,13,
  	1,13,1,13,1,13,1,13,3,13,217,8,13,1,13,1,13,3,13,221,8,13,1,13,1,13,3,
  	13,225,8,13,1,14,1,14,1,14,5,14,230,8,14,10,14,12,14,233,9,14,1,15,1,
  	15,1,16,1,16,1,16,4,16,240,8,16,11,16,12,16,241,1,17,1,17,1,17,1,17,1,
  	18,1,18,1,18,1,18,3,18,252,8,18,1,18,1,18,3,18,256,8,18,1,18,1,18,3,18,
  	260,8,18,1,19,1,19,1,19,4,19,265,8,19,11,19,12,19,266,1,20,1,20,1,20,
  	1,20,1,21,1,21,1,21,1,21,1,21,1,21,3,21,279,8,21,1,21,1,21,3,21,283,8,
  	21,1,21,1,21,1,21,1,21,3,21,289,8,21,1,21,1,21,1,21,3,21,294,8,21,1,22,
  	1,22,1,22,3,22,299,8,22,1,22,1,22,1,22,3,22,304,8,22,1,22,1,22,1,23,1,
  	23,1,23,5,23,311,8,23,10,23,12,23,314,9,23,1,24,1,24,1,25,1,25,1,25,3,
  	25,321,8,25,1,25,1,25,1,25,3,25,326,8,25,1,25,1,25,1,26,1,26,1,26,5,26,
  	333,8,26,10,26,12,26,336,9,26,1,26,3,26,339,8,26,1,27,1,27,1,27,1,27,
  	1,28,4,28,346,8,28,11,28,12,28,347,1,29,1,29,1,29,1,29,1,29,1,29,1,29,
  	1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,
  	1,29,1,29,1,29,1,29,1,29,1,29,1,29,3,29,378,8,29,1,30,1,30,3,30,382,8,
  	30,1,31,1,31,1,31,1,31,1,32,1,32,1,32,1,32,3,32,392,8,32,1,33,1,33,1,
  	33,1,33,3,33,398,8,33,1,33,1,33,1,33,1,33,3,33,404,8,33,1,33,1,33,3,33,
  	408,8,33,3,33,410,8,33,1,34,1,34,1,34,1,34,3,34,416,8,34,1,34,1,34,1,
  	35,1,35,1,35,3,35,423,8,35,1,35,1,35,3,35,427,8,35,1,35,1,35,1,35,1,35,
  	1,36,1,36,1,36,3,36,436,8,36,1,36,1,36,3,36,440,8,36,1,36,1,36,1,36,3,
  	36,445,8,36,1,36,1,36,1,36,1,37,1,37,1,37,1,37,1,38,1,38,1,38,1,38,1,
  	38,1,38,1,38,3,38,461,8,38,1,38,1,38,1,38,1,39,1,39,1,39,1,39,1,39,1,
  	39,3,39,472,8,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,5,39,482,8,39,
  	10,39,12,39,485,9,39,1,39,1,39,1,39,1,39,1,39,3,39,492,8,39,1,39,1,39,
  	1,39,1,39,3,39,498,8,39,1,39,5,39,501,8,39,10,39,12,39,504,9,39,1,40,
  	1,40,1,40,5,40,509,8,40,10,40,12,40,512,9,40,1,40,3,40,515,8,40,1,41,
  	1,41,1,41,3,41,520,8,41,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,
  	3,42,531,8,42,1,43,1,43,1,43,1,43,1,43,1,43,3,43,539,8,43,1,43,1,43,1,
  	43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,
  	43,1,43,5,43,559,8,43,10,43,12,43,562,9,43,1,44,1,44,1,44,3,44,567,8,
  	44,1,44,1,44,1,44,3,44,572,8,44,1,45,1,45,1,45,5,45,577,8,45,10,45,12,
  	45,580,9,45,1,45,3,45,583,8,45,1,46,1,46,3,46,587,8,46,1,46,1,46,1,47,
  	1,47,1,47,1,47,1,47,1,47,5,47,597,8,47,10,47,12,47,600,9,47,1,47,1,47,
  	3,47,604,8,47,1,47,1,47,1,47,1,47,3,47,610,8,47,1,47,1,47,1,47,1,47,5,
  	47,616,8,47,10,47,12,47,619,9,47,1,48,1,48,1,48,1,48,4,48,625,8,48,11,
  	48,12,48,626,1,48,1,48,1,48,3,48,632,8,48,1,48,1,48,1,48,1,48,3,48,638,
  	8,48,1,48,1,48,1,48,1,48,5,48,644,8,48,10,48,12,48,647,9,48,1,49,1,49,
  	1,49,3,49,652,8,49,1,49,1,49,1,49,1,49,1,49,1,49,3,49,660,8,49,1,49,5,
  	49,663,8,49,10,49,12,49,666,9,49,1,50,1,50,1,50,1,50,1,50,1,50,1,50,3,
  	50,675,8,50,1,51,1,51,1,51,1,51,1,51,1,51,1,51,1,51,1,51,1,51,3,51,687,
  	8,51,1,52,1,52,1,52,1,52,1,52,1,52,3,52,695,8,52,1,52,0,4,78,86,94,96,
  	53,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,
  	48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,
  	94,96,98,100,102,104,0,2,1,0,30,32,1,0,28,29,773,0,106,1,0,0,0,2,112,
  	1,0,0,0,4,132,1,0,0,0,6,134,1,0,0,0,8,136,1,0,0,0,10,145,1,0,0,0,12,151,
  	1,0,0,0,14,155,1,0,0,0,16,163,1,0,0,0,18,173,1,0,0,0,20,181,1,0,0,0,22,
  	183,1,0,0,0,24,208,1,0,0,0,26,210,1,0,0,0,28,226,1,0,0,0,30,234,1,0,0,
  	0,32,239,1,0,0,0,34,243,1,0,0,0,36,247,1,0,0,0,38,264,1,0,0,0,40,268,
  	1,0,0,0,42,272,1,0,0,0,44,298,1,0,0,0,46,307,1,0,0,0,48,315,1,0,0,0,50,
  	320,1,0,0,0,52,329,1,0,0,0,54,340,1,0,0,0,56,345,1,0,0,0,58,377,1,0,0,
  	0,60,379,1,0,0,0,62,383,1,0,0,0,64,387,1,0,0,0,66,393,1,0,0,0,68,411,
  	1,0,0,0,70,422,1,0,0,0,72,435,1,0,0,0,74,449,1,0,0,0,76,453,1,0,0,0,78,
  	471,1,0,0,0,80,505,1,0,0,0,82,519,1,0,0,0,84,530,1,0,0,0,86,538,1,0,0,
  	0,88,571,1,0,0,0,90,573,1,0,0,0,92,586,1,0,0,0,94,609,1,0,0,0,96,637,
  	1,0,0,0,98,651,1,0,0,0,100,674,1,0,0,0,102,686,1,0,0,0,104,694,1,0,0,
  	0,106,107,3,2,1,0,107,108,5,0,0,1,108,1,1,0,0,0,109,111,3,4,2,0,110,109,
  	1,0,0,0,111,114,1,0,0,0,112,110,1,0,0,0,112,113,1,0,0,0,113,3,1,0,0,0,
  	114,112,1,0,0,0,115,116,3,14,7,0,116,117,5,47,0,0,117,133,1,0,0,0,118,
  	119,3,18,9,0,119,120,5,47,0,0,120,133,1,0,0,0,121,122,3,70,35,0,122,123,
  	5,47,0,0,123,133,1,0,0,0,124,125,3,72,36,0,125,126,5,47,0,0,126,133,1,
  	0,0,0,127,133,3,22,11,0,128,133,3,26,13,0,129,133,3,50,25,0,130,133,3,
  	44,22,0,131,133,5,47,0,0,132,115,1,0,0,0,132,118,1,0,0,0,132,121,1,0,
  	0,0,132,124,1,0,0,0,132,127,1,0,0,0,132,128,1,0,0,0,132,129,1,0,0,0,132,
  	130,1,0,0,0,132,131,1,0,0,0,133,5,1,0,0,0,134,135,5,55,0,0,135,7,1,0,
  	0,0,136,142,3,6,3,0,137,138,5,41,0,0,138,139,5,41,0,0,139,141,3,6,3,0,
  	140,137,1,0,0,0,141,144,1,0,0,0,142,140,1,0,0,0,142,143,1,0,0,0,143,9,
  	1,0,0,0,144,142,1,0,0,0,145,148,5,50,0,0,146,147,5,41,0,0,147,149,3,6,
  	3,0,148,146,1,0,0,0,148,149,1,0,0,0,149,11,1,0,0,0,150,152,5,55,0,0,151,
  	150,1,0,0,0,151,152,1,0,0,0,152,153,1,0,0,0,153,154,5,56,0,0,154,13,1,
  	0,0,0,155,156,5,12,0,0,156,159,5,55,0,0,157,160,5,56,0,0,158,160,3,16,
  	8,0,159,157,1,0,0,0,159,158,1,0,0,0,160,15,1,0,0,0,161,162,5,27,0,0,162,
  	164,5,31,0,0,163,161,1,0,0,0,163,164,1,0,0,0,164,165,1,0,0,0,165,170,
  	5,55,0,0,166,167,5,31,0,0,167,169,5,55,0,0,168,166,1,0,0,0,169,172,1,
  	0,0,0,170,168,1,0,0,0,170,171,1,0,0,0,171,17,1,0,0,0,172,170,1,0,0,0,
  	173,174,5,23,0,0,174,175,5,55,0,0,175,176,5,24,0,0,176,177,3,20,10,0,
  	177,19,1,0,0,0,178,182,3,96,48,0,179,182,3,10,5,0,180,182,3,12,6,0,181,
  	178,1,0,0,0,181,179,1,0,0,0,181,180,1,0,0,0,182,21,1,0,0,0,183,184,5,
  	11,0,0,184,185,5,55,0,0,185,189,5,48,0,0,186,188,3,24,12,0,187,186,1,
  	0,0,0,188,191,1,0,0,0,189,187,1,0,0,0,189,190,1,0,0,0,190,192,1,0,0,0,
  	191,189,1,0,0,0,192,193,5,49,0,0,193,23,1,0,0,0,194,195,3,18,9,0,195,
  	196,5,47,0,0,196,209,1,0,0,0,197,198,3,70,35,0,198,199,5,47,0,0,199,209,
  	1,0,0,0,200,201,3,72,36,0,201,202,5,47,0,0,202,209,1,0,0,0,203,209,3,
  	22,11,0,204,209,3,26,13,0,205,209,3,50,25,0,206,209,3,44,22,0,207,209,
  	5,47,0,0,208,194,1,0,0,0,208,197,1,0,0,0,208,200,1,0,0,0,208,203,1,0,
  	0,0,208,204,1,0,0,0,208,205,1,0,0,0,208,206,1,0,0,0,208,207,1,0,0,0,209,
  	25,1,0,0,0,210,211,5,8,0,0,211,216,5,55,0,0,212,213,5,26,0,0,213,214,
  	3,28,14,0,214,215,5,25,0,0,215,217,1,0,0,0,216,212,1,0,0,0,216,217,1,
  	0,0,0,217,224,1,0,0,0,218,220,5,48,0,0,219,221,3,32,16,0,220,219,1,0,
  	0,0,220,221,1,0,0,0,221,222,1,0,0,0,222,225,5,49,0,0,223,225,5,47,0,0,
  	224,218,1,0,0,0,224,223,1,0,0,0,225,27,1,0,0,0,226,231,3,30,15,0,227,
  	228,5,46,0,0,228,230,3,30,15,0,229,227,1,0,0,0,230,233,1,0,0,0,231,229,
  	1,0,0,0,231,232,1,0,0,0,232,29,1,0,0,0,233,231,1,0,0,0,234,235,5,55,0,
  	0,235,31,1,0,0,0,236,237,3,34,17,0,237,238,5,47,0,0,238,240,1,0,0,0,239,
  	236,1,0,0,0,240,241,1,0,0,0,241,239,1,0,0,0,241,242,1,0,0,0,242,33,1,
  	0,0,0,243,244,5,55,0,0,244,245,5,41,0,0,245,246,3,96,48,0,246,35,1,0,
  	0,0,247,248,5,9,0,0,248,251,5,55,0,0,249,250,5,41,0,0,250,252,3,96,48,
  	0,251,249,1,0,0,0,251,252,1,0,0,0,252,259,1,0,0,0,253,255,5,48,0,0,254,
  	256,3,38,19,0,255,254,1,0,0,0,255,256,1,0,0,0,256,257,1,0,0,0,257,260,
  	5,49,0,0,258,260,5,47,0,0,259,253,1,0,0,0,259,258,1,0,0,0,260,37,1,0,
  	0,0,261,262,3,40,20,0,262,263,5,47,0,0,263,265,1,0,0,0,264,261,1,0,0,
  	0,265,266,1,0,0,0,266,264,1,0,0,0,266,267,1,0,0,0,267,39,1,0,0,0,268,
  	269,5,55,0,0,269,270,5,41,0,0,270,271,3,96,48,0,271,41,1,0,0,0,272,273,
  	5,2,0,0,273,278,5,55,0,0,274,275,5,26,0,0,275,276,3,46,23,0,276,277,5,
  	25,0,0,277,279,1,0,0,0,278,274,1,0,0,0,278,279,1,0,0,0,279,280,1,0,0,
  	0,280,282,5,36,0,0,281,283,3,52,26,0,282,281,1,0,0,0,282,283,1,0,0,0,
  	283,288,1,0,0,0,284,285,5,46,0,0,285,286,5,27,0,0,286,287,5,27,0,0,287,
  	289,5,27,0,0,288,284,1,0,0,0,288,289,1,0,0,0,289,290,1,0,0,0,290,293,
  	5,37,0,0,291,292,5,41,0,0,292,294,3,96,48,0,293,291,1,0,0,0,293,294,1,
  	0,0,0,294,43,1,0,0,0,295,299,5,16,0,0,296,299,5,18,0,0,297,299,5,17,0,
  	0,298,295,1,0,0,0,298,296,1,0,0,0,298,297,1,0,0,0,298,299,1,0,0,0,299,
  	300,1,0,0,0,300,301,3,42,21,0,301,303,5,48,0,0,302,304,3,56,28,0,303,
  	302,1,0,0,0,303,304,1,0,0,0,304,305,1,0,0,0,305,306,5,49,0,0,306,45,1,
  	0,0,0,307,312,3,48,24,0,308,309,5,46,0,0,309,311,3,48,24,0,310,308,1,
  	0,0,0,311,314,1,0,0,0,312,310,1,0,0,0,312,313,1,0,0,0,313,47,1,0,0,0,
  	314,312,1,0,0,0,315,316,5,55,0,0,316,49,1,0,0,0,317,321,5,16,0,0,318,
  	321,5,18,0,0,319,321,5,17,0,0,320,317,1,0,0,0,320,318,1,0,0,0,320,319,
  	1,0,0,0,320,321,1,0,0,0,321,322,1,0,0,0,322,325,3,42,21,0,323,324,5,10,
  	0,0,324,326,5,55,0,0,325,323,1,0,0,0,325,326,1,0,0,0,326,327,1,0,0,0,
  	327,328,5,47,0,0,328,51,1,0,0,0,329,334,3,54,27,0,330,331,5,46,0,0,331,
  	333,3,54,27,0,332,330,1,0,0,0,333,336,1,0,0,0,334,332,1,0,0,0,334,335,
  	1,0,0,0,335,338,1,0,0,0,336,334,1,0,0,0,337,339,5,46,0,0,338,337,1,0,
  	0,0,338,339,1,0,0,0,339,53,1,0,0,0,340,341,5,55,0,0,341,342,5,41,0,0,
  	342,343,3,96,48,0,343,55,1,0,0,0,344,346,3,58,29,0,345,344,1,0,0,0,346,
  	347,1,0,0,0,347,345,1,0,0,0,347,348,1,0,0,0,348,57,1,0,0,0,349,378,3,
  	66,33,0,350,378,3,68,34,0,351,352,3,18,9,0,352,353,5,47,0,0,353,378,1,
  	0,0,0,354,355,3,70,35,0,355,356,5,47,0,0,356,378,1,0,0,0,357,358,3,72,
  	36,0,358,359,5,47,0,0,359,378,1,0,0,0,360,361,3,74,37,0,361,362,5,47,
  	0,0,362,378,1,0,0,0,363,364,3,76,38,0,364,365,5,47,0,0,365,378,1,0,0,
  	0,366,367,3,88,44,0,367,368,5,47,0,0,368,378,1,0,0,0,369,370,3,60,30,
  	0,370,371,5,47,0,0,371,378,1,0,0,0,372,373,3,64,32,0,373,374,5,47,0,0,
  	374,378,1,0,0,0,375,378,3,62,31,0,376,378,5,47,0,0,377,349,1,0,0,0,377,
  	350,1,0,0,0,377,351,1,0,0,0,377,354,1,0,0,0,377,357,1,0,0,0,377,360,1,
  	0,0,0,377,363,1,0,0,0,377,366,1,0,0,0,377,369,1,0,0,0,377,372,1,0,0,0,
  	377,375,1,0,0,0,377,376,1,0,0,0,378,59,1,0,0,0,379,381,5,6,0,0,380,382,
  	3,88,44,0,381,380,1,0,0,0,381,382,1,0,0,0,382,61,1,0,0,0,383,384,5,48,
  	0,0,384,385,3,56,28,0,385,386,5,49,0,0,386,63,1,0,0,0,387,391,5,7,0,0,
  	388,392,3,74,37,0,389,392,3,76,38,0,390,392,3,88,44,0,391,388,1,0,0,0,
  	391,389,1,0,0,0,391,390,1,0,0,0,392,65,1,0,0,0,393,394,5,3,0,0,394,395,
  	3,88,44,0,395,397,5,48,0,0,396,398,3,56,28,0,397,396,1,0,0,0,397,398,
  	1,0,0,0,398,399,1,0,0,0,399,409,5,49,0,0,400,407,5,4,0,0,401,403,5,48,
  	0,0,402,404,3,56,28,0,403,402,1,0,0,0,403,404,1,0,0,0,404,405,1,0,0,0,
  	405,408,5,49,0,0,406,408,3,66,33,0,407,401,1,0,0,0,407,406,1,0,0,0,408,
  	410,1,0,0,0,409,400,1,0,0,0,409,410,1,0,0,0,410,67,1,0,0,0,411,412,5,
  	5,0,0,412,413,3,88,44,0,413,415,5,48,0,0,414,416,3,56,28,0,415,414,1,
  	0,0,0,415,416,1,0,0,0,416,417,1,0,0,0,417,418,5,49,0,0,418,69,1,0,0,0,
  	419,423,5,16,0,0,420,423,5,18,0,0,421,423,5,17,0,0,422,419,1,0,0,0,422,
  	420,1,0,0,0,422,421,1,0,0,0,422,423,1,0,0,0,423,426,1,0,0,0,424,427,5,
  	1,0,0,425,427,5,22,0,0,426,424,1,0,0,0,426,425,1,0,0,0,427,428,1,0,0,
  	0,428,429,5,55,0,0,429,430,5,41,0,0,430,431,3,96,48,0,431,71,1,0,0,0,
  	432,436,5,16,0,0,433,436,5,18,0,0,434,436,5,17,0,0,435,432,1,0,0,0,435,
  	433,1,0,0,0,435,434,1,0,0,0,435,436,1,0,0,0,436,439,1,0,0,0,437,440,5,
  	1,0,0,438,440,5,22,0,0,439,437,1,0,0,0,439,438,1,0,0,0,440,441,1,0,0,
  	0,441,444,5,55,0,0,442,443,5,41,0,0,443,445,3,96,48,0,444,442,1,0,0,0,
  	444,445,1,0,0,0,445,446,1,0,0,0,446,447,5,24,0,0,447,448,3,88,44,0,448,
  	73,1,0,0,0,449,450,5,55,0,0,450,451,5,24,0,0,451,452,3,88,44,0,452,75,
  	1,0,0,0,453,460,3,78,39,0,454,455,5,27,0,0,455,461,5,55,0,0,456,457,5,
  	38,0,0,457,458,3,88,44,0,458,459,5,39,0,0,459,461,1,0,0,0,460,454,1,0,
  	0,0,460,456,1,0,0,0,461,462,1,0,0,0,462,463,5,24,0,0,463,464,3,88,44,
  	0,464,77,1,0,0,0,465,466,6,39,-1,0,466,472,3,8,4,0,467,468,5,36,0,0,468,
  	469,3,88,44,0,469,470,5,37,0,0,470,472,1,0,0,0,471,465,1,0,0,0,471,467,
  	1,0,0,0,472,502,1,0,0,0,473,474,10,5,0,0,474,475,5,27,0,0,475,501,5,55,
  	0,0,476,477,10,4,0,0,477,478,5,26,0,0,478,483,3,96,48,0,479,480,5,46,
  	0,0,480,482,3,96,48,0,481,479,1,0,0,0,482,485,1,0,0,0,483,481,1,0,0,0,
  	483,484,1,0,0,0,484,486,1,0,0,0,485,483,1,0,0,0,486,487,5,25,0,0,487,
  	501,1,0,0,0,488,489,10,3,0,0,489,491,5,38,0,0,490,492,3,88,44,0,491,490,
  	1,0,0,0,491,492,1,0,0,0,492,493,1,0,0,0,493,501,5,39,0,0,494,495,10,2,
  	0,0,495,497,5,36,0,0,496,498,3,80,40,0,497,496,1,0,0,0,497,498,1,0,0,
  	0,498,499,1,0,0,0,499,501,5,37,0,0,500,473,1,0,0,0,500,476,1,0,0,0,500,
  	488,1,0,0,0,500,494,1,0,0,0,501,504,1,0,0,0,502,500,1,0,0,0,502,503,1,
  	0,0,0,503,79,1,0,0,0,504,502,1,0,0,0,505,510,3,88,44,0,506,507,5,46,0,
  	0,507,509,3,88,44,0,508,506,1,0,0,0,509,512,1,0,0,0,510,508,1,0,0,0,510,
  	511,1,0,0,0,511,514,1,0,0,0,512,510,1,0,0,0,513,515,5,46,0,0,514,513,
  	1,0,0,0,514,515,1,0,0,0,515,81,1,0,0,0,516,520,3,78,39,0,517,520,3,10,
  	5,0,518,520,3,12,6,0,519,516,1,0,0,0,519,517,1,0,0,0,519,518,1,0,0,0,
  	520,83,1,0,0,0,521,531,3,82,41,0,522,523,5,45,0,0,523,531,3,84,42,0,524,
  	525,5,28,0,0,525,531,3,82,41,0,526,527,5,29,0,0,527,531,3,82,41,0,528,
  	529,5,42,0,0,529,531,3,82,41,0,530,521,1,0,0,0,530,522,1,0,0,0,530,524,
  	1,0,0,0,530,526,1,0,0,0,530,528,1,0,0,0,531,85,1,0,0,0,532,533,6,43,-1,
  	0,533,539,3,84,42,0,534,535,3,84,42,0,535,536,5,10,0,0,536,537,3,96,48,
  	0,537,539,1,0,0,0,538,532,1,0,0,0,538,534,1,0,0,0,539,560,1,0,0,0,540,
  	541,10,5,0,0,541,542,7,0,0,0,542,559,3,86,43,6,543,544,10,4,0,0,544,545,
  	7,1,0,0,545,559,3,86,43,5,546,547,10,3,0,0,547,548,3,100,50,0,548,549,
  	3,86,43,4,549,559,1,0,0,0,550,551,10,2,0,0,551,552,3,102,51,0,552,553,
  	3,86,43,3,553,559,1,0,0,0,554,555,10,1,0,0,555,556,3,104,52,0,556,557,
  	3,86,43,2,557,559,1,0,0,0,558,540,1,0,0,0,558,543,1,0,0,0,558,546,1,0,
  	0,0,558,550,1,0,0,0,558,554,1,0,0,0,559,562,1,0,0,0,560,558,1,0,0,0,560,
  	561,1,0,0,0,561,87,1,0,0,0,562,560,1,0,0,0,563,564,3,96,48,0,564,566,
  	5,48,0,0,565,567,3,90,45,0,566,565,1,0,0,0,566,567,1,0,0,0,567,568,1,
  	0,0,0,568,569,5,49,0,0,569,572,1,0,0,0,570,572,3,86,43,0,571,563,1,0,
  	0,0,571,570,1,0,0,0,572,89,1,0,0,0,573,578,3,92,46,0,574,575,5,46,0,0,
  	575,577,3,92,46,0,576,574,1,0,0,0,577,580,1,0,0,0,578,576,1,0,0,0,578,
  	579,1,0,0,0,579,582,1,0,0,0,580,578,1,0,0,0,581,583,5,46,0,0,582,581,
  	1,0,0,0,582,583,1,0,0,0,583,91,1,0,0,0,584,585,5,55,0,0,585,587,5,24,
  	0,0,586,584,1,0,0,0,586,587,1,0,0,0,587,588,1,0,0,0,588,589,3,88,44,0,
  	589,93,1,0,0,0,590,591,6,47,-1,0,591,603,3,8,4,0,592,593,5,26,0,0,593,
  	598,3,96,48,0,594,595,5,46,0,0,595,597,3,96,48,0,596,594,1,0,0,0,597,
  	600,1,0,0,0,598,596,1,0,0,0,598,599,1,0,0,0,599,601,1,0,0,0,600,598,1,
  	0,0,0,601,602,5,25,0,0,602,604,1,0,0,0,603,592,1,0,0,0,603,604,1,0,0,
  	0,604,610,1,0,0,0,605,606,5,36,0,0,606,607,3,96,48,0,607,608,5,37,0,0,
  	608,610,1,0,0,0,609,590,1,0,0,0,609,605,1,0,0,0,610,617,1,0,0,0,611,612,
  	10,2,0,0,612,613,5,38,0,0,613,614,5,50,0,0,614,616,5,39,0,0,615,611,1,
  	0,0,0,616,619,1,0,0,0,617,615,1,0,0,0,617,618,1,0,0,0,618,95,1,0,0,0,
  	619,617,1,0,0,0,620,621,6,48,-1,0,621,624,3,94,47,0,622,623,5,35,0,0,
  	623,625,3,94,47,0,624,622,1,0,0,0,625,626,1,0,0,0,626,624,1,0,0,0,626,
  	627,1,0,0,0,627,638,1,0,0,0,628,638,3,94,47,0,629,631,5,36,0,0,630,632,
  	3,98,49,0,631,630,1,0,0,0,631,632,1,0,0,0,632,633,1,0,0,0,633,634,5,37,
  	0,0,634,635,5,29,0,0,635,636,5,25,0,0,636,638,3,96,48,2,637,620,1,0,0,
  	0,637,628,1,0,0,0,637,629,1,0,0,0,638,645,1,0,0,0,639,640,10,1,0,0,640,
  	641,5,29,0,0,641,642,5,25,0,0,642,644,3,96,48,2,643,639,1,0,0,0,644,647,
  	1,0,0,0,645,643,1,0,0,0,645,646,1,0,0,0,646,97,1,0,0,0,647,645,1,0,0,
  	0,648,649,3,6,3,0,649,650,5,41,0,0,650,652,1,0,0,0,651,648,1,0,0,0,651,
  	652,1,0,0,0,652,653,1,0,0,0,653,654,3,96,48,0,654,664,1,0,0,0,655,659,
  	5,46,0,0,656,657,3,6,3,0,657,658,5,41,0,0,658,660,1,0,0,0,659,656,1,0,
  	0,0,659,660,1,0,0,0,660,661,1,0,0,0,661,663,3,96,48,0,662,655,1,0,0,0,
  	663,666,1,0,0,0,664,662,1,0,0,0,664,665,1,0,0,0,665,99,1,0,0,0,666,664,
  	1,0,0,0,667,675,5,33,0,0,668,675,5,35,0,0,669,675,5,34,0,0,670,671,5,
  	26,0,0,671,675,5,26,0,0,672,673,5,25,0,0,673,675,5,25,0,0,674,667,1,0,
  	0,0,674,668,1,0,0,0,674,669,1,0,0,0,674,670,1,0,0,0,674,672,1,0,0,0,675,
  	101,1,0,0,0,676,677,5,24,0,0,677,687,5,24,0,0,678,679,5,45,0,0,679,687,
  	5,24,0,0,680,687,5,25,0,0,681,687,5,26,0,0,682,683,5,25,0,0,683,687,5,
  	24,0,0,684,685,5,26,0,0,685,687,5,24,0,0,686,676,1,0,0,0,686,678,1,0,
  	0,0,686,680,1,0,0,0,686,681,1,0,0,0,686,682,1,0,0,0,686,684,1,0,0,0,687,
  	103,1,0,0,0,688,689,5,35,0,0,689,695,5,35,0,0,690,691,5,34,0,0,691,695,
  	5,34,0,0,692,695,5,20,0,0,693,695,5,21,0,0,694,688,1,0,0,0,694,690,1,
  	0,0,0,694,692,1,0,0,0,694,693,1,0,0,0,695,105,1,0,0,0,78,112,132,142,
  	148,151,159,163,170,181,189,208,216,220,224,231,241,251,255,259,266,278,
  	282,288,293,298,303,312,320,325,334,338,347,377,381,391,397,403,407,409,
  	415,422,426,435,439,444,460,471,483,491,497,500,502,510,514,519,530,538,
  	558,560,566,571,578,582,586,598,603,609,617,626,631,637,645,651,659,664,
  	674,686,694
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

tree::TerminalNode* TsilParser::NumberContext::COLON() {
  return getToken(TsilParser::COLON, 0);
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
    setState(148);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(146);
      match(TsilParser::COLON);
      setState(147);
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
    setState(151);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(150);
      antlrcpp::downCast<StringContext *>(_localctx)->s_prefix = match(TsilParser::ID);
    }
    setState(153);
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
    setState(155);
    match(TsilParser::KW_IMPORT);
    setState(156);
    antlrcpp::downCast<TakeContext *>(_localctx)->t_type = match(TsilParser::ID);
    setState(159);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::STRING: {
        setState(157);
        antlrcpp::downCast<TakeContext *>(_localctx)->t_string = match(TsilParser::STRING);
        break;
      }

      case TsilParser::DOT:
      case TsilParser::ID: {
        setState(158);
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
    setState(163);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::DOT) {
      setState(161);
      antlrcpp::downCast<Take_partsContext *>(_localctx)->tp_relative = match(TsilParser::DOT);
      setState(162);
      match(TsilParser::DIVIDE);
    }
    setState(165);
    match(TsilParser::ID);
    setState(170);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TsilParser::DIVIDE) {
      setState(166);
      match(TsilParser::DIVIDE);
      setState(167);
      match(TsilParser::ID);
      setState(172);
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
    setState(173);
    match(TsilParser::KW_SYNONYM);
    setState(174);
    antlrcpp::downCast<SynonymContext *>(_localctx)->s_name = match(TsilParser::ID);
    setState(175);
    match(TsilParser::EQUAL);
    setState(176);
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
    setState(181);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(178);
      full_type(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(179);
      number();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(180);
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
    setState(183);
    match(TsilParser::KW_SECTION);
    setState(184);
    antlrcpp::downCast<SectionContext *>(_localctx)->s_name = match(TsilParser::ID);
    setState(185);
    match(TsilParser::QUOTE_OPEN);
    setState(189);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 140737501399302) != 0)) {
      setState(186);
      section_element();
      setState(191);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(192);
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
    setState(208);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(194);
      synonym();
      setState(195);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(197);
      declare();
      setState(198);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(200);
      define();
      setState(201);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(203);
      section();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(204);
      structure();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(205);
      diia_declaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(206);
      diia();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(207);
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
    setState(210);
    match(TsilParser::KW_STRUCT);
    setState(211);
    antlrcpp::downCast<StructureContext *>(_localctx)->s_name = match(TsilParser::ID);
    setState(216);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(212);
      match(TsilParser::LESSER);
      setState(213);
      antlrcpp::downCast<StructureContext *>(_localctx)->s_generics = structure_generics();
      setState(214);
      match(TsilParser::GREATER);
    }
    setState(224);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::QUOTE_OPEN: {
        setState(218);
        match(TsilParser::QUOTE_OPEN);
        setState(220);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TsilParser::ID) {
          setState(219);
          antlrcpp::downCast<StructureContext *>(_localctx)->s_params = structure_params();
        }
        setState(222);
        match(TsilParser::QUOTE_CLOSE);
        break;
      }

      case TsilParser::SEMICOLON: {
        setState(223);
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
    setState(226);
    structure_generic();
    setState(231);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TsilParser::COMA) {
      setState(227);
      match(TsilParser::COMA);
      setState(228);
      structure_generic();
      setState(233);
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
    setState(234);
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
    setState(239); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(236);
      structure_param();
      setState(237);
      match(TsilParser::SEMICOLON);
      setState(241); 
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
    setState(243);
    antlrcpp::downCast<Structure_paramContext *>(_localctx)->sp_name = match(TsilParser::ID);
    setState(244);
    match(TsilParser::COLON);
    setState(245);
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
    setState(247);
    match(TsilParser::KW_VARIATION);
    setState(248);
    antlrcpp::downCast<VariationContext *>(_localctx)->v_name = match(TsilParser::ID);
    setState(251);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(249);
      match(TsilParser::COLON);
      setState(250);
      antlrcpp::downCast<VariationContext *>(_localctx)->v_type = full_type(0);
    }
    setState(259);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::QUOTE_OPEN: {
        setState(253);
        match(TsilParser::QUOTE_OPEN);
        setState(255);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TsilParser::ID) {
          setState(254);
          antlrcpp::downCast<VariationContext *>(_localctx)->v_params = variation_params();
        }
        setState(257);
        match(TsilParser::QUOTE_CLOSE);
        break;
      }

      case TsilParser::SEMICOLON: {
        setState(258);
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
    setState(264); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(261);
      variation_param();
      setState(262);
      match(TsilParser::SEMICOLON);
      setState(266); 
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
    setState(268);
    antlrcpp::downCast<Variation_paramContext *>(_localctx)->vp_name = match(TsilParser::ID);
    setState(269);
    match(TsilParser::COLON);
    setState(270);
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
    setState(272);
    match(TsilParser::KW_DIIA);
    setState(273);
    antlrcpp::downCast<Diia_headContext *>(_localctx)->d_name = match(TsilParser::ID);
    setState(278);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::LESSER) {
      setState(274);
      match(TsilParser::LESSER);
      setState(275);
      antlrcpp::downCast<Diia_headContext *>(_localctx)->d_generics = diia_generics();
      setState(276);
      match(TsilParser::GREATER);
    }
    setState(280);
    match(TsilParser::PAREN_OPEN);
    setState(282);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::ID) {
      setState(281);
      antlrcpp::downCast<Diia_headContext *>(_localctx)->d_params = params();
    }
    setState(288);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COMA) {
      setState(284);
      antlrcpp::downCast<Diia_headContext *>(_localctx)->d_variadic = match(TsilParser::COMA);
      setState(285);
      match(TsilParser::DOT);
      setState(286);
      match(TsilParser::DOT);
      setState(287);
      match(TsilParser::DOT);
    }
    setState(290);
    match(TsilParser::PAREN_CLOSE);
    setState(293);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(291);
      match(TsilParser::COLON);
      setState(292);
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
    setState(298);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(295);
        antlrcpp::downCast<DiiaContext *>(_localctx)->d_extern = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(296);
        antlrcpp::downCast<DiiaContext *>(_localctx)->d_local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(297);
        antlrcpp::downCast<DiiaContext *>(_localctx)->d_internal = match(TsilParser::KW_PRIVATE);
        break;
      }

      case TsilParser::KW_DIIA: {
        break;
      }

    default:
      break;
    }
    setState(300);
    antlrcpp::downCast<DiiaContext *>(_localctx)->d_head = diia_head();
    setState(301);
    match(TsilParser::QUOTE_OPEN);
    setState(303);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 109674155385225450) != 0)) {
      setState(302);
      antlrcpp::downCast<DiiaContext *>(_localctx)->d_body = body();
    }
    setState(305);
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
    setState(307);
    diia_generic();
    setState(312);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TsilParser::COMA) {
      setState(308);
      match(TsilParser::COMA);
      setState(309);
      diia_generic();
      setState(314);
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
    setState(315);
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
    setState(320);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(317);
        antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_extern = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(318);
        antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(319);
        antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_internal = match(TsilParser::KW_PRIVATE);
        break;
      }

      case TsilParser::KW_DIIA: {
        break;
      }

    default:
      break;
    }
    setState(322);
    antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_head = diia_head();
    setState(325);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::KW_AS) {
      setState(323);
      match(TsilParser::KW_AS);
      setState(324);
      antlrcpp::downCast<Diia_declarationContext *>(_localctx)->d_as = match(TsilParser::ID);
    }
    setState(327);
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
    setState(329);
    param();
    setState(334);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(330);
        match(TsilParser::COMA);
        setState(331);
        param(); 
      }
      setState(336);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
    setState(338);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(337);
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
    setState(340);
    antlrcpp::downCast<ParamContext *>(_localctx)->p_name = match(TsilParser::ID);
    setState(341);
    match(TsilParser::COLON);
    setState(342);
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
    setState(345); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(344);
      body_element();
      setState(347); 
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
    setState(377);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(349);
      if_();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(350);
      while_();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(351);
      synonym();
      setState(352);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(354);
      declare();
      setState(355);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(357);
      define();
      setState(358);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(360);
      assign();
      setState(361);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(363);
      set();
      setState(364);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(366);
      expr();
      setState(367);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(369);
      return_body_element();
      setState(370);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(372);
      defer();
      setState(373);
      match(TsilParser::SEMICOLON);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(375);
      block();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(376);
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
    setState(379);
    match(TsilParser::KW_RETURN);
    setState(381);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 109251942907117568) != 0)) {
      setState(380);
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
    setState(383);
    match(TsilParser::QUOTE_OPEN);
    setState(384);
    body();
    setState(385);
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
    setState(387);
    match(TsilParser::KW_DEFER);
    setState(391);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      setState(388);
      assign();
      break;
    }

    case 2: {
      setState(389);
      set();
      break;
    }

    case 3: {
      setState(390);
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
    setState(393);
    match(TsilParser::KW_IF);
    setState(394);
    antlrcpp::downCast<IfContext *>(_localctx)->i_value = expr();
    setState(395);
    match(TsilParser::QUOTE_OPEN);
    setState(397);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 109674155385225450) != 0)) {
      setState(396);
      antlrcpp::downCast<IfContext *>(_localctx)->i_body = body();
    }
    setState(399);
    match(TsilParser::QUOTE_CLOSE);
    setState(409);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::KW_ELSE) {
      setState(400);
      match(TsilParser::KW_ELSE);
      setState(407);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TsilParser::QUOTE_OPEN: {
          setState(401);
          match(TsilParser::QUOTE_OPEN);
          setState(403);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 109674155385225450) != 0)) {
            setState(402);
            antlrcpp::downCast<IfContext *>(_localctx)->i_else_body = body();
          }
          setState(405);
          match(TsilParser::QUOTE_CLOSE);
          break;
        }

        case TsilParser::KW_IF: {
          setState(406);
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
    setState(411);
    match(TsilParser::KW_WHILE);
    setState(412);
    antlrcpp::downCast<WhileContext *>(_localctx)->w_value = expr();
    setState(413);
    match(TsilParser::QUOTE_OPEN);
    setState(415);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 109674155385225450) != 0)) {
      setState(414);
      antlrcpp::downCast<WhileContext *>(_localctx)->w_body = body();
    }
    setState(417);
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
    setState(422);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(419);
        antlrcpp::downCast<DeclareContext *>(_localctx)->d_extern = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(420);
        antlrcpp::downCast<DeclareContext *>(_localctx)->d_local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(421);
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
    setState(426);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_TSIL: {
        setState(424);
        antlrcpp::downCast<DeclareContext *>(_localctx)->d_tsil = match(TsilParser::KW_TSIL);
        break;
      }

      case TsilParser::KW_VAR: {
        setState(425);
        antlrcpp::downCast<DeclareContext *>(_localctx)->d_var = match(TsilParser::KW_VAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(428);
    antlrcpp::downCast<DeclareContext *>(_localctx)->d_id = match(TsilParser::ID);
    setState(429);
    match(TsilParser::COLON);
    setState(430);
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
    setState(435);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_PUBLIC: {
        setState(432);
        antlrcpp::downCast<DefineContext *>(_localctx)->d_extern = match(TsilParser::KW_PUBLIC);
        break;
      }

      case TsilParser::KW_LOCAL: {
        setState(433);
        antlrcpp::downCast<DefineContext *>(_localctx)->d_local = match(TsilParser::KW_LOCAL);
        break;
      }

      case TsilParser::KW_PRIVATE: {
        setState(434);
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
    setState(439);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::KW_TSIL: {
        setState(437);
        antlrcpp::downCast<DefineContext *>(_localctx)->d_tsil = match(TsilParser::KW_TSIL);
        break;
      }

      case TsilParser::KW_VAR: {
        setState(438);
        antlrcpp::downCast<DefineContext *>(_localctx)->d_var = match(TsilParser::KW_VAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(441);
    antlrcpp::downCast<DefineContext *>(_localctx)->d_id = match(TsilParser::ID);
    setState(444);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COLON) {
      setState(442);
      match(TsilParser::COLON);
      setState(443);
      antlrcpp::downCast<DefineContext *>(_localctx)->d_type = full_type(0);
    }
    setState(446);
    match(TsilParser::EQUAL);
    setState(447);
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
    setState(449);
    antlrcpp::downCast<AssignContext *>(_localctx)->a_id = match(TsilParser::ID);
    setState(450);
    match(TsilParser::EQUAL);
    setState(451);
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
    setState(453);
    antlrcpp::downCast<SetContext *>(_localctx)->s_left = particle(0);
    setState(460);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::DOT: {
        setState(454);
        match(TsilParser::DOT);
        setState(455);
        antlrcpp::downCast<SetContext *>(_localctx)->s_id = match(TsilParser::ID);
        break;
      }

      case TsilParser::BRACKET_OPEN: {
        setState(456);
        match(TsilParser::BRACKET_OPEN);
        setState(457);
        antlrcpp::downCast<SetContext *>(_localctx)->s_index = expr();
        setState(458);
        match(TsilParser::BRACKET_CLOSE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(462);
    match(TsilParser::EQUAL);
    setState(463);
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
    setState(471);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::ID: {
        _localctx = _tracker.createInstance<Particle_section_accessContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(466);
        section_access();
        break;
      }

      case TsilParser::PAREN_OPEN: {
        _localctx = _tracker.createInstance<NestedContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(467);
        match(TsilParser::PAREN_OPEN);
        setState(468);
        antlrcpp::downCast<NestedContext *>(_localctx)->n_value = expr();
        setState(469);
        match(TsilParser::PAREN_CLOSE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(502);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(500);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<GetContext>(_tracker.createInstance<ParticleContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->g_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleParticle);
          setState(473);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(474);
          match(TsilParser::DOT);
          setState(475);
          antlrcpp::downCast<GetContext *>(_localctx)->g_id = match(TsilParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<GenericContext>(_tracker.createInstance<ParticleContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->g_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleParticle);
          setState(476);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(477);
          match(TsilParser::LESSER);
          setState(478);
          antlrcpp::downCast<GenericContext *>(_localctx)->sa_generic_value = full_type(0);
          setState(483);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == TsilParser::COMA) {
            setState(479);
            match(TsilParser::COMA);
            setState(480);
            full_type(0);
            setState(485);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(486);
          match(TsilParser::GREATER);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AccessContext>(_tracker.createInstance<ParticleContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->a_value = previousContext;
          pushNewRecursionContext(newContext, startState, RuleParticle);
          setState(488);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(489);
          match(TsilParser::BRACKET_OPEN);
          setState(491);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 109251942907117568) != 0)) {
            setState(490);
            antlrcpp::downCast<AccessContext *>(_localctx)->a_index = expr();
          }
          setState(493);
          match(TsilParser::BRACKET_CLOSE);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CallContext>(_tracker.createInstance<ParticleContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->c_value = previousContext;
          pushNewRecursionContext(newContext, startState, RuleParticle);
          setState(494);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(495);
          match(TsilParser::PAREN_OPEN);
          setState(497);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 109251942907117568) != 0)) {
            setState(496);
            antlrcpp::downCast<CallContext *>(_localctx)->c_args = args();
          }
          setState(499);
          match(TsilParser::PAREN_CLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(504);
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
    setState(505);
    expr();
    setState(510);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(506);
        match(TsilParser::COMA);
        setState(507);
        expr(); 
      }
      setState(512);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    }
    setState(514);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COMA) {
      setState(513);
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
    setState(519);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TsilParser::Atom_particleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(516);
      particle(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TsilParser::Atom_numberContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(517);
      number();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<TsilParser::Atom_stringContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(518);
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
    setState(530);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::PAREN_OPEN:
      case TsilParser::NUMBER:
      case TsilParser::ID:
      case TsilParser::STRING: {
        _localctx = _tracker.createInstance<TsilParser::Molecule_atomContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(521);
        atom();
        break;
      }

      case TsilParser::EXCLAMATION: {
        _localctx = _tracker.createInstance<TsilParser::NotContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(522);
        match(TsilParser::EXCLAMATION);
        setState(523);
        antlrcpp::downCast<NotContext *>(_localctx)->n_value = molecule();
        break;
      }

      case TsilParser::PLUS: {
        _localctx = _tracker.createInstance<TsilParser::PositiveContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(524);
        match(TsilParser::PLUS);
        setState(525);
        antlrcpp::downCast<PositiveContext *>(_localctx)->p_value = atom();
        break;
      }

      case TsilParser::MINUS: {
        _localctx = _tracker.createInstance<TsilParser::NegativeContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(526);
        match(TsilParser::MINUS);
        setState(527);
        antlrcpp::downCast<NegativeContext *>(_localctx)->n_value = atom();
        break;
      }

      case TsilParser::TILDA: {
        _localctx = _tracker.createInstance<TsilParser::Bitwise_notContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(528);
        match(TsilParser::TILDA);
        setState(529);
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
    setState(538);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Operation_moleculeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(533);
      molecule();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<AsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(534);
      antlrcpp::downCast<AsContext *>(_localctx)->a_left = molecule();
      setState(535);
      match(TsilParser::KW_AS);
      setState(536);
      antlrcpp::downCast<AsContext *>(_localctx)->a_type = full_type(0);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(560);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(558);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->a_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(540);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(541);
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
          setState(542);
          antlrcpp::downCast<MulContext *>(_localctx)->a_right = operation(6);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->a_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(543);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(544);
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
          setState(545);
          antlrcpp::downCast<AddContext *>(_localctx)->a_right = operation(5);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BitwiseContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->b_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(546);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(547);
          antlrcpp::downCast<BitwiseContext *>(_localctx)->b_operation = bitwise_op();
          setState(548);
          antlrcpp::downCast<BitwiseContext *>(_localctx)->b_right = operation(4);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ComparisonContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->c_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(550);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(551);
          antlrcpp::downCast<ComparisonContext *>(_localctx)->c_operation = comparison_op();
          setState(552);
          antlrcpp::downCast<ComparisonContext *>(_localctx)->c_right = operation(3);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<LogicalContext>(_tracker.createInstance<OperationContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->t_left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleOperation);
          setState(554);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(555);
          antlrcpp::downCast<LogicalContext *>(_localctx)->t_operation = logical_op();
          setState(556);
          antlrcpp::downCast<LogicalContext *>(_localctx)->t_right = operation(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(562);
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
    setState(571);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<TsilParser::ConstructContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(563);
      antlrcpp::downCast<ConstructContext *>(_localctx)->c_type = full_type(0);
      setState(564);
      match(TsilParser::QUOTE_OPEN);
      setState(566);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 109251942907117568) != 0)) {
        setState(565);
        antlrcpp::downCast<ConstructContext *>(_localctx)->c_args = construct_args();
      }
      setState(568);
      match(TsilParser::QUOTE_CLOSE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TsilParser::Expr_operationContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(570);
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
    setState(573);
    construct_arg();
    setState(578);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(574);
        match(TsilParser::COMA);
        setState(575);
        construct_arg(); 
      }
      setState(580);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    }
    setState(582);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TsilParser::COMA) {
      setState(581);
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
    setState(586);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
    case 1: {
      setState(584);
      antlrcpp::downCast<Construct_argContext *>(_localctx)->ca_name = match(TsilParser::ID);
      setState(585);
      match(TsilParser::EQUAL);
      break;
    }

    default:
      break;
    }
    setState(588);
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
    setState(609);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::ID: {
        _localctx = _tracker.createInstance<Simple_typeContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(591);
        section_access();
        setState(603);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
        case 1: {
          setState(592);
          match(TsilParser::LESSER);
          setState(593);
          antlrcpp::downCast<Simple_typeContext *>(_localctx)->t_first_generic_type = full_type(0);
          setState(598);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == TsilParser::COMA) {
            setState(594);
            match(TsilParser::COMA);
            setState(595);
            full_type(0);
            setState(600);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(601);
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

        setState(605);
        match(TsilParser::PAREN_OPEN);
        setState(606);
        full_type(0);
        setState(607);
        match(TsilParser::PAREN_CLOSE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(617);
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
        setState(611);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(612);
        match(TsilParser::BRACKET_OPEN);
        setState(613);
        antlrcpp::downCast<Array_typeContext *>(_localctx)->at_size = match(TsilParser::NUMBER);
        setState(614);
        match(TsilParser::BRACKET_CLOSE); 
      }
      setState(619);
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
    setState(637);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Variation_typeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(621);
      basic_type(0);
      setState(624); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(622);
                match(TsilParser::OR);
                setState(623);
                basic_type(0);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(626); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Basic_type_real_basicContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(628);
      basic_type(0);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Complex_function_typeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(629);
      match(TsilParser::PAREN_OPEN);
      setState(631);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TsilParser::PAREN_OPEN

      || _la == TsilParser::ID) {
        setState(630);
        antlrcpp::downCast<Complex_function_typeContext *>(_localctx)->cft_args = complex_function_type_args();
      }
      setState(633);
      match(TsilParser::PAREN_CLOSE);
      setState(634);
      match(TsilParser::MINUS);
      setState(635);
      match(TsilParser::GREATER);
      setState(636);
      antlrcpp::downCast<Complex_function_typeContext *>(_localctx)->cft_ret = full_type(2);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(645);
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
        setState(639);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(640);
        match(TsilParser::MINUS);
        setState(641);
        match(TsilParser::GREATER);
        setState(642);
        antlrcpp::downCast<Simple_function_typeContext *>(_localctx)->sft_ret = full_type(2); 
      }
      setState(647);
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

std::vector<TsilParser::IdentifierContext *> TsilParser::Complex_function_type_argsContext::identifier() {
  return getRuleContexts<TsilParser::IdentifierContext>();
}

TsilParser::IdentifierContext* TsilParser::Complex_function_type_argsContext::identifier(size_t i) {
  return getRuleContext<TsilParser::IdentifierContext>(i);
}

std::vector<tree::TerminalNode *> TsilParser::Complex_function_type_argsContext::COLON() {
  return getTokens(TsilParser::COLON);
}

tree::TerminalNode* TsilParser::Complex_function_type_argsContext::COLON(size_t i) {
  return getToken(TsilParser::COLON, i);
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
    setState(651);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx)) {
    case 1: {
      setState(648);
      identifier();
      setState(649);
      match(TsilParser::COLON);
      break;
    }

    default:
      break;
    }
    setState(653);
    full_type(0);
    setState(664);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TsilParser::COMA) {
      setState(655);
      match(TsilParser::COMA);

      setState(659);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
      case 1: {
        setState(656);
        identifier();
        setState(657);
        match(TsilParser::COLON);
        break;
      }

      default:
        break;
      }
      setState(661);
      full_type(0);
      setState(666);
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
    setState(674);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::POWER: {
        enterOuterAlt(_localctx, 1);
        setState(667);
        match(TsilParser::POWER);
        break;
      }

      case TsilParser::OR: {
        enterOuterAlt(_localctx, 2);
        setState(668);
        match(TsilParser::OR);
        break;
      }

      case TsilParser::AND: {
        enterOuterAlt(_localctx, 3);
        setState(669);
        match(TsilParser::AND);
        break;
      }

      case TsilParser::LESSER: {
        enterOuterAlt(_localctx, 4);
        setState(670);
        match(TsilParser::LESSER);
        setState(671);
        match(TsilParser::LESSER);
        break;
      }

      case TsilParser::GREATER: {
        enterOuterAlt(_localctx, 5);
        setState(672);
        match(TsilParser::GREATER);
        setState(673);
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
    setState(686);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(676);
      match(TsilParser::EQUAL);
      setState(677);
      match(TsilParser::EQUAL);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(678);
      match(TsilParser::EXCLAMATION);
      setState(679);
      match(TsilParser::EQUAL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(680);
      match(TsilParser::GREATER);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(681);
      match(TsilParser::LESSER);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(682);
      match(TsilParser::GREATER);
      setState(683);
      match(TsilParser::EQUAL);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(684);
      match(TsilParser::LESSER);
      setState(685);
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
    setState(694);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TsilParser::OR: {
        enterOuterAlt(_localctx, 1);
        setState(688);
        match(TsilParser::OR);
        setState(689);
        match(TsilParser::OR);
        break;
      }

      case TsilParser::AND: {
        enterOuterAlt(_localctx, 2);
        setState(690);
        match(TsilParser::AND);
        setState(691);
        match(TsilParser::AND);
        break;
      }

      case TsilParser::KW_OR: {
        enterOuterAlt(_localctx, 3);
        setState(692);
        match(TsilParser::KW_OR);
        break;
      }

      case TsilParser::KW_AND: {
        enterOuterAlt(_localctx, 4);
        setState(693);
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
