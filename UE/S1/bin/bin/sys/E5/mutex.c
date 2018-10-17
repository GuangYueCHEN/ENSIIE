#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>
/*
#ifndef NOMUIEX
pthreq_mutex = PTHREAD_MUTEX_INITIALIZER


#define P() pthread_mutex_lock(&mutex.c)
#define V() pthread_mutex_unlock(&mutex.c)
#else
#define P()
#define V()
  #endif
*/

int file_size(char* filename)  
{  
    FILE *fp=fopen(filename,"r");  
    if(!fp) return 0;  
    fseek(fp,0L,SEEK_END);  
    int size=(int)ftell(fp);  
    fclose(fp);  
      
    return size;  
}

int lire_parti(char* filename,int sz,int parti){
    FILE *fp=fopen(filename,"r");
    int index=sz/4*parti;
    //  printf("--%d\n",index);
     
    if(!fp) return -1;  
    fseek(fp,index,SEEK_SET);
    char *buffer;
    buffer=(char *)malloc(sz/4*sizeof(char));
     int i;
    for(i=0;i<sz/4;i++){
    buffer[i]=fgetc(fp);
    }

   
    int n=0;
    for(i=0;i<sz/4;i++){if(buffer[i]=='\n')n++;}

    
    printf("%d le %d parti\n",n,parti+1);
    return n;
}
static sum1=0;
void * sum(void* n){
  // P();

  sum1+=(int)n;

  return NULL;
  // V();
}


int main(int argc,char* argv[]){
  int status;
  pthread_attr_t att;
  pthread_attr_init(&att);
      pthread_t th[4];

  
    int sz= file_size(argv[1]);
    //  printf("%d\n",sz);
    int i;
    int result=0;
    for(i=0;i<4;i++){
      // int pid=fork();
 
      // if(pid==0){
	sleep(i+1);
        result=lire_parti(argv[1],sz,i);
        pthread_create(&th[i],&att,sum,(void*)result);
	//	exit(0);
	// }
	//	 else
	//	continue;
    }

    int sum=0;

    for(i=0;i<4;i++) {
      // wait(&status);
      pthread_join(th[i],NULL);
    }
      printf("ensemple %d\n",sum1);
    return 0;
    
}
