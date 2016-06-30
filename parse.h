/* tokens */

typedef struct Token Token;
typedef struct Token_list Token_list;

typedef enum {
	OP,
	CP,
	SYM,
	tokenid_count
} TokenID;

typedef enum {
	READY,
	SYMBOL,
	state_count
} State;

struct Token {
	int start;
	int end;
	TokenID id;
	char* text;
};

struct Token_list {
	Token token;
	Token_list* next;
};

// prototypes
Obj read(char* expr);
Token_list* tokenize(char* expr);
Obj parse(Token_list* tokens);

void dock(Token_list** list);
Token_list* slice_ends(Token_list** list);
void push(Obj obj, List** list);