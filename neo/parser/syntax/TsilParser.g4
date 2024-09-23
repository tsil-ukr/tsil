parser grammar TsilParser;

options {
    tokenVocab=TsilLexer;
}

file: f_program=program EOF;

program: body_element*;

atom: '(' expr ')' #atom_nested
    | ID #atom_subject
    | atom ':' ':' ID #atom_section_get
    | atom '<' type (',' type)* '>' #atom_template_get
    | atom '.' ID #atom_get
    | atom '[' expr ']' #atom_position_get
    | atom '(' expr (',' expr)* ')' #atom_call;

operation: NUMBER #operation_number
         | STRING #operation_string
         | atom #operation_atom
         | operation '*' operation #operation_mul
         | operation '/' operation #operation_div
         | operation '%' operation #operation_mod
         | operation '+' operation #operation_add
         | operation '-' operation #operation_sub
         | operation '<' '<' operation #operation_lshift
         | operation '>' '>' operation #operation_rshift
         | operation '>' '>' '>' operation #operation_urshift
         | operation '<' operation #operation_lt
         | operation '<' '=' operation #operation_lte
         | operation '>' operation #operation_gt
         | operation '>' '=' operation #operation_gte
         | operation '=' '=' operation #operation_eq
         | operation '!' '=' operation #operation_neq
         | operation '&' operation #operation_and
         | operation '^' operation #operation_xor
         | operation '|' operation #operation_or
         | operation '&' '&' operation #operation_land
         | operation '|' '|' operation #operation_lor
         | operation '?' operation ':' operation #operation_ternary;

expr: operation #expr_operation;

structure_declare: 'структура' ID ('<' ID (',' ID)* '>')?;
structure_define: 'структура' ID ('<' ID (',' ID)* '>')? '{' (structure_element)* '}';
structure_element: param ';';

diia_declare: ('зовнішня' | 'місцева' | 'внутрішня') 'дія' ID ('<' ID (',' ID)* '>')? '(' (param (',' param)*)? ')' (':' type)?;
diia_define: ('зовнішня' | 'місцева' | 'внутрішня') 'дія' ID ('<' ID (',' ID)* '>')? '(' (param (',' param)*)? ')' (':' type)? body;

tsil_declare: (td_var='змінна' | td_immut='стала' | td_const='ціль') ID (':' type)? ';';
tsil_define: (td_var='змінна' | td_immut='стала' | td_const='ціль') ID (':' type)? '=' expr ';';

synonym: 'синонім' ID '=' expr ';';

section_declare: 'секція' ID;
section_define: 'секція' ID body;

set: atom '.' ID '=' expr ';';
section_set: atom ':' ':' ID '=' expr ';';
position_set: atom '[' expr ']' '=' expr ';';

if: 'якщо' operation body ('інакше' (body | if))?;
while: 'поки' operation body;

body: '{' (body_element)* '}';
body_element: structure_declare | structure_define
            | diia_declare | diia_define
            | tsil_declare | tsil_define
            | set | section_set | position_set
            | synonym
            | section_declare | section_define
            | expr
            | if
            | while
            | body
            | ';';

type: '(' type ')' #type_nested
    | ID #type_subject
    | type ':' ':' ID #type_section_get
    | type '<' type (',' type)* '>' #type_template_get
    | type '.' ID #type_get
    | type '[' NUMBER ']' #type_array
    | type '-' '>' type #type_fn_simple
    | '(' type (',' type)+ ')' '-' '>' type #type_fn_complex
    | '(' param (',' param)* ')' '-' '>' type #type_fn_complex_named;

param: ID ':' type;
