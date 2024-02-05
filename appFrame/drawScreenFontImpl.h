#ifndef DRAW_SCREEN_FONT_IMPL_H
#define DRAW_SCREEN_FONT_IMPL_H

#include "appGuiBase.h"
#include "drawImpl.h"
#include <utilIndexMapping.h>
#include <psFontInfo.h>

typedef GdkFont(APP_FONT);

/************************************************************************/
/*									*/
/*  For the administration of the relation between PostScript fonts and	*/
/*  X11 fonts.								*/
/*									*/
/************************************************************************/

#define X_FONTNAME_MAX 100

typedef struct EncodedScreenFont {
	APP_FONT *esfFontStruct;
	char esfFontName[X_FONTNAME_MAX + 1];
	unsigned char esfIsTwoByte;
	unsigned char esfFontBorrowed;
	const IndexMapping *esfSymbolToByteMapping;
} EncodedScreenFont;

typedef struct EncodedScreenFontList {
	EncodedScreenFont *esfFonts;
	int esfFontCount;
	IndexMapping esflSymbolToFont;
} EncodedScreenFontList;

#define DSFkeyFACE_NUMBER 0
#define DSFkeySIZE_PIXELS 1
#define DSFkey_COUNT 2

typedef struct DrawScreenFont {
	/*  KEY  */
	short int apfPsFaceNumber;
	short int dsfSizePixels;

	/*  DEP  */
	const AfmFontInfo *apfPsFontInfo;
	int apfUnderlinePositionPixels;
	int apfUnderlineThicknessPixels;
	int apfStrikethroughPositionPixels;
	int apfStrikethroughThicknessPixels;
	int apfSuperBaseline;
	int apfSubBaseline;
	int apfXHeightPixels;
	EncodedScreenFontList dsfEncodedFonts;
	char apfFontName[X_FONTNAME_MAX + 1];

	const IndexSet *dsfUnicodesUsed;

#ifdef USE_XFT
	Display *dsfDisplay;
	APP_DRAWABLE dsfDrawable;
	APP_GC dsfGc;
#endif

#ifdef USE_XFT
	XftDraw *dsfXftDrawable;
	XftFont *dsfXftFont;
#endif
} DrawScreenFont;

/************************************************************************/
/*									*/
/*  Procedure declarations.						*/
/*									*/
/************************************************************************/

void drawCleanScreenFont(DrawScreenFont *dsf);
void drawInitScreenFont(DrawScreenFont *dsf);

int drawGetScreenFontKey(const DrawScreenFont *dsf, int prop);

void drawCleanEncodedScreenFont(DrawScreenFont *dsf, EncodedScreenFont *esf);

void drawInitEncodedScreenFont(EncodedScreenFont *esf);

int drawFontOpenScreenFont(DrawScreenFont *dsf, int avoidFontconfig);

XftFont *drawOpenXftFont(DrawScreenFont *dsf);

int drawTextExtentsXft(DocumentRectangle *drText, int x, int y,
		       const DrawScreenFont *hDsf, const DrawScreenFont *vDsf,
		       const char *s, int len);

#endif
