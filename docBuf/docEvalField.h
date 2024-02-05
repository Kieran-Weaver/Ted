/************************************************************************/
/*									*/
/*  Declare field evaluation routines.					*/
/*									*/
/************************************************************************/

#ifndef DOC_EVAL_FIELD_H
#define DOC_EVAL_FIELD_H

#include "docBuf.h"
#include "docNoteProperties.h"

struct BufferItem;
struct DocumentField;
struct RecalculateFields;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int docCalculateChftnFieldString(int *pCalculated, MemoryBuffer *mbResult,
				 const struct DocumentField *df,
				 const struct RecalculateFields *rf);

int docCalculateSymbolFieldString(int *pCalculated, MemoryBuffer *mbResult,
				  const struct DocumentField *df,
				  const struct RecalculateFields *rf);

int docCalculatePagerefFieldString(int *pCalculated, MemoryBuffer *mbResult,
				   const struct DocumentField *df,
				   const struct RecalculateFields *rf);

int docCalculateSectionFieldString(int *pCalculated, MemoryBuffer *mbResult,
				   const struct DocumentField *df,
				   const struct RecalculateFields *rf);

int docCalculateSeqFieldString(int *pCalculated, MemoryBuffer *mbResult,
			       const struct DocumentField *df,
			       const struct RecalculateFields *rf);

int docCalculateSectionPagesFieldString(int *pCalculated,
					MemoryBuffer *mbResult,
					const struct DocumentField *df,
					const struct RecalculateFields *rf);

int docCalculatePageFieldString(int *pCalculated, MemoryBuffer *mbResult,
				const struct DocumentField *df,
				const struct RecalculateFields *rf);

int docCalculateNumpagesFieldString(int *pCalculated, MemoryBuffer *mbResult,
				    const struct DocumentField *df,
				    const struct RecalculateFields *rf);

int docCalculateDocDateFieldString(int *pCalculated, MemoryBuffer *mbResult,
				   const struct DocumentField *df,
				   const struct RecalculateFields *rf);

int docCalculateDocStringFieldString(int *pCalculated, MemoryBuffer *mbResult,
				     const struct DocumentField *df,
				     const struct RecalculateFields *rf);

int docCalculateFilenameFieldString(int *pCalculated, MemoryBuffer *mbResult,
				    const struct DocumentField *df,
				    const struct RecalculateFields *rf);

int docCalculateRefFieldString(int *pCalculated, MemoryBuffer *mbResult,
			       const struct DocumentField *df,
			       const struct RecalculateFields *rf);

int docRecalculateHyperlinkField(int *pCalculated, int *pPartShift,
				 int *pStroffShift, struct BufferItem *paraNode,
				 int part, int partCount,
				 struct DocumentField *df,
				 const struct RecalculateFields *rf);

int docRecalculateMergeField(int *pCalculated, int *pPartShift,
			     int *pStroffShift, struct BufferItem *paraNode,
			     int part, int partCount, struct DocumentField *df,
			     const struct RecalculateFields *rf);

int docRecalculateIncludePictureField(int *pCalculated, int *pPartShift,
				      int *pStroffShift,
				      struct BufferItem *paraNode, int part,
				      int partCount, struct DocumentField *df,
				      const struct RecalculateFields *rf);

int docRecalculateParaStringTextParticules(int *pCalculated, int *pPartShift,
					   int *pStroffShift,
					   struct BufferItem *paraNode,
					   int part, int partCount,
					   struct DocumentField *df,
					   const struct RecalculateFields *rf);

int docRecalculateParaChftnTextParticules(int *pCalculated, int *pPartShift,
					  int *pStroffShift,
					  struct BufferItem *paraNode, int part,
					  int partCount,
					  struct DocumentField *df,
					  const struct RecalculateFields *rf);

int docRecalculateParaListtextTextParticules(
	int *pCalculated, int *pPartShift, int *pStroffShift,
	struct BufferItem *paraNode, int part, int partCount,
	struct DocumentField *df, const struct RecalculateFields *rf);

int docRecalculateParaSymbolTextParticules(int *pCalculated, int *pPartShift,
					   int *pStroffShift,
					   struct BufferItem *paraNode,
					   int part, int partCount,
					   struct DocumentField *df,
					   const struct RecalculateFields *rf);

int docCalculateRefFieldValue(MemoryBuffer *mbResult,
			      const MemoryBuffer *markName,
			      const struct BufferDocument *bd);

int docFormatChftnField(MemoryBuffer *mbResult,
			const FootEndNotesProperties *fep,
			const NoteProperties *np, int noteNumber);

#endif /*  DOC_EVAL_FIELD_H  */
