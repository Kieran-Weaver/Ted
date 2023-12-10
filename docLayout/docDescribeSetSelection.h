/************************************************************************/
/*									*/
/*  Describe what is to be done because a new selection is set in a	*/
/*  formatted document.							*/
/*									*/
/************************************************************************/

#ifndef DOC_DESCRIBE_SET_SELECTION_H
#define DOC_DESCRIBE_SET_SELECTION_H

#include <docBuf.h>
#include "layoutContext.h"

int docDescribeSetSelection(DocumentTree **pTreeSet,
				   struct BufferItem **pBodySectNodeSet,
				   rect *drExternalSet,
				   int *pRedrawOldTree, int *pRedrawNewTree,
				   LayoutContext *lc, BufferDocument *bd,
				   const DocumentSelection *dsOld,
				   const DocumentSelection *dsSet);

#endif /*  DOC_DESCRIBE_SET_SELECTION_H  */
