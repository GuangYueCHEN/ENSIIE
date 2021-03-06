#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char*argv[])
{
  setenv("IacmpDir","/pub/ia/sys/shell/iacmp",1 );
  setenv("LD_LIBRARY_PATH", "/pub/ia/sys/shell/iacmp/lib",1);
  execv("/pub/ia/sys/shell/iacmp/iacmp",argv);
  fprintf(stderr,"%s: pb execv : %s\n",
	  argv[0] ,strerror(errno)
  );
  return 0;
}
