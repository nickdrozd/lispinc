/*
	PRIMITIVES

	Primitive functions operate on actual C objects 
	(like numbers and lists). primitives.c creates 
	a list of the functions and list of the names of 
	these functions and then passes them to env.c, 
	where they are zipped together to create the frame 
	of the base_env.
*/

#ifndef PRIMITIVES_GUARD
#define PRIMITIVES_GUARD

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "objects.h"

// extern List* primitive_vars(void);
// extern List* primitive_vals(void);


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


/* primtive function declarations */

twoArgFunc add_;
twoArgFunc sub_;
twoArgFunc mul_;
twoArgFunc div_;
oneArgFunc addone_;
oneArgFunc subone_;

twoArgFunc eq_;
twoArgFunc lt_;
twoArgFunc gt_;
oneArgFunc iszero_;
oneArgFunc isone_;

oneArgFunc null_;

oneArgFunc car_;
oneArgFunc cdr_;
twoArgFunc cons_;




/* PRIMITIVE FUNCTIONS */

#define addprim TWOFUNC(add_, ADD_NAME)
#define subprim TWOFUNC(sub_, SUB_NAME)
#define mulprim TWOFUNC(mul_, MUL_NAME)
#define divprim TWOFUNC(div_, DIV_NAME)
#define addoneprim ONEFUNC(addone_, ADDONE_NAME)
#define suboneprim ONEFUNC(subone_, SUBONE_NAME)

#define eqprim TWOFUNC(eq_, EQ_NAME)
#define iszeroprim ONEFUNC(iszero_, ISZERO_NAME)
#define isoneprim ONEFUNC(isone_, ISONE_NAME)

#define nullprim ONEFUNC(null_, NULL_NAME)

#define carprim ONEFUNC(car_, CAR_NAME)
#define cdrprim ONEFUNC(cdr_, CDR_NAME)
#define consprim TWOFUNC(cons_, CONS_NAME)

// make sure to keep these updated!!!
#define arith_len 6
#define bool_len 3
#define type_len 1
#define list_len 3

#define PRIM_LEN (arith_len+bool_len+type_len+list_len)

#define LIST_OF_PRIMITIVES { \
addprim, subprim, mulprim, divprim, \
addoneprim, suboneprim, \
eqprim, iszeroprim, isoneprim, \
nullprim, \
carprim, cdrprim, consprim \
}

/* error checking */

bool are_both_nums(Obj a, Obj b);
void print_error_message(Tag tag);

#endif