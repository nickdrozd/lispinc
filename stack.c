/*
	STACK

	The stack is represented as a List, i.e.
	a pointer to a linked list of Objs 
	(see objects.h). It creates the illusion
	of infinite memory. You might think that
	the stack would be necessary because the
	interpreter needs it to run recursive
	functions. In fact, the stack is needed
	because the evaluator's eval / apply loop
	is itself a recursive procedure.

	Note that the stack is never directly 
	manipulated anywhere. Instead, all
	'communication' with the stack goes
	through the stack functions save, restore, 
	and clear_stack (plus print_stack in 
	print.c). In this way, the stack is like
	an object and the stack functions are like
	its methods.
*/

/*
	TODO:
		
*/

#include <stdio.h>
#include <stdlib.h>
	
#include "objects.h"
#include "stack.h"

List* stack;

// stat counters (see print.c)
int save_count = 0;
int curr_stack_depth = 0;
int max_stack_depth = 0;

void save(Obj reg) {
	if (DEBUG) printf("%s\n", "save!");
	List* temp = stack;
	stack = malloc(sizeof(List)); // &stack?
	stack->car = reg;
	stack->cdr = temp;

	save_count++;
	curr_stack_depth++;
	max_stack_depth = 
		curr_stack_depth > max_stack_depth ?
			curr_stack_depth : max_stack_depth;
	return;
}

void restore(Obj* reg) {
	if (DEBUG) printf("%s\n", "restore!");
	*reg = stack->car;
	List* temp = stack;
	stack = stack->cdr;
	free(temp);

	curr_stack_depth--;
	return;
}

#define empty_stack NULL

void clear_stack(void) {
	List* temp = stack;
	while (stack != NULL) {
		stack = stack->cdr;
		free(temp);
		temp = stack;
	}
	return;
}

void initialize_stack(void) {
	clear_stack();
	stack = empty_stack;
	return;
}