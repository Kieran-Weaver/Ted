/************************************************************************/
/*									*/
/*  Text Editor Buffer structure.					*/
/*									*/
/************************************************************************/

#ifndef DOC_BUF_H
#define DOC_BUF_H

#include <time.h>
#include <bitmap.h>
#include <psPostScriptFontList.h>
#include <geo2DInteger.h>
#include <utilMemoryBuffer.h>
#include <docFramePropertiesAdmin.h>
#include <docStyleSheet.h>
#include <docDocumentProperties.h>
#include <docDocumentFieldList.h>
#include "docDrawingShapeList.h"
#include <docInsertedObjectList.h>
#include <docObject.h>
#include "docSelect.h"
#include "docDocumentTree.h"
#include <docListTable.h>
#include <docEditPosition.h>
#include <docEditRange.h>
/************************************************************************/
/*									*/
/*  Forward declarations of structs.					*/
/*									*/
/************************************************************************/

struct BufferDocument;
struct BufferItem;
struct TextLine;
struct TextParticule;
struct DocumentNote;
struct NoteProperties;
struct ParagraphProperties;
struct BorderProperties;
struct TabStopList;
struct DocumentPropertyLists;

/************************************************************************/
/*									*/
/*  The document as a whole.						*/
/*									*/
/************************************************************************/

typedef struct NotesList {
	struct DocumentNote *nlNotes;
	int nlNoteCount;
} NotesList;

typedef struct BufferDocument {
	/**
				 *  Numbered properties of the document.
				 *  In some cases, the lists are shared 
				 *  between documents.
				 */
	struct DocumentPropertyLists *bdPropertyLists;

	/**
				  *  The body of the document. This is the 
				  *  main document tree. Page headers and 
				  *  page footers are attached to the sections.
				  *  
				  *  Notes are kept in bdNotesList. The 
				  *  separators between the notes and ordinary
				  *  text are declared below.
				  */
	DocumentTree bdBody;
	DocumentProperties bdProperties;

	InsertedObjectList bdObjectList;
	DocumentStyleSheet bdStyleSheet;
	DocumentFieldList bdFieldList;
	DrawingShapeList bdShapeList;

	/**
				  *  The notes in this document. References 
				  *  from the contents of the various document 
				  *  trees to this list always pass through 
				  *  the field list of that tree.
				  *
				  *  In practice, only the document body holds
				  *  notes. The implementation of notes 
				  *  implcitly relies on this assumption.
				  */
	NotesList bdNotesList;

	/**
				  *  The Identifiers of the sequence 
				  *  fields in this document. It is map from 
				  *  the identifier to an int. The value of 
				  *  the int is only relevant inside the loop 
				  *  that renumbers the SEQ fields of a tree 
				  *  in the document.
				  */
	void *bdSeqFieldIdentifiers;

	DocumentTree bdEiFtnsep;
	DocumentTree bdEiFtnsepc;
	DocumentTree bdEiFtncn;

	DocumentTree bdEiAftnsep;
	DocumentTree bdEiAftnsepc;
	DocumentTree bdEiAftncn;

	/**
				  *  Used to smuggle the command line property 
				  *  into the line formatter.
				  */
	unsigned char bdAutoHyphenate;
} BufferDocument;

/************************************************************************/

#define docGetObject(bd, n) docGetObjectByNumber(&((bd)->bdObjectList), (n))
#define docClaimObject(p, bd) docClaimInsertedObject((p), &((bd)->bdObjectList))

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

const char *docKindStr(int kind);
const char *docLevelStr(int level);
const char *docTreeTypeStr(int level);
const char *docFieldKindStr(int kind);
const char *docObjectKindStr(int kind);
const char *docBreakKindStr(int kind);
const char *docAttributeStr(const TextAttribute *ta);
const char *docParticuleFlagsStr(int flags);

int docGetDefaultFont(BufferDocument *bd);

BufferDocument *docNewFile(TextAttribute *taDefault,
			   const char *defaultFontName, int defaultFontSize,
			   const PostScriptFontList *psfl,
			   const DocumentGeometry *dg);

void docFreeDocument(BufferDocument *bd);
BufferDocument *docNewDocument(const BufferDocument *bdRef);

