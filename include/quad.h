#ifndef QUADTREE_H
#define QUADTREE_H

/************************************************************************/
/*  Quad Tree basic definitions.					*/
/************************************************************************/

typedef struct qn_s {
	int qn_x;
	int qn_y;
	struct qn_s *qn_parent;
	struct qn_s *qn_nw;
	struct qn_s *qn_ne;
	struct qn_s *qn_sw;
	struct qn_s *qn_se;

	int qn_nval;
	void **qn_vals;
} QuadNode;

typedef struct qt_s {
	QuadNode *qt_root;
	int qt_x0;
	int qt_x1;
	int qt_y0;
	int qt_y1;
} QuadTree;

QuadTree *qtmake(int x0, int x1, int y0, int y1);
int qtput(QuadTree *qt, int x, int y, void *data);
int qtget(QuadTree *qt, int x, int y, void **pvals, int *pnval);
int qtall(QuadTree *qt, int x0, int x1, int y0, int y1,
	  int (*fun)(void *, void *), void *);
void qtclose(QuadTree *qt);

#endif
