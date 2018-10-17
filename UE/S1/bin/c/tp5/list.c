#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
# define ABS(V) ((V) < 0 ? -(V) : (V))
typedef struct node* list;
struct node
{
	list next;
	double value;
};


list create_list(){
	return NULL;
}

int list_isEmpty(list l){
	return l==NULL;
}


list list_vAdd(double value, list l){
	list newlist = (list)malloc(sizeof(struct node));
    newlist->value=value;
    newlist->next=l;
    return newlist;
}

void list_eAdd(list* pl, double value){
  *pl=list_vAdd(value,*pl);
}

void list_print(list l){
	list pl = l;
	while(pl!=NULL){
		printf("%lf\n", pl->value);
		pl=pl->next;
	}
}

int list_count(list l){
	int i=0;
	/*list newlist = (list)malloc(sizeof(struct lain));*/
	while(l!=NULL){
         l=l->next;
         i++;
	}
	return i;
}

int list_sum(list l, double* ret){
	*ret=0;
	list pl=l;
	while(pl!=NULL){
		*ret+=pl->value;
		pl=pl->next;
	}
	return (int)*ret;
}
list inverse(list l){
    list pl=NULL;
    while(l!=NULL){
    list_eAdd(&pl,l->value);
    l=l->next;
    }
    return pl ;
}
void list_reverse(list* pl){
	*pl=inverse(*pl);
}

int ise(double x){
	if(ABS(x) < 10e-20) return 1;
	else return 0;
}


/*int list_find(list l, double value, double* ret);
//int list_elementAt(list l, int index, double* ret);*/




int list_remove(list* pl,double value){
  list ml = create_list();
   list l=*pl;
   ml=l->next;

         if(ise(ml->value-value)){
	   
            while(ml!=NULL&&ise(ml->value-value)) ml=ml->next;


         	if(ml==NULL) l->next=NULL;
         		else l->next=ml; 
               }
	 *pl=l;
	 return 0;
}

list list_delete(list l,double value){
   list lx = (list)malloc(sizeof(struct node));
   lx->next=l;
   list ls=lx;


	while(ls->next!=NULL){
    

         
	  list_remove(&ls,value);


         if(ls->next==NULL) return lx->next;
         		else ls=ls->next;
	}return lx->next;


}
int list_removeAll(list* pl,double value){
  
    list lx = (list)malloc(sizeof(struct node));
   lx->next=*pl;
   list ls=lx;


	while(ls->next!=NULL){
    

         
	  list_remove(&ls,value);


	 if(ls->next==NULL){
	    *pl= lx->next;
	    return 0;
	  }
       	else ls=ls->next;
	}
	*pl=lx->next;


  return 0;
}


list sort(list l){
   list lx = (list)malloc(sizeof(struct node));
   list lnext = (list)malloc(sizeof(struct node));
   list lp = (list)malloc(sizeof(struct node));
   list lsave = (list)malloc(sizeof(struct node));
   list linser = (list)malloc(sizeof(struct node));
   list linsertnext = (list)malloc(sizeof(struct node));
   
   lx->next=l;
   lp=lx->next;
  lnext=lp->next;

   int n=list_count(l);
   int i;
   int x;
   int y;

   for(i=1;i<n;i++){/*从第二个开始插入*/
 	linser=lx;
     linsertnext=lx->next;

   for(x=0;x<i;x++){

   	if(lnext->value>linsertnext->value){
   		linser=linser->next;
   		linsertnext=linser->next;
	}/*寻找插入点*/
   	else break;

   	}
   if(x==i){/*如果要插入的值最大表不变*/
        	lnext=lnext->next;
        }
        else{
        	lp=lx;
        for(y=0;y<i;y++)lp=lp->next;  lsave=lnext->next;  lp->next=lsave; 
        linser->next=lnext;/*insert*/
        lnext->next=linsertnext;
   		lnext=lsave;
   	}
  }
return lx->next;
}


/*int main() {
	list l = create_list();

	int i;

	//srand(time(NULL));
	srand(42);
	for (i = 0; i <10000; i++) {
		
		list_eAdd(&l, rand()%1000000 / (double)(rand()%1000000+1));
	}
        
	list_removeAll(&l,40.0);
		list_sort(&l);
	list_print(l);
	list_removeAll(&l,40.0);
	
	return EXIT_SUCCESS;
}*/