int docNextPosition(DocumentPosition *dp); /* technical */
int docPrevPosition(DocumentPosition *dp); /* technical */

int docGotoNextPosition(DocumentPosition *dp); /* navigation */
int docGotoPrevPosition(DocumentPosition *dp); /* navigation */

int docNextWord(DocumentPosition *dp);
int docPrevWord(DocumentPosition *dp);

int docLineDown(int *pLine, DocumentPosition *dp, int line);

int docLineUp(int *pLine, DocumentPosition *dp, int line);

int docGotoFirstPosition(DocumentPosition *dp, /* navigation */
			 struct BufferItem *node);
int docGotoLastPosition(DocumentPosition *dp, /* navigation */
			struct BufferItem *node);
int docHeadPosition(DocumentPosition *dp, /* technical */
		    struct BufferItem *node);
int docTailPosition(DocumentPosition *dp, /* technical */
		    struct BufferItem *node);

int docDocumentHead(DocumentPosition *dp, BufferDocument *bd);

int docDocumentTail(DocumentPosition *dp, BufferDocument *bd);

void docAvoidParaHeadField(DocumentPosition *dp, int *pPart,
			   const BufferDocument *bd);

void docSetParaSelection(DocumentSelection *ds, struct BufferItem *node,
			 int direction, int start, int length);

int docComparePositions(const DocumentPosition *dp1,
			const DocumentPosition *dp2);

int docSetDocumentPosition(DocumentPosition *dp, struct BufferItem *node,
			   int stroff);

int docCompareNodePositionToSelection(const struct BufferItem *node,
				      const DocumentSelection *ds);

int docCompareCellPositionToSelection(int *pSelected,
				      const struct BufferItem *cellBi,
				      const DocumentSelection *ds);

void docDeleteDocumentTree(BufferDocument *bd, DocumentTree *dt);

void docEraseDocumentTree(BufferDocument *bd, DocumentTree *dt);

InsertedObject *docClaimObjectCopy(BufferDocument *bd, int *pNr,
				   const InsertedObject *ioFrom);

int docDelimitTable(const struct BufferItem *paraNode,
		    struct BufferItem **pParentNode, int *pCol, int *pRow0,
		    int *pRow, int *pRow1);

void docTableDetermineCellspans(int *pRowspan, int *pColspan,
				const struct BufferItem *cellNode);

int docGetCellBottom(LayoutPosition *lpBottom,
		     const struct BufferItem *cellNode);

void docLineSelection(DocumentSelection *dsLine, int *pPartLineBegin,
		      int *pPartLineEnd, const struct BufferItem *node,
		      int line);

void docWordSelection(DocumentSelection *dsWord, int *pIsObject,
		      const DocumentPosition *dpAround);

int docWhatPageHeader(DocumentTree **pTree, int *pIsEmpty,
		      const struct BufferItem *bodySectNode, int page,
		      const BufferDocument *bd);

int docWhatPageFooter(DocumentTree **pTree, int *pIsEmpty,
		      const struct BufferItem *bodySectNode, int page,
		      const BufferDocument *bd);

int docWhatPagesForHeaderFooter(const DocumentProperties *dp,
				const SectionProperties *sp, int treeType);

struct BufferItem *docGetSelectionRoot(DocumentTree **pTree,
				       struct BufferItem **pBodySectNode,
				       BufferDocument *bd,
				       const DocumentSelection *ds);

int docGetHeaderFooter(DocumentTree **pTree, struct BufferItem **pBodySectNode,
		       const DocumentPosition *dp, BufferDocument *bd,
		       int treeType);

int docInquireHeadersFooters(int *pDocHasHeaders, int *pDocHasFooters,
			     const BufferDocument *bd);

int docMakeDocumentTree(BufferDocument *bd, DocumentTree *dt,
			const SelectionScope *ss, const SectionProperties *sp);

struct BufferItem *docMakeExternalParagraph(BufferDocument *bd,
					    DocumentTree *dt, int treeType,
					    const struct BufferItem *bodyNode,
					    int ownerNumber, int txtAttrNr);

struct BufferItem *docMakeTreeRoot(BufferDocument *bd, DocumentTree *dt,
				   const struct BufferItem *bodyBi,
				   int ownerNumber, int treeType);

