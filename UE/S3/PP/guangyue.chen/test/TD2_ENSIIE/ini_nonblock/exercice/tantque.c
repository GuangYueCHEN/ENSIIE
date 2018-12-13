#include <stdio.h>
#include <mpi.h>
#include <unistd.h>

void work(int iter)
{
    sleep(iter);
}

int main(int argc, char **argv)
{
    int rank, nsecs, niter;
int flag=0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Request req;
    if (rank == 0)
    {
        nsecs = 10;
        sleep(nsecs);

        /* TRAVAIL A FAIRE
           Envoyer nsecs au processus 1
         */MPI_Send(&nsecs,1,MPI_INT,1,1000,MPI_COMM_WORLD);
    }
    else if (rank == 1)
    {   nsecs=0;
        niter = 0;
        /* TRAVAIL A FAIRE

           Tant qu'on n'a pas recu nsecs de P0 :
               
               niter++;
               work(niter);
           */
	MPI_Irecv(&niter,1,MPI_INT,0,1000,MPI_COMM_WORLD,&req);
while(!flag){
MPI_Test(&req,&flag,MPI_STATUS_IGNORE);
     nsecs++;
work(nsecs);
}

        printf("Nsecs = %d s  / Nb iter = %d\n", nsecs, niter);
    }

    MPI_Finalize();
    return 0;
}

