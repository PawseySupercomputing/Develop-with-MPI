#include <mpi.h>
#include <stdio.h>
/*
  ! An MPI program to send a message back and forth between two ranks
  ! using a blocking, synchronous send mpi_ssend(), and a blocking
  ! recieve mpi_recv().
*/

int main (int argc, char* argv[]){

        int nexchange = 100;
        int i, rank, size;

//  Message information (here type MPI_INTEGER)
   
        int sender, recver;
        int sendbuffer, recvbuffer;
        MPI_Status status;
        int my_tag = 9999;

//loop counter
        int n;

	MPI_Init(&argc,&argv);

	double t = MPI_Wtime();
	
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

        if (size != 2){
           printf("Must use exactly two MPI tasks\n");
           MPI_Abort(MPI_COMM_WORLD, 1);
        }

//The message is fixed
       sendbuffer = 1;

        for(i = 0; i< nexchange; i++){
           
           // The sender and recver alternate between rank 0 and 1
           sender = i % 2;
           recver = 1 - sender;

           if ( rank == sender ){
              MPI_Ssend(&sendbuffer, 1, MPI_INT, recver, my_tag, MPI_COMM_WORLD);
           }
           else {
              MPI_Recv(&recvbuffer, 1, MPI_INT, sender, my_tag, MPI_COMM_WORLD, &status);
          }

        }
  
	t=MPI_Wtime()-t;
        
        printf("Rank %d took %f seconds\n",rank,t);

	MPI_Finalize();
	return 0;


} 
