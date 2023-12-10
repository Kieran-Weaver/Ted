/************************************************************************/
/*									*/
/*  Quad Tree implementation.						*/
/*									*/
/*  Some kind of balancing is achieved by dividing a rectangle in	*/
/*  quadrants. No attempt is made to balance the tree when the entries	*/
/*  are not evenly spaced.						*/
/*									*/
/************************************************************************/

#ifndef GEO_QUAD_TREE_H
#define GEO_QUAD_TREE_H

#include "geo2DInteger.h"

typedef enum Quadrant {
	QTquadNE,
	QTquadNW,
	QTquadSW,
	QTquadSE,

	QTquad_COUNT
} Quadrant;

typedef enum Octant {
	QToctENE,
	QToctNNE,
	QToctNNW,
	QToctWNW,
	QToctWSW,
	QToctSSW,
	QToctSSE,
	QToctESE,

	QToct_COUNT
} Octant;

typedef struct QuadNode {
	int qnX;
	int qnY;

	struct QuadNode *qn_parent;
	struct QuadNode *qnChildren[QTquad_COUNT];

	short int qnBusy;
	int qnValueCount;
	void **qnValues;
} QuadNode;

typedef struct QuadTree {
	DocumentRectangle qtRectangle;
	int qtDiameter;
	QuadNode *qtRootNode;
} QuadTree;

typedef int (*QuadForAllFilter)(const DocumentRectangle *dr, void *through);

typedef int (*QuadForAllCall)(int *pDelete, int x, int y, void *data,
			      void *through);

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

QuadTree *qtMakeTree(const DocumentRectangle *dr);

void qtFreeTree(QuadTree *qt, QuadForAllCall freefun, void *through);

int qtFreeData(int x, int y, void *data, void *through);

int qtPut(QuadTree *qt, int x, int y, void *data);

int qtGetExact(QuadTree *qt, int x, int y, void ***const pvals,
		      int *pnval);

int qtGetNearest(QuadTree *qt, int x, int y, const void *data, int *pX,
			int *pY, void *const **pvals, int *pnval);

const char *qtQuadrantStr(int q);
const char *qtOctantStr(int q);

int qtForAllInRectangle(const QuadTree *qt, const DocumentRectangle *dr,
			       QuadForAllCall fun, void *through);

int qtForAll(const QuadTree *qt, QuadForAllFilter filter,
		    QuadForAllCall fun, void *through);

#endif /* GEO_QUAD_TREE_H */
