
#include <stdio.h>
#include <mpi.h>
#include <omp.h>

int main(int argc, char *argv[]) {
        int my_id, c = 0, total_threads = 0;
        int provided, required=MPI_THREAD_FUNNELED;

        MPI_Init_thread(&argc, &argv, required, &provided);
        MPI_Comm_rank(MPI_COMM_WORLD, &my_id);

		#pragma omp parallel reduction(+:c)
		{
			c = 1;
		}

		printf("Cantidad de hilos en nodo %d: %d\n", my_id, c);

        MPI_Reduce(&c, &total_threads, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

        if (my_id == 0) {
            printf("\nCantidad total de hilos en el programa: %d\n", total_threads);
        }

        MPI_Finalize();
}
     