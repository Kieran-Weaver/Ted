/************************************************************************/
/*									*/
/*  Document Layout and Printing related functionality.			*/
/*									*/
/************************************************************************/

#ifndef DOC_LAYOUT_H
#define DOC_LAYOUT_H

#include <docBuf.h>
#include <docEditRange.h>
#include <utilIndexMapping.h>
#include "docParticuleData.h"
#include <docStripFrame.h>
#include "docStripLayoutJob.h"
#include "docLayoutDocumentTree.h"
#include <docBlockFrame.h>
#include "layoutContext.h"
#include "docSelectionGeometry.h"

/************************************************************************/

#define includeRectangleY(dr1, dr2)                \
	{                                          \
		if ((dr1)->drY0 > (dr2)->drY0) {   \
			(dr1)->drY0 = (dr2)->drY0; \
		}                                  \
		if ((dr1)->drY1 < (dr2)->drY1) {   \
			(dr1)->drY1 = (dr2)->drY1; \
		}                                  \
	}

/************************************************************************/
/*									*/
/*  Reasons why the formatter stops.					*/
/*									*/
/************************************************************************/

typedef enum FormatterResult {
	FORMATstopREADY = 0,
	FORMATstopFRAME_FULL,
	FORMATstopNEXT_FRAME,
	FORMATstopBLOCK_FULL,

	FORMATstopCOLUMN_BREAK,
	FORMATstopPAGE_BREAK,

	FORMATstopPARTIAL,

	FORMATstop_COUNT
} FormatterResult;

/************************************************************************/
/*									*/
/*  Pass through information for a layout job.				*/
/*									*/
/************************************************************************/

struct LayoutJob;

typedef int (*LAYOUT_SCREEN_LINE)(const struct TextLine *tl,
				  const struct BufferItem *paraNode,
				  const LayoutContext *lc,
				  const ParagraphFrame *ffPixels,
				  ParticuleData *pd);

typedef int (*START_SCREEN_PARAGRAPH)(struct BufferItem *node,
				      const ParagraphFrame *pf,
				      const LayoutContext *lc);

/************************************************************************/
/*									*/
/*  A Layout Job.							*/
/*									*/
/*  A)	The rectangle that is to be redrawn on the screen. Coordinates	*/
/*	are in pixels, but relative to the document as a whole. ( Not	*/
/*	dependent on the position of the scrollbars. ) In non		*/
/*	interactive layout jobs this is a NULL pointer.			*/
/*  B)	Drawing data for font information, scaling from wips to pixels	*/
/*	etc.								*/
/*  C)	The document as a whole.					*/
/*  D)	The Node in the document tree that initiated the layout job.	*/
/*									*/
/*  E)	The current position on paper of the layout job.		*/
/*									*/
/*  F)	Indirection for screen calculations when laying out the		*/
/*	document.							*/
/*									*/
/************************************************************************/

typedef struct LayoutJob {
	rect *ljChangedRectanglePixels; /*  A	*/
	struct BufferItem *ljChangedNode; /*  D	*/
	LayoutContext ljContext;
	int ljReachedDocumentBottom;

	int ljBalancePage;
	int ljBalanceY1;

	const struct BufferItem *ljBodySectNode;

	START_SCREEN_PARAGRAPH ljStartScreenParagraph; /*  F	*/
	LAYOUT_SCREEN_LINE ljLayoutScreenLine; /*  F	*/
} LayoutJob;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void docInitLayoutJob(LayoutJob *lj);
void docCleanLayoutJob(LayoutJob *lj);

int docLayoutLineBox(struct TextLine *tl, struct BufferItem *node,
			    int part, const LayoutContext *lc,
			    ParticuleData *pd, const ParagraphFrame *pf);

int docLayoutParagraphLineExtents(int *pFontSize,
					 const LayoutContext *lc,
					 struct BufferItem *node);

int docLayoutNodeAndParents(struct BufferItem *node, LayoutJob *lj);

int docAdjustParaLayout(struct BufferItem *node, int afterReplace,
			       int stroffFrom, int stroffShift, int stroffUpto,
			       LayoutJob *lj);

