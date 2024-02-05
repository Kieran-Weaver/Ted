/************************************************************************/
/*									*/
/*  Manage a lookup to keep track of numbered structs with object	*/
/*  properties.								*/
/*									*/
/************************************************************************/

#ifndef UTIL_NUMBERED_PROPERTIES_ADMIN_H
#define UTIL_NUMBERED_PROPERTIES_ADMIN_H

#include "utilIntegerValueNode.h"
#include "utilPagedList.h"

typedef void (*NumberedPropertiesFunction)(const void *vpr, int n,
					   void *through);

typedef int (*NumberedPropertiesGetProperty)(const void *vpr, int prop);

typedef struct NumberedPropertiesList {
	PagedList nplPagedList;
	IntegerValueNode nplValueNodes;
	int nplPropCount;
	NumberedPropertiesGetProperty nplGetProperty;
} NumberedPropertiesList;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void utilInitNumberedPropertiesList(NumberedPropertiesList *npl);

void utilCleanNumberedPropertiesList(NumberedPropertiesList *npl);

void utilForAllNumberedProperties(const NumberedPropertiesList *npl,
				  NumberedPropertiesFunction f, void *through);

void utilStartNumberedPropertyList(NumberedPropertiesList *npl, int propCount,
				   NumberedPropertiesGetProperty getProp,
				   int sizeofItem, InitPagedListItem initItem,
				   CleanPagedListItem cleanItem);

int utilGetPropertyNumber(NumberedPropertiesList *npl, int make,
			  const void *vob);

#endif /*  UTIL_NUMBERED_PROPERTIES_ADMIN_H	*/
