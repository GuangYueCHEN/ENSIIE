#include<stdio.h>
# include <string.h> 
# include <unistd.h> 
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h> 
# include <fcntl.h>



int shell(char ∗ cmd)
{
if(strcmp(cmd,"exit")==0 )
return 0 ;
return 1 ;
}
int main (int argc,char* argv[] )
{
  
 FILE *stdin=fopen(argv[1],"r");  
    if(!stdin) return 0;  


  
char cmd[1000],line[1000] ;
while(1) {
if ( feof(stdin)) break ;
printf("shell>  " ) ;
if ( fgets(line,1000,stdin)==0 ) continue ;
if ( sscanf(line,"%s ",cmd)!= 1 ) continue ;
if ( shell(cmd)==0 ) break ;
}
printf ( " \n" ) ;
    fclose(stdin);  
return 0 ;
}
