#ifndef UTIL_PS_H
#define UTIL_PS_H

#include <sioGeneral.h>
#include <geo2DInteger.h>
#include <utilDocumentGeometry.h>
#include "psFace.h"
#include <geoAffineTransform.h>
#include "psNup.h"
#include <utilColor.h>
#include <utilMemoryBuffer.h>
#include "psPostScriptFontList.h"

/************************************************************************/
/*									*/
/*  The state of a printing job.					*/
/*									*/
/************************************************************************/

typedef struct PrintingState {
	SimpleOutputStream *psSos;

	int psLastPageMarked;
	int psLastSheetMarked;
	int psPagesPrinted;
	int psSheetsPrinted;
	int psSheetsStarted;

	const PostScriptFontList *psPostScriptFontList;
	PrintGeometry psPrintGeometry;
	NupSchema psNupSchema;
	int psRotateSheetGrid;

	AffineTransform2D psCurrentTransform;
	const char *psOrientation;

	DocumentRectangle psSheetBoundingBox;

	int psInsideLink;
	int psLinkParticulesDone;
	int psLinkRectLeft;

	MemoryBuffer psNoteRef;
	MemoryBuffer psNoteDef;

	MemoryBuffer psLinkFile;
	MemoryBuffer psLinkMark;

	unsigned char psUsePostScriptFilters;
	unsigned char psUsePostScriptIndexedImages;
	unsigned char ps7Bits;
} PrintingState;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void psStartDSCDocument(const PrintingState *ps, const PostScriptTypeList *psfl,
			const char *title, const char *creatorName,
			const char *creatorReference);

void psRefreshNupSchema(PrintingState *ps, const DocumentGeometry *dgPage);

int psSetNupSchema(PrintingState *ps, const DocumentGeometry *dgPage,
		   const PrintGeometry *pg, int hasPageHeader,
		   int hasPageFooter);

int psPrintString(SimpleOutputStream *sos, const unsigned char *s, int len,
		  int sevenBits);

int psPrintPdfMarkStringValue(PrintingState *ps, const unsigned char *s,
			      int len);

int psPrintStringValue(PrintingState *ps, const unsigned char *s, int len);

int psMoveShowString(PrintingState *ps, const unsigned char *s, int len, int x,
		     int y);

int psShowString(PrintingState *ps, const unsigned char *s, int len);

int psSetFont(PrintingState *ps, const AfmFontInfo *afi,
	      const TextAttribute *ta);

void psInitPrintingState(PrintingState *ps);
void psCleanPrintingState(PrintingState *ps);

int psSetRgb8Color(PrintingState *ps, const RGB8Color *rgb8);

int psStartPage(PrintingState *ps, int documentPage);

int psFinishPage(PrintingState *ps, int documentPage, int asLast);

void psAbortPage(PrintingState *ps, int documentPage, int asLast);

void psSelectFontProcedures(SimpleOutputStream *sos,
			    const PostScriptTypeList *psfl, int allFonts);

int psIncludeFonts(SimpleOutputStream *sos, const PostScriptTypeList *psfl);

void psStartEpsFile(SimpleOutputStream *sos, const char *creator,
		    const char *title, int pointsWide, int pointsHigh);

void psFinishEpsFile(SimpleOutputStream *sos);

void psSetPdfmarkEmulation(SimpleOutputStream *sos);
void psImageQualityDistillerparams(SimpleOutputStream *sos);
void psSetRectfillEmulation(SimpleOutputStream *sos);
void psSetSelectfontEmulation(SimpleOutputStream *sos);
void psSetDefinePageFontImplementation(SimpleOutputStream *sos);
void psSetUtf8ShowImplementation(SimpleOutputStream *sos);
void psSetMvsImplementation(SimpleOutputStream *sos);
void psSetPatternImplementation(SimpleOutputStream *sos, double shadingMesh);

void psDefineProcedure(SimpleOutputStream *sos, const char **lines, int count);

void psDefineEpsProcs(SimpleOutputStream *sos);

void psBeginEpsObject(SimpleOutputStream *sos, const DocumentRectangle *drTo,
		      const DocumentRectangle *drBBox, const char *file);

void psEndEpsObject(SimpleOutputStream *sos);

int psDestPdfmark(PrintingState *ps, int lineTop, const MemoryBuffer *mbRef);

int psEmitDestPdfmark(SimpleOutputStream *sos, const AffineTransform2D *at,
		      int lineTop, const MemoryBuffer *mbRef);

void psTransformMatrix(SimpleOutputStream *sos, const AffineTransform2D *at);

void psFillRectangle(PrintingState *ps, int x, int y, int wide, int high);

void psRectanglePath(PrintingState *ps, int x, int y, int wide, int high);

void psFlushLink(PrintingState *ps, int x0, int wide, int lineTop,
		 int lineHeight);

void psSourcePdfmark(SimpleOutputStream *sos, const DocumentRectangle *drLink,
		     const MemoryBuffer *fileName,
		     const MemoryBuffer *markName);

int psPageModePdfmark(SimpleOutputStream *sos, const char *pageMode);

int psSaveEpsFile(SimpleOutputStream *sos, DocumentRectangle *drBBox,
		  const MemoryBuffer *filename);

int psIncludeEpsFile(SimpleOutputStream *sos, SimpleInputStream *sis);

void psDscListFontNames(SimpleOutputStream *sos, int embedFonts,
			const PostScriptTypeList *pstl);

void psSetFontName(char *fontName, const AfmFontInfo *afi);

int psSetToPdfCommand(MemoryBuffer *command, int pageTwipsWide,
		      int pageTwipsHigh, const MemoryBuffer *filename);

int psOutlinePdfmark(PrintingState *ps, int childCount, int closed,
		     const MemoryBuffer *title, const MemoryBuffer *markName);

#endif /*  UTIL_PS_H  */