void docLayoutColumnTop(LayoutPosition *lpTop, BlockFrame *bf,
			       struct BufferItem *bodySectNode,
			       const LayoutJob *lj);

int docLayoutDocumentTree(DocumentTree *ei, rect *drChanged,
				 int page, int column, int y0Twips,
				 const struct BufferItem *bodySectNode,
				 const LayoutContext *lc,
				 INIT_LAYOUT_EXTERNAL initLayoutExternal,
				 int adjustDocument);

int docLayoutStripChildren(int *pStopCode, ParagraphLayoutJob *plj,
				  BlockFrame *bf, const LayoutJob *lj,
				  struct BufferItem *cellNode);

int docLayoutStackedStrip(struct BufferItem *cellNode, BlockFrame *bf,
				 const LayoutJob *lj, ParagraphLayoutJob *plj);

void docLayoutToNextColumn(LayoutPosition *lpTop, BlockFrame *bf,
				  struct BufferItem *node, const LayoutJob *lj);

int docLayoutRowNode(int *pStopCode, LayoutPosition *lpBelow,
			    const LayoutPosition *lpTop,
			    struct BufferItem *rowBi, BlockFrame *bf,
			    int stayInThisColumn, const LayoutJob *lj);

void docCommitStripLayout(int *pAdvanced, int advanceAnyway,
				 ParagraphLayoutJob *plj, int page, int column,
				 const struct BufferItem *cellNode);

void docFindStripLayoutOrigin(ParagraphLayoutJob *plj, int page,
				     int column,
				     const struct BufferItem *cellNode);

void docLayoutBlockFrame(BlockFrame *bf, struct BufferItem *node,
				const LayoutJob *lj, int page, int column);

int docLayoutFootnotesForColumn(LayoutPosition *lpBelowNotes,
				       const LayoutPosition *lpBelowText,
				       const BlockFrame *refBf, int belowText,
				       const LayoutJob *refLj);

int docLayoutCollectParaFootnoteHeight(
	NotesReservation *nr, int referringPage, int referringColumn,
	BufferDocument *bd, const struct BufferItem *bodySectNode,
	const struct BufferItem *paraNode, int partFrom, int partUpto);

int docCollectFootnotesFromColumn(BlockFrame *bf,
					 const DocumentPosition *dpHere,
					 int partHere, BufferDocument *bd,
					 int referringPage,
					 int referringColumn);

int docNoteSeparatorRectangle(rect *drExtern,
				     DocumentTree **pEiNoteSep, int *pY0Twips,
				     const struct DocumentNote *dnFirstNote,
				     int treeType, const LayoutContext *lc);

int docGetBoxAroundTree(rect *dr,
			       const struct BufferItem *bodySectNode,
			       const DocumentTree *ei, int justUsed, int page,
			       int column, const LayoutContext *lc);

int docTreePrelayout(DocumentTree *ei,
			    const struct BufferItem *bodySectNode,
			    LayoutJob *lj);

int docLayoutNodeImplementation(LayoutPosition *lpBelow,
				       const LayoutPosition *lpTop,
				       struct BufferItem *node, BlockFrame *bf,
				       LayoutJob *lj);

int docSectHeaderFooterPrelayout(struct BufferItem *sectNode,
					LayoutJob *lj);

int docLayoutEndnotesForSection(LayoutPosition *lpBelow,
				       const LayoutPosition *lpTop, int sect,
				       BlockFrame *bf, LayoutJob *lj);

int docLayoutEndnotesForDocument(LayoutPosition *lpBelow,
					const LayoutPosition *lpTop,
					BlockFrame *bf, LayoutJob *lj);

int docLayoutParaLines(int *pStopCode, int isRedo,
			      const ParagraphFrame *pf, LayoutPosition *lpHere,
			      int *pLine, BlockFrame *bf, const LayoutJob *lj,
			      struct BufferItem *paraNode, int part);

int docLayoutSectChildren(LayoutPosition *lpBelow,
				 const LayoutPosition *lpTop,
				 struct BufferItem *sectNode, int from,
				 BlockFrame *bf, LayoutJob *lj);

