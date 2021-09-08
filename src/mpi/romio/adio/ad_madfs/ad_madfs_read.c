/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_madfs.h"
#include "adioi.h"

#include "madfs-posix.h"
extern const MadfsPosix* madfs;

void ADIOI_MADFS_ReadContig(ADIO_File fd, void *buf, int count,
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
    FPRINTF(stdout, "[%d/%d] ADIOI_MADFS_ReadContig called on %s\n", myrank, nprocs, fd->filename);
    if (file_ptr_type != ADIO_EXPLICIT_OFFSET) {
        offset = fd->fp_ind;
        fd->fp_ind += datatype_size * count;
        fd->fp_sys_posn = fd->fp_ind;
    } else {
        fd->fp_sys_posn = offset + datatype_size * count;
    }

    FPRINTF(stdout, "[%d/%d]    reading (buf = %p, loc = %lld, sz = %lld)\n",
            myrank, nprocs, buf, (long long) offset, (long long) datatype_size * count);
    struct ADIO_MADFS_context* context = fd->fs_ptr;
    uintptr_t len;
    madfs_read(madfs, context->inode, offset, buf, datatype_size * count, &len);
    FPRINTF(stdout, "[%d/%d]    ... %ld bytes read.\n", myrank, nprocs, len);
#ifdef HAVE_STATUS_SET_BYTES
    MPIR_Status_set_bytes(status, datatype, datatype_size * count);
#endif
}

void ADIOI_MADFS_ReadStrided(ADIO_File fd, void *buf, int count,
                              MPI_Datatype datatype, int file_ptr_type,
                              ADIO_Offset offset, ADIO_Status * status, int
                              *error_code)
{
    int myrank, nprocs;

    *error_code = MPI_SUCCESS;

    MPI_Comm_size(fd->comm, &nprocs);
    MPI_Comm_rank(fd->comm, &myrank);
    FPRINTF(stdout, "[%d/%d] ADIOI_MADFS_ReadStrided called on %s\n", myrank,
            nprocs, fd->filename);
    FPRINTF(stdout, "[%d/%d]    calling ADIOI_GEN_ReadStrided\n", myrank, nprocs);

    ADIOI_GEN_ReadStrided(fd, buf, count, datatype, file_ptr_type, offset, status, error_code);
}
