#include <stdio.h>
#include "objects.h"

#define DASHES printf("--------------------\n");

extern Obj expr;
extern Obj val;
extern Obj env;
extern Obj cont;
extern Obj func;
extern Obj arglist;
extern Obj unev;
extern List* stack;

void print_registers(void);
void print_stack(void);

void print_info(void) {
	DASHES;
	print_registers();
	print_stack();
}

void print_registers(void) {
	printf("-- %s -- \n", "EXPR");
	print_obj(expr);
	printf("-- %s -- \n", "VAL");
	print_obj(val);
	printf("-- %s -- \n", "CONT");
	print_obj(cont);
	printf("-- %s -- \n", "FUNC");
	print_obj(func);
	printf("-- %s -- \n", "ARGLIST");
	print_obj(arglist);
	printf("-- %s -- \n", "UNEV");
	print_obj(unev);
	// printf("-- %s -- \n", "ENV");
	// print_obj(env);
}

void print_stack(void) {
	DASHES;
	// printf("%s\n", "printing stack...");
	List* temp = stack;
	int count = 0;
	if (!temp)
		printf("%s\n", "-- STACK EMPTY --");
	while (temp) {
		printf("-- STACK ENTRY %d -- \n", count);
		print_obj(temp->car);
		temp = temp->cdr;
		count++;
	}
	DASHES;
}

void print_label(Label label);

void print_obj(Obj obj) {
	switch(obj.tag) {
		case NUM:
			printf("%d\n", obj.val.num);
			break;
		case NAME:
			printf("%s\n", obj.val.name);
			break;
		case LIST:
			printf("%s\n", "LIST");
			print_list(obj.val.list);
			break;
		case FUNC:
			printf("%s\n", "func");
			break;
		case ENV:
			printf("%s\n", "env");
			break;
		case LABEL:
			print_label(obj.val.label);
			break;
		case DUMMY:
			printf("%s\n", "DUMMY");
			break;
		case UNINIT:
			printf("%s\n", "***");
			break;
		case tag_count:
			printf("%s\n", "huh?");
			break;
	}
	return;
}

void print_list(List* list) {
	if (list == NULL) {
		printf("%s\n", "END");
		return;
	}
	print_obj(list->car);
	print_list(list->cdr);
}

void print_label(Label label) {
	switch(label) {
		case _DONE:
			printf("DONE\n");
			break;
		case _IF_DECIDE:
			printf("IF_DECIDE\n");
			break;
		case _DID_ASS_VAL:
			printf("DID_ASS_VAL\n");
			break;
		case _DID_DEF_VAL:
			printf("DID_DEF_VAL\n");
			break;
		case _DID_FUNC:
			printf("DID_FUNC\n");
			break;
		case _ACC_ARG:
			printf("ADD_ARG\n");
			break;
		case _DID_LAST_ARG:
			printf("DID_LAST_ARG\n");
			break;
		case _SEQ_CONT:
			printf("SEQ_CONT\n");
			break;
		case _ALT_SEQ_CONT:
			printf("ALT_SEQ_CONT\n");
			break;
		default:
			printf("UNKNOWN LABEL\n");
	}
}