/************************************************************************/
/*									*/
/*  Keep a trace of modifications to a document.			*/
/*									*/
/************************************************************************/

#ifndef DOC_RTF_TRACE_H
#define DOC_RTF_TRACE_H

#include <stdio.h>

#include <docBuf.h>
#include <docNoteProperties.h>
#include "docEditOperation.h"
#include "docEditStep.h"
#include "docEditTrace.h"

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int docRtfTraceOldContents(DocumentSelection *ds,
				  const EditOperation *eo, int level,
				  unsigned int flags);

int docRtfTraceOldContentsLow(const EditOperation *eo,
				     const DocumentSelection *ds,
				     unsigned int flags);

int docRtfTraceOldProperties(DocumentSelection *ds, EditOperation *eo,
				    int level, const PropertyMask *taSetMask,
				    const PropertyMask *ppSetMask,
				    const PropertyMask *cpSetMask,
				    const PropertyMask *rpSetMask,
				    const PropertyMask *spSetMask,
				    const PropertyMask *dpSetMask);

int docRtfTraceNewProperties(
	EditOperation *eo,

	const PropertyMask *taSetMask, const TextAttribute *taSet,

	const PropertyMask *ppSetMask, const ParagraphProperties *ppSet,

	const PropertyMask *cpSetMask, const CellProperties *cpSet,

	const PropertyMask *rpSetMask, const RowProperties *rpSet,

	const PropertyMask *spSetMask, const SectionProperties *spSet,

	const PropertyMask *dpSetMask, const DocumentProperties *dpSet);

int docRtfTraceHeaderFooter(EditOperation *eo, const DocumentTree *dt);

int docRtfTraceNewContents(EditOperation *eo, int posWhere);

int docRtfTraceNewPosition(EditOperation *eo,
				  const SelectionScope *ssNew, int posWhere);

int docTraceStartStep(EditOperation *eo, EditTrace *et, int command,
			     int fieldKind);

int docTraceStartReplace(DocumentSelection *dsTraced, EditOperation *eo,
				EditTrace *et, int command, int level,
				unsigned int flags);

int docTraceExtendReplace(EditOperation *eo, EditTrace *et, int command,
				 int level, unsigned int flags);

int docRtfTraceFieldKind(EditOperation *eo, int kind);

int docRtfTraceOldField(EditOperation *eo, const DocumentField *df);
int docRtfTraceNewField(EditOperation *eo, const DocumentField *df);

int docEditReadTraceStep(EditStep *es, int *pIsRepeat, int direction,
				const EditTrace *et, const BufferDocument *bd);

int docRtfTraceCloseTrace(EditOperation *eo, EditTrace *et);

int docRtfTraceOldImageProperties(EditOperation *eo,
					 const PropertyMask *pipSetMask,
					 const PictureProperties *pipSet);

int docRtfTraceNewImageProperties(EditOperation *eo,
					 const PropertyMask *pipSetMask,
					 const PictureProperties *pipSet);

int docRtfTraceOldNoteProperties(EditOperation *eo,
					const PropertyMask *npSetMask,
					const NoteProperties *npSet);

int docRtfTraceNewNoteProperties(EditOperation *eo,
					const PropertyMask *npSetMask,
					const NoteProperties *npSet);

int docRtfTraceOldList(EditOperation *eo, const DocumentList *dl);

int docRtfTraceNewList(EditOperation *eo, const DocumentList *dl);

int docRtfTraceVersion(int command, const MemoryBuffer *filename,
			      const char *digest64, const struct tm *revtim,
			      EditTrace *et);

#endif /*  DOC_RTF_TRACE_H	*/
