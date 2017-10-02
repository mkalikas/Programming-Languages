#include "el_ast.hpp"
#include <algorithm>

int height_int_lit(int_lit* e){
  return 0;
}
int height_arg_expr(arg_expr* e) {
  return 0;
}

int height_arith_expr(arith_expr* e) {
  return 1 + std::max(height(e->lhs), height(e->rhs));
}
int height_if_expr(if_expr* e) {
  return 1 + std::max({height(e->test), height(e->pass), height(e->fail)});
}

int height(num_expr* e) {
  switch(e->kind){
    case int_kind: 
      return height_int_lit(static_cast<int_lit*>(e));
    case arg_kind:
      return height_arg_expr(static_cast<arg_expr*>(e));
    case arith_kind:
      return height_arith_expr(static_cast<arith_expr*>(e));
    case if_kind:
      return height_if_expr(static_cast<if_expr*>(e));  
  }
}

int height(bool_expr* b) {
  return 0;
}
int height_relational_expr(rel_expr* e){
  return 1 + std::max(height(e->lhs), height(e->rhs));
}
int height_logical_expr(logical_expr* e) {
  return 1 +std::max(height(e->lhs), height(e->rhs));
}

bool arg_check(program* p) {
  return (p->args == height(p->body));
}