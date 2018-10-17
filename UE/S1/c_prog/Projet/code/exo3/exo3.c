#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#include"astar.h"
#include"stack.h"




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

