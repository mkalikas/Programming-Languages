#pragma once 
#include "ast.hpp"

// Valuation functions for expressions
int eval_program(program* p);
int eval_int_expr(expr* e);;
int eval_arith_expr(arith_expr* e);
bool eval_bool_expr(bool_expr* e);
bool eval_logical_expr(logical_expr* e);
bool eval_cond_expr(cond_expr* e);
bool eval_rel_expr(rel_expr*e);

