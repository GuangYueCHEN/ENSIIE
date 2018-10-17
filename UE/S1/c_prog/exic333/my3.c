 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct stack
{
    int value[4096];
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
    if(p->count>=4096) return 0;
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
    /*printf("print stack--------------------------\n");*/
    int x;
    while(is_empty(p)){
        x=pop(p);
        if(x==1)printf("down\n");
        if(x==2)printf("right\n");
        if(x==3)printf("up\n");
        if(x==4)printf("left\n");
        if(x==5)printf("tp\n");

    }
    /*printf("end print----------------------------\n");*/
}



typedef struct node{
    int F;
    int H;
    int G;
    int x,y;
    char sym;
    struct node * parent;
    int is_in_closed;
    int is_in_open;
}node;
static int count_open;

   char tp ;

void printnode(node n){
    printf("--%d %d %d %d %d|||", n.G,n.H,n.F,n.is_in_open,n.is_in_closed);
}


int distance(int i,int j,int x,int y){
    int m=i-x;
    if(m<0)m=-m;
    int n=j-y;
    if(n<0)n=-n;
    return 10*(m+n);
}


node * insert_to_opentable( node ** Amap,node * open_table, int x, int y, node * curr_node,  int w )  
{  
    int i; node * cur2=Amap[x][y].parent;
    if( Amap[x][y].sym != 'X' )        
    {  
        if ( Amap[x][y].is_in_closed==0)  
        {   
            if ( Amap[x][y].is_in_open==1) 
            {  
                /*   milleur path   */   
                if ( Amap[x][y].G > curr_node->G + w )    
                {  
                    Amap[x][y].G = curr_node->G + w;  
                    Amap[x][y].parent = curr_node;  
                    cur2=Amap[x][y].parent;

                } 
            }  
            else     /*ajouter au 'open table' */                       
            {  
               
                 


                Amap[x][y].G = curr_node->G + w;   
                Amap[x][y].parent = curr_node;
                count_open++;
                Amap[x][y].is_in_open = 1;
                Amap[x][y].F=Amap[x][y].G +Amap[x][y].H;
                open_table[count_open] = Amap[x][y];  
                 cur2=Amap[x][y].parent;
                /*   juste pout tester ,on s'en fou!
                printnode(Amap[x][y]);
                printf("添加成功了%d，%d他的父亲是", x+1,y+1);

              
                printnode(*cur2);


                */

            }  
        }  
    }
    


    return cur2;
} 










