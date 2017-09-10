#pragma once

enum arith_op {	
	add_op,
	sub_op,
	mul_op,
	div_op,
	rem_op
};

enum relational_op {
	lt_op,
	gt_op,
	eq_op
};

enum logical_op {
	and_op,
	or_op
};

enum num_expr_kind {
	int_kind,
	arg_kind,
	arith_kind,
	if_kind
};

enum bool_expr_kind {
	bool_kind,
	relational_kind,
	logical_kind
};
struct program {
	int args;
	num_expr* body;
};

struct num_expr {
	num_expr_kind kind;
};

struct arith_expr : num_expr {
	arith_op op;
	num_expr* lhs;
	num_expr* rhs;

};

struct if_expr : num_expr {
	bool_expr* test;
	num_expr* pass;
	num_expr* fail;
};

struct bool_expr {
	bool_expr_kind kind;
};

struct rel_expr : bool_expr {
	relational_op op;
	num_expr* lhs;
	num_expr* rhs;

};

struct logical_expr : bool_expr {
	logical_op op;
	bool_expr* lhs;
	bool_expr* rhs;
};
struct arg_expr : num_expr {
	int arg;
};

struct int_lit : num_expr {
	int int_val;
};

struct bool_lit : bool_expr {
	bool bool_val;
};





