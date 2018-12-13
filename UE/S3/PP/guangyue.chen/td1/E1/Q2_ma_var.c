#include<stdio.h>
#include<mpi.h>
#include<unistd.h>
int main(int argc, char **argv){
  int N,me,len,ma_var;
  char str_host[MPI_MAX_PROCESSOR_NAME];
  pid_t pid;  

  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&N);
  MPI_Comm_rank(MPI_COMM_WORLD,&me);
  
  MPI_Get_processor_name(str_host,&len);
  pid=getpid();
  printf("my rank is %d out of %d, host %s , pid =%d ,adresse(ma_var)=%p",me,N,str_host,pid,&ma_var);

  MPI_Finalize();
  return 0 ;


}
