# lispinc
An "explicit-control" Lisp interpreter written in assembly-like C

In the textbook Structure and Interpretation of Computer Programs (SICP), Abelson and Sussman present two styles of Lisp (Scheme) interpreters. In the first style, the semantics of the target language are specified (e.g. an "if" statement has its test condition evaluated first, and then either its consequent or alternative are evaluated according as whether the test condition returned true or false), but nothing else is. In particular, the memory requirements of the target language cannot be specified, since the evaluation of the target language is left up to the language of the interpreter. (They call this interpreter a *metacircular evaluator*, since it is written in Lisp and interprets Lisp, but this is an inessential detail.)

The second style of interpreter, which they call an *explicit-control evaluator*, remedies this problem by showing how to interpret the language at a more primitive level. To implement this interpreter, they develop a toy assembly language complete with goto statements and a stack capable of handling recursion of arbitrary depth. Being written in directly in assembly, the explicit-control evaluator makes no (nontrivial) function calls, and so leaves (almost) nothing up to the underlying language. Every part of the computation is completely visible at all times, and it is possible to control exactly how interpretation is to be undertaken. In particular, it's possible to specify that the interpreter be (or not be) tail recursive, allowing one to implement iterative processes using function calls without incurring more than constant memory use.

The book's penultimate exercise, Exercise 5.51, reads "Develop a rudimentary implementation of Scheme in C (or some other low-level language of your choice) by translating the explicit-control evaluator...into C. In order to run this code you will need to also provide appropriate storage-allocation routines and other run-time support".

 lispinc is just such a translation. Or is it an adaption? Actually, the program's main function (found in ec_main.c) is basically a literal translation of SICP's toy assembly code. Here is a comparison of the section of the interpreter that handles lambda expressions:

 SICP (toy assembly):

 ev-lambda
	(assign unev (op lambda-parameters) (reg exp))
	(assign exp (op lambda-body) (reg exp))
	(assign val (op make-procedure)
				(reg unev) (reg exp) (reg env))
	(goto (reg continue))

lispinc (C):

LAMBDA:
	unev = lambdaParams(expr);
	expr = lambdaBody(expr);
	val = makeFunc(unev, expr, env);
	goto CONTINUE;

Aside from minor terminological differences, it should be clear that these two pieces of code are basically the same. There is one nontrivial difference: SICP's toy assembly code allows for goto labels to be passed around as values of variables (in other words, labels are first-class objects), while C does not. Instead of passing around goto labels, lispinc passes enum labels and then adds an extra goto label CONTINUE that dispatches on the enums.

The part of lispinc that actually does the interpretation -- a seriously clever tangle of gotos and stack pushes and pops -- was copied more or less straight out of SICP. The rest of it -- input, parsing, environment manipulation, and printing -- was written from scratch. However, anyone familiar with the programming style advocated by SICP would immediately recognize certains parts of this program (especially the part dealing with environments) as striving to emulate it.

FAQ

* Why did you write this in C? Why not something easier, like Python?

One way of "translating" SICP's explicit-control evaluator would be to write it in actual assembly for a real chip or whatever. I don't know assembly, and I didn't feel like learning. I did, however, know enough C to get off the ground, and since C is still respectably low-level, I figured it would be good enough as a substitute. (C is also mentioned explicitly in the SICP problem statement.) Certainly the interpreter could be adapted to a higher-level language, but it would be harder to ensure that the underlying language wasn't "doing the work".

