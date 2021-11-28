#include <stdio.h>
#include "mpi.h"
#include <stdlib.h>
#include <math.h>
float func(float x)
{
    return x*x;
}
int main(int argc, char **argv)
{
    int x;
    int n;
    int tag = 50;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &x);
    MPI_Comm_size(MPI_COMM_WORLD, &n);
    MPI_Status status;
    float wynik = 0, a=1, b=10;
    float var=(b-a)/n;
    if(x==n-1)
    {
        wynik += func(a + (x*var)+1);
        MPI_Send(&wynik, 1, MPI_FLOAT, x-1, tag, MPI_COMM_WORLD);
    }
    if((x>=0) && (x < n - 1))
	{
        MPI_Recv(&wynik, 1, MPI_FLOAT, x+1, tag, MPI_COMM_WORLD, &status);
        wynik += func(a + (x+1)*var);
        if(x!=0)
        {
            MPI_Send(&wynik, 1, MPI_FLOAT, x-1, tag, MPI_COMM_WORLD);
        }
        else
        {
            wynik += (func(a) + func(b))/2;
            printf("Wynik calki = %f\n", var * wynik);
        }
    }
    MPI_Finalize();
    return 0;
}
