/************************************************************************/
/*									*/
/*  PostScript printing.						*/
/*									*/
/************************************************************************/

#include <sioGeneral.h>
#include <psPrint.h>
#include <docBuf.h>
#include "docDraw.h"
#include "docParticuleData.h"

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int docPsPrintGetDocumentFonts(PostScriptTypeList *pstl,
				      const LayoutContext *lc);

int docPsPrintTab(const DrawTextLine *dtl, int part, int textAttrNr,
			 const TextAttribute *ta, int leader, int x0Twips,
			 int x1Twips, const LayoutPosition *baseLine);

void docPsSaveTabLeaderProcedures(SimpleOutputStream *sos);

int docPsPrintDrawDrawingShape(const rect *drTwips,
				      int page, struct DrawingShape *ds,
				      DrawingContext *dc, void *vps);

int docPsPrintObject(const DrawTextLine *dtl, int part,
			    InsertedObject *io, int x0Twips, int x1Twips,
			    const LayoutPosition *baseLine);

int docPsPrintShapeImage(PrintingState *ps, DrawingContext *dc,
				struct DrawingShape *ds,
				const rect *drTwips,
				const AffineTransform2D *at);

int docPsPrintTextLine(struct BufferItem *paraBi, int line,
			      const ParagraphFrame *pf,
			      const rect *drLine, void *vps,
			      DrawingContext *dc, const BlockOrigin *bo);

int docPsPrintStartField(const DrawTextLine *dtl, int part,
				const DocumentField *df);

int docPsPrintFinishField(const DrawTextLine *dtl, int part,
				 const DocumentField *df);

int docPsPrintFtnsep(const DrawTextLine *dtl, int part, int textAttrNr,
			    const TextAttribute *ta, int x0Twips, int x1Twips,
			    const LayoutPosition *baseLine);

int docPsPrintSpan(const DrawTextLine *dtl, int part, int count,
			  const LayoutPosition *baseLine, int textAttrNr,
			  const TextAttribute *ta, const char *printString,
			  int nbLen);

int docPsPrintRunUnderline(const DrawTextLine *dtl, int part, int upto,
				  int textAttrNr, const TextAttribute *ta,
				  int x0Twips, int x1Twips,
				  const LayoutPosition *baseLine);

int docPsPrintRunStrikethrough(const DrawTextLine *dtl, int part,
				      int upto, int textAttrNr,
				      const TextAttribute *ta, int x0Twips,
				      int x1Twips,
				      const LayoutPosition *baseLine);

void psDefineBorderProcs(SimpleOutputStream *sos);

int docPsPrintOrnaments(const BlockOrnaments *bo, int page,
			       const rect *drOutside,
			       const rect *drInside, void *through,
			       struct DrawingContext *dc);

int docPsDocinfoPdfmark(PrintingState *ps, const char *applicationName,
			       const char *applicationReference,
			       const DocumentProperties *dp);

int docPsOutlinePdfmarks(PrintingState *ps, BufferDocument *bd);
