# Makefile with variables
P=main
OBJECTS=	main.o	dll.o
CFLAGS	=	-g	-Wall	-O3
LDLIBS =
CC=gcc
# Generate application
$(P):	$(OBJECTS)
	$(CC)	$(CFLAGS)	-o	$(P)	$(OBJECTS)
# Generate dll.o
dll.o:	dll.c	dll.h
	$(CC)	$(CFLAGS)	-c	dll.c
# Generate main.o
main.o:	main.c	dll.h
	$(CC)	$(CFLAGS)	-c	main.c
clean:
	rm	*.o	$(P)