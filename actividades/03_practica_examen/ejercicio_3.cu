#include <iostream>
#include <math.h>
#include "cuda.h"

// function to add the elements of two arrays
__global__
void add(int n, float *x, float *y)
{
  for (int i = 0; i < n; i++)
      y[i] = x[i] + y[i];
}

int main(void)
{
  int N = 1<<20; // 1M elements

  //float *x = new float[N];
  //float *y = new float[N];
  float *x;
  float *y;
  cudaMallocManaged (&x, N);
  cudaMallocManaged (&y, N);

  // initialize x and y arrays on the host
  for (int i = 0; i < N; i++) {
    x[i] = 1.0f;
    y[i] = 2.0f;
  }

  size_t threads_per_block = 10;
  size_t number_of_blocks = 10;

  // Run kernel on 1M elements on the CPU
  //add(N, x, y);
  add<<<number_of_blocks, threads_per_block>>>(N, x, y);
  cudaDeviceSynchronize();

  // Check for errors (all values should be 3.0f)
  float maxError = 0.0f;
  for (int i = 0; i < N; i++)
    maxError = fmax(maxError, fabs(y[i]-3.0f));
  std::cout << "Max error: " << maxError << std::endl;

  // Free memory
  //delete [] x;
  //delete [] y;
  cudaFree(x);
  cudaFree(y);

  return 0;
}