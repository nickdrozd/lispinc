#ifndef KEYWORDS_GUARD
#define KEYWORDS_GUARD

/* syntax */

#define OPENPAREN(X)  X == '(' || X == '['  || X == '{'
#define CLOSEPAREN(X) X == ')' || X == ']'  || X == '}'
#define WHITESPACE(X) X == ' ' || X == '\n' || X == '\t'

/* reserved words */

#define FUN_KEY "lambda"

#define QUOTE_KEY "quote"
#define BEGIN_KEY "begin"

#define DEF_KEY "define"
#define ASS_KEY "set!"

#define IF_KEY "if"
#define AND_KEY "and"
#define OR_KEY "or"

#define DELAY_KEY "delay"

/* non-flag user commands */

#define QUIT_COMMAND ".quit"

#endif