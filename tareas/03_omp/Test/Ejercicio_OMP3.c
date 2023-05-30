#include <stdio.h>
#include <omp.h>
#include "timer.h"

#define ARRAY_SIZE 8000000

double A[ARRAY_SIZE];
double B[ARRAY_SIZE];
double C[ARRAY_SIZE];

int main(int argc, char *argv[]){
   int Ndim = 10000;
   int Mdim = 5000;
   int Pdim = 2000;

   //double *A;
   //double *B;

   for (int m=0; m<ARRAY_SIZE; m++){
      A[m] = m;
      B[m] = m + 1;
   }

   struct timespec tstart;
   double time_sum = 0.0;
   cpu_timer_start(&tstart);

   #pragma omp parallel for
   for (int i=0; i< Ndim ; i++) {
      for (int j=0; j< Mdim ; j++) {
         double tmp = 0.0;
         for (int k=0;k< Pdim ;k++) {
            /* C(i,j) = sum( over k) A(i,k) * B(k,j) */
			#pragma omp critical
            tmp += (A[i+ Ndim +k]) * (B[k+ Pdim +j]);
         }
         C[i+ Ndim +j] = tmp;
      }
   }

   time_sum += cpu_timer_stop(tstart);
   printf("Runtime is %lf msecs\n", time_sum);
}
