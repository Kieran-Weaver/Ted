#ifndef DOC_DRAW_H
#define DOC_DRAW_H

#include <docBuf.h>
#include <docStripFrame.h>
#include <docBlockOrnaments.h>
#include "docLayoutDocumentTree.h"
#include <docBlockFrame.h>
#include <utilIndexMapping.h>
#include <docLayoutPosition.h>
#include "docParticuleData.h"
#include "layoutContext.h"
#include "docSelectionGeometry.h"

struct DrawingContext;

/************************************************************************/

typedef struct ParagraphDrawingStrip {
	int pdsLineFrom;
	int pdsLineUpto;

	int pdsAtParaTop;
	int pdsAtParaBottom;

	LayoutPosition pdsShadeTop;
	LayoutPosition pdsShadeBelow;
} ParagraphDrawingStrip;

typedef struct DrawTextLine {
	void *dtlThrough;
	struct DrawingContext *dtlDrawingContext;

	LayoutPosition dtlShiftedTop;
	DocumentRectangle dtlLineRectangle;
	LayoutPosition dtlBaselinePosition;
	LayoutPosition dtlShiftedBaselinePosition;
	int dtlXShift;
	int dtlYShift;
	int dtlPartUpto;
	const ParticuleData *dtlParticuleData;
	const struct TextLine *dtlTextLine;
	const struct BufferItem *dtlParaNode;
	const ParagraphFrame *dtlParagraphFrame;
	int dtlDrawParticulesSeparately;
} DrawTextLine;

/************************************************************************/
/*									*/
/*  The different resources needed for drawing.				*/
/*									*/
/************************************************************************/

typedef int (*DRAW_TEXT_LINE)(struct BufferItem *paraBi, int line,
			      const struct ParagraphFrame *pf,
			      const DocumentRectangle *drLinePixels,
			      void *through, struct DrawingContext *dc,
			      const BlockOrigin *bo);

typedef int (*DRAW_ORNAMENTS)(const BlockOrnaments *ornaments, int page,
			      const DocumentRectangle *drOutside,
			      const DocumentRectangle *drInside, void *through,
			      struct DrawingContext *dc);

typedef int (*FINISH_PAGE)(void *through, struct DrawingContext *dc,
			   struct BufferItem *bodySectNode, int page,
			   int asLast);

typedef int (*START_PAGE)(void *through, const DocumentGeometry *dg,
			  struct DrawingContext *dc, int page);

typedef int (*SET_COLOR_RGB)(struct DrawingContext *dc, void *through,
			     const RGB8Color *rgb8);

typedef int (*SET_FONT)(struct DrawingContext *dc, void *through,
			int textAttrNr, const TextAttribute *ta);

typedef int (*DRAW_SHAPE)(const DocumentRectangle *drTwips, int page,
			  struct DrawingShape *ds, struct DrawingContext *dc,
			  void *through);

typedef int (*DRAW_OBJECT)(const DrawTextLine *dtl, int part,
			   InsertedObject *io, int x0Twips, int x1Twips,
			   const LayoutPosition *baseLine);

typedef int (*DRAW_TAB)(const DrawTextLine *dtl, int part, int textAttrNr,
			const TextAttribute *ta, int leader, int x0Twips,
			int x1Twips, const LayoutPosition *baseLine);

typedef int (*DRAW_FTNSEP)(const DrawTextLine *dtl, int part, int textAttrNr,
			   const TextAttribute *ta, int x0Twips, int x1Twips,
			   const LayoutPosition *baseLine);

typedef int (*DRAW_UNDERLINE)(const DrawTextLine *dtl, int part, int upto,
			      int textAttrNr, const TextAttribute *ta,
			      int x0Twips, int x1Twips,
			      const LayoutPosition *baseLine);

typedef int (*DRAW_STRIKETHROUGH)(const DrawTextLine *dtl, int part, int upto,
				  int textAttrNr, const TextAttribute *ta,
				  int x0Twips, int x1Twips,
				  const LayoutPosition *baseLine);

typedef int (*START_FIELD)(const DrawTextLine *dtl, int part,
			   const DocumentField *df);

typedef int (*FINISH_FIELD)(const DrawTextLine *dtl, int part,
			    const DocumentField *df);

typedef int (*DRAW_SPAN)(const DrawTextLine *dtl, int part, int count,
			 const LayoutPosition *baseLine, int textAttrNr,
			 const TextAttribute *ta, const char *printString,
			 int nbLen);

