/*
    PRINT

    Some of these print functions have to do with displaying
    information about the evaluator itself, and some print program
    information and greetings and that kind of things. A few are used
    specifically for debugging (they only do anything if the DEBUG
    flag is set).
*/

/*
    TODO:
        -- figure out how to mark envs
            so that printing them is informative
*/

#ifndef PRINT_GUARD
#define PRINT_GUARD

#include <stdio.h>

#include "env.h"
#include "flags.h"
#include "keywords.h"
#include "objects.h"
#include "registers.h"
#include "stack.h"
#include "tally.h"

#define NL_PRINT(...)                                                          \
    printf(__VA_ARGS__);                                                       \
    NL;

#define TABNL_PRINT(...)                                                       \
    TAB;                                                                       \
    printf(__VA_ARGS__);                                                       \
    NL;

#define NL printf("\n");
#define TAB printf("\t");
#define PRDIV printf("--------------------\n");

/* evaluator info printing */

void print_info(char* main_label);
void print_final_val(void);
void print_stats(void);

void print_stack(void);
void print_registers(void);

void print_base_env(void);
void print_unbound(void);

void print_register(Obj reg, char* name);
void print_label(Label label);

void print_obj(Obj obj);
void print_list(List* list);

/* user interface */

void print_intro(void);
void print_help(void);
void print_flags(void);
void print_exit(void);

void print_flag(int flag, char* name);

/* debugging */

void debug_print(char* statement);
void debug_register(Obj reg, char* name);

#endif
