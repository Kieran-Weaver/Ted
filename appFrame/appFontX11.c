/************************************************************************/
/*									*/
/*  Management of X11 fonts: Translation of understandable fonts to	*/
/*  X11 structures.							*/
/*									*/
/************************************************************************/

#include <config.h>
#include "appGuiBase.h"
#include "appScreenFont.h"
#include "drawDrawingSurfaceImpl.h"
#include <utilLongestCommonSubstring.h>
#include <uniLegacyEncoding.h>
#include <uniLegacyMapping.h>
#include "drawImpl.h"

typedef struct XFontFaceSize {
	short int xffsPixelSize;
	short int xffsListIndex;
} XFontFaceSize;

int guiSystemFont(DrawingSurface ds, APP_FONT *xfs)
{
	NumberedPropertiesList *npl = &(ds->dsScreenFontAdmin);
	DrawScreenFont *dsf = (DrawScreenFont *)0;
	int screenFont;

	/* HACK */
	dsf = utilPagedListClaimItemAtEnd(&screenFont, &(npl->nplPagedList));
	if (!dsf) {
		return -1;
	}

	dsf->dsfEncodedFonts.esfFonts = malloc(sizeof(EncodedScreenFont));
	if (!dsf->dsfEncodedFonts.esfFonts) {
		return -1;
	}
	drawInitEncodedScreenFont(dsf->dsfEncodedFonts.esfFonts);
	dsf->dsfEncodedFonts.esfFontCount = 1;

	dsf->dsfEncodedFonts.esfFonts[0].esfFontStruct = xfs;

	dsf->dsfDrawable = ds->dsDrawable;
	dsf->dsfGc = ds->dsGc;
	dsf->dsfEncodedFonts.esfFonts[0].esfFontBorrowed = 0;

#ifdef USE_XFT
	dsf->dsfXftDrawable = ds->dsXftDrawable;
#endif

	return screenFont;
}
