#include <cstdio>
#include "cuda.h"

void init(int *a, int N)
{
  for (int i = 0; i < N; ++i) {
    a[i] = i;
  }
}

/*
	Cree una función que duplique cada uno de los elementos del array a de forma paralela, cada hilo debe de trabajar sobre más de un elemento. No cambie el N ni el tamaño del grid de hilos
*/
__global__
void doubleElements(int *a, int N)
{
  for (int i = blockIdx.x*blockDim.x + threadIdx.x; i < N; i += blockDim.x*gridDim.x) {
    a[i] *= 2;
  }
}

bool checkElementsAreDoubled(int *a, int N)
{
  for (int i = 0; i < N; ++i) {
    if (a[i] != i*2) {
      return false;
    }
  }
  return true;
}

int main()
{
  /*
   * 'N' is greater than the size of the grid (see below).
   */

  int N = 10000;
  int *a;

  size_t size = N * sizeof(int);
  cudaMallocManaged(&a, size);

  init(a, N);

  /*
   * The size of this grid is 256*32 = 8192.
   */

  size_t threads_per_block = 256;
  size_t number_of_blocks = 32;

  printf("Starting...\n\n");
  doubleElements<<<number_of_blocks, threads_per_block>>>(a, N);
  cudaDeviceSynchronize();

  bool areDoubled = checkElementsAreDoubled(a, N);
  printf("All elements were doubled? %s\n", areDoubled ? "TRUE" : "FALSE");

  cudaFree(a);
}
