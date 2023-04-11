// Copyright 2023 Manuel Morales <manuel.moraleschaves@ucr.ac.cr>
// Actividad 1 - Ping Pong

#include <mpi.h>
#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]) {
    if (MPI_Init(&argc, &argv) == MPI_SUCCESS) {
        int rank = -1;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        int processCount = -1;
        MPI_Comm_size(MPI_COMM_WORLD, &processCount);

        if (processCount != 2) {
            std::cout << "The program needs exactly 2 processes... " << std::endl;
            exit(1);
        }

        int n = 0;

        while(n < 1000) {
            if (rank == 0) {
                MPI_Send(&n, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
                MPI_Recv(&n, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                std::cout << "Process 0: Received number " + std::to_string(n) << std::endl;;
            } else {
                MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                n++;
                MPI_Send(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
            }            
        }

        if (rank == 0) {
            std::cout << "Process finished..." << std::endl;
        }

        MPI_Finalize();
    }

    return 0;
}
