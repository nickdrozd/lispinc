/*
	LIB

	These are the functions that are loaded into lispinc
	on startup. Many Lisp implementations include 
	functions like cons, car, and cdr as primitives.
	An alternative approach is to define those functions
	in terms of lambda abstraction. While these lambda 
	definitions tend to be opaque, this approach has 
	has the advantages that 1) it's more theoretically 
	elegant to avoid unneeded primitives and 2) it saves 
	the trouble of having to deal primitive C functions 
	any more than is necessary.

	read.c loops over the length of the library to load 
	library functions, then switches to reading user 
	input. Unfortunately, there is no way to check 
	the length of the library array (or is there???), 
	so the length of the library must be updated by
	hand. To make this easier, counters are included 
	for sections of the library. These counters are 
	all added together to get the length of the library. 

	Remember: these counters must be updated manually!

	#defines are used instead of constants because 
	apparently nothing can be initialized with anything 
	except string literals and numbers.

*/

/* list operations */

#define list_count 4

#define cons \
	"(define cons \
		(lambda (x y) \
			(lambda (s) \
				(s x y))))"

#define car \
	"(define car \
		(lambda (p) \
			(p (lambda (x y) \
					x))))"

#define cdr \
	"(define cdr \
		(lambda (p) \
			(p (lambda (x y) \
					y))))"

#define nil \
	"(define nil (quote ()))"

/* arithmetic operations */

#define arith_count 5

#define zero_ \
	"(define zero? \
		(lambda (n) \
			(= n 0)))"

#define add1 \
	"(define add1 \
		(lambda (n) \
			(+ n 1)))"

#define sub1 \
	"(define sub1 \
		(lambda (n) \
			(- n 1)))"

#define fact_rec \
	"(define recursive_factorial \
		(lambda (n) \
			(if (zero? n) \
				1 \
				(* n (recursive_factorial (sub1 n))))))"

#define fact_iter \
	"(define iterative_factorial \
		(lambda (n) \
			(begin \
				(define loop \
					(lambda (count total) \
						(if (zero? count) \
							total \
							(loop (sub1 count) \
								(* total count))))) \
				(loop n 1))))"

/* newlines are needed because of some quirk in the
	parsing process (see read.c and parse.c) */

char* library[] = {cons"\n",
					 car"\n", 
					 cdr"\n", 
					 nil"\n", 
					 zero_"\n",
					 add1"\n", 
					 sub1"\n",  
					 fact_rec"\n", 
					 fact_iter"\n"};

/* lib_len should match the length of library
	(this has to be handled manually?) */

int lib_len = list_count + arith_count;