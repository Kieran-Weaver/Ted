/************************************************************************/
/*									*/
/*  Bookkeeping for BOOKMARK fields.					*/
/*									*/
/************************************************************************/

#ifndef DOC_BOOKMARK_FIELD_H
#define DOC_BOOKMARK_FIELD_H

#define DOCmaxBOOKMARK 40

#include <utilMemoryBuffer.h>

struct DocumentField;
struct MemoryBuffer;
struct FieldInstructions;

/************************************************************************/
/*									*/
/*  Administrative routines.						*/
/*									*/
/************************************************************************/

int docFieldGetBookmark(const MemoryBuffer **markName,
			       const struct DocumentField *df);

int docIsTocBookmark(long *pId, const struct DocumentField *df);

int docFieldMatchesBookmark(const struct DocumentField *df,
				   const MemoryBuffer *markName);

int docSetBookmarkField(struct FieldInstructions *fi,
			       const struct MemoryBuffer *mb);

int docAdaptBookmarkName(struct MemoryBuffer *markName);

int docBookmarkFromText(struct MemoryBuffer *markName, const char *text,
			       int len);

int docBookmarkSuffixIndex(const struct MemoryBuffer *markName,
				  int wanted);

#endif /*  DOC_BOOKMARK_FIELD_H  */
