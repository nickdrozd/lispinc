#include "llh.h"

/* input */

/* isQuit can't be defined in read.c because it affects
    how the evaluator itself runs, whereas the other
    user commands (e.g. flag toggling) are executed
    just by the read function. */

bool isQuit(Obj expr) {
    return GETTAG(expr) == NAME && cmpForm(GETNAME(expr), QUIT_COMMAND);
}

/* numbers */

bool isNum(Obj expr) {
    form_check_count++;
    return GETTAG(expr) == NUM || isBool(expr);
}

bool isBool(Obj expr) { return GETTAG(expr) == BOOL_; }

/* variables */

bool isVar(Obj expr) {
    form_check_count++;
    return GETTAG(expr) == NAME;
}

bool isUnbound(Obj expr) { return GETTAG(expr) == DUMMY; }

/* special forms */

char* specialForm(Obj expr) { return GETNAME(CAR(expr)); }

bool cmpForm(char* cand, char* form) { return strcmp(cand, form) == 0; }

bool hasForm(Obj expr, char* form) {
    form_check_count++;
    return cmpForm(specialForm(expr), form);
}

/* quotation */

bool isQuote(Obj expr) { return hasForm(expr, QUOTE_KEY); }

Obj quotedText(Obj expr) { return CADR(expr); }

/* begin */

bool isBegin(Obj expr) { return hasForm(expr, BEGIN_KEY); }

Obj beginActions(Obj expr) { return CDR(expr); }

/* delay */

bool isDelay(Obj expr) { return hasForm(expr, DELAY_KEY); }

Obj delayExpr(Obj expr) { return CADR(expr); }

Obj transformDelay(Obj expr) {
    List* list =
        makeList(LAMBDAOBJ, makeList(NULLOBJ, makeList(delayExpr(expr), NULL)));

    Obj obj = LISTOBJ(list);
    return obj;
}

/* if */

bool isIf(Obj expr) { return hasForm(expr, IF_KEY); }

Obj ifTest(Obj expr) { return CADR(expr); }

// is this right?
bool isTrue(Obj expr) {
    switch (GETTAG(expr)) {
        case NUM:
            return GETNUM(expr) != false;
        case BOOL_:
            return GETBOOL(expr) != false;
        default:
            return true;
    }
}

Obj ifThen(Obj expr) { return CADDR(expr); }

Obj ifElse(Obj expr) { return CADDDR(expr); }

/* other boolean macros */

bool isAnd(Obj expr) { return hasForm(expr, AND_KEY); }

bool isOr(Obj expr) { return hasForm(expr, OR_KEY); }

Obj boolExps(Obj expr) { return CDR(expr); }

/* transformAnd and transformOr take and- and or-expressions and
transform them into if-expressions. For example, the
expression (and a b c d) is transformed into
(if a (and b c d) false), and the expression
(or a b c d) is tranformed into (if a true (or b c d)).
This is not a very efficient way to implement boolean
expression, but it is the easiest way */

Obj transformAnd(Obj expr) {
    Obj seq = boolExps(expr);

    if (noExps(seq)) return TRUEOBJ;

    Obj first = firstExp(seq);

    List* cdr = GETLIST(seq)->cdr;
    Obj rest = LISTOBJ(makeList(ANDOBJ, cdr));

    List* ifTrans = makeList(
        IFOBJ, makeList(first, makeList(rest, makeList(FALSEOBJ, NULL))));

    return LISTOBJ(ifTrans);
}

Obj transformOr(Obj expr) {
    Obj seq = boolExps(expr);

    if (noExps(seq)) return FALSEOBJ;

    Obj first = firstExp(seq);

    List* cdr = GETLIST(seq)->cdr;
    Obj rest = LISTOBJ(makeList(OROBJ, cdr));

    List* ifTrans = makeList(
        IFOBJ, makeList(first, makeList(TRUEOBJ, makeList(rest, NULL))));

    return LISTOBJ(ifTrans);
}

/* lambda */

