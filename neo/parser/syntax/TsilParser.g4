parser grammar TsilParser;

options {
    tokenVocab=TsilLexer;
}

file: f_program=program EOF;

program: body_element*;

atom: '(' expr ')' #atom_nested
    | id=ID #atom_subject
    | object=atom ':' ':' id=ID #atom_section_get
    | object=atom '<' type (',' type)* '>' #atom_template_get
    | object=atom '.' id=ID #atom_get
    | object=atom '[' position=expr ']' #atom_position_get
    | object=atom '(' expr (',' expr)* ')' #atom_call;

operation: NUMBER #operation_number
         | (tt=ID)? STRING #operation_string
         | atom #operation_atom
         | left=operation op='*' right=operation #operation_mul
         | left=operation op='/' right=operation #operation_div
         | left=operation op='%' right=operation #operation_mod
         | left=operation op='+' right=operation #operation_add
         | left=operation op='-' right=operation #operation_sub
         | left=operation op=op_lshift right=operation #operation_lshift
         | left=operation op=op_rshift right=operation #operation_rshift
         | left=operation op=op_urshift right=operation #operation_urshift
         | left=operation op='<' right=operation #operation_lt
         | left=operation op=op_lte right=operation #operation_lte
         | left=operation op='>' right=operation #operation_gt
         | left=operation op=op_gte right=operation #operation_gte
         | left=operation op=op_eq right=operation #operation_eq
         | left=operation op=op_neq right=operation #operation_neq
         | left=operation op='&' right=operation #operation_and
         | left=operation op='^' right=operation #operation_xor
         | left=operation op='|' right=operation #operation_or
         | left=operation op=op_land right=operation #operation_land
         | left=operation op=op_lor right=operation #operation_lor
         | cond=operation '?' ifok=operation ':' ifnot=operation #operation_ternary;

op_lshift: '<' '<';
op_rshift: '>' '>';
op_urshift: '>' '>' '>';
op_lte: '<' '=';
op_gte: '>' '=';
op_eq: '=' '=';
op_neq: '!' '=';
op_land: '&' '&';
op_lor: '|' '|';

expr: operation #expr_operation;

structure_declare: 'структура' id=ID ('<' generic_id=ID (',' generic_id=ID)* '>')?;
structure_define: 'структура' id=ID ('<' generic_id=ID (',' generic_id=ID)* '>')? '{' (structure_element)* '}';
structure_element: param ';';

diia_declare: ('зовнішня' | 'місцева' | 'внутрішня') 'дія' id=ID ('<' generic_id=ID (',' generic_id=ID)* '>')? '(' (param (',' param)*)? ')' (':' restyp=type)?;
diia_define: ('зовнішня' | 'місцева' | 'внутрішня') 'дія' id=ID ('<' generic_id=ID (',' generic_id=ID)* '>')? '(' (param (',' param)*)? ')' (':' restyp=type)? body;

tsil_declare: (td_var='змінна' | td_immut='стала' | td_const='ціль') id=ID (':' type)? ';';
tsil_define: (td_var='змінна' | td_immut='стала' | td_const='ціль') id=ID (':' type)? '=' expr ';';

synonym: 'синонім' id=ID '=' expr ';';

section_declare: 'секція' id=ID;
section_define: 'секція' id=ID body;

set: object=atom '.' id=ID '=' value=expr ';';
position_set: object=atom '[' idx=expr ']' '=' value=expr ';';
section_set: object=atom ':' ':' id=ID '=' value=expr ';';

if: 'якщо' cond=operation ifok=body ('інакше' (ifnot=body | ifnotif=if))?;
while: 'поки' cond=operation body;

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
    | id=ID #type_subject
    | object=type ':' ':' id=ID #type_section_get
    | object=type '<' template_type=type (',' template_type=type)* '>' #type_template_get
    | object=type '.' id=ID #type_get
    | left=type '[' size=NUMBER ']' #type_array
    | param_type=type '-' '>' restyp=type #type_fn_simple
    | '(' param_type=type (',' param_type=type)+ ')' '-' '>' restyp=type #type_fn_complex
    | '(' param (',' param)* ')' '-' '>' restyp=type #type_fn_complex_named;

param: ID ':' type;
