#include <stdio.h>
#include "objects.h"

// void print_list(List* list);
// void print_obj(Obj obj);

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
			printf("%s\n", "FUNC");
			break;
		// these last few can occur in the stack
		case ENV:
			printf("%s\n", "ENV");
			break;
		case LABEL:
			printf("%s: %d\n", "LABEL", obj.val.label);
		case DUMMY:
		case tag_count:
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