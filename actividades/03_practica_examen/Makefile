default:	ejercicio1 ejercicio2 ejercicio3
all:		ejercicio1 ejercicio2 ejercicio3

ejercicio1: ejercicio_1.c
	mpicc ejercicio_1.c -g -O3 -o ejercicio_1

run1:
	mpirun -np 4 ./ejercicio_1

ejercicio2: ejercicio_2.c
	gcc ejercicio_2.c -g -O3 -fopenmp -o ejercicio_2

run2:
	./ejercicio_2

ejercicio3: ejercicio_3.cu
	nvcc ejercicio_3.cu -arch=compute_35 -g -O3 -o ejercicio_3

run3:
	./ejercicio_3

clean:
	rm -f ejercicio_1 ejercicio_1.o
	rm -f ejercicio_2 ejercicio_2.o
	rm -f ejercicio_3 ejercicio_3.o