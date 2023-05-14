#include <stdlib.h>

int main(int argc, char *argv[])
{
  int j, imax, jmax;

  // primero se asigna una columna de punteros de tipo puntero a double
  double **x = (double **)malloc(jmax * sizeof(double *));

  // ahora se asigna cada fila de datos
  for (j=0; j<jmax; j++){
     x[j] = (double *)malloc(imax * sizeof(double));
  }

  // Cálculos o procesos con el array

  for (j=0; j<jmax; j++){
     free(x[j]);
  }
  free(x);
}

              