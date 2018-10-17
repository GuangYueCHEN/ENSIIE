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

 char buff[100];
 dup2(fsrc,0);
 dup2(fdes,1);
  lire();
  lire();

  execlp("./lire",0,1);

  close(fsrc);
close(fdes);


  return 0;
    }
