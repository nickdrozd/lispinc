/*
	TODO:
		-- load basic library functions (list operations, full arithmetic, etc)
		-- get better memory management
		-- double check labels in objects.h
*/

/*
	compile with:
		-- parse.c
		-- read.c
		-- env.c
		-- registers.c
		-- stack.c
		-- llh.c
		-- print.c
*/


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


int main(void) {
			if (DEBUG) printf("\n%s\n\n", "starting main...");

	print_intro();

	base_env = makeBaseEnv();

			if (INFO) printf("base_env: %p\n", base_env);

	INITIALIZE:
		/* maybe initialize isn't needed, but it could
		make reading repl info easier */
		
		goto START;

	START:
		initialize_registers();
		initialize_stack();
		env = MKOBJ(ENV, env, base_env);
				if (INFO) { printf("\n\n@ START\n"); print_info(); }
		expr = read_code();
				if (DEBUG) printf("\nec_main -- code read!\n");
		if (isQuit(expr)) // move this to read.c
			goto QUIT;
		cont = MKOBJ(LABEL, label, _DONE);
		goto EVAL;

	CONTINUE:
				if (INFO) { printf("\n\n@ CONTINUE\n"); print_info(); }
		if (cont.val.label == _DONE)
			goto DONE;
		if (cont.val.label == _IF_DECIDE)
			goto IF_DECIDE;
		if (cont.val.label == _DID_ASS_VAL)
			goto DID_ASS_VAL;
		if (cont.val.label == _DID_DEF_VAL)
			goto DID_DEF_VAL;
		if (cont.val.label == _DID_FUNC)
			goto DID_FUNC;
		if (cont.val.label == _ACC_ARG)
			goto ACC_ARG;
		if (cont.val.label == _DID_LAST_ARG)
			goto DID_LAST_ARG;
		if (cont.val.label == _SEQ_CONT)
			goto SEQ_CONT;
		if (cont.val.label == _ALT_SEQ_CONT)
			goto ALT_SEQ_CONT;

	EVAL:
				if (INFO) { printf("\n\n@ EVAL\n"); print_info(); }
		if (isNum(expr))
			goto NUMBER;
		if (isVar(expr))
			goto VARIABLE;
		if (isQuote(expr))
			goto QUOTATION;
		if (isLambda(expr))
			goto LAMBDA;
		if (isBegin(expr))
			goto BEGIN;
		if (isAss(expr))
			goto ASSIGNMENT;
		if (isDef(expr))
			goto DEFINITION;
		if (isIf(expr))
			goto IF;
		goto FUNCTION;


	NUMBER:
				if (INFO) { printf("\n\n@ NUMBER\n"); print_info(); }
		val = expr;
		goto CONTINUE;

	VARIABLE:
				if (INFO) { printf("\n\n@ VARIABLE\n"); print_info(); }
				if (DEBUG) printf("%s\n", expr.val.name);
		val = lookup(expr, env);
		if (val.tag == DUMMY)
			goto UNBOUND;
		goto CONTINUE;

	UNBOUND:
				if (INFO) { printf("\n\n@ UNBOUND\n"); print_info(); }
		printf("\n\nUNBOUND VARIABLE: \"%s\"!\n", expr.val.name);
		// clear_stack();
		// getchar();
		if (REPL)
			goto START;
		// goto ERROR;

	QUOTATION:
				if (INFO) { printf("\n\n@ QUOTATION\n"); print_info(); }
		val = quotedText(expr);
		goto CONTINUE;

	BEGIN:
				if (INFO) { printf("\n\n@ BEGIN\n"); print_info(); }
		unev = beginActions(expr);
		save(cont);
		goto SEQUENCE;

	LAMBDA:
				if (INFO) { printf("\n\n@ LAMBDA\n"); print_info(); }
		unev = lambdaParams(expr);
		expr = lambdaBody(expr);
		val = makeFunc(unev, expr, env);
		goto CONTINUE;

	/* if (and other boolean macros) */

	IF:
				if (INFO) { printf("\n\n@ IF\n"); print_info(); }
		save(expr);
		save(env);
		save(cont);
		cont = MKOBJ(LABEL, label, _IF_DECIDE);
		expr = ifTest(expr);
		goto EVAL;

	IF_DECIDE:
				if (INFO) { printf("\n\n@ IF_DECIDE\n"); print_info(); }
		restore(&cont);
		restore(&env);
		restore(&expr);
		if (isTrue(val))
			goto IF_THEN;
		goto IF_ELSE;

	IF_THEN:
				if (INFO) { printf("\n\n@ IF_THEN\n"); print_info(); }
		expr = ifThen(expr);
		goto EVAL;

	IF_ELSE:
				if (INFO) { printf("\n\n@ IF_THEN\n"); print_info(); }
		expr = ifElse(expr);
		goto EVAL;

	/* ass, def */

	#define ASS_DEF_RETURN_VAL MKOBJ(NAME, name, "ok")
		
	// leave ass/def val as return val?

	ASSIGNMENT:
				if (INFO) { printf("\n\n@ ASSIGNMENT\n"); print_info(); }
		unev = assVar(expr);
		save(unev);
		expr = assVal(expr);
		save(env);
		save(cont);
		cont = MKOBJ(LABEL, label, _DID_ASS_VAL);
		goto EVAL;

	DID_ASS_VAL:
				if (INFO) { printf("\n\n@ DID_ASS_VAL\n"); print_info(); }
		restore(&cont);
		restore(&env);
		restore(&unev);
		setVar(unev, val, env); // var, val, env
		// val = ASS_DEF_RETURN_VAL;
		goto CONTINUE;

	DEFINITION:
				if (INFO) { printf("\n\n@ DEFINITION\n"); print_info(); }
		unev = defVar(expr);
		save(unev);
		expr = defVal(expr);
		save(env);
		save(cont);
		cont = MKOBJ(LABEL, label, _DID_DEF_VAL);
		goto EVAL;

	DID_DEF_VAL:
				if (INFO) { printf("\n\n@ DID_DEF_VAL\n"); print_info(); }
		restore(&cont);
		restore(&env);
		restore(&unev);
		defineVar(unev, val, &env); // var, val, env
		// val = ASS_DEF_RETURN_VAL;
		goto CONTINUE;


	/******************/

	/* function application */

	FUNCTION:
				if (INFO) { printf("\n\n@ FUNCTION\n"); print_info(); }
		save(cont);
		save(env);
		unev = getArgs(expr);
		save(unev);
		expr = getFunc(expr);
		cont = MKOBJ(LABEL, label, _DID_FUNC);
		goto EVAL;

	#define empty_arglist MKOBJ(LIST, list, NULL)

	DID_FUNC:
				if (INFO) { printf("\n\n@ DID_FUNC\n"); print_info(); }
		restore(&unev); // the arguments
		restore(&env);
		arglist = empty_arglist; // #definition above
		func = val;
		if (noArgs(unev)) // (null? unev)
			goto APPLY;
		save(func);
		// fall through to ARG_LOOP

	ARG_LOOP:
				if (INFO) { printf("\n\n@ ARG_LOOP\n"); print_info(); }
		save(arglist);
		expr = firstArg(unev); // (car unev)
		if (isLastArg(unev)) // (null? (cdr unev))
			goto LAST_ARG;
		save(env);
		save(unev);
		cont = MKOBJ(LABEL, label, _ACC_ARG);
		goto EVAL;

	ACC_ARG:
				if (INFO) { printf("\n\n@ ACC_ARG\n"); print_info(); }
		restore(&unev);
		restore(&env);
		restore(&arglist);
		arglist = adjoinArg(val, arglist); // append val to end of arglist
		unev = restArgs(unev); // (cdr unev)
		goto ARG_LOOP;

	LAST_ARG:
		if (INFO) { printf("\n\n@ LAST_ARG\n"); print_info(); }
		cont = MKOBJ(LABEL, label, _DID_LAST_ARG);
		goto EVAL;

	DID_LAST_ARG:
				if (INFO) { printf("\n\n@ DID_LAST_ARG\n"); print_info(); }
		restore(&arglist);
		arglist = adjoinArg(val, arglist);
		restore(&func);
		goto APPLY;


	/******************/

	APPLY:
					if (INFO) { printf("\n\n@ APPLY\n"); print_info(); }
		if (isPrimitive(func))
			goto APPLY_PRIMITIVE;
		if (isCompound(func))
			goto APPLY_COMPOUND;

	APPLY_PRIMITIVE:
				if (INFO) { printf("\n\n@ APPLY_PRIMITIVE\n"); print_info(); }
		val = applyPrimitive(func, arglist);
		restore(&cont);
		goto CONTINUE;

	// only place env is assigned a new value
	APPLY_COMPOUND:
				if (INFO) { printf("\n\n@ APPLY_COMPOUND\n"); print_info(); }
		unev = funcParams(func);
		env = funcEnv(func);
		env = extendEnv(unev, arglist, env);
		unev = funcBody(func);
		if (TAIL)
			goto SEQUENCE;
		goto ALT_SEQUENCE; 

	/* tail recursion is implented in SEQUENCE */

	SEQUENCE: // SEQUENCE never receives an empty list
				if (INFO) { printf("\n\n@ SEQUENCE\n"); print_info(); }
		expr = firstExp(unev);
		if (isLastExp(unev))
			goto LAST_EXP;
		save(unev);
		save(env);
		cont = MKOBJ(LABEL, label, _SEQ_CONT);
		goto EVAL;

	SEQ_CONT:
				if (INFO) { printf("\n\n@ SEQ_CONT\n"); print_info(); }
		restore(&env);
		restore(&unev);
		unev = restExps(unev);
		goto SEQUENCE;

	LAST_EXP:
				if (INFO) { printf("\n\n@ LAST_EXP\n"); print_info(); }
		restore(&cont);
		goto EVAL;

	/* alternatively, we could require that the stack is always saved in full */

	ALT_SEQUENCE:
				if (INFO) { printf("\n\n@ ALT_SEQUENCE\n"); print_info(); }
		if (noExps(unev))
			goto SEQ_END;
		expr = firstExp(unev);
		save(unev);
		save(env);
		cont = MKOBJ(LABEL, label, _ALT_SEQ_CONT);
		goto EVAL;

	ALT_SEQ_CONT:
				if (INFO) { printf("\n\n@ ALT_SEQ_CONT\n"); print_info(); }
		restore(&env);
		restore(&unev);
		unev = restExps(unev);
		goto ALT_SEQUENCE;

	SEQ_END:
				if (INFO) { printf("\n\n@ SEQ_END\n"); print_info(); }
		restore(&cont);
		goto CONTINUE;


	/************************/

	DONE:
				if (INFO) { printf("\n\n@ DONE\n"); print_info(); }
			print_final_val();
		//getchar();
			if (STATS) print_stats();
		if (REPL) 
			goto INITIALIZE; // can't do repl until input gets sorted out
		goto QUIT;

	// ERROR:
	// 	printf("%s\n", "I AM ERROR");
	// 	goto QUIT;
	// 	return 0;

	QUIT:
		free_memory();
		printf("\n%s\n", "exiting lispinc...");
		printf("Byeeeeee!\n\n");
		return 0;
}














