Obj read_code(void);

/* input prompt */
void input_prompt(void);
void print_prompt(void);
void get_input(void);
bool badSyntax(char* code);
bool isEnter(char* code);
bool parens_balanced(char* code);
bool open_paren(char c);
bool close_paren(char c);

/* help */
void print_intro(void);
void print_lib(void);
void print_help(void);

/* check for user commands */
int isFlag(char* code);
int isHelp(char* code);
// int isQuit(char* code);
int isSpecial(char* code);
int streq(char* str1, char* str2);

/* flag manipulation */
void toggle_val(int* flag);
void switch_flag(char* flag_name);