#include<stdio.h>
#include<mpi.h>

int main(int argc, char **argv){

	int rank;
	int P;

	int envoi=0;
	int recv;
MPI_Status sta;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	if(rank==0){
		MPI_Send(&envoi,1,MPI_INT,1,1000,MPI_COMM_WORLD);
		printf("i send %d\n",envoi );
	}else{
		MPI_Recv(&recv,1,MPI_INT,0,1000,MPI_COMM_WORLD,&sta);
		printf("i recv %d\n",recv );

	}
MPI_Finalize();
return 0;



}
