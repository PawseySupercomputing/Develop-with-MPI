CC = cc
F90 = ftn
MPICC = cc
MPIF90 = ftn
CFLAGS= -g
SOURCE=src

all: hello pingpong 

hello:
	$(CC) $(CFLAGS) $(SOURCE)/hello-mpi.c -o hello-mpi
pingpong:
	$(CC) $(CFLAGS) $(SOURCE)/pingpong.c -o pingpong-mpi
clean:
	rm -r hello-mpi pingpong-mpi 
