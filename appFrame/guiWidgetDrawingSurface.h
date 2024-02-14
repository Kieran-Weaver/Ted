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

struct DrawingSurface *guiDrawingSurfaceForNativeWidget(APP_WIDGET nativeWidget);

int guiGetLabelFont(struct DrawingSurface *ds, const PostScriptFontList *psfl,
		    APP_WIDGET nativeLabel);

void drawMoveArea(struct DrawingSurface *ds, int xDest, int yDest,
		  const DocumentRectangle *drSrc);
