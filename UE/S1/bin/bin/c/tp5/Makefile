CC=gcc -Wall -Wextra -ansi

all: list_insertion list_merge
list_insertion.o: list.h
list_merge.o: list.h

list_insertion: list_insertion.o main.c
	$(CC) $^ -o $@

list_merge: list_merge.o main.c
	$(CC) $^ -o $@

clean:
	rm -rf *.o