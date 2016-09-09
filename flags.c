#include "flags.h"

int DEBUG = 0;
int INFO = 1;
int STATS = 1;
int STEP = 0;
int TAIL = 1;

int LIB = 1;

/* flag manipulation */

// inelegant
void switch_flag(char* flag_command) {
			if (DEBUG) printf("%s\n", "switching flag...");
	if (streq(flag_command, DEBUG_COMMAND))
		toggle_val(&DEBUG);
	else if (streq(flag_command, INFO_COMMAND))
		toggle_val(&INFO);
	else if (streq(flag_command, STATS_COMMAND))
		toggle_val(&STATS);
	else if (streq(flag_command, TAIL_COMMAND))
		toggle_val(&TAIL);
	else if (streq(flag_command, STEP_COMMAND))
		toggle_val(&STEP);
	else if (streq(flag_command, REPL_COMMAND))
		repl_switch();
	else if (streq(flag_command, DEMO_COMMAND))
		demo_switch();
}

void toggle_LIB(void) {
	toggle_val(&LIB);
}

void toggle_val(int* flag) {
			if (DEBUG) printf("toggle_val: %d\n", *flag);
	*flag = 1 - *flag;
			// self-referential debugging statement?
			if (DEBUG) printf("toggled! %d\n", *flag);

	return;
}

void repl_switch(void) {
	INFO = 0;
	STATS = 0;
	STEP = 0;
}

void demo_switch(void) {
	INFO = 1;
	STATS = 1;
	STEP = 1;
}