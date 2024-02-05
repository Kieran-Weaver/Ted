/************************************************************************/
/*									*/
/*  Drawn pulldowns: For color chooser etc.				*/
/*									*/
/************************************************************************/

#include "guiWidgets.h"
#include <drawDrawingSurface.h>

struct AppDrawnPulldown;
typedef void (*AppDrawnPulldownPuldown)(void *through);

typedef struct AppDrawnPulldown {
	APP_WIDGET adpInplaceDrawing;
	APP_WIDGET adpPulldownShell;
	APP_WIDGET adpPulldownDrawing;
	APP_EVENT_HANDLER_T adpClickHandler;
	AppDrawnPulldownPuldown adpPulldown;
	void *adpThrough;
	int adpMouseX;
	int adpMouseY;
	unsigned char adpEnabled;

	struct DrawingSurface *adpInplaceDrawingSurface;
	struct DrawingSurface *adpPulldownDrawingSurface;
	RGB8Color adpInplaceBackgroundColor;

} AppDrawnPulldown;

/************************************************************************/
/*									*/
/*  Declarations.							*/
/*									*/
/************************************************************************/

void appMakeDrawnPulldownInColumn(AppDrawnPulldown *adp,
				  APP_EVENT_HANDLER_T redrawInplace,
				  APP_EVENT_HANDLER_T redrawPulldown,
				  APP_EVENT_HANDLER_T clickHandler,
				  AppDrawnPulldownPuldown pullDown,
				  APP_WIDGET column, void *through);

void appMakeDrawnPulldownInRow(AppDrawnPulldown *adp,
			       APP_EVENT_HANDLER_T redrawInplace,
			       APP_EVENT_HANDLER_T redrawPulldown,
			       APP_EVENT_HANDLER_T clickHandler,
			       AppDrawnPulldownPuldown pullDown, APP_WIDGET row,
			       int column, int colspan, void *through);

void appGuiEnableDrawnPulldown(AppDrawnPulldown *adp, int sensitive);

void appInitDrawnPulldown(AppDrawnPulldown *adp);
void appCleanDrawnPulldown(AppDrawnPulldown *adp);

void appGuiSetDrawnPulldownHeight(AppDrawnPulldown *adp, int height);

void appGuiSetDrawnPulldownStrips(AppDrawnPulldown *adp, int strips);

int appGuiDrawnPulldownGetStrip(int *pStrip, const AppDrawnPulldown *adp,
				const APP_WIDGET w,
				const APP_EVENT *mouseEvent);

void appDrawnPulldownDrawArrow(const DocumentRectangle *drClip, int *pRestWide,
			       int *pRestHigh, APP_WIDGET w,
			       AppDrawnPulldown *adp);

int appFinishDrawnPulldownInplace(AppDrawnPulldown *adp);
int appFinishDrawnPulldownPulldown(AppDrawnPulldown *adp);

void appExposeDrawnPulldownInplace(AppDrawnPulldown *adp);
