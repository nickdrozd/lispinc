/*
	TODO:
		-- check TODOs in other files
			:: env, parse
		-- figure out scanf
		-- double check labels in objects.h
		-- lookup table for primitive names
*/

/*
	compile with:
		-- parse.c
		-- env.c
		-- llh.c
		-- stack.c
		-- print.c
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "objects.h"
#include "declarations.h"

/*
	registers:
		val -- result of evaluation
		expr  -- (pointer to) expression to be evaluated
		env -- pointer to evaluation environment (data structure)
		cont -- Label
		func -- pointer to function data structure
			-- pointer to list/env pair?
			-- note the structure of lambdas
				(see function_notes)
		arglist -- list of evaluated arguments
			-- Obj list?
		unev -- temporary register for expressions
			-- Obj list?

		flag? no?
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

#define empty_arglist MKOBJ(LIST, list, NULL)

int DEBUG = 0;
int INFO = 1;
int STATS = 1;

/* until scanf gets sorted out... */

char* code = 

//"add";
//char* code = "cat";
//"(add (sub 2 7) (mul 5 6))";
//"((lambda (x) (add x 3)) 5)";
"(((lambda (x) (lambda (y) (add x y))) 3) 4)";
//"(add 3 cat)";
//"(quote (a b c))";

Obj expr;
Obj val;
Obj cont;
Obj func;
Obj arglist;
Obj unev;
Obj env;

List* stack;

Env* base_env;

int main(void) {
			if (DEBUG) printf("%s\n\n", "starting main...");

	// needed for repl?
	base_env = makeBaseEnv();

	expr = MKOBJ(UNINIT, uninit, 0);
	val = MKOBJ(UNINIT, uninit, 0);
	cont = MKOBJ(UNINIT, uninit, 0);
	func = MKOBJ(UNINIT, uninit, 0);
	arglist = MKOBJ(UNINIT, uninit, 0);
	unev = MKOBJ(UNINIT, uninit, 0);

	env = MKOBJ(ENV, env, base_env);

			if (INFO) printf("base_env: %p\n", env.val.env);

	List* stack = NULL;

	START:
				if (INFO) { printf("\n\n@ START\n"); print_info(); }
		expr = read_code();
		// if (isQuit(expr)) 
		// 	return 0;
		// debug options
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
		printf("UNBOUND VARIABLE: \"%s\"!\n", expr.val.name);
		printf("%s\n", "clearing stack...");
		clear_stack();
		// if in repl mode,
		// goto START;
		goto ERROR;

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
		// fall-through to IF_ELSE
	// IF_ELSE:
		expr = ifElse(expr);
		goto EVAL;

	IF_THEN:
		if (INFO) { printf("\n\n@ IF_THEN\n"); print_info(); }
		expr = ifThen(expr);
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
		defineVar(unev, val, env); // var, val, env
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
				if (DEBUG) print_stack();
		goto EVAL;

	DID_FUNC:
				if (INFO) { printf("\n\n@ DID_FUNC\n"); print_info(); }
		restore(&unev); // the arguments
		restore(&env);
		arglist = empty_arglist; // #definition above
				if (DEBUG) debug_register(arglist, "arglist");
		func = val;
		if (noArgs(unev)) // (null? unev)
			goto APPLY;
		save(func);
		// fall through to ARG_LOOP

	ARG_LOOP:
				if (INFO) { printf("\n\n@ ARG_LOOP\n"); print_info(); }
		save(arglist);
				if (DEBUG) print_stack();
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
				if (DEBUG) debug_register(arglist, "arglist");
		arglist = adjoinArg(val, arglist); // append val to end of arglist
				if (DEBUG) debug_register(arglist, "arglist");
		unev = restArgs(unev); // (cdr unev)
				if (DEBUG) debug_register(unev, "unev");
				if (DEBUG) debug_register(arglist, "arglist");
		goto ARG_LOOP;

	LAST_ARG:
		if (INFO) { printf("\n\n@ LAST_ARG\n"); print_info(); }
		cont = MKOBJ(LABEL, label, _DID_LAST_ARG);
		goto EVAL;

	DID_LAST_ARG:
				if (INFO) { printf("\n\n@ DID_LAST_ARG\n"); print_info(); }
		restore(&arglist);
				if (DEBUG) debug_register(arglist, "arglist");
		arglist = adjoinArg(val, arglist);
				if (DEBUG) debug_register(arglist, "arglist");
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
				if (DEBUG) debug_register(unev, "unev");
		env = funcEnv(func);
				if (DEBUG) debug_register(env, "env");
		env = extendEnv(unev, arglist, env);
				if (DEBUG) debug_register(env, "env");
		unev = funcBody(func);
				if (DEBUG) debug_register(unev, "unev");
		goto SEQUENCE; // why not eval?
		// goto ALT_SEQUENCE; 
			// use ternary with tail_recursion switch to choose

	/* tail recursion is implented in SEQUENCE */

	SEQUENCE: // SEQUENCE never receives an empty list
				if (INFO) { printf("\n\n@ SEQUENCE\n"); print_info(); }
		expr = firstExp(unev);
		if (isLastExp(unev));
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
				if (STATS) print_stats();
		// goto START; // can't do repl until input gets sorted out
		//print_list(stack); // to silence warning
		return 0;

	ERROR:
		// put something interesting here?
		// what to do?
		return 0;
}














