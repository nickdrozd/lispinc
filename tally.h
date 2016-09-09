#ifndef EC_MAIN_GUARD
#define EC_MAIN_GUARD

void reset_stats(void);

extern int save_count;
extern int curr_stack_depth;
extern int max_stack_depth;

extern int lookup_count;
extern int envs_traversed;
extern int frames_traversed;

#endif