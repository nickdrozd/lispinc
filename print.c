#include <stdio.h>
#include "objects.h"

// registers.c
void print_registers(void);

// stack.c
void print_stack(void);

int start = 1;

void print_info(void) {
	if (start) {
		start = 0;
		return;
	}

	print_registers();
	print_stack();
}

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
			printf("%s: %d\n", "LABEL", obj.val.label);
			// add print_label
			break;
		case DUMMY:
			printf("%s\n", "DUMMY");
			break;
		case UNINITIALIZED:
			printf("%s\n", "UNINITIALIZED");
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