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

NUMBER: INTEGER | FLOAT | HEX | BIN;

INTEGER: INTEGER_PART_START INTEGER_PART_CONTINUE* ('ц8' | 'ц16' | 'ц32' | 'ц64' | 'п8' | 'п16' | 'п32' | 'п64')?;
fragment INTEGER_PART_START: DIGIT;
fragment INTEGER_PART_CONTINUE: ('_')? DIGIT;

FLOAT: FLOAT_PART_START FLOAT_PART_CONTINUE* '.' FLOAT_PART_START FLOAT_PART_CONTINUE* ('д32' | 'д64')?;
fragment FLOAT_PART_START: DIGIT;
fragment FLOAT_PART_CONTINUE: ('_')? DIGIT;

HEX: '0' ('ш' | 'Ш') HEX_PART_START HEX_PART_CONTINUE*;
fragment HEX_PART_START: ('А' | 'а' | 'Б' | 'б' | 'В' | 'в' | 'Г' | 'г' | 'Ґ' | 'ґ' | 'Д' | 'д' | DIGIT);
fragment HEX_PART_CONTINUE: ('_')? ('А' | 'а' | 'Б' | 'б' | 'В' | 'в' | 'Г' | 'г' | 'Ґ' | 'ґ' | 'Д' | 'д' | DIGIT);

BIN: '0' ('д' | 'Д') BIN_PART_START BIN_PART_CONTINUE*;
fragment BIN_PART_START: ('0' | '1');
fragment BIN_PART_CONTINUE: ('_')? ('0' | '1');

ID: ID_START ID_CONTINUE*;

STRING: '"' ( ~["\n\r] | '\\"' )* '"';

COMMENT: '/' '*' (COMMENT | .)*? '*' '/' -> channel(HIDDEN);
LINE_COMMENT: '/' '/' (LINE_COMMENT | ~[\r\n])* -> channel(HIDDEN);

WS: (' ' | '\t') -> channel(HIDDEN);
NL: ('\r'? '\n') -> channel(HIDDEN);

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