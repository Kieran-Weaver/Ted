/************************************************************************/
/*									*/
/*  Bookkeeping for PAGEREF fields.					*/
/*									*/
/************************************************************************/

#ifndef DOC_PAGEREF_FIELD_H
#define DOC_PAGEREF_FIELD_H

struct DocumentField;

#include <utilMemoryBuffer.h>

typedef struct PagerefField {
	MemoryBuffer pfBookmark;
	unsigned char pfNumberFormat; /* \*	*/
	unsigned char pfAsHyperlink; /* \h	*/
	unsigned char pfWithPosition; /* \p	*/
} PagerefField;

/************************************************************************/
/*									*/
/*  Administrative routines.						*/
/*									*/
/************************************************************************/

void docInitPagerefField(PagerefField *pf);
void docCleanPagerefField(PagerefField *pf);

int docGetPagerefField(PagerefField *pf, const struct DocumentField *df);

int docSetPagerefField(struct DocumentField *df, const PagerefField *pf);

#endif /*  DOC_PAGEREF_FIELD_H  */
