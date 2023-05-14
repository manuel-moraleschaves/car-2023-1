#include <stdlib.h>
#include "malloc2D.h"

double **malloc2D(int jmax, int imax)
{
   // primero se asigna un bloque de memoria para los punteros de las filas y para el array 2D
   double **x = (double **)malloc(jmax*sizeof(double *) + jmax*imax*sizeof(double));

   // Ahora se asigna el inicio del bloque de memoria para el array 2D después de los punteros de fila
   x[0] = (double *)(x + jmax);

   // Por último, se asigna la localización de memoria para que cada puntero apunte a cada fila 
   for (int j = 1; j < jmax; j++) {
      x[j] = x[j-1] + imax;
   }

   return(x);
}
     