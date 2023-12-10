/************************************************************************/
/*									*/
/*  Simple io streams using raw file IO.				*/
/*									*/
/************************************************************************/

#include "utilMemoryBuffer.h"
#include "sioGeneral.h"

SimpleOutputStream *sioOutFileioOpen(const MemoryBuffer *filename);

SimpleOutputStream *
sioOutFileioOpenForAppend(const MemoryBuffer *filename);

SimpleOutputStream *sioOutFileioOpenS(const char *filename);

SimpleOutputStream *sioOutFileioOpenTempFile(MemoryBuffer *filename,
						    const char *templateStr);

SimpleInputStream *sioInFileioOpen(const MemoryBuffer *filename);

SimpleInputStream *sioInFileioOpenS(const char *filename);
