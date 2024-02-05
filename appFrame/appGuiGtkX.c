#include <config.h>

#include <stdlib.h>

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

