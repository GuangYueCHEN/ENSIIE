mpirun -n 2 ./mpi.exe 
cd ..
ls
cd ..
ls
mkdir E4_Deadlock
cd E4_Deadlock/
ls
vim mpi.c
mpicc mpi.c -o mpi.exe
vim mpi.c
mpicc mpi.c -o mpi.exe
vim mpi.c
exit
module load mpi/openmpi-x86_64
mpicc monprog.c -o monprog.exe
module load mpi/openmpi-x86_64
sinfo
salloc -n 4 -N 2
squeue
salloc -n 4 -N 2
squeue
ls
 cd TD1_ENSIIE/
ls
cd prise_en_main/
ls
cat correction1.c 
cat correction2.c 
cat correction3.c 
mpicc correction3.c -o test.exe
ls
cd ..
ls
 cd ping_pong/
ls
cat corr_ping1.c 
cat corr_pong1.c 
ls
cat corr_pong2.c 
cat corr_ping_pong3.c 
cd ..
ls
cd questions_pieges/
ls
cd pieges/
ls
cd ..
ls
 cd corrections/
ls
cqt correctionA.c 
cat correctionA.c 
cd..
cd ..
ls
 cd ..
ls
cd ..
ls
cd TD1_ENSIIE/
ls
 cd deadlock/
ls
cd correction/
ls
cat deadlock.c 
ls
cd TD1_ENSIIE/
ls
ls*
ls
module load mpi/openmpi-x86_64
sinfo
cd ..
ls
cp /tmp/TD2_ENSIIE.tar  .
ls
 tar TD2_ENSIIE.tar 
 tar -fs TD2_ENSIIE.tar 
ls
 tar --help
 tar -xf TD2_ENSIIE.tar 
ls
mkdir td
2
mkdir td2
ls
rm td
rm -r td
cd TD2_ENSIIE/
ls
cd ini_nonblock/
ls
cd exercice/
vim deadlock.c 
emacs deadlock.c 
emacs deadlock.c &
mpicc deadlock.c -o test.exe
mpirun -n 2 ./test.exe 
sinfo
cd ..
ls 
cd correction/
ls
cqt corr1_deadlock.c 
cat corr1_deadlock.c 
cd ..
ls*
*
s
ls
cd exercice/
ls
mpicc deadlock.c -o test.exe
mpirun -n 2 ./test.exe 
mpirun -n 4 ./test.exe 
cd ..
ls
cd  ..
ls
cd td1/
ls
 cd E1/
ls
mpicc Q1_MPI.c -o test.exe
mpirun -n 2 ./test.exe 
sinfo
cd 
ls
 cd TD2_ENSIIE/
cd ini_nonblock/
cd exercice/
ls
emacs tantque.c &
emacs deadlock.c &
mpicc deadlock.c -o test.exe
mpirun -n 2 ./test.exe 
mpicc tantque.c -o test.exe
vim tantque.c
mpicc tantque.c -o test.exe
vim tantque.c
mpicc tantque.c -o test.exe
vim tantque.c
mpicc tantque.c -o test.exe
vim tantque.c
mpicc tantque.c -o test.exe
mpirun -n 2 ./test.exe 
cd ..
ls
cd ..
ls
 cd exo_waitall/
ls
vim exo_waitall.c 
emacs exo_waitall.c &
cd ..
ls
 cd exo_waitall/correction/
ls
mpicc error1_waitall.c -o test.exe
mpirun -n 2 ./test.exe 
mpicc error2_waitall.c -o test.exe
mpirun -n 2 ./test.exe 
mpicc correct_waitall.c -o test.exe
mpirun -n 2 ./test.exe 
mpicc correct_recv.c -o test.exe
mpirun -n 2 ./test.exe 
ls
cat error2_waitall.c 
cat correct_waitall.c 
cd ../../..
ls
cd TD2_ENSIIE/convolution/
ls
ls
 cd TD2_ENSIIE/
ls
cd ini_nonblock/
ls
cd correction/
ls
cat corr1_deadlock.c 
cat corr2_deadlock.c 
ls
cat corr_tantque.c 
      MPI_Send(&nsecs, 1, MPI_INT, 1, 1000, MPI_COMM_WORLD);
