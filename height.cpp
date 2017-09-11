#include "el_ast.hpp"
#include <algorithm>

int nheight(num_expr* node) {
	if(!node)
		return 0;

	switch(node->kind){
		case int_kind:
			return 0;
		case arg_kind:
			return 1;
		case arith_kind:
			arith_expr* a;
			return 1 + std::max(nheight(a->lhs), nheight(a->rhs));
		case if_kind:
			if_expr* i;
			return 1 + std::max(bheight(i->test), nheight(i->pass), nheight(i->fail));

	}
}

int bheight() {

}
