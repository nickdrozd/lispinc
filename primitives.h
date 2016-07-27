List* primitive_vars(void);
List* primitive_vals(void);

/* primitive arithmetic functions */

#define PRIM_ADD "+"
#define PRIM_SUB "-"
#define PRIM_MUL "*"
#define PRIM_DIV "/"
#define PRIM_EQ "=" 

intFunc add_;
intFunc sub_;
intFunc mul_;
intFunc div_;
intFunc eq_;