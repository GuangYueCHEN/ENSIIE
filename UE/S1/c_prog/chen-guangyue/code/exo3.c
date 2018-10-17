#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
ici je utilise le struct de stack , cest pour riveser les cours de TP et cest plus claire si je l'utilise pour conserver le result


*/
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

/*quand je print stack , je le change pour le bon resultat , quand je push le value , je push 1,2,3,4,5 pour representer le BAS HAUT....... * */
void printstack(stack *p){

    int x;
    while(is_empty(p)){
        x=pop(p);
        if(x==1)printf("BAS\n");
        if(x==2)printf("DROITE\n");
        if(x==3)printf("HAUT\n");
        if(x==4)printf("GAUCHE\n");
        if(x==5)printf("TP\n");
        
    }

}

/*
ici je utilise le struct de node 
ceat pour utiliser le methode A*
dans ce struct il ya 
F:= H + G
G:= le distince de 1 er sommet
H:=le distince de sommet 'S'
sym := comme le matrix du plan
pointeur parent pour conserver le pas pécédent 
table is_closed et is open : ajouter les neibhour des sommets dans is_open ,apres les mets dans is_closed  


*/


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
/*
cest quand je crée le fonction A* pour tester s'il mache bien, cest pas utile
*/
void printnode(node n){
    printf("--%d %d %d %d %d|||", n.G,n.H,n.F,n.is_in_open,n.is_in_closed);
}

/*
pour calculer H des sommets
*/
int distance(int i,int j,int x,int y){
    int m=i-x;
    if(m<0)m=-m;
    int n=j-y;
    if(n<0)n=-n;
    return 10*(m+n);
}

/*
ajouter les voisins des sommets dans is_open ,apres les mets dans is_closed  
*/
node * insert_to_opentable( node ** Amap,node * open_table, int x, int y, node * curr_node,  int w ,int timer)
{
    node * cur2=Amap[x][y].parent;
   
    if( Amap[x][y].sym != 'X' )/*si les neibour ne sont pas 'X' */
    {
        if ( Amap[x][y].is_in_closed==0)/*si les neibour ne sont dans le table 'is _ closed '*/
        {
            if ( Amap[x][y].is_in_open==1)
            {
                /*   milleur path  si il est dans le table 'is _ open ' */
                if ( Amap[x][y].G > curr_node->G + w )
                {
                    Amap[x][y].G = curr_node->G + w;
                    Amap[x][y].parent = curr_node;
                    if(Amap[x][y].G>timer*10)return cur2;
                    cur2=Amap[x][y].parent;
                    
                }
            }
            else     /*ajouter au 'open table' */
            {
                
                
                
                
                Amap[x][y].G = curr_node->G + w;
                if(Amap[x][y].G>timer*10)return cur2;
                Amap[x][y].parent = curr_node;
                count_open++;
                Amap[x][y].is_in_open = 1;
                Amap[x][y].F=Amap[x][y].G +Amap[x][y].H;
                open_table[count_open] = Amap[x][y];
                cur2=Amap[x][y].parent;
            
                
            }
        }
    }
    

    
    return cur2;
}








/*le fonction de A* , les deux chars cest pour ecuser le rout de begin à end*/

