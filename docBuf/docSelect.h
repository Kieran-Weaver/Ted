#ifndef DOC_SELECT_H
#define DOC_SELECT_H

#include <docLayoutPosition.h>
#include <docSelectionScope.h>
#include <docObject.h>
#include <docEditPosition.h>
#include <docEditRange.h>
#include "docTableRectangle.h"

/************************************************************************/
/*									*/
/*  Forward declarations of structs.					*/
/*									*/
/************************************************************************/

struct BufferDocument;
struct BufferItem;
struct DocumentTree;
struct DocumentField;

/************************************************************************/
/*									*/
/*  A position in a document.						*/
/*									*/
/*  NOTE Geometry is derived from the position, NOT the other way round.*/
/*									*/
/************************************************************************/

typedef struct DocumentPosition {
	struct BufferItem *dpNode;
	int dpStroff;
} DocumentPosition;

typedef struct DocumentSelection {
	SelectionScope dsSelectionScope;

	DocumentPosition dsHead; /*  E  */
	DocumentPosition dsTail; /*  E  */
	DocumentPosition dsAnchor; /*  E  */

	int dsCol0;
	int dsCol1;
	signed char dsDirection;
} DocumentSelection;

#define docSamePosition(b, e) \
	((b)->dpNode == (e)->dpNode && (b)->dpStroff == (e)->dpStroff)

#define docPositionsInsideParagraph(b, e) ((b)->dpNode == (e)->dpNode)
#define docPositionsInsideCell(b, e) \
	((b)->dpNode->biParent == (e)->dpNode->biParent)
#define docPositionsInsideRow(b, e) \
	((b)->dpNode->biParent->biParent == (e)->dpNode->biParent->biParent)

#define docSelectionInsideParagraph(ds) \
	docPositionsInsideParagraph(&(ds)->dsHead, &(ds)->dsTail)
#define docSelectionInsideCell(ds) \
	docPositionsInsideCell(&(ds)->dsHead, &(ds)->dsTail)
#define docSelectionInsideRow(ds) \
	docPositionsInsideRow(&(ds)->dsHead, &(ds)->dsTail)

/************************************************************************/
/*									*/
/*  Routine Declarations.						*/
/*									*/
/************************************************************************/

void docInitDocumentPosition(DocumentPosition *dp);
void docInitDocumentSelection(DocumentSelection *ds);

void docSetIBarSelection(DocumentSelection *ds, const DocumentPosition *dp);

int docIsIBarSelection(const DocumentSelection *ds);
int docIsParaSelection(const DocumentSelection *ds);

int docGetObjectSelection(const DocumentSelection *ds,
			  const struct BufferDocument *bd, int *pPart,
			  DocumentPosition *dpObject, InsertedObject **pIo);

void docSetRangeSelection(DocumentSelection *ds, const DocumentPosition *dpHead,
			  const DocumentPosition *dpTail, int direction);

int docLineHead(DocumentPosition *dp, int posFlags);
int docLineTail(DocumentPosition *dp, int posFlags);

int docSelectFrameOfPosition(DocumentSelection *ds, const DocumentPosition *dp);

void docGetSelectionScope(SelectionScope *ss, const struct BufferItem *node);

void docSetSelectionScope(DocumentSelection *ds);

int docSelectionSameInstance(const struct DocumentTree *tree, int page,
			     int column);

int docSelectionSameRoot(const DocumentSelection *dsFrom,
			 const struct BufferItem *biTo);

void docSetEditPosition(EditPosition *ep, const DocumentPosition *dp);

void docSetEditRange(EditRange *er, const DocumentSelection *ds);

void docSetIBarRange(EditRange *er, const DocumentPosition *dp);

int docGetTableRectangle(TableRectangle *tr, const DocumentSelection *ds);

int docSetNodeSelection(DocumentSelection *ds, struct BufferItem *node);

void docAvoidMergedTail(DocumentSelection *dsNew, EditRange *er);

#endif /*	DOC_SELECT_H	*/
