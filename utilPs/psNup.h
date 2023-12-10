#ifndef UTIL_NUP_H
#define UTIL_NUP_H

#include <geo2DInteger.h>
#include <utilDocumentGeometry.h>
#include <geoAffineTransform.h>

/************************************************************************/
/*									*/
/*  Position the pages of a document on successive sheets of paper.	*/
/*									*/
/************************************************************************/

typedef struct NupSchema {
	AffineTransform2D nsBaseTransform;
	int nsNup;
	int nsRows;
	int nsCols;
	AffineTransform2D *nsNupTransforms;
	int nsXShift;
} NupSchema;

/************************************************************************/
/*									*/
/*  Geometry specifications for a print job.				*/
/*									*/
/************************************************************************/

typedef struct PrintGeometry {
	DocumentGeometry pgSheetGeometry;
	int pgRotatePage90;
	int pgCenterPageHorizontally;
	int pgGridRows;
	int pgGridCols;
	int pgGridHorizontal;
	int pgScalePagesToFit;

	int pgPrintOddSides;
	int pgPrintEvenSides;
	int pgPrintSheetsReverse;
	int pgPrintBookletOrder;

	int pgFirstPage;
	int pgLastPage;
	int pgUsePostScriptFilters;
	int pgUsePostScriptIndexedImages;
	int pg7Bits;
	int pgSkipEmptyPages;
	int pgSkipBlankPages;
	int pgOmitHeadersOnEmptyPages;
	int pgEmbedFonts;

	/**
			 *  Filename of a file to initialize PS 
			 *  printing: Owned by the caller.
			 */
	const char *pgCustomPsSetupFilename;
} PrintGeometry;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void psInitPrintGeometry(PrintGeometry *pg);
void psCleanPrintGeometry(PrintGeometry *pg);

void psInitNupSchema(NupSchema *ns);
void psCleanNupSchema(NupSchema *ns);

int psNupFitPagesToSheet(int *pFitWithoutRot, int *pFitWithRot,
				const PrintGeometry *pg,
				const DocumentGeometry *dgPage);

int utilNupGetBaseTranform(AffineTransform2D *pAt1Page,
				  int *pRotatePages, const PrintGeometry *pg,
				  const DocumentGeometry *dgPage, double fac);

void psNupSheetBoundingBox(DocumentRectangle *sheetBBox,
				  const NupSchema *ns,
				  const DocumentGeometry *dgPage,
				  int hasPageHeader, int hasPageFooter);

int utilNupSetSchema(NupSchema *ns, int rotateSheetGrid,
			    const AffineTransform2D *at1Page,
			    const PrintGeometry *pg, double fac,
			    const DocumentGeometry *dgPage);

void utilNupGetPageTranform(AffineTransform2D *at, const NupSchema *ns,
				   int page);

#endif /*  UTIL_NUP_H  */
