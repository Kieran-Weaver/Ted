/************************************************************************/
/*									*/
/*  Bookkeeping for HYPERLINK fields.					*/
/*									*/
/************************************************************************/

#ifndef DOC_HYPERLINK_FIELD_H
#define DOC_HYPERLINK_FIELD_H

#include <utilMemoryBuffer.h>
#include "docFieldInstructions.h"

struct DocumentField;

typedef struct HyperlinkField {
	MemoryBuffer hfFile;
	MemoryBuffer hfBookmark;
	MemoryBuffer hfFont;
} HyperlinkField;

/************************************************************************/
/*									*/
/*  Administrative routines.						*/
/*									*/
/************************************************************************/

void docInitHyperlinkField(HyperlinkField *hf);
void docCleanHyperlinkField(HyperlinkField *hf);

int docGetHyperlinkField(HyperlinkField *hf, const struct DocumentField *df);

int docMakeHyperlinkRelative(struct DocumentField *dfTo,
			     const MemoryBuffer *refFileName);

int docSetHyperlinkField(FieldInstructions *fi, const HyperlinkField *hf);

int docHyperlinkFieldIsLink(const HyperlinkField *hf);
int docHyperlinkFieldIsExtern(const HyperlinkField *hf);

int docEqualHyperlinkFields(const HyperlinkField *hf1,
			    const HyperlinkField *hf2);

int docCopyHyperlinkField(HyperlinkField *to, const HyperlinkField *from);

#endif /*  DOC_HYPERLINK_FIELD_H  */
