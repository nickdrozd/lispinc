/*
	TODO:
		-- copy_env function to prevent
			naming disputes
		-- markings for distinct envs
		-- contract env to go back to
			prior scope?
		-- separate lookup table for prim names
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objects.h"

extern int DEBUG;

// prototypes
Frame* makeFrame(List* vars, List* vals);
Env* makeEnv(Frame* frame, Env* enclosure);
Obj extendEnv(Obj vars_obj, Obj vals_obj, Obj base_env_obj);

Obj lookup_in_frame(char* var, Frame* frame);
Obj lookup_in_env(char* var, Env* env);
Obj lookup(Obj var_obj, Obj env_obj);

void defineVar(Obj var_obj, Obj val_obj, Obj env_obj);
void setVar(Obj var_obj, Obj val_obj, Obj env_obj);

Obj makeBaseEnv(void);

/* primitive functions */

int add_func(int a, int b) {
	return a + b;
}

int sub_func(int a, int b) {
	return a - b;
}

int mul_func(int a, int b) {
	return a * b;
}

int div_func(int a, int b) {
	return a / b; // floor division
}

intFunc add_ = add_func;
intFunc sub_ = sub_func;
intFunc mul_ = mul_func;
intFunc div_ = div_func;

/* base_env */

Obj makeBaseEnv(void) {
	List* function_vars = 
		makeList(MKOBJ(NAME, name, "add"), 
			makeList(MKOBJ(NAME, name, "sub"), 
				makeList(MKOBJ(NAME, name, "mul"), 
					makeList(MKOBJ(NAME, name, "div"), NULL))));

	List* function_vals = 
		makeList(MKOBJ(FUNC, func, add_), 
			makeList(MKOBJ(FUNC, func, sub_), 
				makeList(MKOBJ(FUNC, func, mul_), 
					makeList(MKOBJ(FUNC, func, div_), NULL))));

	Frame* primitives = makeFrame(function_vars, function_vals);

	Env* env = makeEnv(primitives, NULL);

	Obj env_obj = MKOBJ(ENV, env, env);

	return env_obj;
}

/* lookup in env */

Obj lookup(Obj var_obj, Obj env_obj) {
	if (DEBUG) printf("looking up \"%s\"\n", var_obj.val.name);
	char* var = var_obj.val.name;
	Env* env = env_obj.val.env;

	return lookup_in_env(var, env);
}

Obj lookup_in_env(char* var, Env* env) { // lookup in env
	if (DEBUG) printf("%s\n", "looking up in env...");
	if (env == NULL) {
		if (DEBUG) printf("%s\n", "null env, returning DUMMY");
		return MKOBJ(DUMMY, dummy, 0);
	}

	Frame* frame = env->frame;
	Obj checkFrame = lookup_in_frame(var, frame);

	if (checkFrame.tag != DUMMY)
		return checkFrame;
	else
		return lookup_in_env(var, env->enclosure);
}

Obj lookup_in_frame(char* var, Frame* frame) { // helper for lookup
	if (DEBUG) printf("%s\n", "looking up in frame...");
	if (frame == NULL)
		return MKOBJ(DUMMY, dummy, 0);

	char* key = frame->key;

	if (strcmp(var, key) == 0)
		return (frame->val);
	else
		return lookup_in_frame(var, frame->next);
}

/* modify env */

// add keyval to first frame in env
void defineVar(Obj var_obj, Obj val_obj, Obj env_obj) {
	char* var = var_obj.val.name;
	Env* env = env_obj.val.env;

	Frame* frame = env->frame;

	while (frame != NULL) {
		if (strcmp(var, frame->key) == 0) {
			frame->val = val_obj;
			return;
		}

		frame = frame->next; // cdr down frame list
	}

	// frame == NULL
	frame = malloc(sizeof(Frame));
	frame->key = var;
	frame->val = val_obj;
	frame->next = NULL;
	return;
}

// set first occurence of var to val
void setVar(Obj var_obj, Obj val_obj, Obj env_obj) {
	char* var = var_obj.val.name;
	Env* env = env_obj.val.env;

	if (env == NULL) {
		printf("unbound variable -- setVar\n");
		return;
	}

	Frame* frame = env->frame;

	while (frame != NULL) {

		if (strcmp(var, frame->key) == 0) {
			frame->val = val_obj;
			return;
		}

		frame = frame->next;
	}

	Obj enclosure = MKOBJ(ENV, env, env->enclosure);

	setVar(var_obj, val_obj, enclosure);
}

// add a new frame to base_env, return pointer to new env
Obj extendEnv(Obj vars_obj, Obj vals_obj, Obj base_env_obj) {
	List* vars = vars_obj.val.list;
	List* vals = vals_obj.val.list;
	Env* base_env = base_env_obj.val.env;

	Frame* frame = makeFrame(vars, vals);
	Env* ext_env = malloc(sizeof(Env));
	ext_env->frame = frame;
	ext_env->enclosure = base_env;

	Obj ext_env_obj = MKOBJ(ENV, env, ext_env);
	return ext_env_obj;
}

/* constructors */

// cons-like
List* makeList(Obj car, List* cdr) {
	List* list = malloc(sizeof(List));
	list->car = car;
	list->cdr = cdr;
	return list;
}

// zip-like
Frame* makeFrame(List* vars, List* vals) {
	if (vars == NULL)
		return NULL;

	char* key = vars->car.val.name;
	Obj val = vals->car;

	Frame* frame = malloc(sizeof(Frame));

	frame->key = key;
	frame->val = val;

	frame->next = makeFrame(vars->cdr, vals->cdr);

	return frame;
}

Env* makeEnv(Frame* frame, Env* enclosure) {
	Env* env = malloc(sizeof(Env));
	env->frame = frame;
	env->enclosure = enclosure;
	return env;
}

/* lookup table for primitive function names */

// Obj makeBaseEnv(void) {
// 	List* function_vars = 
// 		makeList(MKOBJ(NAME, name, "add"), 
// 			makeList(MKOBJ(NAME, name, "sub"), 
// 				makeList(MKOBJ(NAME, name, "mul"), 
// 					makeList(MKOBJ(NAME, name, "div"), NULL))));

// 	List* function_vals = 
// 		makeList(MKOBJ(FUNC, func, add_), 
// 			makeList(MKOBJ(FUNC, func, sub_), 
// 				makeList(MKOBJ(FUNC, func, mul_), 
// 					makeList(MKOBJ(FUNC, func, div_), NULL))));

// 	Frame* primitives = makeFrame(function_vars, function_vals);

// 	Env* env = makeEnv(primitives, NULL);

// 	Obj env_obj = MKOBJ(ENV, env, env);

// 	return env_obj;
// }