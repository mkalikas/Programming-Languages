#pragma once 
#include "ast.hpp"

// Valuation functions for expressions
value eval(const expr* e);
value eval_arith_expr(const arith_expr* e);
value eval_logical_expr(const logical_expr* e);
value eval_cond_expr(const cond_expr* e);
value eval_rel_expr(const rel_expr* e);

