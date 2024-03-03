parser grammar TsilParser;

options {
    tokenVocab=TsilLexer;
}

file: f_program=program EOF;

program: program_element*;
program_element: structure | diia_declaration |  diia | if | while | define | assign | set | (expr ';') | ';';

structure: 'структура' s_name=identifier '{' (s_params=structure_params)? '}';
structure_params: (structure_param ';')+;
structure_param: sp_name=identifier sp_type=type;

diia_head: ('дія' | d_type=type) d_name=identifier '(' (d_params=params)? ')';
diia: (d_splav='сплав')? d_head=diia_head '{' (d_body=body)? '}';
diia_declaration: (d_splav='сплав')? d_head=diia_head ';';

if: 'якщо' i_value=expr '{' (i_body=body)? '}';

while: 'поки' w_value=expr '{' (w_body=body)? '}';

define: ('ціль' | d_type=type) d_id=identifier '=' d_value=expr;

assign: a_id=identifier '=' a_value=expr;

set: s_left=identifiers_chain '=' s_value=expr;

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
     | a_left=expr a_operation=('*' | '/' | '%') a_right=expr #arithmetic_mul
     | a_left=expr a_operation=('+' | '-') a_right=expr #arithmetic_add
     | b_left=expr b_operation=bitwise_op b_right=expr #bitwise
     | c_left=expr c_operation=comparison_op c_right=expr #comparison
     | t_left=expr t_operation=logical_op t_right=expr #logical
     ;

identifiers_chain: ic_id=ID |  ic_left=identifiers_chain '.' ic_right=ID;

type: ID;

args: expr (',' expr)* (',')?;

params: param (',' param)* (',')?;
param: p_type=type p_name=identifier;

body: body_element_or_return+;
body_element_or_return: body_element | return_body_element;
body_element: if | while | define | assign | set | (expr ';') | ';';
return_body_element: 'вернути' rbl_value=expr;

bitwise_op: '^' | '|' | '&' | '<' '<' | '>' '>';
comparison_op: '=' '=' | '!' '=' | '>' | '<' | '>' '=' | '<' '=';
logical_op: '|' '|' | '&' '&';

number: NUMBER;
string: STRING;
identifier: ID;