#ifndef TED_DOC_FRONT_H
#define TED_DOC_FRONT_H

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

int tedDocReplace(EditDocument *ed, const char *word);

int tedDocAddRowToTable(EditDocument *ed, int after, int traced);

int tedDocAddColumnToTable(EditDocument *ed, int after, int traced);

int tedDocSetTableProperties(EditDocument *ed, int wholeRow,
				    int wholeColumn,
				    const PropertyMask *cpSetMask,
				    const CellProperties *cpSet,
				    const PropertyMask *rpSetMask,
				    const RowProperties *rpSet, int traced);

int tedDocSetImageProperties(EditDocument *ed,
				    const PropertyMask *pipSetMask,
				    const PictureProperties *pip, int traced);

int tedDocSetHyperlink(EditDocument *ed, const HyperlinkField *hf,
			      int traced);

int tedDocRemoveHyperlink(EditDocument *ed, int traced);

int tedDocFollowLink(APP_WIDGET option, EditDocument *ed,
			    const MemoryBuffer *fileName,
			    const MemoryBuffer *markName);

int tedDocDeleteSelectedParagraphs(EditDocument *ed, int traced);

int tedDocDeleteSelectedSections(EditDocument *ed, int traced);

int tedDocInsertParagraph(EditDocument *ed, int after, int traced);

int tedDocInsertSection(EditDocument *ed, int after, int traced);

int tedDocSetDocumentProperties(EditDocument *ed,
				       const PropertyMask *dpSetMask,
				       const DocumentProperties *dpSet,
				       int traced);

int tedDocChangeCurrentNote(EditDocument *ed,
				   const PropertyMask *npSetMask,
				   const NoteProperties *npSet, int traced);

int tedDocChangeSectionProperties(EditDocument *ed,
					 const PropertyMask *spUpdMask,
					 const SectionProperties *spNew,
					 int traced);

int tedDocChangeAllSectionProperties(EditDocument *ed,
					    const PropertyMask *spUpdMask,
					    const SectionProperties *spNew,
					    const PropertyMask *dpSetMask,
					    const DocumentProperties *dpNew,
					    int traced);

int
tedDocChangeParagraphProperties(EditDocument *ed, const PropertyMask *ppUpdMask,
				const struct ParagraphProperties *ppNew,
				int traced);

int tedDocSetParagraphTabs(EditDocument *ed,
				  const struct TabStopList *tsl, int traced);

int tedDocSetNewList(EditDocument *ed, int traced);

int tedDocChangeCurrentList(EditDocument *ed,
				   const struct DocumentList *dlNew,
				   int traced);

int tedDocDeleteHeaderFooter(EditDocument *ed, int treeType, int traced);

int tedDocInsertHeaderFooter(EditDocument *ed, int treeType, int traced);

void tedDocEditHeaderFooter(EditDocument *ed, APP_WIDGET relative,
				   APP_WIDGET option, int treeType);

int tedDocInsertNote(EditDocument *ed, int noteTreeType, int traced);

void tedDocGotoNoteDef(EditDocument *ed);
void tedDocGotoNoteRef(EditDocument *ed);

void tedDocNextNote(EditDocument *ed);
void tedDocPrevNote(EditDocument *ed);

void tedDocSelectTable(EditDocument *ed);
void tedDocSelectRow(EditDocument *ed, int direction, int allColumns);
void tedDocSelectWholeCell(EditDocument *ed, int direction, int allRows);

int tedDocSelectColumn(EditDocument *ed, int col);

int tedDocDeleteTable(EditDocument *ed, int traced);
int tedDocDeleteRow(EditDocument *ed, int traced);
int tedDocDeleteColumn(EditDocument *ed, int traced);

int tedDocSelectCurrentFrame(EditDocument *ed);
int tedDocDeleteCurrentFrame(EditDocument *ed, int traced);

int tedDocSetBookmark(EditDocument *ed, const MemoryBuffer *markName,
			     int traced);

int tedDocGoToBookmark(EditDocument *ed, const MemoryBuffer *markName);

int tedDocRemoveBookmark(EditDocument *ed, int traced);

int tedDocFindBookmarkField(DocumentField **pDf, EditDocument *ed,
				   const MemoryBuffer *markName);

