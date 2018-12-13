#include<stdio.h>
#include<mpi.h>

int main(int argc, char **argv){
	int rk,i,tag;
	MPI_Status sta;	
	double tab[10];
	
	MPI_Init(&argc,&argv);
	
	MPI_Comm_rank(MPI_COMM_WORLD,&rk);
	tag=1001;
	if(rk==0){
		

		MPI_Recv(&tab,10,MPI_DOUBLE,1,tag,MPI_COMM_WORLD,&sta);
	
		 for( i=0;i<10;i++){
                        printf("%lf\n",tab[i]);
                }

	}else if(rk==1){
		
		for( i=0;i<10;i++){
			tab[i]=10.1-i;
		}
		 MPI_Send(&tab,10,MPI_DOUBLE,0,tag,MPI_COMM_WORLD  );

	}

    MPI_Finalize();

    return 0;


}
