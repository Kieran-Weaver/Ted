#ifndef DRAW_SCREEN_FONT_UTIL_H
#define DRAW_SCREEN_FONT_UTIL_H

#include <drawDrawingSurface.h>

#ifdef __cplusplus
extern "C"{
#endif

/************************************************************************/
/*									*/
/*  Procedure declarations.						*/
/*									*/
/************************************************************************/

void drawFontUnderlineGeometry(int *pThick, int *pY,
				      const struct DrawingSurface* ds, int screenFont,
				      int baselinePixels);

void drawFontStrikethroughGeometry(int *pThick, int *pY,
					  const struct DrawingSurface* ds,
					  int screenFont, int baselinePixels);

void drawFontGetSuperBaseline(int *pSuperBaseline, int baselinePixels,
				     const struct DrawingSurface* ds, int screenFont);

void drawFontGetSubBaseline(int *pSubBaseline, int baselinePixels,
				   const struct DrawingSurface* ds, int screenFont);

#ifdef __cplusplus
}
#endif

#endif /*  DRAW_SCREEN_FONT_UTIL_H	*/
