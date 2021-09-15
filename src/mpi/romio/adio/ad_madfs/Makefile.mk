##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

if BUILD_AD_MADFS

noinst_HEADERS += adio/ad_madfs/ad_madfs.h

romio_other_sources +=                \
    adio/ad_madfs/ad_madfs_close.c  \
    adio/ad_madfs/ad_madfs_read.c   \
    adio/ad_madfs/ad_madfs_rdcoll.c \
    adio/ad_madfs/ad_madfs_wrcoll.c \
    adio/ad_madfs/ad_madfs_open.c   \
    adio/ad_madfs/ad_madfs_write.c  \
    adio/ad_madfs/ad_madfs_done.c   \
    adio/ad_madfs/ad_madfs_fcntl.c  \
    adio/ad_madfs/ad_madfs_iread.c  \
    adio/ad_madfs/ad_madfs_iwrite.c \
    adio/ad_madfs/ad_madfs_wait.c   \
    adio/ad_madfs/ad_madfs_flush.c  \
    adio/ad_madfs/ad_madfs_seek.c   \
    adio/ad_madfs/ad_madfs_resize.c \
    adio/ad_madfs/ad_madfs_hints.c  \
    adio/ad_madfs/ad_madfs_delete.c \
    adio/ad_madfs/ad_madfs.c

endif BUILD_AD_MADFS
