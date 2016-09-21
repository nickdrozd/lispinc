/*
	PRIMITIVES

	Primitive functions operate on actual C objects 
	(like numbers and lists). primitives.c creates 
	a list of the functions and list of the names of 
	these functions and then passes them to env.c, 
	where they are zipped together to create the frame 
	of the base_env.

	TODO:
		* primitive names should be moved to keywords.h
*/

#ifndef PRIMITIVES_GUARD
#define PRIMITIVES_GUARD

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "objects.h"
#include "keywords.h"
#include "read.h"
#include "print.h"
#include "flags.h"

Obj applyPrimitive(Obj func, Obj arglist);

/* primitive arithmetic functions */
#define arith_len 6

twoArgFunc add_;
#define addprim TWOFUNC(add_, ADD_NAME)

twoArgFunc sub_;
#define subprim TWOFUNC(sub_, "-")

twoArgFunc mul_;
#define mulprim TWOFUNC(mul_, MUL_NAME)

twoArgFunc div_;
#define divprim TWOFUNC(div_, "/")

oneArgFunc addone_;
#define addoneprim ONEFUNC(addone_, "add1")

oneArgFunc subone_;
#define suboneprim ONEFUNC(subone_, "sub1")

/* primitive boolean functions */
#define bool_len 7

oneArgFunc not_;
#define notprim ONEFUNC(not_, "not")

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
#define type_len 5

oneArgFunc null_;
#define nullprim ONEFUNC(null_, "null?")

oneArgFunc isnumber_;
#define isnumberprim ONEFUNC(isnumber_, "number?")

oneArgFunc islist_;
#define islistprim ONEFUNC(islist_, "list?")

oneArgFunc isbool_;
#define isboolprim ONEFUNC(isbool_, "boolean?")

oneArgFunc issymbol_;
#define issymbolprim ONEFUNC(issymbol_, "symbol?")

/* primitive list functions */
#define list_len 11

twoArgFunc cons_;
#define consprim TWOFUNC(cons_, "cons")

oneArgFunc car_;
#define carprim ONEFUNC(car_, "car")

oneArgFunc cdr_;
#define cdrprim ONEFUNC(cdr_, "cdr")

twoArgFunc setcar_;
#define setcarprim TWOFUNC(setcar_, "set-car!")

twoArgFunc setcdr_;
#define setcdrprim TWOFUNC(setcar_, "set-cdr!")

oneArgFunc cadr_;
#define cadrprim ONEFUNC(cadr_, "cadr")

oneArgFunc cddr_;
#define cddrprim ONEFUNC(cddr_, "cddr")

oneArgFunc cdadr_;
#define cdadrprim ONEFUNC(cdadr_, "cdadr")

oneArgFunc caddr_;
#define caddrprim ONEFUNC(caddr_, "caddr")

oneArgFunc cdddr_;
#define cdddrprim ONEFUNC(cdddr_, "cdddr")

oneArgFunc cadddr_;
#define cadddrprim ONEFUNC(cadddr_, "cadddr")

/* I/O */
#define io_len 4

nilArgFunc read_;
#define readprim NILFUNC(read_, "read")

oneArgFunc display_;
#define displayprim ONEFUNC(display_, "display")

nilArgFunc newline_;
#define newlineprim NILFUNC(newline_, "newline")

nilArgFunc error_;
#define errorprim NILFUNC(error_, "error")

/* primitive application */
#define prim_app_len 3

twoArgFunc apply_nil_;
#define applynilprim TWOFUNC(apply_nil_, "applyNilFunc")

twoArgFunc apply_one_;
#define applyoneprim TWOFUNC(apply_one_, "applyOneFunc")

twoArgFunc apply_two_;
#define applytwoprim TWOFUNC(apply_two_, "applyTwoFunc")


// make sure to keep these updated!!!

#define PRIM_LEN (arith_len + bool_len + type_len + \
				list_len + io_len + prim_app_len)

#define LIST_OF_PRIMITIVES { \
addprim, subprim, mulprim, divprim, \
addoneprim, suboneprim, \
notprim, eqprim, ltprim, gtprim, \
iszeroprim, isoneprim, geneqprim, \
nullprim, isnumberprim, islistprim, \
isboolprim, issymbolprim, \
carprim, cdrprim, consprim, \
setcarprim, setcdrprim, \
cadrprim, cddrprim, cdadrprim, \
caddrprim, cdddrprim, cadddrprim, \
readprim, displayprim, errorprim, newlineprim, \
applynilprim, applyoneprim, applytwoprim, \
}



/* error checking */

bool are_both_nums(Obj a, Obj b);
void print_error_message(Tag tag, char* source);


// from read.c
int streq(char* str1, char* str2);

#endif