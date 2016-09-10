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

	There are several constructors. makeList mallocs
	a List cell and returns a pointer to it. NUMOBJ, 
	NAMEOBJ, and the rest are macros that expand to 
	different applications of another macro called 
	MKOBJ. MKOBJ in turn expands to an initialization 
	of an OBJ. Such an initialization is both hard to 
	read and annoying to type.

	The Env type is included here because it's part
	of Val, and the Frame type is included because
	it's part of Env. See env.c for details.
*/

/*
	TODO: 
		* describe Prim
		* describe Comp
*/

#ifndef OBJECTS_GUARD
#define OBJECTS_GUARD

// #include "keywords.h"

/* typedefs */

typedef union Val Val;
typedef struct Obj Obj;
typedef struct List List;

typedef struct Prim Prim;
typedef union primFunc primFunc;
typedef int (*intFunc)(int, int);
typedef int (*objFunc)(Obj);

typedef struct Comp Comp;

typedef struct Frame Frame;
typedef struct Env Env;

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

/* primitive functions */

typedef enum {
	INTPRIM,
	OBJPRIM,
	primType_count
} primType;

union primFunc {
	intFunc intfunc;
	objFunc objfunc;
};

struct Prim {
	primType type;
	primFunc func;
};

/* compiled functions */

struct Comp {
	Env* env;
	Label label;
};

/* objects */

typedef enum {
	NUM,
	NAME,
	LIST,
	ENV,
	LABEL,
	PRIM,
	COMP,
	DUMMY,
	UNINIT,
	tag_count
} Tag;

union Val {
	int num;
	char* name;
	List* list;
	Env* env;
	Label label;
	Prim prim;
	Comp comp;
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

/* frames and envs */

struct Frame {
	char* key;
	Obj val;
	Frame* next;
};

struct Env {
	Frame* frame;
	Env* enclosure;
};

/* constructors and selectors */

#define CAR(X) X->car
#define CDR(X) X->cdr
#define CADR(X) CAR(CDR(X))
#define CDDR(X) CDR(CDR(X))
#define CADDR(X) CAR(CDDR(X))
#define CDDDR(X) CDR(CDDR(X))
#define CADDDR(X) CAR(CDDDR(X))

/* nested macros have to listed reversed from their
	natural logical order */

/* selectors */

#define GETCOMPLAB(X) GETCOMP(X).label
#define GETCOMPENV(X) GETCOMP(X).env

#define GETTAG(X) X.tag
#define GETNUM(X) X.val.num
#define GETNAME(X) X.val.name
#define GETLIST(X) X.val.list
#define GETPRIM(X) X.val.prim
#define GETENV(X) X.val.env
#define GETLABEL(X) X.val.label
#define GETCOMP(X) X.val.comp

/* constructors */

// Prim

#define INTFUNC(X) MKPRIM(INTPRIM,intfunc, X)
#define OBJFUNC(X) MKPRIM(OBJPRIM, objfunc, X)

#define MKPRIM(TYPE,FUNCTYPE,FUNC) (Prim){.type = TYPE, .func = (primFunc){.FUNCTYPE = FUNC}}

// Comp

#define COMPENVOBJ(X) ENVOBJ(GETCOMPENV(X))
#define COMPLABOBJ(X) LABELOBJ(GETCOMPLAB(X))

	// takes envobj, not plain env
#define MKCOMP(LABEL,ENV) (Comp){.label = LABEL, .env = GETENV(ENV)}

// Obj

// keyword objs
#define QUOTEOBJ NAMEOBJ(QUOTE_KEY)
#define LAMBDAOBJ NAMEOBJ(LAMBDA_KEY)
#define DEFOBJ NAMEOBJ(DEF_KEY)
#define ASSOBJ NAMEOBJ(ASS_KEY)
#define IFOBJ NAMEOBJ(IF_KEY)
#define ANDOBJ NAMEOBJ(AND_KEY)
#define OROBJ NAMEOBJ(OR_KEY)

#define TRUEOBJ NUMOBJ(1)
#define FALSEOBJ NUMOBJ(0)
#define NULLOBJ LISTOBJ(NULL)

#define NUMOBJ(X) MKOBJ(NUM, num, X)
#define NAMEOBJ(X) MKOBJ(NAME, name, X)
#define LISTOBJ(X) MKOBJ(LIST, list, X)
#define PRIMOBJ(X) MKOBJ(PRIM, prim, X)
#define COMPOBJ(X) MKOBJ(COMP, comp, (X)) // parentheses needed?
#define ENVOBJ(X) MKOBJ(ENV, env, X)
#define LABELOBJ(X) MKOBJ(LABEL, label, X)
#define DUMMYOBJ MKOBJ(DUMMY, dummy, 0)
#define UNINITOBJ MKOBJ(UNINIT, uninit, 0)

#define MKOBJ(TAG,VALTYPE,VAL) (Obj){.tag = TAG, .val = (Val){.VALTYPE = VAL}}

// List (defined in env.c)
List* makeList(Obj car, List* cdr);


#endif
