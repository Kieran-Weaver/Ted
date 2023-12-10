/************************************************************************/
/*									*/
/*  Ted, Screen drawing and forcing drawing through			*/
/*  guiExposeDrawingWidget().						*/
/*									*/
/************************************************************************/

#ifndef TED_DRAW_H
#define TED_DRAW_H

#include <docDraw.h>
#include <config.h>
#include <drawDrawingSurface.h>

#if LOG_REDRAWS
#undef BLINK_IBAR
#define BLINK_IBAR 0
#endif

typedef struct ScreenDrawingData {
	RGB8Color sddForeColor;
	RGB8Color sddBehindColor;
	RGB8Color sddGridColor;

	DocumentTree *sddSelRootTree;
	struct BufferItem *sddSelRootNode;
	struct BufferItem *sddSelRootBodySectNode;
	int sddBoxFirstPage;
	int sddBoxLastPage;

	const DocumentRectangle *sddFullRect;
} ScreenDrawingData;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int tedDrawDrawingShape(const DocumentRectangle *drTwips, int page,
			       struct DrawingShape *ds, DrawingContext *dc,
			       void *vsdd);

int tedDrawTextReverse(struct BufferItem *paraBi, int line,
			      const ParagraphFrame *pf,
			      const DocumentRectangle *drLine, void *vsdd,
			      DrawingContext *dc, const BlockOrigin *bo);

int tedDrawTextSelected(struct BufferItem *paraBi, int line,
			       const ParagraphFrame *pf,
			       const DocumentRectangle *drLine, void *vsdd,
			       DrawingContext *dc, const BlockOrigin *bo);

int tedDrawTextLine(struct BufferItem *paraBi, int line,
			   const ParagraphFrame *pf,
			   const DocumentRectangle *drLine, void *vsdd,
			   DrawingContext *dc, const BlockOrigin *bo);

void tedOriginalClipping(DrawingContext *dc, ScreenDrawingData *sdd);

void tedDrawFreePixmap(struct DrawingSurface *sp);

int tedDrawIBar(const DocumentRectangle *drPixels,
		       const LayoutContext *lc);

void tedGetIBarRect(DocumentRectangle *drPixels,
			   const PositionGeometry *pg, const LayoutContext *lc);

int tedDrawObject(const DrawTextLine *dtl, int part, InsertedObject *io,
			 int x0Twips, int x1Twips,
			 const LayoutPosition *baseLine);

void tedDrawShadedRectangle(const LayoutContext *lc,
			    struct DrawingSurface **shadingPixmaps, int pattern,
			    const DocumentRectangle *drShade);

void tedDrawHorizontalBorderLine(struct DrawingSurface *ds, int style,
					int minThick, int x0, int x1, int y);

int tedDrawTab(const DrawTextLine *dtl, int part, int textAttrNr,
		      const TextAttribute *ta, int leader, int x0Twips,
		      int x1Twips, const LayoutPosition *baseLine);

int tedDrawChftnsep(const DrawTextLine *dtl, int part, int textAttrNr,
			   const TextAttribute *ta, int x0Twips, int x1Twips,
			   const LayoutPosition *baseLine);

int tedDrawSpan(const DrawTextLine *dtl, int part, int count,
		       const LayoutPosition *baseLine, int textAttrNr,
		       const TextAttribute *ta, const char *printString,
		       int nbLen);

int tedDrawRunUnderline(const DrawTextLine *dtl, int part, int upto,
			       int textAttrNr, const TextAttribute *ta,
			       int x0Twips, int x1Twips,
			       const LayoutPosition *baseLine);

int tedDrawRunStrikethrough(const DrawTextLine *dtl, int part, int upto,
				   int textAttrNr, const TextAttribute *ta,
				   int x0Twips, int x1Twips,
				   const LayoutPosition *baseLine);

int tedDrawOrnaments(const BlockOrnaments *bo, int page,
			    const DocumentRectangle *drOutside,
			    const DocumentRectangle *drInside, void *through,
			    struct DrawingContext *dc);

int tedDrawSetColorRgb(DrawingContext *dc, void *vsdd,
			      const RGB8Color *rgb8);

#endif /*  TED_DRAW_H	*/
