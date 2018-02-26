##
# @see http://releases.llvm.org/3.8.0/tools/clang/docs/UsersManual.html
# @see https://stackoverflow.com/questions/15548023/clang-optimization-levels
##

# compiler to use
CC = clang

# flags to pass compiler
CFLAGS = -fsanitize=signed-integer-overflow -fsanitize=undefined -O0 -ggdb3 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wshadow

# name for executable
EXE = trienode

# space-separated list of header files
HDRS =

# space-separated list of libraries, if any,
# each of which should be prefixed with -l
LIBS =

# space-separated list of source files
SRCS = trienode.c trienode_test.c

# automatically generated list of object files
OBJS = $(SRCS:.c=.o)


# default target
$(EXE): $(OBJS) $(HDRS) makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# dependencies
$(OBJS): $(HDRS) makefile

# housekeeping
clean:
	rm -f $(EXE) *.o
