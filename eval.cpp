#include "eval.hpp"

int eval_program(program* p) {
	return eval_num_expr(p->body);
}

int eval_num_expr(num_expr* e){
	switch(e->kind) {
		case int_kind: 
      return eval_int_lit(static_cast<int_lit*>(e));
    case arg_kind:
      return eval_arg_expr(static_cast<arg_expr*>(e));
    case arith_kind:
      return eval_arith_expr(static_cast<arith_expr*>(e));
	}
	
}
int eval_int_lit(int_lit* e){
	return e->int_val;
}
int eval_arg_expr(arg_expr* e){
	return e->arg;
}
int eval_arith_expr(arith_expr* e){
	switch(e->op) {
		case add_op:
			return eval_num_expr(e->lhs) + eval_num_expr(e->rhs);
		case sub_op:
			return eval_num_expr(e->lhs) - eval_num_expr(e->rhs);
		case mul_op:
			return eval_num_expr(e->lhs) *eval_num_expr(e->rhs);
	}
}
