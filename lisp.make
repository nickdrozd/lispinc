CC = gcc
CFLAGS = -Wall

lispinc: ec_main.c parse.c env.c llh.c stack.c print.c
	$(CC) $(CFLAGS) -o lispinc