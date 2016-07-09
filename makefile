CC = gcc
CFLAGS = -Wall
make_obj = $(CC) $(CFLAGS) -c

objects = ec_main.o parse.o read.o env.o registers.o stack.o llh.o print.o
headers = read.h env.h registers.h stack.h llh.h print.h objects.h

lispinc : $(objects)
	$(CC) -o lispinc $(objects)

ec_main.o : ec_main.c $(headers)
	$(make_obj) ec_main.c

parse.o : parse.c parse.h objects.h
	$(make_obj) parse.c

read.o : read.c read.h parse.h objects.h
	$(make_obj) read.c

env.o : env.c env.h objects.h
	$(make_obj) env.c

registers.o : registers.c objects.h
	$(make_obj) registers.c

stack.o : stack.c stack.h objects.h
	$(make_obj) stack.c

llh.o : llh.c llh.h objects.h
	$(make_obj) llh.c

print.o : print.c print.h registers.h objects.h
	$(make_obj) print.c

