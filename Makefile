CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wpedantic -O3
CHECKFLAGS = -lcheck

SRCS = quadratic_equation.c
CHECKSRCS = tests.c

STATIC_LIB = quadratic_equation.a

OBJS = $(SRCS:.c=.o)

all: check

lib: $(STATIC_LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(STATIC_LIB): $(OBJS)
	ar -rcs $@ $^

check: $(STATIC_LIB)
	$(CC) $(CFLAGS) $(STATIC_LIB) $(CHECKSRCS) -o tests.out $(CHECKFLAGS)
	@./tests.out

clean:
	rm -rf *.o *.out *.a
