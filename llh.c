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
	at the end of the file
*/

/*
	TODO:
		-- figure out isTrue
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
		
#include "objects.h"
#include "keywords.h"
#include "flags.h"
#include "llh.h"

/* input */

/* isQuit can't be defined in read.c because it affects
	how the evaluator itself runs, whereas the other 
	user commands (e.g. flag toggling) are executed 
	just by the read function. */

bool isQuit(Obj expr) {
	return GETTAG(expr) == NAME &&
		cmpForm(GETNAME(expr), QUIT);
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
	// return GETLIST(expr)->car.val.name;
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

/* if (and other boolean macros) */

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

/* lambda */

bool isLambda(Obj expr) {
	return hasForm(expr, FUN_KEY);
}

Obj lambdaParams(Obj expr) {
	return CADR(GETLIST(expr));
}

/* to allow for implicit begin blocks, change this
and some other functions to provide for a list of
body expressions; otherwise, explicit begins are needed
for, e.g, iterative factorial */

Obj lambdaBody(Obj expr) {
	return CADDR(GETLIST(expr));
}

Obj makeFunc(Obj params, Obj body, Obj env) {
	List* list = 
		makeList(NAMEOBJ("lambda"),
			makeList(params,
				makeList(body,
					makeList(env, NULL))));

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

/* function */

Obj getArgs(Obj expr) {
	return LISTOBJ(CDR(GETLIST(expr)));
}

Obj getFunc(Obj expr) {
	return CAR(GETLIST(expr));
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

/* adjoinArg (with its own helpers) */

void appendObj(Obj obj, List** list) {
	if (*list == NULL) {
		*list = malloc(sizeof(List));
		(*list)->car = obj;
		(*list)->cdr = NULL;
		return;
	}
	else appendObj(obj, &((*list)->cdr));
}

List* reverse(List* list) {
	if (list == NULL)
		return NULL;

	Obj car = list->car;
	List* cdr = list->cdr;
	List* head = reverse(cdr);
	appendObj(car, &head);
	return head;
}

/*
	adjoinArg conses val to the front of
	arglist, then reverses the whole thing.
	this isn't efficient, but it was
	shockingly and insurmountably difficult
	to do it more straighforwardly.
*/

Obj adjoinArg(Obj val, Obj arglist) {
	List* args = GETLIST(arglist);
	List* head = malloc(sizeof(List));
	head->car = val;
	head->cdr = args;
	head = reverse(head);
	return LISTOBJ(head);
}

Obj restArgs(Obj expr) {
	return LISTOBJ(CDR(GETLIST(expr)));
}

/* apply */

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

bool isPrimitive(Obj obj) {
	return GETTAG(obj) == PRIM;
}

bool isCompound(Obj obj) {
	return GETTAG(obj) == LIST;
}

Obj applyPrimitive(Obj func, Obj arglist) {
			if (INFO) printf("%s\n", "applying PRIMITIVE...");
	List* list = GETLIST(arglist);

	primType type = func.val.prim.type;

	if (type == INTPRIM) {
		int arg1 = list->car.val.num;
		int arg2 = list->cdr->car.val.num;
				if (INFO) printf("arg1: %d\narg2: %d\n\n", arg1, arg2);
		intFunc prim = func.val.prim.func.intfunc;
		int result = (*prim)(arg1, arg2);
		return NUMOBJ(result);
	}
	
	else if (type == OBJPRIM) {
		Obj arg = list->car;
				if (INFO) ;
		objFunc prim = func.val.prim.func.objfunc;
		int result = (*prim)(arg);
		return NUMOBJ(result);
	}

	else {
		printf("apply_primitive: unknown primitive function type!\n");
		return DUMMYOBJ;
	}
}

// make sure these coordinate with makeFunc

Obj funcParams(Obj obj) {
	return CADR(GETLIST(obj));
}

Obj funcBody(Obj obj) {
	return LISTOBJ(CDDR(GETLIST(obj)));
}

Obj funcEnv(Obj obj) {
	return CADDDR(GETLIST(obj));
}

// extendEnv in env.c

/* sequence */

Obj firstExp(Obj seq) {
	return CAR(GETLIST(seq));
}

Obj restExps(Obj seq) {
	// return MKOBJ(LIST, list, CDR(GETLIST(seq)));
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


/* 
	for posterity: failed attempts at adjoinArg
	
	three version (one with a helper)
 */

// version 1

// Obj adjoinArg(Obj val, Obj arglist) {
// 	if (DEBUG) printf("%s\n", "adjoining args...");
// 	List* list = GETLIST(arglist);
// 	List* temp = list;
// 	while (list) {
// 		print_list(list);
// 		print_list(temp);
// 		list = list->cdr;
// 	}
// 	list = malloc(sizeof(List));
// 	list->car = val;
// 	list->cdr = NULL;
// 	if (DEBUG) print_list(list);
// 	return MKOBJ(LIST, list, temp);
// }

/***/

// version 2

// List* appendObj(Obj obj, List* list) {
// 	List* result = list;
// 	while (list != NULL)
// 		list = list->cdr;
// 	list = malloc(sizeof(List));
// 	list->car = obj;
// 	list->cdr = NULL;
// 	return result;
// }

// Obj adjoinArg(Obj arg, Obj argl) {
// 	List* args = argl.val.list;
// 	List* result = appendObj(arg, args);
// 	Obj resobj = { .tag = LIST,
// 					.val = { .list = result }};
// 	return resobj;
// }

/***/

// version 3

// Obj adjoinArg(Obj val, Obj arglist) {
// 	if (DEBUG) printf("%s\n", "adjoining args...");
	
// 	List* list = GETLIST(arglist);
// 	List* head = NULL;
// 	List* tail = NULL;
	
// 	if (list) {
// 		print_list(list);
// 		print_list(list->cdr);
// 		tail = malloc(sizeof(List));
// 		tail->car = list->car;
// 		tail->cdr = NULL;
// 		head = tail;
// 		print_list(tail);
// 		print_list(head);
// 		list = list->cdr;
// 		while (list) {
// 			print_list(list);
// 			print_list(tail);
// 			print_list(head);
// 			tail->cdr = malloc(sizeof(List));
// 			tail = tail->cdr;
// 			tail->car = list->car;
// 			tail->cdr = NULL;
// 			list = list->cdr;
// 		}
// 		tail = malloc(sizeof(List));
// 		tail->car = val;
// 		tail->cdr = NULL;
// 		// return MKOBJ(LIST, list, head);
// 	}
	
// 	else {
// 		head = malloc(sizeof(List));
// 		head->car = val;
// 		head->cdr = NULL;
// 		// return MKOBJ(LIST, list, head);
// 	}

// 	printf("\n");
// 	print_list(head);
// 	printf("\n");
// 	return MKOBJ(LIST, list, head);
// }

/***/

