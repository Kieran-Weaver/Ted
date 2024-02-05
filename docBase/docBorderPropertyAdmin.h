/************************************************************************/
/*									*/
/*  Manage a lookup to keep track of border properties.			*/
/*									*/
/************************************************************************/

#ifndef DOC_BORDER_PROPERTY_ADMIN_H
#define DOC_BORDER_PROPERTY_ADMIN_H

#include "docBorderProperties.h"
#include <utilIntegerValueNode.h>
#include <utilNumberedPropertiesAdmin.h>
typedef void (*BorderPropertiesFunction)(const BorderProperties *bp, int n,
					 void *through);

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void docInitBorderPropertyList(NumberedPropertiesList *bpl);

int docBorderPropertiesNumberImpl(NumberedPropertiesList *bpl,
				  const BorderProperties *bp);

void docForAllBorderProperties(const NumberedPropertiesList *bpl,
			       BorderPropertiesFunction f, void *through);

void docGetBorderPropertiesByNumberImpl(BorderProperties *bp,
					const NumberedPropertiesList *bpl,
					int n);

int docBorderNumberIsBorderImpl(const NumberedPropertiesList *bpl, int n);

int docMergeBorderPropertiesLists(int **pBorderMap, const int *colorMap,
				  NumberedPropertiesList *bplTo,
				  const NumberedPropertiesList *bplFrom);

#endif /*  DOC_BORDER_PROPERTY_ADMIN_H	*/
