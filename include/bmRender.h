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

int bmTextureMap(ColorAllocator *ca, int swapBitmapUnit,
			int swapBitmapBytes, int swapBitmapBits, int dither,
			unsigned char *bufferOut, const unsigned char *bufferIn,
			const BitmapDescription *bdOut,
			const BitmapDescription *bdIn, double E_x, double E_y,
			double E_z, double P_x, double P_y, double P_z,
			double N_x, double N_y, double N_z, double M_x,
			double M_y, double M_z);

int bmTextureMapInverse(ColorAllocator *ca, int swapBitmapUnit,
			       int swapBitmapBytes, int swapBitmapBits,
			       int dither, unsigned char *bufferOut,
			       const unsigned char *bufferIn,
			       const BitmapDescription *bdOut,
			       const BitmapDescription *bdIn, double E_x,
			       double E_y, double E_z, double P_x, double P_y,
			       double P_z, double N_x, double N_y, double N_z,
			       double M_x, double M_y, double M_z);

int bmSetColorAllocatorForImage(ColorAllocator *ca,
				       const BitmapDescription *bd);

int bmSetColorAllocatorForPaletteImage(ColorAllocator *ca,
					      const BitmapDescription *bd);

int bmSetColorAllocatorForBWImage(ColorAllocator *ca,
					 const BitmapDescription *bd);

int bmSetColorAllocatorForWBImage(ColorAllocator *ca,
					 const BitmapDescription *bd);

#endif