struct BufferItem *docInsertEmptyParagraph(BufferDocument *bd,
					   struct BufferItem *node,
					   int txtAttrNr);

int docTableRectangleSelection(DocumentSelection *ds,
			       struct BufferItem **pSelParentBi,
			       BufferDocument *bd, const TableRectangle *tr);

int docMergeDocumentLists(int **pFontMap, int **pListStyleMap,
			  BufferDocument *bdTo, BufferDocument *bdFrom,
			  const int *colorMap, const int *rulerMap);

int docMergeColorTables(int **pColorMap, BufferDocument *bdTo,
			const BufferDocument *bdFrom);

int docFindBookmarkInDocument(DocumentSelection *dsInside, int *pHeadPart,
			      int *pTailPart, const BufferDocument *bd,
			      const MemoryBuffer *markName);

DocumentField *docMakeField(BufferDocument *bd, DocumentTree *dt,
			    const DocumentSelection *dsInput, int part0,
			    int part1, int attr0, int attr1);

void docConstrainSelectionToOneParagraph(int *pHeadMoved, int *pTailMoved,
					 DocumentSelection *ds);

int docParaNextWord(const struct BufferItem *paraNode, int stroff);

int docParaPrevWord(const struct BufferItem *paraNode, int stroff);

int docParaHeadOfWord(int *pStroff, const struct BufferItem *paraNode,
		      int part);

int docParaTailOfWord(int *pStroff, const struct BufferItem *paraNode,
		      int part);

int docParaPastLastNonBlank(const struct BufferItem *paraNode, int from,
			    int upto);

DocumentTree *docSectionHeaderFooter(const struct BufferItem *bodySectNode,
				     unsigned char *pApplies,
				     const DocumentProperties *dp,
				     int treeType);

int docSectionHasHeaderFooter(const struct BufferItem *bodySectNode,
			      unsigned char *pApplies,
			      const DocumentProperties *dp, int treeType);

DocumentTree *docDocumentNoteSeparator(BufferDocument *bd, int which);

int docGetTreeOfNode(DocumentTree **pTree, struct BufferItem **pBodySectNode,
		     BufferDocument *bd, struct BufferItem *node);

int docGetRootOfSelectionScope(DocumentTree **pTree,
			       struct BufferItem **pBodySectNode,
			       BufferDocument *bd, const SelectionScope *ss);

int docSectionHeaderFooterFirstPage(int *pUsedInDocument,
				    const struct BufferItem *bodySectNode,
				    int treeType, const DocumentProperties *dp);

int docSelectWholeSection(DocumentSelection *bs, int direction);
int docSelectWholeTable(DocumentSelection *bs);
int docSelectRow(DocumentSelection *bs, int direction, int allColumns);
int docSelectWholeCell(DocumentSelection *bs, int direction, int allRows);
int docSelectColumn(DocumentSelection *ds, int col);
int docSelectWholeParagraph(DocumentSelection *bs, int direction);

int docSelectWholeBody(DocumentSelection *ds, BufferDocument *bd);

int docNumberOfParagraph(const struct BufferItem *paraNode);

struct BufferItem *docGetParagraphByNumber(const DocumentTree *dt, int n);

struct BufferItem *docGetCommonParent(struct BufferItem *paraNode1,
				      struct BufferItem *paraNode2);

void docSetTreeTypeOfNode(struct BufferItem *node, int treeType);

int docCheckNoteSeparatorItem(BufferDocument *bd, int sepTreeType);
int docCheckSeparatorItemForNoteType(BufferDocument *bd, int noteTreeType);

int docCountParticulesInField(const struct BufferItem *paraNode, int *pClosed,
			      int part, int partUpto);

int docGetSolidRgbShadeOfItem(int *pIsFilled, RGB8Color *rgb8,
			      const BufferDocument *bd, const ItemShading *is);

void docDelimitTables(struct BufferItem *parentNode, int recursively);

int docTextAttributeNumber(BufferDocument *bd, const TextAttribute *ta);

void docGetTextAttributeByNumber(TextAttribute *ta, const BufferDocument *bd,
				 int n);

int docItemShadingNumber(BufferDocument *bd, const ItemShading *is);

void docGetItemShadingByNumber(ItemShading *is, const BufferDocument *bd,
			       int n);

