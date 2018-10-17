#include"Dijkstra.h"
#include"stack2.h"
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
 


