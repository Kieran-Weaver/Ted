/************************************************************************/
/*									*/
/*  The font list of a document.					*/
/*									*/
/************************************************************************/

#ifndef DOC_FONT_LIST_H
#define DOC_FONT_LIST_H

#include "utilDocFont.h"
typedef struct DocFontSort {
	int arrayIndex;
	int sortIndex;
} DocFontSort;

typedef struct DocumentFontList {
	int dflFontCount;
	DocumentFont **dflFontPages;
	int dflFontPageCount;
	DocFontSort *dflFontSortIndex;
} DocumentFontList;

#define DFL_PGSZ 256

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

DocumentFont *docFontListGetFontByNumber(const DocumentFontList *dfl, int n);

void docInitFontList(DocumentFontList *dfl);

void docCleanFontList(DocumentFontList *dfl);

int docCopyFontList(DocumentFontList *to, const DocumentFontList *from);

DocumentFont *utilDocFontListInsertFont(DocumentFontList *dfl,
					const DocumentFont *df);

int docGetFontByName(DocumentFontList *dfl, const char *fontName);

int docMergeFontIntoFontlist(DocumentFontList *dflTo,
			     const DocumentFont *dfFrom);

const DocumentFont *
utilDocumentFontListGetFontBySortIndex(DocumentFontList *dfl, int idx);

int utilDocumentFontListGetSortIndex(DocumentFontList *dfl, int aidx);

int utilDocumentFontListGetArrayIndex(DocumentFontList *dfl, int sidx);

DocumentFont *utilAddFontToDocList(DocumentFontList *dfl, const char *name,
				   int styleInt, int pitch);

void utilDocFontListClearCharsUsed(DocumentFontList *dfl);

#endif /*  DOC_FONT_LIST_H	*/
