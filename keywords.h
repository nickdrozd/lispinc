#ifndef KEYWORDS_GUARD
#define KEYWORDS_GUARD

/* syntax */

#define OPENPAREN(X)  X == '(' || X == '['  || X == '{'
#define CLOSEPAREN(X) X == ')' || X == ']'  || X == '}'
#define WHITESPACE(X) X == ' ' || X == '\n' || X == '\t'

/* reserved words */

#define DEF_KEY "define"
#define FUN_KEY "lambda"
#define IF_KEY "if"
#define QUOTE_KEY "quote"
#define ASS_KEY "set!"
#define BEGIN_KEY "begin"

/* non-flag user commands */

#define QUIT_COMMAND ".quit"

#endif