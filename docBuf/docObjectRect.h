/************************************************************************/
/*									*/
/*  Document Layout and Printing related functionality.			*/
/*									*/
/************************************************************************/

#ifndef DOC_OBJECT_RECT_H
#define DOC_OBJECT_RECT_H

#include "docBuf.h"

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void docObjectGetPageRect(rect *drDest,
				 const InsertedObject *io, int x0Twips,
				 int baselineTwips);

void docObjectGetSourceRect(rect *drSrc,
				   const PictureProperties *pip);

#endif /*  DOC_OBJECT_RECT_H  */
