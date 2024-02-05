/************************************************************************/
/*									*/
/*  A list of shapes.							*/
/*									*/
/************************************************************************/

#ifndef DOC_DOCUMENT_SHAPE_LIST_H
#define DOC_DOCUMENT_SHAPE_LIST_H

#include <utilPagedList.h>

typedef struct DrawingShapeList {
	PagedList dslPagedList;
} DrawingShapeList;

struct DrawingShape *docGetShapeByNumber(const DrawingShapeList *dsl, int n);

void docDeleteShapeFromList(DrawingShapeList *dsl, struct DrawingShape *ds);

void docCleanShapeList(DrawingShapeList *dsl);
void docInitShapeList(DrawingShapeList *dsl);

struct DrawingShape *docClaimDrawingShape(DrawingShapeList *dsl);

struct DrawingShape *docClaimShapeInParent(DrawingShapeList *dsl,
					   struct DrawingShape *parent, int n,
					   int kind);

#endif /*  DOC_DOCUMENT_SHAPE_LIST_H  */
