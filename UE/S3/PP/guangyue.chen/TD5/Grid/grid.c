#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char **argv) 
{
    MPI_Init(&argc, &argv);

    int ndims = 2;
    int mesh_size[2] = {100,100};
    int nproc_per_dim[2] = {0, 0};//秩谱图的长和宽
    int periods_per_dim[2] = {0, 0};//是否周期性
    int rang,nproc;

    MPI_Comm_rank(MPI_COMM_WORLD, &(rang));
    MPI_Comm_size(MPI_COMM_WORLD, &(nproc));

    int err = 0;



    // DEBUT Zone-1-A
    // Créer la topologie cartesienne adaptée au nombre de processus à l'aide de MPI_Dims_create et MPI_Cart_create
MPI_Comm GRID_COMM;
MPI_Dims_create(100,ndims,nproc_per_dim);
MPI_Cart_create(GRID_COMM,ndims,nproc_per_dim,periods_per_dim,false,&GRID_COMM);


    if (rang == 0)
    {
        printf("\n dims : %d, nbproc X : %d, nbproc Y : %d, nb_procs_tot (objectif) : %d (%d) \n", \
                ndims,nproc_per_dim[0],nproc_per_dim[1],nproc_per_dim[0]*nproc_per_dim[1],nproc);
        fflush(stdout);
    }
    // FIN Zone-1-A



    // DEBUT Zone-1-B
    // Une barriere MPI ici permettrait de sérarer les affichages
    MPI_Barrier(MPI_COMM_WORLD);
    int proc_coords[2];
    // Récupérer les coordonnées du rang dans la topologie
    err=MPI_Cart_coords(GRID_COMM,rang,ndims,proc_coords);
    //返回当前进程坐标
    
    int Q[2], R[2], nloc[0], ideb[0], ifin[0];

    int idim = 0;

    for (idim = 0; idim < ndims; idim++)
    {
    
        Q[idim] = mesh_size[idim] / nproc_per_dim[idim]; //100/length=4    100/rang=25 
        R[idim] = mesh_size[idim] % nproc_per_dim[idim];//100%length=0    100%rang=0
        //Q[0]有多少行              Q[1]有多少列
        //R[0]最后一个在第几列        R[1]最后一个在第几行


        if (proc_coords[idim] < R[idim]) //如果得到的坐标行小于R列数                       或列数
        {
            nloc[idim] = Q[idim]+1;       //nloc[0]=Q[0]+1（行数）5
            ideb[idim] = proc_coords[idim] * (Q[idim]+1); //（行数*列） 0
            ifin[idim] = ideb[idim] + nloc[idim]; // 行数*列 +行数 5
        } 
        else 
        {
            nloc[idim] = Q[idim];   //4
            ideb[idim] = R[idim] * (Q[idim]+1) + (proc_coords[idim] - R[idim]) * Q[idim];//0
            ifin[idim] = ideb[idim] + nloc[idim];//4
        }

    }

    int ntot_per_proc = nloc[0] * nloc[1];

    printf("%d %d %d %d\n", rang, proc_coords[0], proc_coords[1], ntot_per_proc);
    fflush(stdout);

    // Une barriere MPI ici permettrait de sérarer les affichages
    
    int nglob = 0;
    // Faire une réduction pour que le processus 0 récupère le nombre total de mailles

    if (rang == 0)
    {
        printf("\n Nombre total de maille (objectif) : %d (%d) \n",nglob,mesh_size[0]*mesh_size[1]);
        fflush(stdout);
    }
    // FIN Zone-1-B



    // DEBUT Zone-2-A
    // Faire un allgather pour récupérer le nombre de mailles dans tous les autres les autres processus
    MPR_Request req;
    MPI_Status sta;
    int flag;
    err=MPI_Iallgather(&ntot_per_proc,1,MPI_INT,nb_cells_by_proc,MPI_INT,MPI_COMM_WORLD,&req);
    MPI_Test(&req,&flag,&sta);
    While(!flag){
        MPI_Test(&req,&flag,&sta);
        k++;
    }
    MPI_Wait(&req,&sta);
    if (rang == 0)
    {
        int ir;
        for (ir = 0; ir < nproc; ir++)
        { 
            printf("( %d ; %d )\n", ir, nb_cells_by_proc[ir]);
        }
    }
    // FIN Zone-2-A

    // DEBUT Zone-2-B
    // Faire un allgather pour récupérer le nombre de mailles des processus voisins
    int nb_cells_in_neighbor[4]={-1,-1,-1,-1};
    err=MPI_Neighbor_allgather(&ntot_per_proc,1,MPI_INT,nb_cells_in_neighbor,1,MPI_INT,GRID_COMM);
    flag=0;
    err=MPI_Ineighbor_allgather(&ntot_per_proc,1,MPI_INT,nb_cells_in_neighbor,1,MPI_INT,GRID_COMM,&req);
    MPI_Test(&req,&flag,&sta);
    while(!flag){
       MPI_Test(&req,&flag,&sta);
       k++;
    }
    MPI_Wait(&req,&sta);
    printf("NB FRID %d\n",k);

    
    printf("RANG %d : ( W %d ; E %d ; N %d ; S %d)\n", \
            rang, nb_cells_in_neighbor[0], nb_cells_in_neighbor[1], \
            nb_cells_in_neighbor[2], nb_cells_in_neighbor[3]);
    // FIN Zone-2-B

    

    MPI_Finalize();

    return 0;
}

