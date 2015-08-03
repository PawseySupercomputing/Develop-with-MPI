# Develop-with-MPI
Exercises for the MPI programming course


Instructions

A number of exercises are used in the course, and are described below.
For each exercise, we have provided a 'stub' code in both ANSI C and
Fortran which can be used as a template for your solution. These stubs
are found in

./Exercises/c
./Exercises/fortran

If you are stuck, a solution can be seen the corresponding directory

./Solutions/c
./Solutions/fortran

All C files should compile with the command

magnus-1:> cc file.c

All Fortran files should compile with the command

magnus-1:> ftn file.f90


* Exercise 1. "Hello World"

- Write an MPI program to print the MPI rank and total number of MPI tasks
  to the screen for all MPI ranks. You will need to use the default MPI
  communicator MPI_COMM_WORLD. Run the program a number of times on
  different numbers of MPI tasks and note the results.

  Additional exercise
  - What happens at run time if you accidentally forget to call MPI_Init()?

* Exercise 2. "Ping-pong"

- Write an MPI program to pass a single integer back and forth between
  exactly two MPI tasks. This should use MPI_Ssend() and MPI_Recv().
  The 'ping-pong' should occur a fixed number of times.

  Additional exercises
  - Rewrite your program to send a message of a different data type,
    e.g., a double precision floating point number.
  - To provide an estimate of the time taken to exchange the message,
    one can use MPI_Wtime(). This MPI function returns a double
    precision value which is the number of seconds since a fixed
    point in the past. To obtain an elapsed time, take a difference:
      tstart = MPI_Wtime()
      ...
      tstop  = MPI_Wtime()
      elapsed = tstop - tstart

    Use MPI_Wtime() to find out how long the ping-pong message exchange
    is taking on the average.

* Exercise 3. "Pass a message around a ring"

- Write an MPI program to compute the sum of the MPI ranks by passing
  a message around in a ring. All ranks should compute and display
  the sum. The message should be exchanged via MPI_Issend() and MPI_Irecv()
  followed by two appropriate calls to MPI_Wait(). This program should
  work for an arbitrary number of MPI tasks.

  Additional exercises
  - Check your results on different numbers of MPI tasks.
  - Does the order of the calls to MPI_Issend() and MPI_Irecv() matter?

* Exercise 4. "Using a Cartesian Communicator"

- Rewrite the program of Exercise 3 using a Cartesian communicator instead
  of MPI_COMM_WORLD.

  Additional exercise
  - What is the result if you define a non-periodic Cartesian communicator?
  - Modify the program to send independent messages in both directions at the
    same time

* Exercise 5. "Using collective communication"

- Write an MPI program to compute and display the sum of the ranks using:
  a. MPI_Reduce()
  b. MPI_Allreduce()

* Exercise 6. "John Conway's Game of Life"

- This exercise puts together all the things covered in the exercises
  above to write an MPI version of this simple cellular automata. We
  provide a serial version which is written in such a way as to make
  the parallelisation as simple as possible. We suggest you make a
  copy of this version as a basis of a parallel version.

  Note:
  - A file life.ref is also provided which gives the reference output
    which a correct parallel version should reproduce (minus the ascii
    representation of the grid) from the given initial conditions.
  - We suggest you try a one-dimensional domain decomposition in the
    x-direction first.
  - The initial conditions are, in general, a little awkward. If you
    place the initial live cells in the left-hand local domain, you
    should be able to get the message passing etc working first for
    two MPI tasks.
