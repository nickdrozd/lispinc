#include "llh.h"

/* input */

/* isQuit can't be defined in read.c because it affects
	how the evaluator itself runs, whereas the other 
	user commands (e.g. flag toggling) are executed 
	just by the read function. */

bool isQuit(Obj expr) {
	return GETTAG(expr) == NAME &&
		cmpForm(GETNAME(expr), QUIT_COMMAND);
}

/* primitive types */

bool isNum(Obj expr) {
	return GETTAG(expr) == NUM;
}

bool isVar(Obj expr) {
	return GETTAG(expr) == NAME;
}

/* special forms */

char* specialForm(Obj expr) {
	return GETNAME(CAR(GETLIST(expr)));
}

bool cmpForm(char* cand, char* form) {
	return strcmp(cand, form) == 0;
}

bool hasForm(Obj expr, char* form) {
	return cmpForm(specialForm(expr), form);
}

/* quotation */

bool isQuote(Obj expr) {
	return hasForm(expr, QUOTE_KEY);
}

Obj quotedText(Obj expr) {
	return CADR(GETLIST(expr));
}

/* begin */

bool isBegin(Obj expr) {
	return hasForm(expr, BEGIN_KEY);
}

Obj beginActions(Obj expr) {
	return LISTOBJ(CDR(GETLIST(expr)));
}

/* delay */

bool isDelay(Obj expr) {
	return hasForm(expr, DELAY_KEY);
}

Obj delayExpr(Obj expr) {
	return CADR(GETLIST(expr));
}

Obj makeDelay(Obj expr) {
	List* list = 
		makeList(LAMBDAOBJ,
			makeList(NULLOBJ, 
				makeList(delayExpr(expr), NULL)));

	Obj obj = LISTOBJ(list);
	return obj;
}

/* if */

bool isIf(Obj expr) {
	return hasForm(expr, IF_KEY);
}

Obj ifTest(Obj expr) {
	return CADR(GETLIST(expr));
}

// is this right?
bool isTrue(Obj expr) {
	return GETNUM(expr) != false;
}

Obj ifThen(Obj expr) {
	return CADDR(GETLIST(expr));
}

Obj ifElse(Obj expr) {
	return CADDDR(GETLIST(expr));
}

/* other boolean macros */

bool isAnd(Obj expr) {
	return hasForm(expr, AND_KEY);
}

bool isOr(Obj expr) {
	return hasForm(expr, OR_KEY);
}

Obj boolExps(Obj expr) {
	return LISTOBJ(CDR(GETLIST(expr)));
}

/* makeAnd and makeOr take and- and or-expressions and 
transform them into if-expressions. For example, the 
expression (and a b c d) is transformed into 
(if a (and b c d) false), and the expression 
(or a b c d) is tranformed into (if a true (or b c d)).
This is not a very efficient way to implement boolean 
expression, but it is the easiest way */

Obj makeAnd(Obj expr) {
	Obj seq = boolExps(expr);

	if (noExps(seq))
		return TRUEOBJ;

	Obj first = firstExp(seq);

	List* cdr = CDR(GETLIST(seq));
	Obj rest = 
		LISTOBJ(makeList(ANDOBJ, cdr));

	List* ifTrans = 
		makeList(IFOBJ, 
			makeList(first, 
				makeList(rest, 
					makeList(FALSEOBJ, NULL))));

	return LISTOBJ(ifTrans);
}

Obj makeOr(Obj expr) {
	Obj seq = boolExps(expr);

	if (noExps(seq))
		return FALSEOBJ;

	Obj first = firstExp(seq);

	List* cdr = CDR(GETLIST(seq));
	Obj rest = 
		LISTOBJ(makeList(OROBJ, cdr));

	List* ifTrans = 
		makeList(IFOBJ, 
			makeList(first, 
				makeList(TRUEOBJ, 
					makeList(rest, NULL))));

	return LISTOBJ(ifTrans);
}


/* lambda */

bool isLambda(Obj expr) {
	return hasForm(expr, LAMBDA_KEY);
}

Obj lambdaParams(Obj expr) {
	return CADR(GETLIST(expr));
}

/* to allow for implicit begin blocks, change this
and some other functions to provide for a list of
body expressions; otherwise, explicit begins are needed
for, e.g, iterative factorial */

Obj lambdaBody(Obj expr) {
	return LISTOBJ(CDDR(GETLIST(expr)));
}

Obj makeFunc(Obj params, Obj body, Obj env) {
	// List* list = 
	// 	makeList(LAMBDAOBJ,
	// 		makeList(params,
	// 			makeList(body,
	// 				makeList(env, NULL))));

	List* list = 
		makeList(env,
			makeList(params, 
				makeList(body, NULL)));

	Obj obj = LISTOBJ(list);
	return obj;
}

/* ass, def */

bool isAss(Obj expr) {
	return hasForm(expr, ASS_KEY);
}

Obj assVar(Obj expr) {
	return CADR(GETLIST(expr));
}

Obj assVal(Obj expr) {
	return CADDR(GETLIST(expr));
}

// -- setVar in env.c

bool isDef(Obj expr) {
	return hasForm(expr, DEF_KEY);
}

Obj defVar(Obj expr) {
	return CADR(GETLIST(expr));
}

Obj defVal(Obj expr) {
	return CADDR(GETLIST(expr));
}

// -- defineVar in env.c

/* set-car! and set-cdr! */

bool isSetCar(Obj expr) {
	return hasForm(expr, SETCAR_KEY);
}

