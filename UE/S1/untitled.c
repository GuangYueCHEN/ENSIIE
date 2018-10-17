#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int noway(char** matrix,int x,int y,int size){
    if(y==0&&x==0) return matrix[x][y+1]=='X'&&matrix[x+1][y]=='X';

    else if (y==0&&x==size-1) return matrix[x][y+1]=='X'&&matrix[x-1][y]=='X';

    else if (x==0&&y==size-1) return matrix[x][y-1]=='X'&&matrix[x+1][y]=='X';

    else if (x==size-1&&y==size-1) return matrix[x][y-1]=='X'&&matrix[x-1][y]=='X';

    else if (y==0) return matrix[x][y+1]=='X'&&matrix[x+1][y]=='X'&&matrix[x-1][y]=='X';

    else if (y==size-1) return matrix[x][y-1]=='X'&&matrix[x+1][y]=='X'&&matrix[x-1][y]=='X';

    else if (x==0) return matrix[x][y+1]=='X'&&matrix[x][y-1]=='X'&&matrix[x-1][y]=='X';

    else if (x==size-1) return matrix[x][y+1]=='X'&&matrix[x][y-1]=='X'&&matrix[x+1][y]=='X';

    else return matrix[x][y+1]=='X'&&matrix[x][y-1]=='X'&&matrix[x+1][y]=='X'&&matrix[x-1][y]=='X';
}


void findways(char** matrix,int size,int timer){
    int beginX,beginY;
    int sortiX,sortiY;
    int i,j;

    for(i=0;i<size;i++){

        for(j=0;j<size;j++){
            if(matrix[i][j]=='E') {
                beginX=i;
                beginY=j;
            }else if(matrix[i][j]=='S'){
                sortiX=i;
                sortiY=j;
            }

        }
    }








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
    


  findways(matrix,n,timer);






    return EXIT_SUCCESS;
}
