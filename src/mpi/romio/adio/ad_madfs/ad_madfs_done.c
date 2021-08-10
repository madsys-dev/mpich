/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_madfs.h"
#include "adioi.h"

int ADIOI_MADFS_ReadDone(ADIO_Request * request, ADIO_Status * status, int
                          *error_code)
{
    int myrank, nprocs;

    *error_code = MPI_SUCCESS;

    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    FPRINTF(stdout, "[%d/%d] ADIOI_MADFS_ReadDone called on ADIO_REQUEST_NULL\n", myrank, nprocs);
    return 1;
}


int ADIOI_MADFS_WriteDone(ADIO_Request * request, ADIO_Status * status, int
                           *error_code)
{
    int myrank, nprocs;

    *error_code = MPI_SUCCESS;

    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    FPRINTF(stdout, "[%d/%d] ADIOI_MADFS_WriteDone called on ADIO_REQUEST_NULL\n", myrank, nprocs);
    return 1;
}
