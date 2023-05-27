CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

OBJS = main.o stack.o sort.o

all: program

program: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o program

main.o: main.c stack.h sort.h
	$(CC) $(CFLAGS) -c main.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

sort.o: sort.c sort.h
	$(CC) $(CFLAGS) -c sort.c

clean:
	rm -f $(OBJS)
