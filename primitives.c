#include "primitives.h"

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
	return GETTAG(a) == NUM && 
		GETTAG(b) == NUM;
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