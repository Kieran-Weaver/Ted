/************************************************************************/
/*									*/
/*  Implementation of copy/paste related functionality.			*/
/*									*/
/************************************************************************/

#ifndef TED_COPY_PASTE_IMPL_H
#define TED_COPY_PASTE_IMPL_H

#include <docSelectionDescription.h>
#include <docBuf.h>

struct EditDocument;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void tedSaveSelectionTxtToFile(BufferDocument *bd, const char *filename);

void tedSaveSelectionToFile(BufferDocument *bd,
				   const DocumentSelection *ds, int rtfFlags,
				   const char *filename);

int tedDocSaveSelectionRtf(MemoryBuffer *mb, DocumentSelection *ds,
				  SelectionDescription *sd,
				  struct EditDocument *ed);

int tedDocCopySelection(struct EditDocument *ed);

int tedApplyPastedRuler(struct EditDocument *ed, BufferDocument *bdFrom,
			       int traced);

int tedApplyPastedFont(struct EditDocument *ed, BufferDocument *bdFrom,
			      int traced);

void tedCopyFont(struct EditDocument *ed);

void tedCopyRuler(struct EditDocument *ed);

#endif /*  TED_COPY_PASTE_IMPL_H	*/
