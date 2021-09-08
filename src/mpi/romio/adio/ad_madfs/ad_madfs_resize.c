/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_madfs.h"
#include "adioi.h"

void ADIOI_MADFS_Resize(ADIO_File fd, ADIO_Offset size, int *error_code)
{
    int myrank, nprocs;
    *error_code = MPI_SUCCESS;
    MPI_Comm_size(fd->comm, &nprocs);
    MPI_Comm_rank(fd->comm, &myrank);
    FPRINTF(stdout, "[%d/%d] ADIOI_MADFS_Resize called on %s\n", myrank, nprocs, fd->filename);
}
