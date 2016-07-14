/*
	TODO:
		-- input???
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "objects.h"
#include "read.h"
#include "flags.h"
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

int isFlag(char* code) {
			if (DEBUG) printf("isFlag\n");
	return streq(code, "DEBUG\n") || 
			streq(code, "REPL\n") || 
			streq(code, "INFO\n") || 
			streq(code, "STATS\n") || 
			streq(code, "TAIL\n");
}

int isHelp(char* code) {
			if (DEBUG) printf("isHelp\n");
	return streq(code, "HELP\n");
}

int isSpecial(char* code) {
			if (DEBUG) printf("isSpecial\n");
	return isFlag(code) || isHelp(code);
}

void print_help(void) {
	return;
}

Obj read_code(void) {
	char code[BUFSIZ];
	// needed?
	// for (int i = 0; i < BUFSIZ; i++)
	// 	code[i] = '\0';

	printf("\n\nlispinc >>> ");
	fgets(code, BUFSIZ, stdin);

	while (isSpecial(code)) {
		if (isFlag(code))
			switch_flag(code);
		else if (isHelp(code))
			print_help();
		printf("\n\nlispinc >>> ");
		fgets(code, BUFSIZ, stdin);
	}

			if (DEBUG) printf("\nLISP CODE: %s\n", code);

	return parse(tokenize(code));
}

int streq(char* str1, char* str2) {
			if (DEBUG) printf("streq -- str1: %s, str2: %s, strcmp(str1, str2): %d\n", str1, str2, strcmp(str1, str1) );
	return strcmp(str1, str2) == 0;
}