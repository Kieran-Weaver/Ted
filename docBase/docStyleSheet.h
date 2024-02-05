/************************************************************************/
/*									*/
/*  The stylesheet of a document.					*/
/*									*/
/************************************************************************/

#ifndef DOC_STYLE_SHEET_H
#define DOC_STYLE_SHEET_H

#include "docStyle.h"

typedef struct DocumentStyleSheet {
	DocumentStyle **dssStyles;
	int dssStyleCount;
	void *dssStylesByName;
} DocumentStyleSheet;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

DocumentStyle *docInsertStyle(DocumentStyleSheet *dss, int n,
			      const DocumentStyle *dsFrom,
			      const DocumentAttributeMap *dam);

void docInitStyleSheet(DocumentStyleSheet *dss);
void docCleanStyleSheet(DocumentStyleSheet *dss);

DocumentStyle *docGetStyleByName(const DocumentStyleSheet *dss,
				 const char *styleName);

int docCopyStyleSheet(DocumentStyleSheet *to, const DocumentStyleSheet *from,
		      const DocumentAttributeMap *dam);

#endif /*  DOC_STYLE_SHEET_H  */
