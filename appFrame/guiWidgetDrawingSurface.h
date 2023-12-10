/************************************************************************/
/*									*/
/*  A widget in the screen GUI. (Implementation)			*/
/*									*/
/************************************************************************/

#include "appGuiBase.h"
#include <drawDrawingSurface.h>
#include <psPostScriptFontList.h>

/************************************************************************/
/*									*/
/*  Routine Declarations.						*/
/*									*/
/************************************************************************/

extern struct DrawingSurface *guiDrawingSurfaceForNativeWidget(APP_WIDGET nativeWidget,
						       int avoidFontconfig);

extern int guiGetLabelFont(struct DrawingSurface *ds, const PostScriptFontList *psfl,
			   APP_WIDGET nativeLabel);

extern void drawMoveArea(struct DrawingSurface *ds, int xDest, int yDest,
			 const DocumentRectangle *drSrc);