int docLayoutSectNode(LayoutPosition *lpBelow,
			     const LayoutPosition *lpTop,
			     struct BufferItem *sectNode, BlockFrame *bf,
			     LayoutJob *lj);

int docLayoutTableSlice(LayoutPosition *lpBelow,
			       const LayoutPosition *lpTop,
			       struct BufferItem *parentNode, int from,
			       int upto, BlockFrame *bf, LayoutJob *lj);

void docResetExternalTreeLayout(BufferDocument *bd);

void docDrawingShapeInvalidateTextLayout(struct DrawingShape *ds);

void docShapePageY(LayoutPosition *lpShapeTop,
			  LayoutPosition *lpBelowShape, BlockFrame *bfShape,
			  const struct DrawingShape *ds,
			  const struct BufferItem *paraNode,
			  const LayoutPosition *lpLineTop,
			  const BlockFrame *bf);

void docShapePageRectangle(LayoutPosition *lpShapeTop,
				  LayoutPosition *lpBelowShape, int *pX0,
				  int *pX1, const struct DrawingShape *ds,
				  const struct BufferItem *paraNode,
				  const LayoutPosition *lpLineTop,
				  const ParagraphFrame *pfRef,
				  const BlockFrame *bfRef, int xChar);

int docShapeCheckTextLayout(struct DrawingShape *ds,
				   const rect *drTwips,
				   rect *drChanged,
				   const struct BufferItem *bodySectNode,
				   int page, int column,
				   const LayoutContext *lc,
				   INIT_LAYOUT_EXTERNAL initLayoutExternal);

int docLayoutInvalidateRange(DocumentSelection *dsLayout,
				    BufferDocument *bd, const DocumentTree *ei,
				    EditRange *er);

void docRedoParaStripLayout(const LayoutJob *lj, BlockFrame *bf,
				   const LayoutPosition *lpFrom,
				   struct BufferItem *cellNode, int paraFrom,
				   int paraUpto);

int docCheckPageOfSelectedTree(int *pChanged,
				      struct BufferItem **pBodySectNode,
				      rect *drChanged,
				      DocumentTree *selRootEi,
				      const LayoutContext *lc,
				      INIT_LAYOUT_EXTERNAL initLayoutExternal);

int docSectNotesPrelayout(int sect,
				 const struct BufferItem *bodySectNode,
				 LayoutJob *lj);

void docLayoutSetNodeBottom(int *pChanged, struct BufferItem *node,
				   const LayoutPosition *lp,
				   const LayoutContext *lc,
				   rect *drChanged);

void docLayoutSetBottomPosition(int *pChanged, LayoutPosition *lpBelow,
				       const LayoutPosition *lp,
				       const LayoutContext *lc,
				       rect *drChanged);

int docLayoutGetInitialFrame(BlockFrame *bf, const LayoutJob *lj,
				    const LayoutPosition *lpHere,
				    struct BufferItem *node);

void docLayoutStartNodeLayout(struct BufferItem *node,
				     const LayoutJob *lj,
				     const LayoutPosition *lpHere);

void docLayoutFinishNodeLayout(int *pChanged, struct BufferItem *node,
				      const LayoutJob *lj,
				      const LayoutPosition *lpHere);

int docLayoutFinishSectNode(LayoutPosition *lpBelow,
				   const LayoutPosition *lpTop,
				   struct BufferItem *sectNode, BlockFrame *bf,
				   LayoutJob *lj);

void docLayoutCalculateParaTopInset(const BufferDocument *bd,
					   struct BufferItem *paraNode);

void docLayoutCalculateParaBottomInset(const BufferDocument *bd,
					      struct BufferItem *paraNode);

const AfmFontInfo *docLayoutGetAfi(int *pTextAttrNr, TextAttribute *ta,
					  unsigned char *pLineFlags,
					  const LayoutContext *lc,
					  const struct BufferItem *paraNode,
					  int part);

int docLayoutFontAscDesc(const struct BufferItem *paraNode,
				TextAttribute *ta, rect *drAscDesc,
				int *pBorder, const LayoutContext *lc,
				int part);

