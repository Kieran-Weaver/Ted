/************************************************************************/
/*									*/
/*  Basic screen font management.					*/
/*									*/
/************************************************************************/

#include <config.h>

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include <geo2DInteger.h>
#include "drawImpl.h"
#include "drawScreenFontAdmin.h"

#include <appDebugon.h>

int drawFontImplementationNameImpl(char *target, int maxlen,
				   const NumberedPropertiesList *npl,
				   int screenFont)
{
	const AfmFontInfo *afi;
	const DrawScreenFont *dsf;

	dsf = drawGetScreenFontByNumber(npl, screenFont);
	if (!dsf) {
		LXDEB(screenFont, dsf);
		return -1;
	}
	afi = dsf->apfPsFontInfo;

#ifdef USE_XFT
	if (dsf->dsfXftFont) {
		if (utilMemoryBufferIsEmpty(&(afi->afiFontFileName)) ||
		    afi->afiFontFileName.mbSize >= maxlen) {
			return -1;
		}

		strcpy(target,
		       utilMemoryBufferGetString(&(afi->afiFontFileName)));
		return 0;
	}
#endif


	return -1;
}
