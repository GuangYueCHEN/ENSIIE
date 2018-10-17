
APPLI=tp9
CSRC= evalution.c  lexeme.c   stack.c  fichier.c
CC = gcc

CFLAGS = -Wall -Wextra -ansi -I. 

COBJ=$(CSRC:.c=.o)


.c.o:
	$(CC) $(CFLAGS) -c $*.c

$(APPLI):	$(COBJ)
	$(CC) -o $(APPLI) $(COBJ) -lm

clean:
	-rm *.o *[~%] core *.bak




evalution.o: evalution.h lexeme.h fichier.h stack.h
fichier.o: fichier.h
stack.o: stack.h
lexeme.o: lexeme.h
