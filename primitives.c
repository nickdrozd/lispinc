#include <stdlib.h>

#include "objects.h"
#include "primitives.h"

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


	// List* function_vars = 
	// 	makeList(NAMEOBJ(PRIM_ADD), 
	// 		makeList(MKOBJ(NAME, name, PRIM_SUB), 
	// 			makeList(MKOBJ(NAME, name, PRIM_MUL), 
	// 				makeList(MKOBJ(NAME, name, PRIM_DIV), 
	// 					makeList(MKOBJ(NAME, name, PRIM_EQ), NULL)))));

	// List* function_vals = 
	// 	makeList(MKOBJ(FUNC, func, add_), 
	// 		makeList(MKOBJ(FUNC, func, sub_), 
	// 			makeList(MKOBJ(FUNC, func, mul_), 
	// 				makeList(MKOBJ(FUNC, func, div_), 
	// 					makeList(MKOBJ(FUNC, func, eq_), NULL)))));

/* primitive names */

List* primitive_vars(void) {
	List* vars = 
		makeList(NAMEOBJ(PRIM_ADD), 
			makeList(NAMEOBJ(PRIM_SUB), 
				makeList(NAMEOBJ(PRIM_MUL), 
					makeList(NAMEOBJ(PRIM_DIV), 
						makeList(NAMEOBJ(PRIM_EQ), NULL)))));

	return vars;
}

/* primitive arithmetic functions */

List* primitive_vals(void) {
	List* vals = 
		makeList(FUNCOBJ(add_), 
			makeList(FUNCOBJ(sub_), 
				makeList(FUNCOBJ(mul_), 
					makeList(FUNCOBJ(div_), 
						makeList(FUNCOBJ(eq_), NULL)))));
	return vals;
}