MPI_Send(&nsecs, 1, MPI_INT, 1, 1000, MPI_COMM_WORLD);MPI_Send(&nsecs, 1, MPI_INT, 1, 1000, MPI_COMM_WORLD);
ld
cd ..
ls
cd  ..
ls
 cd exo_waitall/
cd correction/
ls
cat correct_waitall.c 
cat error1_waitall.c 
ls
cat error1_waitall.c 
cat correct_recv.c 
ls
 cd ..
ls
 cd ..
ls
cd convolution/
cd correction/
ls
 cd TD2_ENSIIE/
ls
cd exo_waitall/
ls
cd correction/
ls
cat error1_waitall.c 
ls
cat error2_waitall.c 
cat correct_waitall.c 
cd ..
ls
cd 
ls
 cp /tmp/
 cp /tmp/TD3_ENSIIE.tar .
ls
tar -xf TD2_ENSIIE.tar 
ls
tar -xf TD3_ENSIIE.tar 
ls
cd TD3_ENSIIE/
ls
cd prod_scal/
ls
cd correction/
cat corr_prod_scal.c 
cat vec_x
ls
cat corr_prod_scal.c 
cd ..
cd reduction/
cd correction/
ls
cat corr_pt2pt_reduction.c 
cat  corr_coll_reduction.c 
cat corr_pt2pt_reduction.c 
ls
cat corr_coll_reduction.c 
cd ..
ls
 cd ..
ls
 cd pieges_coll/
ls
cd correction/
ls
cat corr_barriere.c 
cat corr_scatter.c 
cat corr_coll.c 
mpicc corr_coll.c -o test.exe
ls
cd TD2_ENSIIE/
ls
cd cd exo_waitall/
ls
cd exo_waitall/
ls
cd correction/
ls
cd ..
ls
emacs exo_waitall.c 
cd correction/
ls
cat correct_waitall.c 
cat correct_recv.c 
ls
cd
ls
cp TD3_ENSIIE td3
ls
cp -r TD3_ENSIIE td3
ls
cd td3/prod_scal/
ls
emacs exo_prod_scal.c 
module load mpi/openmpi-x86_64
mpicc exo_prod_scal.c -o test.exe
ls
mpirun -n4 ./test.exe 
mpirun -n 4 ./test.exe 
emacs exo_prod_scal.c &
ls
cd correction/
ls
mpicc corr_prod_scal.c -o test.exe
mpirun -n 4 ./test.exe 
cd ..
ls
mpicc corr_prod_scal.c -o test.exe
mpirun -n 4 ./test.exe 
mpicc exo_prod_scal.c -o test.exe
mpirun -n 4 ./test.exe 
cd ..
ls
cd reduction/
ls
emacs exo_reduction.c &
ls
mpicc exo_reduction.c -o test.exe
mpirun -n 4 ./test.exe 
mpicc exo_reduction.c -o test.exe
mpirun -n 4 ./test.exe 
ls
cp exo_reduction.c exo_reduction_pt2pt.c
ls
mpicc exo_reduction.c -o test.exe
mpirun -n 4 ./test.exe 
cd ..
ls
cd pieges_coll/
ls
cd ..
ls
 cd reduction/
ls
mv exo_reduction.c exo_reduction_collectives.c
l
sls
lsl
ls
 cd ..
ls
 cd pieges_coll/
ls
cd pieges/
ls
emacs piege_barriere.c &
ls
mpicc piege_barriere.c -o test.exe
mpirun -n 4 ./test.exe 
mpicc piege_barriere.c -o test.exe
mpirun -n 4 ./test.exe 
ls
cd REP_COMMUN/
ls
cat trace.P
cat trace.P1
cd ..
ls
emacs piege_scatter.c &
mpicc piege_scatter.c -o test.exe
mpirun -n 4 ./test.exe 
mpicc piege_scatter.c -o test.exe
mpirun -n 4 ./test.exe 
mpicc piege_coll.c -o test.exe
mpirun -n 4 ./test.exe 
emacs piege_coll.c &
ls
 cd ..
ls
cd correction/
mpicc corr_coll.c -o test.exe
mpirun -n 4 ./test.exe 
ls 
cd ..
ls
 cd ..
 ls
 cd prod_scal/
ls
emacs exo_prod_scal.c
cd ..
ls
 cd reduction/
ls
 emacs exo_reduction_collectives.c 
cd ..
ls
 cd pieges_coll/
