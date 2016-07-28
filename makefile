NAME = lispinc

CC = gcc
CFLAGS = -Wall -std=c99 -g
make_obj = $(CC) $(CFLAGS) -c

objects = ec_main.o read.o flags.o parse.o env.o primitives.o lib.o registers.o stack.o llh.o print.o mem.o

$(NAME) : $(objects)
	$(CC) -o $(NAME) $(objects)

main_headers = flags.h read.h mem.h env.h registers.h stack.h llh.h print.h objects.h

ec_main.o : ec_main.c $(main_headers)
	$(make_obj) ec_main.c

read.o : read.c read.h parse.h lib.h flags.h print.h keywords.h objects.h
	$(make_obj) read.c

flags.o : flags.c read.c flags.h
	$(make_obj) flags.c

parse.o : parse.c parse.h flags.h keywords.h objects.h
	$(make_obj) parse.c

env.o : env.c env.h mem.h flags.h objects.h
	$(make_obj) env.c

primitives.o : primitives.c primitives.h objects.h
	$(make_obj) primitives.c

lib.o : lib.c flags.h keywords.h lib.h
	$(make_obj) lib.c

registers.o : registers.c print.h objects.h
	$(make_obj) registers.c

stack.o : stack.c stack.h flags.h objects.h
	$(make_obj) stack.c

llh.o : llh.c llh.h flags.h keywords.h objects.h
	$(make_obj) llh.c

print.o : print.c print.h registers.h stack.h flags.h objects.h
	$(make_obj) print.c

mem.o: mem.c mem.h parse.h flags.h objects.h
	$(make_obj) mem.c