/************************************************************************/
/*									*/
/*  Writing RTF.							*/
/*									*/
/************************************************************************/

#ifndef RTF_WRITER_H
#define RTF_WRITER_H

#include <sioGeneral.h>
#include <docBuf.h>

struct RtfWriter;
typedef struct RtfWriter RtfWriter;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

RtfWriter *docRtfOpenWriter(SimpleOutputStream *sos, BufferDocument *bd,
				   int flags);

void docRtfCloseWriter(RtfWriter *rw);

#endif /*	RTF_WRITER_H	*/
