program_NAME := lispinc
program_SRCS := $(wildcard *.c)
program_OBJS := ${program_SRCS: .c=.o}

CFLAGS += -Wall -std=c99
#make_obj := $(CC) $(CFLAGS) -c

#.PHONY : all clean

all : $(program_NAME)

$(program_NAME) : $(program_OBJS)
	$(CC) -o $(program_NAME) $(program_OBJS)

#clean : 
#	@- $(RM) $(program_OBJS)

#define CORRESPONDING_HEADER
#	$(1) : ${1: .o=.h}
#	$(foreach object_file,$(program_OBJS),$(eval $(call CORRESPONDING_HEADER,$(object_file))))
#endef
