#include <stdio.h> 
#include <unistd.h>  //???
#include<sys/types.h> //???
#include<sys/stat.h>//???
#include<fcntl.h>  //???
#include<string.h> //string
#include<errno.h> //erreur

int main(int argc , char *argv[]){
/*
int i ;
if (argc !=3){
  fprintf(stderr,"%s:Fatal: %d mauvais nb d'args (2 attendus)\n",argv[0],argc);
return 1 ;
}

//else printf("il faut 2 files \n");
int fsrc;
 if ((fsrc =open(argv[1],O_RDONLY))==-1){
     
  fprintf(stderr,"%s:Fatal: pb ouverture %s en lecture :%s \n",argv[0],argv[1],strerror(errno));
return 1;
}

else printf("rd ouver succes \n");

int fdes ;

 if ((fdes =open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,0666))==-1){
  fprintf(stderr,"%s:Fatal: pb ouverture %s en ecriture :%s \n",argv[0],argv[2],strerror(errno));
return 1;
}
else printf("wr  ouvre succes\n");


for (i=0;i<10;i+=1){
       char c;
int status = read(fsrc,&c,1);
if (status==-1){
fprintf(stderr,"%s:Fatal:%s en lecture :%s \n",argv[0],argv[1],strerror(errno));
return 1;
}
printf("test %c %d",c,status);
if (status == 0) break;

status =write(fdes,&c,1);
if (status==-1||status==0){
fprintf(stderr,"%s:Fatal:%s en ecriture :%s \n",argv[0],argv[2],strerror(errno));return 1;
}
//if (lseek(fsrc,9,SEEK_CUR)==-1){
//fprintf(stderr,"%s pb avancee ds %s %s \n",argv[0],argv[1],strerror(errno));
//return 1;
//}
}



    


close(fsrc);
close(fdes);
return 0;

FILE *f = NULL;
char buff[255];
f = fopen("./test","r");
fprintf(f,"this is the test ligne 1\n");
fputs("ligne2\n",f);

fclose(f);

FILE *fp = argv[1];

fp = fopen("./test","w");
fscanf(fp,"%s",buff);
printf("%s\n",buff);

fgets(buff,255,(FILE*)fp);
printf("%s\n",buff);
fclose(fp);
*/


  FILE *f = NULL;

f = fopen(argv[1],"r");
 if (f == NULL) {
      fprintf(stderr,"%s: pb ouverture %s en lecture : %s\n",
          argv[0],argv[1],strerror(errno));
      return 1;
    }



   int x= fseek(f,0,SEEK_END);
   int sz=ftell(f);
   if  (sz == 0) return 0;
   if(x<0){
     fprintf(stderr,"%szzzzzzzzzzzzzzzzxxxxxxxxxx\n",strerror(errno));return 1;}


   sz-=1;
   printf("%d\n",sz);
 




 char *buff= malloc(sz);
  fseek(f,0,SEEK_SET);
  if ((int)fread(buff,sizeof(char),sz,f)!=sz) {
    fprintf(stderr,"%srrrrrrrrrrrrrrrrrrrrrxxxxxxxxxx\n",strerror(errno));return 1;}

  
fclose(f);


 
FILE *fp = NULL;
fp = fopen(argv[2],"w+");
 if (fp == NULL) {
      fprintf(stderr,"%s: pb ouverture %s en ecriture : %s\n",
          argv[0],argv[2],strerror(errno));
      return 1;
    }

 if ((int)fwrite(buff,sizeof(char),sz,fp)!=sz){
   fprintf(stderr,"%swwwwwwwwwwwwxxxxxxwxxxx\n",strerror(errno));return 1;}

fclose(fp);
 
return 0;
}
