#!/bin/bash

#SBATCH --job-name=mpprime

#SBATCH --ntasks=1
#SBATCH --cpus-per-task=16

date

# Compile sequential program
gcc -std=gnu99 -lm 1-simple.c -o 1-simple

# Compile thread program
gcc -std=gnu99 -pthread -lm 2-thread.c -o 2-thread

# Compile OpenMP program
gcc -fopenmp -std=gnu99 -lm 3-openmp.c -o 3-openmp

START=100000000
END=100005000
THREAD=16

echo *** EXECUTING SEQUENTIAL PROGRAM ***
/usr/bin/time -f 'Elapsed: %e, CPU Time: %U' ./1-simple ${START} ${END}
echo
echo *** EXECUTING THREADED PROGRAM ***
/usr/bin/time -f 'Elapsed: %e, CPU Time: %U' ./2-thread ${START} ${END} ${THREAD}
echo
echo *** EXECUTING OPENMP PROGRAM ***
/usr/bin/time -f 'Elapsed: %e, CPU Time: %U' ./3-openmp ${START} ${END}