int A(char (*matrix)[1002],char begin,char end,int size,int timer){
   
    int beginX,beginY,endX,endY;
    int have_key;
    int i,j;


 node **Amap = (node**)malloc(sizeof(node*)*size);  
  
    for(int i = 0; i < size;i++)  
    {  
        Amap[i] = (node*)malloc(sizeof(node)*size);  
    } 

 node * open_table=(node*)malloc(sizeof(node)*size*size);

    for(i=0;i<size;i++){

        for(j=0;j<size;j++){
            if(matrix[i][j]==begin) {
                beginX=i;
                beginY=j;
            }else if(matrix[i][j]==end) {
                endX=i;
                endY=j;
            }

        }
    }


    for(i=0;i<size;i++){

        for(j=0;j<size;j++){
            Amap[i][j].sym=matrix[i][j];
           if(matrix[i][j]=='X')continue;
           Amap[i][j].G=0;
           Amap[i][j].H=distance(i,j,endX,endY);
           Amap[i][j].F=0;
           Amap[i][j].parent=NULL;
           Amap[i][j].is_in_open=0;
           Amap[i][j].is_in_closed=0;    /* closed */
           Amap[i][j].y=j;
           Amap[i][j].x=i;
            if(matrix[i][j]==begin) {
              Amap[i][j].is_in_open=1; /* openset := set containing the initial node */
              count_open=1;
              open_table[0]=Amap[i][j];
            }

        }
    }

node min=open_table[0];
int is_found=0;
int x,y;
node cur3;
int k;

while(count_open!=0){   /*while openset is not empty              */
k=0;
count_open--;



min=open_table[0];
   /*pour  trouver le min  */
for(i=count_open;i>=0;i--){
   /* printnode(open_table[i]);printf("%d %d\n",open_table[i].x+1,open_table[i].y+1 );*/

   if(min.F>=open_table[i].F){
    min=open_table[i];
    k=i;
   }
}/*printf("\n  and min is");printnode(min);printf("\n");*/



if(min.H==0){
    is_found=1;/* printf("found\n");*/
    break;
   
}



x=min.x;
y=min.y;
/* ajouter les neiber*/

if ( ( x + 1 ) >= 0 && ( x + 1 ) < size && y >= 0 && y < size )  
    {  
        Amap[x+1][y].parent = insert_to_opentable( Amap,open_table,x+1, y, &Amap[x][y], 10 ); 

        
    }  
  
    if ( ( x - 1 ) >= 0 && ( x - 1 ) < size && y >= 0 && y < size)  
    {  
        Amap[x-1][y].parent = insert_to_opentable(Amap,open_table, x-1, y, & Amap[x][y],  10 );  
    
    }  
  
    if ( x >= 0 && x < size && ( y + 1 ) >= 0 && ( y + 1 ) < size )  
    {  
        Amap[x][y+1].parent = insert_to_opentable( Amap,open_table,x, y+1, &Amap[x][y],  10 );  
     
    }  
  
    if ( x >= 0 && x < size && ( y - 1 ) >= 0 && ( y - 1 ) < size )  
    {  
        Amap[x][y-1].parent = insert_to_opentable( Amap,open_table, x, y-1,  &Amap[x][y],  10 );  
   
    }  
  
    if ( ( x + 1 ) >= 0 && ( x + 1 ) < size && ( y + 1 ) >= 0 && ( y + 1 ) < size &&(matrix[x+1][y]!='X'||matrix[x][y+1]!='X') )  
    {  
        Amap[x+1][y+1].parent = insert_to_opentable( Amap,open_table,x+1, y+1,  &Amap[x][y],  14 );  
    }  
  
    if ( ( x + 1 ) >= 0 && ( x + 1 ) < size && ( y - 1 ) >= 0 && ( y - 1 ) < size&&(matrix[x+1][y]!='X'||matrix[x][y-1]!='X') )  
    {  
        Amap[x+1][y-1].parent = insert_to_opentable( Amap,open_table,x+1, y-1,  &Amap[x][y],  14 );  
    }  
  
    if ( ( x - 1 ) >= 0 && ( x - 1 ) < size && ( y + 1 ) >= 0 && ( y + 1 ) < size&&(matrix[x-1][y]!='X'||matrix[x][y+1]!='X') )  
    {  
        Amap[x-1][y+1].parent = insert_to_opentable( Amap,open_table,x-1, y+1,  &Amap[x][y],  14 );  
    }  
  
    if ( ( x - 1 ) >= 0 && ( x - 1 ) < size && ( y - 1 ) >= 0 && ( y - 1 ) < size &&(matrix[x-1][y]!='X'||matrix[x][y-1]!='X'))  
    {  
        Amap[x-1][y-1].parent = insert_to_opentable( Amap,open_table,x-1, y-1,  &Amap[x][y],  14 );  
    }  

   tp = matrix[x][y] ;

    if(tp == '*' || tp == '%'|| tp == '$'|| tp == '#'|| tp =='&'|| tp =='+'|| tp =='-'|| tp =='@'|| tp =='^') {
        /*printf("TRY TO FIND TP\n+++++++++++++++");*/
        int tpi,tpj;
       
                     for(tpi=0;tpi<size;tpi++){

                           for(tpj=0;tpj<size;tpj++){



                         if(matrix[tpi][tpj]==tp&&(tpi!=x&&tpj!=y)&&Amap[tpi][tpj].is_in_closed!=1){
                                

                               Amap[tpi][tpj].parent=insert_to_opentable( Amap,open_table,tpi, tpj,  &Amap[x][y],  0);
                               Amap[x][y].sym='.';
                                
                                    
                                  }
                              }
                          }

                   



    }


    Amap[x][y].is_in_closed=1;
    Amap[x][y].is_in_open=0;
   /* printf("%c\n", Amap[x][y].sym);
Amap[x][y].sym='0';*/

/*
printf("\nsadsadasdasdsadasdsadsadsadsadsadsadasd\n");       
   for(i=0;i<size;i++){

        for(j=0;j<size;j++){
            if(Amap[i][j].parent!=NULL)printnode(*Amap[i][j].parent);
            else printf("       X X       ");
        }printf("\n");
     }
printf("\nsadsadasdasdsadasdsadsadsadsadsadsadasd\n");






printf("------------------------\n");

   printf("%d %d\n",count_open,k );
printf("<<<<<<<<<<<<<<<<<<<<<<\n");
    printnode(min);
    printnode(open_table[count_open]);
       printnode(open_table[k]);
    printf("!!!");
    for(i=0;i<=count_open;i++)printnode(open_table[i]);
    printf("\nparrrrrrrrrrrrrr\n");
    if(open_table[count_open].parent!=NULL)printnode(*open_table[count_open].parent);
    printf("!!!");



    printf("<<<<<<<<<<<<<<<<<<<<<\n");
*/
    






    
    cur3= open_table[count_open];
    open_table[count_open] = open_table[k];  
    open_table[k]= cur3;  
    
 




  
/*
   printf("\n>>>>>>>>>>>>>>>>>>\n");
    printnode(min);
    printnode(open_table[count_open]);
    printnode(open_table[k]);
    printf("!!!");for(i=0;i<=count_open;i++)printnode(open_table[i]);
    printf("\nparrrrrrrrrrrrrr\n");
    if(open_table[count_open].parent!=NULL)printnode(*open_table[count_open].parent);
       printf("!!!");



    printf(">>>>>>>>>>>>>>>>\n");
    printf("\nsadsadasdasdsadasdsadsadsadsadsadsadasd\n");       
   for(i=0;i<size;i++){

        for(j=0;j<size;j++){
            if(Amap[i][j].parent!=NULL)printnode(*Amap[i][j].parent);
            else printf("       X X       ");
        }printf("\n");
     }
printf("\nsadsadasdasdsadasdsadsadsadsadsadsadasd\n");




printf("------------------------\n");
*/
}
node parent; int time=0;
if ( is_found)  
    {  
        stack result=new();

      cur3=Amap[endX][endY];

      while(cur3.parent!=NULL){
       parent=*cur3.parent;         
          x=cur3.x - parent.x;
          y=cur3.y - parent.y;
          tp=Amap[cur3.x][cur3.y].sym;
         
       if(distance(parent.x,parent.y,cur3.x,cur3.y)==2){

        time=time+2;


          if(Amap[cur3.x-1][cur3.y].sym!='X'&&y==1&&x==1){
             push(&result,1);
             push(&result,2);
          }else if(Amap[cur3.x][cur3.y-1].sym!='X'&&y==1&&x==1){

             push(&result,2);
             push(&result,1);

           }else if(Amap[cur3.x+1][cur3.y].sym!='X'&&y==1&&x==-1){
           
            push(&result,4);
             push(&result,1);

           }else if(Amap[cur3.x+1][cur3.y-1].sym!='X'&&y==1&&x==-1){

            push(&result,1);
             push(&result,4);

           }else if(Amap[cur3.x-1][cur3.y].sym!='X'&&y==-1&&x==1){

            push(&result,2);
             push(&result,3);

           }else if(Amap[cur3.x][cur3.y+1].sym!='X'&&y==-1&&x==1){
            push(&result,3);
             push(&result,2);

           }else if(Amap[cur3.x+1][cur3.y].sym!='X'&&y==-1&&x==-1){

            push(&result,3);
             push(&result,4);

           }else if(Amap[cur3.x+1][cur3.y].sym!='X'&&y==-1&&x==-1){

            push(&result,4);
             push(&result,3);

           }


      }else if(tp == '*' ||tp == '%'||tp == '$'||tp == '#'||tp == '&'||tp == '+'||tp == '-'||tp == '@'||tp == '^'){
       
         push(&result,5);
   

      } else{

        if(x==1)push(&result,1);
        if(x==-1)push(&result,3);
        if(y==1)push(&result,2);
            if(y==-1)push(&result,4);
         time++;
    }
     cur3=*cur3.parent;

    }
    /*printf("%d %d\n",result.count ,timer);*/
     if(time<=timer){
        printstack(&result);
         return time;
    }
     else {
      printf("so far\n");  
      return 0;
     
    }



    }  
    else  
    {  
        printf("no path\n");  



/*
 for(i=0;i<size;i++){

        for(j=0;j<size;j++){
      printf("%c", Amap[i][j].sym);

     }printf("\n");

}*/
 

     printf("\n");
        return 0;
    }  




   



}







int main() {
    int n;
    char matrix[1000][1002] = { "" };
    int i,j;
    int timer;
    
    scanf("%d",&n);
    fgetc(stdin);
    
    for(i = 0; i < n; i++) {
        fgets(matrix[i], 1002, stdin);
    }
    
    scanf("%d", &timer);
    fgetc(stdin);
    int have_door=0;
    for(i=0;i<n;i++){
        for (int j = 0; j < n; j++)
        {
            if(matrix[i][j]=='A'){
                have_door=1;
                break;
            }
        }
    }
    int acc;
    if(have_door==1){
        acc=A(matrix,'E','a',n,timer);
        if(acc==0) return 1;
        timer=timer-acc;
        acc=A(matrix,'a','A',n,timer);
        if(acc==0) return 1;
        timer=timer-acc;
        acc=A(matrix,'A','S',n,timer);
if(acc==0) return 1;
    }

    else acc=A(matrix,'E','S',n,timer);

    return EXIT_SUCCESS;
}
