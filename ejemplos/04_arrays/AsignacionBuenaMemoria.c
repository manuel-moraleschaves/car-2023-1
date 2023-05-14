#include <stdlib.h>

int main(int argc, char *argv[])
{
   int imax, jmax;

   // primero se asigna un bloque de memoria para los punteros de columna
   double **x = (double **)malloc(jmax*sizeof(double *));

   // Ahora se asigna el bloque de memoria del array 2D 
   x[0] = (void *)malloc(jmax*imax*sizeof(double));

   // Last, assign the memory location to point to in the block of data for each row pointer
   for (int j = 1; j < jmax; j++) {
      x[j] = x[j-1] + imax;
   }

   // Cálculos o procesos con el array

   // Desasignar memoria
   free(x[0]);
   free(x);
}
    