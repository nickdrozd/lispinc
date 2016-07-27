#include <stdlib.h>

#include "objects.h"
#include "primitives.h"

/* primitive names */

List* primitive_vars(void) {
	List* prim_arith_vars = 
		makeList(NAMEOBJ(PRIM_ADD), 
			makeList(NAMEOBJ(PRIM_SUB), 
				makeList(NAMEOBJ(PRIM_MUL), 
					makeList(NAMEOBJ(PRIM_DIV), 
						makeList(NAMEOBJ(PRIM_EQ), NULL)))));

	List* vars = prim_arith_vars;

	return vars;
}

/* primitive values */

List* primitive_vals(void) {
	List* prim_arith_vals = 
		makeList(FUNCOBJ(add_), 
			makeList(FUNCOBJ(sub_), 
				makeList(FUNCOBJ(mul_), 
					makeList(FUNCOBJ(div_), 
						makeList(FUNCOBJ(eq_), NULL)))));

	List* vals = prim_arith_vals;

	return vals;
}

/* primitive arithmetic functions */

int add_func(int a, int b) {
	return a + b;
}

int sub_func(int a, int b) {
	return a - b;
}

int mul_func(int a, int b) {
	return a * b;
}

int div_func(int a, int b) {
	return a / b; // floor division
}

int eq_func(int a, int b) {
	if (a == b)
		return 1;
	else
		return 0;
}

intFunc add_ = add_func;
intFunc sub_ = sub_func;
intFunc mul_ = mul_func;
intFunc div_ = div_func;
intFunc eq_ = eq_func;