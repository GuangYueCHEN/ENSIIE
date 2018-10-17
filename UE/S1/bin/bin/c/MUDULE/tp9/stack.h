#ifndef _STACK_H
#define _STACK_H

typedef struct pile * stack ;

stack stack_create();
  

int is_empty(stack );

int pop(stack  );

int push(stack  ,int );


void print_stack(stack);

void stack_delete(stack);
#endif
