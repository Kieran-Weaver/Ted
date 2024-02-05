/************************************************************************/
/*									*/
/*  Printf to memory buffers.						*/
/*									*/
/************************************************************************/

#ifndef UTIL_MB_PRINTF
#define UTIL_MB_PRINTF

#include "utilMemoryBuffer.h"
/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

#ifdef __GNUC__
int utilMemoryBufferPrintf(MemoryBuffer *mb, const char *format, ...)
	__attribute__((format(printf, 2, 3)));
#else
int utilMemoryBufferPrintf(MemoryBuffer *mb, const char *format, ...);
#endif

#endif
