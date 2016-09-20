/*
	KEYWORDS

	keywords.h contains settings for Lisp syntax and 
	reserved words and user commands.

	Lisp has almost no syntax, so "syntax" here means 
	delineators, parenthesis-like characters and 
	space-like characters. If, for instance, you wanted 
	to change lispinc to include angle brackets as 
	delineators (so that <+ 4 5> and (+ 4 5) would be 
	equivalent), this is the place to do it.

	Reserved words are the "special" words that are not 
	interpreted as normal functions (define, lambda, 
	etc). If you want to add a new "special form" to 
	lispinc (something like delay, for instace), this is 
	the place to do it.

	 Last, there are the user commands for doing things 
	 like switching flags. Note that due to an 
	 irregularity in the parsing process, any user 
	 command that gets executes outside of the main body 
	 of the interpreter must end in a newline character.
*/


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

#define SETCAR_KEY "set-car!"
#define SETCDR_KEY "set-cdr!"

#define IF_KEY "if"
#define AND_KEY "and"
#define OR_KEY "or"

#define DELAY_KEY "delay"

/* primitives */

#define ADD_NAME "_+_"
#define MUL_NAME "_*_"

#define TRUE_NAME "#t"
#define FALSE_NAME "#f"

/* user commands */

// commands run by read
// (it would be nice if these didn't need newlines)
#define nlchar "\n"

#define DEBUG_COMMAND ".debug"nlchar
#define INFO_COMMAND ".info"nlchar
#define STATS_COMMAND ".stats"nlchar
#define TAIL_COMMAND ".tail"nlchar
#define STEP_COMMAND ".step"nlchar
#define REPL_COMMAND ".repl"nlchar
#define DEMO_COMMAND ".demo"nlchar

#define HELP_COMMAND ".help"nlchar

// commands run by main

#define QUIT_COMMAND ".quit"

#endif