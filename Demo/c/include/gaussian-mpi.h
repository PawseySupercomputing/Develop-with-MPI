#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MASTER 0

typedef struct{
	//Global information for all MPI-tasks
	int neq; 
	int num_row,num_col;
	char* filename;
	//MPI-tasks local information 
	int num_my_col;
	int* col_start_indx;
	float** my_col;
}input;


void* check_malloc(size_t bytes, char* msg);
void check_flag(int flag, int error);
void Read_command_line_arguments(int* argc,char** argv, input* parms);
float** allocate_mat(int,int);
void set_to_default_system(float** A);
void read_in_system(int neq, float** A,char* filename);
void write_out(int neq , float** A);
float* solve(int neq , float** A);
float summation(int,float*, float**);
float* backward_substitution(int,float**);


//Methods for MPI VERSION 
void adjust_chunk_size(int , int , int*, int*);
void distribute_columns(int, int,  float**);
void solve_mpi(int,int);
void gather_columns(int,int,float**);
