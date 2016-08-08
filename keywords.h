#ifndef KEYWORDS_GUARD
#define KEYWORDS_GUARD

/* syntax */

#define OPENPAREN(X)  X == '(' || X == '['  || X == '{'
#define CLOSEPAREN(X) X == ')' || X == ']'  || X == '}'
#define WHITESPACE(X) X == ' ' || X == '\n' || X == '\t'

/* reserved words */

#define LAMBDA_KEY "lambda"

#define QUOTE_KEY "quote"
#define BEGIN_KEY "begin"

#define DEF_KEY "define"
#define ASS_KEY "set!"

#define IF_KEY "if"
#define AND_KEY "and"
#define OR_KEY "or"

#define DELAY_KEY "delay"

/* user commands */

// commands run by read
// (it would be nice if these didn't need newlines)
#define nlchar "\n"

#define DEBUG_COMMAND ".debug"nlchar
#define INFO_COMMAND ".info"nlchar
#define STATS_COMMAND ".stats"nlchar
#define TAIL_COMMAND ".tail"nlchar
#define STEP_COMMAND ".step"nlchar

#define HELP_COMMAND ".help"nlchar

// commands run by main

#define QUIT_COMMAND ".quit"

#endif