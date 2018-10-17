#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char* argv[]){
  int i;
  for(i=1;i<=argc;i++){
    
    int pid=fork();
    
    if(pid==0){
            sleep(atoi(argv[i]));
            printf("%d\n",atoi(argv[i]));
	    exit(EXIT_SUCCESS);
	     } else {
	       continue;

	     }
    }	    

    return 0;
   




}

  