int docShadingNumberIsShading(const BufferDocument *bd, int n);

int docFramePropertiesNumber(BufferDocument *bd, const FrameProperties *fp);

void docGetFramePropertiesByNumber(FrameProperties *fp,
				   const BufferDocument *bd, int n);

int docBorderPropertiesNumber(BufferDocument *bd,
			      const struct BorderProperties *bp);

void docGetBorderPropertiesByNumber(struct BorderProperties *bp,
				    const BufferDocument *bd, int n);

int docBorderNumberIsBorder(const BufferDocument *bd, int n);

int docTabStopListNumber(BufferDocument *bd, const struct TabStopList *tsl);

void docGetTabStopListByNumber(struct TabStopList *tsl,
			       const BufferDocument *bd, int n);

int docBalanceFieldSelection(DocumentField **pLeftField,
			     DocumentField **pRightField, int *pBeginMoved,
			     int *pEndMoved, int *pHeadPart, int *pTailPart,
			     DocumentPosition *dpBegin, DocumentPosition *dpEnd,
			     DocumentTree *dt, BufferDocument *bd);

int docGetListOfParagraph(struct ListOverride **pLo, struct DocumentList **pDl,
			  int ls, const BufferDocument *bd);

int docGetListLevelOfParagraph(int *startPath, int *formatPath,
			       struct ListOverride **pLo,
			       struct DocumentList **pDl,
			       const struct ListLevel **pLl,
			       const ParagraphProperties *pp,
			       const BufferDocument *bd);

int docRemoveParagraphFromList(struct BufferItem *paraNode, DocumentTree *dt,
			       BufferDocument *bd);

int docParaHeadFieldKind(const struct BufferItem *paraNode,
			 const BufferDocument *bd);

int docDelimitParaHeadField(DocumentField **pField,
			    DocumentSelection *dsInsideField,
			    DocumentSelection *dsAroundField, int *pPartBegin,
			    int *pPartEnd, const struct BufferItem *paraNode,
			    const BufferDocument *bd);

int docFindListOfSelection(int *pLs, int *pLevel, int *pMultiList,
			   int *pMultiLevel, int *pParaNr,
			   const DocumentSelection *ds, DocumentTree *tree,
			   BufferDocument *bd);

int docApplyListRuler(const struct DocumentList *dl,
		      const struct ListOverride *lo, BufferDocument *bd);

int docGetEffectiveTextAttributes(TextAttribute *ta, BufferDocument *bd,
				  const struct BufferItem *paraNode, int part);

int docGetSelectionAttributes(BufferDocument *bd, const DocumentSelection *ds,
			      PropertyMask *pUpdMask, TextAttribute *pTaNew);

int docInsertParaHeadField(DocumentField **pField,
			   DocumentSelection *dsInsideField,
			   DocumentSelection *dsAroundField, int *pHeadPart,
			   int *pTailPart, struct BufferItem *paraNode,
			   BufferDocument *bd, DocumentTree *dt, int fieldKind,
			   int textAttrNr);

int docDelimitFieldInDoc(DocumentSelection *dsInside,
			 DocumentSelection *dsAround, int *pPart0, int *pPart1,
			 const BufferDocument *bd, const DocumentField *df);

int docDelimitFieldInTree(DocumentSelection *dsInside,
			  DocumentSelection *dsAround, int *pPart0, int *pPart1,
			  const BufferDocument *bd, const DocumentTree *dt,
			  const DocumentField *df);

int docDeleteFieldFromParent(DocumentTree *dt, DocumentField *df);

int docNextSimilarRoot(DocumentPosition *dp, int *pPage, int *pColumn,
		       BufferDocument *bd);

int docPrevSimilarRoot(DocumentPosition *dp, int *pPage, int *pColumn,
		       BufferDocument *bd);

int docAdaptParagraphToListLevel(int *pChanged, struct BufferItem *paraNode,
				 const BufferDocument *bd);

int docMakeCapsString(char **pUpperString, int **pSegments, int *pSegmentCount,
		      const TextAttribute *ta, const char *printString,
		      int len);

int docChangeRowProperties(PropertyMask *rpDonePask, struct BufferItem *rowNode,
			   const PropertyMask *rpSetMask,
			   const RowProperties *rpFrom);

