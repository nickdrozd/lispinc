/*
    Low-Level Helpers

    These functions perform mostly boring tasks like determing whether
    an expression is lambda expression. The idea is that in a real
    register machine, these would be implemented as primitive machine
    operations.
*/

#ifndef LLH_GUARD
#define LLH_GUARD

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "flags.h"
#include "keywords.h"
#include "objects.h"
#include "print.h"
#include "tally.h"

bool isQuit(Obj expr);

bool isNum(Obj expr);
bool isBool(Obj expr);

bool isVar(Obj expr);
bool isUnbound(Obj expr);

char* specialForm(Obj expr);
bool cmpForm(char* cand, char* form);
bool hasForm(Obj expr, char* form);

bool isQuote(Obj expr);
Obj quotedText(Obj expr);

bool isBegin(Obj expr);
Obj beginActions(Obj expr);

bool isDelay(Obj expr);
Obj delayExpr(Obj expr);
Obj transformDelay(Obj expr);

bool isIf(Obj expr);
Obj ifTest(Obj expr);
bool isTrue(Obj expr);
Obj ifThen(Obj expr);
Obj ifElse(Obj expr);

bool isAnd(Obj expr);
bool isOr(Obj expr);
Obj boolExps(Obj expr);
Obj transformAnd(Obj seq);
Obj transformOr(Obj seq);

bool isLambda(Obj expr);
Obj lambdaParams(Obj expr);
Obj lambdaBody(Obj expr);
Obj makeFunc(Obj params, Obj body, Obj env);

bool isDef(Obj expr);
Obj defVar(Obj expr);
Obj defVal(Obj expr);
bool isSugarDef(Obj expr);
Obj transformSugarDef(Obj expr);

bool isAss(Obj expr);
Obj assVar(Obj expr);
Obj assVal(Obj expr);

/* FUNCTION */
bool isSimple(Obj expr);

Obj getArgs(Obj expr);
Obj getFunc(Obj expr);
bool noArgs(Obj expr);
bool noCompoundArgs(Obj expr);

/* ARG_LOOP */
Obj firstArg(Obj expr);
bool isLastArg(Obj expr);
Obj adjoinArg(Obj val, Obj arglist);
Obj restArgs(Obj expr);

/* APPLY */
bool isPrimitive(Obj obj);
bool isCompound(Obj obj);
bool isCompiled(Obj obj);

Obj funcParams(Obj obj);
Obj funcBody(Obj obj);
Obj funcEnv(Obj obj);

/* SEQUENCE */
Obj firstExp(Obj seq);
Obj restExps(Obj seq);
bool isLastExp(Obj seq);
bool noExps(Obj seq);

/* error-checking */
bool isError(Obj obj);

#endif
