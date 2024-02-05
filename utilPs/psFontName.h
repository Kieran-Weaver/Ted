/************************************************************************/
/*									*/
/*  Analysis and manipulation of font names.				*/
/*									*/
/************************************************************************/

#ifndef PS_FONT_NAME_H
#define PS_FONT_NAME_H

#include "psFontInfo.h"

/************************************************************************/
/*									*/
/*  Declarations.							*/
/*									*/
/************************************************************************/

int utilFontWeightFromString(int *pWeight, int *pStart, int *pLength,
			     const char *name);

int utilFontWidthFromString(int *pWidth, int *pStart, int *pLength,
			    const char *name);

int psRemoveWidthFromName(char *target, int maxlen, int *pWidth,
			  const char *name);

int psFontInfoMoveWidthToFamilyName(AfmFontInfo *afi);

const char *psWidthStr(int width);
const char *psWeightStr(int weight);

int psFontGetWeight(unsigned char *pWeight, const char *weight);
int psFontGetWidth(int *pWidth, const char *swdth);

#endif
