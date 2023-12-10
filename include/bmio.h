/************************************************************************/
/*									*/
/*  Read/Write raster images from/to input/output streams.		*/
/*									*/
/************************************************************************/

#ifndef BM_IO_H
#define BM_IO_H

#include "bitmap.h"
#include <sioGeneral.h>

typedef int (*bmReadBitmap)(BitmapDescription *pBd, unsigned char **pBuffer,
			    SimpleInputStream *sis);

typedef int (*bmWriteBitmap)(const BitmapDescription *bd,
			     const unsigned char *buffer,
			     SimpleOutputStream *sos);

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int bmRtfWriteRtf(const BitmapDescription *bd,
			 const unsigned char *buffer, SimpleOutputStream *sos);

int bmPngWritePng(const BitmapDescription *bd,
			 const unsigned char *buffer, SimpleOutputStream *sos);

int bmRtfWritePngRtf(const BitmapDescription *bd,
			    const unsigned char *buffer,
			    SimpleOutputStream *sos);

int bmJpegWriteJfif(const BitmapDescription *bd,
			   const unsigned char *buffer,
			   SimpleOutputStream *sos);

int bmRtfWriteJfifRtf(const BitmapDescription *bd,
			     const unsigned char *buffer,
			     SimpleOutputStream *sos);

int bmGifWriteGif(const BitmapDescription *bd,
			 const unsigned char *buffer, SimpleOutputStream *sos);

int bmBmpReadDib(BitmapDescription *bd, unsigned char **pBuffer,
			SimpleInputStream *sis);

int bmJpegReadJfif(BitmapDescription *bd, unsigned char **pBuffer,
			  SimpleInputStream *sis);

int bmPngReadPng(BitmapDescription *bd, unsigned char **pBuffer,
			SimpleInputStream *sis);

int bmGifReadGif(BitmapDescription *bd, unsigned char **pBuffer,
			SimpleInputStream *sis);

int bmEpsTestJpegEmbeddable(unsigned int *pPixelsWide,
				   unsigned int *pPixelsHigh,
				   unsigned int *pComponentCount,
				   unsigned int *pBitsPerCompunent,
				   SimpleInputStream *sis);

int bmPsPrintJpegImage(SimpleOutputStream *sos, double xscale,
			      double yscale, int componentCount, int ox, int oy,
			      int pixelsWide, int pixelsHigh,
			      int bitsPerComponent, SimpleInputStream *sis);

#endif
