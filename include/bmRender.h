/************************************************************************/
/*									*/
/*  Functions relating to rendering raster images.			*/
/*									*/
/************************************************************************/

#ifndef BM_RENDER_H
#define BM_RENDER_H

#include "bitmap.h"
#include "bmcolor.h"

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int bmFillImage(ColorAllocator *ca, int bitmapUnit, int swapBitmapBytes,
		       int swapBitmapBits, int dither, unsigned char *bufferOut,
		       const BitmapDescription *bdOut, const RasterImage *riIn,
		       const DocumentRectangle *drSel);

#endif
