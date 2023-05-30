
#include <stdio.h>
#include <mpi.h>
#include <omp.h>
int main(int argc, char *argv[]) {
        int my_id, omp_rank, c;
        int provided, required=MPI_THREAD_FUNNELED;
        MPI_Init_thread(&argc, &argv, required, &provided);
        MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
		#pragma omp parallel reduction(+:c)
		{
			c = omp_get_num_threads();
		}
        #pragma omp parallel private(omp_rank)
        {
                omp_rank = omp_get_thread_num();
                printf("Soy el hilo %d en el proceso %d\n", omp_rank, my_id);
        }
		
		printf("Reducción total de c: %d\n",c);
		
        MPI_Finalize();
}



                  