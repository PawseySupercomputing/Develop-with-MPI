
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char* argv[]){
	MPI_Init(&argc,&argv);

	int myid, numtasks;
	MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	MPI_Comm_size(MPI_COMM_WORLD,&numtasks);

	char* hostname = (char*) malloc (MPI_MAX_PROCESSOR_NAME*sizeof(char));
	int length;
	MPI_Get_processor_name(hostname,&length);
	printf("Hello from rank %d of %d on host %s with name length %d\n",myid,numtasks,hostname,length);

	MPI_Finalize();
	return 0;


} 
