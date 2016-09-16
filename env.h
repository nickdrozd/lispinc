/*
	ENV

	The evaluation environment is a lookup
	table wherein names (variables) are bound
	to values. The heart of Lisp is lambdas,
	and lambdas are evaluated by extending
	the enviroment with the lambdas variables
	bound to its arguments.

	Typewise, an Env is a struct containing 
	a pointer to another Env (its 'enclosing
	enviroment' or 'enclosure') and a pointer
	to a Frame. A Frame is a linked list of
	key / value pairs. For convenience, both
	keys and values are wrapped in the Obj
	type (see objects.h for definitions).

	[ add a diagram here? ]

	Functions

	makeBaseEnv returns a pointer to an
	enviroment with basic arithmetic operations
	defined. Other primitive functions can be
	added later.

	lookup takes two Objs as arguments, the
	first of type NAME and the second of type
	ENV. It looks up the name in the env and
	returns the bound value.

	defineVar and setVar each take three Objs as
	arguments, with the first of type NAME and 
	the third of type ENV (the second can be
	anything.) setVar sets the first occurence
	of the name in the env to the value (raising
	an error if the name is unbound), while
	defineVar adds a new name/value binding to 
	the topmost frame of the env (it doesn't check 
	to see if the name is already bound, but because 
	of the top-down lookup procedure this doesn't 
	create naming-collision problems).

	extendEnv takes two List Objs (the first being
	a List of NAME Objs) and an Env Obj and adds
	a returns a new Env Obj, the frame of which is
	the two Lists zipped together and the enclosure
	of which is the first Env.

	Note that these functions all take Objs as
	arguments: this is because they have to
	interface the registers of the evaluator,
	which are all of type Obj. In general, the
	functions in this file that operate on types
	other than Obj are 'private' functions, and
	the Obj-valued functions are 'public'.
*/

/*
	TODO:
		-- markings for distinct envs?
		-- clean up lookup_prim_name, it's ugly
*/

#ifndef ENV_GUARD
#define ENV_GUARD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "objects.h"
#include "flags.h"
#include "primitives.h"
#include "tally.h"
#include "mem.h"

/* env builders */

extern Env* base_env;

Env* makeBaseEnv(void);
Obj extendEnv(Obj vars_obj, Obj vals_obj, Obj base_env_obj);

/* lookup */

Obj lookup(Obj var_obj, Obj env_obj);

	Obj lookup_in_env(char* var, Env* env);
	Obj lookup_in_frame(char* var, Frame* frame);

/* modify env */

void defineVar(Obj var_obj, Obj val_obj, Obj env_obj);
void setVar(Obj var_obj, Obj val_obj, Obj env_obj);

/* constructors */

Frame* zipFrame(List* vars, List* vals);
Env* makeEnv(Frame* frame, Env* enclosure);

#endif



