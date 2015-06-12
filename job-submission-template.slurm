#!/bin/bash -l
#SBATCH --nodes=1
#SBATCH --account=courses01
#SBATCH --reservation=courseq
#SBATCH --job-name=MPI-course
#SBATCH --time=00:20:00
#SBATCH --export=NONE

# Change -n for ntasks and -N for ntasks per node.

#Update name of executable here:
EXE="hello-mpi"
aprun -n 1 -d ${OMP_NUM_THREADS} -j 1 ./${EXE}

