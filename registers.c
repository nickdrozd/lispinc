#include "registers.h"

Obj expr;
Obj val;
Obj cont;
Obj func;
Obj arglist;
Obj unev;
Obj env;

void initialize(void) {
    reset_stats();
    initialize_registers();
    initialize_stack();
    return;
}

void initialize_registers(void) {
    expr = UNINITOBJ;
    val = UNINITOBJ;
    cont = UNINITOBJ;
    func = UNINITOBJ;
    arglist = UNINITOBJ;
    unev = UNINITOBJ;
    env = UNINITOBJ;
    return;
}
