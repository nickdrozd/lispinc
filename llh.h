/*
	Low-Level Helpers

	These functions perform mostly boring
	tasks like determing whether an expression
	is lambda expression. The idea is that in
	a real register machine, these would be
	implemented as primitive machine operations.

	One function, adjoinArgs, turned out to be
	bizarrely difficult to implement correctly 
	and stalled the whole project for three days.
	Several failed attempts have been preserved
	at the end of the file.
*/

#ifndef LLH_GUARD
#define LLH_GUARD

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
		
#include "objects.h"
#include "keywords.h"
#include "flags.h"

bool isQuit(Obj expr);

bool isNum(Obj expr);
bool isVar(Obj expr);

char* specialForm(Obj expr);
bool cmpForm(char* cand, char* form);
bool hasForm(Obj expr, char* form);

bool isQuote(Obj expr);
Obj quotedText(Obj expr);

bool isBegin(Obj expr);
Obj beginActions(Obj expr);

bool isDelay(Obj expr);
Obj delayExpr(Obj expr);
Obj makeDelay(Obj expr);

bool isIf(Obj expr);
Obj ifTest(Obj expr);
bool isTrue(Obj expr);
Obj ifThen(Obj expr);
Obj ifElse(Obj expr);

bool isLambda(Obj expr);
Obj lambdaParams(Obj expr);
Obj lambdaBody(Obj expr);
Obj makeFunc(Obj params, Obj body, Obj env);

bool isAss(Obj expr);
Obj assVar(Obj expr);
Obj assVal(Obj expr);
bool isDef(Obj expr);
Obj defVar(Obj expr);
Obj defVal(Obj expr);

Obj getArgs(Obj expr);
Obj getFunc(Obj expr);
bool noArgs(Obj expr);
Obj firstArg(Obj expr);
bool isLastArg(Obj expr);
Obj adjoinArg(Obj val, Obj arglist);
Obj restArgs(Obj expr);
bool isPrimitive(Obj obj);
bool isCompound(Obj obj);
Obj applyPrimitive(Obj func, Obj arglist);
Obj funcParams(Obj obj);
Obj funcBody(Obj obj);
Obj funcEnv(Obj obj);
Obj firstExp(Obj seq);
Obj restExps(Obj seq);
bool isLastExp(Obj seq);
bool noExps(Obj seq);

#endif