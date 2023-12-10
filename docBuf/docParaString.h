/************************************************************************/
/*									*/
/*  Text Editor Buffer structure of the string buffer in a paragraph.	*/
/*									*/
/************************************************************************/

#ifndef DOC_PARA_STRING_H
#define DOC_PARA_STRING_H

#include "docBuf.h"
#include "docTreeNode.h"

struct TextConverter;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int docParaAppendText(BufferDocument *bd, BufferItem *paraBi,
			     const TextAttribute *ta, struct TextConverter *tc,
			     const char *text, int len);

int docParaDivideAppendedText(BufferItem *paraBi,
				     int textAttributeNumber, int stroff,
				     int upto);

int docRedivideStringInParticules(BufferItem *bi, int strOff, int strLen,
					 int part, int partsFree,
					 int textAttributeNumber);

int docParaStringReplace(int *pSizeShift, BufferItem *bi,
				int stroffBegin, int stroffTail,
				const char *addedString, int addedStrlen);

int docParaFixStroff(const BufferItem *paraBi, int stroff);

int docParaNextStroff(const BufferItem *paraBi, int stroff);

int docParaPrevStroff(const BufferItem *paraBi, int stroff);

int docParaFirstStroff(const BufferItem *paraBi);

int docParaLastStroff(const BufferItem *paraBi);

void docParaSetupTextConverter(struct TextConverter *tc);

#endif
