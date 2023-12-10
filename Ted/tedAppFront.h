#ifndef TED_APP_FRONT_H
#define TED_APP_FRONT_H

#include <appFrame.h>
#include <docRowProperties.h>
#include <docPictureProperties.h>
#include <docDocumentProperties.h>
#include <docNoteProperties.h>
#include <docSectProperties.h>
#include <docDocumentField.h>
#include <docTocField.h>
#include <docHyperlinkField.h>
#include <docExpandedTextAttribute.h>

struct ParagraphProperties;
struct TabStopList;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void tedAppReplace(void *voidea, const char *word);

void tedAppAddRowToTable(EditApplication *ea, int after);

void tedAppAddColumnToTable(EditApplication *ea, int after);

void tedAppSetTableProperties(EditApplication *ea, int wholeRow,
				     int wholeColumn,
				     const PropertyMask *cpSetMask,
				     const CellProperties *cpSet,
				     const PropertyMask *rpSetMask,
				     const RowProperties *rpSet);

void tedAppSetImageProperties(EditApplication *ea,
				     const PropertyMask *pipSetMask,
				     const PictureProperties *pip);

int tedAppShiftRowsInTable(EditApplication *ea, int direction);

int tedAppSetHyperlink(EditApplication *ea, const HyperlinkField *hf);

int tedAppRemoveHyperlink(EditApplication *ea);

int tedAppFollowLink(APP_WIDGET option, EditApplication *ea,
			    const MemoryBuffer *fileName,
			    const MemoryBuffer *markName);

int tedAppDeleteSelectedParagraphs(EditApplication *ea);
int tedAppDeleteSelectedSections(EditApplication *ea);

int tedAppInsertParagraph(EditApplication *ea, int after);

int tedAppInsertSection(EditApplication *ea, int after);

int tedAppSetDocumentProperties(EditApplication *ea,
				       const PropertyMask *dpSetMask,
				       const DocumentProperties *dpSet);

void tedAppChangeCurrentNote(EditApplication *ea,
				    const PropertyMask *npSetMask,
				    const NoteProperties *npSet);

int tedAppChangeSectionProperties(EditApplication *ea,
					 const PropertyMask *spUpdMask,
					 const SectionProperties *spNew);

int tedAppChangeAllSectionProperties(EditApplication *ea,
					    const PropertyMask *spUpdMask,
					    const SectionProperties *spNew,
					    const PropertyMask *dpSetMask,
					    const DocumentProperties *dpNew);

int
tedAppChangeParagraphProperties(EditApplication *ea,
				const PropertyMask *ppUpdMask,
				const struct ParagraphProperties *ppNew);

int tedAppSetParagraphTabs(EditApplication *ea,
				  const struct TabStopList *tsl);

int tedAppSetNewList(EditApplication *ea);

int tedAppChangeCurrentList(EditApplication *ea,
				   const struct DocumentList *dlNew);

void tedAppDeleteHeaderFooter(EditApplication *ea, int treeType);

void tedAppEditHeaderFooter(EditApplication *ea, APP_WIDGET relative,
				   APP_WIDGET option, int treeType);

void tedAppGotoNoteDef(EditApplication *ea);
void tedAppGotoNoteRef(EditApplication *ea);
void tedAppNextNote(EditApplication *ea);
void tedAppPrevNote(EditApplication *ea);

void tedAppSelectTable(EditApplication *ea);
void tedAppSelectRow(EditApplication *ea, int direction, int allColumns);
void tedAppSelectWholeCell(EditApplication *ea, int direction,
				  int allRows);

void tedAppDeleteTable(EditApplication *ea);
void tedAppDeleteRow(EditApplication *ea);
void tedAppDeleteColumn(EditApplication *ea);

int tedAppSelectCurrentFrame(EditApplication *ea);
int tedAppDeleteCurrentFrame(EditApplication *ea);

int tedAppSetBookmark(EditApplication *ea, const MemoryBuffer *markName);

int tedAppGoToBookmark(EditApplication *ea,
			      const MemoryBuffer *markName);

int tedAppRemoveBookmark(EditApplication *ea);

int tedAppFindBookmarkField(DocumentField **pDf, EditApplication *ea,
				   const MemoryBuffer *markName);

void tedAppSetTocField(EditApplication *ea, const TocField *tf);

void tedAppDeleteTocField(EditApplication *ea);

void tedAppAddTocField(EditApplication *ea, const TocField *tf);

int tedAppFindNext(void *voidea);

int tedAppFindPrev(void *voidea);

int tedAppListFontToolSet(void *voidea, const PropertyMask *taSetMask,
				 const ExpandedTextAttribute *etaSet);

int tedAppFontToolSet(void *voidea, const PropertyMask *taSetMask,
			     const ExpandedTextAttribute *etaSet);

void tedAppSetParaOutlineLevel(EditApplication *ea, int level);

int tedAppSelectWholeSection(EditApplication *ea, int direction);

int tedAppSelectWholeParagraph(EditApplication *ea, int direction);

void tedManual(APP_WIDGET option, EditApplication *ea,
		      APP_WIDGET relative);

void tedVisibleDocumentCountChanged(EditApplication *ea, int from,
					   int to);

#endif /*  TED_APP_FRONT_H	*/
