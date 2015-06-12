CC = cc
F90 = ftn
MPICC = cc
MPIF90 = ftn
CFLAGS= -g
SOURCE=src/Game_of_life_

EXE_PREFIX=game-
all: serial init_mpi mpi_pnt2pnt mpi_collective 

serial:
	$(CC) $(CFLAGS) $(SOURCE)serial.c -o $(EXE_PREFIX)serial

init_mpi: 
	$(CC) $(CFLAGS) $(SOURCE)init_mpi.c -o $(EXE_PREFIX)init_mpi

mpi_pnt2pnt: 
	$(CC) $(CFLAGS) $(SOURCE)mpi_pnt2pnt.c -o $(EXE_PREFIX)mpi_pnt2pnt

mpi_collective:
	$(CC) $(CFLAGS) $(SOURCE)mpi_collective.c -o $(EXE_PREFIX)mpi_collective

clean:
	rm -r $(EXE_PREFIX)serial $(EXE_PREFIX)mpi-pnt2pnt $(EXE_PREFIX)mpi_pnt2pnt $(EXE_PREFIX)mpi_collective

