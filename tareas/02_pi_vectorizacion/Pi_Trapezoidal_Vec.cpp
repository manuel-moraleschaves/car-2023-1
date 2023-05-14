// Copyright 2023 Manuel Morales <manuel.moraleschaves@ucr.ac.cr>

#include <iostream>
#include <iomanip>
#include <math.h>
#include "timer.h"

#define DOMAINBEGIN 0.0
#define DOMAINEND 1.0

int main(int argc, char* argv[]) {

    int trapezoidsTotal = 80000;
    if (argc == 2) {
        if (sscanf(argv[1], "%d", &trapezoidsTotal) != 1 || errno) {
            std::cout << "Error: Invalid number of trapezoids..." << std::endl;
            exit(1);
        }
    }

    double trapezoidsLenght = (DOMAINEND - DOMAINBEGIN) / trapezoidsTotal;
    double sum = 0.0;

    double* __restrict__ vec = (double*) malloc(sizeof(double) * trapezoidsTotal);

    struct timespec tstart;
    double elapsed_time = 0.0;    
    cpu_timer_start(&tstart);

    std::cout << "\nCalculating PI with " << std::to_string(trapezoidsTotal) << " trapezoids using Vectorization...\n" << std::endl;

    #pragma omp simd reduction(+:sum)
    for (int i = 1; i < trapezoidsTotal; i++) {
        vec[i] = 4 / (1 + pow(i * trapezoidsLenght, 2));
        sum += vec[i];
    }
    
    double fa = 4 / (1 + pow(DOMAINBEGIN, 2));
    double fb = 4 / (1 + pow(DOMAINEND, 2));
    double result = (trapezoidsLenght/2) * (fa + (2*sum) + fb);

    elapsed_time = cpu_timer_stop(tstart);

    std::cout << "Approximation of PI: " << std::fixed << std::setprecision(14) << result << std::endl;
    std::cout << "\nProgram finished in " << std::fixed << std::setprecision(8) << elapsed_time << " secs ...\n" << std::endl;

    free(vec);

    return 0;
}