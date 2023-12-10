/************************************************************************/
/*									*/
/*  Private functions on a drawing surface.				*/
/*									*/
/************************************************************************/

#include <drawDrawingSurface.h>
#include <psPostScriptFontList.h>
#include "appGuiBase.h"

/************************************************************************/
/*									*/
/*  Utility functions.							*/
/*									*/
/************************************************************************/

extern int drawFontImplementationName(char *target, int maxlen,
				      const struct DrawingSurface *ds, int screenFont);

extern int drawOpenDefaultFont(struct DrawingSurface *ds,
			       const PostScriptFontList *psfl, APP_WIDGET w,
			       int fontSizeHintPixels);
