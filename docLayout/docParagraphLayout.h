/************************************************************************/
/*									*/
/*  Document Layout and Printing related functionality.			*/
/*									*/
/************************************************************************/

#ifndef DOC_PARAGRAPH_LAYOUT_H
#define DOC_PARAGRAPH_LAYOUT_H

#include <docBuf.h>
#include <docBlockOrnaments.h>

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void docGetParaOrnaments(BlockOrnaments *ornaments,
				rect *drOutside,
				rect *drInside,
				const rect *drPara,
				const BufferDocument *bd,
				const struct BufferItem *paraBi, int atParaTop,
				int atParaBottom);

#endif /*  DOC_PARAGRAPH_LAYOUT_H  */
