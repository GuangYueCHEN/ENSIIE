#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct stack
{
    int value[2002];
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
    if(p->count>=2002) return 0;
      p->value[p->count]=n;
      p->count++;
      return 1 ;

}
int pop(stack *p){
    p->count--;
    return p->value[p->count];

}
stack inverse(stack *p){
    stack res=new();
    int x;
     while(is_empty(p)){
        x=pop(p);
        push(&res,x);
     }
    return res;
}

void printstack(stack *p){
    //printf("print stack--------------------------\n");
    int x;
    while(is_empty(p)){
        x=pop(p);
        //printf("%d",x );
        if(x==1)printf("down\n");
        if(x==2)printf("right\n");
        if(x==3)printf("up\n");
        if(x==4)printf("left\n");
        if(x==5)printf("tp\n");

    }
    //printf("end print----------------------------\n");
}




int noway(char (*matrix)[1002],int (*visited)[1002],int x,int y,int size){
    if(y==0&&x==0) return (matrix[x][y+1]=='X'||visited[x][y+1]!=0)&&(matrix[x+1][y]=='X'||visited[x+1][y]!=0);

    else if (y==0&&x==size-1) return (matrix[x][y+1]=='X'||visited[x][y+1]!=0)&&(matrix[x-1][y]=='X'||visited[x-1][y]!=0);

    else if (x==0&&y==size-1) return (matrix[x][y-1]=='X'||visited[x][y-1]!=0)&&(matrix[x+1][y]=='X'||visited[x+1][y]!=0);

    else if (x==size-1&&y==size-1) return (matrix[x][y-1]=='X'||visited[x][y-1]!=0)&&(matrix[x-1][y]=='X'||visited[x-1][y]!=0);

    else if (y==0) return (matrix[x][y+1]=='X'||visited[x][y+1]!=0)&&(matrix[x+1][y]=='X'||visited[x+1][y]!=0)&&(matrix[x-1][y]=='X'||visited[x-1][y]!=0);

    else if (y==size-1) return (matrix[x][y-1]=='X'||visited[x][y-1]!=0)&&(matrix[x+1][y]=='X'||visited[x+1][y]!=0)&&(matrix[x-1][y]=='X'||visited[x-1][y]!=0);

    else if (x==0) return (matrix[x][y+1]=='X'||visited[x][y+1]!=0)&&(matrix[x][y-1]=='X'||visited[x][y-1]!=0)&&(matrix[x+1][y]=='X'||visited[x+1][y]!=0);

    else if (x==size-1) return (matrix[x][y+1]=='X'||visited[x][y+1]!=0)&&(matrix[x][y-1]=='X'||visited[x][y-1]!=0)&&(matrix[x][y+1]=='X'||visited[x][y+1]!=0);

    else return (matrix[x][y+1]=='X'||visited[x][y+1]!=0)&&(matrix[x][y-1]=='X'||visited[x][y-1]!=0)&&(matrix[x+1][y]=='X'||visited[x+1][y]!=0)&&(matrix[x-1][y]=='X'||visited[x-1][y]!=0);
}




