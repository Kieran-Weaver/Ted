/************************************************************************/
/*									*/
/*  Manage a lookup to keep track of text attributes.			*/
/*									*/
/************************************************************************/

#ifndef UTIL_TEXT_ATTRIBUTE_ADMIN_H
#define UTIL_TEXT_ATTRIBUTE_ADMIN_H

#include "textAttribute.h"
#include <utilNumberedPropertiesAdmin.h>

typedef int (*TextAttributeFunction)(int n, const TextAttribute *ta,
				     void *through);

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void utilInitTextAttributeList(NumberedPropertiesList *tal);

int utilTextAttributeNumber(NumberedPropertiesList *tal,
			    const TextAttribute *ta);

void utilGetTextAttributeByNumber(TextAttribute *ta,
				  const NumberedPropertiesList *tal, int n);

int textForAllAttributesInList(const NumberedPropertiesList *tal,
			       const IndexSet *filter, TextAttributeFunction f,
			       void *through);

#endif /*  UTIL_TEXT_ATTRIBUTE_ADMIN_H	*/