int tedDocSetTocField(EditDocument *ed, const TocField *tf, int traced);

void tedDocDeleteTocField(EditDocument *ed, int traced);

void tedDocAddTocField(EditDocument *ed, const TocField *tf, int traced);

void tedDocChangeTextAttribute(EditDocument *ed,
				      const PropertyMask *taSetMask,
				      const TextAttribute *taSet, int traced);

int tedDocShiftRowsInTable(EditDocument *ed, int direction);

int tedDocListFontToolSet(EditDocument *ed,
				 const PropertyMask *taSetMask,
				 const ExpandedTextAttribute *etaSet);

int tedDocFontToolSet(EditDocument *ed, const PropertyMask *taSetMask,
			     const ExpandedTextAttribute *etaSet);

void tedDocFormatSetParaAlignment(EditDocument *ed, int align,
					 int traced);

void tedDocSetParaOutlineLevel(EditDocument *ed, int level, int traced);

void tedDocSetPageLayout(EditDocument *ed, const PropertyMask *dgSetMask,
				const DocumentGeometry *dgSet,
				int wholeDocument, int traced);

int tedFormatShiftIndent(EditDocument *ed, int step, int traced);

int tedObjectOpenImage(EditApplication *ea, void *voided,
			      APP_WIDGET relative, APP_WIDGET option,
			      const MemoryBuffer *filename);

APP_SCROLLBAR_CALLBACK_H(tedDocHorizontalScrollbarCallback, bar, voided, e);
APP_SCROLLBAR_CALLBACK_H(tedDocVerticalScrollbarCallback, bar, voided, e);

APP_MENU_CALLBACK_H(tedDocTableSelectTable, w, voided, event);
APP_MENU_CALLBACK_H(tedDocTableSelectRow, w, voided, event);
APP_MENU_CALLBACK_H(tedDocTableSelectColumn, w, voided, event);

APP_MENU_CALLBACK_H(tedDocTableDeleteTable, w, voided, event);
APP_MENU_CALLBACK_H(tedDocTableDeleteRow, w, voided, event);
APP_MENU_CALLBACK_H(tedDocTableDeleteColumn, w, voided, event);

void tedDocUndo(EditDocument *ed);
int tedDocRepeat(EditDocument *ed);

APP_MENU_CALLBACK_H(tedDocToolFind, w, voided, event);
APP_MENU_CALLBACK_H(tedDocToolFindNext, w, voided, event);
APP_MENU_CALLBACK_H(tedDocToolSpell, w, voided, event);

APP_MENU_CALLBACK_H(tedDocEditPaste, w, voided, event);
APP_MENU_CALLBACK_H(tedDocFontCopy, w, voided, event);
APP_MENU_CALLBACK_H(tedDocEditUndo, w, voided, event);
APP_MENU_CALLBACK_H(tedDocEditRepeat, w, voided, event);

APP_MENU_CALLBACK_H(tedDocFontBold, w, voided, event);
APP_MENU_CALLBACK_H(tedDocFontItalic, w, voided, event);
APP_MENU_CALLBACK_H(tedDocFontUnderlined, w, voided, event);
APP_MENU_CALLBACK_H(tedDocFontSupersub, w, voided, event);

APP_MENU_CALLBACK_H(tedDocInsertImage, w, voided, event);
APP_MENU_CALLBACK_H(tedDocInsertFile, w, voided, event);
APP_MENU_CALLBACK_H(tedDocInsertLink, w, voided, event);
APP_MENU_CALLBACK_H(tedDocInsertBookmark, w, voided, event);
APP_MENU_CALLBACK_H(tedDocInsertFootnote, w, voided, event);
APP_MENU_CALLBACK_H(tedDocInsertEndnote, w, voided, event);
APP_MENU_CALLBACK_H(tedDocInsertChftnsep, w, voided, event);
APP_MENU_CALLBACK_H(tedDocInsertPageNumber, w, voided, event);
APP_MENU_CALLBACK_H(tedDocInsertLineBreak, w, voided, event);
APP_MENU_CALLBACK_H(tedDocInsertPageBreak, w, voided, event);
APP_MENU_CALLBACK_H(tedDocInsertColumnBreak, w, voided, event);
APP_MENU_CALLBACK_H(tedDocMenuInsertSectBreak, w, voided, event);
APP_MENU_CALLBACK_H(tedDocToolInsertSymbol, w, voided, event);
APP_MENU_CALLBACK_H(tedDocFormatOnePara, w, voided, event);