ls 
cd p
cd pieges/ 
ls
mpicc piege_coll.c -o test.exe
mpirun -n 4 ./test.exe 
mpicc piege_coll.c -o test.exe
mpirun -n 4 ./test.exe 
ls
module load mpi/openmpi-x86_64
ls
cd TD1_ENSIIE/
ls
cd prise_en_main/
ls
emacs correction1.c 
cat correction1.c 
cat correction2.c 
mpicc correction1.c -o test.exe
module load mpi/openmpi-x86_64
mpicc correction1.c -o test.exe
mpirun -n 4 ./test.exe 
ls
 cat correction2.c 
mpicc correction2.c -o test.exe
mpirun -n 4 ./test.exe 
cat correction3.c 
mpicc correction3.c -o test.exe
mpirun -n 4 ./test.exe 
vim correction3.c 
mpicc correction3.c -o test.exe
mpirun -n 4 ./test.exe 
vim correction3.c 
cd ..
ls
mv prise_en_main/ Q1
ls
cd ping_pong/
ls
cat corr_ping1.c 
cat corr_pong2.c 
ls
cat corr_ping_pong3.c 
ls
cd ..
ls
cd ..
ls
cd TD1_ENSIIE/
ls
cd ..
sl
ls
 cd td1/
ls
cp -r E3_question_pieges/ ~/TD1_ENSIIE/
cd
ls
cd TD1_ENSIIE/
ls
cd E3_question_pieges/
ls
cd pieges/
ls
cat piegeA.c 
ls
cd ..
ls
 cd corrections/
ls
cat correctionA.c 
cd ..
ls
 cat pieges/piegeB.c 
cat corrections/correctionB.c 
cat pieges/piegeC.c 
clear
cat pieges/piegeC.c 
cat corrections/correctionC.c 
cat corrections/correctionD.c 
cd ..
ls
mv deadlock/ E4_deadlock/
ls
cd E4_deadlock/
ls
cd correction/
ls
cat deadlock.c 
ls
mpicc deadlock.c -o test.exe
mpirun -n 4 ./test.exe 13 
mpirun -n 2 ./test.exe 13 
mpirun -n 2 ./test.exe 65424 
mpirun -n 2 ./test.exe 33333 
ls
mpirun -n 2 ./test.exe 3333 
mpirun -n 2 ./test.exe 22222 
mpirun -n 2 ./test.exe 6666 
cat deadlock.c 
ls
cat echange_standard.c 
ls
 cat echange_buffer.c 
ls
cat echange_synchrone.c 
cat echange_standard.c 
l
ls
cat TAILLE_BLOCAGE 
cd ..
ls
cd ..
ls
cd RenumAnneau/
ls
cd Q1
cd Q2
ls
cat init_anneau.c 
mpicc init_anneau.c -o test.exe
mpirun -n 4 ./test.exe 
cd ..
ls
 cd Q3/
ls
cat renum_anneau.c 
mpicc renum_anneau.c -o test.exe
mpirun -n 4 ./test.exe 
cd ..
ls
 cd Q4
ls
 cat renum_nproc_anneau.c 
mpicc renum_nproc_anneau.c -o test.exe
mpirun -n 4 ./test.exe 
'cd ..
cd ..
;
cd ..
;s
ls
cd ..
ls
 cd master_slave/
ls
cd exercice/
ls
cat master_slave_exo.c 
cd ..
ls
 cd correction/
ls
cat master_slave_mpi.c 
exit
ls
cd TD2_ENSIIE/
ls
cd ini_nonblock/
ls
 cd exercice/
ls
rm deadlock.c~
ls
rm \#tantque.c# 
ls
rm tantque.c~
ls
cd ..
cd exercice/
ls
 cat deadlock.c 
cd .. 
ls
cd exercice/
ls
 cat deadlock.c 
cd ..
cd ini_nonblock/
ls
 cd correction/
ls
 cat corr1_deadlock.c 
