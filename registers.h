#ifndef REGISTERS_GUARD
#define REGISTERS_GUARD

#include <stdio.h>

#include "objects.h"
#include "print.h"

void initialize_registers(void);
void debug_register(Obj reg, char* name);

extern Obj expr;
extern Obj val;
extern Obj cont;
extern Obj func;
extern Obj arglist;
extern Obj unev;
extern Obj env;

#endif