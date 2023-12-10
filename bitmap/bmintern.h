#ifndef BM_INTERN_H
#define BM_INTERN_H

#include "bitmap.h"

/************************************************************************/
/*									*/
/*  Byte Masks								*/
/*									*/
/************************************************************************/

unsigned char Bmc1Masks[8];
unsigned char Bmc7Masks[8];

/************************************************************************/
/*									*/
/*  Routines.								*/
/*									*/
/************************************************************************/

int bmReadTiffFile(const MemoryBuffer *filename, unsigned char **pBuffer,
			  BitmapDescription *bd, int *pPrivateFormat);

int bmWriteTiffFile(const MemoryBuffer *filename,
			   const unsigned char *buffer,
			   const BitmapDescription *bd, int privateFormat);

int bmCanWriteTiffFile(const BitmapDescription *bd, int privateFormat);

int bmReadBmpFile(const MemoryBuffer *filename, unsigned char **pBuffer,
			 BitmapDescription *bd, int *pPrivateFormat);

int bmReadIcoFile(const MemoryBuffer *filename, unsigned char **pBuffer,
			 BitmapDescription *bd, int *pPrivateFormat);

int bmCanWriteBmpFile(const BitmapDescription *bd, int privateFormat);

int bmCanWriteIcoFile(const BitmapDescription *bd, int privateFormat);

int bmWriteBmpFile(const MemoryBuffer *filename,
			  const unsigned char *buffer,
			  const BitmapDescription *bd, int privateFormat);

int bmWriteIcoFile(const MemoryBuffer *filename,
			  const unsigned char *buffer,
			  const BitmapDescription *bd, int privateFormat);

int bmReadGifFile(const MemoryBuffer *filename, unsigned char **pBuffer,
			 BitmapDescription *bd, int *pPrivateFormat);

int bmCanWriteEpsFile(const BitmapDescription *bd, int privateFormat);

int bmCanWritePdfFile(const BitmapDescription *bd, int privateFormat);

int bmWriteEpsFile(const MemoryBuffer *filename,
			  const unsigned char *buffer,
			  const BitmapDescription *bd, int privateFormat);

int bmWritePdfFile(const MemoryBuffer *filename,
			  const unsigned char *buffer,
			  const BitmapDescription *bd, int privateFormat);

int bmReadJpegFile(const MemoryBuffer *filename, unsigned char **pBuffer,
			  BitmapDescription *bd, int *pPrivateFormat);

int bmReadXbmFile(const MemoryBuffer *filename, unsigned char **pBuffer,
			 BitmapDescription *bd, int *pPrivateFormat);

int bmCanWriteXbmFile(const BitmapDescription *bd, int privateFormat);

int bmWriteXbmFile(const MemoryBuffer *filename,
			  const unsigned char *buffer,
			  const BitmapDescription *bd, int privateFormat);

int bmReadPngFile(const MemoryBuffer *filename, unsigned char **pBuffer,
			 BitmapDescription *bd, int *pPrivateFormat);

int bmWritePngFile(const MemoryBuffer *filename,
			  const unsigned char *buffer,
			  const BitmapDescription *bd, int privateFormat);

int bmReadXpmFile(const MemoryBuffer *filename, unsigned char **pBuffer,
			 BitmapDescription *bd, int *pPrivateFormat);

int bmCanWriteXpmFile(const BitmapDescription *bd, int privateFormat);

int bmWriteXpmFile(const MemoryBuffer *filename,
			  const unsigned char *buffer,
			  const BitmapDescription *bd, int privateFormat);

int bmReadPbmFile(const MemoryBuffer *filename, unsigned char **pBuffer,
			 BitmapDescription *bd, int *pPrivateFormat);

int bmCanWritePbmFile(const BitmapDescription *bd, int privateFormat);

int bmWritePbmFile(const MemoryBuffer *filename,
			  const unsigned char *buffer,
			  const BitmapDescription *bd, int privateFormat);

int bmFillBlock(unsigned char *buffer, int x0, int y0, int x1, int y1,
		       int bytesPerRow);

unsigned char *bmBackgroundBuffer(int bufferLength, int colorEncoding);
unsigned char *bmForegroundBuffer(int bufferLength, int colorEncoding);

int bmMakeGrayPalette(const BitmapDescription *bd, int *pColorCount,
			     int *pTransparentColor, RGB8Color *palette,
			     int maxColors);

int bmInflateTo8bit(unsigned char *to, const unsigned char *from,
			   const BitmapDescription *bd, int trnsC, int remA);

int bmInflateToInt(unsigned int *to, const unsigned char *from,
			  const BitmapDescription *bd, int trnsC, int remA);

int bmInflateTo8bitGray(unsigned char *to, const unsigned char *from,
			       int bitsPerPixel, int pixelsWide);

int bmMakeMonochrome(BitmapDescription *bd, unsigned char *buffer);

int bmPlanarToChunky(unsigned char *to, const unsigned char *from,
			    const BitmapDescription *bd);

int bmPaletteColor(BitmapDescription *bd, int r, int g, int b, int a);

#endif /*  BM_INTERN_H	*/
