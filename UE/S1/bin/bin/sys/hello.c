#include<stdio.h>
int main(){
  int pid=fork();

  if(pid==0){
    sleep(2);

  }else{
      int pid2=fork();
       if(pid2==0){
       sleep(4);
 
       printf("world\n");
       }else{
   printf("hello\n");
       }
   }
return 0;






}
