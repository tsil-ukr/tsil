parser grammar TsilParser;

options {
    tokenVocab=TsilLexer;
}

file: f_program=program EOF;

program: program_element*;
program_element: structure | diia_declaration |  diia | section | ';';

structure: 'структура' s_name=identifier ('<' s_generics=structure_generics '>')? '{' (s_params=structure_params)? '}';
structure_generics: structure_generic (',' structure_generic)*;
structure_generic: sg_name=identifier;
structure_params: structure_param (',' structure_param)* ','?;
structure_param: sp_name=identifier ':' sp_type=full_type;

constructor: (c_new='зберегти')? c_type=full_type '{' (c_args=constructor_args)? '}';
constructor_args: constructor_arg (',' constructor_arg)* ','?;
constructor_arg: ca_name=identifier '=' ca_value=expr;

diia_head: 'дія' d_name=identifier ('<' d_generics=diia_generics '>')? '(' (d_params=params)? (d_variadic=',' '.' '.' '.')? ')' ('-' '>' d_type=full_type)?;
diia: (d_extern='екстерн' (d_extern_type=string)?)? d_head=diia_head '{' (d_body=body)? '}';
diia_declaration: (d_extern='екстерн' (d_extern_type=string)?)? d_head=diia_head ('як' d_as=identifier)? ';';
diia_generics: diia_generic (',' diia_generic)*;
diia_generic: dg_name=identifier;

section: 'секція' s_name=identifier '{' section_element* '}';
section_element: structure | diia_declaration |  diia | section | ';';

if: 'якщо' i_value=expr '{' (i_body=body)? '}' ('інакше' '{' (i_else_body=body)? '}')?;

while: 'поки' w_value=expr '{' (w_body=body)? '}';

define: 'ціль' d_id=identifier (':' d_type=full_type)? '=' d_value=expr
      | 'ціль' d_id=identifier ':' d_type=full_type;

assign: a_id=identifier '=' a_value=expr;

set: s_left=identifiers_chain '.' s_id=identifier '=' s_value=expr;

sizeof: 'розмір!' '(' (s_type=full_type | s_value=expr) ')';

atom: identifier #atom_identifier
    | g_left=atom '.' g_id=identifier #get
    | c_value=atom ('<' c_first_generic_type=full_type (',' full_type)* '>')? '(' (c_args=args)? ')' #call
    | '+' p_value=atom  #positive
    | '-' n_value=atom  #negative
    | '!' n_value=atom  #not
    | '~' bn_value=atom  #bitwise_not
    | '(' n_value=expr ')' #nested;

// wtf is this?
molecule: atom #value_atom
        | number #atom_number
        | string #atom_string;

expr: molecule #expr_molecule
    | constructor #atom_constructor
    | sizeof #atom_sizeof
    | a_left=molecule 'як' a_type=full_type #as
    | 'не' nt_value=molecule #not_text
    | a_left=expr a_operation=('*' | '/' | '%') a_right=expr #arithmetic_mul
    | a_left=expr a_operation=('+' | '-') a_right=expr #arithmetic_add
    | b_left=expr b_operation=bitwise_op b_right=expr #bitwise
    | c_left=expr c_operation=comparison_op c_right=expr #comparison
    | t_left=expr t_operation=logical_op t_right=expr #logical
    ;

identifiers_chain: ic_id=ID |  ic_left=identifiers_chain '.' ic_right=ID;

full_type: identifier ('<' t_first_generic_type=full_type (',' full_type)* '>')? ('[' ft_arr_size=expr ']')? #type
         | sft_arg=full_type '-' '>' sft_ret=full_type #simple_function_type
         | '(' (cft_args=simple_function_type_args)? ')' '-' '>' cft_ret=full_type #complex_function_type;
simple_function_type_args: full_type (',' full_type)*;

args: expr (',' expr)* (',')?;

params: param (',' param)* (',')?;
param: p_name=identifier ':' p_type=full_type;

body: body_element_or_return+;
body_element_or_return: body_element | (return_body_element ';');
body_element: if | while | (define ';') | (assign ';') | (set ';') | (expr ';') | ';';
return_body_element: 'вернути' (rbl_value=expr)?;

bitwise_op: '^' | '|' | '&' | '<' '<' | '>' '>';
comparison_op: '=' '=' | '!' '=' | '>' | '<' | '>' '=' | '<' '=';
logical_op: '|' '|' | '&' '&' | 'або' | 'і';

number: INTEGER | FLOAT | HEX | BIN;
string: (s_prefix=ID)?  STRING;
identifier: ID;