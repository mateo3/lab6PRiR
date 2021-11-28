#include stdio.h
#include mpi.h
#include stdlib.h
#include math.h

int main(int argc, char argv)
{
    int a;
    int N, 
    int tag = 50;
    float pi= 0;
    MPI_Init(&argc, &argv);
    MPI_Status status;
    MPI_Comm_rank(MPI_COMM_WORLD, &a);
    MPI_Comm_size(MPI_COMM_WORLD, &N);
    
   if(a!=0)
    {
        MPI_Recv(&pi, 1, MPI_FLOAT, a-1, tag, MPI_COMM_WORLD, &status);
    }
    pi = pi + powf(-1, a)  (2  (a+1) - 1)  4;
    if(a!=N-1)
    {
        MPI_Send(&pi, 1, MPI_FLOAT, a+1, tag, MPI_COMM_WORLD);
    }
    else
    {
        printf(Przyblizenie PI = %fn, pi);
    }
    MPI_Finalize();
    return 0;
}