int A(char (*matrix)[1002],char begin,char end,int size,int timer){
    
    int endX,endY;
   
    int i,j;
    
    /*créer N*N node de struct */
    node **Amap = (node**)malloc(sizeof(node*)*size);
    
    for( i = 0; i < size;i++)
    {
        Amap[i] = (node*)malloc(sizeof(node)*size);
    }
    /*creer le table de opentable*/
    node * open_table=(node*)malloc(sizeof(node)*size*size);
    





    /* trouver le x,y de sommet 'S' ou 'a' */
    for(i=0;i<size;i++){
        
        for(j=0;j<size;j++){
             if(matrix[i][j]==end) {
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
int num=0;









    while(count_open!=0){   /*while openset is not empty              */
        k=0;
        count_open--;
        
         if(num==44444) break;

        num++;
    /*
*/

        
        min=open_table[0];
        /*pour  trouver le min  */
        for(i=0;i<=count_open;i++){
          
            
            if(min.F>=open_table[i].F){
                min=open_table[i];
                k=i;
            }
        }
        
        
        /* si H = 0 ,ca signifie j'ai trouver le end sommet*/
        if(min.H==0){
            is_found=1;
            break;
            
        }
   
        
        
        x=min.x;
        y=min.y;
        /* ajouter les neiber,le  G de distince des neiberest G(de current sommet)+10*/
        
        if ( ( x + 1 ) >= 0 && ( x + 1 ) < size && y >= 0 && y < size )
        {
            Amap[x+1][y].parent = insert_to_opentable( Amap,open_table,x+1, y, &Amap[x][y], 10 ,timer);
            
            
        }
        
        if ( ( x - 1 ) >= 0 && ( x - 1 ) < size && y >= 0 && y < size)
        {
            Amap[x-1][y].parent = insert_to_opentable(Amap,open_table, x-1, y, & Amap[x][y],  10 ,timer);
            
        }
        
        if ( x >= 0 && x < size && ( y + 1 ) >= 0 && ( y + 1 ) < size )
        {
            Amap[x][y+1].parent = insert_to_opentable( Amap,open_table,x, y+1, &Amap[x][y],  10 ,timer);
            
        }
        
        if ( x >= 0 && x < size && ( y - 1 ) >= 0 && ( y - 1 ) < size )
        {
            Amap[x][y-1].parent = insert_to_opentable( Amap,open_table, x, y-1,  &Amap[x][y],  10,timer );
            
        }
        
      
        /* si ce sommet est les symbols des tp */
        tp = matrix[x][y] ;
        
        if(tp == '*' || tp == '%'|| tp=='$'|| tp=='#'|| tp=='&'|| tp =='+'|| tp =='-'|| tp =='@'|| tp =='^'||tp=='!') {
           
            int tpi,tpj;
            
            for(tpi=0;tpi<size;tpi++){
                
                for(tpj=0;tpj<size;tpj++){
                    
                    
                    
                    if(matrix[tpi][tpj]==tp&&(tpi!=x||tpj!=y)&&Amap[tpi][tpj].is_in_closed!=1){
                        
                        /*  metter un autre sommet de tp  dans le table de 'open' , le distince est la meme ,et mets le 1er tp à '.' */
                        Amap[tpi][tpj].parent=insert_to_opentable( Amap,open_table,tpi, tpj,  &Amap[x][y],  0,timer);
                        Amap[x][y].sym='.';
                     
                        
                        
                    }
                }
            }
            
            
            
            
            
        }
        
        
        Amap[x][y].is_in_closed=1;
        Amap[x][y].is_in_open=0;

        
        /* sort le sommet de ce sommet ( je le mets dans le dernier place de open_table ,apres count -- ), */
        for(i=k;i<count_open;i++){
        cur3= open_table[i+1];
        open_table[i+1] = open_table[i];
        open_table[i]= cur3;
        }
        
        
  
        
       
        
        
        
        
        
    }
    node parent; int time=0;
  



    /*si je trouve ,print le resultat*/
    if ( is_found)
    {
        stack result=new();
        
        cur3=Amap[endX][endY];
    
/*comme le pécédent , je conserve les resultat de le dernier à le 1er , dans un stack , apres je printstack , l'ordre est inverse  * */
        while(cur3.parent!=NULL){
            parent=*cur3.parent;
            x=cur3.x - parent.x;
            y=cur3.y - parent.y;
            tp=Amap[cur3.x][cur3.y].sym;
          
               
            if(tp == '*' ||tp == '%'||tp == '$'||tp == '#'||tp == '&'||tp == '+'||tp == '-'||tp == '@'||tp == '^'||tp=='!'){
                
                push(&result,5);
/* 5 = TP */
                
                
            } else{
                
                if(x==1)push(&result,1);/* 1= BAS */
                if(x==-1)push(&result,3);/*3= HAUT */
                if(y==1)push(&result,2);/* 2 = DROITE*/
                if(y==-1)push(&result,4);/* 4 = GOUCHE */
                time++;
            }
            cur3=*cur3.parent;
            
        }
         /* si le tempt est bon , printstack */
        if(time<=timer){
            printstack(&result);
       
     
        
            return time;
        }
        else {
               /* le temps nest pas bon return 0*/
            return 0;
            
        }
        
        
        
    }
    else
    {
             /* si trouve pas , return 0 */
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


             /* si il ya la porte ,have_door = 1 */
    for(i=0;i<n;i++){
        for ( j = 0; j < n; j++)
        {
            if(matrix[i][j]=='A'){
                have_door=1;
          
                break;
            }
        }
        if(have_door==1)break;
    }
    int acc;
    if(have_door==1){
         /* si il ya la porte , esseyer s'il peut aller le 'S',ne peut pas trouve le rout à 'a',et apres à 'S'*/
        matrix[i][j]='X';
        acc=A(matrix,'E','S',n,timer);
        if(acc==0){
        

        acc=A(matrix,'E','a',n,timer);
    
        matrix[i][j]='.';
        timer=timer-acc;


     
        acc=A(matrix,'a','S',n,timer);

        if(acc==0) return 1;
        }
    }
    
    else acc=A(matrix,'E','S',n,timer);

    return EXIT_SUCCESS;
}

