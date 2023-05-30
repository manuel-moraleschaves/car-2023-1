# Tarea3: OMP
 
## Descripción de la Tarea

Paralelice el siguiente código de multiplicación de matrices utilizando OpenMP:

```

for (i=0; i< Ndim ; i++) {
	for (j=0; j< Mdim ; j++) {
		tmp = 0.0;
		for (k=0;k< Pdim ;k++) {
			/* C(i,j) = sum( over k) A(i,k) * B(k,j) */
			tmp += *(A+(i* Ndim +k)) * *(B+(k* Pdim +j));
		}
		*(C+(i* Ndim +j)) = tmp;
	}
}

```


## Pseudocódigo con OMP

```

#pragma omp parallel for
for (i=0; i< Ndim ; i++) {
	for (j=0; j< Mdim ; j++) {
		tmp = 0.0;
		for (k=0;k< Pdim ;k++) {
			/* C(i,j) = sum( over k) A(i,k) * B(k,j) */
			#pragma omp critical
			tmp += *(A+(i* Ndim +k)) * *(B+(k* Pdim +j));
		}
		*(C+(i* Ndim +j)) = tmp;
	}
}

```



## Test

Se realizaron varias [pruebas](./Test/) y se identificó que la [Opción 3](#opción-3) fue la que mejor resultados presentó, por lo que ese es el pseudocódigo presentado anteriormente.

### [Opción 1](./Test/Ejercicio_OMP.c)

```

[curso-726@nu-0b OMP]$ gcc timer.h Ejercicio_OMP.c timer.c -g -O3 -fopenmp -o Ejercicio_OMP

[curso-726@nu-0b OMP]$ ./Ejercicio_OMP

Runtime is 209.331930 msecs

```

### [Opción 2](./Test/Ejercicio_OMP2.c)
```

[curso-726@nu-0b OMP]$ gcc timer.h Ejercicio_OMP2.c timer.c -g -O3 -fopenmp -o Ejercicio_OMP2

[curso-726@nu-0b OMP]$ ./Ejercicio_OMP2

Runtime is 5.130520 msecs

```

### [Opción 3](./Test/Ejercicio_OMP3.c)

```

[curso-726@nu-0b OMP]$ gcc timer.h Ejercicio_OMP3.c timer.c -g -O3 -fopenmp -o Ejercicio_OMP3

[curso-726@nu-0b OMP]$ ./Ejercicio_OMP3

Runtime is 3.013350 msecs

```


## Créditos
Desarrollado por **Manuel Morales Chaves**.  
<manuel.moraleschaves@ucr.ac.cr>
\
\
Recursos consultados/utilizados:
- [OpenMP](https://www.openmp.org/).
