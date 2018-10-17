#include <stdio.h>
#include <stdlib.h>

#define INFINITY 4294967295
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
        printf("%d\n",pop(&p));
    }
   
}

/*
ici je utilise le struct de stack , cest pour riveser les cours de TP et cest plus claire si je l'utilise pour conserver le result


*/














/*je crée une fonction pour excuser le methode de  Dijkstra * */


void Dijkstra(int** matrix,int begin,int end,int N){ 
    
    if(begin==end){
        printf("%d\n",begin+1);
        return;
    }
    





    int j,i,k,n;  
    unsigned int mini;  
    int cannotfind=1;

/*deux table pour montrer le sommets si j'ai 'visited' et distince de ce sommet à le 1er  * */
    int *visited = (int *)calloc(N,sizeof(int));  
    unsigned int *distance = (unsigned int *)calloc(N,sizeof(unsigned int));  

    int *parent = (int *)calloc(N,sizeof(int));  
  
             
  
/*pour insert tous les distince des sommets sont infini * */
    for( i=0; i<N; i++ ) {  
      if(matrix[begin][i]!=-1) {
        distance[i] = matrix[begin][i];   
        parent[i] = begin;  
        } else {
           distance[i] =INFINITY;  
           parent[i] = -1;
        }
     
    }   



    visited[begin] = 1;  
   

  
/*  */
    for( i=0; i<N; i++ ) {  

        if(i==begin)i++;

        j = 0;  
        mini = INFINITY;  
  


/*trouver le plus cous distince sommets , l'utiliser en le mettant dans le table 'visited'* */
        for( k=0; k<N; k++ )  
            if( (visited[k] == 0) && (distance[k] < mini) ) {  
                mini = distance[k];  
                j = k;        
            }  
          
        visited[j] = 1;
        if(j==end) {
            cannotfind=0;
        }


/*si le distince est plus court,est cest pas dans le table 'visited' , je corriger le distince * */
        for( k=0; k<N; k++ )   {
            if( (0 == visited[k])&& matrix[j][k]!=-1 && (distance[k] > distance[j] + matrix[j][k] || distance[k]==INFINITY) ) {  
                distance[k] = distance[j] + matrix[j][k];   
                parent[k]=j;
                
            } 
        } 
     
    }  

/*si trouve pas * */
    if (cannotfind==1)
    {
        printf("Not connected\n");
        return;
    }


    n=0;
    
    stack result=new();

    push(&result,end+1);


/*comme le pécédent , je conserve les resultat de le dernier à le 1er , dans un stack , apres je printstack , l'ordre est inverse  * */
    for( i=end; i!=begin&&n<50; i=parent[i])  {

         push(&result,parent[i]+1);
         n++;
    }
 
 
     printstack(result);


    free(visited);

    free(parent);
      
    free(distance);

} 
 






int main() {
  
    int n, s, t;
	scanf("%d",&n);
    int ** matrix = (int**) malloc(n*sizeof(int*));
    int i,j;
	
    for(i = 0; i < n; i++) {
        int* line = (int*) malloc(n * sizeof(int));
        matrix[i] = line;
        for(j = 0; j < n; j++) {
            scanf("%d", &line[j]);
		}
    }


	
    scanf("%d", &s);
    scanf("%d", &t);
    s=s-1;
    t=t-1;


    Dijkstra(matrix,s,t,n);

    
	
    for(i = 0; i < n; i++) {
        free(matrix[i]);
	}
	
    free(matrix);
    return EXIT_SUCCESS;
}
