/*
	TODO:
		-- input???
*/

#include <stdio.h>

#include "objects.h"
#include "read.h"
#include "parse.h"

/* until scanf gets sorted out... */
// char* code = 

/* a number */
// "68";

/* a defined variable */
// "add";

/* un undefined variable */
// "cat";

/* arithmetic */
// "(add (sub 2 7) (mul 5 6))";

/* arithmetic with undefined variable */
// "(add 3 cat)";

/* one lambda of one arg */
// "((lambda (x) (add x 3)) 5)";

/* two lambdas of one arg each */
// "(((lambda (x) (lambda (y) (add x y))) 3) 4)";

/* one lambda of two args */
// "((lambda (a b) (div a b)) 36 9)";

/* quotation */
// "(quote (a b c))";

/* define */
// "(define x 5)";

/* define, then set */
// "(begin "
// 	"(define x 5) "
// 	"(set! x (add x 7)) "
// 	"(mul x x))";

/* recursive factorial */
// "(begin "
// 	"(define factorial "
// 		"(lambda (n) "
// 			"(if (eq n 0) "
// 				"1 "
// 				"(mul n (factorial (sub n 1)))))) "
// 	"(factorial 6))";

/* tail-recursive factorial */
// "(begin "
// 	"(define factorial "
// 		"(lambda (n) "
// 			"(begin " // explicit begin needed because of lambdaBody in llh.c
// 				"(define loop "
// 					"(lambda (count total) "
// 						"(if (eq count 0) "
// 							"total "
// 							"(loop (sub count 1) "
// 									"(mul total count))))) "
// 				"(loop n 1)))) "
// 	"(factorial 6))";

/* until scanf gets sorted out... */
// extern char* code;

Obj read_code(void) {
	char code[BUFSIZ];
	// for (int i = 0; i < BUFSIZ; i++)
	// 	code[i] = '\0';
	printf("\n\nlispinc >>> ");
	fgets(code, BUFSIZ, stdin);
			if (DEBUG) printf("\nLISP CODE: %s\n", code);
	return parse(tokenize(code));
}