#include "primitives.h"

/* primitive arithmetic functions */

#define PRIM_NULL_NAME "null?"

#define PRIM_ADD_NAME "+"
#define PRIM_SUB_NAME "-"
#define PRIM_MUL_NAME "*"
#define PRIM_DIV_NAME "/"
#define PRIM_EQ_NAME "=" 

twoArgFunc add_;
twoArgFunc sub_;
twoArgFunc mul_;
twoArgFunc div_;
twoArgFunc eq_;

oneArgFunc null_;

/* primitive names */

List* primitive_vars(void) {

	List* prim_arith_vars = 
		makeList(NAMEOBJ(PRIM_ADD_NAME), 
			makeList(NAMEOBJ(PRIM_SUB_NAME), 
				makeList(NAMEOBJ(PRIM_MUL_NAME), 
					makeList(NAMEOBJ(PRIM_DIV_NAME), 
						makeList(NAMEOBJ(PRIM_EQ_NAME), NULL)))));

	// List* vars = prim_arith_vars;

	List* vars =
		makeList(NAMEOBJ(PRIM_NULL_NAME), 
			prim_arith_vars);

	return vars;
}

/* primitive values */

List* primitive_vals(void) {

	Prim addprim = TWOFUNC(add_, PRIM_ADD_NAME);
	Prim subprim = TWOFUNC(sub_, PRIM_SUB_NAME);
	Prim mulprim = TWOFUNC(mul_, PRIM_MUL_NAME);
	Prim divprim = TWOFUNC(div_, PRIM_DIV_NAME);
	Prim eqprim = TWOFUNC(eq_, PRIM_EQ_NAME);

	Prim nullprim = ONEFUNC(null_, PRIM_NULL_NAME);

	List* prim_arith_vals = 
		makeList(PRIMOBJ(addprim), 
			makeList(PRIMOBJ(subprim), 
				makeList(PRIMOBJ(mulprim), 
					makeList(PRIMOBJ(divprim), 
						makeList(PRIMOBJ(eqprim), NULL)))));

	// List* vals = prim_arith_vals;

	List* vals = 
		makeList(PRIMOBJ(nullprim),
			prim_arith_vals);

	return vals;
}

/* primitive type-checking */

// null? returns false for non-list objects
Obj null_func(Obj obj) {
	int isList = GETTAG(obj) == LIST;

	if (!isList)
		return NUMOBJ(isList);

	int isNull = GETLIST(obj) == NULL;

	return NUMOBJ(isNull);
}

oneArgFunc null_ = null_func;

/* primitive list functions 
(not to be confused with the list 
macros found in objects.h!) */

Obj car(Obj obj) {
	return GETLIST(obj)->car;
}

Obj cdr(Obj obj) {
	return LISTOBJ(GETLIST(obj)->cdr);
}

// second object MUST BE list
Obj cons(Obj car, Obj cdr) {
	return LISTOBJ(makeList(car, GETLIST(cdr)));
}

/* primitive arithmetic */

Obj add_func(Obj a, Obj b) {
	return NUMOBJ(GETNUM(a) + GETNUM(b));
}

Obj sub_func(Obj a, Obj b) {
	return NUMOBJ(GETNUM(a) - GETNUM(b));
}

Obj mul_func(Obj a, Obj b) {
	return NUMOBJ(GETNUM(a) * GETNUM(b));
}

Obj div_func(Obj a, Obj b) { // floor division
	return NUMOBJ(GETNUM(a) / GETNUM(b));
}

Obj eq_func(Obj a, Obj b) {
	return NUMOBJ(GETNUM(a) == GETNUM(b));
}

twoArgFunc add_ = add_func;
twoArgFunc sub_ = sub_func;
twoArgFunc mul_ = mul_func;
twoArgFunc div_ = div_func;
twoArgFunc eq_ = eq_func;