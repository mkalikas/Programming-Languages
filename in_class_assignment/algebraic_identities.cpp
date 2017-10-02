#include "syntactic_equality.cpp"

prog popt(prog p) {

}

num_expr nopt(num_expr* e) {
  if(const arith_expr* e = static_cast<const arith_expr*>(e); get_expr_kind(e) == ek_arith) {
    switch(e->op) {
      default:
        break;
      case op_add: 
        return e->e1 == int_lit(e->val(0)) ? e->e2 : nopt(e->e2);
      case op_sub: 
        return e->e1;
      case op_mul:

      case op_div:

      case op_rem: 

    }
  }
}

bool_expr bopt (bool_expr* e) {

}

