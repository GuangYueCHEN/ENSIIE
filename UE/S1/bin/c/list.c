#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct maillons* list;
 struct maillons{
        int value;
	list next;
	};
/*
 list  newlist(){
        list p;
        p->value =NULL;
        p->nest =NULL;
	return p;
	}
 */
 list newlist(){
       return NULL;
       }

 int isempty(list p){
        return p==NULL;
         }
 list addHead(list p,int pvalue){
       list Head = (list)malloc(sizeof(struct maillons));
       Head->value = pvalue;
       Head->next = p;
       printf("list add sucess \n %d\n",Head->value);
       return Head;
       }

  list eaddHead(list* p,int pvalue){
       *p=addHead(*p,pvalue);
       }
  void printlist(list p){
       list print=p;
       while(!isempty(print)){
      
       printf("%20d\n",print->value);
       print = print->next;
       }
       }
  int main(){
     list l=newlist();
     eaddHead(&l,2);
     eaddHead(&l,3);
     eaddHead(&l,4);
     eaddHead(&l,5);
     eaddHead(&l,6);
     printlist(l);
     return 0;
    } 


