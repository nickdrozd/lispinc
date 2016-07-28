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

#ifndef STACK_GUARD
#define STACK_GUARD

#include <stdio.h>
#include <stdlib.h>
	
#include "objects.h"
#include "flags.h"

/* stack.c */
void save(Obj reg);
void restore(Obj* reg);
void clear_stack(void);
void initialize_stack(void);
void reset_stats(void);

extern int save_count;
extern int curr_stack_depth;
extern int max_stack_depth;

extern List* stack;

#endif