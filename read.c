/*
	TODO:
		-- input???
*/

#include <stdio.h>

#include "objects.h"
#include "read.h"
#include "parse.h"

/* until scanf gets sorted out... */
extern char* code;

Obj read_code(void) {
	printf("testing make???\n");
	// char code[BUFSIZ];
	// printf("lispinc >>> ");
	// fgets(code, BUFSIZ, stdin);
	// 		if (DEBUG) printf("\nLISP CODE: %s\n", code);
	return parse(tokenize(code));
}