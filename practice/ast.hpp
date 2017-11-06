#pragma once

#include "type.hpp"
#include "eval.hpp"

struct expr;

// Expressions 
enum expr_kind : int {
  // Lambda Calculus
  ek_ref,
  ek_abs,
  ek_app,

  // Numeric
  ek_int,
  ek_arg,
  ek_if,
  ek_arith,

  // Logical 
  ek_logical
  ek_bool,
  ek_cond,
  ek_and,
  ek_or,
  ek_not,

  // Relational
  ek_relational
};

// Operators for Arithmetic Expressions 
enum arith_op { 
  add_op,
  sub_op,
  mul_op,
  div_op,
  rem_op
};

// Operators for Logical Expressions 
enum logical_op {
  and_op,
  or_op
};

// Operators for Relational Expressions 
enum relational_op {
  lt_op,
  gt_op,
  eq_op
};

enum value_kind
{
  int_val,
  abs_val,
};

struct program 
{
  program(int n, expr* b) : args(n), body(b) {}
  int args;
  expr* body;
};

// The base class of all expressions
struct expr
{
  expr(expr_kind k) : kind(k), t(nullptr) {}

  expr_kind kind;
  type* t;
};

// Integer literal expression
struct int_expr : epxr
{
  int_expr(int v) : expr(ek_int), int_val(v) {}

};

// Input
struct arg_expr : expr 
{
  arg_expr(int a) : expr(ek_arg), arg(a) {}
  
  int arg;
};

// Arithmetic Expressions
struct arith_expr : expr 
{
  arith_expr(arith_op op, expr* l, expr* r) : expr(ek_arith), op(op), lhs(l), rhs(r) {}   
  
  arith_op op;   
  expr* lhs;   
  expr* rhs;

};

// Conditional Expressions 
struct if_expr : expr
{
  if_expr(bool_expr* e1, expr* e2, expr* e3) : expr(ek_if), test(e1), pass(e2), fail(e3) {}
  
  bool_expr* test;
  expr* pass;
  expr* fail;
};

// Boolean literal expression 
struct bool_expr : expr 
{
  bool_expr(bool b) : expr(ek_bool), bool_val(b) {}
  
  bool bool_val;
};

// Relational Expressions
struct rel_expr : expr
{
  rel_expr(relational_op op, expr* l, expr* r) : expr(ek_relational), op(op), lhs(l), rhs(r) {}
  
  relational_op op;
  expr* lhs;
  expr* rhs;

};

// Logical Expression
struct logical_expr : expr 
{
  logical_expr(logical_op op, expr* l, expr* r) : expr(ek_logical), op(op), lhs(l), rhs(r) {}
  
  logical_op op;
  expr* lhs;
  expr* rhs;
};

// Conditional expression.
struct cond_expr : expr
{
  cond_expr(expr* e1, expr* e2, expr* e3)
    : expr(ek_cond), e1(e1), e2(e2), e3(e3)
  {}
  
  expr* e1;
  expr* e2
  expr* e3;
};

struct value
{
  value(value_kind k) : kind(k) {}

  value_kind kind;

};

value evaluate(const expr* e);

// Height Algorithms 
int height(expr* e);
int height(bool_expr* b);






