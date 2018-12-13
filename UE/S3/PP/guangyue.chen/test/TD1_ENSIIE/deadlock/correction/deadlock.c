#include <stdio.h>                                                            
#include <stdlib.h>                                                             
#include <mpi.h>

void echange_dangereux(int rang, char *buf_send, char *buf_recv, int n) {
    MPI_Status sta;
    int vois = (rang+1) % 2;
    int mpi_buf_size=n+MPI_BSEND_OVERHEAD;
    char *buf;
    buf=malloc(mpi_buf_size);
    
if(rang==0){
MPI_Buffer_attach(buf,mpi_buf_size);
    MPI_Bsend(buf_send,n,MPI_BYTE,vois,rang,MPI_COMM_WORLD);
    MPI_Recv(buf_recv,n,MPI_BYTE,vois,vois,MPI_COMM_WORLD,&sta);
    MPI_Buffer_detach(&buf,&mpi_buf_size);
   }else{
MPI_Recv(buf_recv,n,MPI_BYTE,vois,vois,MPI_COMM_WORLD,&sta);
 MPI_Buffer_attach(buf,mpi_buf_size);
    MPI_Bsend(buf_send,n,MPI_BYTE,vois,rang,MPI_COMM_WORLD);
    MPI_Buffer_detach(&buf,&mpi_buf_size);
}
 free(buf);
     
    
}

int main(int argc, char **argv) {

    int n, rang, P;
    char *buf_send, *buf_recv;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rang);
    MPI_Comm_size(MPI_COMM_WORLD, &P);

    if (argc != 2) {
	if (rang == 0)
	    printf("Utilisation : %s <n>\n", argv[0]);
	abort();
	return 1;
    }
    n = atoi(argv[1]);

    if (P != 2) {
	if (rang == 0)
	    printf("Il faut exactement 2 processus MPI et non %d\n", P);
	abort();
	return 1;
    }

    buf_send = calloc(n, sizeof(n));
    buf_recv = calloc(n, sizeof(n));

    printf("Debut echange %d octets\n", n);
    echange_dangereux(rang, buf_send, buf_recv, n);
    printf("Fin echange.\n");

    free(buf_send);
    free(buf_recv);

    MPI_Finalize();

    return 0;
}
