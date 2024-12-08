lexer grammar TsilLexer;

KW_TSIL: 'ціль';
KW_DIIA: 'дія';
KW_IF: 'якщо';
KW_ELSE: 'інакше';
KW_WHILE: 'поки';
KW_RETURN: 'вернути';
KW_DEFER: 'відкласти';
KW_STRUCT: 'структура';
KW_VARIATION: 'варіація';
KW_AS: 'як';
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
KW_VAR: 'змінна';
KW_IMMUT: 'стала';
KW_SYNONYM: 'синонім';
KW_EXEC: 'виконати';
KW_TRY: 'спробувати';
KW_CATCH: 'зловити';
KW_THROW: 'впасти';
KW_GOTO: 'стрибнути';
KW_ENUM: 'перелік';
KW_ENUMERATE: 'перелічити';
KW_IS: 'є';

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

NUMBER: TYPED_INTEGER | INTEGER | TYPED_FLOAT | FLOAT | HEX | BIN;

TYPED_INTEGER: INTEGER ('_')? ('ц8' | 'ц16' | 'ц32' | 'ц64' | 'п8' | 'п16' | 'п32' | 'п64' | 'д32' | 'д64' | 'Ц' | 'П' | 'Д');
INTEGER: INTEGER_START INTEGER_CONTINUE*;
fragment INTEGER_START: DIGIT;
fragment INTEGER_CONTINUE: ('_')? DIGIT;

TYPED_FLOAT: FLOAT ('_')? ('ц8' | 'ц16' | 'ц32' | 'ц64' | 'п8' | 'п16' | 'п32' | 'п64' | 'д32' | 'д64' | 'Ц' | 'П' | 'Д');
FLOAT: FLOAT_START FLOAT_CONTINUE* '.' FLOAT_START FLOAT_CONTINUE*;
fragment FLOAT_START: DIGIT;
fragment FLOAT_CONTINUE: ('_')? DIGIT;

HEX: '0' ('ш' | 'Ш') HEX_START HEX_CONTINUE*;
fragment HEX_START: ('А' | 'а' | 'Б' | 'б' | 'В' | 'в' | 'Г' | 'г' | 'Д' | 'д' | 'Е' | 'е' | DIGIT);
fragment HEX_CONTINUE: ('_')? ('А' | 'а' | 'Б' | 'б' | 'В' | 'в' | 'Г' | 'г' | 'Д' | 'д' | 'Е' | 'е' | DIGIT);

BIN: '0' ('д' | 'Д') BIN_START BIN_CONTINUE*;
fragment BIN_START: ('0' | '1');
fragment BIN_CONTINUE: ('_')? ('0' | '1');

fragment DIGIT: '0'..'9';

ID: ID_START ID_CONTINUE*;
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

STRING: '"' ( ~["\n\r] | '\\"' )* '"';

COMMENT: '/' '*' (COMMENT | .)*? '*' '/' -> channel(HIDDEN);
LINE_COMMENT: '/' '/' (LINE_COMMENT | ~[\r\n])* -> channel(HIDDEN);

WS: (' ' | '\t') -> channel(HIDDEN);
NL: ('\r'? '\n') -> channel(HIDDEN);