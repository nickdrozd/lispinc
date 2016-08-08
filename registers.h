#ifndef REGISTERS_GUARD
#define REGISTERS_GUARD

#include <stdio.h>

#include "objects.h"
#include "stack.h"
#include "print.h"

void initialize(void);

void initialize_registers(void);

void debug_register(Obj reg, char* name);

#define EXPR_NAME "EXPR"
#define VAL_NAME "VAL"
#define CONT_NAME "CONT"
#define FUNC_NAME "FUNC"
#define ARGLIST_NAME "ARGLIST"
#define UNEV_NAME "UNEV"
#define ENV_NAME "ENV"

extern Obj expr;
extern Obj val;
extern Obj cont;
extern Obj func;
extern Obj arglist;
extern Obj unev;
extern Obj env;

#endif