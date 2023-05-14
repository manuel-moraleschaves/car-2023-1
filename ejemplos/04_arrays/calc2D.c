#include "malloc2D.h"

int main(int argc, char *argv[])
{
   int i, j;
   int imax=100, jmax=100;

   double **x = (double **)malloc2D(jmax,imax);

   // Acceso de una dimensión al array contiguo de 2D
   double *x1d=x[0];
   for (i = 0; i< imax*jmax; i++){
      x1d[i] = 0.0;
   }

   // acceso normal 2D
   for (j = 0; j< jmax; j++){
      for (i = 0; i< imax; i++){
         x[j][i] = 0.0;
      }
   }

   // Cálculo manual de índices 2D en un array de 1D
   for (j = 0; j< jmax; j++){
      for (i = 0; i< imax; i++){
         x1d[i + imax * j] = 0.0;
      }
   }
}

       