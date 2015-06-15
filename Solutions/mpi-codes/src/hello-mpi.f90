program hello
	integer rank,numtasks,mpierr
	call MPI_Init(mpierr)
	call MPI_Comm_size(MPI_COMM_WORLD, numtasks, mpierr)
!call MPI_COMM_RANK(MPI_COMM_WORLD, rank, mpierr)
	!write(*,*) "hello world from " , rank, numtasks
call MPI_FINALIZE(mpierr)
	end
