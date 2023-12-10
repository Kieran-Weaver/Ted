#ifndef LAYOUT_CONTEXT_H
#define LAYOUT_CONTEXT_H

#include <utilIndexMapping.h>
#include <utilMatchFont.h>
#include <docBuf.h>

struct DrawingSurface;

typedef struct LayoutContext {
	struct DrawingSurface *lcDrawingSurface;
	IndexMapping *lcAttributeToScreenFont;
	const PostScriptFontList *lcPostScriptFontList;
	BufferDocument *lcDocument;
	DOC_CLOSE_OBJECT lcCloseObject;

	int lcOx;
	int lcOy;

	GetFontForAttribute lcGetFontForAttribute;

	double lcPixelsPerTwip;
	double lcPageGapPixels;
} LayoutContext;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void layoutInitContext(LayoutContext *lc);

int docLayoutYPixels(const LayoutContext *lc, const LayoutPosition *lp);

int docLayoutXPixels(const LayoutContext *lc, int xTwips);

int docGetPageForYPixels(const LayoutContext *lc, int yPixels);

#endif /*	LAYOUT_CONTEXT_H	*/
