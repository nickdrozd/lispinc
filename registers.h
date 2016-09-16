/*
	REGISTERS

	registers.c declares the evaluator's seven registers: 
	EXPRession, VALue, CONTinue, FUNCtion, ARGumentLIST, 
	UNEValuated, and ENVironment. It also provides a 
	function to initialize the registers (as well as the 
	stack) and a function to print the contents of a 
	register.
*/

#ifndef REGISTERS_GUARD
#define REGISTERS_GUARD

#include "objects.h"
#include "stack.h"
#include "tally.h"

void initialize(void);
void initialize_registers(void);

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