#pragma once

struct num_expr;
struct bool_expr;

/* 
  Primitive Syntactic Domains 
  int_lit, bool_lit, arith_op, relational_op, logical_op
*/

// Operators for Arithmetic Expressions 
enum arith_op { 
  add_op,
  sub_op,
  mul_op,
  div_op,
  rem_op
};

// Operators for Relational Expressions 
enum relational_op {
  lt_op,
  gt_op,
  eq_op
};

// Operators for Logical Expressions 
enum logical_op {
  and_op,
  or_op
};

// Kinds of numeric expressions 
enum num_expr_kind {
  int_kind,
  arg_kind,
  arith_kind,
  if_kind
};

// Kinds of boolean expressions 
enum bool_expr_kind {
  bool_kind,
  relational_kind,
  logical_kind
};

struct program {
  program(int n, num_expr* b) : args(n), body(b) {}
  int args;
  num_expr* body;
};

// Numeric Expression
struct num_expr {
  num_expr(num_expr_kind k) : kind(k) {}

  num_expr_kind kind;
};

// Integer Literal
struct int_lit : num_expr {
  int_lit(int v) : num_expr(int_kind), int_val(v) {}

  int int_val;
};

// Input
struct arg_expr : num_expr {
  arg_expr(int a) : num_expr(arg_kind), arg(a) {}
  
  int arg;
};

// Arithmetic Expressions
struct arith_expr : num_expr {
  arith_expr(arith_op op, num_expr* l, num_expr* r) : num_expr(arith_kind), op(op), lhs(l), rhs(r) {}   
  
  arith_op op;   
  num_expr* lhs;   
  num_expr* rhs;

};

// Conditional Expressions 
struct if_expr : num_expr {
  if_expr(bool_expr* e1, num_expr* e2, num_expr* e3) : num_expr(if_kind), test(e1), pass(e2), fail(e3) {}
  
  bool_expr* test;
  num_expr* pass;
  num_expr* fail;
};

// Boolean Expressions 
struct bool_expr {
  bool_expr(bool_expr_kind k) : kind(k) {}
  
  bool_expr_kind kind;
};

// Boolean Literal 
struct bool_lit : bool_expr {
  bool_lit(bool b) : bool_expr(bool_kind), bool_val(b) {}
  
  bool bool_val;
};

// Relational Expressions
struct rel_expr : bool_expr {
  rel_expr(relational_op op, num_expr* l, num_expr* r) : bool_expr(relational_kind), op(op), lhs(l), rhs(r) {}
  
  relational_op op;
  num_expr* lhs;
  num_expr* rhs;

};

// Logical Expression
struct logical_expr : bool_expr {
  logical_expr(logical_op op, bool_expr* l, bool_expr* r) : bool_expr(logical_kind), op(op), lhs(l), rhs(r) {}
  
  logical_op op;
  bool_expr* lhs;
  bool_expr* rhs;
};

// Height Algorithms 
int height(num_expr* e);
int height(bool_expr* b);






