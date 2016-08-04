#include "ec_main.h"

int main(void) {
			debug_print("starting main...");

	print_intro();

	base_env = makeBaseEnv();

	START:
				main_label = "START";
		initialize_registers();
		initialize_stack();
		env = ENVOBJ(base_env);
				if (INFO) print_base_env();
				if (INFO) print_info();
		expr = read_code();
				debug_print("ec_main -- code read!");
		if (isQuit(expr)) 
			goto QUIT;
		cont = LABELOBJ(_DONE);
		goto EVAL;

	CONTINUE:
				main_label = "CONTINUE";
				if (INFO) print_info();
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
		if (GETLABEL(cont) == _SEQ_CONT)
			goto SEQ_CONT;
		if (GETLABEL(cont) == _ALT_SEQ_CONT)
			goto ALT_SEQ_CONT;

	EVAL:
				main_label = "EVAL";
				if (INFO) print_info();
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
				main_label = "NUMBER";
				if (INFO) print_info();
		val = expr;
		goto CONTINUE;

	VARIABLE:
				main_label = "VARIABLE";
				if (INFO) print_info();
				debug_print(GETNAME(expr));
		val = lookup(expr, env);
		if (GETTAG(val) == DUMMY)
			goto UNBOUND;
		goto CONTINUE;

	UNBOUND:
				main_label = "UNBOUND";
				if (INFO) print_info();
				print_unbound();
		goto START;

	QUOTATION:
				main_label = "QUOTATION";
				if (INFO) print_info();
		val = quotedText(expr);
		goto CONTINUE;

	BEGIN:
				main_label = "BEGIN";
				if (INFO) print_info();
		unev = beginActions(expr);
		save(cont);
		goto SEQUENCE;

	LAMBDA:
				main_label = "LAMBDA";
				if (INFO) print_info();
		unev = lambdaParams(expr);
		expr = lambdaBody(expr);
		val = makeFunc(unev, expr, env);
		goto CONTINUE;

	/* if (and other boolean macros) */

	IF:
				main_label = "IF";
				if (INFO) print_info();
		save(expr);
		save(env);
		save(cont);
		cont = LABELOBJ(_IF_DECIDE);
		expr = ifTest(expr);
		goto EVAL;

	IF_DECIDE:
				main_label = "IF_DECIDE";
				if (INFO) print_info();
		restore(&cont);
		restore(&env);
		restore(&expr);
		if (isTrue(val))
			goto IF_THEN;
		goto IF_ELSE;

	IF_THEN:
				main_label = "IF_THEN";
				if (INFO) print_info();
		expr = ifThen(expr);
		goto EVAL;

	IF_ELSE:
				main_label = "IF_ELSE";
				if (INFO) print_info();
		expr = ifElse(expr);
		goto EVAL;

	/* ass, def */

	#define ASS_DEF_RETURN_VAL MKOBJ(NAME, name, "ok")
		
	// leave ass/def val as return val?

	ASSIGNMENT:
				main_label = "ASSIGNMENT";
				if (INFO) print_info();
		unev = assVar(expr);
		save(unev);
		expr = assVal(expr);
		save(env);
		save(cont);
		cont = LABELOBJ(_DID_ASS_VAL);
		goto EVAL;

	DID_ASS_VAL:
				main_label = "DID_ASS_VAL";
				if (INFO) print_info();
		restore(&cont);
		restore(&env);
		restore(&unev);
		setVar(unev, val, env); // var, val, env
		// val = ASS_DEF_RETURN_VAL;
		goto CONTINUE;

	DEFINITION:
				main_label = "DEFINITION";
				if (INFO) print_info();
		unev = defVar(expr);
		save(unev);
		expr = defVal(expr);
		save(env);
		save(cont);
		cont = LABELOBJ(_DID_DEF_VAL);
		goto EVAL;

	DID_DEF_VAL:
				main_label = "DID_DEF_VAL";
				if (INFO) print_info();
		restore(&cont);
		restore(&env);
		restore(&unev);
		defineVar(unev, val, &env); // var, val, env
		// val = ASS_DEF_RETURN_VAL;
		goto CONTINUE;


	/******************/

	/* function application */

	FUNCTION:
				main_label = "FUNCTION";
				if (INFO) print_info();
		save(cont);
		save(env);
		unev = getArgs(expr);
		save(unev);
		expr = getFunc(expr);
		cont = LABELOBJ(_DID_FUNC);
		goto EVAL;

	#define empty_arglist MKOBJ(LIST, list, NULL)

	DID_FUNC:
				main_label = "DID_FUNC";
				if (INFO) print_info();
		restore(&unev); // the arguments
		restore(&env);
		arglist = empty_arglist; // #definition above
		func = val;
		if (noArgs(unev)) // (null? unev)
			goto APPLY;
		save(func);
		goto ARG_LOOP;

	ARG_LOOP:
				main_label = "ARG_LOOP";
				if (INFO) print_info();
		save(arglist);
		expr = firstArg(unev); // (car unev)
		if (isLastArg(unev)) // (null? (cdr unev))
			goto LAST_ARG;
		save(env);
		save(unev);
		cont = LABELOBJ(_ACC_ARG);
		goto EVAL;

	ACC_ARG:
				main_label = "ACC_ARG";
				if (INFO) print_info();
		restore(&unev);
		restore(&env);
		restore(&arglist);
		// append val to end of arglist
		arglist = adjoinArg(val, arglist);
		unev = restArgs(unev); // (cdr unev)
		goto ARG_LOOP;

	LAST_ARG:
				main_label = "LAST_ARG";
				if (INFO) print_info();
		cont = LABELOBJ(_DID_LAST_ARG);
		goto EVAL;

	DID_LAST_ARG:
				main_label = "DID_LAST_ARG";
				if (INFO) print_info();
		restore(&arglist);
		arglist = adjoinArg(val, arglist);
		restore(&func);
		goto APPLY;


	/******************/

	APPLY:
				main_label = "APPLY";
				if (INFO) print_info();
		if (isPrimitive(func))
			goto APPLY_PRIMITIVE;
		if (isCompound(func))
			goto APPLY_COMPOUND;

	APPLY_PRIMITIVE:
				main_label = "APPLY_PRIMITIVE";
				if (INFO) print_info();
		val = applyPrimitive(func, arglist);
		restore(&cont);
		goto CONTINUE;

	// only place env is assigned a new value
	APPLY_COMPOUND:
				main_label = "APPLY_COMPOUND";
				if (INFO) print_info();
		unev = funcParams(func);
		env = funcEnv(func);
		env = extendEnv(unev, arglist, env);
		unev = funcBody(func);
		if (TAIL)
			goto SEQUENCE;
		goto ALT_SEQUENCE; 

	/* tail recursion is implented in SEQUENCE */

	SEQUENCE: // SEQUENCE never receives an empty list
				main_label = "SEQUENCE";
				if (INFO) print_info();
		expr = firstExp(unev);
		if (isLastExp(unev))
			goto LAST_EXP;
		save(unev);
		save(env);
		cont = LABELOBJ(_SEQ_CONT);
		goto EVAL;

	SEQ_CONT:
				main_label = "SEQ_CONT";
				if (INFO) print_info();
		restore(&env);
		restore(&unev);
		unev = restExps(unev);
		goto SEQUENCE;

	LAST_EXP:
				main_label = "LAST_EXP";
				if (INFO) print_info();
		restore(&cont);
		goto EVAL;

	/* alternatively, we could require that 
		the stack is always saved in full */

	ALT_SEQUENCE:
				main_label = "ALT_SEQUENCE";
				if (INFO) print_info();
		if (noExps(unev))
			goto SEQ_END;
		expr = firstExp(unev);
		save(unev);
		save(env);
		cont = LABELOBJ(_ALT_SEQ_CONT);
		goto EVAL;

	ALT_SEQ_CONT:
				main_label = "ALT_SEQ_CONT";
				if (INFO) print_info();
		restore(&env);
		restore(&unev);
		unev = restExps(unev);
		goto ALT_SEQUENCE;

	SEQ_END:
				main_label = "SEQ_END";
				if (INFO) print_info();
		restore(&cont);
		goto CONTINUE;


	/************************/

	DONE:
				main_label = "DONE";
				if (INFO) print_info();
				print_final_val();
				if (STATS) print_stats();
		goto START;

	QUIT:
				main_label = "QUIT";
				free_memory();
				print_exit();
				return 0;
}














