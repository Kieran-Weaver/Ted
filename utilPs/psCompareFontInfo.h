/************************************************************************/
/*									*/
/*  Comparisons between postscript font infos. For sorting and		*/
/*  classification.							*/
/*									*/
/************************************************************************/

#ifndef PS_CMP_FONT_INFO_H
#define PS_CMP_FONT_INFO_H

#include "psFontInfo.h"

/************************************************************************/
/*									*/
/*  Declarations.							*/
/*									*/
/************************************************************************/

int psFontCompareInfosIncludingFamily(const void *voidpafi1,
				      const void *voidpafi2);

int psFontCompareInfosExcludingFamily(const void *voidpafi1,
				      const void *voidpafi2);

#endif
