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

/* primitive arithmetic functions */
#define arith_len 6

twoArgFunc add_;
#define addprim TWOFUNC(add_, "__+__")

twoArgFunc sub_;
#define subprim TWOFUNC(sub_, "-")

twoArgFunc mul_;
#define mulprim TWOFUNC(mul_, "__*__")

twoArgFunc div_;
#define divprim TWOFUNC(div_, "/")

oneArgFunc addone_;
#define addoneprim ONEFUNC(addone_, "add1")

oneArgFunc subone_;
#define suboneprim ONEFUNC(subone_, "sub1")

/* primitive boolean functions */
#define bool_len 6

twoArgFunc eq_;
#define eqprim TWOFUNC(eq_, "=")

twoArgFunc lt_;
#define ltprim TWOFUNC(lt_, "<")

twoArgFunc gt_;
#define gtprim TWOFUNC(gt_, ">")

oneArgFunc iszero_;
#define iszeroprim ONEFUNC(iszero_, "zero?")

oneArgFunc isone_;
#define isoneprim ONEFUNC(isone_, "one?")

twoArgFunc geneq_;
#define geneqprim TWOFUNC(geneq_, "eq?")

/* primitive type-check functions */
#define type_len 4

oneArgFunc null_;
#define nullprim ONEFUNC(null_, "null?")

oneArgFunc isnumber_;
#define isnumberprim ONEFUNC(isnumber_, "number?")

oneArgFunc islist_;
#define islistprim ONEFUNC(islist_, "list?")

oneArgFunc isbool_;
#define isboolprim ONEFUNC(isbool_, "boolean?")

/* primitive list functions */
#define list_len 3

oneArgFunc car_;
#define carprim ONEFUNC(car_, "car")

oneArgFunc cdr_;
#define cdrprim ONEFUNC(cdr_, "cdr")

twoArgFunc cons_;
#define consprim TWOFUNC(cons_, "cons")

// make sure to keep these updated!!!

#define PRIM_LEN (arith_len+bool_len+type_len+list_len)

#define LIST_OF_PRIMITIVES { \
addprim, subprim, mulprim, divprim, \
addoneprim, suboneprim, \
eqprim, ltprim, gtprim, \
iszeroprim, isoneprim, geneqprim, \
nullprim, isnumberprim, islistprim, isboolprim, \
carprim, cdrprim, consprim \
}



/* error checking */

bool are_both_nums(Obj a, Obj b);
void print_error_message(Tag tag);


// from read.c
int streq(char* str1, char* str2);

#endif