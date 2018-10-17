#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack
{
    int value[4096];
    int count;
}stack;
stack new();
int is_empty(stack *p);
int push(stack *p,int n);
int pop(stack *p);
stack inverse(stack *p);
void printstack(stack *p);