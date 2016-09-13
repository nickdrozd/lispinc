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
				if (INFO) print_base_env();
				// if (INFO) print_info("START");
		expr = read_code();
				debug_print("ec_main -- code read!");
		if (isQuit(expr)) 
			goto QUIT;
		cont = LABELOBJ(_DONE);
		goto EVAL;

	/************************/

	EVAL:
				if (INFO) print_info("EVAL");
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
		if (isSetCar(expr))
			goto SET_CAR;
		if (isSetCdr(expr))
			goto SET_CDR;
		goto FUNCTION;


	NUMBER:
				if (INFO) print_info("NUMBER");
		val = expr;
		goto CONTINUE;

	VARIABLE:
				if (INFO) print_info("VARIABLE");
				debug_print(GETNAME(expr));
		val = lookup(expr, env);
		if (isUnbound(val))
			goto UNBOUND;
		goto CONTINUE;

	UNBOUND:
				if (INFO) print_info("UNBOUND");
				print_unbound();
		goto START;

	QUOTATION:
				if (INFO) print_info("QUOTATION");
		val = quotedText(expr);
		goto CONTINUE;

	BEGIN:
				if (INFO) print_info("BEGIN");
		unev = beginActions(expr);
		save(cont);
		goto SEQUENCE;

	DELAY:
				if (INFO) print_info("DELAY");
		expr = makeDelay(expr);
		goto EVAL;

	LAMBDA:
				if (INFO) print_info("LAMBDA");
		unev = lambdaParams(expr);
		expr = lambdaBody(expr);
		val = makeFunc(unev, expr, env);
		goto CONTINUE;

	/* if (and other boolean macros) */

	IF:
				if (INFO) print_info("IF");
		save(expr);
		save(env);
		save(cont);
		cont = LABELOBJ(_IF_DECIDE);
		expr = ifTest(expr);
		goto EVAL;

	IF_DECIDE:
				if (INFO) print_info("IF_DECIDE");
		restore(cont);
		restore(env);
		restore(expr);
		if (isTrue(val))
			goto IF_THEN;
		goto IF_ELSE;

	IF_THEN:
				if (INFO) print_info("IF_THEN");
		expr = ifThen(expr);
		goto EVAL;

	IF_ELSE:
				if (INFO) print_info("IF_ELSE");
		expr = ifElse(expr);
		goto EVAL;

	AND:
				if (INFO) print_info("AND");
		expr = makeAnd(expr);
		goto EVAL;

	OR:
				if (INFO) print_info("OR");
		expr = makeOr(expr);
		goto EVAL;

	/* ass, def */

	#define ASS_DEF_RETURN_VAL DUMMYOBJ
		
	// leave ass/def val as return val?

	ASSIGNMENT:
				if (INFO) print_info("ASSIGNMENT");
		unev = assVar(expr);
		save(unev);
		expr = assVal(expr);
		save(env);
		save(cont);
		cont = LABELOBJ(_DID_ASS_VAL);
		goto EVAL;

	DID_ASS_VAL:
				if (INFO) print_info("DID_ASS_VAL");
		restore(cont);
		restore(env);
		restore(unev);
		setVar(unev, val, env); // var, val, env
		// val = ASS_DEF_RETURN_VAL;
		goto CONTINUE;

	DEFINITION:
				if (INFO) print_info("DEFINITION");
		unev = defVar(expr);
		save(unev);
		expr = defVal(expr);
		save(env);
		save(cont);
		cont = LABELOBJ(_DID_DEF_VAL);
		goto EVAL;

	DID_DEF_VAL:
				if (INFO) print_info("DID_DEF_VAL");
		restore(cont);
		restore(env);
		restore(unev);
		defineVar(unev, val, env); // var, val, env
		// val = ASS_DEF_RETURN_VAL;
		goto CONTINUE;

	SET_CAR:
				if (INFO) print_info("SET_CAR");
		expr = makeSetCar(expr);
		goto EVAL;

	SET_CDR:
				if (INFO) print_info("SET_CDR");
		expr = makeSetCdr(expr);
		goto EVAL;

	/******************/

	/* function application */

	FUNCTION:
				if (INFO) print_info("FUNCTION");
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
				if (INFO) print_info("DID_FUNC");
		restore(unev);
		restore(env);
		func = val;
		goto CHECK_NO_ARGS;

	SIMPLE_FUNC:
				if (INFO) print_info("SIMPLE_FUNC");
		func = lookup(expr, env);
		if (isUnbound(func))
			goto UNBOUND;
		goto CHECK_NO_ARGS;

	#define empty_arglist NULLOBJ

	CHECK_NO_ARGS:
				if (INFO) print_info("CHECK_NO_ARGS");
		arglist = empty_arglist;
		// avoids ARG_LOOP
		if (noArgs(unev)) 
			goto APPLY;
		/* is there an honest way to avoid this save? */
		save(func);
		goto ARG_LOOP;

	/* arguments:
		* unev has args
		* func and cont on stack */

	ARG_LOOP:
				if (INFO) print_info("ARG_LOOP");
		expr = firstArg(unev); 
		if (isSimple(expr))
			goto SIMPLE_ARG;
		goto COMPOUND_ARG;

	COMPOUND_ARG:
		save(arglist);
		// avoids ACC_ARG (two saves)
		if (isLastArg(unev)) 
			goto LAST_ARG;
		save(unev); // current and remaining args
		save(env);
		cont = LABELOBJ(_ACC_ARG);
		goto EVAL;

	ACC_ARG:
				if (INFO) print_info("ACC_ARG");
		restore(env);
		restore(unev);
		restore(arglist);
		arglist = adjoinArg(val, arglist);
		unev = restArgs(unev); 
		goto ARG_LOOP;

	LAST_ARG:
				if (INFO) print_info("LAST_ARG");
		cont = LABELOBJ(_DID_LAST_ARG);
		goto EVAL;

	DID_LAST_ARG:
				if (INFO) print_info("DID_LAST_ARG");
		restore(arglist);
		arglist = adjoinArg(val, arglist);
		goto RESTORE_FUNC;

	SIMPLE_ARG:
				if (INFO) print_info("SIMPLE_ARG");
		cont = LABELOBJ(_DID_SIMPLE_ARG);
		goto EVAL;

	DID_SIMPLE_ARG:
				if (INFO) print_info("DID_SIMPLE_ARG");
		arglist = adjoinArg(val, arglist);
		if (isLastArg(unev))
			goto RESTORE_FUNC;
		unev = restArgs(unev);
		goto ARG_LOOP;

	RESTORE_FUNC:
				if (INFO) print_info("RESTORE_FUNC");
		restore(func);
		goto APPLY;


	/******************/

	APPLY:
				if (INFO) print_info("APPLY");
		if (isPrimitive(func))
			goto APPLY_PRIMITIVE;
		if (isCompiled(func))
			goto APPLY_COMPILED;
		if (isCompound(func))
			goto APPLY_COMPOUND;

	APPLY_COMPILED:
				if (INFO) print_info("APPLY_COMPILED");
		restore(cont); // to maintain contract
		val = COMPLABOBJ(func);
		goto COMP_LABEL;

	APPLY_PRIMITIVE:
				if (INFO) print_info("APPLY_PRIMITIVE");
		val = applyPrimitive(func, arglist);
		restore(cont);
		goto CONTINUE;

	// only place env is assigned a new value
	APPLY_COMPOUND:
				if (INFO) print_info("APPLY_COMPOUND");
		unev = funcParams(func);
		env = funcEnv(func);
		env = extendEnv(unev, arglist, env);
		unev = funcBody(func);
		if (TAIL)
			goto SEQUENCE;
		goto ALT_SEQUENCE; 

	/* tail recursion is implented in SEQUENCE */

	SEQUENCE: // SEQUENCE never receives an empty list
				if (INFO) print_info("SEQUENCE");
		expr = firstExp(unev);
		if (isLastExp(unev))
			goto LAST_EXP;
		save(unev);
		save(env);
		cont = LABELOBJ(_SEQ_CONT);
		goto EVAL;

	SEQ_CONT:
				if (INFO) print_info("SEQ_CONT");
		restore(env);
		restore(unev);
		unev = restExps(unev);
		goto SEQUENCE;

	LAST_EXP:
				if (INFO) print_info("LAST_EXP");
		restore(cont);
		goto EVAL;

	/* alternatively, we could require that 
		the stack is always saved in full */

	ALT_SEQUENCE:
				if (INFO) print_info("ALT_SEQUENCE");
		if (noExps(unev))
			goto SEQ_END;
		expr = firstExp(unev);
		save(unev);
		save(env);
		cont = LABELOBJ(_ALT_SEQ_CONT);
		goto EVAL;

	ALT_SEQ_CONT:
				if (INFO) print_info("ALT_SEQ_CONT");
		restore(env);
		restore(unev);
		unev = restExps(unev);
		goto ALT_SEQUENCE;

	SEQ_END:
				if (INFO) print_info("SEQ_END");
		restore(cont);
		goto CONTINUE;


	/************************/

	DONE:
				if (INFO) print_info("DONE");
				print_final_val();
				if (STATS) print_stats();
		goto START;

	QUIT:
				free_memory();
				print_exit();
				return 0;

	/************************/

	COMPILED_CODE:
				if (INFO) print_info("COMPILED_CODE");
		COMPILED_CODE_BODY;

	CONTINUE:
				if (INFO) print_info("CONTINUE");
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
		if (GETLABEL(cont) == _SEQ_CONT)
			goto SEQ_CONT;
		if (GETLABEL(cont) == _ALT_SEQ_CONT)
			goto ALT_SEQ_CONT;

		// compiler labels
		COMP_CONT(cont);

	COMP_LABEL:
				if (INFO) print_info("COMP_LABEL");
		COMP_CONT(val);

}
