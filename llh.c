/*
	TODO:
		-- figure out isTrue
*/

// low-level helper functions

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "objects.h"

// extern int DEBUG;

// bool isQuit(Obj expr) {
// 	return expr.tag == NAME &&
// 		strcmp(expr.val.name, "quit") == 1;
// }

bool isNum(Obj expr) {
	return expr.tag == NUM;
}

bool isVar(Obj expr) {
	return expr.tag == NAME;
}

/* special forms */

char* specialForm(Obj expr) {
	return expr.val.list->car.val.name;
}

bool cmpForm(char* cand, char* form) {
	return strcmp(cand, form) == 0;
}

bool hasForm(Obj expr, char* form) {
	return cmpForm(specialForm(expr), form);
}

/* quotation */

bool isQuote(Obj expr) {
	return hasForm(expr, "quote");
}

Obj quotedText(Obj expr) {
	return MKOBJ(LIST, list, expr.val.list->cdr);
}

/* begin */

bool isBegin(Obj expr) {
	return hasForm(expr, "begin");
}

Obj beginActions(Obj expr) {
	return MKOBJ(LIST, list, expr.val.list->cdr);
}

/* if (and other boolean macros) */

bool isIf(Obj expr) {
	return hasForm(expr, "if");
}

Obj ifTest(Obj expr) {
	return expr.val.list->cdr->car;
}

// is this right?
bool isTrue(Obj expr) {
	return expr.val.num != false;
}

Obj ifThen(Obj expr) {
	return expr.val.list->cdr->cdr->car;
}

Obj ifElse(Obj expr) {
	return expr.val.list->cdr->cdr->cdr->car;
}

/* lambda */

bool isLambda(Obj expr) {
	return hasForm(expr, "lambda");
}

Obj lambdaParams(Obj expr) {
	return expr.val.list->cdr->car;
}

Obj lambdaBody(Obj expr) {
	return expr.val.list->cdr->cdr->car;
}

Obj makeFunc(Obj params, Obj body, Obj env) {
	List* list = 
		makeList(MKOBJ(NAME, name, "lambda"),
			makeList(params,
				makeList(body,
					makeList(env, NULL))));

	Obj obj = MKOBJ(LIST, list, list);
	return obj;
}

/* ass, def */

bool isAss(Obj expr) {
	return hasForm(expr, "set!");
}

Obj assVar(Obj expr) {
	return expr.val.list->cdr->car;
}

Obj assVal(Obj expr) {
	return expr.val.list->cdr->cdr->car;
}

// -- setVar in env.c

bool isDef(Obj expr) {
	return hasForm(expr, "def");
}

Obj defVar(Obj expr) {
	return expr.val.list->cdr->car;
}

Obj defVal(Obj expr) {
	return expr.val.list->cdr->cdr->car;
}

// -- defineVar in env.c

/* function */

Obj getArgs(Obj expr) {
	return MKOBJ(LIST, list, expr.val.list->cdr);
}

Obj getFunc(Obj expr) {
	return expr.val.list->car;
}

// -- empty_arglist macro

bool noArgs(Obj expr) {
	return expr.val.list == NULL;
}

Obj firstArg(Obj expr) {
	return expr.val.list->car;
}

bool isLastArg(Obj expr) {
	return expr.val.list->cdr == NULL;
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
	List* args = arglist.val.list;
	List* head = malloc(sizeof(List));
	head->car = val;
	head->cdr = args;
	head = reverse(head);
	return MKOBJ(LIST, list, head);
}

Obj restArgs(Obj expr) {
	return MKOBJ(LIST, list, expr.val.list->cdr);
}

/* apply */

bool isPrimitive(Obj obj) {
	return obj.tag == FUNC;
}

bool isCompound(Obj obj) {
	return obj.tag == LIST;
}

Obj applyPrimitive(Obj func, Obj arglist) {
			if (INFO) printf("%s\n", "applying PRIMITIVE...");
			if (DEBUG) debug_register(arglist, "arglist");
	List* list = arglist.val.list;
	int arg1 = list->car.val.num;
	int arg2 = list->cdr->car.val.num;
			if (INFO) printf("arg1: %d\narg2: %d\n", arg1, arg2);
	intFunc prim = func.val.func;
	int result = (*prim)(arg1, arg2);
	return MKOBJ(NUM, num, result);
}

Obj funcParams(Obj obj) {
	return obj.val.list->car;
}

Obj funcBody(Obj obj) {
	return obj.val.list->cdr->car;
}

Obj funcEnv(Obj obj) {
	return obj.val.list->cdr->cdr->car;
}

// extendEnv in env.c

/* sequence */

Obj firstExp(Obj seq) {
	return seq.val.list->car;
}

Obj restExps(Obj seq) {
	return MKOBJ(LIST, list, seq.val.list->cdr);
}

bool isLastExp(Obj seq) {
	return (restExps(seq)).val.list == NULL;
}

bool noExps(Obj seq) {
	return seq.val.list == NULL;
}


/* 
	for posterity: failed attempts at adjoinArg
	
	three version (one with a helper)
 */

// version 1

// Obj adjoinArg(Obj val, Obj arglist) {
// 	if (DEBUG) printf("%s\n", "adjoining args...");
// 	List* list = arglist.val.list;
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
	
// 	List* list = arglist.val.list;
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
