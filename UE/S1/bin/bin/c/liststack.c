#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct maillons* lstack;
 struct maillons{
        int value[20];
   int count;
	lstack next;
	};

 lstack newlstack(){
        lstack newl = (lstack)malloc(sizeof(struct maillons));
	newl->count=0;
	newl->next=NULL;
	return newl;
       }

 int stackisempty(lstack p){
        return p->count==0;
         }
int listisempty(lstack p){
  return p==NULL;
}

void push(lstack p,int a){
  p->value[p->count]=a;
  p->count++;
  printf("%d,",a);
    }

int pop(lstack p){
  p->count--;
  return p->value[p->count];
}

lstack addHead(lstack p,int pvalue[],int taille){
       lstack Head = (lstack)malloc(sizeof(struct maillons));
       int n;
       for(n=0;n<taille;n++)
	 push(Head,pvalue[n]);

       
       //Head->value = pvalue;
       Head->next = p;
       printf("list add sucess \n");
      
       
       return Head;
       }

lstack eaddHead(lstack *p,int pvalue[],int taille){
  *p=addHead(*p,pvalue,taille);
       }
  void printlist(lstack p){
       lstack print=p;
       while(!listisempty(print)){
	 printf("printliststack\n");
	 while(!stackisempty(print)){
	   // printf("ssssssssssssssss\n"); 
	   printf("%d , ",pop(print));

	 }
	 printf("\n");
	 print=print->next;
       }
       }

  int main(){
     lstack l=newlstack();
     int a1[10]={1,2,3,4,5,6,7,8,9,10};
     int a2[10]={11,12,13,14,15,16,17,18,19,20};
     int a3[10]={21,22,23,24,25,26,27,28,29,30};
     int a4[10]={31,32,33,34,35,36,37,38,39,40};
     int a5[10]={41,42,43,44,45,46,47,48,49,50};
     
     eaddHead(&l,a1,10);
     eaddHead(&l,a2,10);
     eaddHead(&l,a3,10);
     eaddHead(&l,a4,10);
     eaddHead(&l,a5,10);
     printlist(l);
     return 0;
    } 


