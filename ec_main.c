/*
	TODO:
		* add new labels / change old labels
		* make_$_Exec functions
		* print_info

	make_$_Exec functions return lists of the form 
	($_EXEC_LABEL, info, ...)

	eg makeLambdaExec -> (LAMBDA_EXEC, params, body)

	ideally these extra parameters should appear in 
	the same order in which they appear in lisp 
	expressions so that the same expression selectors 
	can be used. for instance, lambdaParams can be 
	used for a real lambda expression and for the 
	lambdaExec function, since the parameters are the 
	cadr of both.
*/



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
		save(env);
		save(cont);
		cont = LABELOBJ(_EXECUTE);
		goto ANALYZE;


	// analyze expects something in expr
	ANALYZE:
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
		val = makeNumExec(expr);
		goto CONTINUE;

	QUOTATION:
		val = makeQuoteExec(expr);
		goto CONTINUE;

	VARIABLE:
		val = makeVarExec(expr);
		goto CONTINUE;

	LAMBDA:
				print_info("LAMBDA");
		unev = lambdaParams(expr);
		save(unev);
		expr = lambdaBody(expr);
		save(cont);
		cont = LABELOBJ(BODY_ANALYZED);
		goto SEQUENCE;

	BODY_ANALYZED:
		restore(cont);
		restore(unev); // parameters
		val = makeLambdaExec(unev, val);
		goto CONTINUE; // CONTINUE???


	DEFINITION:
				print_info("DEFINITION");
		if (isSugarDef(expr))
			expr = transformSugarDef(expr);
		unev = defVar(expr);
		save(unev);
		expr = defVal(expr);
		save(cont);
		cont = LABELOBJ(_DEF_VAL_ANALYZED);
		goto ANALYZE;

	DEF_VAL_ANALYZED:
				print_info("DEF_VAL_ANALYZED");
		restore(cont);
		restore(unev);
		val = makeDefExec(unev, val);
		goto CONTINUE;

	// ASSIGNMENT:

	// ASS_VAL_ANALYZED:







	EXECUTE:
		restore(cont);
		restore(env);
		// dispatch on label bound in val

	NUM_EXEC:
		val = execNum(val);
		goto CONTINUE;

	QUOTE_EXEC:
		val = execQuote(val);
		goto CONTINUE;

	VAR_EXEC:
		val = execVar(val);
		val = lookup(val, env);
		if (isUnbound(val))
			goto UNBOUND;
		goto CONTINUE;

	UNBOUND:
				print_info("UNBOUND");
		print_unbound();
		goto START;

	LAMBDA_EXEC:
		unev = lambdaParams(val);
		val = lambdaBody(val);
		val = makeFunc(unev, val, env);
		goto CONTINUE;



	DEF_EXEC: // is this needed?
		unev = defVar(val);
		save(unev);
		val = defVal(val);
		save(cont);
		cont = LABELOBJ(_DEF_VAL_EXECUTED);
		goto EXECUTE; // ???

	DEF_VAL_EXECUTED:
		restore(cont);
		restore(unev);
		defineVar(unev, val, env); // var, val, env
		// val = ASS_DEF_RETURN_VAL;
		goto CONTINUE;

	// ASS_EXEC:

	// ASS_VAL_EXECUTED:










}