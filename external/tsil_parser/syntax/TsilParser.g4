parser grammar TsilParser;

options {
    tokenVocab=TsilLexer;
}

file: f_program=program EOF;

program: body_element*;

// a::b<c>(d)[e]
atom: '(' expr ')' #atom_nested
    | id=ID #atom_subject
    | object=atom ':' ':' id=ID #atom_section_get
    | object=atom '<' (type (',' type)*)? '>' #atom_template_get
    | object=atom '.' id=ID #atom_get
    | object=atom '[' position=expr ']' #atom_position_get
    | object=atom '(' (call_arg (',' call_arg)*)? ')' #atom_call;
call_arg: expr | typeless_object;

operation: NUMBER #operation_number
         | (tt=ID)? STRING #operation_string
         | atom #operation_atom
         | left=operation op='як' (right_type=type | right_tsil='ціль') #operation_as
         | op='!' right=operation #operation_pre_not
         | op='~' right=operation #operation_pre_bw_not
         | op='+' right=operation #operation_pre_plus
         | op='-' right=operation #operation_pre_minus
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

gendef: ID;

expr: operation #expr_operation
    | simple_type '{' (object_arg (',' object_arg)* ','?)? '}' #expr_object;
object_arg: ((id=ID '=')? (value_expr=expr | value_object=typeless_object)) | autofill='.' '.' '.';
typeless_object: '{' (object_arg (',' object_arg)* ','?)? '}';

structure_define: 'структура' id=ID ('<' first_gendef=gendef (',' gendef)* '>')? (';' | ('{' (structure_element)* '}'));
structure_element: param ';';

diia_define: (extern='зовнішня' | local='місцева' | intern='внутрішня')? 'дія' id=ID ('<' first_gendef=gendef (',' gendef)* '>')? '(' (param (',' param)*)? ')' (':' restyp=type)? (';' | body);

tsil_define: (td_external='зовнішня' | td_local='місцева' | td_internal='внутрішня')? (td_var='змінна' | td_immut='стала')? 'ціль' id=ID (':' type)? ('=' (value_expr=expr | value_object=typeless_object))? ';';

assign: id=ID assign_op (value_expr=expr | value_object=typeless_object) ';';

synonym: 'синонім' id=ID ('<' first_gendef=gendef (',' gendef)* '>')? '=' (value_expr=expr | value_object=typeless_object | value_type=type) ';';
synonym_fn: 'синонім' id=ID ('<' first_gendef=gendef (',' gendef)* '>')? '(' ')' '=' '>' (value_expr=expr | value_object=typeless_object | value_type=type) ';';

section_define: 'секція' id=ID (body)?;

set: object=atom '.' id=ID assign_op (value_expr=expr | value_object=typeless_object) ';';
position_set: object=atom '[' idx=expr ']' assign_op (value_expr=expr | value_object=typeless_object) ';';
section_set: object=atom ':' ':' id=ID assign_op (value_expr=expr | value_object=typeless_object) ';';

assign_op: (aop_mul='*' | aop_div='/' | aop_mod='%' | aop_plus='+' | aop_minus='-' | op_lshift | op_rshift | op_urshift | aop_and='&' | aop_xor='^' | aop_or='|')? '=';

if: 'якщо' cond=operation ifok=body ('інакше' (ifnot=body | ifnotif=if))?;
while: 'поки' cond=operation body;

exec: 'виконати' body ';';

body: '{' (body_element)* '}';
body_element: structure_define
            | diia_define
            | tsil_define
            | assign
            | set
            | section_set
            | position_set
            | synonym
            | synonym_fn
            | section_define
            | if
            | while
            | (expr ';')
            | body
            | exec
            | return
            | preproc
            | take
            | semi=';';
return: 'вернути' (value_expr=expr | value_object=typeless_object)? ';';

simple_type: id=ID #simple_type_subject
           | object=simple_type ':' ':' id=ID #simple_type_section_get
           | object=simple_type '<' type (',' type)* '>' #simple_type_template_get
           | object=simple_type '.' id=ID #simple_type_get
           | left=simple_type '[' size=NUMBER ']' #simple_type_array;
single_type: simple_type #type_simple_type
           | '(' ')' '-' '>' restyp=type #type_fn
           | param_type=single_type '-' '>' restyp=type #type_fn_simple
           | '(' type (',' type)* ')' '-' '>' restyp=type #type_fn_complex
           | '(' param (',' param)* ')' '-' '>' restyp=type #type_fn_complex_named;
type: '(' type ')' #type_nested
    | single_type #type_single
    | single_type ('|' single_type)+ #type_variation;

param: id=ID (':' type)?;

preproc: '%' '[' 'якщо' cond=operation ']' (body_element)* ('%' '[' 'інакше' ']' (body_element)*)? '%' '[' '/' 'якщо' ']' #preproc_if
       | '%' '[' 'впасти' cond=operation ']' #preproc_throw;

take: 'взяти' (type_id=ID)? take_element ('/' take_element)* ';';
take_element: ID | STRING;