module load mpi/openmpi-x86_64
mpicc corr1_deadlock.c -o test.exe
ls
mpirun -n 2 ./test.exe 
vim corr1_deadlock.c 
mpicc corr1_deadlock.c -o test.exe
vim corr1_deadlock.c 
mpicc corr1_deadlock.c -o test.exe
mpirun -n 2 ./test.exe 
vim corr1_deadlock.c 
mpicc corr1_deadlock.c -o test.exe
mpirun -n 2 ./test.exe 
vim corr1_deadlock.c 
mpicc corr1_deadlock.c -o test.exe
mpirun -n 2 ./test.exe 
vim corr1_deadlock.c 
mpicc corr1_deadlock.c -o test.exe
mpirun -n 2 ./test.exe 
ls
cat corr2_deadlock.c 
ls
cat corr_tantque.c 
cat ../exercice/tantque.c 
ls
 cd ..
ls
cd ..
ls
 cd exo_waitall/
ls
 cat exo_waitall.c 
ls
cd correction/
ls
cat error1_waitall.c 
ls
mpicc error1_waitall.c -o test.exe 
cat  corr_coll_reduction.c 
mpirun -n 4 ./test.exe 
cat error2_waitall.c 
cat correct_waitall.c 
cat correct_recv.c 
ls
 cd ..
ls
 cd ..
ls
 cd convolution/
ls
cd correction/
ls
cd ..
ls
cat convol
cat convol.c 
cat correction/convolAsync.c 
ls
cd TD3_ENSIIE/
ls
cd prod_scal/
ls
cd correction/
ls
 cat corr_prod_scal.c 
ls
cd ..
ls
cd ..
ls
 cd cd prod_scal/
cd prod_scal/
ls
cd correction/
module load mpi/openmpi-x86_64
mpicc corr_prod_scal.c -o test.exe 
mpirun -n 4 ./test.exe 
vim corr_prod_scal.c 
mpicc corr_prod_scal.c -o test.exe 
vim corr_prod_scal.c 
mpicc corr_prod_scal.c -o test.exe 
mpirun -n 4 ./test.exe 
vim corr_prod_scal.c 
cd ../..
ls
cd reduction/
ls
cd correction/
ls
cat corr_coll_reduction.c 
cat corr_pt2pt_reduction.c 
ls
cd ..
ls
 cd ..
ls
 cd pieges_coll/
ls
 cd correction/
ls
cat corr_barriere.c 
cd ..
ls
 cd pieges/
ls
 cat piege_barriere.c 
ls
mpicc piege_barriere.c -o test.exe 
mpirun -n 4 ./test.exe 
cd ..
ls
mpicc correction/corr_barriere.c -o test.exe
mpirun -n 4 ./test.exe 
ls
cd REP_COMMUN/
ls
cd ..
ls
rm -r REP_COMMUN/
ls
cat pieges/piege_scatter.c 
ls
mpicc pieges/piege_scatter.c -o test.exe
mpirun -n 4 ./test.exe 
cat correction/corr_scatter.c 
cat pieges/piege_coll.c 
cat correction/corr_coll.c 
ls
cd pieges/
ls
cat piege_coll.c 
ls
cd ..
cd correction/
ls
cat corr_coll.c 
ls
cd ..
ls
 cd ..
ls
cd algo_bcast/
ls
cd correction/
ls
cat linear_algo.c 
ls
cat btreev2_algo.c 
cd 
cd TD1
cd TD1_ENSIIE/
ls
 cd E3_question_pieges/
ls
 cd corrections/
ls
 cat correctionA.c 
 cat correctionD.c 
cd ..
ls
cd ..
ls
cd RenumAnneau/
ls
cd Q3/
ls
cd ..
ls
cd E4_deadlock/
ls
 cd correction/
ls
 cat echange_buffer.c 
cd 
ls
mkdir test
ls
cp TD1_ENSIIE ./test
cp TD1_ENSIIE.tar ./test
cp TD2_ENSIIE.tar ./test
cp TD3_ENSIIE.tar ./test
cd test/
ls
tar -xf TD1_ENSIIE.tar 
ls
cd TD1_ENSIIE/
ls
 cd prise_en_main/
ls
cd ..
ls
cd prise_en_main/
la
 ls
cat correction
cat correction1.c 
cd
cd test/
cd TD1_ENSIIE/
ls
cd prise_en_main/
ls
vim 1.c
ls
vim 1.c
mpicc 1.c 
vim 1.c
mpicc 1.c 
mpirun -n 4 ./a.out 
vim 1.c 
mpicc 1.c 
mpirun -n 4 ./a.out 
vim 1.c 
mpicc 1.c 
mpirun -n 4 ./a.out 
vim 1.c 
mpicc 1.c 
mpirun -n 4 ./a.out 
cd ..
ls
 cd ping_pong/
