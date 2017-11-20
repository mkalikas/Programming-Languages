#include "ast.hpp"

int main() {

  // creates (+ 3 4)
  auto* e = new arith_expr{add_op, new int_expr(3), new int_expr(4)};

  // creates (and true false)
  auto* e2 = new logical_expr{
    and_op, new bool_expr(true), new bool_expr(false)};

  return 0;

}