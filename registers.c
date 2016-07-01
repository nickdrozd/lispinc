#include <stdio.h>
#include "objects.h"

Obj makeBaseEnv(void);

Obj expr;
Obj val;
Obj cont;
Obj func;
Obj arglist;

Obj unev;
Obj env;

void print_registers(void) {
	printf("-- %s -- \n", "EXPR");
	print_obj(expr);
	printf("-- %s -- \n", "VAL");
	print_obj(val);
	printf("-- %s -- \n", "CONT");
	print_obj(cont);
	printf("-- %s -- \n", "FUNC");
	print_obj(func);
	printf("-- %s -- \n", "ARGLIST");
	print_obj(arglist);
	printf("-- %s -- \n", "UNEV");
	print_obj(unev);
	printf("-- %s -- \n", "ENV");
	print_obj(env);
}