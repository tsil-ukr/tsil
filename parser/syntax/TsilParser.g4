parser grammar TsilParser;

options {
    tokenVocab=TsilLexer;
}

file: f_program=program EOF;

program: (program_element ';')*;
program_element: structure | diia | if | while | expr | define | assign | set | ';';

structure: 'структура' s_name=ID '{' (s_params=structure_params)? '}';
structure_params: (structure_param ';')+;
structure_param: sp_name=ID sp_type=type;

diia: ('дія' | d_type=type) d_name=ID '(' d_params=params? ')' '{' (d_body=body)? '}';

if: 'якщо' i_value=expr '{' (i_body=body)? '}';

while: 'поки' w_value=expr '{' (w_body=body)? '}';

define: ('ціль' | d_type=type) d_assign=assign;

assign: a_id=ID '=' a_value=expr;

set: identifiers_chain '=' set_value=expr;

atom: NUMBER #number
    | STRING #string
    | ID #identifier
    | c_left=atom '.' c_right=ID #get
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
param: p_type=type p_name=ID;

body: (body_element_or_return ';')+;
body_element_or_return: body_element | return_body_element;
body_element: if | while | expr | define | assign | set | ';';
return_body_element: 'вернути' rbl_value=expr;

bitwise_op: '^' | '|' | '&' | '<' '<' | '>' '>';
comparison_op: '=' '=' | '!' '=' | '>' | '<' | '>' '=' | '<' '=';
logical_op: '|' '|' | '&' '&';
