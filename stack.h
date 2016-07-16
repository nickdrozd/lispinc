/* stack.c */
void save(Obj reg);
void restore(Obj* reg);
void clear_stack(void);
void initialize_stack(void);
void reset_stats(void);

extern int save_count;
extern int curr_stack_depth;
extern int max_stack_depth;

extern List* stack;