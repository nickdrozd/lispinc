/*
	OBJECTS

	The explicit control evaluator uses just
	eight variables (seven to represent 
	registers and one to represent the stack).
	All (parsed) input, output, and intermediate
	states of all computations must fit into
	these variables. The challenge here is that
	C requires the types of all variables to be
	declared in advance. So what type should
	the eight variables be?

	The solution (or at least a solution) is to
	use a combination of structs and unions. Each
	of the seven register variables has the vaguely-
	named type 'Obj'. Obj is essentially a wrapper
	type that allows disparately-typed pieces of
	information to interact. An Obj consists of
	two parts: a 'val' that holds the Obj's 'real'
	value, and a 'tag' that says the type of the val.

	The val is a union type called 'Val' which
	provides for any possible type that the system
	can handle. It can contain: a num (int), a name 
	(char*), a List (a pointer to a linked list of 
	Objs), a func (a pointer to a two-valued int
	function), an env (a pointer to an Env, see 
	env.c), a Label (an enum type corresponding to
	the main function's goto labels), and two ints
	indicating that the Obj is uninitialized or a
	dummy (used for error checking). More types
	can be added as needed.

	The tag is an enum type (so really an int) that
	corresponds to the type of the val. It's used
	for dispatching for functions that need to know
	that, e.g. printf.

	The stack is of type List, a pointer to a 
	linked list of Objs. Objs can themselves contain
	such pointers and bear the LIST tag.

	There are two constructors. makeList mallocs
	a List cell and returns a pointer to it. MKOBJ
	isn't a function, but rather a preprocessor
	macro. Initializing an Obj is unpleasant because
	it requires nesting brackets, and MKOBJ is both
	easier to type and easier to read.

	//The Env type is included here because it's part
	//of Val, and the Frame type is included because
	//it's part of Env. See env.c for details.

	Besides all that, objects.h contains prototypes
	for print functions and debugging flags. These
	are unrelated to Obj, but since this file is
	universally included, it's convenient to put 
	them here. See print.c for definitions.
*/

#ifndef OBJECTS_GUARD
#define OBJECTS_GUARD

/* typedefs */
typedef union Val Val;
typedef struct Obj Obj;
typedef struct List List;

typedef struct Frame Frame;
typedef struct Env Env;
typedef int (*intFunc)(int, int);

/* there are more labels, 
but these are the ones that 
get saved and restored */
typedef enum {
	_DONE,
	_IF_DECIDE,
	_DID_ASS_VAL,
	_DID_DEF_VAL,
	_DID_FUNC,
	_ACC_ARG,
	_DID_LAST_ARG,
	_SEQ_CONT,
	_ALT_SEQ_CONT,
	label_count
} Label;

/* objects */

typedef enum {
	NUM,
	NAME,
	LIST,
	FUNC,
	ENV,
	LABEL,
	DUMMY,
	UNINIT,
	tag_count
} Tag;

union Val {
	int num;
	char* name;
	List* list;
	intFunc func;
	Env* env;
	Label label;
	int dummy;
	int uninit;
};

struct Obj {
	Tag	tag;
	Val val;
};

struct List {
	Obj car;
	List* cdr;
};

/* constructors */
#define MKOBJ(TAG,VALTYPE,VAL) (Obj){.tag = TAG, .val = (Val){.VALTYPE = VAL}}
List* makeList(Obj car, List* cdr);

/* debug / info mode */
extern int DEBUG;
extern int INFO;
extern int STATS;

/* print.c prototypes (for debugging) */
void debug_register(Obj reg, char* name);
// hopefully these can be isolated to print.c
void print_obj(Obj obj);
void print_list(List* list);

#endif