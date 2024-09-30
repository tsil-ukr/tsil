parser grammar TsilParser;

options {
    tokenVocab=TsilLexer;
}

file: f_program=program EOF;

program: body_element*;

atom: '(' expr ')' #atom_nested
    | id=ID #atom_subject
    | object=atom ':' ':' id=ID #atom_section_get
    | object=atom '<' (type (',' type)*)? '>' #atom_template_get
    | object=atom '.' id=ID #atom_get
    | object=atom '[' position=expr ']' #atom_position_get
    | object=atom '(' (expr (',' expr)*)? ')' #atom_call;

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
         | left=operation op='як' right=type #operation_as
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

gendef: ID;

expr: operation #expr_operation
    | type '{' (arg=expr (',' arg=expr))? '}' #expr_object;

structure_define: 'структура' id=ID ('<' first_gendef=gendef (',' gendef)* '>')? (';' | ('{' (structure_element)* '}'));
structure_element: param ';';

diia_define: (extern='зовнішня' | local='місцева' | intern='внутрішня')? 'дія' id=ID ('<' first_gendef=gendef (',' gendef)* '>')? '(' (param (',' param)*)? ')' (':' restyp=type)? (';' | body);

tsil_define: (td_var='змінна' | td_immut='стала' | td_const='ціль') id=ID (':' type)? ('=' value=expr)? ';';

assign: id=ID '=' value=expr ';';

synonym: 'синонім' id=ID ('<' first_gendef=gendef (',' gendef)* '>')? '=' expr ';';

section_define: 'секція' id=ID (body)?;

set: object=atom '.' id=ID '=' value=expr ';';
position_set: object=atom '[' idx=expr ']' '=' value=expr ';';
section_set: object=atom ':' ':' id=ID '=' value=expr ';';

if: 'якщо' cond=operation ifok=body ('інакше' (ifnot=body | ifnotif=if))?;
while: 'поки' cond=operation body;

body: '{' (body_element)* '}';
body_element: structure_define
            | diia_define
            | tsil_define
            | assign
            | set | section_set | position_set
            | synonym
            | section_define
            | if
            | while
            | (expr ';')
            | body
            | return
            | semi=';';
return: 'вернути' value=expr ';';

type: '(' type ')' #type_nested
    | id=ID #type_subject
    | object=type ':' ':' id=ID #type_section_get
    | object=type '<' type (',' type)* '>' #type_template_get
    | object=type '.' id=ID #type_get
    | left=type '[' size=NUMBER ']' #type_array
    | '(' ')' '-' '>' restyp=type #type_fn
    | param_type=type '-' '>' restyp=type #type_fn_simple
    | '(' type (',' type)+ ')' '-' '>' restyp=type #type_fn_complex
    | '(' param (',' param)* ')' '-' '>' restyp=type #type_fn_complex_named;

param: id=ID (':' type)?;
