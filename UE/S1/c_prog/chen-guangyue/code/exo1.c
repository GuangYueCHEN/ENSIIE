#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct stack
{
	int value[20];
	int count;
}stack;

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
		printf("%d\n",pop(&p)+1);
	}

}

/*
ici je utilise le struct de stack , cest pour riveser les cours de TP et cest plus claire si je l'utilise pour conserver le result


*/












/*je crée une fonction pour excuser le methode de  BFS * */

void BFSTraverse(int** matrix,int begin,int end,int N){
    int i,j,want;
 

 /* find cest les noeuds que j'ai visité ,Q cest comme open_table */
  int* Q=(int*) malloc(N* sizeof(int));
  int* find=(int*)calloc(N,sizeof(int));
   find[begin]=1;
    Q[0]=begin;  
    int first=-1,last=0,v;
    int cannotfind=1;  
    if(begin==end){
        cannotfind=0;
    }
    else{

         /*  quand first = last ca signifie j'ai ajouté tous les sommets ce que le 1er sommets peut arriver   */
         while(first!=last){   
        v=Q[++first];  
        

        for (i=0;i<N;i++){  

           

            if (matrix[v][i]==1)  {  
                if(find[i] == 0)  
                {  
                    Q[++last]=i;  
                    find[i] = 1;  
                    if(i==end){
                        cannotfind=0;  /* si je trouve le sommet que je veux , can not found =0 , et sort le cycle */
                        first=last;
                        break;

                    }    
                }  
            }   
        } 
    }
   


    }   
/*  si ne peut pas trouver */
 if(cannotfind==1){
 	printf("Not connected\n");
 	return;
 }



    stack result=new();
    push(&result,end);




    want = end;
/* je de le dernier à le permier ,si cest le rout ,je le conserver dans un stack , et quand je printf le stack , l'ordre  est inverse*/
while(want!=begin){ 

    for( i=0;i<N;i++)  
        {  
         j=Q[i];

            if (matrix[j][want]==1)  {
            	want=j;
            	push(&result,j);

            	break;
            }


    }


}

		free(find);


printstack(result);


}





int main() {
    int i,j;
    int n, s, t;
    scanf("%d",&n);
    int** matrix = (int**) malloc(n*sizeof(int*));

    for(i = 0; i < n; i++) {
        int* line = (int*) malloc(n * sizeof(int));
        matrix[i] = line;
        for(j = 0; j < n; j++) {
            scanf("%d", &line[j]);
		}
    }
	
    scanf("%d", &s);
    scanf("%d", &t);
    s--;
    t--;



int k;

int findNum=0;


BFSTraverse(matrix,s,t,n);





  
    for(i = 0; i < n; i++) {
		free(matrix[i]);
	}
	
    free(matrix);
    return EXIT_SUCCESS;
    
}
