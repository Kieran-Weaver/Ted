/************************************************************************/
/*									*/
/*  A surface to draw upon.						*/
/*									*/
/************************************************************************/

#ifndef GUI_DRAWING_SURFACE_H
#define GUI_DRAWING_SURFACE_H

#include <utilColor.h>
#include <geo2DInteger.h>
#include <geoAffineTransform.h>
#include <psFontInfo.h>
#include <bitmap.h>

struct DrawingSurface;

/************************************************************************/
/*									*/
/*  Line attributes.							*/
/*									*/
/************************************************************************/

typedef enum LineStyle {
	LineStyleSolid,
	LineStyleSingleDash,
	LineStyleDoubleDash,

	LineStyle_Count
} LineStyle;

typedef enum LineCap {
	LineCapNotLast,
	LineCapButt,
	LineCapRound,
	LineCapProjecting,

	LineCap_Count
} LineCap;

typedef enum LineJoin {
	LineJoinMiter,
	LineJoinRound,
	LineJoinBevel,

	LineJoin_Count
} LineJoin;

/************************************************************************/
/*									*/
/*  Routine Declarations.						*/
/*									*/
/************************************************************************/

extern void drawFreeDrawingSurface(struct DrawingSurface* ds);

extern int drawSetForegroundColor(struct DrawingSurface* ds, const RGB8Color *rgb8);

extern void drawFillRectangle(struct DrawingSurface* ds,
			      const DocumentRectangle *drLogical);
extern void drawRectangle(struct DrawingSurface* ds,
			  const DocumentRectangle *drLogical);

extern int drawOpenScreenFont(struct DrawingSurface* ds, const AfmFontInfo *afi,
			      int pixelSize, const IndexSet *unicodesWanted);

extern struct DrawingSurface *drawMakeDrawingSurfaceForParent(struct DrawingSurface* parent,
						      int wide, int high);

extern struct DrawingSurface *drawMakeDrawingSurfaceForImageAndParent(
	struct DrawingSurface* parent, const RasterImage *abi,
	const DocumentRectangle *drSrc, int wide, int high);

extern int drawRasterImage(struct DrawingSurface* ds, const DocumentRectangle *drDest,
			   const RasterImage *abi,
			   const DocumentRectangle *drSrc);

extern int drawString(struct DrawingSurface* ds, int x0, int y0, int screenFont,
		      const char *s, int len);

extern void drawSymbol(struct DrawingSurface* ds, int x, int y, int screenFont,
		       int symbol);

extern int drawSetLineAttributes(struct DrawingSurface* ds, int lineWidth,
				 int lineStyle, int capStyle, int joinStyle,
				 const unsigned char *dashList, int dashCount);

extern int drawLine(struct DrawingSurface* ds, int x0, int y0, int x1, int y1);

extern int drawLines(struct DrawingSurface* ds, const Point2DI *points, int count,
		     int close);

extern int drawFillPolygon(struct DrawingSurface* ds, const Point2DI *points,
			   int count);

extern void drawArc(struct DrawingSurface* ds, const Arc2DI *arc);

extern void drawFillArc(struct DrawingSurface* ds, const Arc2DI *arc);

extern int drawGetTextExtents(DocumentRectangle *drText,
			      const struct DrawingSurface* ds, int x0, int y0,
			      int screenFont, const char *s, int len);

extern int drawGetSymbolExtents(DocumentRectangle *drText, struct DrawingSurface *ds,
				int x0, int y0, int screenFont, int symbol);

extern int drawGetUnderlineGeometry(int *pThick, int *pY,
				    const struct DrawingSurface* ds, int screenFont,
				    int baselinePixels);

extern int drawGetStrikethroughGeometry(int *pThick, int *pY,
					const struct DrawingSurface* ds, int screenFont,
					int baselinePixels);

extern int drawSetForegroundColorWhite(struct DrawingSurface* ds);
extern int drawSetForegroundColorBlack(struct DrawingSurface* ds);

extern int drawGetSubBaseline(int *pSubBaseline, const struct DrawingSurface* ds,
			      int screenFont, int baselinePixels);

extern int drawGetSuperBaseline(int *pSuperBaseline, const struct DrawingSurface* ds,
				int screenFont, int baselinePixels);

extern void drawSetClipRect(struct DrawingSurface* ds, const DocumentRectangle *drClip);

extern void drawNoClipping(struct DrawingSurface* ds);

extern void drawChildSurface(struct DrawingSurface* ds, const struct DrawingSurface* child,
			     int xDest, int yDest,
			     const DocumentRectangle *drChild);

#endif /*	GUI_DRAWING_SURFACE_H	*/
