default:	Pi_Trapezoidal_Mpi Pi_Trapezoidal_Hyb Pi_Trapezoidal_Vec
all:		Pi_Trapezoidal_Mpi Pi_Trapezoidal_Hyb Pi_Trapezoidal_Vec

Pi_Trapezoidal_Mpi: Pi_Trapezoidal_Mpi.cpp
	mpic++ timer.h Pi_Trapezoidal_Mpi.cpp timer.c -o Pi_Trapezoidal_Mpi

Pi_Trapezoidal_Hyb: Pi_Trapezoidal_Hyb.cpp
	mpic++ timer.h Pi_Trapezoidal_Hyb.cpp timer.c -g -O3 -fstrict-aliasing -ftree-vectorize -march=native -mtune=native -fopt-info-vec-optimized -ftree-vectorizer-verbose=3 -fopt-info-vec -o Pi_Trapezoidal_Hyb

Pi_Trapezoidal_Vec: Pi_Trapezoidal_Vec.cpp
	g++ timer.h Pi_Trapezoidal_Vec.cpp timer.c -g -O3 -fstrict-aliasing -ftree-vectorize -march=native -mtune=native -fopt-info-vec-optimized -ftree-vectorizer-verbose=3 -fopt-info-vec -o Pi_Trapezoidal_Vec
	
clean:
	rm -f Pi_Trapezoidal_Mpi Pi_Trapezoidal_Mpi.o
	rm -f Pi_Trapezoidal_Hyb Pi_Trapezoidal_Hyb.o
	rm -f Pi_Trapezoidal_Vec Pi_Trapezoidal_Vec.o

distclean:
	rm -f Makefile
