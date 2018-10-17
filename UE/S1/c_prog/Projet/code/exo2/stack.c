#include <stdio.h>
#include <stdlib.h>
#include"stack.h"



stack new(){
    stack p;
    p.count=0;
    return p;
}

int is_empty(stack *p){
    return p->count;
}


int push(stack *p,int n){
    if(p->count>=20) return 0;
      p->value[p->count]=n;
      p->count++;
      return 1 ;

}
int pop(stack *p){
    p->count--;
    return p->value[p->count];

}

void printstack(stack p){
   
    while(is_empty(&p)){
        printf("%d\n",pop(&p));
    }
   
}

/*
ici je utilise le struct de stack , cest pour riveser les cours de TP et cest plus claire si je l'utilise pour conserver le result


*/
