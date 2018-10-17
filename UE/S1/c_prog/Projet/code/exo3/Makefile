# ########################################## #

######  #     #   ###     #       #     ######                                  
#       ##    #  #   #                  #                                       
#       # #   #   #      ##      ##     #                                       
#####   #  #  #    #      #       #     #####                                   
#       #   # #     #     #       #     #                                       
#       #    ##  #   #    #       #     #                                       
######  #     #   ###   #####   #####   ######      

# ########################################## #


APPLI=exo3
CSRC= exo3.c stack.c   astar.c 
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
astar.o: astar.h stack.h

main.o: stack.h    astar.h

