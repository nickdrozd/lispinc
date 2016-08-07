#include "print.h"

/* evaluator info printing */

char* main_label;

void print_info(void) {
	NL;NL;
	printf("@ %s", main_label);NL;
	PRDIV;
	print_registers();
	print_stack();
	if (STEP)
		getchar();
}

void print_stats(void) {
	if (LIB) return;

	printf("*** STATS ***\n");
	printf("Total number of saves: %d", save_count);NL;
	printf("Maximum stack depth: %d", max_stack_depth);NL;
	reset_stats();
}

void print_final_val(void) {
	if (LIB) return;
	
	printf("\nVALUE: ");
	print_obj(val);
	NL;NL;

	if (!STATS)
		reset_stats();
	
	if (STEP)
		getchar();
}

void print_registers(void) {
	print_register(expr, "EXPR");
	print_register(val, "VAL");
	print_register(cont, "CONT");
	print_register(func, "FUNC");
	print_register(arglist, "ARGLIST");
	print_register(unev, "UNEV");
	print_register(env, "ENV");
}

void print_stack(void) {
	PRDIV;
	// printf("%s\n", "printing stack...");
	List* temp = stack;
	int count = 0;
	if (!temp)
		printf("%s\n", "-- EMPTY STACK --");
	while (temp) {
		printf("-- STACK ENTRY %d --", count);NL;
		print_obj(temp->car); NL;
		temp = temp->cdr;
		count++;
	}
	PRDIV;
}

void print_base_env(void) {
	NL;NL;
	printf("base_env: %p", base_env);
	NL;
}

void print_unbound(void) {
	NL;NL;
	printf("UNBOUND VARIABLE: \"%s\"!", 
							GETNAME(expr));
	NL;
}

/* info helpers */

void print_register(Obj reg, char* name) {
	printf("-- %s -- \n", name);
	print_obj(reg); NL;
}

void print_obj(Obj obj) {
	switch(GETTAG(obj)) {
		case NUM:
			printf("%d ", GETNUM(obj));
			break;
		case NAME:
			printf("%s ", GETNAME(obj));
			break;
		case LIST:
			printf("%s", "( ");
			print_list(GETLIST(obj));
			break;
		case PRIM:
			printf("__%s__ ", 
				lookup_prim_name(obj));
			break;
		case ENV:
			printf("%p ", GETENV(obj));
			break;
		case LABEL:
			print_label(GETLABEL(obj));
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

// TODO: clean this up!
// (it used to look nice!)
char* lookup_prim_name(Obj func_obj) {
	// dispatch on primitive function type
	primType type = func_obj.val.prim.type;

	intFunc lookup_intfunc;
	intFunc val_intfunc;

	objFunc lookup_objfunc;
	objFunc val_objfunc;

	primType val_type;

	if (type == INTPRIM) 
		lookup_intfunc = func_obj.val.prim.func.intfunc;

	else if (type == OBJPRIM) 
		lookup_objfunc = func_obj.val.prim.func.objfunc;

	Frame* frame = base_env->frame;
	Obj val;
	char* key;

	while (frame) {

		val = frame->val;

		if (val.tag == PRIM) {
			val_type = val.val.prim.type;

			if (val_type == INTPRIM) {
				val_intfunc = val.val.prim.func.intfunc;
				key = frame->key;
				if (lookup_intfunc == val_intfunc)
					return key;
			}

			else if (val_type == OBJPRIM) {
				val_objfunc = val.val.prim.func.objfunc;
				key = frame->key;
				if (lookup_objfunc == val_objfunc)
					return key;
			}

			// val_func = val.val.prim;
			// if (lookup_func == val_func)
				// return key;
		}

		frame = frame->next;
	}

	return "unknown primitive function...";
}


/* user interface printing */

void print_intro(void) {
	NL;
	printf("Welcome to lispinc!"); 
	NL;NL;
	printf("Nick Drozd, 2016"); 
	NL;
	printf("github.com/nickdrozd/lispinc"); 
	NL;NL;
	printf("Enter .help for help and enter .quit to quit."); 
	NL;NL;
	printf("Now, the time has come for you to lispinc...for your life!"); 
	NL;NL;
}

void print_help(void) {
	NL;
	printf("*** HELP ***");NL;
	TAB;printf("-- enter .info to toggle evaluator info mode");NL;
	TAB;printf("-- enter .step to toggle step mode (pauses between each step of the evaluator in info mode)");NL;
	TAB;printf("-- enter .stats to toggle stack stats mode");NL;
	TAB;printf("-- enter .tail to toggle tail recursion mode (turning this off is really only of any interest in conjunction with stats mode)");NL;
	TAB;printf("-- enter .debug to toggle debug mode");NL;
	TAB;printf("-- enter .quit to quit");NL;NL;
}

void print_flags(void) {
	NL;
	printf("*** FLAGS ***");NL;
	print_flag(INFO, "INFO");
	print_flag(STEP, "STEP");
	print_flag(STATS, "STATS");
	print_flag(TAIL, "TAIL");
	print_flag(DEBUG, "DEBUG");
}

void print_exit(void) {
	NL; 
	printf("exiting lispinc..."); 
	NL; NL;
	printf("Byeeeeee!");
	NL; NL;
}

void print_flag(int flag, char* name) {
	TAB;printf("%s  :%s", name, flag ? "ON" : "OFF");NL;
}


/* debugging */

void debug_print(char* statement) {
	if (DEBUG) { 
		NL;NL;
		printf("DEBUG: %s", statement);
		NL;NL;
	}
}