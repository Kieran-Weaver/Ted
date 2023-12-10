/************************************************************************/
/*									*/
/*  Manage bookmarks related to TOC fields.				*/
/*									*/
/************************************************************************/

#ifndef DOC_CALCULATE_TOC_FIELD_H
#define DOC_CALCULATE_TOC_FIELD_H

#include <docRecalculateFields.h>

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int docRecalculateTocFields(RecalculateFields *rf);

int docRecalculateOneTocField(BufferDocument *bdDoc,
				     const DocumentField *df);

#endif /*	DOC_CALCULATE_TOC_FIELD_H	*/
