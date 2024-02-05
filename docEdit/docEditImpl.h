/************************************************************************/
/*									*/
/*  Document Editing.							*/
/*									*/
/************************************************************************/

#ifndef DOC_EDIT_IMPL_H
#define DOC_EDIT_IMPL_H

#include <docBuf.h>
#include <docDebug.h>

/************************************************************************/
/*									*/
/*  Routine Declarations.						*/
/*									*/
/************************************************************************/

void docFlattenRow(struct BufferItem *bi);

int docEditFindPositionOutsideBlockDelete(int *pSide, DocumentPosition *dpNew,
					  const DocumentSelection *dsDel);

int docNewList(const struct DocumentList **pDl, const struct ListOverride **pLo,
	       int lsExample, BufferDocument *bd, const PropertyMask *taSetMask,
	       const TextAttribute *taSet);

int docEditMakeNote(struct DocumentNote **pDn, BufferDocument *bd,
		    DocumentField *dfNote, const struct BufferItem *bodyNode,
		    int treeType, int fieldKind);

#endif /*	DOC_EDIT_IMPL_H	*/
