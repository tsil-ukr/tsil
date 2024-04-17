parser grammar TsilParser;

options {
    tokenVocab=TsilLexer;
}

file: f_program=program EOF;

program: program_element*;
program_element: structure | diia_declaration |  diia | if | while | define | assign | set | (expr ';') | ';';

structure: 'структура' s_name=identifier ('<' s_generics=structure_generics '>')? '{' (s_params=structure_params)? '}';
structure_generics: structure_generic (',' structure_generic)*;
structure_generic: sg_name=identifier;
structure_params: structure_param (',' structure_param)* ','?;
structure_param: sp_name=identifier ':' sp_type=type;

constructor: (c_new='покласти')? c_type=type '{' (c_args=constructor_args)? '}';
constructor_args: constructor_arg (',' constructor_arg)* ','?;
constructor_arg: ca_name=identifier '=' ca_value=expr;

diia_head: 'дія' d_name=identifier '(' (d_params=params)? (d_variadic=',' '.' '.' '.')? ')' (':' d_type=type)?;
diia: (d_extern='екстерн')? d_head=diia_head '{' (d_body=body)? '}';
diia_declaration: (d_extern='екстерн')? d_head=diia_head  ('як' d_as=identifier)? ';';

if: 'якщо' i_value=expr '{' (i_body=body)? '}';

while: 'поки' w_value=expr '{' (w_body=body)? '}';

define: 'ціль' d_id=identifier (':' d_type=type)? '=' d_value=expr
      | 'ціль' d_id=identifier ':' d_type=type;

assign: a_id=identifier '=' a_value=expr;

set: s_left=identifiers_chain '.' s_id=identifier '=' s_value=expr;

sizeof: 'розмір типу' s_type=type;

atom: number #atom_number
    | string #atom_string
    | identifier #atom_identifier
    | g_left=atom '.' g_id=identifier #get
    | c_value=atom '(' (c_args=args)? ')' #call
    | '+' p_value=atom  #positive
    | '-' n_value=atom  #negative
    | '!' n_value=atom  #not
    | '~' bn_value=atom  #bitwise_not
    | '(' n_value=expr ')' #nested;

expr: atom #value_atom
     | constructor #atom_constructor
     | sizeof #atom_sizeof
     | a_left=atom 'як' a_type=type #as
     | a_left=expr a_operation=('*' | '/' | '%') a_right=expr #arithmetic_mul
     | a_left=expr a_operation=('+' | '-') a_right=expr #arithmetic_add
     | b_left=expr b_operation=bitwise_op b_right=expr #bitwise
     | c_left=expr c_operation=comparison_op c_right=expr #comparison
     | t_left=expr t_operation=logical_op t_right=expr #logical
     ;

identifiers_chain: ic_id=ID |  ic_left=identifiers_chain '.' ic_right=ID;

type: identifier ('<' t_first_generic_type=type (',' type)* '>')?;

args: expr (',' expr)* (',')?;

params: param (',' param)* (',')?;
param: p_name=identifier ':' p_type=type;

body: body_element_or_return+;
body_element_or_return: body_element | return_body_element;
body_element: if | while | define | assign | set | (expr ';') | ';';
return_body_element: 'вернути' rbl_value=expr;

bitwise_op: '^' | '|' | '&' | '<' '<' | '>' '>';
comparison_op: '=' '=' | '!' '=' | '>' | '<' | '>' '=' | '<' '=';
logical_op: '|' '|' | '&' '&';

number: NUMBER;
string: (s_prefix=ID)?  STRING;
identifier: ID;