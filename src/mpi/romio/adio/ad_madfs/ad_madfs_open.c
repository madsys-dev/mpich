/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_madfs.h"
#include "adioi.h"
#include "madfs-posix.h"

extern const MadfsPosix* madfs;

void ADIOI_MADFS_Open(ADIO_File fd, int *error_code)
{
    int myrank, nprocs;

    fd->fd_sys = 1;
    fd->fd_direct = -1;
    *error_code = MPI_SUCCESS;

    MPI_Comm_size(fd->comm, &nprocs);
    MPI_Comm_rank(fd->comm, &myrank);
    FPRINTF(stdout, "[%d/%d] ADIOI_MADFS_Open called on %s\n", myrank, nprocs, fd->filename);
    struct ADIO_MADFS_context* context = (struct ADIO_MADFS_context *) ADIOI_Calloc(1, sizeof(struct ADIO_MADFS_context));
    const INode *parent;
    FPRINTF(stdout, "[%d/%d] fd->fs_ptr set from %p to %p\n", myrank, nprocs, fd->fs_ptr, context);
    fd->fs_ptr = context;
    if (!madfs) {    
        FPRINTF(stdout, "[%d/%d] calling madfs_openfs, madfs = %p\n", myrank, nprocs, madfs);
        madfs_openfs(&madfs);
    } else{
        FPRINTF(stdout, "[%d/%d] skipping madfs_openfs, madfs = %p\n", myrank, nprocs, madfs);
    }
    static char buffer[1000];
    strcpy(buffer, fd->filename);
    char *base = strrchr(buffer, '/');
    if (!base) {
        FPRINTF(stdout, "[%d/%d] path should start from `/` (path = %s)\n", myrank, nprocs, fd->filename);
    }
    *(base++) = '\0';

    madfs_lookup(madfs, buffer, &parent);
    madfs_open(madfs, parent, base, fd->access_mode, 
        O_WRONLY|O_CREAT, 0x100000, &context->inode);
}
