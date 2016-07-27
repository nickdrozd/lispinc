/* syntax */

#define OPENPAREN(X)  X == '(' || X == '['  || X == '{'
#define CLOSEPAREN(X) X == ')' || X == ']'  || X == '}'
#define WHITESPACE(X) X == ' ' || X == '\n' || X == '\t'

/* reserved words */

#define QUOTE_KEY "quote"
#define IF_KEY "if"
#define FUN_KEY "lambda"
#define DEF_KEY "define"
#define ASS_KEY "set!"
#define BEGIN_KEY "begin"

/* non-flag user commands */

#define QUIT ".quit"
