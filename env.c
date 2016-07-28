#include "env.h"

/* base_env established separately to 
	persist through repl */

Env* base_env;

/* env builders */

// returns pointer to base_env
Env* makeBaseEnv(void) {

	List* prim_vars = primitive_vars();
	List* prim_vals = primitive_vals();

	Frame* primitives = makeFrame(prim_vars, prim_vals);

	Env* env = makeEnv(primitives, NULL);

	append_to_envs(env);

	return env;
}

// returns new env obj with vars bound to vals
Obj extendEnv(Obj vars_obj, Obj vals_obj, Obj base_env_obj) {

	List* vars = vars_obj.val.list;
	List* vals = vals_obj.val.list;
	Env* base_env = base_env_obj.val.env;

	Frame* frame = makeFrame(vars, vals);
	Env* ext_env = makeEnv(frame, base_env);

	append_to_envs(ext_env);

	return ENVOBJ(ext_env);
}


/* lookup */

// returns val bound to var in env
Obj lookup(Obj var_obj, Obj env_obj) {
			if (DEBUG) printf("looking up \"%s\"\n", var_obj.val.name);

	char* var = var_obj.val.name;
	Env* env = env_obj.val.env;

	return lookup_in_env(var, env);
}

// lookup helpers

Obj lookup_in_env(char* var, Env* env) { // lookup in env
			if (DEBUG) printf("%s\n", "looking up in env...");
	if (env == NULL) {
			if (DEBUG) printf("%s\n", "null env, returning DUMMY");
		return DUMMYOBJ;
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
		return DUMMYOBJ;

	char* key = frame->key;

	if (strcmp(var, key) == 0)
		return (frame->val);
	else
		return lookup_in_frame(var, frame->next);
}

/* modify env */

/* adds new var/val binding to env
(doesn't check for existing binding) */
void defineVar(Obj var_obj, Obj val_obj, Obj* env_obj) {

	char* var = var_obj.val.name;
	Env* env = (*env_obj).val.env;

	Frame* frame = malloc(sizeof(Frame));
	frame->key = var;
	frame->val = val_obj;
	frame->next = env->frame;
	env->frame = frame;
	return;
}

// sets first occurence of var to val
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

	Obj enclosure = ENVOBJ(env->enclosure);

	setVar(var_obj, val_obj, enclosure);
}

/* constructors */

Env* makeEnv(Frame* frame, Env* enclosure) {
	Env* env = malloc(sizeof(Env));
	env->frame = frame;
	env->enclosure = enclosure;
	return env;
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

// cons-like (declaration in objects.h)
List* makeList(Obj car, List* cdr) {
	List* list = malloc(sizeof(List));
	list->car = car;
	list->cdr = cdr;
	return list;
}
