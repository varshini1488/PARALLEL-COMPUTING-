#include<stdio.h>
#include<mpi.h>
int main(int argc,char *argv[])
{
    int rank,data_send,data_recv;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    data_send=rank;
    #define size 1000000
    if(rank == 0)
    {
        MPI_Send(&data_send,size,MPI_INT,1,0,MPI_COMM_WORLD);
        MPI_Recv(&data_recv,size,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    }
    else if(rank == 1)
    {
        MPI_Send(&data_send,1,MPI_INT,0,0,MPI_COMM_WORLD);
        MPI_Recv(&data_recv,,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    }
    printf("process %d recieve %d\n",rank,data_recv);
    MPI_Finalize();
    return 0;
}