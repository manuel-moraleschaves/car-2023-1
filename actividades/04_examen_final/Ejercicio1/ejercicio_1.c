#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <string.h>


int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    char message[500];
    char temp[50];

    // Por simplicidad se definio un array de tamanio fijo 8
    // y un numero fijo de 4 procesos
    int maxn = 8;
    int size = 4;

    // Segmento local de los datos, con 4 filas y 8 columnas
    int xlocal[size][maxn];

    int rank, nprocs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    if (nprocs != size){
        if (rank == 0){
            printf("Error: Program must be called with 4 processes...\n");
        }
        exit(1);
    }


    // Llenado del segmento de datos local
    sprintf(temp, "Rank %d (before):\n", rank);
    strcat(message, temp);    
    for (int i = 0; i < size; i++){
        for (int j = 0; j < maxn; j++){
            if (i == 0 || i == size-1){
                xlocal[i][j] = -1;
            }
            else {
                xlocal[i][j] = rank;
            }
            sprintf(temp, "% 2d ", xlocal[i][j]); 
            strcat(message, temp);
        }
        sprintf(temp, "\n");
        strcat(message, temp);
    }


    // Intercambio de mensajes
    if (rank == 0){
        MPI_Sendrecv(&xlocal[1], maxn, MPI_INT, 1, 0,
                     &xlocal[size-1], maxn, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    } 
    else if (rank == size-1) {
        MPI_Sendrecv(&xlocal[1], maxn, MPI_INT, size-2, 0,
                     &xlocal[0], maxn, MPI_INT, size-2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    else {
        MPI_Sendrecv(&xlocal[1], maxn, MPI_INT, rank-1, 0,
                     &xlocal[0], maxn, MPI_INT, rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        
        MPI_Sendrecv(&xlocal[1], maxn, MPI_INT, rank+1, 0,
                     &xlocal[size-1], maxn, MPI_INT, rank+1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }


    // Salida final del segmento de datos local en cada rank
    sprintf(temp, "Rank %d (after):\n", rank);
    strcat(message, temp);        
    for (int i = 0; i < size; i++){
        for (int j = 0; j < maxn; j++){
            sprintf(temp, "% 2d ", xlocal[i][j]); 
            strcat(message, temp);
        }
        sprintf(temp, "\n");
        strcat(message, temp);
    }
    printf("%s\n", message);


    MPI_Finalize();
    return 0;
}
