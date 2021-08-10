/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_madfs.h"

/* adioi.h has the ADIOI_Fns_struct define */
#include "adioi.h"

struct ADIOI_Fns_struct ADIO_MADFS_operations = {
    ADIOI_MADFS_Open,  /* Open */
    ADIOI_GEN_OpenColl, /* OpenColl */
    ADIOI_MADFS_ReadContig,    /* ReadContig */
    ADIOI_MADFS_WriteContig,   /* WriteContig */
    ADIOI_MADFS_ReadStridedColl,       /* ReadStridedColl */
    ADIOI_MADFS_WriteStridedColl,      /* WriteStridedColl */
    ADIOI_MADFS_SeekIndividual,        /* SeekIndividual */
    ADIOI_MADFS_Fcntl, /* Fcntl */
    ADIOI_MADFS_SetInfo,       /* SetInfo */
    ADIOI_MADFS_ReadStrided,   /* ReadStrided */
    ADIOI_MADFS_WriteStrided,  /* WriteStrided */
    ADIOI_MADFS_Close, /* Close */
    ADIOI_MADFS_IreadContig,   /* IreadContig */
    ADIOI_MADFS_IwriteContig,  /* IwriteContig */
    ADIOI_MADFS_ReadDone,      /* ReadDone */
    ADIOI_MADFS_WriteDone,     /* WriteDone */
    ADIOI_MADFS_ReadComplete,  /* ReadComplete */
    ADIOI_MADFS_WriteComplete, /* WriteComplete */
    ADIOI_MADFS_IreadStrided,  /* IreadStrided */
    ADIOI_MADFS_IwriteStrided, /* IwriteStrided */
    ADIOI_MADFS_Flush, /* Flush */
    ADIOI_MADFS_Resize,        /* Resize */
    ADIOI_MADFS_Delete,        /* Delete */
    ADIOI_GEN_Feature,  /* Features */
    "MADFS: the logging-only file system",
    ADIOI_GEN_IreadStridedColl, /* IreadStridedColl */
    ADIOI_GEN_IwriteStridedColl,        /* IwriteStridedColl */
#if defined(F_SETLKW64)
    ADIOI_GEN_SetLock   /* SetLock */
#else
    ADIOI_GEN_SetLock64 /* SetLock */
#endif
};
