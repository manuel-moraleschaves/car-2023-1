#include <mpi.h>
#include <stdio.h>

#define SENDER 0
#define RECEIVER 1

void run() {
    // Get the rank of the process
    int local_rank = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &local_rank);

    int number = 0;

    // Stop at ping pong 1000
    while(number < 1000) {
        if(local_rank == 0) {
            // Send a ping
            MPI_Send(&number, 1, MPI_INT, RECEIVER, 0, MPI_COMM_WORLD);
            // Wait for the pong
            MPI_Recv(&number, 1, MPI_INT, RECEIVER, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("[0] Received number %d\n", number);
        }
        else if (local_rank == 1) {
            // Wait for the ping and increment 1
            MPI_Recv(&number, 1, MPI_INT, SENDER, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            number += 1;
            // Send the pong
            MPI_Send(&number, 1, MPI_INT, SENDER, 0, MPI_COMM_WORLD);
        }
    }
}

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size = 0;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    if(world_size == 2) {
        run();
    }
    else {
        printf("Exactly 2 processes are needed in this program.\n");
    }

    // Finalize the MPI environment.
    MPI_Finalize();
}
