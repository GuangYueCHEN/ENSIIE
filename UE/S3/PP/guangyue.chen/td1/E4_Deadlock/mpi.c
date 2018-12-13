#include<stdio.h>
#include<mpi.h>


void mpi(int rang,int n,char *buf_send,char *buf_recv)
{
 	int vois; 
	MPI_Status sta;
	if(rang==0){
		vois=1;
		}
	else if (rang==1){
		vois=0;
		}
	MPI_Send(buf_send,n,MPI_BYTE,vois,0,MPI_COMM_WORLD);
	MPI_Recv(buf_send,n,MPI_BYTE,vois,0,MPI_COMM_WORLD,&sta);

}



int main(int argc,char **argv){
	   int n, rang, P;
	
	  char *buf_send=calloc(n,sizeof(char));
	  char *buf_recv=calloc(n,sizeof(char));


    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rang);
    MPI_Comm_size(MPI_COMM_WORLD, &P);
    mpi(rang,n, buf_send, buf_recv);


    free(buf_send);
    free(buf_recv);

    MPI_Finalize();

    return 0;


}
