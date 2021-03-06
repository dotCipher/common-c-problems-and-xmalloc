# Makefile for HW2
# By: Cody Moore
# CSE 376

# C-Compiler (default: GNU C-Compiler)
CC=gcc
GCC=gcc

# Compile flags (No error checking for demo purposes)
CFLAGS_NORMAL=-g -O2 -Wall
# -Wall -Werror left out on purpose
CFLAGS=-g -O2 -w
CDBGFLAGS=-g -O0 -w

# Source Files
ALL_SRCS:=$(wildcard *.c)
ALL_HDRS:=$(wildcard *.h)
TEST_SRCS:=$(filter-out prog-%.c, $(ALL_SRCS))
XMEM_SRCS=$(filter-out xmalloc%.c, $(ALL_SRCS))

# Object Files
TEST_OBJS=$(patsubst %.c, %.o, $(TEST_SRCS))
XMEM_OBJS=$(patsubst %.c, %.o, $(XMEM_SRCS))

# Exec Files
TEST_EXEC=$(patsubst %.c, %, $(TEST_SRCS))
XMEM_EXEC=$(patsubst %.c, %, $(XMEM_SRCS))

# Main targets (default: GNU C-Compiler)
all: all-gcc
all-gcc: prog-all xmalloc xmalloc-test

# Test Source Targets (default: GNU C-Compiler)
prog-all: prog-all-gcc
prog-all-gcc:$(TEST_OBJS)
	for f in $(shell ls | grep ^prog-[0-9][0-9].c -c | xargs seq -w 1); do \
		$(GCC) $(CFLAGS) prog-$$f.c -o prog-$$f; \
	done

prog-%: prog-%.c
	$(CC) $(CFLAGS) $< -o $@
prog-%-gcc: prog-%.c
	$(GCC) $(CFLAGS) $< -o $(patsubst prog-%-gcc, prog-%, $@)

# Run targets
run-all run-all-gcc: $(TEST_EXEC) xmalloc-test
	for f in $^; do \
		./$$f;\
	done
run-%: prog-%
	./$(patsubst run-%, prog-%, $<)
run-%-gcc: prog-%
	./$(patsubst run-%, prog-%, $<)

# Xmem targets (xmalloc/xfree)
xmalloc xmalloc.o: xmalloc.c xmalloc.h
	$(GCC) $(CFLAGS_NORMAL) -c $<
xmalloc-test: xmalloc_test.c xmalloc.o
	$(GCC) $(CFLAGS_NORMAL) $< -o $@ xmalloc.o

# Clean targets
# Using deprecated perm find (temporary solution)
clean:
	find . -perm +100 -type f -delete ; \
<<<<<<< Makefile
	rm -f *.o
=======
	rm -f *.o

>>>>>>> 1.11
