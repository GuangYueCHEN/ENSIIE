#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct lain* list;
struct lain
{
	list next;
	double value;
};

list new(){
	return NULL;
}

int isempty(list l){
	return l==NULL;
}

void printlist(list l){
	list pl = l;
	while(pl!=NULL){
		printf("%.0lf\n", pl->value);
		pl=pl->next;
	}
}


list addhead(list l,double num){
	list newlist = (list)malloc(sizeof(struct lain));
    newlist->value=num;
    newlist->next=l;
    return newlist;
}

void list_addhead(list* pl,double num){
	*pl=addhead(*pl,num);
}

int taille(list l){
	int i=0;
	//list newlist = (list)malloc(sizeof(struct lain));
	while(l!=NULL){
         l=l->next;
         i++;
	}
	return i;
}

double somme(list l){
	double sum=0;
	list pl=l;
	while(pl!=NULL){
		sum+=pl->value;
		pl=pl->next;
	}
	return sum;
}

list inverse(list l){
    list pl=NULL;
    while(l!=NULL){
    list_addhead(&pl,l->value);
    l=l->next;
    }
    return pl ;
}
void list_inverse(list* pl){
	*pl=inverse(*pl);
}


int ise(double e){
	if(e>=10&&e<=20) return 1;
	else return 0;
}



list isel(list l){
	list pl = NULL;
	while(l!=NULL){
         if(!ise(l->value)){list_addhead(&pl,l->value); }
         l=l->next;
	}
	return pl;
}


void deletenext(list l ){
	list ml = new();
	
		ml=l->next;

         if(ise(ml->value)){
            while(ml!=NULL&&ise(ml->value)) ml=ml->next;


         	if(ml==NULL) l->next=NULL;
         		else l->next=ml; 
               }
        
}


list list_delete(list l){
   list lx = (list)malloc(sizeof(struct lain));
   lx->next=l;
   list ls=lx;


	while(ls->next!=NULL){
    

         
         deletenext(ls);


         if(ls->next==NULL) return lx->next;
         		else ls=ls->next;
	}return lx->next;

}


list sort(list l){
   list lx = (list)malloc(sizeof(struct lain));
   list lnext = (list)malloc(sizeof(struct lain));
   list lp = (list)malloc(sizeof(struct lain));
   list lsave = (list)malloc(sizeof(struct lain));
   list linser = (list)malloc(sizeof(struct lain));
   list linsertnext = (list)malloc(sizeof(struct lain));
   
   lx->next=l;
   lp=lx->next;
  lnext=lp->next;

   int n=taille(l);
   int i;
   int x;
   int y;

 for(i=1;i<n;i++){//从第二个开始插入
 	linser=lx;
     linsertnext=lx->next;

   for(x=0;x<i;x++){

   	if(lnext->value>linsertnext->value){
   		linser=linser->next;
   		linsertnext=linser->next;
   	   }//寻找插入点
   	else break;

   	}
        if(x==i){//如果要插入的值最大表不变
        	lnext=lnext->next;
        }
        else{
        	lp=lx;
        for(y=0;y<i;y++)lp=lp->next;  lsave=lnext->next;  lp->next=lsave; //连接表尾

        linser->next=lnext;//insert
        lnext->next=linsertnext;
   		lnext=lsave;
   	}
  }
return lx->next;
}







int main(){
	list l = new();
	list tl = new();
	list xl = new();
	list_addhead(&l,13);
	list_addhead(&l,4);
	list_addhead(&l,5);
	list_addhead(&l,15);
	list_addhead(&l,52);
	list_addhead(&l,12);
	list_addhead(&l,14);
	list_addhead(&l,16);
	list_addhead(&l,20);
	list_addhead(&l,25);
	list_addhead(&l,53);
	list_addhead(&l,11);

printf("%d个\n",taille(l) );
printf("%.0lf和\n",somme(l) );

printlist(l);
printf("xxxxxxxxxxxxx\n");
//list_inverse(&l);
//printlist(l);
//printf("xxxxxxxxxxxxx\n");
//tl=isel(l);
//printlist(tl);
//printf("xxxxxxxxxxxxx\n");
//xl=l;
//xl=list_delete(xl);
//printlist(xl);
xl=sort(l);
printlist(xl);
return 0;

}











