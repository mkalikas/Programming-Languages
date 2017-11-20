#include "eval.hpp"

value eval(const expr* e) {
  switch(e->kind) {
    case ek_int: 
      return value{int_val};
    case ek_arg:
      return value{arg};
    case ek_arith:
      return eval_arith_expr(static_cast<const arith_expr*>(e));
    case ek_if: 

    case ek_not:

    case ek_ref:
    case ek_abs:
    case ek_app:

    case ek_logical:
      return eval_logical_expr(static_cast<const logical_expr*>(e));
    case ek_bool: 
      return value{bool_val};
    case ek_cond:
      return eval_cond_expr(static_cast<const cond_expr*>(e));
    case ek_relational:
      return eval_rel_expr(static_cast<const rel_expr*>(e));
    case ek_tuple:
  }
}

value eval_arith_expr(const arith_expr* e) {
  value v1 = eval(e->lhs);
  value v2 = eval(e->rhs);
  switch(e->op) {
    case add_op:
      return (eval(e->lhs) + eval(e->rhs));
    case sub_op:
      return (eval(e->lhs) - eval(e->rhs));
    case mul_op:
      return (eval(e->lhs) * eval(e->rhs));
    case div_op:
      return (eval(e->lhs) / eval(e->rhs));
    case rem_op:
      return (eval(e->lhs) % eval(e->rhs));
  }
}

value eval_logical_expr(const logical_expr* e) {
  switch(e->op) {
    case and_op:

    case or_op:
  }
}
value eval_cond_expr(const cond_expr* e) {

}

value eval_rel_expr(const rel_expr* e) {
  switch(e->op) {
    case lt_op:
    case gt_op:
    case eq_op:
  }
}