bool isLambda(Obj expr) { return hasForm(expr, LAMBDA_KEY); }

Obj lambdaParams(Obj expr) { return CADR(expr); }

/* to allow for implicit begin blocks, change this
and some other functions to provide for a list of
body expressions; otherwise, explicit begins are needed
for, e.g, iterative factorial */

Obj lambdaBody(Obj expr) { return CDDR(expr); }

Obj makeFunc(Obj params, Obj body, Obj env) {
    List* list = makeList(env, makeList(params, makeList(body, NULL)));

    return LISTOBJ(list);
}

/* ass, def */

bool isDef(Obj expr) { return hasForm(expr, DEF_KEY); }

bool isSugarDef(Obj expr) { return GETTAG(CADR(expr)) == LIST; }

Obj transformSugarDef(Obj expr) {
    Obj funcArgs = CADR(expr);
    Obj func = CAR(funcArgs);
    Obj args = CDR(funcArgs);
    Obj body = CDDR(expr);

    Obj lambdaExpr = CONS(LAMBDAOBJ, CONS(args, body));

    Obj transformed = CONS(DEFOBJ, CONS(func, CONS(lambdaExpr, NULLOBJ)));

    return transformed;
}

Obj defVar(Obj expr) { return CADR(expr); }

Obj defVal(Obj expr) { return CADDR(expr); }

bool isAss(Obj expr) { return hasForm(expr, ASS_KEY); }

Obj assVar(Obj expr) { return CADR(expr); }

Obj assVal(Obj expr) { return CADDR(expr); }

/* function */

Obj getFunc(Obj expr) { return CAR(expr); }

bool isSimple(Obj expr) { return isVar(expr) || isNum(expr); }

Obj getArgs(Obj expr) { return CDR(expr); }

bool noArgs(Obj expr) { return GETLIST(expr) == NULL; }

bool noCompoundArgs(Obj expr) {
    if (noArgs(expr))
        return true;
    else {
        List* list = GETLIST(expr);
        return isSimple(list->car) && noCompoundArgs(LISTOBJ(list->cdr));
    }
}

Obj firstArg(Obj expr) { return CAR(expr); }

bool isLastArg(Obj expr) { return GETLIST(expr)->cdr == NULL; }

/* adjoinArg walks down the whole length
of the arglist to append a value to the end.
This is less efficient than building the list
backwards and then reversing, but it makes
the info display easier to read. */

Obj adjoinArg(Obj val, Obj arglist) {
    List* args = GETLIST(arglist);

    if (!args) return LISTOBJ(makeList(val, args));

    List* pnr = args;
    while (pnr->cdr) pnr = pnr->cdr;

    pnr->cdr = malloc(sizeof(List));
    pnr = pnr->cdr;
    pnr->car = val;
    pnr->cdr = NULL;

    return LISTOBJ(args);
}

Obj restArgs(Obj expr) { return CDR(expr); }

/* apply */

bool isPrimitive(Obj obj) {
    // isPrimitive_count++;
    return GETTAG(obj) == PRIM;
}

bool isCompound(Obj obj) {
    // isCompound_count++;
    return GETTAG(obj) == LIST;
}

bool isCompiled(Obj obj) {
    // isCompiled_count++;
    return GETTAG(obj) == COMP;
}

// make sure these coordinate with makeFunc

Obj funcParams(Obj obj) { return CADR(obj); }

Obj funcBody(Obj obj) { return CADDR(obj); }

Obj funcEnv(Obj obj) { return CAR(obj); }

/* sequence */

Obj firstExp(Obj seq) { return CAR(seq); }

Obj restExps(Obj seq) { return CDR(seq); }

bool isLastExp(Obj seq) {
    List* next = GETLIST(seq)->cdr;
    return next == NULL;
}

bool noExps(Obj seq) {
    List* list = GETLIST(seq);
    return list == NULL;
}

/* error-checking */

bool isError(Obj obj) { return GETTAG(obj) == ERROR; }
