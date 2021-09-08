/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#ifndef AD_MADFS_H_INCLUDED
#define AD_MADFS_H_INCLUDED

#include "adio.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <madfs-posix.h>

struct ADIO_MADFS_context {
    const INode *inode;
};


void ADIOI_MADFS_Open(ADIO_File fd, int *error_code);
void ADIOI_MADFS_Close(ADIO_File fd, int *error_code);
void ADIOI_MADFS_ReadContig(ADIO_File fd, void *buf, int count,
                             MPI_Datatype datatype, int file_ptr_type,
                             ADIO_Offset offset, ADIO_Status * status, int
                             *error_code);
void ADIOI_MADFS_WriteContig(ADIO_File fd, const void *buf, int count,
                              MPI_Datatype datatype, int file_ptr_type,
                              ADIO_Offset offset, ADIO_Status * status, int
                              *error_code);
void ADIOI_MADFS_IwriteContig(ADIO_File fd, const void *buf, int count,
                               MPI_Datatype datatype, int file_ptr_type,
                               ADIO_Offset offset, ADIO_Request * request, int
                               *error_code);
void ADIOI_MADFS_IreadContig(ADIO_File fd, void *buf, int count,
                              MPI_Datatype datatype, int file_ptr_type,
                              ADIO_Offset offset, ADIO_Request * request, int
                              *error_code);
int ADIOI_MADFS_ReadDone(ADIO_Request * request, ADIO_Status * status, int
                          *error_code);
int ADIOI_MADFS_WriteDone(ADIO_Request * request, ADIO_Status * status, int
                           *error_code);
void ADIOI_MADFS_ReadComplete(ADIO_Request * request, ADIO_Status * status, int
                               *error_code);
void ADIOI_MADFS_WriteComplete(ADIO_Request * request, ADIO_Status * status, int *error_code);
void ADIOI_MADFS_Fcntl(ADIO_File fd, int flag, ADIO_Fcntl_t * fcntl_struct, int *error_code);
void ADIOI_MADFS_WriteStrided(ADIO_File fd, const void *buf, int count,
                               MPI_Datatype datatype, int file_ptr_type,
                               ADIO_Offset offset, ADIO_Status * status, int *error_code);
void ADIOI_MADFS_ReadStrided(ADIO_File fd, void *buf, int count,
                              MPI_Datatype datatype, int file_ptr_type,
                              ADIO_Offset offset, ADIO_Status * status, int
                              *error_code);
void ADIOI_MADFS_WriteStridedColl(ADIO_File fd, const void *buf, int count,
                                   MPI_Datatype datatype, int file_ptr_type,
                                   ADIO_Offset offset, ADIO_Status * status, int
                                   *error_code);
void ADIOI_MADFS_ReadStridedColl(ADIO_File fd, void *buf, int count,
                                  MPI_Datatype datatype, int file_ptr_type,
                                  ADIO_Offset offset, ADIO_Status * status, int
                                  *error_code);
void ADIOI_MADFS_IreadStrided(ADIO_File fd, void *buf, int count,
                               MPI_Datatype datatype, int file_ptr_type,
                               ADIO_Offset offset, ADIO_Request * request, int
                               *error_code);
void ADIOI_MADFS_IwriteStrided(ADIO_File fd, const void *buf, int count,
                                MPI_Datatype datatype, int file_ptr_type,
                                ADIO_Offset offset, ADIO_Request * request, int
                                *error_code);
void ADIOI_MADFS_Flush(ADIO_File fd, int *error_code);
void ADIOI_MADFS_Resize(ADIO_File fd, ADIO_Offset size, int *error_code);
ADIO_Offset ADIOI_MADFS_SeekIndividual(ADIO_File fd, ADIO_Offset offset,
                                        int whence, int *error_code);
void ADIOI_MADFS_SetInfo(ADIO_File fd, MPI_Info users_info, int *error_code);
void ADIOI_MADFS_Get_shared_fp(ADIO_File fd, int size, ADIO_Offset * shared_fp, int *error_code);
void ADIOI_MADFS_Set_shared_fp(ADIO_File fd, ADIO_Offset offset, int *error_code);
void ADIOI_MADFS_Delete(const char *filename, int *error_code);

#endif /* AD_MADFS_H_INCLUDED */
