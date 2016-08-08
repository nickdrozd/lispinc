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

extern int LIB;

/* flag names */

#define DEBUG_NAME "DEBUG"
#define INFO_NAME "INFO"
#define STATS_NAME "STATS"
#define TAIL_NAME "TAIL"
#define STEP_NAME "STEP"

/* flag manipulation */
void toggle_val(int* flag);
void switch_flag(char* flag_command);

/* from read.c */
int streq(char* str1, char* str2);

#endif