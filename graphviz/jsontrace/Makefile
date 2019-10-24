#
# Makefile for the trace utility.
#

CC = gcc

OBJS = trace.o symbols.o stack.o

jsontrace: $(OBJS)
	gcc -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -Wall -c $<

install: jsontrace
	cp jsontrace /usr/local/bin

clean:
	rm -f jsontrace *.o
