/*
	FLAGS

	Flags are used to indicate certain system settings. 
	DEBUG, INFO, STATS, TAIL, and STEP are user-set, 
	while LIB is used in the process of loading the 
	library functions. 
*/

#ifndef FLAGS_GUARD
#define FLAGS_GUARD

#include <stdio.h>
#include <stdbool.h>

#include "keywords.h"

extern int DEBUG;
extern int INFO;
extern int STATS;
extern int TAIL;
extern int STEP;

/* LIB keeps print functions from printing during
library loading (see print.c) */
extern int LIB;

/* flag names */

#define DEBUG_NAME "DEBUG"
#define INFO_NAME "INFO"
#define STATS_NAME "STATS"
#define TAIL_NAME "TAIL"
#define STEP_NAME "STEP"

/* flag manipulation */
void switch_flag(char* flag_command);
void toggle_val(int* flag);
void repl_switch(void);
void demo_switch(void);

/* LIB has its own dedicated toggle function 
to make read.c more readable */
void toggle_LIB(void);

/* from read.c (redundant declaration?) */
int streq(char* str1, char* str2);

#endif