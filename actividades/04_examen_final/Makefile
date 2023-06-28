default:	ejercicio1 ejercicio2 ejercicio3
all:		ejercicio1 ejercicio2 ejercicio3

ejercicio1: ./Ejercicio1/ejercicio_1.c
	mpicc ./Ejercicio1/ejercicio_1.c -g -O3 -o ./Ejercicio1/ejercicio_1

run1:
	mpirun -np 4 ./Ejercicio1/ejercicio_1

ejercicio2: ./Ejercicio2/pi_mc.c
	gcc ./Ejercicio2/random.h ./Ejercicio2/pi_mc.c ./Ejercicio2/random.c -fopenmp -g -O3 -o ./Ejercicio2/pi_mc

run2:
	./Ejercicio2/pi_mc

ejercicio3: ./Ejercicio3/loop-stride.cu
	nvcc ./Ejercicio3/loop-stride.cu -arch=compute_35 -g -O3 -o ./Ejercicio3/loop-stride

run3:
	./Ejercicio3/loop-stride

clean:
	rm -f ./Ejercicio1/ejercicio_1 ./Ejercicio1/ejercicio_1.o
	rm -f ./Ejercicio2/pi_mc ./Ejercicio2/pi_mc.o
	rm -f ./Ejercicio3/loop-stride ./Ejercicio3/loop-stride.o