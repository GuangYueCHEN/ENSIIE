#include"stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct pile{
int value[20];
int count;
};

stack stack_create(){
  stack p=(stack)malloc(sizeof(struct pile)) ;

   p->count = 0 ;
   
   return p;
   }
  

int is_empty(stack p){
      return p->count;
}


int pop(stack p){
    if(!is_empty) return 1;
    p->count--;
    return p->value[p->count];
    
}

int push(stack p,int x){
    if(p->count==20) return 1;
       p->value[p->count]=x;
    p->count++;
    return 0;
}


void print_stack(stack p){
   while(p->count!=0){
    p->count--;

    printf("%d\n",p->value[p->count]);
 }
}

void stack_delete(stack p){
  free(p);
}
