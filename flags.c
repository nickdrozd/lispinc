#include <stdio.h>

#include "objects.h"

int DEBUG = 1;
int REPL = 1;
int INFO = 0;
int STATS = 1;
int TAIL = 1;

void toggle_val(int* flag) {
			if (DEBUG) printf("toggle_val: %d\n", *flag);
	*flag = 1 - *flag;
			// self-referential debugging statement?
			if (DEBUG) printf("toggled! %d\n", *flag);

	return;
}

void switch_flag(char* flag_name) {
			if (DEBUG) printf("%s\n", "switching flag...");
	if (streq(flag_name, "DEBUG\n"))
		toggle_val(&DEBUG);
	else if (streq(flag_name, "REPL\n"))
		toggle_val(&REPL);
	else if (streq(flag_name, "INFO\n"))
		toggle_val(&INFO);
	else if (streq(flag_name, "STATS\n"))
		toggle_val(&STATS);
	else if (streq(flag_name, "TAIL\n"))
		toggle_val(&TAIL);
}

// void switch_flag(char* flag_name) {
// 	switch(flag_name) {
// 		case: "DEBUG"
// 			toggle_val(*DEBUG);
// 			break;
// 		case: "REPL"
// 			toggle_val(*REPL);
// 			break;
// 		case: "INFO"
// 			toggle_val(*INFO);
// 			break;
// 		case: "STATS"
// 			toggle_val(*STATS);
// 			break;
// 		case: "TAIL"
// 			toggle_val(*TAIL);
// 			break;	
// 	}
// }

