#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include "lire.h"
int main(int argc ,char *argv[]){
  fprintf(stderr,"je suis la cmd lire\n");
  lire();
  return 0;
}


