/************************************************************************/
/*									*/
/*  Geometry Specification strings.					*/
/*									*/
/************************************************************************/

#ifndef GEO_STRING_H
#define GEO_STRING_H

void geoLengthToString(char *target, int twips, int unitInt);

void geoRectangleToString(char *target, int widthTwips, int heightTwips,
				 int unitInt);

int geoRectangleFromString(const char *s, int defaultUnitInt,
				  int *pWidth, int *pHeight);

int geoLengthFromString(const char *s, int defaultUnitInt, int *pValue);

#endif /* GEO_STRING_H */
