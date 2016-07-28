/*
	TODO:
		-- get better memory management
		-- double check labels in objects.h
		-- documentation!
*/

/*
	registers:
		val -- result of evaluation
		expr -- expression to be evaluated
		env -- pointer to evaluation environment (data structure)
		cont -- Label
		func -- function / operator
		arglist -- arguments / operands
		unev -- temporary register for expressions
*/

/*
	CONTRACTS

	Eval:
		-- expr holds the expression to be evaluated
		-- env holds the environment in which the
			expression is to be evaluated
		-- cont holds a place to go next
		-- the result will be left in val; the contents
			of all other registers may be destroyed

	Apply:
		-- arglist contains a list of arguments
		-- func contains a function to be applied
		-- the top of the stack holds a place to go next
		-- the result will be left in val;
			the stack will be popped; the contents of 
			all other registers may be destroyed
*/


#ifndef EC_MAIN_GUARD
#define EC_MAIN_GUARD

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
		
#include "objects.h"
#include "flags.h"
#include "read.h"
#include "env.h"
#include "registers.h"
#include "stack.h"
#include "llh.h"
#include "print.h"
#include "mem.h"

#endif