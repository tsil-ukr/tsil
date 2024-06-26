parser grammar TsilParser;

options {
    tokenVocab=TsilLexer;
}

file: f_program=program EOF;

program: program_element*;
program_element: (take ';') | (synonym ';') | (declare ';') | (define ';') | section | structure | diia_declaration | diia | ';';

identifier: ID;
section_access: identifier (':' ':' identifier)* #real_section_access;
number: NUMBER (':' id=identifier)?;
string: (s_prefix=ID)? STRING;

take: 'взяти' t_type=ID (t_string=STRING | t_parts=take_parts);
take_parts: (tp_relative='.' '/')? ID ('/' ID)*;

synonym: 'синонім' s_name=ID '=' s_value=synonym_value;
synonym_value: full_type | number | string;

section: 'секція' s_name=ID '{' section_element* '}';
section_element: (synonym ';') | (declare ';') | (define ';') | section | structure | diia_declaration | diia | ';';

structure: 'структура' s_name=ID ('<' s_generics=structure_generics '>')? ('{' (s_params=structure_params)? '}' | ';');
structure_generics: structure_generic (',' structure_generic)*;
structure_generic: sg_name=ID;
structure_params: (structure_param ';')+;
structure_param: sp_name=ID ':' sp_type=full_type;

variation: 'варіація' v_name=ID (':' v_type=full_type)? ('{' (v_params=variation_params)? '}' | ';');
variation_params: (variation_param ';')+;
variation_param: vp_name=ID ':' vp_type=full_type;

diia_head: 'дія' d_name=ID ('<' d_generics=diia_generics '>')? '(' (d_params=params)? (d_variadic=',' '.' '.' '.')? ')' (':' d_type=full_type)?;
diia: (d_extern='зовнішня' | d_local='місцева' | d_internal='внутрішня')? d_head=diia_head '{' (d_body=body)? '}';
diia_generics: diia_generic (',' diia_generic)*;
diia_generic: dg_name=ID;
diia_declaration: (d_extern='зовнішня' | d_local='місцева' | d_internal='внутрішня')? d_head=diia_head ('як' d_as=ID)? ';';
params: param (',' param)* (',')?;
param: p_name=ID ':' p_type=full_type;

body: body_element+;
body_element: if | while | (synonym ';') | (declare ';') | (define ';') | (assign ';') | (set ';') | (expr ';') | (return_body_element ';') | (defer ';') | block | ';';
return_body_element: 'вернути' (rbl_value=expr)?;
block: '{' body '}';

defer: 'відкласти' (assign | set | expr);

if: 'якщо' i_value=expr '{' (i_body=body)? '}' ('інакше' ('{' (i_else_body=body)? '}' | i_else_if=if))?;

while: 'поки' w_value=expr '{' (w_body=body)? '}';

declare: (d_extern='зовнішня' | d_local='місцева' | d_internal='внутрішня')? (d_tsil='ціль' | d_var='змінна') d_id=ID ':' d_type=full_type;

define: (d_extern='зовнішня' | d_local='місцева' | d_internal='внутрішня')? (d_tsil='ціль' | d_var='змінна') d_id=ID (':' d_type=full_type)? '=' d_value=expr;

assign: a_id=ID '=' a_value=expr;

set: s_left=particle ('.' s_id=ID | '[' s_index=expr ']') '=' s_value=expr;

particle: section_access #particle_section_access
        | g_left=particle '.' g_id=ID #get
        | g_left=particle '<' sa_generic_value=full_type (',' full_type)* '>' #generic
        | a_value=particle '[' (a_index=expr)? ']' #access
        | c_value=particle '(' (c_args=args)? ')' #call
        | '(' n_value=expr ')' #nested;
args: expr (',' expr)* (',')?;

atom: particle #atom_particle
    | number #atom_number
    | string #atom_string;

molecule: atom #molecule_atom
        | '!' n_value=molecule #not
        | '+' p_value=atom #positive
        | '-' n_value=atom #negative
        | '~' bn_value=atom #bitwise_not;

operation: molecule #operation_molecule
         | a_left=molecule 'як' a_type=full_type #as
         | a_left=operation a_operation=('*' | '/' | '%') a_right=operation #mul
         | a_left=operation a_operation=('+' | '-') a_right=operation #add
         | b_left=operation b_operation=bitwise_op b_right=operation #bitwise
         | c_left=operation c_operation=comparison_op c_right=operation #comparison
         | t_left=operation t_operation=logical_op t_right=operation #logical;

expr: c_type=full_type '{' (c_args=construct_args)? '}' #construct
    | operation #expr_operation;
construct_args: construct_arg (',' construct_arg)* ','?;
construct_arg: (ca_name=ID '=')? ca_value=expr;

basic_type: section_access ('<' t_first_generic_type=full_type (',' full_type)* '>')? #simple_type
          | at_type=basic_type '[' at_size=NUMBER ']' #array_type
          | ('(' full_type ')') #full_type_nested;
full_type: basic_type ('|' basic_type)+ #variation_type
         | basic_type #basic_type_real_basic
         | '(' (cft_args=complex_function_type_args)? ')' '-' '>' cft_ret=full_type #complex_function_type
         | sft_arg=full_type '-' '>' sft_ret=full_type #simple_function_type;
complex_function_type_args: full_type (',' full_type)*;

bitwise_op: '^' | '|' | '&' | ('<' '<') | ('>' '>');
comparison_op: ('=' '=') | ('!' '=') | '>' | '<' | ('>' '=') | ('<' '=');
logical_op: ('|' '|') | ('&' '&') | 'або' | 'і';