typedef struct DrawingContext {
	int dcCurrentTextAttributeSet;
	TextAttribute dcCurrentTextAttribute;
	int dcCurrentColorSet;
	RGB8Color dcCurrentColor;

	LayoutContext dcLayoutContext;
	const DocumentRectangle *dcClipRect;
	const DocumentSelection *dcSelection;
	const SelectionGeometry *dcSelectionGeometry;
	int dcFirstPage;
	int dcLastPage;
	int dcDrawExternalItems;
	int dcPostponeHeadersFooters;
	int dcDocHasPageHeaders;
	int dcDocHasPageFooters;

	int dcDrawTableGrid;

	SET_COLOR_RGB dcSetColorRgb;
	SET_FONT dcSetFont;
	DRAW_SHAPE dcDrawShape;
	DRAW_OBJECT dcDrawObject;
	START_FIELD dcStartField;
	FINISH_FIELD dcFinishField;
	DRAW_TAB dcDrawTab;
	DRAW_FTNSEP dcDrawFtnsep;
	DRAW_UNDERLINE dcDrawUnderline;
	DRAW_STRIKETHROUGH dcDrawStrikethrough;
	DRAW_SPAN dcDrawSpan;

	DRAW_TEXT_LINE dcDrawTextLine; /*  foreground	*/
	DRAW_ORNAMENTS dcDrawOrnaments; /*  background	*/

	FINISH_PAGE dcFinishPage;
	START_PAGE dcStartPage;
	INIT_LAYOUT_EXTERNAL dcInitLayoutExternal;
} DrawingContext;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void docInitDrawTextLine(DrawTextLine *dtl);
void docInitDrawingContext(DrawingContext *dc);

int docDrawNode(LayoutPosition *lpBelow, struct BufferItem *node,
		       void *through, DrawingContext *dc);

int docDrawPageRange(DrawingContext *dc, void *through);

int docDrawPageHeader(struct BufferItem *sectNode, void *through,
			     DrawingContext *dc, int page);

int docDrawPageFooter(struct BufferItem *sectNode, void *through,
			     DrawingContext *dc, int page);

int docDrawShapesForPage(void *through, DrawingContext *dc,
				int belowText, int page);

int docDrawFootnotesForColumn(int page, int column, void *through,
				     DrawingContext *dc);

int docDrawEndnotesForSection(LayoutPosition *lpBelow, int sect,
				     void *through, DrawingContext *dc);

int docDrawEndnotesForDocument(LayoutPosition *lpBelow, void *through,
				      DrawingContext *dc);

int docDrawToColumnOfNode(struct BufferItem *prevBodyBi,
				 struct BufferItem *thisBodyBi,
				 struct BufferItem *thisBi, void *through,
				 LayoutPosition *lpHere, DrawingContext *dc,
				 const BlockOrigin *bo);

void docDrawSetColorRgb(DrawingContext *dc, void *through,
			       const RGB8Color *rgb8);

void docDrawSetColorNumber(DrawingContext *dc, void *through,
				  int colorNumber);

void docDrawSetFont(DrawingContext *dc, void *through, int textAttrNr,
			   const TextAttribute *ta);

int docDrawShapeGetFill(int *pFill, RGB8Color *rgb8Fill,
			       const struct DrawingShape *ds,
			       DrawingContext *dc, void *through);

int docDrawShapeGetLine(int *pLine, RGB8Color *rgb8Stroke,
			       const struct DrawingShape *ds,
			       DrawingContext *dc, void *through);

int docDrawShape(DrawingContext *dc, void *through,
			const struct BufferItem *bodySectNode,
			const InsertedObject *io);

int docDrawRowNode(struct BufferItem *rowBi, void *through,
			  DrawingContext *dc, const BlockOrigin *bo);

int docDrawTableHeader(int *pHigh, const struct BufferItem *rowBi,
			      const BlockFrame *bfRef, void *through,
			      DrawingContext *dc,
			      const LayoutPosition *lpHeader);

int docDrawParagraphStrip(void *through, ParagraphDrawingStrip *pds,
				 struct BufferItem *paraBi, int countAfter,
				 const LayoutPosition *lpShadeTop, int lineFrom,
				 const ParagraphFrame *pf, DrawingContext *dc,
				 const LayoutPosition *lpThisFrame,
				 const BlockOrigin *bo);

int docDrawTextLines(void *through, const ParagraphDrawingStrip *pds,
			    struct BufferItem *paraBi, const ParagraphFrame *pf,
			    DrawingContext *dc, const BlockOrigin *bo);

int docDrawToNextColumn(struct BufferItem *thisBodyBi,
			       struct BufferItem *nextBodyBi, void *through,
			       LayoutPosition *lpHere, BlockFrame *bf,
			       DrawingContext *dc);

int docDrawParaNode(LayoutPosition *lpBelow, struct BufferItem *paraBi,
			   void *through, DrawingContext *dc,
			   const BlockOrigin *bo);

void docSetDrawTextLine(DrawTextLine *dtl, void *through,
			       DrawingContext *dc, const struct TextLine *tl,
			       const struct BufferItem *paraBi,
			       const BlockOrigin *bo, const ParagraphFrame *pf,
			       const DocumentRectangle *drLine);

int docDrawLineParticules(const DrawTextLine *dtl, int *pXTwips,
				 int part);

int docDrawShapeText(const DocumentRectangle *drHere,
			    const struct BufferItem *bodySectNode, int page,
			    int column, struct DrawingShape *ds,
			    DrawingContext *dc, void *through);

#endif
