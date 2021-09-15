/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_madfs.h"
#include "adioi.h"

void ADIOI_MADFS_Flush(ADIO_File fd, int *error_code)
{
    int myrank, nprocs;

    *error_code = MPI_SUCCESS;

    MPI_Comm_size(fd->comm, &nprocs);
    MPI_Comm_rank(fd->comm, &myrank);
    FPRINTF(stdout, "[%d/%d] ADIOI_MADFS_Flush called on %s\n", myrank, nprocs, fd->filename);
}
