#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int rank, nprocs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    if (nprocs <= 1){
        if (rank == 0){
            printf("Error: Must be called with at least two processes...\n");
        }
        exit(1);
    }

    /*int number = 0;
    if (argc == 2 && rank == 0) {
        if (sscanf(argv[1], "%d", &number) != 1 || errno) {
            fprintf(stderr, "Invalid number.\n");
            exit(2);
        }
    }*/

    int number = 0;
    if (rank == 0) {
        printf("Enter a number: \n");
        if (scanf("%d", &number) != 1 || errno) {
            fprintf(stderr, "Invalid number...\n");
            exit(2);
        }
    }

    MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Rank %d: number %d\n", rank, number);

    MPI_Finalize();
    return 0;
}
