# ########################################## #

######  #     #   ###     #       #     ######                                  
#       ##    #  #   #                  #                                       
#       # #   #   #      ##      ##     #                                       
#####   #  #  #    #      #       #     #####                                   
#       #   # #     #     #       #     #                                       
#       #    ##  #   #    #       #     #                                       
######  #     #   ###   #####   #####   ######      

# ########################################## #


APPLI=exo1
CSRC= exo1.c stack.c   BFS.c 
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


stack.o: stack.h
BFS.o: FFS.h stack.h

main.o: stack.h    FFS.h 

