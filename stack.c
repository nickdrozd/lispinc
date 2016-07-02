/*
	the stack is never directly manipulated;
	it is only affected by calls to stack
	functions. so the stack is like an object,
	and the functions are like its methods.
*/

#include <stdio.h>
#include <stdlib.h>
#include "objects.h"

List* stack = NULL;

void save(Obj reg) {
	if (DEBUG) printf("%s\n", "save!");
	List* temp = stack;
	stack = malloc(sizeof(List)); // &stack?
	stack->car = reg;
	stack->cdr = temp;
	return;
}

void restore(Obj* reg) {
	if (DEBUG) printf("%s\n", "restore!");
	*reg = stack->car;
	List* temp = stack;
	stack = stack->cdr;
	free(temp);
	return;
}

void clear_stack(void) {
	List* temp = stack;
	while (stack != NULL) {
		stack = stack->cdr;
		free(temp);
		temp = stack;
	}
	return;
}