/************************************************************************/
/*									*/
/*  Data structures that describe postscript fonts.			*/
/*									*/
/************************************************************************/

#ifndef PS_READ_WRITE_FONT_INFO_H
#define PS_READ_WRITE_FONT_INFO_H

#include <sioGeneral.h>
#include "psFontInfo.h"

/************************************************************************/
/*									*/
/*  Declarations.							*/
/*									*/
/************************************************************************/

void psWriteFontInfoDict(SimpleOutputStream *sos, const AfmFontInfo *afi);

#endif
