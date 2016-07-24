Frame* makeFrame(List* vars, List* vals);
Env* makeEnv(Frame* frame, Env* enclosure);
Obj extendEnv(Obj vars_obj, Obj vals_obj, Obj base_env_obj);

Obj lookup_in_frame(char* var, Frame* frame);
Obj lookup_in_env(char* var, Env* env);
Obj lookup(Obj var_obj, Obj env_obj);

void defineVar(Obj var_obj, Obj val_obj, Obj* env_obj);
void setVar(Obj var_obj, Obj val_obj, Obj env_obj);

Env* makeBaseEnv(void);

extern Env* base_env;
