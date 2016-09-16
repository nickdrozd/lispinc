#include "primitives.h"

/* PRIMITIVE FUNCTION NAMES */

/* primitive arithmetic functions */

#define ADD_NAME "+"
#define SUB_NAME "-"
#define MUL_NAME "*"
#define DIV_NAME "/"
#define ADDONE_NAME "add1"
#define SUBONE_NAME "sub1"

#define EQ_NAME "=" 
#define LT_NAME "<"
#define GT_NAME ">"
#define ISZERO_NAME "zero?"
#define ISONE_NAME "one?"

/* primitive type-check functions */

#define NULL_NAME "null?"

/* primitive list functions */

#define CAR_NAME "car"
#define CDR_NAME "cdr"
#define CONS_NAME "cons"

/* PRIMITIVE FUNCTIONS FRAMES */

/* primitive names */

#define NAMELIST(name,list) makeList(NAMEOBJ(name),list)

List* primitive_vars(void) {

	List* arith_vars = 
		NAMELIST(ADD_NAME, NAMELIST(SUB_NAME, 
			NAMELIST(MUL_NAME, NAMELIST(DIV_NAME, 
				NAMELIST(EQ_NAME, NULL)))));

	List* otherarith_vars = 
		NAMELIST(ISZERO_NAME, NAMELIST(ISONE_NAME, 
			NAMELIST(ADDONE_NAME, NAMELIST(SUBONE_NAME, 
				arith_vars))));

	List* type_vars = 
		NAMELIST(NULL_NAME, otherarith_vars);

	List* list_vars = 
		NAMELIST(CAR_NAME, NAMELIST(CDR_NAME, 
			NAMELIST(CONS_NAME, type_vars)));

	return list_vars;
}

/* primitive values */

#define PRIMLIST(prim,list) makeList(PRIMOBJ(prim), list)

List* primitive_vals(void) {
	/* these have to be declared inside a function
	(something about initializing nonconstants) */

	Prim addprim = TWOFUNC(add_, ADD_NAME);
	Prim subprim = TWOFUNC(sub_, SUB_NAME);
	Prim mulprim = TWOFUNC(mul_, MUL_NAME);
	Prim divprim = TWOFUNC(div_, DIV_NAME);
	Prim addoneprim = ONEFUNC(addone_, ADDONE_NAME);
	Prim suboneprim = ONEFUNC(subone_, SUBONE_NAME);

	Prim eqprim = TWOFUNC(eq_, EQ_NAME);
	Prim iszeroprim = ONEFUNC(iszero_, ISZERO_NAME);
	Prim isoneprim = ONEFUNC(isone_, ISONE_NAME);
	Prim nullprim = ONEFUNC(null_, NULL_NAME);


	Prim carprim = ONEFUNC(car_, CAR_NAME);
	Prim cdrprim = ONEFUNC(cdr_, CDR_NAME);
	Prim consprim = TWOFUNC(cons_, CONS_NAME);

	List* arith_vals = 
		PRIMLIST(addprim, PRIMLIST(subprim,
			PRIMLIST(mulprim, PRIMLIST(divprim, 
				PRIMLIST(eqprim, NULL)))));

	// List* arith_vals = 
	// 	makeList(PRIMOBJ(addprim), 
	// 		makeList(PRIMOBJ(subprim), 
	// 			makeList(PRIMOBJ(mulprim), 
	// 				makeList(PRIMOBJ(divprim), 
	// 					makeList(PRIMOBJ(eqprim), NULL)))));

	List* otherarith_vals = 
		PRIMLIST(iszeroprim, PRIMLIST(isoneprim, 
			PRIMLIST(addoneprim, PRIMLIST(suboneprim, 
				arith_vals))));

	List* type_vals = 
		makeList(PRIMOBJ(nullprim),
			otherarith_vals);

	List* list_vals = 
		makeList(PRIMOBJ(carprim),
			makeList(PRIMOBJ(cdrprim),
				makeList(PRIMOBJ(consprim),
					type_vals)));

	return list_vals;
}

/* PRIMITIVE FUNCTIONS DEFINED */

/* primitive type-checking */

// null? returns false for non-list objects
Obj null_func(Obj obj) {
	bool isList = GETTAG(obj) == LIST;

	if (!isList) return FALSEOBJ;

	bool isNull = GETLIST(obj) == NULL;

	return BOOLOBJ(isNull);
}

oneArgFunc null_ = null_func;

