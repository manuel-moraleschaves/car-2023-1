#include <stdio.h>

__global__ void print_kernel() {
    printf("Hola desde el bloque %d, hilo %d\n", blockIdx.x, threadIdx.x);
}

int main() {
    print_kernel<<<10, 10>>>();
    cudaDeviceSynchronize();
}