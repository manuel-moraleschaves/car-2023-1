#include <iostream>
#include <cstdio>
#include "cuda.h"

void helloCPU()
{
  std::cout<<"Hello from Cpu.\n";
}

__global__
void helloGPU()
{
  printf("Hello also from Gpu.\n");
}

int main()
{

  helloCPU();
  helloGPU<<<1,1>>>();
  cudaDeviceSynchronize();

  return EXIT_SUCCESS;
}
