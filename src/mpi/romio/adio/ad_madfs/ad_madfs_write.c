/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_madfs.h"
#include "adioi.h"

#include "madfs-posix.h"
extern const MadfsPosix* madfs;

void ADIOI_MADFS_WriteContig(ADIO_File fd, const void *buf, int count,
                              MPI_Datatype datatype, int file_ptr_type,
                              ADIO_Offset offset, ADIO_Status * status, int
                              *error_code)
{
    int myrank, nprocs;
    MPI_Count datatype_size;

    *error_code = MPI_SUCCESS;

    MPI_Comm_size(fd->comm, &nprocs);
    MPI_Comm_rank(fd->comm, &myrank);
    MPI_Type_size_x(datatype, &datatype_size);
    FPRINTF(stdout, "[%d/%d] ADIOI_MADFS_WriteContig called on %s\n", myrank,
            nprocs, fd->filename);
    FPRINTF(stdout, "[%d/%d]    writing (buf = %p, loc = %lld, sz = %lld)\n",
            myrank, nprocs, buf, (long long) offset, (long long) datatype_size * (long long) count);
    struct ADIO_MADFS_context *context = fd->fs_ptr;
    uintptr_t len;
    madfs_write(madfs, context->inode, offset, buf, datatype_size * count, &len);
    FPRINTF(stdout, "[%d/%d]    ... write %ld bytes\n", myrank, nprocs, len);

    if (file_ptr_type != ADIO_EXPLICIT_OFFSET) {
        fd->fp_ind += datatype_size * count;
        fd->fp_sys_posn = fd->fp_ind;
        FPRINTF(stdout, "[%d/%d]    new file position is %lld\n", myrank,
                nprocs, (long long) fd->fp_ind);
    } else {
        fd->fp_sys_posn = offset + datatype_size * count;
    }

#ifdef HAVE_STATUS_SET_BYTES
    MPIR_Status_set_bytes(status, datatype, datatype_size * count);
#endif
}

void ADIOI_MADFS_WriteStrided(ADIO_File fd, const void *buf, int count,
                               MPI_Datatype datatype, int file_ptr_type,
                               ADIO_Offset offset, ADIO_Status * status, int *error_code)
{
    int myrank, nprocs;

    *error_code = MPI_SUCCESS;

    MPI_Comm_size(fd->comm, &nprocs);
    MPI_Comm_rank(fd->comm, &myrank);
    FPRINTF(stdout, "[%d/%d] ADIOI_MADFS_WriteStrided called on %s\n",
            myrank, nprocs, fd->filename);
    FPRINTF(stdout, "[%d/%d]    calling ADIOI_GEN_WriteStrided\n", myrank, nprocs);

    ADIOI_GEN_WriteStrided(fd, buf, count, datatype, file_ptr_type, offset, status, error_code);
}
