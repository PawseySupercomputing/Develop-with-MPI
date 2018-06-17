#!/bin/bash --login

#SBATCH --nodes=1
#SBATCH --account=courses01
#SBATCH --reservation=courseq
#SBATCH --job-name=MPI-course
#SBATCH --time=00:20:00
#SBATCH --export=NONE

srun -n 1 --export=all ./a.out
