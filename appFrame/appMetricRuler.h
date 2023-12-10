/************************************************************************/
/*									*/
/*  Definitions relating to rulers.					*/
/*									*/
/************************************************************************/

#include "appFrame.h"
#include "appRuler.h"
#include <geo2DInteger.h>

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void *appMakeMetricRuler(int sizeAcross, double magnifiedPixelsPerTwip,
				double magnification,
				const PostScriptFontList *psfl,

				int minUnused, int maxUnused,

				int documentC0, int documentC1, int visibleC0,
				int visibleC1,

				int whatUnit);

void appFreeMetricRuler(void *voidmr);

APP_EVENT_HANDLER_H(appRedrawHorizontalMetricRuler, w, voidmr, event);
APP_EVENT_HANDLER_H(appRedrawVerticalMetricRuler, w, voidmr, event);

APP_EVENT_HANDLER_H(appHorizontalRulerConfigure, w, voidmr, event);
APP_EVENT_HANDLER_H(appVerticalRulerConfigure, w, voidmr, event);

void appHorizontalRulerTrackMouse(int *pX0pixels, int *pX1pixels,
					 int *pChanged, APP_WIDGET w,
					 EditApplication *ea,
					 APP_EVENT *downEvent, void *voidmr,
					 EditDocument *ed);

void appVerticalRulerTrackMouse(int *pY0pixels, int *pY1pixels,
				       int *pChanged, APP_WIDGET w,
				       EditApplication *ea,
				       APP_EVENT *downEvent, void *voidmr,
				       EditDocument *ed);

void appScrollHorMetricRuler(void *voidmr, APP_WIDGET w, int d);

void appScrollVertMetricRuler(void *voidmr, APP_WIDGET w, int d);

void appSetMetricRulerRange(void *voidmr, APP_WIDGET w, int docFullV1,
				   int docVisV0, int docVisV1);

void appSetMetricRulerValues(APP_WIDGET w, void *voidmr, int v0, int v1);

void appSetMetricRulerMagnification(APP_WIDGET w, void *voidmr,
					   double magnifiedPixelsPerTwip,
					   double magnification);

void appAdaptMetricRuler(APP_WIDGET w, void *voidmr, int documentC1);

void appDocSetMetricTopRuler(EditDocument *ed, int topRulerHeight,
				    double magnification, int unitInt,
				    APP_EVENT_HANDLER_T mouseDown);

void appDocSetMetricLeftRuler(EditDocument *ed, int topRulerHeight,
				     double magnification, int unitInt,
				     APP_EVENT_HANDLER_T mouseDown);

void appDrawRectangleSelection(rect *drClip,
				      rect *drSelected,
				      struct DrawingSurface* ds,
				      const rect *drScreen, int ox,
				      int oy);

void appRemoveRectangleSelection(const rect *drVisible,
					rect *drSelected,
					APP_WIDGET w);

void appSetHorRectangleSelection(rect *drVisible,
					rect *drSelected,
					int x0Screen, int x1Screen,
					APP_WIDGET w);

void appSetVertRectangleSelection(rect *drVisible,
					 rect *drSelected,
					 int y0Screen, int y1Screen,
					 APP_WIDGET w);

void appMetricRulerDrawHair(EditDocument *ed);

void appMetricRulerExposeValue(EditDocument *ed);
void appMetricRulerChangeValue(EditDocument *ed, int newValue);

void appHorizontalRulerDrawMark(RulerData *rd, int fontBottom, int tagY0,
				       int tagY1, int tickY0, int tickY1,
				       int iitem, int tick, double units,
				       int ox);
