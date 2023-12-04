#include <config.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "drawUtilImpl.h"
#include "drawImpl.h"

#include <appDebugon.h>

/************************************************************************/
/*									*/
/*  Actions in the GTK interface that cannot be done without using	*/
/*  plain old X11, or some knowledge of the relationship between GTK	*/
/*  and X11.								*/
/*									*/
/*  The author is aware of the fact that he should not have done this.	*/
/*									*/
/************************************************************************/


#include <gdk/gdkx.h>
#include "appFrame.h"

void appCopyPixmapValue(APP_SELECTION_EVENT *gsd, APP_BITMAP_IMAGE pixmapCopied)
{
	Pixmap pixmap = GDK_WINDOW_XWINDOW(pixmapCopied);

	gtk_selection_data_set(gsd, gsd->target, 8 * sizeof(Pixmap),
			       (unsigned char *)&pixmap, sizeof(Pixmap));

	return;
}

void appDrawGtkSetXFillRule(GdkGC *gc, int rule)
{
	GC xgc = gdk_x11_gc_get_xgc(gc);

	switch (rule) {
	case GDK_EVEN_ODD_RULE:
		rule = EvenOddRule;
		break;
	case GDK_WINDING_RULE:
		rule = WindingRule;
		break;
	default:
		LDEB(rule);
		rule = EvenOddRule;
		break;
	}

	XSetFillRule(GDK_DISPLAY(), xgc, rule);
}

#ifdef USE_XFT

XftDraw *appGtkXftDrawCreate(GdkDrawable *drawable, AppXftColorList *axcl)
{
	GdkVisual *gdk_vis = gdk_visual_get_system();
	GdkColormap *gdk_cmap = gdk_colormap_get_system();

	Drawable x_drawable;
	XftDraw *xftDraw;

	if (!drawable) {
		XDEB(drawable);
		return (XftDraw *)0;
	}

	axcl->axclDisplay = GDK_WINDOW_XDISPLAY(drawable);


	x_drawable = GDK_WINDOW_XID(drawable);
	axcl->axclVisual = gdk_x11_visual_get_xvisual(gdk_vis);
	axcl->axclColormap = gdk_x11_colormap_get_xcolormap(gdk_cmap);


	xftDraw = XftDrawCreate(axcl->axclDisplay, x_drawable, axcl->axclVisual,
				axcl->axclColormap);

	if (!xftDraw) {
		XDEB(xftDraw);
	}

	return xftDraw;
}

#endif

