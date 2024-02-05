/************************************************************************/
/*									*/
/*  Manage a lookup to keep track of text attributes.			*/
/*									*/
/************************************************************************/

#ifndef DOC_FRAME_PROPERTY_ADMIN_H
#define DOC_FRAME_PROPERTY_ADMIN_H

#include "docFrameProperties.h"
#include <utilIntegerValueNode.h>
#include <utilNumberedPropertiesAdmin.h>
typedef void (*FramePropertiesFunction)(const FrameProperties *fp, int n,
					void *through);

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void docInitFramePropertyList(NumberedPropertiesList *fpl);

int docFramePropertiesNumberImpl(NumberedPropertiesList *fpl,
				 const FrameProperties *fp);

void docForAllFrameProperties(const NumberedPropertiesList *fpl,
			      FramePropertiesFunction f, void *through);

void docGetFramePropertiesByNumberImpl(FrameProperties *fp,
				       const NumberedPropertiesList *fpl,
				       int n);

int docFrameNumberIsFrameImpl(const NumberedPropertiesList *fpl, int n);

int docMergeFramePropertyLists(int **pFrameMap, NumberedPropertiesList *fplTo,
			       const NumberedPropertiesList *fplFrom);

#endif /*  DOC_FRAME_PROPERTY_ADMIN_H	*/
