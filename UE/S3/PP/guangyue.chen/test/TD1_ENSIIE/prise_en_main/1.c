#include <stdio.h>
#include<mpi.h>
#include<unistd.h>


int main(int argc, char **argv){
int rang,P,len;
char name[MPI_MAX_PROCESSOR_NAME];
char ma_var;
printf("asdasd\n");
pid_t pid;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rang);
MPI_Comm_size(MPI_COMM_WORLD,&P);

MPI_Get_processor_name(name,&len);
 pid = getpid();
    printf("%d, %d,adress  %p, pid=%d\n", rang, P, &ma_var, pid);

MPI_Finalize();
return 0;
}


