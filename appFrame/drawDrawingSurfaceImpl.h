/************************************************************************/
/*									*/
/*  A surface to draw upon. (Implementation)				*/
/*									*/
/************************************************************************/

#include <drawDrawingSurface.h>
#include "drawImpl.h"
#include "appXftColorList.h"
#include "drawColors.h"

struct DrawingSurface {
	AppColors *dsColors;

	APP_POINT *dsPoints;
	int dsPointCount;

	GdkGC *dsGc;
	GdkDrawable *dsDrawable;

#ifdef USE_XFT
	XftDraw *dsXftDrawable;
	AppXftColorList dsXftColorList;
#endif

	unsigned char dsIsPixmap;
	unsigned char dsAvoidFontconfig;
	NumberedPropertiesList dsScreenFontAdmin;
};

/************************************************************************/
/*									*/
/*  Utility functions.							*/
/*									*/
/************************************************************************/

void drawInitDrawingSurface(struct DrawingSurface *ds);

void drawSetSystemColor(struct DrawingSurface *ds, APP_COLOR_RGB *xc);
