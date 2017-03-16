CC = cc
F90 = ftn
MPICC = $(CC)
MPIF90 = $(F90)

ifeq ($(PE_ENV),CRAY)
	CFLAGS=-G2
else  
	CFLAGS = -g -std=gnu99
endif


SOURCE = src
INC= -I ./include
all: mpi_latency mpi_bandwidth_blocking mpi_bandwidth_nonblocking gaussian_serial gaussian_mpi cart_shift dims_test

mpi_latency: 
	$(CC) $(CFLAGS) $(SOURCE)/mpi_latency.c -o latency
mpi_bandwidth_blocking:
	$(CC) $(CFLAGS) $(SOURCE)/mpi_bandwidth.c -o bandwidth-blocking
mpi_bandwidth_nonblocking:
	$(CC) $(CFLAGS) $(SOURCE)/mpi_bandwidth-nonblock.c -o bandwidth-nonblocking

gaussian_mpi: 
	$(CC) $(CFLAGS) $(SOURCE)/gaussian-mpi-version.c $(SOURCE)/gauss-main-mpi.c -o gauss-mpi $(INC) 

gaussian_serial: 
	$(CC) $(CFLAGS) $(SOURCE)/gaussian-serial-version.c $(SOURCE)/gauss-main-serial.c -o gauss-serial $(INC)
cart_shift:
	$(CC) $(CFLAGS) cart_shift.c -o cart_shift
dims_test:
	$(CC) $(CFLAGS) dims_test.c -o dims_test

clean:
	rm -r latency bandwidth-blocking bandwidth-nonblocking gauss-serial gauss-mpi cart_shift dims_test

