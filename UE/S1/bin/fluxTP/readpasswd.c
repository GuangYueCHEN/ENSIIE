#include <stdio.h> 
#include <unistd.h>  //???
#include<sys/types.h> //???
#include<sys/stat.h>//???
#include<fcntl.h>  //???
#include<string.h> //string
#include<errno.h> //erreur

int readpasswd(char pwd[16]){

char* ttypath =
  ttyname(0) ? ttyname(0)
  :ttyname(1) ? ttyname(1)
  :ttyname(2);

if(ttypath==0)return -1;

int fdes ;

if ((fdes =open(ttypath,O_RDWR))==-1){
            fprintf(stderr,":Fatal: pb ouverture %s en ecriture :%s \n",ttypath,
		    strerror(errno));
return 1;
}

         printf("PASSWD:");
         fflush(stdout);
	 
system("stty raw -echo");

 
int i=0;
int state;
char c;

 for(;;i++) {
           state= read(fdes,&c,1);
           if(state==-1) return 1;
           if(c==127){
              write(fdes,"\b \b",3);
              i--;
	      pwd[i]='\0';
	      i--;
              continue;
              }

	   else pwd[i]=c;

	   if(c=='\n'||c=='\r')break;
 
	   write(fdes,"X",1);
     }


system("stty -raw echo");

return 0;

}





int main(){

  int state;
  char buffer[16];

    state=readpasswd(buffer);

   if (state==1)
     {printf("\n-----read error ");}
   if (state==0)
     {printf("\n-----read succes ");}
   printf("----------------------\n");

   printf("PASSWD:%s\n",buffer);

return 0;

}
