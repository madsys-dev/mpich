/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_madfs.h"
#include "adioi.h"
#include "madfs.h"

const char* parent_directory(const char* filename) {
    static char buffer[1000];
    strcpy(buffer, filename);
    char *pos = strrchr(buffer, '/');
    if (pos) {
        *pos = '\0';
    }
    return buffer;
}

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
    INode parent;
    fd->fs_ptr = context;
    madfs_openfs(&context->madfs);
    madfs_lookup(context->madfs, parent_directory(fd->filename), &parent);
    madfs_open(context->madfs, parent, fd->filename, fd->access_mode, 
        O_WRONLY|O_CREAT, 0x100000, &context->inode);
}
