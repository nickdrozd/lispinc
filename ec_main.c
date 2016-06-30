/*
	TODO:
		-- add labels for continue
			-- make sure labels add up in objects.h
		-- check TODOs in other files
		-- UNBOUND label
		-- figure out scanf
		-- double check labels in objects.h
		-- figure out how to set cont as an Obj
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

Obj expr;
Obj val;
Obj env;
Obj cont;
Obj func;
Obj arglist;
Obj unev;

int main(void) {

	START:
		// expr = read_code
		// if (quit) return
		// debug options
		cont = MKOBJ(LABEL, label, _DONE);
		goto EVAL;


	CONTINUE:
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
		val = expr;
		goto CONTINUE;

	VARIABLE:
		val = lookup(expr, env);
		if (val.tag == DUMMY)
			goto UNBOUND;
		goto CONTINUE;

	UNBOUND:
		printf("%s\n", "unbound variable");
		clear_stack();
		goto START;

	QUOTATION:
		val = quotedText(expr);
		goto CONTINUE;

	BEGIN:
		unev = beginActions(expr);
		save(cont);
		goto SEQUENCE;

	LAMBDA:
		unev = lambdaParams(expr);
		expr = lambdaBody(expr);
		val = makeFunc(unev, expr, env);
		goto CONTINUE;

	/* if (and other boolean macros) */

	IF:
		save(expr);
		save(env);
		save(cont);
		cont = MKOBJ(LABEL, label, _IF_DECIDE);
		expr = ifTest(expr);
		goto EVAL;

	IF_DECIDE:
		restore(&cont);
		restore(&env);
		restore(&expr);
		if (isTrue(val))
			goto IF_THEN;

	IF_ELSE:
		expr = ifElse(expr);
		goto EVAL;

	IF_THEN:
		expr = ifThen(expr);
		goto EVAL;

	/* ass, def */

	#define ASS_DEF_RETURN_VAL MKOBJ(NAME, name, "ok")
		
	// leave ass/def val as return val?

	ASSIGNMENT:
		unev = assVar(expr);
		save(unev);
		expr = assVal(expr);
		save(env);
		save(cont);
		cont = MKOBJ(LABEL, label, _DID_ASS_VAL);
		goto EVAL;

	DID_ASS_VAL:
		restore(&cont);
		restore(&env);
		restore(&unev);
		setVar(unev, val, env); // var, val, env
		// val = ASS_DEF_RETURN_VAL;
		goto CONTINUE;

	DEFINITION:
		unev = defVar(expr);
		save(unev);
		expr = defVal(expr);
		save(env);
		save(cont);
		cont = MKOBJ(LABEL, label, _DID_DEF_VAL);
		goto EVAL;

	DID_DEF_VAL:
		restore(&cont);
		restore(&env);
		restore(&unev);
		defineVar(unev, val, env); // var, val, env
		// val = ASS_DEF_RETURN_VAL;
		goto CONTINUE;


	/******************/

	/* function application */

	FUNCTION:
		save(cont);
		save(env);
		unev = getArgs(expr);
		save(unev);
		expr = getFunc(expr);
		cont = MKOBJ(LABEL, label, _DID_FUNC);
		goto EVAL;

	DID_FUNC:
		restore(&unev); // the arguments
		restore(&env);
		arglist = empty_arglist; // #definition above
		func = val;
		if (noArgs(unev)) // (null? unev)
			goto APPLY;
		save(func);
		// fall through to ARG_LOOP

	ARG_LOOP:
		save(arglist);
		expr = firstArg(unev); // (car unev)
		if (isLastArg(unev)) // (null? (cdr unev))
			goto LAST_ARG;
		save(env);
		save(unev);
		cont = MKOBJ(LABEL, label, _ACC_ARG);
		goto EVAL;

	ACC_ARG:
		restore(&unev);
		restore(&env);
		restore(&arglist);
		arglist = adjoinArg(val, arglist); // append val to end of arglist
		unev = restArgs(unev); // (cdr unev)
		goto ARG_LOOP;

	LAST_ARG:
		cont = MKOBJ(LABEL, label, _DID_LAST_ARG);
		goto EVAL;

	DID_LAST_ARG:
		restore(&arglist);
		arglist = adjoinArg(val, arglist);
		restore(&func);
		goto APPLY;


	/******************/

	APPLY:
		if (isPrimitive(func))
			goto APPLY_PRIMITIVE;
		if (isCompound(func))
			goto APPLY_COMPUND;

	APPLY_PRIMITIVE:
		val = applyPrimitive(func, arglist);
		restore(&cont);
		goto CONTINUE;

	APPLY_COMPUND: // only place env is assigned a new value
		unev = funcParams(func);
		env = funcEnv(func);
		env = extendEnv(unev, arglist, env);
		unev = funcBody(func);
		goto SEQUENCE; // why not eval?
		// goto ALT_SEQUENCE; 
			// use ternary with tail_recursion switch to choose

	/* tail recursion is implented in SEQUENCE */

	SEQUENCE: // SEQUENCE never receives an empty list
		expr = firstExp(unev);
		if (isLastExp(unev));
			goto LAST_EXP;
		save(unev);
		save(env);
		cont = MKOBJ(LABEL, label, _SEQ_CONT);
		goto EVAL;

	SEQ_CONT:
		restore(&env);
		restore(&unev);
		unev = restExps(unev);
		goto SEQUENCE;

	LAST_EXP:
		restore(&cont);
		goto EVAL;

	/* alternatively, we could require that the stack is always saved in full */

	ALT_SEQUENCE:
		if (noExps(unev))
			goto SEQ_END;
		expr = firstExp(unev);
		save(unev);
		save(env);
		cont = MKOBJ(LABEL, label, _ALT_SEQ_CONT);
		goto EVAL;

	ALT_SEQ_CONT:
		restore(&env);
		restore(&unev);
		unev = restExps(unev);
		goto ALT_SEQUENCE;

	SEQ_END:
		restore(&cont);
		goto CONTINUE;


	/************************/

	DONE:
		print_obj(val);
		goto START;

}