/* primitive list functions 
(not to be confused with the list 
macros found in objects.h!) */

/* car and cdr both do simple error-checking */

Obj car_func(Obj obj) {
	if (!(GETTAG(obj) == LIST)) {
		print_error_message(LIST);
		return ERROROBJ;
	}

	List* list = GETLIST(obj);

	if (list == NULL) {
		print_error_message(LIST);
		return ERROROBJ;
	}
	else
		return list->car;
}

Obj cdr_func(Obj obj) {
	if (!(GETTAG(obj) == LIST)) {
		print_error_message(LIST);
		return ERROROBJ;
	}

	List* list = GETLIST(obj);

	// cdr of empty list is empty list
	if (list == NULL)
		return NULLOBJ;
	else
		return LISTOBJ(list->cdr);
}

/* second object MUST BE list. if it isn't 
a list, it will be coerced to a one-item list */
Obj cons_func(Obj car, Obj cdr) {
	int isList = GETTAG(cdr) == LIST;

	if (!isList) {
		printf("%s\n", "Second arg not a list! Converting to one-item list...");
		List* listcdr = makeList(cdr, NULL);
		return LISTOBJ(makeList(car, listcdr));
	}
	else
		return LISTOBJ(makeList(car, GETLIST(cdr)));
}

oneArgFunc car_ = car_func;
oneArgFunc cdr_ = cdr_func;
twoArgFunc cons_ = cons_func;

/* primitive arithmetic */

Obj add_func(Obj a, Obj b) {
	if (!are_both_nums(a,b)) {
		print_error_message(NUM);
		return ERROROBJ;
	}
	return NUMOBJ(GETNUM(a) + GETNUM(b));
}

Obj sub_func(Obj a, Obj b) {
	if (!are_both_nums(a,b)) {
		print_error_message(NUM);
		return ERROROBJ;
	}
	return NUMOBJ(GETNUM(a) - GETNUM(b));
}

Obj mul_func(Obj a, Obj b) {
	if (!are_both_nums(a,b)) {
		print_error_message(NUM);
		return ERROROBJ;
	}
	return NUMOBJ(GETNUM(a) * GETNUM(b));
}

Obj div_func(Obj a, Obj b) { // floor division
	if (!are_both_nums(a,b)) {
		print_error_message(NUM);
		return ERROROBJ;
	}
	return NUMOBJ(GETNUM(a) / GETNUM(b));
}

Obj addone_func(Obj a) {
	return add_func(a, ONEOBJ);
}

Obj subone_func(Obj a) {
	return sub_func(a, ONEOBJ);
}

twoArgFunc add_ = add_func;
twoArgFunc sub_ = sub_func;
twoArgFunc mul_ = mul_func;
twoArgFunc div_ = div_func;
oneArgFunc addone_ = addone_func;
oneArgFunc subone_ = subone_func;


/* boolean functions */

Obj eq_func(Obj a, Obj b) {
	if (!are_both_nums(a,b)) {
		print_error_message(NUM);
		return ERROROBJ;
	}
	return BOOLOBJ(GETNUM(a) == GETNUM(b));
}

Obj lt_func(Obj a, Obj b) {
	if (!are_both_nums(a,b)) {
		print_error_message(NUM);
		return ERROROBJ;
	}
	return BOOLOBJ(GETNUM(a) < GETNUM(b));
}

Obj gt_func(Obj a, Obj b) {
	if (!are_both_nums(a,b)) {
		print_error_message(NUM);
		return ERROROBJ;
	}
	return BOOLOBJ(GETNUM(a) > GETNUM(b));
}

Obj iszero_func(Obj a) {
	return eq_func(a, ZEROOBJ);
}

Obj isone_func(Obj a) {
	return eq_func(a, ONEOBJ);
}

twoArgFunc eq_ = eq_func;
twoArgFunc lt_ = lt_func;
twoArgFunc gt_ = gt_func;
oneArgFunc iszero_ = iszero_func;
oneArgFunc isone_ = isone_func;


/* error-checking */

// error-checking helper
bool are_both_nums(Obj a, Obj b) {
	return isNum(a) && isNum(b);
}

void print_error_message(Tag tag) {
	char* operation_type;

	switch(tag) {
		case NUM:
			operation_type = "Arithmetic";
			break;
		case LIST:
			operation_type = "List";
			break;
		default:
			operation_type = "???";
			break;
	}

	printf("%s operation error!\n", operation_type);
}