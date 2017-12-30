/*
    PARSE

    tokenize is a classic finite state automaton for "tokenizing"
    (i.e. determining the basic meaningful pieces of) the input code
    string. Because Lisp syntax is so brilliantly simple (only
    parentheses and whitespace are syntactically significant), the FSA
    has only two "states". It is implemented entirely with GOTOs, with
    no function calls at all!***

    *** Actually, it uses the C standard library, but still, it makes
    no calls to user-defined functions.

    tokenize generates a list of tokens which is then passed to parse.
    parse, in turn, generates a basic abstract syntax tree. again,
    because Lisp syntax is so simple, no further analysis is needed.
    parse generates a single Obj, which may itself contain a List of
    Objs (see objects.h for details).

    parse mixes iteration and recursion -- it walks down the token
    list and recurs when it finds a list. Is that what recursive
    descent is?
*/

/*
    TODO:
        -- figure out memory management
            -- free_tokens doesn't mix with library?
*/

#ifndef PARSE_GUARD
#define PARSE_GUARD

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flags.h"
#include "keywords.h"
#include "mem.h"
#include "objects.h"

/*
    Token and Token_list types, passed
    from tokenize to parse, and prototypes
*/

/* tokens */

typedef struct Token Token;
typedef struct Token_list Token_list;

typedef enum { OP, CP, SYM, tokenid_count } TokenID;

typedef enum { READY, SYMBOL, state_count } State;

struct Token {
    int start;
    int end;
    TokenID id;
    char* text;
};

struct Token_list {
    Token token;
    Token_list* next;
};

// prototypes
Obj parse(char* expr);
Token_list* tokenize(char* expr);
Obj read_tokens(Token_list* tokens);

void dock(Token_list** list);
Token_list* slice_ends(Token_list** list);
void push(Obj obj, List** list);

void print_tokens(Token_list* tokens);

void free_tokens(Token_list** list);

#endif
