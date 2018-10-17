#include<stdio.h>

typedef struct pile{
int value[20];
int count;
}pile;

pile new(){
   pile p ;

   p.count = 0 ;
   
   return p;
   }
  

int is_empty(pile p){
      return p.count;
}


int pop(pile* p){
    if(!is_empty) return 1;
    p->count--;
    return p->value[p->count];
    
}

int push(pile* p,int x){
    if(p->count==20) return 1;
       p->value[p->count]=x;
    p->count++;
    return 0;
}


void print_pile(pile p){
   while(p.count!=0){
    p.count--;

    printf("%d\n",p.value[p.count]);
 }
}


void encoreTop(pile* p){
 int i=p->value[p->count-1];
     push(p,i-1);
}


int produit2(pile p){
  if (!is_empty(p)) return 1;
  return pop(&p)*produit2(p);
 
}

int produit(pile p){
   int pro =1;
   while(is_empty(p)){
    pro*= pop(&p);
    }

  return pro;

}
int* max(double a,double b){
      if(a>=b) return &a;
      else return &b;
      }

pile* MAX(pile)

int main(){
 pile p1;
p1=new();
print_pile(p1);
int j;
printf("combien\n");
scanf("%d",&j);
int i;
printf("voila\n");
for(i=0;i<j;i++){
 int y ;
scanf("%d",&y);
if(push(&p1,y)==1) break;
}
printf("produit\n");
printf("%d\n",produit(p1));
printf("%d\n",produit2(p1));
//printf("encore top-1\n");
//encoreTop(&p1);

//print_pile(p1);

return 0;
}

