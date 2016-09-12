#include "tally.h"

/* stack stats */

int save_count = 0;
int curr_stack_depth = 0;
int max_stack_depth = 0;

/* env stats */

int lookup_count = 0;
int envs_traversed = 0;
int frames_traversed = 0;

/* llh stats */

int form_check_count = 0;
// int isPrimitive_count = 0;
// int isCompound_count = 0;

/* stat functions */

void print_stats(void) {
	if (LIB) return;

	printf("*** STATS ***");NL;

	printf("Total number of saves: %d", save_count);NL;
	printf("Maximum stack depth: %d", max_stack_depth);NL;

	printf("Total number of lookups: %d", lookup_count);NL;
	printf("Total envs traversed: %d", envs_traversed);NL;
	printf("Total frames traversed: %d", frames_traversed);NL;

	printf("Total times special forms checked: %d", form_check_count);NL;
	// printf("Total times isPrimitive called: %d", isPrimitive_count);NL;
	// printf("Total times isCompound called: %d", isCompound_count);NL;

	reset_stats();
}

void reset_stats(void) {
	save_count = 0;
	curr_stack_depth = 0;
	max_stack_depth = 0;

	lookup_count = 0;
	envs_traversed = 0;
	frames_traversed = 0;

	form_check_count = 0;
	// isPrimitive_count = 0;
	// isCompound_count = 0;
}