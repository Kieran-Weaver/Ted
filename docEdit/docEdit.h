/************************************************************************/
/*									*/
/*  Document Editing.							*/
/*									*/
/************************************************************************/

#ifndef DOC_EDIT_H
#define DOC_EDIT_H

#include <docBuf.h>
#include <docDebug.h>
#include "docEditOperation.h"
#include "docDocumentCopyJob.h"

/************************************************************************/
/*									*/
/*  Routine Declarations.						*/
/*									*/
/************************************************************************/

int docRollNodeChildren(EditOperation *eo, struct BufferItem *parentBi,
			int from, int to, int by);

int docEditDeleteReplacedFields(EditOperation *eo);

int docParaReplaceText(EditOperation *eo, int paraNr, DocumentPosition *dpTail,
		       const DocumentPosition *dpHead, unsigned int stroffTail,
		       const char *addedText, unsigned int addedLength,
		       int addedAttributeNumber);

int docParaDeleteText(EditOperation *eo, int paraNr, DocumentPosition *dpTail,
		      const DocumentPosition *dpHead, unsigned int stroffTail);

int docParaInsertTail(DocumentCopyJob *dcj, int paraNrTo,
		      DocumentPosition *dpTail, const DocumentPosition *dpTo,
		      const DocumentPosition *dpFrom);

int docSplitParaNode(struct BufferItem **pNewParaBi, EditOperation *eo,
		     int splitLevel);

int docEditSplitParaParent(EditOperation *eo, struct BufferItem **pBeforeNode,
			   struct BufferItem **pAfterNode,
			   struct BufferItem *paraNode, int after,
			   int splitLevel);

int docRemoveSelectionTail(EditOperation *eo);

void docDeleteEmptyParents(EditOperation *eo, int *pSectsDeleted,
			   struct BufferItem *bi);

void docEditDeleteNodes(EditOperation *eo, int *pSectionsDeleted,
			int *pFirstParaDeleted, int *pParagraphsDeleted,
			struct BufferItem *bi, int first, int count);

struct TextParticule *docEditParaSpecialParticule(EditOperation *eo, int kind);

int docReplaceSelection(EditOperation *eo, const char *addedText,
			int addedLength, int addedAttributeNumber);

int docDeleteSelection(EditOperation *eo);

int docMergeParagraphsInSelection(EditOperation *eo);

int docInsertTableRows(DocumentSelection *dsRows, EditOperation *eo,
		       struct BufferItem *sectBi,
		       const struct BufferItem *refRowBi,
		       const RowProperties *rp, int textAttributeNumber, int n,
		       int paraNr, int rows);

int docSplitColumnInRows(struct BufferItem **pNewParaBi, EditOperation *eo,
			 struct BufferItem *sectBi, int row0, int row, int row1,
			 int col, int after);

int docDeleteColumnsFromRows(EditOperation *eo, struct BufferItem *sectBi,
			     int delRow0, int delRow1, int delCol0,
			     int delCol1);

void docEditShiftReferences(EditOperation *eo, const SelectionScope *ssRoot,
			    int paraFrom, int stroffFrom, int sectShift,
			    int paraShift, int stroffShift);

void docEditAvoidDeletedParagraphs(EditOperation *eo,
				   const SelectionScope *ssRoot, int paraFrom,
				   int paraUpto);

int docEditUpdParaProperties(EditOperation *eo, PropertyMask *pPpDonePask,
			     struct BufferItem *paraNode,
			     const PropertyMask *ppSetMask,
			     const ParagraphProperties *ppNew,
			     const DocumentAttributeMap *dam);

int docEditUpdSectProperties(EditOperation *eo, PropertyMask *pSpDonePask,
			     struct BufferItem *sectNode,
			     const PropertyMask *spSetMask,
			     const SectionProperties *spNew,
			     const DocumentAttributeMap *dam);

int docEditShiftParticuleOffsets(EditOperation *eo, struct BufferItem *paraBi,
				 int paraNr, int partFrom, int partUpto,
				 int stroffFrom, int stroffShift);

