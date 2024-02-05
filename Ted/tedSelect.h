
#ifndef TED_SELECT_H
#define TED_SELECT_H

#include <docBuf.h>
#include <docSelectionGeometry.h>
#include <docSelectionDescription.h>
struct EditDocument;

/************************************************************************/
/*									*/
/*  Routine Declarations.						*/
/*									*/
/************************************************************************/

void tedSetSelectionLow(struct EditDocument *ed, const DocumentSelection *dsSet,
			int lastLine, int *pScrolledX, int *pScrolledY);

int tedHasSelection(const struct EditDocument *ed);
int tedHasIBarSelection(const struct EditDocument *ed);

void tedDelimitCurrentSelection(struct EditDocument *ed);

int tedGetObjectSelection(const struct EditDocument *ed, int *pPartObj,
			  DocumentPosition *dpObj, InsertedObject **pIo);

void tedExposeSelection(struct EditDocument *ed, const DocumentSelection *ds,
			const struct BufferItem *bodySectNode, int scrolledX,
			int scrolledY);

int tedGetSelection(DocumentSelection *ds, SelectionGeometry *sg,
		    SelectionDescription *sd, DocumentTree **pTree,
		    struct BufferItem **pBodySectNode,
		    const struct EditDocument *ed);

int tedFindRootForPosition(DocumentPosition *dpFound, PositionGeometry *pgFound,
			   DocumentTree **pTree, struct BufferItem **pSelSectBi,
			   int *pPage, int *pColumn, struct EditDocument *ed,
			   int docX, int docY);

void tedSetSelection(struct EditDocument *ed, const DocumentSelection *dsSet,
		     int lastLine, int *pScrolledX, int *pScrolledY);

void tedSetSelectedPosition(struct EditDocument *ed, const DocumentPosition *dp,
			    int lastLine, int *pScrolledX, int *pScrolledY);

void tedDescribeSelection(struct EditDocument *ed);

#endif /*  TED_SELECT_H	*/
