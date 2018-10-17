# ########################################## #

######  #     #   ###     #       #     ######                                  
#       ##    #  #   #                  #                                       
#       # #   #   #      ##      ##     #                                       
#####   #  #  #    #      #       #     #####                                   
#       #   # #     #     #       #     #                                       
#       #    ##  #   #    #       #     #                                       
######  #     #   ###   #####   #####   ######      

# ########################################## #


APPLI=exo2
CSRC= exo2.c stack.c   Dijkstra.c 
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
Dijkstra.o: Dijkstra.h stack.h

main.o: stack.h    Dijkstra.h