int docLayoutStringExtents(int *pWidth, int *pDecWidth,
				  rect *dr,
				  const TextAttribute *ta, int sizeTwips,
				  const BufferDocument *bd,
				  const AfmFontInfo *afi,
				  const char *printString, int len);

int docLayoutInlineObject(TextAttribute *ta, BufferDocument *bd,
				 const struct BufferItem *paraNode, int part,
				 InsertedObject *io, rect *drWord,
				 int *pWordBorder, int *pX1, int x0);

void docLayoutCalculateAfterRowTopInset(struct BufferItem *belowBi,
					       const BufferDocument *bd);

int docLayoutStartParagraph(const LayoutJob *lj, int *pStopCode,
				   struct BufferItem *paraNode,
				   const BlockFrame *bf,
				   ParagraphLayoutPosition *plp);

void docLayoutFinishFrame(const FrameProperties *fp,
				 BlockFrame *bfTextFrame,
				 const BlockFrame *bfFlow, const LayoutJob *lj,
				 const ParagraphLayoutPosition *plpFlow,
				 struct BufferItem *cellNode, int paraFrom,
				 int paraUpto);

int docLayoutParagraphInStrip(int *pStopCode,
				     ParagraphLayoutPosition *plp,
				     BlockFrame *bf, const LayoutJob *lj,
				     int cellTopInset,
				     struct BufferItem *paraNode);

int docLayoutRowInStrip(int *pStopCode, ParagraphLayoutPosition *plp,
			       BlockFrame *bf, const LayoutJob *lj,
			       int cellTopInset, struct BufferItem *paraNode);

int docAdjustParentLayout(const LayoutPosition *lpTop,
				 struct BufferItem *node, BlockFrame *bf,
				 LayoutJob *lj);

int docLayoutCellNode(LayoutPosition *lpBelow,
			     const LayoutPosition *lpTop,
			     struct BufferItem *cellNode, int from,
			     BlockFrame *bf, LayoutJob *lj);

void docRowLayoutRowspanAdmin(struct BufferItem *cellNode,
				     const struct BufferItem *rowBi,
				     const struct BufferItem *nextRowBi,
				     int nextRow, const CellProperties *cp,
				     int l, int r, ParagraphLayoutJob *plj);

void docCellStripFrame(struct BufferItem *cellNode, const BlockFrame *bf,
			      ParagraphLayoutJob *plj);

void docGetPixelRect(rect *drPixels,
			    const LayoutContext *lc,
			    const rect *drTwips, int page);

void docGetPixelRectForPos(rect *drPixels,
				  const LayoutContext *lc, int x0Twips,
				  int x1Twips, const LayoutPosition *lpTop,
				  const LayoutPosition *lpBottom);

void docGetPageRectPixels(rect *drPixels,
				 const LayoutContext *lc, int page);

void docGetPixelRectangleForPages(rect *drPixels,
					 const LayoutContext *lc, int page0,
					 int page1);

void docPixelRectangleForPositions(rect *drPixels,
					  const PositionGeometry *pgB,
					  const PositionGeometry *pgE,
					  const LayoutContext *lc);

int docLayoutScapsScreenFont(const LayoutContext *lc,
				    const TextAttribute *ta);

void docNodeRectangle(rect *drPixels,
			     struct BufferItem *node, const LayoutContext *lc,
			     const BlockOrigin *bo);

int docGetFirstSectionOnPage(BufferDocument *bd, int page);

int docFindHeaderFooterForY(DocumentTree **pTree,
				   struct BufferItem **pSelSectNode,
				   int *pColumn, const LayoutContext *lc,
				   struct BufferItem *bodySectNode,
				   BufferDocument *bd, int page, int docY);

void docPageRectsPixels(rect *drOutside,
			       rect *drInside, double xfac,
			       const struct BufferItem *bodySectNode,
			       const BufferDocument *bd);

int docSectColumnsAreBalanced(const struct BufferItem *sectNode);

int docAdjustLayoutToChangedTree(LayoutPosition *lpHere,
					struct BufferItem *node, LayoutJob *lj);

void docLayoutAdjustFrame(BlockFrame *bf, const struct BufferItem *node);

#endif /*  DOC_LAYOUT_H  */