APP_MENU_CALLBACK_H(tedDocFormatCopyRul, w, voided, event);
APP_MENU_CALLBACK_H(tedDocFormatPasteRul, w, voided, event);

APP_MENU_CALLBACK_H(tedDocFormatIncreaseIndent, w, voided, event);
APP_MENU_CALLBACK_H(tedDocFormatDecreaseIndent, w, voided, event);
APP_MENU_CALLBACK_H(tedDocFormatAlignLeft, w, voided, event);
APP_MENU_CALLBACK_H(tedDocFormatAlignRight, w, voided, event);
APP_MENU_CALLBACK_H(tedDocFormatAlignCenter, w, voided, event);
APP_MENU_CALLBACK_H(tedDocFormatAlignJustify, w, voided, event);

APP_MENU_CALLBACK_H(tedDocTableDrawGrid, w, voided, event);

APP_MENU_CALLBACK_H(tedDocFilePrint, printOption, voided, e);
APP_MENU_CALLBACK_H(tedDocTableInsertTable, option, voided, e);
APP_MENU_CALLBACK_H(tedDocTableAddRow, option, voided, e);
APP_MENU_CALLBACK_H(tedDocTableAddColumn, option, voided, e);
APP_MENU_CALLBACK_H(tedDocFormatTool, option, voided, e);
APP_MENU_CALLBACK_H(tedDocShowPageTool, pageOption, voided, e);
APP_MENU_CALLBACK_H(tedDocFontPaste, option, voided, e);
APP_MENU_CALLBACK_H(tedDocToolFont, option, voided, e);
APP_MENU_CALLBACK_H(tedDocFileProps, option, voided, e);
APP_MENU_CALLBACK_H(tedDocFileUnlock, option, voided, e);
APP_MENU_CALLBACK_H(tedDocFileRecover, option, voided, e);

APP_EVENT_HANDLER_H(tedDocObserveFocus, w, voided, event);

APP_PASTE_REPLY(tedPasteClipboardRtf, w, event, voided);
APP_PASTE_REPLY(tedPasteClipboardString, w, event, voided);
APP_PASTE_REPLY(tedPastePrimaryString, w, event, voided);
APP_PASTE_REPLY(tedPasteRulerTed, w, event, voided);
APP_PASTE_REPLY(tedPasteFontTed, w, event, voided);
APP_PASTE_REPLY(tedPasteClipboardPng, w, event, voided);
APP_PASTE_REPLY(tedPasteClipboardJfif, w, event, voided);

APP_GIVE_COPY(tedCopyClipboardRtf, w, event, voided);
APP_GIVE_COPY(tedCopyClipboardString, w, event, voided);
APP_GIVE_COPY(tedCopyPrimaryString, w, event, voided);
APP_GIVE_COPY(tedCopyClipboardPng, w, event, voided);
APP_GIVE_COPY(tedCopyClipboardJfif, w, event, voided);
APP_GIVE_COPY(tedCopyFontTed, w, event, voided);
APP_GIVE_COPY(tedCopyRulerTed, w, event, voided);

void tedClipboardLost(APP_WIDGET w, void *voided, APP_EVENT *clrEvent);

void tedPrimaryLost(APP_WIDGET w, void *voided, APP_EVENT *clrEvent);

APP_EVENT_HANDLER_H(tedMouseButtonPressed, w, voided, downEvent);
APP_EVENT_HANDLER_H(tedScrollEventHandler, w, voided, scrollEvent);

void tedDocGotKey(void *voided, int keySym, unsigned int state);

void tedDocGotString(void *voided, const char *string, int length);

void tedDocSplitParagraph(struct EditDocument *ed, int onNewPage,
				 int traced);

int tedDocInsertSectBreak(struct EditDocument *ed, int traced);

#endif /*  TED_DOC_FRONT_H	*/
