#include "lib.h"

#define triangular \
	"("DEF_KEY" recursive_triangular_interpreted \
		("LAMBDA_KEY" (n) \
			("IF_KEY" (zero? n) \
				0 \
				("ADD_NAME" n (recursive_triangular_interpreted (sub1 n))))))"

#define tetrahedral \
	"("DEF_KEY" recursive_tetrahedral_interpreted \
		("LAMBDA_KEY" (n) \
			("IF_KEY" (zero? n) \
				0 \
				("ADD_NAME" (recursive_triangular_interpreted n) \
					(recursive_tetrahedral_interpreted (sub1 n))))))"

#define supertetrahedral \
	"("DEF_KEY" recursive_supertetrahedral_interpreted \
		("LAMBDA_KEY" (n) \
			("IF_KEY" (zero? n) \
				0 \
				("ADD_NAME" (recursive_tetrahedral_interpreted n) \
					(recursive_supertetrahedral_interpreted (sub1 n))))))"

#define fact_rec \
	"("DEF_KEY" recursive_factorial_interpreted \
		("LAMBDA_KEY" (n) \
			("IF_KEY" (zero? n) \
				1 \
				("MUL_NAME" n (recursive_factorial_interpreted (sub1 n))))))"

#define fact_iter \
	"("DEF_KEY" iterative_factorial_interpreted \
		("LAMBDA_KEY" (n) \
			("DEF_KEY" loop \
				("LAMBDA_KEY" (count total) \
					("IF_KEY" (zero? count) \
						total \
						(loop (sub1 count) \
							("MUL_NAME" total count))))) \
			(loop n 1)))"

#define fib_rec \
	"("DEF_KEY" recursive_fibonacci_interpreted \
		("LAMBDA_KEY" (n) \
			("IF_KEY" (< n 2) \
				n \
				("ADD_NAME" (recursive_fibonacci_interpreted (- n 1)) \
					(recursive_fibonacci_interpreted (- n 2))))))"

#define fib_iter \
	"("DEF_KEY" iterative_fibonacci_interpreted \
		("LAMBDA_KEY" (n) \
			("DEF_KEY" loop \
				("LAMBDA_KEY" (count a b) \
					("IF_KEY" (zero? count) \
						a \
						(loop (sub1 count) \
							b \
							("ADD_NAME" a b))))) \
			(loop n 0 1)))"

/* newlines are needed because of some quirk in the
	parsing process (see read.c and parse.c) */

char* library[] = {
	 triangular"\n", 
	 tetrahedral"\n", 
	 supertetrahedral"\n", 
	 fact_rec"\n", 
	 fact_iter"\n",
	 fib_rec"\n",
	 fib_iter"\n",
	};

/* lib_len should match the length of library
	(this has to be handled manually?) */

int lib_len = 7;


/* library loading */

int lib_counter = 0;

char* load_library(void) {	
			if (DEBUG) print_lib();
	char* lib_entry = library[lib_counter];
	lib_counter++;
	return lib_entry;
}

void print_lib(void) {
	char* lib_entry = library[lib_counter];
	printf("loading library entry: %s\n", lib_entry);
}

bool lib_loaded(void) {
	return lib_counter >= lib_len;
}
