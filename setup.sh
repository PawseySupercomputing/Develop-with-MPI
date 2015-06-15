#!/bin/bash

CWD=$PWD
SOL="${CWD}/Solutions"
WB="${CWD}/workbench"

NUM_EXER=6


if [ ! -d ${WB} ]; then
	mkdir -p ${WB}
fi

for (( i=1 ; i<=${NUM_EXER}; i++ ))
	do
	mkdir -p ${WB}/exercise${i}/c
	mkdir -p ${WB}/exercise${i}/ftn
done

#copy sources

echo -e "/* Exercise 1 \n * Write a hello world program which show rank of each \n * participating process and the total number of tasks.*/">> ${WB}/exercise1/c/hello-mpi.c
cp ${SOL}/mpi-codes/makefiles/hello-world ${WB}/exercise1/c/Makefile

echo -e "/* Exercise 2 \n * Write a mpi program with a maximum of 2 processes which send and receive \n * a message until one of the two reaches a limit and both processes exit.*/">> ${WB}/exercise2/c/pingpong.c
cp ${SOL}/mpi-codes/makefiles/pingpong ${WB}/exercise2/c/Makefile

for (( i=3; i<=6; i++ ))
do 
	cp ${SOL}/Game_of_life_solution/c/src/Game_of_life_serial.c ${WB}/exercise${i}/c/Game_of_life.c
	cp ${SOL}/Game_of_life_solution/c/makefiles/makefile ${WB}/exercise${i}/c/Makefile
	cp ${SOL}/Game_of_life_solution/ftn/src/Game_of_life_serial.f90 ${WB}/exercise${i}/ftn/Game_of_life.f90
	cp ${SOL}/Game_of_life_solution/ftn/makefiles/makefile ${WB}/exercise${i}/ftn/Makefile
done
