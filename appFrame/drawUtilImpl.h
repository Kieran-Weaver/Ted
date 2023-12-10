/************************************************************************/
/*									*/
/*  Gtk/Gdk implementation utility functions.            		*/
/*									*/
/************************************************************************/

#include "appGuiBase.h"
#include "drawImpl.h"
#include "drawColors.h"
#include "appXftColorList.h"
#include <bitmap.h>

/************************************************************************/
/*									*/
/*  Utility Routines							*/
/*									*/
/************************************************************************/

int drawUtilGtkMakeImage(APP_IMAGE **pPimage, int toWide, int toHigh,
				AppColors *ac, const RasterImage *abi,
				const rect *drSrc);

XftDraw *appGtkXftDrawCreate(GdkDrawable *drawable,
				    AppXftColorList *axcl);

AppColors *guiGetColorsGtk(void);

void guiCollectExposuresGtk(rect *drClip, GdkWindow *window,
				   APP_EVENT *event);

void appDrawGtkSetXFillRule(GdkGC *gc, int rule);

