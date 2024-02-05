/************************************************************************/
/*									*/
/*  An array of bytes and its (maximum) size.				*/
/*									*/
/************************************************************************/

#ifndef UTIL_MEMORY_H
#define UTIL_MEMORY_H

typedef struct MemoryBuffer {
	int mbSize;
	unsigned char *mbBytes;
} MemoryBuffer;

#define utilMemoryBufferIsEmpty(mb) ((mb)->mbSize == 0)

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void utilInitMemoryBuffer(MemoryBuffer *mb);
void utilEmptyMemoryBuffer(MemoryBuffer *mb);
void utilCleanMemoryBuffer(MemoryBuffer *mb);

int utilCopyMemoryBuffer(MemoryBuffer *mbTo, const MemoryBuffer *mbFrom);

int utilMemoryBufferSetSize(MemoryBuffer *mb, int size);

int utilMemoryBufferSetString(MemoryBuffer *mb, const char *s);

int utilMemoryBufferSetBytes(MemoryBuffer *mb, const unsigned char *bytes,
			     int size);

const unsigned char *utilMemoryBufferGetBytes(int *pSize,
					      const MemoryBuffer *mbFrom);

const char *utilMemoryBufferGetString(const MemoryBuffer *mbFrom);

int utilMemoryCompareBuffers(const MemoryBuffer *mb1, const MemoryBuffer *mb2);

#define utilEqualMemoryBuffer(mb1, mb2)    \
	((mb1)->mbSize == (mb2)->mbSize && \
	 utilMemoryCompareBuffers((mb1), (mb2)) == 0)

int utilMemoryAppendBuffer(MemoryBuffer *to, const MemoryBuffer *from);
int utilMemoryBufferAppendString(MemoryBuffer *to, const char *s);
int utilMemoryBufferAppendBytes(MemoryBuffer *mb, const unsigned char *bytes,
				int size);

int utilMemoryBufferReplaceBytes(MemoryBuffer *mb, int offHead, int offPast,
				 const unsigned char *addedBytes,
				 int addedCount);

int utilMemoryBufferGetRange(MemoryBuffer *mbTo, const MemoryBuffer *mbFrom,
			     int offFrom, int lenFrom);

char *utilMemoryStrdup(const MemoryBuffer *mbFrom);

int utilMemoryBufferEqualsString(const MemoryBuffer *mb, const char *s);

int utilMemoryBufferLastIndexOf(const MemoryBuffer *mb, int cal);

int utilMemoryBufferIndexOf(const MemoryBuffer *mb, int cal);

#endif /*  UTIL_MEMORY_H	*/
