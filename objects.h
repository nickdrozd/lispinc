/* typedefs */
typedef union Val Val;
typedef struct Obj Obj;
typedef struct List List;

typedef struct Frame Frame;
typedef struct Env Env;
typedef int (*intFunc)(int, int); // ???

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
	type_count
} Tag;

union Val {
	int num;
	char* name;
	List* list;
	intFunc func;
	Env* env;
	Label label;
	int dummy;
	// new function type?
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