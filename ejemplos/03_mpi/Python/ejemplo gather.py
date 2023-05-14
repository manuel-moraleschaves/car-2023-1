from mpi4py import MPI

comm = MPI.COMM_WORLD
size = comm.Get_size()
rank = comm.Get_rank()

datos = (int(rank)+1)**2 

fin = comm.gather(datos, root=0)


print("Rank " + str(rank) + " --> datos: " + str(fin))