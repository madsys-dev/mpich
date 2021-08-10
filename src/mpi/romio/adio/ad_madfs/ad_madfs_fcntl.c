/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_madfs.h"
#include "adioi.h"
#include "adio_extern.h"

void ADIOI_MADFS_Fcntl(ADIO_File fd, int flag, ADIO_Fcntl_t * fcntl_struct, int *error_code)
{
    int myrank, nprocs;
    static char myname[] = "ADIOI_MADFS_FCNTL";

    *error_code = MPI_SUCCESS;

    MPI_Comm_size(fd->comm, &nprocs);
    MPI_Comm_rank(fd->comm, &myrank);
    FPRINTF(stdout, "[%d/%d] ADIOI_MADFS_Fcntl called on %s\n", myrank, nprocs, fd->filename);

    switch (flag) {
        case ADIO_FCNTL_GET_FSIZE:
            fcntl_struct->fsize = 0;
            *error_code = MPI_SUCCESS;
            break;

        case ADIO_FCNTL_SET_DISKSPACE:
            *error_code = MPI_SUCCESS;
            break;

        case ADIO_FCNTL_SET_ATOMICITY:
            fd->atomicity = (fcntl_struct->atomicity == 0) ? 0 : 1;
            *error_code = MPI_SUCCESS;
            break;

        default:
            /* --BEGIN ERROR HANDLING-- */
            *error_code = MPIO_Err_create_code(MPI_SUCCESS, MPIR_ERR_RECOVERABLE,
                                               myname, __LINE__,
                                               MPI_ERR_ARG, "**flag", "**flag %d", flag);
            return;
            /* --END ERROR HANDLING-- */
    }
}
