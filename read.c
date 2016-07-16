/*
	TODO:
		-- print_help and print_intro
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "objects.h"
#include "read.h"
#include "parse.h"

#define NL printf("\n");

#define _DEBUG ".debug\n"
#define _REPL ".repl\n"
#define _INFO ".info\n"
#define _STATS ".stats\n"
#define _TAIL ".tail\n"

#define _HELP ".help\n"
#define _QUIT ".quit\n"

int DEBUG = 0;
int REPL = 1;
int INFO = 0;
int STATS = 1;
int TAIL = 1;

char code[BUFSIZ];

Obj read_code(void) {

	input_prompt();

	while (isSpecial(code)) {
		if (isFlag(code))
			switch_flag(code);
		else if (isHelp(code))
			print_help();
		input_prompt();
	}

			if (DEBUG) printf("\nLISP CODE: %s\n", code);

	return parse(tokenize(code));
}

/* input prompt */

void input_prompt(void) {
	print_prompt();
	get_input();
}

void print_prompt(void) {
	NL; NL;
	printf("lispinc >>> ");
}

/* NB: fgets add an extra newline at the end of input */
void get_input(void) {
	fgets(code, BUFSIZ, stdin);
	// code[strlen(code) - 1] = '\0';
}

/* help */

void print_help(void) {
	printf("\nHELP -- You're on your own for now...\n");
}

/* check for user commands */

int isFlag(char* code) {
			if (DEBUG) printf("isFlag\n");
	return streq(code, _DEBUG) || 
			streq(code, _REPL) || 
			streq(code, _INFO) || 
			streq(code, _STATS) || 
			streq(code, _TAIL);
}

int isHelp(char* code) {
			if (DEBUG) printf("isHelp\n");
	return streq(code, _HELP);
}

// bool isQuit(char* code) {
// 			if (DEBUG) printf("isQuit\n");
// 	return streq(code, _QUIT);
// }

int isSpecial(char* code) {
			if (DEBUG) printf("isSpecial\n");
	return isFlag(code) || isHelp(code); // || isQuit(code);
}

int streq(char* str1, char* str2) {
	return strcmp(str1, str2) == 0;
}

/* flag manipulation */

void toggle_val(int* flag) {
			if (DEBUG) printf("toggle_val: %d\n", *flag);
	*flag = 1 - *flag;
			// self-referential debugging statement?
			if (DEBUG) printf("toggled! %d\n", *flag);

	return;
}

void switch_flag(char* flag_name) {
			if (DEBUG) printf("%s\n", "switching flag...");
	if (streq(flag_name, _DEBUG))
		toggle_val(&DEBUG);
	else if (streq(flag_name, _REPL))
		toggle_val(&REPL);
	else if (streq(flag_name, _INFO))
		toggle_val(&INFO);
	else if (streq(flag_name, _STATS))
		toggle_val(&STATS);
	else if (streq(flag_name, _TAIL))
		toggle_val(&TAIL);
}








/*************************/

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