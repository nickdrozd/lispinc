/*
    LIB

    These are the functions that are loaded into lispinc
    on startup. Many Lisp implementations include
    functions like cons, car, and cdr as primitives.
    An alternative approach is to define those functions
    in terms of lambda abstraction. While these lambda
    definitions tend to be opaque, this approach has
    has the advantages that 1) it's more theoretically
    elegant to avoid unneeded primitives and 2) it saves
    the trouble of having to deal primitive C functions
    any more than is necessary.

    read.c loops over the length of the library to load
    library functions, then switches to reading user
    input. Unfortunately, there is no way to check
    the length of the library array (or is there???),
    so the length of the library must be updated by
    hand. To make this easier, counters are included
    for sections of the library. These counters are
    all added together to get the length of the library.

    Remember: these counters must be updated manually!

    #defines are used instead of constants because
    apparently nothing can be initialized with anything
    except string literals and numbers.
*/

/*
    TODO: It turns out that list operations implemented
    as lambda abstractions don't play along with quote.
    Make them primitives!
*/

#ifndef LIB_GUARD
#define LIB_GUARD

#include <stdio.h>
#include <stdbool.h>

#include "keywords.h"
#include "flags.h"

char* load_library(void);
bool lib_loaded(void);

void print_lib(void);

#endif
