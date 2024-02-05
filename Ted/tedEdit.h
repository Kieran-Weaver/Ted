/************************************************************************/
/*									*/
/*  Ted: data structures and routines for on screen interactive		*/
/*  editing.								*/
/*									*/
/************************************************************************/

#ifndef TED_EDIT_H
#define TED_EDIT_H

#include <config.h>
#include <docEdit.h>
#include <docEditTrace.h>
#include <layoutContext.h>
#include <docSelectionGeometry.h>
#include <docSelectionDescription.h>

struct EditDocument;

typedef struct TedEditOperation {
	struct EditDocument *teoEditDocument;
	EditOperation teoEo;
	LayoutContext teoLayoutContext;

	DocumentRectangle teoChangedRect;
	int teoChangedRectSet;
	DocumentRectangle teoOldScreenRectangle;
	int teoRefreshScreenRectangle;

	/**/
	TextAttribute teoSavedTextAttribute;
	int teoSavedTextAttributeNumber;

	/**
				 *   The edit trace. Only set of the 
				 *   edit operation is to be traced.
				 */
	EditTrace *teoEditTrace;
} TedEditOperation;

/************************************************************************/
/*									*/
/*  Routine Declarations:						*/
/*									*/
/************************************************************************/

int tedAdjustParagraphLayout(TedEditOperation *teo, DocumentTree *dt);

int tedStartEditOperation(TedEditOperation *teo, SelectionGeometry *sg,
			  SelectionDescription *sd, struct EditDocument *ed,
			  int fullWidth, int traced);

void tedInitEditOperation(TedEditOperation *teo);
void tedCleanEditOperation(TedEditOperation *teo);

int tedEditFinishSelectionHead(TedEditOperation *teo);
int tedEditFinishSelectionTail(TedEditOperation *teo);
int tedEditFinishSelectionHeadNext(TedEditOperation *teo);

int tedEditFinishSelection(TedEditOperation *teo,
			   const DocumentSelection *dsNew);

int tedEditFinishRange(TedEditOperation *teo, int col0, int col1,
		       const EditRange *erNew);

int tedEditFinishPosition(TedEditOperation *teo, const EditPosition *epNew);

int tedEditFinishOldSelection(TedEditOperation *teo);

int tedEditReplaceSelection(TedEditOperation *teo, const char *addedText,
			    int addedLength, int textAttributeNr);

int tedEditDeleteSelection(TedEditOperation *teo);

int tedEditIncludeNodeInRedraw(TedEditOperation *teo,
			       const struct BufferItem *bi);

int tedEditIncludeRowsInRedraw(TedEditOperation *teo,
			       const struct BufferItem *sectBi, int row0,
			       int row1);

int tedChangeParticuleAttributes(PropertyMask *pTaAllMask,
				 const LayoutContext *lc, struct BufferItem *bi,
				 int partFrom, int partUpto,
				 const TextAttribute *taSet,
				 const PropertyMask *taSetMask);

void tedIncludeRectangleInChange(TedEditOperation *teo,
				 const DocumentRectangle *dr);

int tedDocReplaceSelectionWithField(TedEditOperation *teo, DocumentField **pDf,
				    int *pHeadPart, int *pTailPart,
				    DocumentSelection *dsInside,
				    DocumentSelection *dsAround,
				    const FieldInstructions *fi, int fieldKind,
				    const PropertyMask *taSetMask,
				    const TextAttribute *taSet);

int tedLayoutNodeOfField(TedEditOperation *teo, DocumentSelection *dsAround,
			 unsigned int whenMask);

int tedDocFlattenTypedField(struct EditDocument *ed, int fieldType,
			    const PropertyMask *taSetMask,
			    const TextAttribute *taSet, int traced);

int tedReplaceSelectionWithRasterImage(struct EditDocument *ed, RasterImage *ri,
				       int traced);

int tedIncludeDocument(TedEditOperation *teo, DocumentCopyJob *dcj);

int tedEditIncludeDocument(TedEditOperation *teo, DocumentCopyJob *dcj,
			   int command, int posWhere);

int tedEditInsertSection(DocumentPosition *dpBeforeSplit,
			 DocumentPosition *dpAfterSplit, TedEditOperation *teo,
			 int split, int after);

int tedDeleteSelectionImpl(TedEditOperation *teo);

