/************************************************************************/
/*									*/
/*  Document Editing: Copying over (part of) a document to the same	*/
/*  document or another one.						*/
/*									*/
/************************************************************************/

#ifndef DOC_DOCUMENT_COPY_JOB_H
#define DOC_DOCUMENT_COPY_JOB_H

#include <docBuf.h>
#include "docEditOperation.h"
#include <docDocumentAttributeMap.h>

/************************************************************************/
/*									*/
/*  For copying information from one location to another. Possibly	*/
/*  between different documents.					*/
/*									*/
/************************************************************************/

typedef struct FieldCopyStackLevel {
	DocumentField *fcslField;
	struct FieldCopyStackLevel *fcslPrev;
} FieldCopyStackLevel;

typedef struct DocumentCopyJob {
	EditOperation *dcjEditOperation;
	SelectionScope dcjTargetSelectionScope;

	DocumentTree *dcjTargetTree;
	BufferDocument *dcjSourceDocument;
	DocumentTree *dcjSourceTree;
	/**
				     *  Are we in an excursion to an 
				     *  external tree?
				     */
	int dcjInExternalTree;

	int dcjCopyFields;
	int *dcjFieldMap;
	FieldCopyStackLevel *dcjFieldStack;

	DocumentAttributeMap dcjAttributeMap;
	int dcjForceAttributeTo;

	/**
				     *  The file name that we paste to.
				     *  This is to avoid that hyperlinks 
				     *  within the document become absolute.
				     */
	MemoryBuffer dcjRefFileName;

	int dcjCurrentTextAttributeNumberFrom;
	int dcjCurrentTextAttributeNumberTo;

	IndexSet dcjNoteFieldsCopied;
	int dcjBulletsCopied;

	/**
				 *  Transfer the paragraph properties of the 
				 *  first paragraph of the source to the target?
				 *  [Only relevant with multi-paragraph inserts]
				 */
	unsigned char dcjCopyHeadParaProperties;
	/**
				 *  Transfer the paragraph properties of the 
				 *  last paragraph of the source to the target?
				 *  [Only relevant with multi-paragraph inserts]
				 */
	unsigned char dcjCopyTailParaProperties;
} DocumentCopyJob;

/************************************************************************/
/*									*/
/*  Routine Declarations.						*/
/*									*/
/************************************************************************/

int docMapTextAttributeNumber(DocumentCopyJob *dcj,
				     int attributeNumberFrom);

int docMapTextAttributeNumberFromTo(BufferDocument *bdTo,
					   const BufferDocument *bdFrom,
					   int attributeNumberFrom);

void docInitDocumentCopyJob(DocumentCopyJob *dcj);
void docCleanDocumentCopyJob(DocumentCopyJob *dcj);

int docSet1DocumentCopyJob(DocumentCopyJob *dcj, EditOperation *eo,
				  int copyFields);

int docSetTraceDocumentCopyJob(DocumentCopyJob *dcj, EditOperation *eo,
				      BufferDocument *bdFrom);

int docSet2DocumentCopyJob(DocumentCopyJob *dcj, EditOperation *eo,
				  BufferDocument *bdFrom, DocumentTree *eiFrom,
				  const MemoryBuffer *refFileName,
				  int forceAttributeTo);

int docPushFieldOnCopyStack(DocumentCopyJob *dcj, DocumentField *df);

void docMapTextAttribute(TextAttribute *taTo,
				const TextAttribute *taFrom,
				const DocumentCopyJob *dcj);

#endif /*	DOC_DOCUMENT_COPY_JOB_H	*/