int docEditCleanParticules(EditOperation *eo, struct BufferItem *paraBi,
			   int partFrom, int partUpto);

int docCheckNoBreakAsLast(EditOperation *eo, struct BufferItem *paraBi);

void docEditAdaptRowPropertiesToFirstChild(EditOperation *eo,
					   const struct BufferItem *paraBi);

int docEditFixParaBreakKind(EditOperation *eo, DocumentTree *dt,
			    BufferDocument *bd, int paraNr);

int docIncludeDocument(DocumentCopyJob *dcj);

int docSectionParagraph(EditOperation *eo, struct BufferItem **pParaBi,
			struct BufferItem *sectBi, int sectShift,
			const ParagraphProperties *pp, int textAttributeNumber);

int docEditDeleteFieldsForBlockDelete(EditOperation *eo,
				      const DocumentSelection *ds);

int docDeleteFieldsInRange(EditOperation *eo, DocumentSelection *dsBalanced);

int docEditSurroundTextSelectionByField(
	EditOperation *eo, DocumentField **pDf, DocumentSelection *dsInside,
	DocumentSelection *dsAround, int *pHeadPart, int *pTailPart,
	const PropertyMask *taSetMask, const TextAttribute *taSet,
	int fieldKind, const FieldInstructions *fi);

int docChangeSelectionProperties(
	EditOperation *eo, const DocumentSelection *ds,

	PropertyMask *selTaChgMask, const PropertyMask *taSetMask,
	const TextAttribute *taSet,

	PropertyMask *selPpChgMask, const PropertyMask *ppSetMask,
	const ParagraphProperties *ppSet,

	PropertyMask *selCpChgMask, const PropertyMask *cpSetMask,
	const CellProperties *cpSet,

	PropertyMask *selRpChgMask, const PropertyMask *rpSetMask,
	const RowProperties *rpSet,

	PropertyMask *selSpChgMask, const PropertyMask *spSetMask,
	const SectionProperties *spSet,

	PropertyMask *docDpChgMask, const PropertyMask *dpSetMask,
	const DocumentProperties *dpSet);

int docInsertParagraph(EditOperation *eo, DocumentPosition *dpNew,
		       struct BufferItem *paraNode, int after,
		       int textAttributeNumber);

int docInsertSection(EditOperation *eo, DocumentPosition *dpBeforeSplit,
		     DocumentPosition *dpAfterSplit,
		     struct BufferItem *paraNode, int split, int after,
		     int textAttributeNumber);

int docEditChangeList(EditOperation *eo, struct DocumentList *dl,
		      struct ListOverride *lo,
		      const struct DocumentList *dlNew);

int docCopySelectionProperties(
	DocumentCopyJob *dcj, const DocumentSelection *dsTo,
	const DocumentSelection *dsFrom,

	PropertyMask *selPpDoneMask, const PropertyMask *ppSetMask,

	PropertyMask *selCpDoneMask, const PropertyMask *cpSetMask,

	PropertyMask *selRpDoneMask, const PropertyMask *rpSetMask,

	PropertyMask *selSpDoneMask, const PropertyMask *spSetMask,

	PropertyMask *docDpDoneMask, const PropertyMask *dpSetMask);

int docEditShiftIndent(EditOperation *eo, int step);

int docDeleteField(DocumentSelection *dsExInside, EditOperation *eo,
		   struct BufferItem *paraNodeHead,
		   struct BufferItem *paraNodeTail, int partHead, int partTail,
		   DocumentField *df);

int docSurroundTextSelectionByField(
	BufferDocument *bd, DocumentTree *dt, const DocumentSelection *ds,
	DocumentField **pDf, DocumentSelection *dsInside,
	DocumentSelection *dsAround, int *pHeadPart, int *pTailPart,
	const PropertyMask *taSetMask, const TextAttribute *taSet,
	int fieldKind, const FieldInstructions *fi);

int docFillTableDocument(BufferDocument *bdTable, struct BufferItem *parentNode,
			 int textAttrNr, int wide, int rows, int columns);

#endif /*	DOC_EDIT_H	*/
