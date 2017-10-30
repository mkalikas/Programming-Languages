#pragma once

enum expr_kind : int {
  // Lambda Calculus
  ref_expr_kind,
  abs_expr_kind,

  // Boolean Expressions
  bool_expr_kind,
  cond_expr_kind,
};

enum value_kind {
  int_val,
  abs_val,
};

// Base class for expressions
struct expr
{
  expr(expr_kind k) : kind(k) {}

  expr_kind kind;
};

// Boolean literal expression
struct bool_expr : expr
{
  bool_expr(bool b)
    : expr(bool_expr_kind), val(b)
  {}

  bool val;
};

// Conditional expression.
struct cond_expr : expr
{
  cond_expr(expr* e1, expr* e2, expr* e3)
    : expr(cond_expr_kind), cond(e1), true_val(e2), false_val(e3)
  {}
  
  expr* cond;
  expr* true_val;
  expr* false_val;
};


struct value
{
  value(bool b) : kind(int_val) {}

  value_kind kind;
};

value evaluate(const expr* e);