int docSelectionForEditPositionsInDoc(DocumentSelection *ds,
				      const BufferDocument *bd,
				      const SelectionScope *ss,
				      const EditPosition *epHead,
				      const EditPosition *epTail);

int docSelectionForEditPositionsInTree(DocumentSelection *ds,
				       const DocumentTree *dt,
				       const EditPosition *epHead,
				       const EditPosition *epTail);

int docPositionForEditPosition(DocumentPosition *dpNew, const EditPosition *ep,
			       const DocumentTree *dt);

int docShiftFieldReferences(DocumentTree *dt, int sectFrom, int paraFrom,
			    int stroffFrom, int sectShift, int paraShift,
			    int stroffShift);

int docGetCellRight(int *pColspan, const struct BufferItem *cellNode);

int docGetMatchingCell(int *pColspan, const struct BufferItem *rowNode, int l,
		       int r);

const CellProperties *docGetCellProperties(const RowProperties **pRp,
					   const struct BufferItem *cellNode);

void docSetCellRectangleProperties(CellProperties *cpSet,
				   const struct BufferItem *rowNode,
				   const TableRectangle *tr,
				   const DocumentAttributeMap *dam);

void docDeleteFieldFromDocument(BufferDocument *bd, DocumentField *df);

int docDeleteFieldRange(int *pUpdateFlags, BufferDocument *bd,
			const EditRange *er, ChildFields *rootFields,
			DocumentField *dfLeft, DocumentField *dfRight);

void docDeleteChildFields(int *pUpdateFlags, BufferDocument *bd,
			  ChildFields *cf);

int docFindSetPattern(void **pProg, const char *pattern, int useRegex);

int docGetCharsUsed(BufferDocument *bd);

int docGetAttributesUsedInTree(BufferDocument *bd, const DocumentTree *dt,
			       IndexSet *isUsed);

int docGetAttributesUsedInShape(BufferDocument *bd,
				const struct DrawingShape *ds,
				IndexSet *isUsed);

void docPlainTextAttribute(TextAttribute *ta, BufferDocument *bd);

int docScapsAttributeNumber(BufferDocument *bd, const TextAttribute *ta);

void docCleanNodeObjects(int *pBulletsDeleted, int *pParagraphCount,
			 DocumentTree *dt, BufferDocument *bd,
			 struct BufferItem *node, DOC_CLOSE_OBJECT closeObject);

void docCleanDocumentObjects(BufferDocument *bd, DOC_CLOSE_OBJECT closeObject);

const DocumentFont *docRtfGetCurrentFont(BufferDocument *bd, TextAttribute *ta);

const char *docGetEncodingName(BufferDocument *bd, TextAttribute *ta,
			       int charset);

void docGetColorByNumber(RGB8Color *rgb8, const BufferDocument *bd,
			 int colorNumber);

void docDeleteObject(BufferDocument *bd, int n);

int docChangeParticuleAttributes(int *pChanged, PropertyMask *pTaAllMask,
				 BufferDocument *bd,
				 struct BufferItem *paraNode, int part,
				 int partUpto, const TextAttribute *taSet,
				 const PropertyMask *taSetMask);

int docCopySectHeadersFooters(struct BufferItem *sectNodeTo,
			      BufferDocument *bdTo,
			      struct BufferItem *sectNodeFrom,
			      BufferDocument *bdFrom);

int docCopySectDescription(struct BufferItem *sectNodeTo, BufferDocument *bdTo,
			   struct BufferItem *sectNodeFrom,
			   BufferDocument *bdFrom);

int docNodeAtExtremity(int *pAtExtremity, const struct BufferItem *parentNode,
		       const struct BufferItem *paraNode, int after);

int docHeaderFooterPage(const BufferDocument *bd,
			const struct BufferItem *bodySectNode, int currentPage,
			int treeType);

void docInvalidateSectHeaderFooterLayout(struct BufferItem *sectNode);

void docInvalidateParagraphLayout(struct BufferItem *paraNode);
void docInvalidateNodeLayout(struct BufferItem *node);

struct BufferItem *docGetBodySectNodeOfScope(const SelectionScope *ss,
					     const BufferDocument *bd);

void docOverridePaperSize(struct BufferDocument *bd,
			  const DocumentGeometry *dgFrom);

#endif
