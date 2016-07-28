/*
	MEM

	mem.c handles memory management. In particular,
	it contains functions that free memory that has
	been allocated via malloc.

	Does any of this even work?
*/

#ifndef MEM_GUARD
#define MEM_GUARD

#include <stdio.h>
#include <stdlib.h>

#include "objects.h"
#include "flags.h"
#include "parse.h"

void free_memory(void);

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

#endif