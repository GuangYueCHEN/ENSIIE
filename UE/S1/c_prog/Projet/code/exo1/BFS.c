#include "FFS.h"
#include "stack.h"
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
