CC = cc
F90 = ftn
MPICC = cc
MPIF90 = ftn
CFLAGS= -g
SOURCE=src/Game_of_life_

EXE_PREFIX=game-
all: serial init_mpi mpi_pnt2pnt mpi_collective 

serial:
	$(F90) $(CFLAGS) $(SOURCE)serial.f90 -o $(EXE_PREFIX)serial

init_mpi: 
	$(MPIF90) $(CFLAGS) $(SOURCE)init_mpi.f90 -o $(EXE_PREFIX)init_mpi

mpi_pnt2pnt: 
	$(MPIF90) $(CFLAGS) $(SOURCE)mpi_pnt2pnt.f90 -o $(EXE_PREFIX)mpi_pnt2pnt

mpi_collective:
	$(MPIF90) $(CFLAGS) $(SOURCE)mpi_collective.f90 -o $(EXE_PREFIX)mpi_collective

clean:
	rm -r $(EXE_PREFIX)serial $(EXE_PREFIX)mpi-pnt2pnt $(EXE_PREFIX)mpi_pnt2pnt $(EXE_PREFIX)mpi_collective

