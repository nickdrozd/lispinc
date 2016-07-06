/*
	DECLARATIONS

	These are all the functions used by ec_main.c
	but defined elsewhere. Ideally there should
	be as few of these as possible. For instance,
	read_code calls tokenize and parse, but main
	doesn't see either of those. Information
	hiding, separation of concerns, blah blah blah.
*/

/* parse.c */
Obj read_code(void);

/* print.c */
void print_info(void);
void print_stack(void);
void debug_register(Obj register, char* name);
void print_final_val(void);
void print_stats(void);

/* stack.c */
void save(Obj reg);
void restore(Obj* reg);
void clear_stack(void);

/* env.c */
Obj lookup(Obj var_obj, Obj env_obj);
void defineVar(Obj var_obj, Obj val_obj, Obj env_obj);
void setVar(Obj var_obj, Obj val_obj, Obj env_obj);
Obj extendEnv(Obj vars_obj, Obj vals_obj, Obj base_env_obj);
Env* makeBaseEnv(void);

/* llh.c */
//bool isQuit(Obj expr)
bool isNum(Obj expr);
bool isVar(Obj expr);
char* specialForm(Obj expr);
bool cmpForm(char* cand, char* form);
bool hasForm(Obj expr, char* form);
bool isQuote(Obj expr);
Obj quotedText(Obj expr);
bool isBegin(Obj expr);
Obj beginActions(Obj expr);
bool isIf(Obj expr);
Obj ifTest(Obj expr);
bool isTrue(Obj expr);
Obj ifThen(Obj expr);
Obj ifElse(Obj expr);
bool isLambda(Obj expr);
Obj lambdaParams(Obj expr);
Obj lambdaBody(Obj expr);
Obj makeFunc(Obj params, Obj body, Obj env);
bool isAss(Obj expr);
Obj assVar(Obj expr);
Obj assVal(Obj expr);
bool isDef(Obj expr);
Obj defVar(Obj expr);
Obj defVal(Obj expr);
Obj getArgs(Obj expr);
Obj getFunc(Obj expr);
bool noArgs(Obj expr);
Obj firstArg(Obj expr);
bool isLastArg(Obj expr);
Obj adjoinArg(Obj val, Obj arglist);
Obj restArgs(Obj expr);
bool isPrimitive(Obj obj);
bool isCompound(Obj obj);
Obj applyPrimitive(Obj func, Obj arglist);
Obj funcParams(Obj obj);
Obj funcBody(Obj obj);
Obj funcEnv(Obj obj);
Obj firstExp(Obj seq);
Obj restExps(Obj seq);
bool isLastExp(Obj seq);
bool noExps(Obj seq);