void findways(char (*matrix)[1002],int beginX,int beginY, int size,int timer){
   
    int i,j,k,tpi,tpj;
    int visited[1000][1002]={0};
    stack result;
    
    if(noway(matrix,visited,beginX,beginY,size)) printf("no way\n");
    else printf("OK I WILL  find it\n");


//int ii=0;
   
        result=new();

        i=beginX;j=beginY;

        //if(noway(matrix,visited,beginX,beginY,size)) printf("sorry i cant find it\n");

        printf("start------------\n");



        for(k=0;;){

            if(k>timer){
                k--;
                int h=k;







                
                printf("cannotfind\n");
                return;
            }

        /* ii++;
            if(ii==10){
                printf("error\n");
                return;
            }
*/
/*
        for ( tpi = 0; tpi < size; ++tpi)
        {
            for (tpj = 0; tpj < size; ++tpj)
            {
               printf("%c",  matrix[tpi][tpj]);
            }
            printf("\n");
        }

   
 */      printf("--------------------\n");
        for ( tpi = 0; tpi < size; ++tpi)
        {
            for (tpj = 0; tpj < size; ++tpj)
            {
               printf("%d",  visited[tpi][tpj]);
            }
            printf("\n");
        }printf("%d\n", k);
  


        if(matrix[i][j]=='S'){
         printf("finded!!!!!!!!!!!!\n");
                result=inverse(&result);
                printstack(&result);
                
                return ;
            }



            //down
            if(i!=size-1&&matrix[i+1][j]!='X'&&visited[i+1][j]==0){
           
                visited[i][j]=1;
                k++;
                i++;
                 push(&result,1);
                continue;
            }
 
            //right
            if(j!=size-1&&matrix[i][j+1]!='X'&&visited[i][j+1]==0){
           
                visited[i][j]=2;
                k++;
                j++;
                push(&result,2);
                continue;
            }


            //up
            if(i!=0&&matrix[i-1][j]!='X'&&visited[i-1][j]==0){
            
                visited[i][j]=3;
                k++;
                i--;
                 push(&result,3);
                continue;
            }



            //left
            if(j!=0&&matrix[i][j-1]!='X'&&visited[i][j-1]==0){
             
                visited[i][j]=4;
                k++;
                j--;
                 push(&result,4);
                continue;
            }
                           // tp
            int cannotfindTP=1;
            //printf("%d %d\n",i,j);
            if(matrix[i][j]=='*'){

                printf("TRY TO FIND TP\n+++++++++++++++");

                     for(tpi=0;tpi<size;tpi++){

                           for(tpj=0;tpj<size;tpj++){

                           // printf("%d",matrix[tpi][tpj]=='*'&&(tpi!=i&&tpj!=j)&&visited[tpi][tpj]==0);


                                  if(matrix[tpi][tpj]=='*'&&(tpi!=i&&tpj!=j)&&visited[tpi][tpj]==0){
                                
                                    visited[i][j]=5;
                                    i=tpi;
                                    j=tpj;
                                     push(&result,5);
                                     cannotfindTP=0;
                                     tpi=size+1;
                                    
                                  }
                              }
                          }

                    if(cannotfindTP==0) continue;


                
                     for(tpi=0;tpi<size;tpi++){
                           for(tpj=0;tpj<size;tpj++){

                                  if(matrix[tpi][tpj]=='*'&&visited[tpi][tpj]==5) {
                                    i=tpi;
                                    j=tpj;
                                    pop(&result);
                                    continue;
                                  }
                              }
                          }


            }



           


     



            //printf("%d %d %d\n",i,j,noway(matrix,visited,i,j,size));
            if(noway(matrix,visited,i,j,size)) {
                visited[i][j]=9;
               // printf("ssi lu\n");
                if(i!=0&&visited[i-1][j]==1){
                    i--;
                    k--;
                    pop(&result);

                }
                 else if(j!=0&&visited[i][j-1]==2){
                    j--;
                    k--;
                    pop(&result);
                
                }else  if(i!=size-1&&visited[i+1][j]==3){
                    i++;
                    k--;
                    pop(&result);
                }
                 else if(j!=size-1&&visited[i][j+1]==4){
                    j++;
                    k--;
                    pop(&result);
                }
                 


            }

        }
        
   

       /* for ( tpi = 0; tpi < size; ++tpi)
        {
            for (tpj = 0; tpj < size; ++tpj)
            {
               visited[tpi][tpj]=0;
            }
        }*/



   // }



}


int main() {
    int n;
	char matrix[1000][1002] = { "" };
	int i;
	int timer;
	
    scanf("%d",&n);
	fgetc(stdin);
    
    for(i = 0; i < n; i++) {
        fgets(matrix[i], 1002, stdin);
    }

    scanf("%d", &timer);
    fgetc(stdin);

     int beginX,beginY;


    for(i=0;i<size;i++){

        for(j=0;j<size;j++){
            if(matrix[i][j]=='E') {
                beginX=i;
                beginY=j;
            }

        }
    }

  findways(matrix,beginX,beginY,n,timer);

    return EXIT_SUCCESS;
}
