
APPLI=prog
CSRC= evalution.c  lexeme.c   stack.c fichier.c
CC = gcc

CFLAGS = -Wall -Wextra -ansi -I. 

COBJ=$(CSRC:.c=.o)


.c.o:
	$(CC) $(CFLAGS) -c $*.c

$(APPLI):	$(COBJ)
	$(CC) -o $(APPLI) $(COBJ) -lm

clean:
	-rm *.o *[~%] core *.bak


# DO NOT DELETE

 evalution.o: evalution.h lexeme.h fichier.h stack.h
fichier.o: fichier.h
stack.o: stack.h

lexeme.o: lexeme.h
