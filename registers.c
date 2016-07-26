#include <stdio.h>

#include "objects.h"
#include "print.h"

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

// is there a better way to include the register name?
void debug_register(Obj reg, char* name) {
	printf("\nDEBUG -- register: %s\n", name);
	print_obj(reg); NL; NL;
}

// void initialize(void) {
// 	initialize_registers();
// 	initialize_stack();
// 	return;
// }