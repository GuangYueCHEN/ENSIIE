#include "lire.h"
#include <stdio.h> 
#include <unistd.h>  //???
#include<sys/types.h> //???
#include<sys/stat.h>//???
#include<fcntl.h>  //???
#include<string.h> //string
#include<errno.h> //erreur

int main(int argc , char *argv[]){

 int fsrc;
 if ((fsrc =open(argv[1],O_RDONLY))==-1){
     
  fprintf(stderr,"%s:Fatal: pb ouverture %s en lecture :%s \n",argv[0],argv[1],strerror(errno));
return 1;
}


 int fdes ;

 if ((fdes =open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,0666))==-1){
  fprintf(stderr,"%s:Fatal: pb ouverture %s en ecriture :%s \n",argv[0],argv[2],strerror(errno));
return 1;
}
lire();
printf("\n");
 char buff[100];
 int t,y;
 t= dup(0);
 y=dup(1);
 dup2(fsrc,0);
 dup2(fdes,1);
  lire();
   printf("\n");
close(fdes);
close(fsrc);
//printf("\n");
 dup2(t,0);
    dup2(y,1);
  execlp("./lire",0,1);




  return 0;
    }
