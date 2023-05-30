default:	hola_hibrido hola_hibrido_reduce
all:		hola_hibrido hola_hibrido_reduce

hola_hibrido: hola_hibrido.c
	mpicc hola_hibrido.c -g -O3 -fopenmp -o hola_hibrido

hola_hibrido_reduce: hola_hibrido_reduce.c
	mpicc hola_hibrido_reduce.c -g -O3 -fopenmp -o hola_hibrido_reduce

clean:
	rm -f hola_hibrido hola_hibrido.o
	rm -f hola_hibrido_reduce hola_hibrido_reduce.o

run:
	mpirun -np 4 ./hola_hibrido_reduce
