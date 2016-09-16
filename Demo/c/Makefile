CC = cc
F90 = ftn
MPICC = cc
MPIF90 = ftn
CFLAGS = -g -craype-verbose
SOURCE = src
INC= -I ./include
all: mpi-latency mpi-bandwidth-blocking mpi-bandwidth-nonblocking gaussian-serial gaussian-mpi

mpi-latency: 
	$(CC) $(CFLAGS) $(SOURCE)/mpi_latency.c -o latency
mpi-bandwidth-blocking:
	$(CC) $(CFLAGS) $(SOURCE)/mpi_bandwidth.c -o bandwidth-blocking
mpi-bandwidth-nonblocking:
	$(CC) $(CFLAGS) $(SOURCE)/mpi_bandwidth-nonblock.c -o bandwidth-nonblocking

gaussian-mpi: 
	cc src/gaussian-mpi-version.c src/gauss-main-mpi.c -o gauss-mpi $(INC)

gaussian-serial: 
	cc src/gaussian-serial-version.c src/gauss-main-serial.c -o gauss-serial $(INC)

clean:
	rm -r latency bandwidth-blocking bandwidth-nonblocking gauss-serial gauss-mpi

