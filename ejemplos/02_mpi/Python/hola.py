from mpi4py import MPI
comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()

print("Hola, soy el rank "+ str(rank)+ " de " + str(size) + "\n")
