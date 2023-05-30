# Tarea4: Reducción en OMP y MPI (Híbrido)
 
## Descripción de la Tarea

Tome el código ["hola_hibrido.c"](./hola_hibrido.c) y modifíquelo para que los procesos compartan la cantidad de hilos que tiene cada uno con una [reducción de MPI](https://mpitutorial.com/tutorials/mpi-reduce-and-allreduce/) de manera que sólo el proceso 0 reporte la cantidad total de hilos que hay en toda la aplicación.


## Compilación y Ejecución

Para compilar el programa utilizar `make hola_hibrido_reduce` o usar directamente el siguiente comando:
```
mpicc hola_hibrido_reduce.c -g -O3 -fopenmp -o hola_hibrido_reduce
```

Para ejecutar el programa utilizar `make run` o usar directamente el siguiente comando de ejemplo:
```
mpirun -np 4 ./hola_hibrido_reduce
```


## Resultado

Al ejecutar el programa con 16 hilos por nodo este es el resultado obtenido:

```

[curso-726@nu-0c Tarea4]$ export OMP_NUM_THREADS=16

[curso-726@nu-0c Tarea4]$ make run
mpirun -np 4 ./hola_hibrido_reduce

Cantidad de hilos en nodo 0: 16
Cantidad de hilos en nodo 3: 16
Cantidad de hilos en nodo 1: 16
Cantidad de hilos en nodo 2: 16

Cantidad total de hilos en el programa: 64

```


## Créditos
Desarrollado por **Manuel Morales Chaves**.  
<manuel.moraleschaves@ucr.ac.cr>
\
\
Recursos consultados/utilizados:
- [OpenMP](https://www.openmp.org/).
- [MPI Forum](https://www.mpi-forum.org/).
