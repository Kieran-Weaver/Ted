#ifndef BM_INTERN_H
#define BM_INTERN_H

#include "bitmap.h"

/************************************************************************/
/*									*/
/*  Byte Masks								*/
/*									*/
/************************************************************************/

extern const unsigned char Bmc1Masks[8];
extern const unsigned char Bmc7Masks[8];

/************************************************************************/
/*									*/
/*  Routines.								*/
/*									*/
/************************************************************************/

int bmReadBmpFile(const MemoryBuffer *filename, unsigned char **pBuffer,
			 BitmapDescription *bd, int *pPrivateFormat);

int bmCanWriteBmpFile(const BitmapDescription *bd, int privateFormat);

int bmWriteBmpFile(const MemoryBuffer *filename,
			  const unsigned char *buffer,
			  const BitmapDescription *bd, int privateFormat);

int bmReadGifFile(const MemoryBuffer *filename, unsigned char **pBuffer,
			 BitmapDescription *bd, int *pPrivateFormat);

int bmCanWritePdfFile(const BitmapDescription *bd, int privateFormat);

int bmWritePdfFile(const MemoryBuffer *filename,
			  const unsigned char *buffer,
			  const BitmapDescription *bd, int privateFormat);

int bmReadJpegFile(const MemoryBuffer *filename, unsigned char **pBuffer,
			  BitmapDescription *bd, int *pPrivateFormat);

int bmReadPngFile(const MemoryBuffer *filename, unsigned char **pBuffer,
			 BitmapDescription *bd, int *pPrivateFormat);

int bmWritePngFile(const MemoryBuffer *filename,
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
