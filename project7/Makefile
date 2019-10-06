CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -fstack-protector-all -Werror -Wshadow

all: main.x tester.x program1.x

main.x: main.o compare-arrays.o fill-array.o
	$(CC) main.o compare-arrays.o fill-array.o -o main.x

tester.x: tester.o fill-array.o incr-array.o sum-array.o
	$(CC) tester.o fill-array.o incr-array.o sum-array.o -o tester.x

program1.x: program1.o compare-arrays.o
	$(CC) program1.o compare-arrays.o -o program1.x

main.o: main.c compare-arrays.h fill-array.h
	$(CC) -c $(CFLAGS) main.c

tester.o: tester.c fill-array.h incr-array.h sum-array.h
	$(CC) -c $(CFLAGS) tester.c

program1.o: program1.c compare-arrays.h
	$(CC) -c $(CFLAGS) program1.c

compare-arrays.o: compare-arrays.c compare-arrays.h
	$(CC) -c $(CFLAGS) compare-arrays.c

fill-array.o: fill-array.c fill-array.h
	$(CC) -c $(CFLAGS) fill-array.c

incr-array.o: incr-array.c incr-array.h
	$(CC) -c $(CFLAGS) incr-array.c

sum-array.o: sum-array.c sum-array.h
	$(CC) -c $(CFLAGS) sum-array.c

clean:
	-rm -f *.o *.x
