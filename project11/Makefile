CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -fstack-protector-all -Werror -Wshadow -g

all: public01.x public02.x public03.x public04.x public05.x public06.x \
public07.x public08.x public09.x public10.x

sss.o: sss.c sss.h safe-fork.h split.h
	$(CC) -c $(CFLAGS) sss.c

public01.x: sss.o public01.o
	$(CC) sss.o safe-fork.o split.o public01.o -o public01.x

public02.x: sss.o public02.o
	$(CC) sss.o safe-fork.o split.o public02.o -o public02.x

public03.x: sss.o memory-checking.o public03.o
	$(CC) sss.o safe-fork.o split.o memory-checking.o public03.o -o\
	public03.x

public04.x: sss.o public04.o
	$(CC) sss.o public04.o safe-fork.o split.o -o public04.x

public05.x: sss.o public05.o
	$(CC) sss.o public05.o safe-fork.o split.o -o public05.x

public06.x: sss.o  memory-checking.o public06.o
	$(CC) sss.o public06.o safe-fork.o  memory-checking.o split.o -o \
	public06.x

public07.x: sss.o public07.o
	$(CC) sss.o public07.o safe-fork.o split.o -o public07.x

public08.x: sss.o public08.o
	$(CC) sss.o public08.o safe-fork.o split.o -o public08.x

public09.x: sss.o public09.o
	$(CC) sss.o public09.o safe-fork.o split.o -o public09.x

public10.x:sss.o public10.o
	$(CC) sss.o public10.o safe-fork.o split.o -o public10.x

public01.o: sss.h public01.c 
	$(CC) -c $(CFLAGS) public01.c

public02.o: sss.h public02.c
	$(CC) -c $(CFLAGS) public02.c

public03.o: sss.h memory-checking.h public03.c
	$(CC) -c $(CFLAGS) public03.c

public04.o: sss.h public04.c
	$(CC) -c $(CFLAGS) public04.c

public05.o:sss.h public05.c
	$(CC) -c $(CFLAGS) public05.c

public06.o: sss.h memory-checking.h public06.c
	$(CC) -c $(CFLAGS) public06.c

public07.o: sss.h public07.c
	$(CC) -c $(CFLAGS) public07.c

public08.o: sss.h public08.c
	$(CC) -c $(CFLAGS) public08.c

public09.o: sss.h public09.c
	$(CC) -c $(CFLAGS) public09.c

public10.o: sss.h public10.c
	$(CC) -c $(CFLAGS) public10.c

clean:
	-rm -f  public01.o public02.o public03.o public04.o public05.o  *.x \
	public06.o public07.o public08.o public09.o public10.o sss.o
