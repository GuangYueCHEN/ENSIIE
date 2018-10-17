#!cce
#include <stdio.h>
#include <stdlib.h>

#warning NE DOIT PAS APPARAITRE QUAND SILENCE EST DEFINIE

int main ( int argc, char* argv[])
{
  int i,n;
  char* mess;

  if ( argc==1 ) {
    n=1;
    mess="Hello World";
  } else if ( argc==2 ) {
    n=atoi(argv[1]);
    mess="Hello World";
  } else if ( argc==3 ) {
    n=atoi(argv[1]);
    mess=argv[2];
  } else {
    fprintf(stderr,"%s: too many args.\n",argv[0]);
    exit(3);
  }

  if ( n <= 0 || n>10 ) {
    fprintf(stderr,"%s: times=%d is invalid (0<=n<=10.\n",argv[0],n);
    exit(5);
  }

  for (i=0 ; i<n ; i+=1)
    printf("%s\n",mess);

  return 0;
}
