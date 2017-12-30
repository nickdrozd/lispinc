#include "mem.h"

void free_memory(void) {
    if (DEBUG) printf("freeing memory...\n");

    free_lists();
    free_envs();
}

/* lists */

/* list of lists allocated */
List_list* lists_head;
List_list* lists_tail;

void free_lists(void) {
    if (DEBUG) printf("freeing lists...\n");

    if (lists_head == NULL) return;

    List_list* temp = lists_head;
    lists_head = lists_head->next;
    free_list(&(temp->list));
    free_lists();
}

void free_list(List** list) {
    if (*list == NULL) return;

    List* temp = *list;
    *list = (*list)->cdr;
    free(temp);
    temp = NULL;
    free_list(list);
}

void append_to_lists(List* list) {
    if (lists_tail) lists_tail = lists_tail->next;

    lists_tail = malloc(sizeof(List_list));
    lists_tail->list = list;
    lists_tail->next = NULL;

    if (!lists_head) lists_head = lists_tail;
}

/* envs */

/* list of envs established */
Env_list* envs_head;
Env_list* envs_tail;

void free_envs(void) {
    if (DEBUG) printf("freeing envs...\n");

    if (envs_head == NULL) return;

    Env_list* temp = envs_head;
    envs_head = envs_head->next;
    free_env(&(temp->env));
    free_envs();
}

void free_env(Env** env) {
    if (*env == NULL) return;

    Frame* temp = (*env)->frame;
    free(*env);
    *env = NULL;
    free_frame(&temp);
}

void free_frame(Frame** frame) {
    if (*frame == NULL) return;

    Frame* temp = (*frame)->next;
    free(*frame);
    *frame = NULL;
    free_frame(&temp);
}

void append_to_envs(Env* env) {
    if (envs_tail) envs_tail = envs_tail->next;

    envs_tail = malloc(sizeof(Env_list));
    envs_tail->env = env;
    envs_tail->next = NULL;

    if (!envs_head) envs_head = envs_tail;
}

/* tokens freed in parse.c */
