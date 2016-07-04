lispinc: ec_main.c objects
	cc *.o ec_main.c -o lispinc

objects: env.c llh.c parse.c print.c stack.c
	cc env.c llh.c parse.c print.c stack.c -c

.PHONY: clean
clean: 
	rm -f *.o lispinc
