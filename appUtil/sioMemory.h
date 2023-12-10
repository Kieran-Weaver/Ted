/************************************************************************/
/*									*/
/*  Simple io streams using blocks of memory.				*/
/*									*/
/************************************************************************/

#ifndef SIO_MEMORY_H
#define SIO_MEMORY_H

#include "sioGeneral.h"
#include "utilMemoryBuffer.h"

SimpleInputStream *sioInMemoryOpen(const MemoryBuffer *mb);

SimpleInputStream *sioInMemoryOpenFrom(const MemoryBuffer *mb, int from);

SimpleOutputStream *sioOutMemoryOpen(MemoryBuffer *mb);

SimpleOutputStream *sioOutMemoryOpenTo(MemoryBuffer *mb, int to);

#endif
