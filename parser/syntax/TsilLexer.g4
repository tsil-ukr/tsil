lexer grammar TsilLexer;

KW_TSIL: 'ціль';
KW_DIIA: 'дія';
KW_SAVE: 'зберегти';
KW_DELETE: 'видалити';
KW_IF: 'якщо';
KW_ELSE: 'інакше';
KW_WHILE: 'поки';
KW_RETURN: 'вернути';
KW_STRUCT: 'структура';

EQUAL: '=';
GREATER: '>';
LESSER: '<';
DOT: '.';
PLUS: '+';
MINUS: '-';
MULTIPLY: '*';
DIVIDE: '/';
MOD: '%';
POWER: '^';
AND: '&';
OR: '|';
PAREN_OPEN: '(';
PAREN_CLOSE: ')';
BRACKET_OPEN: '[';
BRACKET_CLOSE: ']';
QUESTION: '?';
COLON: ':';
TILDA: '~';
QUOTE: '\'';
DOUBLE_QUOTE: '"';
EXCLAMATION: '!';
COMA: ',';
SEMICOLON: ';';
QUOTE_OPEN: '{';
QUOTE_CLOSE: '}';

NUMBER: DIGIT+;

ID: ID_START ID_CONTINUE*;

STRING: '"' ( ~["\n\r] )* '"';

NL: ( '\r'? '\n' ) -> channel(HIDDEN);
WS: (' ' | '\t') -> channel(HIDDEN);

fragment DIGIT
    : '0'..'9'
    ;

fragment ID_START
    : 'a'..'z' | 'A'..'Z'
    | 'а'..'я' | 'А'..'Я' | 'і' | 'І' | 'ї' | 'Ї' | 'є' | 'Є' | 'ґ' | 'Ґ'
    | '_'
    ;

fragment ID_CONTINUE
    : ID_START
    | '0'..'9'
    | 'ʼ'
    | ID_START
    ;