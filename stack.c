#include <stdlib.h>
#include "objects.h"

// extern?
List* stack;

void save(Obj reg) {
	List* temp = stack;
	stack = malloc(sizeof(List)); // &stack?
	stack->car = reg;
	stack->cdr = temp;
	return;
}

void restore(Obj* reg) {
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