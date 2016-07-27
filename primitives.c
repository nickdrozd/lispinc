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

	Prim addprim = INTFUNC(add_);
	Prim subprim = INTFUNC(sub_);
	Prim mulprim = INTFUNC(mul_);
	Prim divprim = INTFUNC(div_);
	Prim eqprim = INTFUNC(eq_);

	List* prim_arith_vals = 
		makeList(PRIMOBJ(addprim), 
			makeList(PRIMOBJ(subprim), 
				makeList(PRIMOBJ(mulprim), 
					makeList(PRIMOBJ(divprim), 
						makeList(PRIMOBJ(eqprim), NULL)))));

	List* vals = prim_arith_vals;

	return vals;
}

/* primitive type-checking */

int null_func(Obj obj) {
	int isList = obj.tag == LIST;
	int isNull = obj.val.list == NULL;

	return isList && isNull;
}

objFunc null_ = null_func;

/* primitive arithmetic */

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