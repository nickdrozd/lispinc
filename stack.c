#include "stack.h"

List* stack;

/* stack operations */

void save(Obj reg) {
    if (DEBUG) printf("%s\n", "save!");

    List* temp = stack;
    stack = malloc(sizeof(List));  // &stack?
    stack->car = reg;
    stack->cdr = temp;

    save_count++;
    curr_stack_depth++;
    max_stack_depth =
        curr_stack_depth > max_stack_depth ? curr_stack_depth : max_stack_depth;

    return;
}

/* use restore macro instead of _restore function to avoid having to
give the pointer address of the argument (see stack.h) */

/* #define restore(reg) _restore(&reg); */

void _restore(Obj* reg) {
    if (DEBUG) printf("%s\n", "restore!");

    *reg = stack->car;
    List* temp = stack;
    stack = stack->cdr;
    free(temp);

    curr_stack_depth--;
    return;
}

/* stack management */

#define empty_stack NULL

void clear_stack(void) {
    List* temp = stack;
    while (stack) {
        stack = stack->cdr;
        free(temp);
        temp = stack;
    }
    return;
}

void initialize_stack(void) {
    clear_stack();
    stack = empty_stack;
    return;
}
