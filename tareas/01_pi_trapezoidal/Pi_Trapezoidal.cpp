// Copyright 2023 Manuel Morales <manuel.moraleschaves@ucr.ac.cr>

#include <mpi.h>
#include <iostream>
#include <iomanip>
#include <math.h>

#define TRAPEZOIDSPERPROCESS 10000
#define DOMAINBEGIN 0.0
#define DOMAINEND 1.0

int main(int argc, char* argv[]) {
    if (MPI_Init(&argc, &argv) == MPI_SUCCESS) {
        int rank = -1;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        int processCount = -1;
        MPI_Comm_size(MPI_COMM_WORLD, &processCount);

        if (processCount < 1) {
            std::cout << "Error: The program must be called with at least one processs..." << std::endl;
            exit(1);
        }

        int trapezoidsTotal = processCount * TRAPEZOIDSPERPROCESS;
        int start = 1;
        int end = TRAPEZOIDSPERPROCESS;

        if (rank > 0) {
            start = rank * TRAPEZOIDSPERPROCESS;
            end = start + TRAPEZOIDSPERPROCESS;
        }

        double trapezoidsLenght = (DOMAINEND - DOMAINBEGIN) / trapezoidsTotal;
        double subDomain = DOMAINBEGIN;
        double sum = 0.0;

        if (rank == 0) {
            std::cout << "\nCalculating PI with " << std::to_string(trapezoidsTotal) << " trapezoids and " <<
                std::to_string(processCount) << " process(es)...\n" << std::endl;
        }

        for (int i = start; i < end; i++) {
            subDomain = i * trapezoidsLenght;
            sum += 4 / (1 + pow(subDomain, 2));
        }

        double totalSum = 0.0;
        MPI_Reduce(&sum, &totalSum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

        if (rank == 0) {
            double fa = 4 / (1 + pow(DOMAINBEGIN, 2));
            double fb = 4 / (1 + pow(DOMAINEND, 2));
            double result = (trapezoidsLenght/2) * (fa + (2*totalSum) + fb);

            std::cout << "Approximation of PI: " << std::fixed << std::setprecision(14) << result << std::endl;
            std::cout << "\nProgram finished...\n" << std::endl;
        }

        MPI_Finalize();
    }

    return 0;
}
