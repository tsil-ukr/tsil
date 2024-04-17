
// Generated from TsilLexer.g4 by ANTLR 4.13.0


#include "TsilLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct TsilLexerStaticData final {
  TsilLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  TsilLexerStaticData(const TsilLexerStaticData&) = delete;
  TsilLexerStaticData(TsilLexerStaticData&&) = delete;
  TsilLexerStaticData& operator=(const TsilLexerStaticData&) = delete;
  TsilLexerStaticData& operator=(TsilLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag tsillexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
TsilLexerStaticData *tsillexerLexerStaticData = nullptr;

void tsillexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (tsillexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(tsillexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<TsilLexerStaticData>(
    std::vector<std::string>{
      "KW_TSIL", "KW_DIIA", "KW_SAVE", "KW_DELETE", "KW_IF", "KW_ELSE", 
      "KW_WHILE", "KW_RETURN", "KW_STRUCT", "KW_EXTERN", "KW_AS", "KW_SIZEOF", 
      "EQUAL", "GREATER", "LESSER", "DOT", "PLUS", "MINUS", "MULTIPLY", 
      "DIVIDE", "MOD", "POWER", "AND", "OR", "PAREN_OPEN", "PAREN_CLOSE", 
      "BRACKET_OPEN", "BRACKET_CLOSE", "QUESTION", "COLON", "TILDA", "QUOTE", 
      "DOUBLE_QUOTE", "EXCLAMATION", "COMA", "SEMICOLON", "QUOTE_OPEN", 
      "QUOTE_CLOSE", "NUMBER", "ID", "STRING", "NL", "WS", "DIGIT", "ID_START", 
      "ID_CONTINUE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,43,271,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,
  	1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,
  	6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,
  	1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,
  	1,22,1,22,1,23,1,23,1,24,1,24,1,25,1,25,1,26,1,26,1,27,1,27,1,28,1,28,
  	1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,
  	1,36,1,36,1,37,1,37,1,38,4,38,232,8,38,11,38,12,38,233,1,39,1,39,5,39,
  	238,8,39,10,39,12,39,241,9,39,1,40,1,40,5,40,245,8,40,10,40,12,40,248,
  	9,40,1,40,1,40,1,41,3,41,253,8,41,1,41,1,41,1,41,1,41,1,42,1,42,1,42,
  	1,42,1,43,1,43,1,44,1,44,1,45,1,45,1,45,3,45,270,8,45,0,0,46,1,1,3,2,
  	5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,
  	16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,
  	55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,73,37,75,38,77,
  	39,79,40,81,41,83,42,85,43,87,0,89,0,91,0,1,0,4,3,0,10,10,13,13,34,34,
  	2,0,9,9,32,32,9,0,65,90,95,95,97,122,1028,1028,1030,1031,1040,1103,1108,
  	1108,1110,1111,1168,1169,2,0,48,57,700,700,273,0,1,1,0,0,0,0,3,1,0,0,
  	0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,
  	1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,
  	0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,
  	0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,
  	1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,
  	0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,
  	0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,
  	1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,1,93,1,0,0,0,3,98,1,0,
  	0,0,5,102,1,0,0,0,7,111,1,0,0,0,9,120,1,0,0,0,11,125,1,0,0,0,13,132,1,
  	0,0,0,15,137,1,0,0,0,17,145,1,0,0,0,19,155,1,0,0,0,21,163,1,0,0,0,23,
  	166,1,0,0,0,25,178,1,0,0,0,27,180,1,0,0,0,29,182,1,0,0,0,31,184,1,0,0,
  	0,33,186,1,0,0,0,35,188,1,0,0,0,37,190,1,0,0,0,39,192,1,0,0,0,41,194,
  	1,0,0,0,43,196,1,0,0,0,45,198,1,0,0,0,47,200,1,0,0,0,49,202,1,0,0,0,51,
  	204,1,0,0,0,53,206,1,0,0,0,55,208,1,0,0,0,57,210,1,0,0,0,59,212,1,0,0,
  	0,61,214,1,0,0,0,63,216,1,0,0,0,65,218,1,0,0,0,67,220,1,0,0,0,69,222,
  	1,0,0,0,71,224,1,0,0,0,73,226,1,0,0,0,75,228,1,0,0,0,77,231,1,0,0,0,79,
  	235,1,0,0,0,81,242,1,0,0,0,83,252,1,0,0,0,85,258,1,0,0,0,87,262,1,0,0,
  	0,89,264,1,0,0,0,91,269,1,0,0,0,93,94,5,1094,0,0,94,95,5,1110,0,0,95,
  	96,5,1083,0,0,96,97,5,1100,0,0,97,2,1,0,0,0,98,99,5,1076,0,0,99,100,5,
  	1110,0,0,100,101,5,1103,0,0,101,4,1,0,0,0,102,103,5,1087,0,0,103,104,
  	5,1086,0,0,104,105,5,1082,0,0,105,106,5,1083,0,0,106,107,5,1072,0,0,107,
  	108,5,1089,0,0,108,109,5,1090,0,0,109,110,5,1080,0,0,110,6,1,0,0,0,111,
  	112,5,1074,0,0,112,113,5,1080,0,0,113,114,5,1076,0,0,114,115,5,1072,0,
  	0,115,116,5,1083,0,0,116,117,5,1080,0,0,117,118,5,1090,0,0,118,119,5,
  	1080,0,0,119,8,1,0,0,0,120,121,5,1103,0,0,121,122,5,1082,0,0,122,123,
  	5,1097,0,0,123,124,5,1086,0,0,124,10,1,0,0,0,125,126,5,1110,0,0,126,127,
  	5,1085,0,0,127,128,5,1072,0,0,128,129,5,1082,0,0,129,130,5,1096,0,0,130,
  	131,5,1077,0,0,131,12,1,0,0,0,132,133,5,1087,0,0,133,134,5,1086,0,0,134,
  	135,5,1082,0,0,135,136,5,1080,0,0,136,14,1,0,0,0,137,138,5,1074,0,0,138,
  	139,5,1077,0,0,139,140,5,1088,0,0,140,141,5,1085,0,0,141,142,5,1091,0,
  	0,142,143,5,1090,0,0,143,144,5,1080,0,0,144,16,1,0,0,0,145,146,5,1089,
  	0,0,146,147,5,1090,0,0,147,148,5,1088,0,0,148,149,5,1091,0,0,149,150,
  	5,1082,0,0,150,151,5,1090,0,0,151,152,5,1091,0,0,152,153,5,1088,0,0,153,
  	154,5,1072,0,0,154,18,1,0,0,0,155,156,5,1077,0,0,156,157,5,1082,0,0,157,
  	158,5,1089,0,0,158,159,5,1090,0,0,159,160,5,1077,0,0,160,161,5,1088,0,
  	0,161,162,5,1085,0,0,162,20,1,0,0,0,163,164,5,1103,0,0,164,165,5,1082,
  	0,0,165,22,1,0,0,0,166,167,5,1088,0,0,167,168,5,1086,0,0,168,169,5,1079,
  	0,0,169,170,5,1084,0,0,170,171,5,1110,0,0,171,172,5,1088,0,0,172,173,
  	5,32,0,0,173,174,5,1090,0,0,174,175,5,1080,0,0,175,176,5,1087,0,0,176,
  	177,5,1091,0,0,177,24,1,0,0,0,178,179,5,61,0,0,179,26,1,0,0,0,180,181,
  	5,62,0,0,181,28,1,0,0,0,182,183,5,60,0,0,183,30,1,0,0,0,184,185,5,46,
  	0,0,185,32,1,0,0,0,186,187,5,43,0,0,187,34,1,0,0,0,188,189,5,45,0,0,189,
  	36,1,0,0,0,190,191,5,42,0,0,191,38,1,0,0,0,192,193,5,47,0,0,193,40,1,
  	0,0,0,194,195,5,37,0,0,195,42,1,0,0,0,196,197,5,94,0,0,197,44,1,0,0,0,
  	198,199,5,38,0,0,199,46,1,0,0,0,200,201,5,124,0,0,201,48,1,0,0,0,202,
  	203,5,40,0,0,203,50,1,0,0,0,204,205,5,41,0,0,205,52,1,0,0,0,206,207,5,
  	91,0,0,207,54,1,0,0,0,208,209,5,93,0,0,209,56,1,0,0,0,210,211,5,63,0,
  	0,211,58,1,0,0,0,212,213,5,58,0,0,213,60,1,0,0,0,214,215,5,126,0,0,215,
  	62,1,0,0,0,216,217,5,39,0,0,217,64,1,0,0,0,218,219,5,34,0,0,219,66,1,
  	0,0,0,220,221,5,33,0,0,221,68,1,0,0,0,222,223,5,44,0,0,223,70,1,0,0,0,
  	224,225,5,59,0,0,225,72,1,0,0,0,226,227,5,123,0,0,227,74,1,0,0,0,228,
  	229,5,125,0,0,229,76,1,0,0,0,230,232,3,87,43,0,231,230,1,0,0,0,232,233,
  	1,0,0,0,233,231,1,0,0,0,233,234,1,0,0,0,234,78,1,0,0,0,235,239,3,89,44,
  	0,236,238,3,91,45,0,237,236,1,0,0,0,238,241,1,0,0,0,239,237,1,0,0,0,239,
  	240,1,0,0,0,240,80,1,0,0,0,241,239,1,0,0,0,242,246,5,34,0,0,243,245,8,
  	0,0,0,244,243,1,0,0,0,245,248,1,0,0,0,246,244,1,0,0,0,246,247,1,0,0,0,
  	247,249,1,0,0,0,248,246,1,0,0,0,249,250,5,34,0,0,250,82,1,0,0,0,251,253,
  	5,13,0,0,252,251,1,0,0,0,252,253,1,0,0,0,253,254,1,0,0,0,254,255,5,10,
  	0,0,255,256,1,0,0,0,256,257,6,41,0,0,257,84,1,0,0,0,258,259,7,1,0,0,259,
  	260,1,0,0,0,260,261,6,42,0,0,261,86,1,0,0,0,262,263,2,48,57,0,263,88,
  	1,0,0,0,264,265,7,2,0,0,265,90,1,0,0,0,266,270,3,89,44,0,267,270,7,3,
  	0,0,268,270,3,89,44,0,269,266,1,0,0,0,269,267,1,0,0,0,269,268,1,0,0,0,
  	270,92,1,0,0,0,6,0,233,239,246,252,269,1,0,1,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  tsillexerLexerStaticData = staticData.release();
}

}

TsilLexer::TsilLexer(CharStream *input) : Lexer(input) {
  TsilLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *tsillexerLexerStaticData->atn, tsillexerLexerStaticData->decisionToDFA, tsillexerLexerStaticData->sharedContextCache);
}

TsilLexer::~TsilLexer() {
  delete _interpreter;
}

std::string TsilLexer::getGrammarFileName() const {
  return "TsilLexer.g4";
}

const std::vector<std::string>& TsilLexer::getRuleNames() const {
  return tsillexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& TsilLexer::getChannelNames() const {
  return tsillexerLexerStaticData->channelNames;
}

const std::vector<std::string>& TsilLexer::getModeNames() const {
  return tsillexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& TsilLexer::getVocabulary() const {
  return tsillexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView TsilLexer::getSerializedATN() const {
  return tsillexerLexerStaticData->serializedATN;
}

const atn::ATN& TsilLexer::getATN() const {
  return *tsillexerLexerStaticData->atn;
}




void TsilLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  tsillexerLexerInitialize();
#else
  ::antlr4::internal::call_once(tsillexerLexerOnceFlag, tsillexerLexerInitialize);
#endif
}
