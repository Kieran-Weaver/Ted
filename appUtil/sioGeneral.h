/************************************************************************/
/*									*/
/*  Simplification of stdio.						*/
/*									*/
/************************************************************************/

#ifndef SIO_GENERAL_H
#define SIO_GENERAL_H

/*  for EOF:			*/
#include <stdio.h>
#define SIOsizBUF 1024

typedef int (*SIOinREADBYTES)(void *, unsigned char *, unsigned int);
typedef int (*SIOinCLOSE)(void *);

typedef struct SimpleInputStream {
	unsigned char sisBuffer[SIOsizBUF];
	unsigned char *sisP;
	int sisN;
	void *sisPrivate;

	long sisBytesRead;

	SIOinREADBYTES sisReadBytes;
	SIOinCLOSE sisClose;
} SimpleInputStream;

#define sioInGetByte(s) \
	((--((s)->sisN)) >= 0 ? *(((s)->sisP)++) : sioInFillBuffer(s))

typedef int (*SIOoutWRITEBYTES)(void *, const unsigned char *, int);
typedef int (*SIOoutCLOSE)(void *);

typedef struct SimpleOutputStream {
	unsigned char sosBuffer[SIOsizBUF];
	unsigned char *sosP;
	int sosN;
	void *sosPrivate;

	long sosBytesWritten;

	SIOoutWRITEBYTES sosWriteBytes;
	SIOoutCLOSE sosClose;
} SimpleOutputStream;

#define sioOutPutByte(c, s)                                 \
	(((s)->sosN >= SIOsizBUF && sioOutFlushBuffer(s)) ? \
		 -1 :                                       \
		 (*(((s)->sosP)++) = (c), (s)->sosN++, 0))

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

/*  in  */

int sioInFillBuffer(SimpleInputStream *sis);

int sioInUngetLastRead(SimpleInputStream *sis);

SimpleInputStream *sioInOpen(void *specific, SIOinREADBYTES readBytes,
			     SIOinCLOSE closeIt);

long sioInGetBytesRead(SimpleInputStream *sis);

int sioInClose(SimpleInputStream *sis);

char *sioInGetString(char *s, int size, SimpleInputStream *sis);

int sioInReadBytes(SimpleInputStream *sis, unsigned char *buf, int count);

/*  out  */

int sioOutFlushBuffer(SimpleOutputStream *sos);

SimpleOutputStream *sioOutOpen(void *specific, SIOoutWRITEBYTES writeBytes,
			       SIOoutCLOSE closeIt);

int sioOutClose(SimpleOutputStream *sos);

long sioOutGetBytesWritten(SimpleOutputStream *sos);

int sioOutPutString(const char *s, SimpleOutputStream *sos);

int sioOutWriteBytes(SimpleOutputStream *sos, const unsigned char *buf,
		     int count);

#ifdef __GNUC__
int sioOutPrintf(SimpleOutputStream *sos, const char *format, ...)
	__attribute__((format(printf, 2, 3)));
#else
int sioOutPrintf(SimpleOutputStream *sos, const char *format, ...);
#endif

#endif
