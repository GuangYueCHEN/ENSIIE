#include"stack3.h"


/*
ici je utilise le struct de stack , cest pour riveser les cours de TP et cest plus claire si je l'utilise pour conserver le result


*/


stack new(){
    stack p;
    p.count=0;
    return p;
}

int is_empty(stack *p){
    return p->count;
}


int push(stack *p,int n){
    if(p->count>=4096) return 0;
    p->value[p->count]=n;
    p->count++;
    return 1 ;
    
}
int pop(stack *p){
    p->count--;
    return p->value[p->count];
    
}
stack inverse(stack *p){
    stack res=new();
    int x;
    while(is_empty(p)){
        x=pop(p);
        push(&res,x);
    }
    return res;
}

/*quand je print stack , je le change pour le bon resultat , quand je push le value , je push 1,2,3,4,5 pour representer le BAS HAUT....... * */
void printstack(stack *p){

    int x;
    while(is_empty(p)){
        x=pop(p);
        if(x==1)printf("BAS\n");
        if(x==2)printf("DROITE\n");
        if(x==3)printf("HAUT\n");
        if(x==4)printf("GAUCHE\n");
        if(x==5)printf("TP\n");
        
    }

}
