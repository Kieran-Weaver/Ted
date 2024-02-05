/************************************************************************/
/*									*/
/*  Fields: parts of the document that are calculated in stead of typed	*/
/*  by the user.							*/
/*									*/
/************************************************************************/

#ifndef DOC_DOCUMENT_FIELD_H
#define DOC_DOCUMENT_FIELD_H

#include <utilMemoryBuffer.h>
#include "docFieldInstructions.h"
#include "docSelectionScope.h"
#include "docEditRange.h"

typedef enum FieldKind {
	DOCfkUNKNOWN = 0,
	DOCfkHYPERLINK,
	DOCfkXE,
	DOCfkTC,
	DOCfkTCN,
	DOCfkBOOKMARK,
	DOCfkSEQ,
	DOCfkSECTION,
	DOCfkSECTIONPAGES,
	DOCfkPAGE,
	DOCfkPAGEREF,
	DOCfkNUMPAGES,
	DOCfkREF,

	DOCfkCREATEDATE,
	DOCfkSAVEDATE,
	DOCfkPRINTDATE,
	DOCfkDATE,
	DOCfkTIME,

	DOCfkAUTHOR,
	DOCfkCOMMENTS,
	DOCfkDOCCOMM,
	DOCfkKEYWORDS,
	DOCfkSUBJECT,
	DOCfkTITLE,
	DOCfkFILENAME,

	DOCfkMERGEFIELD,
	DOCfkFORMTEXT,
	DOCfkFORMCHECKBOX,

	/**
	      *  A note reference in the body of the document, or the 
	      *  note number at the head of the note.
	      */
	DOCfkCHFTN,
	/**
	      *  An annotation reference in the document. Only partially 
	      *  implemented. (MdD May 2010)
	      */
	DOCfkCHATN,

	/**
	      *  The bullet or number at the head of a numbered paragraph
	      *  that is calculated programmatically.
	      */
	DOCfkLISTTEXT,

	DOCfkINCLUDEPICTURE,

	DOCfkTOC,

	DOCfk_COUNT
} FieldKind;

/**
      *  Field type that potentially has a note.
      */
#define docFieldHasNote(t) ((t) == DOCfkCHFTN || (t) == DOCfkCHATN)

struct DocumentField;

typedef struct ChildFields {
	struct DocumentField **cfChildren;
	int cfChildCount;
} ChildFields;

typedef struct DocumentField {
	unsigned char dfKind;
	MemoryBuffer dfData;
	/**
				  *  The instructions of the field.
				  */
	FieldInstructions dfInstructions;

	/**
				  *  The tree in the document that owns the 
				  *  field. For (BODY) fields that span 
				  *  sections, the section number is that of 
				  *  the head position of the field.
				  */
	SelectionScope dfSelectionScope;
	/**
				  *  The position of the head particule of 
				  *  the field.
				  */
	EditPosition dfHeadPosition;
	/**
				  *  The position of the tail particule of 
				  *  the field.
				  */
	EditPosition dfTailPosition;
	/*
				 * If a field spans part of a table,
				 * these can be used to give the first/last 
				 * column covered by the field. Is only 
				 * used for bookmarks.
				 */
	short dfFirstColumn;
	short dfLastColumn;
	/*
				 * Flags that reflect the status of the 
				 * field content.
				 */
	unsigned char dfDirty;
	unsigned char dfEdited;
	unsigned char dfLocked;
	unsigned char dfPrivate;
	/********************************/
	/*  Fields have a hierarchy.	*/
	/********************************/
	ChildFields dfChildFields;
	struct DocumentField *dfParent;
	int dfNumberInParent;
	/**
				 * The index of the field.
				 * ABUSED to keep a linked list of free fields
				 */
	int dfFieldNumber;
	/**
				 *  Reference to the note of a chftn field.
				 *
				 *  ABUSED to remember the sequence number
				 *  of a SEQ field. [In that case, it counts 
				 *  from 1.]
				 */
	int dfNoteIndex;
	/**
				 * Make it possible to refer
				 * the page number of a field.
				 */
	int dfPage;
} DocumentField;

typedef enum FieldProperty {
	FPpropFIRST_COLUMN = 0,
	FPpropLAST_COLUMN,
	FPpropDIRTY,
	FPpropEDITED,
	FPpropLOCKED,
	FPpropPRIVATE,

	FPpropFLDRSLT,
	FPpropFLDINST,

	FPprop_COUNT
} FieldProperty;

#define docGetBodySectNrOfField(df)                       \
	((df)->dfSelectionScope.ssTreeType == DOCinBODY ? \
		 (df)->dfSelectionScope.ssSectNr :        \
		 (df)->dfSelectionScope.ssOwnerSectNr)

#define docEditPositionInField(df, ep)                                  \
	(docCompareEditPositions(&((df)->dfHeadPosition), (ep)) <= 0 && \
	 docCompareEditPositions(&((df)->dfTailPosition), (ep)) >= 0)

/************************************************************************/
/*									*/
/*  Administrative routines.						*/
/*									*/
/************************************************************************/

DocumentField *docGetFirstField(const ChildFields *rootFields);
DocumentField *docGetLastField(const ChildFields *rootFields);

DocumentField *docGetNextField(const ChildFields *rootFields,
			       DocumentField *df);

DocumentField *docGetPrevField(const ChildFields *rootFields,
			       DocumentField *df);

DocumentField *docGetFirstFieldOfSection(const ChildFields *rootFields,
					 int sect);

DocumentField *docGetNextFieldInSection(const ChildFields *rootFields, int sect,
					DocumentField *df);

void docInitDocumentField(DocumentField *df);
void docInitChildFields(ChildFields *cf);
void docCleanChildFields(ChildFields *cf);

void docCleanDocumentField(DocumentField *df);

int docSetFieldInst(DocumentField *df, const char *bytes, int size);

int docAddToFieldData(DocumentField *df, const char *bytes, int size);

int docFieldGetTc(const DocumentField *df, char *pFlag, int *pLevel,
		  int *pNumbered);

int docInsertChildField(DocumentField *parent, ChildFields *cf,
			DocumentField *df);

int docDeleteChildField(ChildFields *cf, DocumentField *df);

DocumentField *docFindChildField(const ChildFields *cf, const EditPosition *ep,
				 int lastOne);

DocumentField *docFindTypedChildField(const ChildFields *cf,
				      const EditPosition *ep, int type);

void docSetFieldTail(DocumentField *dfPa, const EditPosition *epTail);

int docAddChildToField(DocumentField *dfCh, DocumentField *dfPa);

int docInsertFieldInTree(ChildFields *cf, DocumentField *df);

DocumentField *docFieldGetCommonParent(DocumentField *dfLeft,
				       DocumentField *dfRight);

int docFieldFormatInteger(MemoryBuffer *mbResult, int format, int value);

int docCopyFieldProperties(DocumentField *dfTo, const DocumentField *dfFrom);

int docSetFieldProperty(DocumentField *df, int prop, int val);

int docAllocateInstructionComponents(DocumentField *df, int n);

DocumentField *docFindFieldInRange(const EditRange *er, const ChildFields *cf,
				   int lastOne, int kind);

#endif /*  DOC_DOCUMENT_FIELD_H  */
