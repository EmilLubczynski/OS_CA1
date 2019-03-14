CFLAGS = -c -Wall
CC = gcc
DISTDIR = dist
LIBDIR = lib
OBJECTS = $(DISTDIR)/solution.o\
	  $(DISTDIR)/my-functions.o

link: $(OBJECTS)
	$(CC) $? -o $(DISTDIR)/solution

$(DISTDIR)/solution.o: solution.c
	$(CC) $(CFLAGS) $? -o $(DISTDIR)/solution.o

dist/my-functions.o: $(LIBDIR)/my-functions.c
	$(CC) $(CFLAGS) $? -o $(DISTDIR)/my-functions.o

clean:
	rm -rf ./$(DISTDIR) && mkdir ./$(DISTDIR)
