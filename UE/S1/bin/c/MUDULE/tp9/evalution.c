
#include"evalution.h"
#include <stdio.h>
#include <stdlib.h>


int eval(flux f){
 stack p=stack_create();
 lexeme QFobaz ;
  char* buffer;
  int x,y,res=0;
  while(!fin_de_fichier(f)){
    
    buffer=lit_un_mot(f);
    QFobaz = chaine_vers_lexeme(buffer);
    
    if(est_constante(QFobaz)){
      push(p,val_constante(QFobaz));
   
    }else if(est_plus(QFobaz)){
      
       if(!is_empty(p))
       return 1;
      
       x=pop(p);
      
       if(!is_empty(p))
       return 1;
       
       y=pop(p);
       
       push(p,x+y);
      
            }
  
  }

 return pop(p);
}

int main(int argc,char* argv[]){
  if(argc !=2){
    printf("error\n");
    return 1;
  }
  
   flux f=ouvre(argv[1]);
  
    int val = eval(f);


   ferme(f);
   printf("%d\n",val);

  return 0;
}

