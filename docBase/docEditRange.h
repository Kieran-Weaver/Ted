/************************************************************************/
/*									*/
/*  A range in a document.						*/
/*									*/
/************************************************************************/

#ifndef DOC_EDIT_RANGE_H
#define DOC_EDIT_RANGE_H

#include "docEditPosition.h"
typedef struct EditRange {
	EditPosition erHead;
	EditPosition erTail;
} EditRange;

#define docEditRangeIsIBar(er)                             \
	((er)->erHead.epParaNr == (er)->erTail.epParaNr && \
	 (er)->erHead.epStroff == (er)->erTail.epStroff)

/************************************************************************/
/*									*/
/*  Routines.								*/
/*									*/
/************************************************************************/

void docInitEditRange(EditRange *er);

void docShiftEditRange(EditRange *er, int paraFrom, int stroffFrom,
		       int paraShift, int stroffShift);

void docUnionEditRanges(EditRange *erTo, const EditRange *er1,
			const EditRange *er2);

#endif /*	DOC_EDIT_RANGE_H	*/
