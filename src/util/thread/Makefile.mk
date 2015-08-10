## -*- Mode: Makefile; -*-
## vim: set ft=automake :
##
## (C) 2011 by Argonne National Laboratory.
##     See COPYRIGHT in top-level directory.
##

AM_CPPFLAGS += -I$(top_srcdir)/src/util/thread

noinst_HEADERS +=                               \
    src/util/thread/mpiu_thread.h               \
    src/util/thread/mpiu_thread_posix_funcs.h   \
    src/util/thread/mpiu_thread_posix_types.h   \
    src/util/thread/mpiu_thread_solaris_funcs.h \
    src/util/thread/mpiu_thread_solaris_types.h \
    src/util/thread/mpiu_thread_win_funcs.h     \
    src/util/thread/mpiu_thread_win_types.h

mpi_core_sources += \
    src/util/thread/mpiu_thread_win.c \
    src/util/thread/mpiu_thread_solaris.c \
    src/util/thread/mpiu_thread_posix.c

