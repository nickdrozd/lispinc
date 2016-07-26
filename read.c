/*
	READ

	read.c handles input. It doesn't do anything
	terribly interesting or exotic. Input is taken
	from fgets. If the input is a user command,
	then command is executed. Otherwise, the input
	(presumed to be Lisp code) is passed to the
	functions in parse.c.

	Also included here are a few print functions,
	like printing the REPL prompt, help, and the 
	intro text. These aren't included in print.c 
	because they don't do anything substantive.
*/

/*
	TODO:
		-- make it so that newlines don't have to be
			added to every input string (problem
			with tokenize in parse.c?s)
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "objects.h"
#include "read.h"
#include "flags.h"
#include "parse.h"
#include "lib.h"

#define NL printf("\n");

char code[BUFSIZ];

int lib_counter = 0;

/* should there be a separate load_library function?
	how should it be implemented? */

Obj read_code(void) {

	if (lib_counter < lib_len) {
		// print_lib();
		char* lib_entry = library[lib_counter];
				if (DEBUG) printf("library entry: %s\n", lib_entry);
		Obj result = process_code_text(lib_entry);
		lib_counter++;
		return result;
	}

	if (lib_counter >= lib_len && LIB) 
		toggle_val(&LIB);


	input_prompt();

	while (isSpecial(code)) {
		if (isFlag(code))
			switch_flag(code);
		else if (isHelp(code))
			print_help();
		input_prompt();
	}

			if (DEBUG) printf("\nLISP CODE: %s\n", code);

	Obj result = process_code_text(code);
	return result;
}

/* input prompt */

void input_prompt(void) {
	print_prompt();
	get_input();
	if (badSyntax(code)) {
		printf("Bad syntax! Try again!\n");
		input_prompt();
	}
	if (isEnter(code))
		input_prompt();
}

void print_prompt(void) {
	NL;
	printf("lispinc >>> ");
}

/* NB: fgets add an extra newline at the end of input */
void get_input(void) {
	fgets(code, BUFSIZ, stdin);
	// code[strlen(code) - 1] = '\0';
}

bool badSyntax(char* code) {
	return !parens_balanced(code);
}

bool isEnter(char* code) {
	return streq(code, "\n");
}

bool parens_balanced(char* code) {
	int op = 0;
	int cp = 0;
	int len = strlen(code);

	for (int i = 0; i < len; i++) {
		if (open_paren(code[i]))
			op++;
		if (close_paren(code[i]))
			cp++;
	}

	return op == cp;
}

bool open_paren(char c) {
	return c == '(' ||
			c == '[' ||
			c == '{';
}

bool close_paren(char c) {
	return c == ')' ||
			c == ']' ||
			c == '}';
}

/* help */

void print_intro(void) {
	NL;
	printf("Welcome to lispinc!"); NL; NL;
	printf("Nick Drozd, 2016"); NL;
	printf("github.com/nickdrozd/lispinc"); NL; NL;
	printf("Enter .help for help and enter .quit to quit."); NL; NL;
	printf("Now, the time has come for you to lispinc...for your life!"); NL; NL;
}

void print_lib(void) {
	printf("loading library..."); 
	NL;
}

void print_help(void) {
	NL;
	printf("HELP");NL;
	printf("\t-- enter .stats to toggle stats mode");NL;
	printf("\t-- enter .info to toggle info mode");NL;
	printf("\t-- enter .step to toggle step mode (pauses between each step of the evaluator; useful in conjunction with info mode)\n");
	printf("\t-- enter .tail to toggle tail recursion mode (turning this off is really only of any interest in conjunction with stats mode)");NL;
	printf("\t-- enter .debug to toggle debug mode");NL;
	printf("\t-- enter .quit to quit");NL;NL;
}

/* check for user commands (see flags.h) */

int isFlag(char* code) {
			if (DEBUG) printf("isFlag\n");
	return streq(code, _DEBUG) || 
			streq(code, _REPL) || 
			streq(code, _INFO) || 
			streq(code, _STATS) || 
			streq(code, _TAIL) ||
			streq(code, _STEP);
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


