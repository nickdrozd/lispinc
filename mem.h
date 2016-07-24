/* lists */

typedef struct List_list List_list;

struct List_list {
	List* list;
	List_list* next;
};

void free_lists(void);
void free_list(List** list);
void append_to_lists(List* list);

/* envs */

typedef struct Env_list Env_list;

struct Env_list {
	Env* env;
	Env_list* next;
};

void free_envs(void);
void free_env(Env** env);
void free_frame(Frame** frame);
void append_to_envs(Env* env);

/* tokens freed in parse.c */