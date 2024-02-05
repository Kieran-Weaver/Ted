/************************************************************************/
/*									*/
/*  Derive text metrics from font metrics.				*/
/*									*/
/************************************************************************/

#ifndef PS_FONT_METRICS_H
#define PS_FONT_METRICS_H

#include "psFontInfo.h"

/************************************************************************/
/*									*/
/*  Declarations.							*/
/*									*/
/************************************************************************/

int psCalculateStringExtents(DocumentRectangle *dr, const char *ss, int len,
			     int twipsSize, int withKerning, int vswap,
			     const AfmFontInfo *afi);

void psUnderlineGeometry(int *pPos, int *pThick, int baseline, int twipsSize,
			 const AfmFontInfo *afi);

void psStrikethroughGeometry(int *pPos, int *pThick, int baseline,
			     int twipsSize, const AfmFontInfo *afi);

int psFontBBox(DocumentRectangle *drBBox, DocumentRectangle *drAscDesc,
	       int twipsSize, int vswap, const AfmFontInfo *afi);

int psGetSuperBaseline(int *pSuperBaseline, int baseline, int fontSizeTwips,
		       const AfmFontInfo *afi);

int psGetSubBaseline(int *pSubBaseline, int baseline, int fontSizeTwips,
		     const AfmFontInfo *afi);

int psGetSmallcapsSize(int *pSmallcapsSize, int fontSizeTwips,
		       const AfmFontInfo *afi);

#endif
