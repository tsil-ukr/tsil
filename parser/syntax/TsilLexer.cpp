
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
      "KW_WHILE", "KW_RETURN", "KW_STRUCT", "KW_SPLAV", "EQUAL", "GREATER", 
      "LESSER", "DOT", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MOD", "POWER", 
      "AND", "OR", "PAREN_OPEN", "PAREN_CLOSE", "BRACKET_OPEN", "BRACKET_CLOSE", 
      "QUESTION", "COLON", "TILDA", "QUOTE", "DOUBLE_QUOTE", "EXCLAMATION", 
      "COMA", "SEMICOLON", "QUOTE_OPEN", "QUOTE_CLOSE", "NUMBER", "ID", 
      "STRING", "NL", "WS", "DIGIT", "ID_START", "ID_CONTINUE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'\\u0446\\u0456\\u043B\\u044C'", "'\\u0434\\u0456\\u044F'", "'\\u0437\\u0431\\u0435\\u0440\\u0435\\u0433\\u0442\\u0438'", 
      "'\\u0432\\u0438\\u0434\\u0430\\u043B\\u0438\\u0442\\u0438'", "'\\u044F\\u043A\\u0449\\u043E'", 
      "'\\u0456\\u043D\\u0430\\u043A\\u0448\\u0435'", "'\\u043F\\u043E\\u043A\\u0438'", 
      "'\\u0432\\u0435\\u0440\\u043D\\u0443\\u0442\\u0438'", "'\\u0441\\u0442\\u0440\\u0443\\u043A\\u0442\\u0443\\u0440\\u0430'", 
      "'\\u0441\\u043F\\u043B\\u0430\\u0432'", "'='", "'>'", "'<'", "'.'", 
      "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'&'", "'|'", "'('", "')'", 
      "'['", "']'", "'\\u003F'", "':'", "'~'", "'''", "'\"'", "'!'", "','", 
      "';'", "'{'", "'}'"
    },
    std::vector<std::string>{
      "", "KW_TSIL", "KW_DIIA", "KW_SAVE", "KW_DELETE", "KW_IF", "KW_ELSE", 
      "KW_WHILE", "KW_RETURN", "KW_STRUCT", "KW_SPLAV", "EQUAL", "GREATER", 
      "LESSER", "DOT", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MOD", "POWER", 
      "AND", "OR", "PAREN_OPEN", "PAREN_CLOSE", "BRACKET_OPEN", "BRACKET_CLOSE", 
      "QUESTION", "COLON", "TILDA", "QUOTE", "DOUBLE_QUOTE", "EXCLAMATION", 
      "COMA", "SEMICOLON", "QUOTE_OPEN", "QUOTE_CLOSE", "NUMBER", "ID", 
      "STRING", "NL", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,41,250,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,
  	1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,
  	16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,1,
  	23,1,23,1,24,1,24,1,25,1,25,1,26,1,26,1,27,1,27,1,28,1,28,1,29,1,29,1,
  	30,1,30,1,31,1,31,1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,1,36,4,36,211,
  	8,36,11,36,12,36,212,1,37,1,37,5,37,217,8,37,10,37,12,37,220,9,37,1,38,
  	1,38,5,38,224,8,38,10,38,12,38,227,9,38,1,38,1,38,1,39,3,39,232,8,39,
  	1,39,1,39,1,39,1,39,1,40,1,40,1,40,1,40,1,41,1,41,1,42,1,42,1,43,1,43,
  	1,43,3,43,249,8,43,0,0,44,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,
  	10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,
  	43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,
  	33,67,34,69,35,71,36,73,37,75,38,77,39,79,40,81,41,83,0,85,0,87,0,1,0,
  	4,3,0,10,10,13,13,34,34,2,0,9,9,32,32,9,0,65,90,95,95,97,122,1028,1028,
  	1030,1031,1040,1103,1108,1108,1110,1111,1168,1169,2,0,48,57,700,700,252,
  	0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,
  	0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,
  	0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,
  	1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,
  	0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,
  	0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,
  	1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,
  	0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,1,89,1,0,0,0,3,94,1,0,0,0,
  	5,98,1,0,0,0,7,107,1,0,0,0,9,116,1,0,0,0,11,121,1,0,0,0,13,128,1,0,0,
  	0,15,133,1,0,0,0,17,141,1,0,0,0,19,151,1,0,0,0,21,157,1,0,0,0,23,159,
  	1,0,0,0,25,161,1,0,0,0,27,163,1,0,0,0,29,165,1,0,0,0,31,167,1,0,0,0,33,
  	169,1,0,0,0,35,171,1,0,0,0,37,173,1,0,0,0,39,175,1,0,0,0,41,177,1,0,0,
  	0,43,179,1,0,0,0,45,181,1,0,0,0,47,183,1,0,0,0,49,185,1,0,0,0,51,187,
  	1,0,0,0,53,189,1,0,0,0,55,191,1,0,0,0,57,193,1,0,0,0,59,195,1,0,0,0,61,
  	197,1,0,0,0,63,199,1,0,0,0,65,201,1,0,0,0,67,203,1,0,0,0,69,205,1,0,0,
  	0,71,207,1,0,0,0,73,210,1,0,0,0,75,214,1,0,0,0,77,221,1,0,0,0,79,231,
  	1,0,0,0,81,237,1,0,0,0,83,241,1,0,0,0,85,243,1,0,0,0,87,248,1,0,0,0,89,
  	90,5,1094,0,0,90,91,5,1110,0,0,91,92,5,1083,0,0,92,93,5,1100,0,0,93,2,
  	1,0,0,0,94,95,5,1076,0,0,95,96,5,1110,0,0,96,97,5,1103,0,0,97,4,1,0,0,
  	0,98,99,5,1079,0,0,99,100,5,1073,0,0,100,101,5,1077,0,0,101,102,5,1088,
  	0,0,102,103,5,1077,0,0,103,104,5,1075,0,0,104,105,5,1090,0,0,105,106,
  	5,1080,0,0,106,6,1,0,0,0,107,108,5,1074,0,0,108,109,5,1080,0,0,109,110,
  	5,1076,0,0,110,111,5,1072,0,0,111,112,5,1083,0,0,112,113,5,1080,0,0,113,
  	114,5,1090,0,0,114,115,5,1080,0,0,115,8,1,0,0,0,116,117,5,1103,0,0,117,
  	118,5,1082,0,0,118,119,5,1097,0,0,119,120,5,1086,0,0,120,10,1,0,0,0,121,
  	122,5,1110,0,0,122,123,5,1085,0,0,123,124,5,1072,0,0,124,125,5,1082,0,
  	0,125,126,5,1096,0,0,126,127,5,1077,0,0,127,12,1,0,0,0,128,129,5,1087,
  	0,0,129,130,5,1086,0,0,130,131,5,1082,0,0,131,132,5,1080,0,0,132,14,1,
  	0,0,0,133,134,5,1074,0,0,134,135,5,1077,0,0,135,136,5,1088,0,0,136,137,
  	5,1085,0,0,137,138,5,1091,0,0,138,139,5,1090,0,0,139,140,5,1080,0,0,140,
  	16,1,0,0,0,141,142,5,1089,0,0,142,143,5,1090,0,0,143,144,5,1088,0,0,144,
  	145,5,1091,0,0,145,146,5,1082,0,0,146,147,5,1090,0,0,147,148,5,1091,0,
  	0,148,149,5,1088,0,0,149,150,5,1072,0,0,150,18,1,0,0,0,151,152,5,1089,
  	0,0,152,153,5,1087,0,0,153,154,5,1083,0,0,154,155,5,1072,0,0,155,156,
  	5,1074,0,0,156,20,1,0,0,0,157,158,5,61,0,0,158,22,1,0,0,0,159,160,5,62,
  	0,0,160,24,1,0,0,0,161,162,5,60,0,0,162,26,1,0,0,0,163,164,5,46,0,0,164,
  	28,1,0,0,0,165,166,5,43,0,0,166,30,1,0,0,0,167,168,5,45,0,0,168,32,1,
  	0,0,0,169,170,5,42,0,0,170,34,1,0,0,0,171,172,5,47,0,0,172,36,1,0,0,0,
  	173,174,5,37,0,0,174,38,1,0,0,0,175,176,5,94,0,0,176,40,1,0,0,0,177,178,
  	5,38,0,0,178,42,1,0,0,0,179,180,5,124,0,0,180,44,1,0,0,0,181,182,5,40,
  	0,0,182,46,1,0,0,0,183,184,5,41,0,0,184,48,1,0,0,0,185,186,5,91,0,0,186,
  	50,1,0,0,0,187,188,5,93,0,0,188,52,1,0,0,0,189,190,5,63,0,0,190,54,1,
  	0,0,0,191,192,5,58,0,0,192,56,1,0,0,0,193,194,5,126,0,0,194,58,1,0,0,
  	0,195,196,5,39,0,0,196,60,1,0,0,0,197,198,5,34,0,0,198,62,1,0,0,0,199,
  	200,5,33,0,0,200,64,1,0,0,0,201,202,5,44,0,0,202,66,1,0,0,0,203,204,5,
  	59,0,0,204,68,1,0,0,0,205,206,5,123,0,0,206,70,1,0,0,0,207,208,5,125,
  	0,0,208,72,1,0,0,0,209,211,3,83,41,0,210,209,1,0,0,0,211,212,1,0,0,0,
  	212,210,1,0,0,0,212,213,1,0,0,0,213,74,1,0,0,0,214,218,3,85,42,0,215,
  	217,3,87,43,0,216,215,1,0,0,0,217,220,1,0,0,0,218,216,1,0,0,0,218,219,
  	1,0,0,0,219,76,1,0,0,0,220,218,1,0,0,0,221,225,5,34,0,0,222,224,8,0,0,
  	0,223,222,1,0,0,0,224,227,1,0,0,0,225,223,1,0,0,0,225,226,1,0,0,0,226,
  	228,1,0,0,0,227,225,1,0,0,0,228,229,5,34,0,0,229,78,1,0,0,0,230,232,5,
  	13,0,0,231,230,1,0,0,0,231,232,1,0,0,0,232,233,1,0,0,0,233,234,5,10,0,
  	0,234,235,1,0,0,0,235,236,6,39,0,0,236,80,1,0,0,0,237,238,7,1,0,0,238,
  	239,1,0,0,0,239,240,6,40,0,0,240,82,1,0,0,0,241,242,2,48,57,0,242,84,
  	1,0,0,0,243,244,7,2,0,0,244,86,1,0,0,0,245,249,3,85,42,0,246,249,7,3,
  	0,0,247,249,3,85,42,0,248,245,1,0,0,0,248,246,1,0,0,0,248,247,1,0,0,0,
  	249,88,1,0,0,0,6,0,212,218,225,231,248,1,0,1,0
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
