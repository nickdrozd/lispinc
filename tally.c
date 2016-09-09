#include "tally.h"

/* stack stats */

int save_count = 0;
int curr_stack_depth = 0;
int max_stack_depth = 0;

/* env stats */

int lookup_count = 0;
int envs_traversed = 0;
int frames_traversed = 0;


void reset_stats(void) {
	save_count = 0;
	curr_stack_depth = 0;
	max_stack_depth = 0;

	lookup_count = 0;
	envs_traversed = 0;
	frames_traversed = 0;
}