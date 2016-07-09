CC = gcc
CFLAGS = -Wall

lispinc: ec_main.c objects
	$(CC) *.o ec_main.c -o lispinc $(CFLAGS)

objects: env.c llh.c parse.c print.c stack.c read.c registers.c
	$(CC) env.c llh.c parse.c print.c stack.c registers.c read.c -c

.PHONY: clean
clean: 
	rm -f *.o lispinc
