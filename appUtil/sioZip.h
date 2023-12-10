/************************************************************************/
/*									*/
/*  Simple io streams, Data on the stream travels in In/Deflate format	*/
/*  using zlib. The implementation is a VERY SIMPLE ONE: It assumes	*/
/*  that the compressed files fit in memory.				*/
/*									*/
/************************************************************************/

#include "utilPagedList.h"
#include "sioGeneral.h"

typedef struct ZipOutput {
	SimpleOutputStream *zoSosZip;
	unsigned long zoBytesWritten;
	PagedList zoFileList;

	int zoEntryCount;
	unsigned long zoDirectoryOffset;
	unsigned long zoDirectorySize;
} ZipOutput;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void sioZipInitOutput(ZipOutput *zo);
void sioZipCleanOutput(ZipOutput *zo);

int sioZipFlushOutput(ZipOutput *zo);

SimpleOutputStream *sioOutZipOpen(ZipOutput *zipOutput,
					 const char *fileName, int compressed);
