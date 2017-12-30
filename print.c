#include "print.h"

/* evaluator info printing */

void print_info(char* main_label) {
    labels_passed_count++;
    if (!INFO || LIB) return;

    NL;
    printf("@ %s", main_label);
    NL;
    PRDIV;
    print_registers();
    print_stack();
    if (STEP) getchar();
    NL;

    return;
}

void print_final_val(void) {
    if (LIB) return;

    NL;
    printf("VALUE: ");
    print_obj(val);
    NL;
    NL;

    // is this step needed?
    if (STEP) getchar();

    return;
}

void print_registers(void) {
    print_register(expr, EXPR_NAME);
    print_register(val, VAL_NAME);
    print_register(cont, CONT_NAME);
    print_register(func, FUNC_NAME);
    print_register(arglist, ARGLIST_NAME);
    print_register(unev, UNEV_NAME);
    print_register(env, ENV_NAME);
}

void print_stack(void) {
    PRDIV;
    // printf("%s\n", "printing stack...");
    List* temp = stack;
    int count = 0;
    if (!temp) printf("%s\n", "-- EMPTY STACK --");
    while (temp) {
        printf("-- STACK ENTRY %d --", count);
        NL;
        print_obj(temp->car);
        NL;
        temp = temp->cdr;
        count++;
    }
    PRDIV;
}

void print_base_env(void) {
    if (!INFO || LIB) return;

    NL;
    NL;
    printf("base_env: %p", base_env);
    NL;
}

void print_unbound(void) {
    NL;
    NL;
    printf("UNBOUND VARIABLE: \"%s\"!", GETNAME(expr));
    NL;
}

/* info helpers */

void print_register(Obj reg, char* name) {
    printf("-- %s -- \n", name);
    print_obj(reg);
    NL;
}

void print_obj(Obj obj) {
    switch (GETTAG(obj)) {
        case NUM:
            printf("%ld ", GETNUM(obj));
            break;
        case NAME:
            printf("%s ", GETNAME(obj));
            break;
        case BOOL_:
            printf("%s ", GETBOOL(obj) == 0 ? "#f" : "#t");
            break;
        case LIST:
            printf("%s", "( ");
            print_list(GETLIST(obj));
            break;
        case PRIM:
            printf("%s ", obj.val.prim.name);
            break;
        case ENV:
            printf("%p ", GETENV(obj));
            break;
        case LABEL:
            print_label(GETLABEL(obj));
            break;
        case COMP:
            printf("COMPILED FUNCTION");
            break;
        case DUMMY:
            printf("%s ", "DUMMY");
            break;
        case ERROR:
            printf("%s\n", "ERROR!!!");
            break;
        case UNINIT:
            printf("%s ", "***");
            break;
        case tag_count:
            printf("%s ", "tag_count...huh?");
            break;
    }
    return;
}

void print_list(List* list) {
    if (list == NULL) {
        printf("%s", ") ");
        return;
    }
    print_obj(list->car);
    print_list(list->cdr);
}

void print_label(Label label) {
    switch (label) {
        case _DONE:
            printf("DONE ");
            break;
        case _IF_DECIDE:
            printf("IF_DECIDE ");
            break;
        case _DID_ASS_VAL:
            printf("DID_ASS_VAL ");
            break;
        case _DID_DEF_VAL:
            printf("DID_DEF_VAL ");
            break;
        case _DID_FUNC:
            printf("DID_FUNC ");
            break;
        case _ACC_ARG:
            printf("ACC_ARG ");
            break;
        case _DID_SIMPLE_ARG:
            printf("DID_SIMPLE_ARG ");
            break;
        case _REST_SIMPLE_ARGS:
            printf("REST_SIMPLE_ARGS ");
            break;
        case _DID_LAST_ARG:
            printf("DID_LAST_ARG ");
            break;
        case _SEQ_CONT:
            printf("SEQ_CONT ");
            break;
        case _ALT_SEQ_CONT:
            printf("ALT_SEQ_CONT ");
            break;
        default:
            printf("UNKNOWN LABEL ");
    }
}

/* user interface printing */

/* we could use macros to make these more concise,
but this way the code has a wysiwyg feel */

void print_intro(void) {
    NL;
    printf("Welcome to lispinc!");
    NL;
    NL;
    printf("Nick Drozd, 2016");
    NL;
    printf("github.com/nickdrozd/lispinc");
    NL;
    NL;
    printf("Enter .help for help and enter .quit to quit.");
    NL;
    NL;
    printf("Now, the time has come for you to lispinc...for your life!");
    NL;
    NL;
}

void print_help(void) {
    NL;
    printf("*** HELP ***");
    NL;
    TAB;
    printf("-- enter .info to toggle evaluator info mode");
    NL;
    TAB;
    printf(
        "-- enter .step to toggle step mode (pauses between each step of the "
        "evaluator in info mode)");
    NL;
    TAB;
    printf("-- enter .stats to toggle stack stats mode");
    NL;
    TAB;
    printf(
        "-- enter .tail to toggle tail recursion mode (turning this off is "
        "really only of any interest in conjunction with stats mode)");
    NL;
    TAB;
    printf("-- enter .debug to toggle debug mode");
    NL;
    TAB;
    printf("-- enter .quit to quit");
    NL;
    TAB;
    printf("-- enter .repl to turn off info, stats, and step modes");
    NL;
    TAB;
    printf("-- enter .demo to turn on info, stats, and step modes");
    NL;
    NL;
}

void print_flags(void) {
    if (!INFO) return;

    NL;
    printf("*** FLAGS ***");
    NL;
    print_flag(INFO, INFO_NAME);
    print_flag(STEP, STEP_NAME);
    print_flag(STATS, STATS_NAME);
    print_flag(TAIL, TAIL_NAME);
    print_flag(DEBUG, DEBUG_NAME);
}

void print_exit(void) {
    NL;
    printf("exiting lispinc...");
    NL;
    NL;
    printf("Byeeeeee!");
    NL;
    NL;
}

void print_flag(int flag, char* name) {
    TAB;
    printf("%s  :%s", name, flag ? "ON" : "OFF");
    NL;
}

/* debugging */

void debug_print(char* statement) {
    if (DEBUG) {
        NL;
        NL;
        printf("DEBUG: %s", statement);
        NL;
        NL;
    }
}

// is there a better way to include the register name?
void debug_register(Obj reg, char* name) {
    if (DEBUG) {
        NL;
        printf("DEBUG -- register: %s", name);
        NL;
        print_obj(reg);
        NL;
        NL;
    }
}
