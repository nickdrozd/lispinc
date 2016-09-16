#include "env.h"

/* base_env established separately to 
	persist through repl */

Env* base_env;

/* env builders */

// returns pointer to base_env
Env* makeBaseEnv(void) {

	List* prim_vars = primitive_vars();
	List* prim_vals = primitive_vals();

	Frame* primitives = zipFrame(prim_vars, prim_vals);

	Env* env = makeEnv(primitives, NULL);

	// memory management
	append_to_envs(env);

	return env;
}

// returns new env obj with vars bound to vals
Obj extendEnv(Obj vars_obj, Obj vals_obj, Obj base_env_obj) {
	List* vars;
	List* vals;

	switch(GETTAG(vars_obj)) {
		case LIST:
			vars = GETLIST(vars_obj);
			vals = GETLIST(vals_obj);
			break;
		case NAME:
			vars = makeList(vars_obj, NULL);
			vals = makeList(vals_obj, NULL);			
			break;
		default:
			printf("\n%s\n", 
				"UNKNOWN PARAMETER TYPE -- extendEnv");
			return base_env_obj;		
	}

	Env* base_env = GETENV(base_env_obj);

	Frame* frame = zipFrame(vars, vals);
	Env* ext_env = makeEnv(frame, base_env);

	// memory management
	append_to_envs(ext_env);

	return ENVOBJ(ext_env);
}


/* lookup */

// returns val bound to var in env
Obj lookup(Obj var_obj, Obj env_obj) {
			if (DEBUG) printf("looking up \"%s\"\n", GETNAME(var_obj));

	char* var = GETNAME(var_obj);
	Env* env = GETENV(env_obj);

	lookup_count++;

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
	else {
		envs_traversed++;
		return lookup_in_env(var, env->enclosure);
	}
}

Obj lookup_in_frame(char* var, Frame* frame) { // helper for lookup
			if (DEBUG) printf("%s\n", "looking up in frame...");
	if (frame == NULL)
		return DUMMYOBJ;

	char* key = frame->key;

	if (strcmp(var, key) == 0)
		return (frame->val);
	else {
		frames_traversed++;
		return lookup_in_frame(var, frame->next);
	}
}

/* modify env */

/* adds new var/val binding to env */
void defineVar(Obj var_obj, Obj val_obj, Obj env_obj) {

	char* var = GETNAME(var_obj);
	Env* env = GETENV(env_obj);

			if (DEBUG) printf("\nVAR: %s\n", var);

	Frame* frame = env->frame;
	char* key = frame->key;

	while (frame->next) {
				if (DEBUG) printf("%s\n", key);
		if (strcmp(var, key) == 0) {
			printf("variable already defined! -- defineVar\n");
			return;
		}
		else {
			frame = frame->next;
			key = frame->key;
		}
	}
			if (DEBUG) printf("%s\n", key);
	Frame* newFrame = malloc(sizeof(Frame));
	newFrame->key = var;
	newFrame->val = val_obj;
	newFrame->next = NULL;
	frame->next = newFrame;
			if (DEBUG) printf("new frame\n");
	return;
}

// sets first occurence of var to val
void setVar(Obj var_obj, Obj val_obj, Obj env_obj) {

	char* var = GETNAME(var_obj);
	Env* env = GETENV(env_obj);

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

Frame* zipFrame(List* vars, List* vals) {
	if (vars == NULL)
		return NULL;

	char* key = GETNAME(vars->car);
	Obj val = vals->car;

	Frame* frame = malloc(sizeof(Frame));

	frame->key = key;
	frame->val = val;

	frame->next = zipFrame(vars->cdr, vals->cdr);

	return frame;
}

// cons-like (declaration in objects.h)
List* makeList(Obj car, List* cdr) {
	List* list = malloc(sizeof(List));
	list->car = car;
	list->cdr = cdr;
	return list;
}
