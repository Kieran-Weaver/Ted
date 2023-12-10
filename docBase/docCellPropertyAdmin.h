/************************************************************************/
/*									*/
/*  Manage a lookup to keep track of cell properties.			*/
/*									*/
/************************************************************************/

#ifndef DOC_CELL_PROPERTY_ADMIN_H
#define DOC_CELL_PROPERTY_ADMIN_H

#include "docCellProperties.h"
#include <utilIntegerValueNode.h>
#include <utilNumberedPropertiesAdmin.h>

typedef void (*CellPropertiesFunction)(const CellProperties *cp, int n,
				       void *through);

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void docInitCellPropertyList(NumberedPropertiesList *cpl);

int docCellPropertiesNumber(NumberedPropertiesList *cpl,
				   const CellProperties *cp);

void docForAllCellProperties(const NumberedPropertiesList *cpl,
				    CellPropertiesFunction f, void *through);

void docGetCellPropertiesByNumber(CellProperties *cp,
					 const NumberedPropertiesList *cpl,
					 int n);

int docMergeCellPropertiesLists(int **pCellMap, const int *borderMap,
				       const int *shadingMap,
				       NumberedPropertiesList *cplTo,
				       const NumberedPropertiesList *cplFrom);

#endif /*  DOC_CELL_PROPERTY_ADMIN_H	*/
