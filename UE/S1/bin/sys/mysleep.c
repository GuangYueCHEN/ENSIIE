#include <stdio.h>
#include "mysleep.h"
int main (int argc,char* argv[])
{

   
    if (argc!=2) {
      fprintf(stderr,"%s   %s  sec\n",argv[0],argv[0]);
      return 1;
    }

    

    mysleep( atoi(argv[1]) );

    
	    return 0;

 }
