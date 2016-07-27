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

void initialize_registers(void) {
	expr = UNINITOBJ;
	val = UNINITOBJ;
	cont = UNINITOBJ;
	func = UNINITOBJ;
	arglist = UNINITOBJ;
	unev = UNINITOBJ;
	env = UNINITOBJ;
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