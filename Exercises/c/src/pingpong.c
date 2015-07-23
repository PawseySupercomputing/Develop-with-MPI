#include <mpi.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Pingpong_limit 10

int main (int argc, char* argv[]){
	MPI_Init(&argc,&argv);
	double t = MPI_Wtime();
	int myid, numtasks, limit;
	MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	MPI_Comm_size(MPI_COMM_WORLD,&numtasks);

	int SENDER=1,count=0;	
	if (numtasks != 2){
		printf ("Number of MPI-tasks must be equal to 2\n");
		MPI_Abort(MPI_COMM_WORLD,1);	
	}

	while ( count != Pingpong_limit){	
		if (myid == SENDER){
			printf("\n[%d] Sending Ping number %d \n",myid,count);
			MPI_Send(&count,1,MPI_INT,!myid,0,MPI_COMM_WORLD);
		}
		else if (myid != SENDER){
			MPI_Recv(&count,1,MPI_INT,!myid,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			printf("[%d] Recived Ping number %d \n",myid,count);
		}
		count++;
		SENDER= !SENDER;
	}
	t=MPI_Wtime()-t;
	printf("[%d]: Elapsed time = %f seconds\n",myid,t);

	MPI_Finalize();
	return 0;


} 
