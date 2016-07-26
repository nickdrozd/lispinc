#define NL printf("\n");
#define PRDIV printf("--------------------\n");

/* evaluator info printing */

void print_info(void);
void print_final_val(void);
void print_stats(void);

void print_stack(void);
void print_registers(void);

void print_obj(Obj obj);
void print_list(List* list);
void print_label(Label label);
char* lookup_func_name(Obj* func_obj);

/* user interface */

void print_intro(void);
void print_lib(void);
void print_help(void);