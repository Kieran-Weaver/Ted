/************************************************************************/
/*									*/
/*  Document Layout functionality: Perform the layout of a series	*/
/*  of paragraphs (css: display=block) and table rows			*/
/*  (css: display=table-row)						*/
/*									*/
/************************************************************************/

#ifndef DOC_STRIP_LAYOUT_JOB_H
#define DOC_STRIP_LAYOUT_JOB_H

#include <docStripFrame.h>
#include <docLayoutPosition.h>

/************************************************************************/
/*									*/
/*  For formatting a series of paragraphs. ( Inside a Cell or simply	*/
/*  below eachother )							*/
/*									*/
/************************************************************************/

struct ParagraphLayoutJob;

typedef struct ParagraphLayoutPosition {
	ParagraphFrame plpParagraphFrame;
	/********************************/
	/*  Belongs to the position as	*/
	/*  it depends on the paragraph	*/
	/*  margins.			*/
	/********************************/

	int pspChild;
	int pspChildAdvanced;
	int pspPart;
	int pspLine;
	/********************************/
	/*  Progress in the chain of	*/
	/*  children.			*/
	/********************************/
	struct ParagraphLayoutJob *pspChildren;
	int pspChildCount;
	/********************************/
	/*  Recursion in parallel	*/
	/*  children. (cells in a row)	*/
	/********************************/

	LayoutPosition plpPos;
} ParagraphLayoutPosition;

typedef struct ParagraphLayoutJob {
	int pljChildUpto;

	LayoutPosition cljMergedCellBelowPosion;

	ParagraphLayoutPosition pljPos;
	ParagraphLayoutPosition pljPos0;
} ParagraphLayoutJob;

#define docLayoutAtStripHead(plp) ((plp)->pspChild == 0 && (plp)->pspPart == 0)

#define docLayoutStripDone(plp, plj) ((plp)->pspChild >= (plj)->pljChildUpto)

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void docInitParagraphLayoutPosition(ParagraphLayoutPosition *plp);

void docInitParagraphLayoutJob(ParagraphLayoutJob *plj);
void docCleanParagraphLayoutJob(ParagraphLayoutJob *plj);

int docParagraphLayoutPosClaimChildren(ParagraphLayoutPosition *plj,
					      int count);

void docBeginParagraphLayoutProgress(ParagraphLayoutJob *plj, int child,
					    int line, int part, int pUpto,
					    const LayoutPosition *lp);

void docStripLayoutStartChild(ParagraphLayoutPosition *plp, int child);
void docStripLayoutNextChild(ParagraphLayoutPosition *plp);

#endif /*	DOC_STRIP_LAYOUT_JOB_H */
