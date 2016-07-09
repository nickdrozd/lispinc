/*
	PRINT

	Some print functions, mostly used for debugging.
	In general, the low-level print functions 
	print_obj and print_list shouldn't be called
	directly, debug_register being preferred.
*/

/*
	TODO:
		-- figure out how to mark envs
			so that printing them is useful
*/

#include <stdio.h>
		
#include "objects.h"
#include "print.h"
#include "registers.h"

#define NL printf("\n");
#define PRDIV printf("--------------------\n");

extern List* stack;
extern Env* base_env;

extern int save_count;
extern int max_stack_depth;

void print_registers(void);
void print_stack(void);

/***************************/

void print_info(void) {
	PRDIV;
	print_registers();
	print_stack();
}

void print_registers(void) {
	printf("-- %s -- \n", "EXPR");
	print_obj(expr); NL;
	printf("-- %s -- \n", "VAL");
	print_obj(val); NL;
	printf("-- %s -- \n", "CONT");
	print_obj(cont); NL;
	printf("-- %s -- \n", "FUNC");
	print_obj(func); NL;
	printf("-- %s -- \n", "ARGLIST");
	print_obj(arglist); NL;
	printf("-- %s -- \n", "UNEV");
	print_obj(unev); NL;
	// identify envs with their pointers
	printf("-- %s -- \n", "ENV");
	print_obj(env); NL;
}

void print_stack(void) {
	PRDIV;
	// printf("%s\n", "printing stack...");
	List* temp = stack;
	int count = 0;
	if (!temp)
		printf("%s\n", "-- EMPTY STACK --");
	while (temp) {
		printf("-- STACK ENTRY %d -- \n", count);
		print_obj(temp->car); NL;
		temp = temp->cdr;
		count++;
	}
	PRDIV;
}

void print_stats(void) {
	printf("*** STATS ***\n");
	printf("Total number of saves: %d\n", save_count);
	printf("Maximum stack depth: %d\n", max_stack_depth);
}

void print_final_val(void) {
	printf("\nVALUE: ");
	print_obj(val); NL; NL;
}

// is there a better way to include the register name?
void debug_register(Obj reg, char* name) {
	printf("\nDEBUG -- register: %s\n", name);
	print_obj(reg); NL; NL;
}

/* low-level printing */

void print_label(Label label);
char* lookup_func_name(Obj* func_obj);

void print_obj(Obj obj) {
	switch(obj.tag) {
		case NUM:
			printf("%d ", obj.val.num);
			break;
		case NAME:
			printf("%s ", obj.val.name);
			break;
		case LIST:
			printf("%s", "( ");
			print_list(obj.val.list);
			break;
		case FUNC:
			printf("__%s__ ", 
				lookup_func_name(&obj));
			break;
		case ENV:
			printf("%p ", obj.val.env);
			break;
		case LABEL:
			print_label(obj.val.label);
			break;
		case DUMMY:
			printf("%s ", "???");
			break;
		case UNINIT:
			printf("%s ", "***");
			break;
		case tag_count:
			printf("%s ", "huh?");
			break;
	}
	return;
}

void print_list(List* list) {
	if (list == NULL) {
		printf("%s", ") ");
		return;
	}
	print_obj(list->car);
	print_list(list->cdr);
}

void print_label(Label label) {
	switch(label) {
		case _DONE:
			printf("DONE ");
			break;
		case _IF_DECIDE:
			printf("IF_DECIDE ");
			break;
		case _DID_ASS_VAL:
			printf("DID_ASS_VAL ");
			break;
		case _DID_DEF_VAL:
			printf("DID_DEF_VAL ");
			break;
		case _DID_FUNC:
			printf("DID_FUNC ");
			break;
		case _ACC_ARG:
			printf("ACC_ARG ");
			break;
		case _DID_LAST_ARG:
			printf("DID_LAST_ARG ");
			break;
		case _SEQ_CONT:
			printf("SEQ_CONT ");
			break;
		case _ALT_SEQ_CONT:
			printf("ALT_SEQ_CONT ");
			break;
		default:
			printf("UNKNOWN LABEL ");
	}
}

char* lookup_func_name(Obj* func_obj) {
	intFunc lookup_func = (*func_obj).val.func;
	Frame* frame = base_env->frame;
	Obj val;
	intFunc val_func;
	char* key;
	while (frame) {
		val = frame->val;
		if (val.tag == FUNC) {
			val_func = val.val.func;
			key = frame->key;
			if (lookup_func == val_func)
				return key;
		}
		frame = frame->next;
	}

	return "unknown primitive function...";
}