ls
cat corr_ping1.c 
vim 1.c
mpicc 1.c 
vim 1.c
mpicc 1.c 
mpirun -n 2 ./a.out 
cd ..
ls
 cd deadlock/
ls
cd correction/
ls
vim deadlock.c 
cat deadlock.c 
cat echange_standard.c 
vim deadlock.c 
mpicc deadlock.c 
mpirun -n 2 ./a.out 
ls
cat echange_buffer.c 
vim deadlock.c 
mpicc deadlock.c 
mpirun -n 2 ./a.out 
vim deadlock.c 
mpicc echange_buffer.c 
mpirun -n 2 ./a.out 
ls
vim deadlock.c 
mpicc deadlock.c 
mpirun -n 2 ./a.out 
cd
ls
cd TD1_ENSIIE/
ls
 cd E4_deadlock/
ls
 cd correction/
ls
mpicc echange_buffer.c 
mpirun -n 2 ./a.out 
mpirun -n 4 ./a.out 
cat echange_buffer.c 
cd
cd test/
ls
 cd TD1_ENSIIE/
ls
 cd deadlock/
ls
 cd correction/
ls
 vim deadlock.c 
mpicc deadlock.c 
 vim deadlock.c 
mpicc deadlock.c 
mpirun -n 2 ./a.out 
cd ..
sl            
cd .
cd ..
ls
 cd ..
ls
 tar -xf TD2_ENSIIE.tar 
ls
cd TD2_ENSIIE/
ls
cd ini_nonblock/
ls
cd exercice/
ls
 vim  deadlock.c 
ls
mpicc deadlock.c 
 vim  deadlock.c 
mpicc deadlock.c 
mpirun -n 2 ./a.out 
 vim  tantque.c 
mpicc tantque.c 
mpirun -n 2 ./a.out 
cd ..
ls
cd correction/
ls
cat corrt
cat corr_tantque.c 
cd 
ls
 exit
ls
cp TD_ENSIIE.tar ./test
 cp /tmp/TD4_ENSIIE.tar .
ls
tar -xf TD4_ENSIIE.tar 
ls
cd TD4_ENSIIE/
ls
cd ReducComplexDdt/
ls
cd correction/
ls
cd ..
ls
emacs max_reduc_complex.c 
ls
cd correction/
ls
emacs max_reduc_complex.c 
ls
cd TD2_ENSIIE/
ls
 cd graphe_comm/
ls
cd correction/
ms
ls
 cat echange_nonbloq.c 
cd ..
ls
cd ..
ls
cd exo_waitall/
ls
 cd correction/
ls
cd
ls
cd TD2_ENSIIE/
ls
 cd convolution/
ls
 cd correction/
ls
 cqt convolAsync.c 
ls
 cat convolAsync.c 
cd ..
cd 
cd TD2_ENSIIE/
ls
cd exo_waitall/
ls
 cat correction/correct_recv.c 
ls
 cp /tmp/TD5_ENSIIE.tar .
ls
exit
ls
exit
ls
 mv main.pdf life_students/
cd life_students/
ls
> module avail mpi
 module avail mpi
module load
mpi
module load mpi
ls
make
module load mpi/openmpi­x86_64
 module avail mpi
module load ...
module load mpi/openmpi­x86_64
module load
module load mpi/openmpi­x86_64
make
 module avail mpi
module load mpi/*
cd
module load mpi/openmpi­x86_64
 cp /tmp/TD3_ENSIIE.tar .
module load mpi/openmpi­x86_64
cd TD4_ENSIIE/
ls
 cd ReducComplexDdt/
ls
 cat max_reduc_complex.c
exit
ls
cd TD4_ENSIIE/
ls
cd ReducComplexDdt/
ls
cd correction/
ls
cat max_reduc_complex.c 
cat max_loc_reduc_complex.c 
cd ..
ls
 cd ..
ls
 cd MatrixComm/
ls
cd correction/
ls
cat matrix_comm.c 
ls
cd ..
ls
 cd ..
ls
cd ..
ls
cd TD5
ls
xpdf TD5.pdf 
pdf TD5.pdf 
open TD5.pdf 
evince TD5.pdf 
pwd
ls
cd Grid/
ls
 cd grid.c
cat grid.c