int tedFlattenFieldImpl(TedEditOperation *teo, DocumentSelection *dsExInside,
			const DocumentSelection *dsAroundField, int headPart,
			int tailPart, DocumentField *df);

int tedEditChangeSelectionProperties(
	TedEditOperation *teo, const DocumentSelection *ds, int level,
	int command,

	const PropertyMask *taSetMask, const TextAttribute *taSet,

	const PropertyMask *ppSetMask, const ParagraphProperties *ppSet,

	const PropertyMask *cpSetMask, const CellProperties *cpSet,

	const PropertyMask *rpSetMask, const RowProperties *rpSet,

	const PropertyMask *spSetMask, const SectionProperties *spSet,

	const PropertyMask *dpSetMask, const DocumentProperties *dpSet);

int tedEditChangeSelectionPropertiesImpl(
	TedEditOperation *teo, const DocumentSelection *ds,

	const PropertyMask *taSetMask, const TextAttribute *taSet,

	const PropertyMask *ppSetMask, const ParagraphProperties *ppSet,

	const PropertyMask *cpSetMask, const CellProperties *cpSet,

	const PropertyMask *rpSetMask, const RowProperties *rpSet,

	const PropertyMask *spSetMask, const SectionProperties *spSet,

	const PropertyMask *dpSetMask, const DocumentProperties *dpSet);

int tedObjectSetImagePropertiesImpl(TedEditOperation *teo, InsertedObject *io,
				    const DocumentPosition *dpObj, int partObj,
				    const PropertyMask *pipSetMask,
				    const PictureProperties *pipSet);

int tedChangeNoteImpl(EditOperation *eo, DocumentField *dfNote,
		      struct DocumentNote *dn, int selInNote,
		      const PropertyMask *npSetMask,
		      const struct NoteProperties *npSet);

int tedDocRollRowsInTableImpl(TedEditOperation *teo, const TableRectangle *tr,
			      int move, int rowsdown);

int tedDocUpdField(TedEditOperation *teo, DocumentField *df,
		   const FieldInstructions *fi);

int tedDocSetField(TedEditOperation *teo, const DocumentSelection *ds,
		   int command, int fieldKind, const FieldInstructions *fi,
		   const PropertyMask *taSetMask, const TextAttribute *taSet);

int tedMergeParagraphsInSelection(struct EditDocument *ed, int traced);

int tedEditShiftRowsInTable(struct EditDocument *ed, int direction, int traced);

int tedRefreshTocField(DocumentSelection *dsAroundToc, TedEditOperation *teo,
		       DocumentField *dfToc);

int tedDeleteTableSliceSelection(struct EditDocument *ed, int traced);

int tedDocReplaceSelection(struct EditDocument *ed, int command,
			   const char *word, int len, int traced);

int tedDocReplaceSelectionTyping(struct EditDocument *ed, const char *str,
				 int length);

int tedDocDeleteSelection(struct EditDocument *ed, int command, int traced);

int tedObjectSetImageProperties(struct EditDocument *ed, InsertedObject *io,
				const DocumentPosition *dpObject,
				int partObject, const PropertyMask *pipSetMask,
				const PictureProperties *pipFrom, int traced);

int tedInsertTable(struct EditDocument *ed, int rows, int columns, int traced);

int tedEditStartReplace(DocumentSelection *dsTraced, TedEditOperation *teo,
			int command, int level, unsigned int flags);

int tedEditStartStep(TedEditOperation *teo, int command);
int tedEditStartTypedStep(TedEditOperation *teo, int command, int fieldKind);

int tedFinishEditOperation(TedEditOperation *teo);

void tedDocInsertStringWithAttribute(struct EditDocument *ed, const char *bytes,
				     int size, const TextAttribute *taSet,
				     const PropertyMask *taSetMask, int traced);

void tedEditInsertSpecialParticule(struct EditDocument *ed, int kind,
				   int command, int redoLayout, int traced);

int tedInsertPageNumber(struct EditDocument *ed, int traced);

int tedIncludePlainDocument(struct EditDocument *ed, BufferDocument *bdFrom,
			    int traced);

int tedIncludeRtfDocument(struct EditDocument *ed, BufferDocument *bdFrom,
			  int traced);

#endif /*	TED_EDIT_H	*/
