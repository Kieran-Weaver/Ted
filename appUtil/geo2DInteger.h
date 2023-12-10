/************************************************************************/
/*									*/
/*  Various definitions relating to document geometry.			*/
/*									*/
/************************************************************************/

#ifndef GEO_2D_INTEGER_H
#define GEO_2D_INTEGER_H

struct rect {
	int drX0;
	int drY0;
	int drX1;
	int drY1;
};

#define RECTDEB(dr)                                                          \
	appDebug("%s(%3d) %s= [%d..%d x %d..%d]\n", __FILE__, __LINE__, #dr, \
		 (dr)->drX0, (dr)->drX1, (dr)->drY0, (dr)->drY1)

struct vec2 {
	int x;
	int y;
};

/**
  * A two dimensional arc
  */
typedef struct Arc2DI {
	/**
			  * The rectangle that holds the full ellipse
			  */
	rect a2diRect;
	/**
			 * The start angle relative to the 3-o-clock angle 
			 * in 64th of a degree counter clock wise.
			 */
	int a2diAngleFrom;
	/**
			 * The change of angle relative to a2diAngleFrom 
			 * Also counter clock wise and also in 64th of a degree.
			 */
	int a2diAngleStep;
} Arc2DI;

typedef struct LineSegment2DI {
	int ls2diX0;
	int ls2diY0;
	int ls2diX1;
	int ls2diY1;
} LineSegment2DI;

#define geo2DIXYInBox(x, y, b)                                       \
	((x) >= (b)->drX0 && (x) <= (b)->drX1 && (y) >= (b)->drY0 && \
	 (y) <= (b)->drY1)

#define geo2DIPointInBox(p, b) geo2DIXYInBox((p)->x, (p)->y, (b))

#define geo2DIBoxAroundXY(x, y, b)       \
	{                                \
		if ((b)->drX0 > (x)) {   \
			(b)->drX0 = (x); \
		}                        \
		if ((b)->drY0 > (y)) {   \
			(b)->drY0 = (y); \
		}                        \
		if ((b)->drX1 < (x)) {   \
			(b)->drX1 = (x); \
		}                        \
		if ((b)->drY1 < (y)) {   \
			(b)->drY1 = (y); \
		}                        \
	}

#define geoShiftRectangle(dr, ox, oy) \
	{                             \
		(dr)->drX0 += (ox);   \
		(dr)->drX1 += (ox);   \
		(dr)->drY0 += (oy);   \
		(dr)->drY1 += (oy);   \
	}

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void geoInitRectangle(rect *dr);
void geoInvalidateRectangle(rect *dr);

void geoUnionRectangle(rect *dr,
			      const rect *dr1,
			      const rect *dr2);

void geoNormalizeRectangle(rect *drTo,
				  const rect *drFrom);

int geoIntersectRectangle(rect *dr,
				 const rect *dr1,
				 const rect *dr2);

int geo2DIIntersectSegments(vec2 *p1, vec2 *p2, double *pXab1,
				   double *pXab2, double *pXcd1, double *pXcd2,
				   const vec2 *ab, const vec2 *cd);

double geo2DIDistanceToLine(const vec2 *ab, const vec2 *c);

double geo2DIProjectionOnLine(const vec2 *ab, const vec2 *c);

int geo2DIPointInPolygon(const vec2 *p, const vec2 *points,
				int pointCount);

int geo2DIClipSegmentToRectangle(vec2 vpChanged[2], double *pXp0,
					double *pXp1, const vec2 vp[2],
					const rect *dr);

int geo2DISurface(vec2 *points, int n);

#endif /*	GEO_2D_INTEGER_H */
