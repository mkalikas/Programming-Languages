#pragma once 
#include "el_ast.hpp"

// Valuation functions for numeric expressions
int eval_program(prog* p);
int eval_num_expr(num_expr* e);
int eval_int_lit(int_lit* e);
int eval_arg_expr(arg_expr* e);
int eval_arith_expr(arith_expr* e);
int eval_if_expr(if_expr* e);

