/************************************************************************/
/*									*/
/*  Manage a lookup to keep track of screen fonts.			*/
/*									*/
/************************************************************************/

#ifndef DRAW_SCREEN_FONT_ADMIN_H
#define DRAW_SCREEN_FONT_ADMIN_H

#include "drawScreenFontImpl.h"
#include <utilIntegerValueNode.h>
#include <utilNumberedPropertiesAdmin.h>

typedef void (*ScreenFontFunction)(const DrawScreenFont *sf, int n,
				   void *through);

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void drawStartScreenFontList(NumberedPropertiesList *sfl);

void drawForAllScreenFonts(const NumberedPropertiesList *sfl,
				  ScreenFontFunction f, void *through);

DrawScreenFont *
drawGetScreenFontByNumber(const NumberedPropertiesList *sfl, int n);

int drawGetScreenFont(DrawScreenFont **pApf, int *pFresh,
			     NumberedPropertiesList *npl,
			     const IndexSet *unicodesUsed,
			     const AfmFontInfo *afi, int pixelSize);

int drawTextExtentsImpl(rect *drText, int x, int y,
			       const NumberedPropertiesList *npl,
			       int screenFont, const char *s, int len);

int drawScapsTextExtentsImpl(rect *drText, int x, int y,
				    const NumberedPropertiesList *npl,
				    int fullScreenFont, int scapsScreenFont,
				    const char *s, int len);

int drawFontImplementationNameImpl(char *target, int maxlen,
					  const NumberedPropertiesList *npl,
					  int screenFont);

#endif /*  DRAW_SCREEN_FONT_ADMIN_H	*/
