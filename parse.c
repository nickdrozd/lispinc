#include "parse.h"

Obj process_code_text(char* expr) {
	Token_list* tokens = tokenize(expr);
	Obj parsed = parse(tokens);
	// free_tokens(&tokens);
	return parsed;
}

// TODO: special case for nonlist expr (???)
Token_list* tokenize(char* expr) {
			if (DEBUG) printf("%s\n", "tokenizing...");
	State state = READY;

	int length = strlen(expr);
	if (length == 0) return NULL;

	int i = 0;
	char c;

	Token_list* tokens = malloc(sizeof(Token_list)); // initialize to NULL?
	Token_list* tail = tokens;
	tail->next = NULL;

	// temporary variables
	int start;
	int end;
	int sub_length;
	char* text;

	// debugging
	// Token_list* temp = tokens;
	// int parens = 0;

	START:
		if (i >= length) {
			if (state == SYMBOL) {
				goto END_TEXT;
			}
			goto DONE;
		}

		c = expr[i];

		// TODO: special case for nonlist expr (???)

		if (OPENPAREN(c))
			goto OPEN;
		if (CLOSEPAREN(c))
			goto CLOSE;
		if (WHITESPACE(c))
			goto SEPARATOR;

		/* default case is any other char
		so no other if clause is needed? */
		// if (isalnum(c))
			goto TEXT;

	OPEN://printf("%d @ %s\n", state, "OPEN");
		if (state == SYMBOL)
			goto END_TEXT;
		tail->token.start = i;
		tail->token.end = i + 1;
		tail->token.id = OP;
		tail->token.text = "OPEN";
		tail->next = malloc(sizeof(Token_list));
		tail = tail->next;
		tail->next = NULL;
		i++;
		goto START;

	CLOSE://printf("%d @ %s\n", state, "CLOSE");
		if (state == SYMBOL)
			goto END_TEXT;
		tail->token.start = i;
		tail->token.end = i + 1;
		tail->token.id = CP;
		tail->token.text = "CLOSE";
		// what should this value be???
		if (i < length - 2) {
			tail->next = malloc(sizeof(Token_list));
			tail = tail->next;
			tail->next = NULL;
		}
		i++;
		goto START;

	SEPARATOR://printf("%d @ %s\n", state, "SEPARATOR");
		if (state == SYMBOL)
			goto END_TEXT;
		i++;
		goto START;

	TEXT://printf("%d @ %s\n", state, "TEXT");
		if (state == READY) {
			state = SYMBOL;
			tail->token.id = SYM;
			tail->token.start = i;
		}
		i++;
		goto START;

	END_TEXT://printf("%d @ %s\n", state, "END_TEXT");
		tail->token.end = i;
		start = tail->token.start;
		end = tail->token.end;
		sub_length = end - start;
		text = malloc(sub_length * sizeof(char));
		strncpy(text, expr + start, sub_length);
		text[sub_length] = '\0';	
		tail->token.text = text;
		if (i < length - 1) {
			tail->next = malloc(sizeof(Token_list));
			tail = tail->next;
			tail->next = NULL;
		}
		state = READY;
		goto START;

	DONE:
				if (DEBUG) print_tokens(tokens);
		return tokens;
}	


Obj parse(Token_list* tokens) {
			if (DEBUG) { printf("%s\n", "parsing..."); print_tokens(tokens); }

	if (tokens == NULL) {
		printf("%s\n", "no tokens -- read_from_tokens");
		exit(1);
	}

	Obj obj; 
	Token token = tokens->token;

	// code is a name or number
	if (token.id == SYM) {
		// if (DEBUG) printf("token: %s\n", token.text);
		char* text = token.text;
		if (isdigit(text[0])) 
			obj = NUMOBJ(atoi(text));
		else 
			obj = NAMEOBJ(text);
		return obj;
	}

	// code is a list
	List* result = NULL;
	Token_list* remainder = slice_ends(&tokens);

	Token_list* head = NULL;
	Token_list* tail = NULL;

	int op = 0;
	int cp = 0;

	while (remainder) {
		Token first = remainder->token;

		// first item is an atom
		if (first.id == SYM) { 
			// wrap first (Token) in a Token_list to pass to parse
			Token_list dummy;
			dummy.next = NULL;
			dummy.token = first;
			push(parse(&dummy), &result);

				// do we need this?
			// if (remainder->next == NULL)
			// 	return result;
			// else
				remainder = remainder->next;
		}

		// first item is a list
		else {
			op = 1;
			cp = 0;
			head = remainder;
			tail = remainder;
			while (op > cp) { // this will terminate if code is wellformed
				tail = tail->next;
				if (tail->token.id == OP)
					op++;
				if (tail->token.id == CP)
					cp++;
			}
			remainder = tail->next;
			tail->next = NULL;
			push(parse(head), &result);
		} 
	}

	// record memory usage
	append_to_lists(result);
	// if (!lists_head)
	// 	lists_head = lists_tail;

	obj = LISTOBJ(result);
	return obj;
}


/* list manipulation */

// token list
void dock(Token_list** list) {
	if (*list == NULL) return;
	
	else if ((*list)->next == NULL) {
		free(*list);
		*list = NULL;
		return;
	}
	
	else dock(&((*list)->next));
}

Token_list* slice_ends(Token_list** list) {
	Token_list* sliced = (*list)->next;
	free(*list);
	*list = NULL;
	dock(&sliced);
	return sliced;
}

// obj list
void push(Obj obj, List** list) {
	if (*list == NULL) {
		*list = malloc(sizeof(List));
		(*list)->car = obj;
		(*list)->cdr = NULL;
		return;
	}

	else push(obj, &((*list)->cdr));
}

/* for debugging */

void print_tokens(Token_list* tokens) {
	printf("printing tokens...\n");

	while (tokens) {
		printf("text: %s\n", tokens->token.text);
		printf("next: %p\n", tokens->next);
		tokens = tokens->next;
	}

	printf("tokens printed!\n");
	return;
}

/* memory management */

void free_tokens(Token_list** list) {
			if (DEBUG) printf("freeing tokens...\n");

	if (*list == NULL)
		return;

	Token_list* temp = *list;
	*list = (*list)->next;
	free(temp);
	temp = NULL;
	free_tokens(list);
}