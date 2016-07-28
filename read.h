/*
	READ

	read.c handles input. It doesn't do anything
	terribly interesting or exotic. Input is taken
	from fgets. If the input is a user command,
	then command is executed. Otherwise, the input
	(presumed to be Lisp code) is passed to the
	functions in parse.c.
*/

/*
	TODO:
		-- make it so that newlines don't have to be
			added to every input string (problem
			with tokenize in parse.c?s)
		-- reader macros
*/

#ifndef READ_GUARD
#define READ_GUARD

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "objects.h"
#include "keywords.h"
#include "flags.h"
#include "parse.h"
#include "lib.h"
#include "print.h"

Obj read_code(void);

/* input prompt */
void input_prompt(void);

void print_prompt(void);
void get_input(void);
bool isIrregular(char* code);

bool isEnter(char* code);
bool badSyntax(char* code);
bool parens_balanced(char* code);

/* check for user commands */
int isSpecial(char* code);
int isFlag(char* code);
int isHelp(char* code);

int streq(char* str1, char* str2);

#endif