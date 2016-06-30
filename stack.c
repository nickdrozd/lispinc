/*
	stack is like an object, and the
	stack functions are like methods
*/

#include <stdio.h>
#include <stdlib.h>
#include "objects.h"

// from print.c
// void print_list(List* list);
// void print_obj(Obj obj);

extern int DEBUG;
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

void print_stack(void) {
	printf("%s\n", "printing stack...");
	List* temp = stack;
	int count = 0;
	while (temp) {
		printf("%d -- ", count);
		print_obj(temp->car);
		temp = temp->cdr;
		count++;
	}
	printf("%s\n", "stack printed!");
}