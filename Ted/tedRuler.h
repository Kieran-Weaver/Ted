/************************************************************************/
/*									*/
/*  Definitions relating to rulers.					*/
/*									*/
/************************************************************************/

#include <appFrame.h>
#include "tedColumnSeparator.h"

struct TabStopList;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int tedDocSetLeftRuler(EditDocument *ed);
int tedDocSetRightRuler(EditDocument *ed);
int tedDocSetTopRuler(EditDocument *ed);
int tedDocSetBottomRuler(EditDocument *ed);

void tedVerticalRulerSetBackground(void *voidrd, const RGB8Color *back);
void tedTopRulerSetBackground(void *voidttr, const RGB8Color *back);
void tedBottomRulerSetBackground(void *voidtbr, const RGB8Color *back);

void *tedMakeTopRuler(int height, double magnifiedPixelsPerTwip,
		      double magnification, const PostScriptFontList *psfl,

		      int leftRulerWidth, int rightRulerWidth,

		      int docX0, int docX1, int marginC0, int marginC1,
		      int docVisibleX0, int docVisibleX1,

		      int whatUnit);

void *tedMakeBottomRuler(const PostScriptFontList *psfl, int height,
			 int leftRulerWidth, int rightRulerWidth,
			 const char *pageFormat);

void tedFreeVerticalRuler(void *voidrd);
void tedFreeTopRuler(void *voidttr);
void tedFreeBottomRuler(void *voidtlr);

APP_EVENT_HANDLER_H(tedRedrawTopRuler, w, voidttr, event);
APP_EVENT_HANDLER_H(tedRedrawBottomRuler, w, voidtlr, event);

void tedScrollTopRuler(void *voidttr, APP_WIDGET w, int d);

void tedSetTopRulerRange(void *voidttr, APP_WIDGET w, int docFullX1,
			 int docVisX0, int docVisX1);

void tedAdaptTopRuler(void *voidttr, APP_WIDGET w, int docX0, int docX1,
		      int marginC0, int marginC1, int firstIndent,
		      int leftIndent, int rightIndent,
		      const struct TabStopList *tslSet, int x0GeometryPx,
		      double xfac);

int tedTopRulerFindMouse(int *pIndex, APP_WIDGET w, int mouseX, int mouseY,
			 EditDocument *ed);

int tedTopRulerTrackMouse(int *pFirstIndent, int *pLeftIndent,
			  int *pRightIndent, struct TabStopList *tsl,
			  int *pCsCount, ColumnSeparator **pCs, APP_WIDGET w,
			  APP_EVENT *downEvent, EditDocument *ed);

APP_EVENT_HANDLER_H(tedTopRulerConfigure, w, voidttr, event);
APP_EVENT_HANDLER_H(tedBottomRulerConfigure, w, voidtlr, event);

int tedSetRulerColumns(APP_WIDGET w, void *voidttr, int bfX0Pixels,
		       int bfX1Pixels, int pfX0Pixels, int pfX1Pixels,
		       ColumnSeparator *cs, int csCount);

void tedSetBottomRulerValues(void *voidtbr, APP_WIDGET w, int page, int pages,
			     int section, int sections);
