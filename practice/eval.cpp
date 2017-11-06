#include "eval.hpp"

int eval_program(program* p) {
  return eval_num_expr(p->body);
}
int eval_int_expr(expr* e) {
  switch(e->kind) {
    case ek_ref:
    case ek_abs:
    case ek_app:
    case ek_int: 
      return e->int_val;
    case ek_arg:
      return e->arg;
    case ek_arith:
      return eval_arith_expr(static_cast<arith_expr*>(e));
    case ek_if: 

    case ek_not:

    case ek_ref:
    case ek_abs:
    case ek_app:

    case ek_relational:
  }

}

int eval_arith_expr(arith_expr* e) {
  switch(e->op) {
    case add_op:
      return eval_num_expr(e->lhs) + eval_num_expr(e->rhs);
    case sub_op:
      return eval_num_expr(e->lhs) - eval_num_expr(e->rhs);
    case mul_op:
      return eval_num_expr(e->lhs) *eval_num_expr(e->rhs);
  }
}
bool eval_bool_expr(bool_expr* e) {
  case ek_logical:
    return eval_logical_expr(static_cast<log ical_expr*>(e));
  case ek_bool: 
    return e->bool_val;
  case ek_cond:
    return eval_cond_expr(static_cast<cond_expr*>(e));
  case ek_relational:
    return eval_rel_expr(static_cast<rel_expr*>(e));

}
bool eval_logical_expr(logical_expr* e) {
  switch(e->op) {
    case and_op:

    case or_op:
  }
}
bool eval_cond_expr(cond_expr* e) {

}
bool eval_rel_expr(rel_expr*e) {
  switch(e->op) {
    case lt_op:
    case gt_op:
    case eq_op:
  }
}
