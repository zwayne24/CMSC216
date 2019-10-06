CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -fstack-protector-all -Werror -Wshadow -g

all: public01.x public02.x public03.x public04.x public05.x public06.x \
public07.x public08.x public09.x public10.x public11.x public12.x \
public13.x public14.x public15.x

pq.o: pq.c pq.h
	$(CC) -c $(CFLAGS) pq.c

check-string-arrays.o: check-string-arrays.c check-string-arrays.h
	$(CC) -c $(CFLAGS) check-string-arrays.c

free-string-array.o: free-string-array.c free-string-array.h
	$(CC) -c $(CFLAGS) free-string-array.c

public01.x: free-string-array.o memory-checking.o public01.o
	$(CC) free-string-array.o memory-checking.o public01.o -o public01.x

public02.x: memory-checking.o pq.o public02.o
	$(CC) memory-checking.o pq.o public02.o -o public02.x

public03.x: pq.o memory-checking.o public03.o
	$(CC) pq.o memory-checking.o public03.o -o public03.x

public04.x: pq.o memory-checking.o public04.o
	$(CC) pq.o memory-checking.o public04.o -o public04.x

public05.x: pq.o memory-checking.o public05.o
	$(CC) pq.o memory-checking.o public05.o -o public05.x

public06.x: pq.o memory-checking.o public06.o
	$(CC) pq.o memory-checking.o public06.o -o public06.x

public07.x: pq.o check-string-arrays.o free-string-array.o memory-checking.o \
public07.o
	$(CC) pq.o check-string-arrays.o free-string-array.o memory-checking.o \
	public07.o -o public07.x

public08.x: pq.o check-string-arrays.o free-string-array.o memory-checking.o \
public08.o
	$(CC) pq.o check-string-arrays.o free-string-array.o memory-checking.o \
	public08.o -o public08.x

public09.x: pq.o check-string-arrays.o free-string-array.o memory-checking.o \
public09.o
	$(CC) pq.o check-string-arrays.o free-string-array.o memory-checking.o \
	public09.o -o public09.x

public10.x: pq.o pqlist.o public10.o
	$(CC) pq.o pqlist.o public10.o -o public10.x

public11.x: pq.o pqlist.o public11.o
	$(CC) pq.o pqlist.o public11.o -o public11.x

public12.x: pq.o pqlist.o public12.o
	$(CC) pq.o pqlist.o public12.o -o public12.x

public13.x: pq.o pqlist.o public13.o
	$(CC) pq.o pqlist.o public13.o -o public13.x

public14.x: pq.o pqlist.o public14.o
	$(CC) pq.o pqlist.o public14.o -o public14.x

public15.x: pq.o pqlist.o public15.o
	$(CC) pq.o pqlist.o public15.o -o public15.x

public01.o: free-string-array.h memory-checking.h public01.c 
	$(CC) -c $(CFLAGS) public01.c

public02.o: memory-checking.h pq.h public02.c
	$(CC) -c $(CFLAGS) public02.c

public03.o: pq.h memory-checking.h public03.c
	$(CC) -c $(CFLAGS) public03.c

public04.o: pq.h memory-checking.h public04.c
	$(CC) -c $(CFLAGS) public04.c

public05.o: pq.h memory-checking.h public05.c
	$(CC) -c $(CFLAGS) public05.c

public06.o: pq.h memory-checking.h public06.c
	$(CC) -c $(CFLAGS) public06.c

public07.o: pq.h check-string-arrays.h free-string-array.h memory-checking.h \
public07.c
	$(CC) -c $(CFLAGS) public07.c

public08.o: pq.h check-string-arrays.h free-string-array.h memory-checking.h \
public08.c
	$(CC) -c $(CFLAGS) public08.c

public09.o: pq.h check-string-arrays.h free-string-array.h memory-checking.h \
public09.c
	$(CC) -c $(CFLAGS) public09.c

public10.o: pq.h pqlist.h public10.c
	$(CC) -c $(CFLAGS) public10.c

public11.o: pq.h pqlist.h public11.c
	$(CC) -c $(CFLAGS) public11.c

public12.o: pq.h pqlist.h public12.c
	$(CC) -c $(CFLAGS) public12.c

public13.o: pq.h pqlist.h public13.c
	$(CC) -c $(CFLAGS) public13.c

public14.o: pq.h pqlist.h public14.c
	$(CC) -c $(CFLAGS) public14.c

public15.o: pq.h pqlist.h public15.c
	$(CC) -c $(CFLAGS) public15.c

clean:
	-rm -f  public01.o public02.o public03.o public04.o public05.o  *.x \
	public06.o public07.o public08.o public09.o public10.o public11.o \
	public12.o public13.o public14.o public15.o free-string-array.o \
	check-string-arrays.o pq.o pqlist.o
