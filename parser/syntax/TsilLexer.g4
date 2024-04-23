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
KW_AS: 'як';
KW_SIZEOF: 'розмір!';
KW_SECTION: 'секція';
KW_IMPORT: 'взяти';
KW_EXPORT: 'дати';
KW_COMPOSITION: 'композиція';
KW_PROPERTY: 'властивість';
KW_PUBLIC: 'зовнішня';
KW_PRIVATE: 'внутрішня';
KW_LOCAL: 'місцева';
KW_NOT: 'не';
KW_OR: 'або';
KW_AND: 'і';
KW_INCLUDE: 'підключити';

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

INTEGER: DIGIT+;
FLOAT: DIGIT+ '.' DIGIT+;
HEX: '0ш' ('А' | 'а' | 'Б' | 'б' | 'В' | 'в' | 'Г' | 'г' | 'Ґ' | 'ґ' | 'Д' | 'д' | DIGIT)+;
BIN: '0д' ('0' | '1')+;

ID: ID_START ID_CONTINUE*;

STRING: '"' ( ~["\n\r] )* '"';

COMMENT: '/' '*' (COMMENT | .)*? '*' '/' -> channel(HIDDEN);
LINE_COMMENT: '/' '/' (LINE_COMMENT | ~[\r\n])* -> channel(HIDDEN);

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