/************************************************************************/
/*									*/
/*  Palette manipulation, mainly for raster images.			*/
/*									*/
/************************************************************************/

#ifndef UTIL_PALETTE_H
#define UTIL_PALETTE_H

#include "utilColor.h"
typedef struct ColorPalette {
	int cpColorCount;
	RGB8Color *cpColors;
} ColorPalette;

/************************************************************************/
/*									*/
/*  Routine declarations:						*/
/*									*/
/************************************************************************/

void utilInitColorPalette(ColorPalette *cp);
void utilCleanColorPalette(ColorPalette *cp);

int utilCopyColorPalette(ColorPalette *to, const ColorPalette *from);

int utilPaletteSetCount(ColorPalette *cp, int colorCount);

int utilPaletteColorIndex(ColorPalette *cp, int maxCount, int r, int g, int b,
			  int a);

int utilPaletteInsertColor(ColorPalette *cp, int avoidZero, int maxColors,
			   const RGB8Color *rgb8);

int utilMergeColorPalettes(int **pColorMap, ColorPalette *cpTo,
			   const ColorPalette *cpFrom, int avoidZero,
			   int maxColors);

#endif /*  UTIL_PALETTE_H  */
