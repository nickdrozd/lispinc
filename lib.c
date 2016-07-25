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

#define fact_rec \
	"(define recursive_factorial \
		(lambda (n) \
			(if (= n 0) \
				1 \
				(* n (recursive_factorial (- n 1))))))"

#define fact_iter \
	"(define iterative_factorial \
		(lambda (n) \
			(begin \
				(define loop \
					(lambda (count total) \
						(if (= count 0) \
							total \
							(loop (- count 1) \
								(* total count))))) \
				(loop n 1))))"


char* library[] = {cons"\n",
					 car"\n", 
					 cdr"\n", 
					 nil"\n", 
					 fact_rec"\n", 
					 fact_iter"\n"};

/* lib_len should match the length of library
	(this has to be handled manually?) */

int lib_len = 6;