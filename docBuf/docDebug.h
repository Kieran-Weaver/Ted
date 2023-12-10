/************************************************************************/
/*									*/
/*  Text buffer: Diagnostic routines.					*/
/*									*/
/************************************************************************/

#ifndef DOC_DEBUG_H
#define DOC_DEBUG_H

#include "docBuf.h"

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void docCheckFieldOffsets(const BufferDocument *bd,
				 const struct BufferItem *bi);

int docCheckNode(const struct BufferItem *bi, int checkGeometry);
int docCheckRootNode(const struct BufferItem *bi, int checkGeometry);

void docListFieldParticule(int indent, const char *label, int n,
				  const struct BufferItem *bi,
				  const struct TextParticule *tp,
				  const DocumentField *df);

void docListFieldTree(const BufferDocument *bd, const DocumentTree *dt);

void docScanNotesOfDocument(const BufferDocument *bd);

void docListFields(const ChildFields *cf, const BufferDocument *bd);

void docListFontList(const DocumentFontList *dfl);

void docLogRectangle(const char *label, const DocumentRectangle *dr);

void docLogRectangles(const char *label1, const DocumentRectangle *dr1,
			     const char *label2, const DocumentRectangle *dr2);

void docListNode(int indent, const struct BufferItem *bi,
			int checkGeometry);

void docListRootNode(int indent, const struct BufferItem *bi,
			    int checkGeometry);

void docListParticule(int indent, const char *label, int n,
			     const struct BufferItem *bi,
			     const struct TextParticule *tp);

void docListTextLine(int indent, const char *label, int n,
			    const struct BufferItem *bi,
			    const struct TextLine *tl);

void docListObjects(BufferDocument *bd);

void docListNotes(const BufferDocument *bd);

void docListShapes(BufferDocument *bd);
void docListDocumentObjects(BufferDocument *bd);

void docListField(int indent, const DocumentField *df);

#endif
