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
    //printf("print stack--------------------------\n");
    while(is_empty(&p)){
        printf("%d\n",pop(&p));
    }
    //printf("end print----------------------------\n");
}


















void Dijkstra(int** matrix,int begin,int end,int N){ 
    
    if(begin==end){
        printf("%d\n",begin+1);
        return;
    }





    int j,i,k,n;  
    unsigned int mini;  
    int cannotfind=1;

    int *visited = (int *)calloc(N,sizeof(int));  
    unsigned int *distance = (unsigned int *)calloc(N,sizeof(unsigned int));  

    int *parent = (int *)calloc(N,sizeof(int));  
  
                //设置权值  
  
    for( i=0; i<N; i++ ) {  
      if(matrix[begin][i]!=-1) {
        distance[i] = matrix[begin][i];   //初始化为与顶点的距离  
        parent[i] = begin;  
        } else {
           distance[i] =INFINITY;  
           parent[i] = -1;
        }
     //printf("%d|", distance[i]); 
     //printf("%d|---", parent[i]); 
    }   //printf("\n"); 



    visited[begin] = 1;  
   

  
    for( i=0; i<N; i++ ) {  

        if(i==begin)i++;

        j = 0;  
        mini = INFINITY;  
  
        for( k=0; k<N; k++ )  
            if( (visited[k] == 0) && (distance[k] < mini) ) {  
                mini = distance[k];  
                j = k;          //j为刚刚找到的V-U中到源点路径最短的顶点  
            }  
          
        visited[j] = 1;
        if(j==end) {
            cannotfind=0;
        }

    /*   printf("!!!%d\n",j );
  for (n = 0; n < N; ++n)
  {
      printf("%d|%d|---",distance[n], parent[n]);
  } printf("\n" );
*/
        for( k=0; k<N; k++ )   {
            if( (0 == visited[k])&& matrix[j][k]!=-1 && (distance[k] > distance[j] + matrix[j][k] || distance[k]==INFINITY) ) {   //由于有顶点新加入U集合，对距离数组distance进行更新，比较原路径长度与以新加入的顶点为中间点的路径长度  
                distance[k] = distance[j] + matrix[j][k];   
                parent[k]=j;
                //printf("%d|%d|== ", distance[k],k);  
            } 
        } //printf("\n");
     
    }  
    if (cannotfind==1)
    {
        printf("can not find\n");
        return;
    }


    n=0;
    //printf("%d到%d的最短路径经过顶点依次为:\n", begin+1, end+1);  
    stack result=new();

    push(&result,end+1);
   // printf("%d ",end+1);

    for( i=end; i!=begin&&n<50; i=parent[i])  {
      //  printf("%d ", parent[i]+1); 
         push(&result,parent[i]+1);
         n++;
    }
 
    //printf("最短路径长度为: %d\n", mini); 
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
/*
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", matrix[i][j] );
    }printf("\n");
    }
    */

    Dijkstra(matrix,s,t,n);

    
	
    for(i = 0; i < n; i++) {
        free(matrix[i]);
	}
	
    free(matrix);
    return EXIT_SUCCESS;
}
