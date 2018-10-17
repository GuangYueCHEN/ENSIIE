#include <stdio.h>
#include <stdlib.h>

typedef struct stack stack;
struct stack
{
	int value[20];
	int count;
};

stack new();


int is_empty(stack *p);


int push(stack *p,int n);

int pop(stack *p);

void printstack(stack p);
