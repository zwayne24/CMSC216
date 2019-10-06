CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -fstack-protector-all -Werror -Wshadow

all: public01.x public02.x public03.x public04.x public05.x public06.x \
public07.x public08.x public09.x public10.x public11.x public12.x \
public13.x public14.x public15.x

pq.o: pq.c pq.h
	$(CC) -c $(CFLAGS) pq.c

check-string-array.o: check-string-arrays.c check-string-arrays.h
	$(CC) -c $(CFLAGS) check-string-arrays.c

public01.x: check-string-arrays.o public01.o
	$(CC) check-string-arrays.o public01.o -o public01.x

public02.x: check-string-arrays.o pq.o public02.o
	$(CC) check-string-arrays.o pq.o public02.o -o public02.x

public03.x: pq.o public03.o
	$(CC) pq.o public03.o -o public03.x

public04.x: pq.o public04.o
	$(CC) pq.o public04.o -o public04.x

public05.x: pq.o public05.o
	$(CC) pq.o public05.o -o public05.x

public06.x: pq.o public06.o
	$(CC) pq.o public06.o -o public06.x

public07.x: pq.o check-string-arrays.o public07.o
	$(CC) pq.o check-string-arrays.o public07.o -o public07.x

public08.x: pq.o check-string-arrays.o public08.o
	$(CC) pq.o check-string-arrays.o public08.o -o public08.x

public09.x: pq.o check-string-arrays.o public09.o
	$(CC) pq.o check-string-arrays.o public09.o -o public09.x

public10.x: pq.o check-string-arrays.o public10.o
	$(CC) pq.o check-string-arrays.o public10.o -o public10.x

public11.x: pq.o check-string-arrays.o public11.o
	$(CC) pq.o check-string-arrays.o public11.o -o public11.x

public12.x: pq.o check-string-arrays.o public12.o
	$(CC) pq.o check-string-arrays.o public12.o -o public12.x

public13.x: pq.o public13.o
	$(CC) pq.o public13.o -o public13.x

public14.x: pq.o public14.o
	$(CC) pq.o public14.o -o public14.x

public15.x: pq.o public15.o
	$(CC) pq.o public15.o -o public15.x

public01.o: check-string-arrays.h public01.c 
	$(CC) -c $(CFLAGS) public01.c

public02.o: check-string-arrays.h pq.h public02.c
	$(CC) -c $(CFLAGS) public02.c

public03.o: pq.h public03.c
	$(CC) -c $(CFLAGS) public03.c

public04.o: pq.h public04.c
	$(CC) -c $(CFLAGS) public04.c

public05.o: pq.h public05.c
	$(CC) -c $(CFLAGS) public05.c

public06.o: pq.h public06.c
	$(CC) -c $(CFLAGS) public06.c

public07.o: pq.h check-string-arrays.h public07.c
	$(CC) -c $(CFLAGS) public07.c

public08.o: pq.h check-string-arrays.h public08.c
	$(CC) -c $(CFLAGS) public08.c

public09.o: pq.h check-string-arrays.h public09.c
	$(CC) -c $(CFLAGS) public09.c

public10.o: pq.h check-string-arrays.h public10.c
	$(CC) -c $(CFLAGS) public10.c

public11.o: pq.h check-string-arrays.h public11.c
	$(CC) -c $(CFLAGS) public11.c

public12.o: pq.h check-string-arrays.h public12.c
	$(CC) -c $(CFLAGS) public12.c

public13.o: pq.h public13.c
	$(CC) -c $(CFLAGS) public13.c

public14.o: pq.h public14.c
	$(CC) -c $(CFLAGS) public14.c

public15.o: pq.h public15.c
	$(CC) -c $(CFLAGS) public15.c

clean:
	-rm -f *.o *.x
