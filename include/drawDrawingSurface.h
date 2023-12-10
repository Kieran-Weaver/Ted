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

void drawFreeDrawingSurface(struct DrawingSurface* ds);

int drawSetForegroundColor(struct DrawingSurface* ds, const RGB8Color *rgb8);

void drawFillRectangle(struct DrawingSurface* ds,
			      const rect *drLogical);
void drawRectangle(struct DrawingSurface* ds,
			  const rect *drLogical);

int drawOpenScreenFont(struct DrawingSurface* ds, const AfmFontInfo *afi,
			      int pixelSize, const IndexSet *unicodesWanted);

struct DrawingSurface *drawMakeDrawingSurfaceForParent(struct DrawingSurface* parent,
						      int wide, int high);

struct DrawingSurface *drawMakeDrawingSurfaceForImageAndParent(
	struct DrawingSurface* parent, const RasterImage *abi,
	const rect *drSrc, int wide, int high);

int drawRasterImage(struct DrawingSurface* ds, const rect *drDest,
			   const RasterImage *abi,
			   const rect *drSrc);

int drawString(struct DrawingSurface* ds, int x0, int y0, int screenFont,
		      const char *s, int len);

void drawSymbol(struct DrawingSurface* ds, int x, int y, int screenFont,
		       int symbol);

int drawSetLineAttributes(struct DrawingSurface* ds, int lineWidth,
				 int lineStyle, int capStyle, int joinStyle,
				 const unsigned char *dashList, int dashCount);

int drawLine(struct DrawingSurface* ds, int x0, int y0, int x1, int y1);

int drawLines(struct DrawingSurface* ds, const vec2 *points, int count,
		     int close);

int drawFillPolygon(struct DrawingSurface* ds, const vec2 *points,
			   int count);

void drawArc(struct DrawingSurface* ds, const Arc2DI *arc);

void drawFillArc(struct DrawingSurface* ds, const Arc2DI *arc);

int drawGetTextExtents(rect *drText,
			      const struct DrawingSurface* ds, int x0, int y0,
			      int screenFont, const char *s, int len);

int drawGetSymbolExtents(rect *drText, struct DrawingSurface *ds,
				int x0, int y0, int screenFont, int symbol);

int drawGetUnderlineGeometry(int *pThick, int *pY,
				    const struct DrawingSurface* ds, int screenFont,
				    int baselinePixels);

int drawGetStrikethroughGeometry(int *pThick, int *pY,
					const struct DrawingSurface* ds, int screenFont,
					int baselinePixels);

int drawSetForegroundColorWhite(struct DrawingSurface* ds);
int drawSetForegroundColorBlack(struct DrawingSurface* ds);

int drawGetSubBaseline(int *pSubBaseline, const struct DrawingSurface* ds,
			      int screenFont, int baselinePixels);

int drawGetSuperBaseline(int *pSuperBaseline, const struct DrawingSurface* ds,
				int screenFont, int baselinePixels);

void drawSetClipRect(struct DrawingSurface* ds, const rect *drClip);

void drawNoClipping(struct DrawingSurface* ds);

void drawChildSurface(struct DrawingSurface* ds, const struct DrawingSurface* child,
			     int xDest, int yDest,
			     const rect *drChild);

#endif /*	GUI_DRAWING_SURFACE_H	*/
