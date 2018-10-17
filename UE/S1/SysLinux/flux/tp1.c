#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>
int main(int argc ,char* argv[]){
    FILE *f =NULL;
   
	FILE *fp =NULL;
	
	f=fopen(argv[1],"r+");
	fp=fopen(argv[1],"r");
	
	fprintf(f,"sdasghgjfdshfadiuhfdjasha\n");
	
	char buff[255];
    
	if(	!fgets(buff,255,(FILE*)fp))printf("error read \n");
	
	printf("%s",buff);
	
	fclose(f);

	fclose(fp);

int i=open(argv[1],O_RDONLY);

     struct stat buf;

     fstat(i,&buf);

	int temp = buf.st_size;

	printf("ftat file size %d BT\n",temp);



int c = lseek(i,0,SEEK_END);
     
	printf("lseek file size %d BT\n",c);
    c-=1;

     char * tmp = malloc(c);
	 lseek(i,0,SEEK_SET);
	int m=read(i,tmp,c);
	if(m!=c){
    printf("%s|||%d%d",strerror(errno),m,c);
	exit(1);
    }

    close(i);


     if((i=open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,0666))==-1 ){
             printf("%s\n",strerror(errno));
			 exit(1);

	 }
	  if (write(i,tmp,c)!=c){
		  printf("%s",strerror(errno));
			 exit(1);

	  }
close(i);
	return 0;
	


}

