#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "stack.h"
#include "FFS.h"

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
