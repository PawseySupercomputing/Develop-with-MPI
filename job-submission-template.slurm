#!/bin/bash --login

#SBATCH --nodes=1
#SBATCH --account=courses01
#SBATCH --reservation=courseq
#SBATCH --job-name=MPI-course
#SBATCH --time=00:20:00
#SBATCH --export=NONE

# The arguments to aprun are:
#   -n   the total number of MPI tasks
#   -N   the number of MPI tasks per node (max. 24 on Magnus).

aprun -n 1 -N 1 ./a.out

