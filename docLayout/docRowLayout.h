/************************************************************************/
/*									*/
/*  Document Layout and Printing related functionality.			*/
/*									*/
/************************************************************************/

#ifndef DOC_ROW_LAYOUT_H
#define DOC_ROW_LAYOUT_H

#include <docBuf.h>
#include <docBlockOrnaments.h>

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void
docGetCellOrnaments(BlockOrnaments *cellOrnaments, rect *drOutside,
		    rect *drInside,
		    const rect *drCell, const BufferDocument *bd,
		    const struct BufferItem *rowBi, int col, int atRowTop,
		    int atRowBottom, int drawTableGrid);

void docLayoutCalculateRowTopInset(int *pInset, const BufferDocument *bd,
					  const struct BufferItem *rowBi,
					  int atRowTop);

void docGetCellBottomBorder(BorderProperties *pBpBottom,
				   int *pBpBottomNr, int *pUseBelow,
				   const BufferDocument *bd,
				   const struct BufferItem *rowBi, int col,
				   int atRowBottom);

#endif /*  DOC_ROW_LAYOUT_H  */
