Obj read_code(void);

/* input prompt */
void input_prompt(void);

void print_prompt(void);
void get_input(void);
bool isIrregular(char* code);

bool isEnter(char* code);
bool badSyntax(char* code);

bool parens_balanced(char* code);
bool open_paren(char c);
bool close_paren(char c);

/* check for user commands */
int isSpecial(char* code);
int isFlag(char* code);
int isHelp(char* code);
// int isQuit(char* code);

int streq(char* str1, char* str2);