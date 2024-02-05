/************************************************************************/
/*									*/
/*  Document Editing.							*/
/*									*/
/************************************************************************/

#ifndef DOC_COPY_NODE_H
#define DOC_COPY_NODE_H

#include <docBuf.h>
#include "docDocumentCopyJob.h"

/************************************************************************/
/*									*/
/*  Routine Declarations.						*/
/*									*/
/************************************************************************/

int docCopyDocumentTree(DocumentCopyJob *dcj, DocumentTree *eiTo,
			const SelectionScope *ssRoot, DocumentTree *eiFrom);

int docCopySectChildren(DocumentCopyJob *dcj, struct BufferItem *sectBiTo,
			const struct BufferItem *sectBiFrom);

int docCopyParticules(DocumentCopyJob *dcj, struct BufferItem *biTo,
		      const struct BufferItem *biFrom, int partTo, int partFrom,
		      int countFrom, int *pParticulesInserted,
		      int *pCharactersCopied);

int docCopyParticuleAndData(struct TextParticule **pTpTo, DocumentCopyJob *dcj,
			    struct BufferItem *paraBiTo, int partTo,
			    int stroffTo, int strlenTo,
			    const struct BufferItem *paraBiFrom,
			    const struct TextParticule *tpFrom);

int docCopyNote(DocumentCopyJob *dcj, DocumentField *dfTo,
		const DocumentField *dfFrom);

struct DrawingShape *docCopyDrawingShape(DocumentCopyJob *dcj,
					 struct DrawingShape *from);

struct BufferItem *docCopyNode(DocumentCopyJob *dcj,
			       struct BufferItem *parentBiTo, int n,
			       const struct BufferItem *biFrom);

struct BufferItem *docCopyParaNode(DocumentCopyJob *dcj,
				   const SelectionScope *ssRoot,
				   struct BufferItem *parentNodeTo, int n,
				   const struct BufferItem *paraNodeFrom);

#endif /*	DOC_COPY_NODE_H	*/
