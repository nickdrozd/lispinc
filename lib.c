#define fact_rec \
	"(define recursive_factorial \
		(lambda (n) \
			(if (= n 0) \
				1 \
				(* n (recursive_factorial (- n 1))))))\n"

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
				(loop n 1))))\n"


/* lib_len should match the length of library
	(this has to be handled manually) */
char* library[] = {fact_rec, fact_iter};
int lib_len = 2;