#include "ec_main.h"

int main(void) {
			debug_print("starting main...");

	print_intro();

	base_env = makeBaseEnv();
	env = ENVOBJ(base_env);

	goto COMPILED_CODE;

	/************************/

	START:
		initialize();
		env = ENVOBJ(base_env);
		expr = read_code();
				print_base_env();
				// print_info("START");
				debug_print("ec_main -- code read!");
		if (isQuit(expr)) 
			goto QUIT;
		cont = LABELOBJ(_DONE);
		goto EVAL;

	/************************/

	EVAL:
				print_info("EVAL");
		if (isNum(expr))
			goto NUMBER;
		if (isVar(expr))
			goto VARIABLE;
		if (isIf(expr))
			goto IF;
		if (isLambda(expr))
			goto LAMBDA;
		if (isDef(expr))
			goto DEFINITION;
		if (isAss(expr))
			goto ASSIGNMENT;
		if (isAnd(expr))
			goto AND;
		if (isOr(expr))
			goto OR;
		if (isBegin(expr))
			goto BEGIN;
		if (isQuote(expr))
			goto QUOTATION;
		if (isDelay(expr))
			goto DELAY;
		goto FUNCTION;


	NUMBER:
				print_info("NUMBER");
		val = expr;
		goto CONTINUE;

	VARIABLE:
				print_info("VARIABLE");
				debug_print(GETNAME(expr));
		val = lookup(expr, env);
		if (isUnbound(val))
			goto UNBOUND;
		goto CONTINUE;

	UNBOUND:
				print_info("UNBOUND");
		print_unbound();
		goto START;

	QUOTATION:
				print_info("QUOTATION");
		val = quotedText(expr);
		goto CONTINUE;

	BEGIN:
				print_info("BEGIN");
		unev = beginActions(expr);
		save(cont);
		goto SEQUENCE;

	DELAY:
				print_info("DELAY");
		expr = transformDelay(expr);
		goto EVAL;

	LAMBDA:
				print_info("LAMBDA");
		unev = lambdaParams(expr);
		expr = lambdaBody(expr);
		val = makeFunc(unev, expr, env);
		goto CONTINUE;

	IF:
				print_info("IF");
		// is there any way to get around these saves?
		save(expr);
		save(env);
		save(cont);
		cont = LABELOBJ(_IF_DECIDE);
		expr = ifTest(expr);
		goto EVAL;

	IF_DECIDE:
				print_info("IF_DECIDE");
		restore(cont);
		restore(env);
		restore(expr);
		if (isTrue(val))
			goto IF_THEN;
		goto IF_ELSE;

	IF_THEN:
				print_info("IF_THEN");
		expr = ifThen(expr);
		goto EVAL;

	IF_ELSE:
				print_info("IF_ELSE");
		expr = ifElse(expr);
		goto EVAL;

	AND:
				print_info("AND");
		expr = transformAnd(expr);
		goto EVAL;

	OR:
				print_info("OR");
		expr = transformOr(expr);
		goto EVAL;

	/* ass, def */

	#define ASS_DEF_RETURN_VAL DUMMYOBJ
		
	// leave ass/def val as return val?

	DEFINITION:
				print_info("DEFINITION");
		if (isSugarDef(expr))
			expr = transformSugarDef(expr);
		unev = defVar(expr);
		save(unev);
		expr = defVal(expr);
		save(env);
		save(cont);
		cont = LABELOBJ(_DID_DEF_VAL);
		goto EVAL;

	DID_DEF_VAL:
				print_info("DID_DEF_VAL");
		restore(cont);
		restore(env);
		restore(unev);
		defineVar(unev, val, env); // var, val, env
		// val = ASS_DEF_RETURN_VAL;
		goto CONTINUE;

	ASSIGNMENT:
				print_info("ASSIGNMENT");
		unev = assVar(expr);
		save(unev);
		expr = assVal(expr);
		save(env);
		save(cont);
		cont = LABELOBJ(_DID_ASS_VAL);
		goto EVAL;

	DID_ASS_VAL:
				print_info("DID_ASS_VAL");
		restore(cont);
		restore(env);
		restore(unev);
		setVar(unev, val, env); // var, val, env
		// val = ASS_DEF_RETURN_VAL;
		goto CONTINUE;

	/******************/

	/* function application */

	FUNCTION:
				print_info("FUNCTION");
		save(cont);
		unev = getArgs(expr);
		expr = getFunc(expr);
		// avoids two saves
		if (isSimple(expr))
			goto SIMPLE_FUNC;
		save(env);
		save(unev);
		cont = LABELOBJ(_DID_FUNC);
		goto EVAL;

	DID_FUNC:
				print_info("DID_FUNC");
		restore(unev);
		restore(env);
		func = val;
		goto CHECK_NO_ARGS;

	SIMPLE_FUNC:
				print_info("SIMPLE_FUNC");
		func = lookup(expr, env);
		if (isUnbound(func))
			goto UNBOUND;
		goto CHECK_NO_ARGS;

	#define empty_arglist NULLOBJ

	/* inelegantly many cases to check? */

	CHECK_NO_ARGS:
				print_info("CHECK_NO_ARGS");
		arglist = empty_arglist;
		// avoids ARG_LOOP
		if (noArgs(unev)) 
			goto APPLY;
		/* is this dishonest? noCompoundArgs is a (tail)
		recursive function -- is that too complicated 
		to be a primitive machine operation? is the C 
		code doing too much work? */
		if (noCompoundArgs(unev))
			goto NO_COMPOUND_ARGS;
		save(func);
		goto ARG_LOOP;

	/* arguments:
		* unev has args
		* func and cont on stack */

	ARG_LOOP:
				print_info("ARG_LOOP");
		expr = firstArg(unev); 
		// avoids saving arglist, env, unev
		if (isSimple(expr))
			goto SIMPLE_ARG;
		goto COMPOUND_ARG;

	COMPOUND_ARG:
				print_info("COMPOUND_ARG");
		save(arglist);
		// avoids two saves
		if (isLastArg(unev)) 
			goto LAST_ARG;
		save(unev); // current and remaining args
		save(env);
		cont = LABELOBJ(_ACC_ARG);
		goto EVAL;

	ACC_ARG:
				print_info("ACC_ARG");
		restore(env);
		restore(unev);
		restore(arglist);
		arglist = adjoinArg(val, arglist);
		unev = restArgs(unev); 
		goto ARG_LOOP;

	LAST_ARG:
				print_info("LAST_ARG");
		cont = LABELOBJ(_DID_LAST_ARG);
		goto EVAL;

	DID_LAST_ARG:
				print_info("DID_LAST_ARG");
		restore(arglist);
		arglist = adjoinArg(val, arglist);
		goto RESTORE_FUNC;

	/* no argument saves, but func needs to be restored */

	SIMPLE_ARG:
				print_info("SIMPLE_ARG");
		cont = LABELOBJ(_DID_SIMPLE_ARG);
		goto EVAL;

	DID_SIMPLE_ARG:
				print_info("DID_SIMPLE_ARG");
		arglist = adjoinArg(val, arglist);
		if (isLastArg(unev))
			goto RESTORE_FUNC;
		unev = restArgs(unev);
		goto ARG_LOOP;

	RESTORE_FUNC:
				print_info("RESTORE_FUNC");
		restore(func);
		goto APPLY;

	/* no argument-related saves */

	NO_COMPOUND_ARGS:
				print_info("NO_COMPOUND_ARGS");
		cont = LABELOBJ(_REST_SIMPLE_ARGS);
		expr = firstArg(unev);
		goto EVAL; 
		
	REST_SIMPLE_ARGS:
				print_info("REST_SIMPLE_ARGS");		
		arglist = adjoinArg(val, arglist);
		if (isLastArg(unev))
			goto APPLY;
		unev = restArgs(unev);
		goto NO_COMPOUND_ARGS;

	/******************/

	APPLY:
				print_info("APPLY");
		if (isPrimitive(func))
			goto APPLY_PRIMITIVE;
		if (isCompiled(func))
			goto APPLY_COMPILED;
		if (isCompound(func))
			goto APPLY_COMPOUND;

	APPLY_PRIMITIVE:
				print_info("APPLY_PRIMITIVE");
		val = applyPrimitive(func, arglist);
		if (isError(val))
			goto START;
		restore(cont);
		goto CONTINUE;

	// only place env is assigned a new value
	APPLY_COMPOUND:
				print_info("APPLY_COMPOUND");
		unev = funcParams(func);
		env = funcEnv(func);
		env = extendEnv(unev, arglist, env);
		unev = funcBody(func);
		if (TAIL)
			goto SEQUENCE;
		goto ALT_SEQUENCE; 

	APPLY_COMPILED:
				print_info("APPLY_COMPILED");
		restore(cont); // to maintain contract
		val = COMPLABOBJ(func);
		goto COMP_LABEL;

	/* tail recursion is implented in SEQUENCE */

	SEQUENCE: // SEQUENCE never receives an empty list
				print_info("SEQUENCE");
		expr = firstExp(unev);
		if (isLastExp(unev))
			goto LAST_EXP;
		save(unev);
		save(env);
		cont = LABELOBJ(_SEQ_CONT);
		goto EVAL;

	SEQ_CONT:
				print_info("SEQ_CONT");
		restore(env);
		restore(unev);
		unev = restExps(unev);
		goto SEQUENCE;

	LAST_EXP:
				print_info("LAST_EXP");
		restore(cont);
		goto EVAL;

	/* alternatively, we could require that 
		the stack is always saved in full */

	ALT_SEQUENCE:
				print_info("ALT_SEQUENCE");
		if (noExps(unev))
			goto SEQ_END;
		expr = firstExp(unev);
		save(unev);
		save(env);
		cont = LABELOBJ(_ALT_SEQ_CONT);
		goto EVAL;

	ALT_SEQ_CONT:
				print_info("ALT_SEQ_CONT");
		restore(env);
		restore(unev);
		unev = restExps(unev);
		goto ALT_SEQUENCE;

	SEQ_END:
				print_info("SEQ_END");
		restore(cont);
		goto CONTINUE;


	/************************/

	DONE:
				print_info("DONE");
				print_final_val();
				if (STATS) print_stats();
		goto START;

	QUIT:
				free_memory();
				print_exit();
				return 0;

	/************************/

	COMPILED_CODE:
				print_info("COMPILED_CODE");
		COMPILED_CODE_BODY;

	CONTINUE:
				print_info("CONTINUE");
		// interpreter labels
		if (GETLABEL(cont) == _DONE)
			goto DONE;
		if (GETLABEL(cont) == _IF_DECIDE)
			goto IF_DECIDE;
		if (GETLABEL(cont) == _DID_ASS_VAL)
			goto DID_ASS_VAL;
		if (GETLABEL(cont) == _DID_DEF_VAL)
			goto DID_DEF_VAL;
		if (GETLABEL(cont) == _DID_FUNC)
			goto DID_FUNC;
		if (GETLABEL(cont) == _ACC_ARG)
			goto ACC_ARG;
		if (GETLABEL(cont) == _DID_LAST_ARG)
			goto DID_LAST_ARG;
		if (GETLABEL(cont) == _DID_SIMPLE_ARG)
			goto DID_SIMPLE_ARG;
		if (GETLABEL(cont) == _REST_SIMPLE_ARGS)
			goto REST_SIMPLE_ARGS;
		if (GETLABEL(cont) == _SEQ_CONT)
			goto SEQ_CONT;
		if (GETLABEL(cont) == _ALT_SEQ_CONT)
			goto ALT_SEQ_CONT;

		// compiler labels
		COMP_CONT(cont);

	COMP_LABEL:
				print_info("COMP_LABEL");
		COMP_CONT(val);

}
