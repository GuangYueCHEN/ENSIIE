#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "fichier.h"
#include "lexeme.h"
#include"stack.h"
#include"evalution.h"

int main(int argc,char* argv[]){

  stack p=eval(argv[1]);
  print_stack(p);


  return 0;
}
