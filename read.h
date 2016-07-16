Obj read_code(void);

/* input prompt */
void input_prompt(void);
void print_prompt(void);
void get_input(void);

/* help */
void print_intro(void);
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