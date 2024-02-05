/************************************************************************/
/*									*/
/*  Emit raster images to PostScript.					*/
/*									*/
/************************************************************************/

#ifndef MB_BITMAP_PRINTER_H
#define MB_BITMAP_PRINTER_H

#include "bitmap.h"
#include "bmio.h"

/************************************************************************/
/*									*/
/*  Context for writing images to PostScript.				*/
/*									*/
/************************************************************************/

typedef struct BitmapPrinter {
	int bpUseFilters;
	int bpIndexedImages;
	SimpleOutputStream *bpOutput;
	SimpleOutputStream *bpHexed;
	SimpleOutputStream *bpBase85;
	SimpleOutputStream *bpFlate;
} BitmapPrinter;

int bmPsOpenBitmapPrinter(BitmapPrinter *bp, SimpleOutputStream *sos,
			  const BitmapDescription *bd, int useFilters,
			  int indexedImages);

void bmCloseBitmapPrinter(BitmapPrinter *bp);

void bmStartEpsFile(SimpleOutputStream *sos, const char *filename,
		    const BitmapDescription *bd);

/************************************************************************/
/*									*/
/*  Write part of a bitmap to postscript.				*/
/*									*/
/************************************************************************/

int bmPsPrintBitmap(SimpleOutputStream *sos, int level, double xscale,
		    double yscale, int ox, int oy,
		    const DocumentRectangle *drSrc, int useFilters,
		    int indexedImages, const BitmapDescription *bd,
		    const unsigned char *buffer);

int bmPsPrintBitmapImage(SimpleOutputStream *sos, int level, double xscale,
			 double yscale, int ox, int oy,
			 const DocumentRectangle *drSrc, int onWhite,
			 int useFilters, int indexedImages,
			 const BitmapDescription *bd,
			 const unsigned char *buffer);

void bmPsWriteImageInstructions(SimpleOutputStream *sos,
				const BitmapDescription *bd, int onWhite,
				int wide, int high, const char *source,
				int indexedImages);

int bmPsWriteBitmapData(BitmapPrinter *bp, const DocumentRectangle *drSrc,
			const BitmapDescription *bd,
			const unsigned char *inputBuffer);

int bmPsRowStringSize(const BitmapDescription *bd, int pixelsWide,
		      int indexedImages);

#endif
