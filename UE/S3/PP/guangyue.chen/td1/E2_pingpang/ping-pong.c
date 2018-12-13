#include<stdio.h>
#include<mpi.h>

int main(int argc, char **argv){
	int rk,jeton,tag,tag2,j;
	MPI_Status sta;	
	 double tabr[10];

	MPI_Init(&argc,&argv);
	
	MPI_Comm_rank(MPI_COMM_WORLD,&rk);
	tag=1000;
	tag2=1001;
	if(rk==0){
		
		jeton=10;

		MPI_Send(&jeton,1,MPI_INT,1,tag,MPI_COMM_WORLD	);
	
	       MPI_Recv(tabr, 10, MPI_DOUBLE, 1, tag2, MPI_COMM_WORLD, &sta);

        	printf("\n");
       		 for(j = 0 ; j < 10 ; j++)
       			 {
           		 printf("P%d, tabr[%i] = %.6e\n", rk, j, tabr[j]);
        		}

	}else if(rk==1){
	
		if(MPI_Recv(&jeton,1,MPI_INT,0,tag,MPI_COMM_WORLD,&sta)==0){

		printf("Je suis P%d et j'ai recu la valeur %d \n", rk, jeton);

	        int  nsec = 5; 
       		 for(j = 0 ; j < nsec ; j++)
       		 {
           		 printf(".");
           		fflush(stdout);
          		  sleep(1); 
       		 }
        	printf("\n");

      		  for(j = 0 ; j < 10 ; j++)
       			 {
       	    		 tabr[j] = 1./(1. + (double)j);
        		 }


		   MPI_Send(tabr, 10, MPI_DOUBLE, 0, tag2, MPI_COMM_WORLD);

		}

		
	}

    MPI_Finalize();

    return 0;


}
