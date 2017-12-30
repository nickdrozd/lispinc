NAME := lispinc
SRCS := $(wildcard *.c)
OBJS := ${SRCS:.c=.o}
HDRS := ${SRCS:.c=.h}

CFLAGS += -std=c99 -Wall -Wextra -g
# -pedantic -O3

DEPS := objects.h keywords.h

.PHONY : all clean format

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o : %.c %.h $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	@- $(RM) $(OBJS)

format :
	clang-format -i *.[ch] -style=file
