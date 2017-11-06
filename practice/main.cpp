#include "ast.hpp"

int main() {

  // creates (+ 3 4)
  auto* e = new arith_expr{add_op, new int_lit(3), new int_lit(4)};

  // creates (and true false)
  auto* e2 = new logical_expr{
    and_op, new bool_lit(true), new bool_lit(false)};

  return 0;

}