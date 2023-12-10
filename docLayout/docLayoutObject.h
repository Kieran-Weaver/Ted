/************************************************************************/
/*									*/
/*  Set the player for an object.					*/
/*									*/
/************************************************************************/

#ifndef DOC_LAYOUT_OBJECT_H
#define DOC_LAYOUT_OBJECT_H

#include <docBuf.h>

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int docGetBitmapForObject(InsertedObject *io);

int docCheckObjectLayout(int *pFixed, InsertedObject *io);

int docGetBitmapForObjectData(int kind, RasterImage *ri,
				     const MemoryBuffer *mb);

void
docLayoutScaleObjectToFitParagraphFrame(int *pChanged, InsertedObject *io,
					int pageHigh,
					const DocumentRectangle *drParaFrame);

void docScaleObjectToParagraph(BufferDocument *bd,
				      struct BufferItem *paraBi, double xfac,
				      InsertedObject *io);

#endif /*	DOC_LAYOUT_OBJECT_H	*/