Obj makeSetCar(Obj expr) {
	Obj var = assVar(expr);
	Obj carVal = assVal(expr);

	Obj cdrVal = 
		LISTOBJ(makeList(NAMEOBJ("cdr"),
					makeList(var, NULL)));

	List* newVal =
		makeList(NAMEOBJ("cons"),
			makeList(carVal,
				makeList(cdrVal, NULL)));

	List* newExpr = 
		makeList(ASSOBJ,
			makeList(var,
				makeList(LISTOBJ(newVal), NULL)));

	return LISTOBJ(newExpr); 
}

bool isSetCdr(Obj expr) {
	return hasForm(expr, SETCDR_KEY);
}

Obj makeSetCdr(Obj expr) {
	Obj var = assVar(expr);
	Obj cdrVal = assVal(expr);

	Obj carVal = 
		LISTOBJ(makeList(NAMEOBJ("car"),
					makeList(var, NULL)));

	List* newVal =
		makeList(NAMEOBJ("cons"),
			makeList(carVal,
				makeList(cdrVal, NULL)));

	List* newExpr = 
		makeList(ASSOBJ,
			makeList(var,
				makeList(LISTOBJ(newVal), NULL)));

	return LISTOBJ(newExpr); 
}

/* function */

Obj getFunc(Obj expr) {
	return CAR(GETLIST(expr));
}

// expr is expression or function itself?
bool isSimpleFunc(Obj expr) {
	// return isVar(getFunc(expr));
	return isVar(expr);
}

Obj getArgs(Obj expr) {
	return LISTOBJ(CDR(GETLIST(expr)));
}

// -- empty_arglist macro

bool noArgs(Obj expr) {
	return GETLIST(expr) == NULL;
}

Obj firstArg(Obj expr) {
	return CAR(GETLIST(expr));
}

bool isLastArg(Obj expr) {
	return CDR(GETLIST(expr)) == NULL;
}

/* adjoinArg walks down the whole length 
of the arglist to append a value to the end. 
This is less efficient than building the list 
backwards and then reversing, but it makes 
the info display easier to read. */

Obj adjoinArg(Obj val, Obj arglist) {
	List* args = GETLIST(arglist);

	if (!args)
		return LISTOBJ(makeList(val,args));

	List* pnr = args;
	while (pnr->cdr) 
		pnr = pnr->cdr;
	
	pnr->cdr = malloc(sizeof(List));
	pnr = pnr->cdr;
	pnr->car = val;
	pnr->cdr = NULL;

	return LISTOBJ(args);
}

Obj restArgs(Obj expr) {
	return LISTOBJ(CDR(GETLIST(expr)));
}

/* apply */

bool isPrimitive(Obj obj) {
	return GETTAG(obj) == PRIM;
}

bool isCompound(Obj obj) {
	return GETTAG(obj) == LIST;
}


// clean this up!
Obj applyPrimitive(Obj func, Obj arglist) {
			debug_print("applying PRIMITIVE...");
	List* list = GETLIST(arglist);

	primType type = func.val.prim.type;

	if (type == INTPRIM) {
		int arg1 = list->car.val.num;
		int arg2 = list->cdr->car.val.num;
				// if (INFO) printf("arg1: %d\narg2: %d\n\n", arg1, arg2);
		intFunc prim = func.val.prim.func.intfunc;
		int result = (*prim)(arg1, arg2);
		return NUMOBJ(result);
	}
	
	else if (type == OBJPRIM) {
		Obj arg = list->car;
				// if (INFO) ;
		objFunc prim = func.val.prim.func.objfunc;
		int result = (*prim)(arg);
		return NUMOBJ(result);
	}

	else {
				debug_print("apply_primitive: unknown primitive function type!");
		return DUMMYOBJ;
	}
}

// make sure these coordinate with makeFunc

Obj funcParams(Obj obj) {
	return CADR(GETLIST(obj));
}

Obj funcBody(Obj obj) {
	return CADDR(GETLIST(obj));
}

Obj funcEnv(Obj obj) {
	return CAR(GETLIST(obj));
}

// extendEnv in env.c

/* sequence */

Obj firstExp(Obj seq) {
	return CAR(GETLIST(seq));
}

Obj restExps(Obj seq) {
	return LISTOBJ(CDR(GETLIST(seq)));
}

// UGLY HACK
bool isLastExp(Obj seq) {
	List* next = CDR(GETLIST(seq));
	return next == NULL || next->car.tag == ENV;
	//return CDR(GETLIST(seq)) == NULL;
}

// UGLY HACK
bool noExps(Obj seq) {
	List* list = GETLIST(seq);
	return GETLIST(seq) == NULL ||
				list->car.tag == ENV;
}



/* the old version of applyPrimitive, before adding 
	the PRIM type that made everything messy */

// bool isPrimitive(Obj obj) {
// 	return GETTAG(obj) == FUNC;
// }

// bool isCompound(Obj obj) {
// 	return GETTAG(obj) == LIST;
// }

// Obj applyPrimitive(Obj func, Obj arglist) {
// 			if (INFO) printf("%s\n", "applying PRIMITIVE...");
// 	List* list = GETLIST(arglist);
// 	int arg1 = list->car.val.num;
// 	int arg2 = list->cdr->car.val.num;
// 			if (INFO) printf("arg1: %d\narg2: %d\n\n", arg1, arg2);
// 	intFunc prim = func.val.func;
// 	int result = (*prim)(arg1, arg2);
// 	return NUMOBJ(result);
// }