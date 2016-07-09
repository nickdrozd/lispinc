#include "objects.h"

/* stack.c */
// void initialize_stack(void);

Obj expr;
Obj val;
Obj cont;
Obj func;
Obj arglist;
Obj unev;
Obj env;

#define uninitialized MKOBJ(UNINIT, uninit, 0)

void initialize_registers(void) {
	expr = uninitialized;
	val = uninitialized;
	cont = uninitialized;
	func = uninitialized;
	arglist = uninitialized;
	unev = uninitialized;
	env = uninitialized;
	return;
}

// void initialize(void) {
// 	initialize_registers();
// 	initialize_stack();
// 	return;
// }