#!/bin/bash --login

#SBATCH --nodes=1
#SBATCH --account=onlinecourse
#SBATCH --reservation=onlinecourse
#SBATCH --job-name=MPI-course
#SBATCH --time=00:20:00
#SBATCH --export=NONE

srun -n 1 --export=all ./a.out
