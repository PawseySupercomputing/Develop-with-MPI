from mpi4py import MPI

comm = MPI.COMM_WORLD
rank = comm.Get_rank()

if rank == 0:
    data = {'a': 7, 'b': 3.14}
    req = comm.isend(data, dest=1, tag=11)
    req.wait()
    print "Hi I am",rank, " and sent data= ", data
elif rank == 1:
    req = comm.irecv(source=0, tag=11)
    data = req.wait()
    print "Hi I am",rank, " and sent data= ", data
