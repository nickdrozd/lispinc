#ifndef PRIMITIVES_GUARD
#define PRIMITIVES_GUARD

#include <stdlib.h>

#include "objects.h"

List* primitive_vars(void);
List* primitive_vals(void);

/* primitive arithmetic functions */

#define PRIM_NULL "null?"

#define PRIM_ADD "+"
#define PRIM_SUB "-"
#define PRIM_MUL "*"
#define PRIM_DIV "/"
#define PRIM_EQ "=" 

#endif